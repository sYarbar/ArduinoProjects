#include <avr/interrupt.h>
#include <avr/sleep.h>
void setup() {
  cli(); // Clear global interrupt
  // Set Pin 13 as output and 10 as input
  DDRB |= B100000 ;
  DDRB &= B111011 ;
  // Control regs for PCINT
  PCICR |= B00000001 ; // Enable PCINT0
  PCMSK0 |= B00000100 ; // Select PCINT0 mask
  Serial.begin(9600); // Only for debug
  // Use an appropriate sleep mode
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sei(); // Set global Interrupt
}
// ISR for pin change interrupt capture
// Note: triggers both on rising & falling
ISR(PCINT0_vect) {
  // Display in serial monitor for debug
  Serial.println("Switch Pressed");
  // Toggle the LED
  PORTB ^= B100000 ;
}
// Main loop
void loop() {
  // Display in serial monitor for debug
  Serial.println("Main Loop");
  // Do nothing!
  // Put MCU to sleep
  sleep_mode();
}
