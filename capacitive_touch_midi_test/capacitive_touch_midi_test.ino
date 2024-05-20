/*********************************************************
Hugo Grimmett
**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

// MIDI channel is 1 (index 0, last digit of following commands)
int NOTE_ON = 0x90;
int NOTE_OFF = 0x80;
int VELOCITY = 64; // 0-127, average is 64

void setup() {
  Serial.begin(31250); // 9600 for serial monitor, 31250 for MIDI

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  // Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    // Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  // Serial.println("MPR121 found!");
}


void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      noteSend(NOTE_ON, touchIndexToNote(i), VELOCITY);
      // Serial.print("Note "); Serial.print(touchIndexToNote(i)); Serial.print(" ON"); Serial.print(" (");Serial.print(NOTE_ON);Serial.print(")\n");
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      noteSend(NOTE_OFF, touchIndexToNote(i), VELOCITY);
      // Serial.print("Note "); Serial.print(touchIndexToNote(i)); Serial.print(" OFF"); Serial.print(" (");Serial.print(NOTE_OFF);Serial.print(")\n");
    }
  }

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
}

int touchIndexToNote(int touch_index) {
  int note = 127;
  switch (touch_index) {
    case 0:
      note = 60;
      break;
    case 1:
      note = 62;
      break;
    case 2:
      note = 64;
      break;
    case 3:
      note = 67;
      break;
    case 4:
      note = 69;
      break;
    case 5:
      note = 72;
      break;
    default:
      note = 120;
      break;
  }
  return note;
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteSend(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
