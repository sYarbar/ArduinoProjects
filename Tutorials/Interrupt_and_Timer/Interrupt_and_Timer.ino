#include <avr/interrupt.h>
#include <avr/sleep.h>
int count1 = 15625; //arbitrary number of clockcycles
int maximumCount = 15625*2; //0.5Hz
int minimumCount = 15625/8; //8Hz
int state8 = 0; //variable used to make switch interrupt once per press
int state7 = 0;

void setup() {
  // put your setup code here, to run once:
  
  cli(); // Clear global interrupt
  DDRB &= B111110; //Set pin 8 to input
  DDRD &= B01111111; //Set pin 7 as input
  DDRD |= B01000000; //Set pin 6 as output
  
  TCCR1A = B00000000; //set timer 1 to normal mode
  TCCR1B = B00000101; //Set prescalar to 1024
  TIMSK1 = B00000001; //Turn on OVF
  TCNT1 = 0xFFFF - count1; //Set timer
  
  PCICR |= B00000101; //Turn on interrupt for PCMSK0(PORT B) and PCMSK2(PORTD)
  PCMSK2 |= B10000000; //Turn PCINT23(pin 7) interrupt on
  PCMSK0 |= B00000001; //Turn on PCINT0(pin8) interrupt
  
  set_sleep_mode(SLEEP_MODE_IDLE);//IDLE is the only sleep mode with clk io
  sei();//Enable Global Interrupt
}

//PCINT0 corresponds to interrupts from port D(pin7)
//should double frequency
ISR(PCINT0_vect){
  if(state7 == 0){
    if(count1 > minimumCount){  //Dont let timer go above 8hz
      count1 = count1/2;
    }
    state7++;
  }
  else{
    state7 = 0;
  }
}
//PCINT2 corresponds to interrupts from port B(pin 8)
//Should half frequency
ISR(PCINT2_vect){
  if(state8 == 0){
    if(count1 < maximumCount){  //Don't let count go below 0.5Hz
      count1 = count1*2;
    }
    state8++;
  }
  else{
    state8 = 0;
  }
}

//Timer1 ISR
ISR(TIMER1_OVF_vect){
  PORTD ^= B01000000;
  TCNT1 = 0xFFFF - count1;
}

void loop() {
  // put your main code here, to run repeatedly:
 sleep_mode();
}
