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

// ESP32 native touch config
#define ESP32_NOTE_PIN T2  // GPIO2
#define OCTAVE_UP_PIN T0     // GPIO4
#define OCTAVE_DOWN_PIN T3   // GPIO15
#define ESP32_TOUCH_THRESHOLD 20  // Adjust experimentally
bool lastTouchStateNote = false;

// MIDI channel is 1 (index 0, last digit of following commands)
int NOTE_ON = 0x90;
int NOTE_OFF = 0x80;
int VELOCITY = 64; // 0-127, average is 64

// set to 1 for serial monitor output -- note that this disables MIDI output
bool debug = 0;

void setup() {
  if (debug) {
    Serial.begin(9600);  // 9600 for debugging
  } else {
    Serial.begin(31250); // 31250 for MIDI
  }
  

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  // Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    if (debug) {
      Serial.println("MPR121 not found, check wiring?");
    }
    while (1);
  }
  if (debug) {
    Serial.println("MPR121 found!");
  }
}


void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();

  int octaveShift = getOctaveShift();
  
  for (uint8_t i=0; i<12; i++) {
    int shiftedNote = touchIndexToNote(i) + octaveShift; // Apply octave shift here

    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      noteSend(NOTE_ON, shiftedNote, VELOCITY);
      if (debug) {
        Serial.print("Note "); Serial.print(shiftedNote); Serial.print(" ON"); Serial.print(" (");Serial.print(NOTE_ON);Serial.print(")\n");
      }
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      noteSend(NOTE_OFF, shiftedNote, VELOCITY);
      if (debug) {
        Serial.print("Note "); Serial.print(shiftedNote); Serial.print(" OFF"); Serial.print(" (");Serial.print(NOTE_OFF);Serial.print(")\n");
      }
    }
  }

  // reset our state
  lasttouched = currtouched;

  // ESP32 native touch handling
  int touchValue = touchRead(ESP32_NOTE_PIN);
  bool noteTouched = touchValue < ESP32_TOUCH_THRESHOLD;
  int note = 72 + octaveShift;  // C5 + shift

  if (noteTouched && !lastTouchStateNote) {
    noteSend(NOTE_ON, note, VELOCITY); // C5
    if (debug) {
      Serial.print("Note ON\n");
    }
  } else if (!noteTouched && lastTouchStateNote) {
    noteSend(NOTE_OFF, note, VELOCITY);
    if (debug) {
      Serial.print("Note OFF\n");
    }
  }

  lastTouchStateNote = noteTouched;

  if (debug) {  
    // --- DEBUG OUTPUT ---
    Serial.print("NoteTouch: "); Serial.print(touchValue);
    Serial.print("  OctaveUp: "); Serial.print(touchRead(OCTAVE_UP_PIN));
    Serial.print("  OctaveDown: "); Serial.println(touchRead(OCTAVE_DOWN_PIN));
    delay(200);  // Slower loop for readability while debugging
  }

  delay(10); // Light debounce

  // comment out this line for detailed data from the sensor!
  // return;
}

int touchIndexToNote(int touch_index) {
  int note = 127;
  switch (touch_index) {
    case 0: return 60;
    case 1: return 61;
    case 2: return 62;
    case 3: return 63;
    case 4: return 64;
    case 5: return 65;
    case 6: return 66;
    case 7: return 67;
    case 8: return 68;
    case 9: return 69;
    case 10: return 70;
    case 11: return 71;
    default: return 120; // Fallback
  }
}

// Get octave shift value based on touch input
int getOctaveShift() {
  bool upTouched = touchRead(OCTAVE_UP_PIN) < ESP32_TOUCH_THRESHOLD;
  bool downTouched = touchRead(OCTAVE_DOWN_PIN) < ESP32_TOUCH_THRESHOLD;

  if (upTouched && !downTouched) return 12;
  if (!upTouched && downTouched) return -12;
  return 0;
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteSend(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}