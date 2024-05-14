//
// A simple MIDI note sequencer (MIDI OUT test)
// 
 
// Author:  P.J. Drongowski
//          http://sandsoftwaresound.net/
// Version: 1.1
// Date:    6 June 2016
// 
// Copyright (c) 2016 Paul J. Drongowski
// Permission granted to redistribute and modify
 
// This program is based on the simple tone
// sequencer and generator program. It uses the
// same two dimensional sequence array and the
// same note and duration symbols. The note pitches
// are MIDI note numbers instead of tone() frequencies.
// You should be able to use the same sequences in
// either program.
 
#include "MidiNoteNum.h"
#include "ToneNote.h"
 
// Define the symbol LEONARDO when compiling for Arduino
// Leonardo boards or the littleBits Arduino. These boards do
// serial MIDI I/O on "Serial1"
#define LEONARDO 1
 
// Define LEONARDO_LED to make the TX LED flash with the music
// #define LEONARDO_LED 1
 
// MIDI transmit channel and note velocity
#define CHANNEL   9
#define VELOCITY  80
 
int noteIndex = 0 ;
int note = 0 ;
int duration = 0 ;
 
#define TEMPO   (90)
#define REST    -1
#define SEQUENCE 18
int sequence[SEQUENCE][2] = {
  NOTE_As2, EIGHTH, 
  REST,     SIXTEENTH, 
  NOTE_Gs3, SIXTEENTH, 
  REST,     EIGHTH, 
  NOTE_As3, EIGHTH,
  REST,     EIGHTH, 
  NOTE_C3,  EIGHTH, 
  NOTE_Cs3, EIGHTH, 
  NOTE_D3,  EIGHTH,
  NOTE_Ds3, EIGHTH, 
  REST,     SIXTEENTH, 
  NOTE_As3, SIXTEENTH, 
  REST,     EIGHTH, 
  NOTE_Cs4, EIGHTH,
  REST,     EIGHTH, 
  NOTE_G2,  EIGHTH, 
  NOTE_Gs2, EIGHTH, 
  NOTE_A2,  EIGHTH
} ;
 
//
// Send a short, 3-byte MIDI message
//
void MidiSend(byte cmd, byte data1, byte data2)
{
#ifdef LEONARDO
  Serial.write(cmd | CHANNEL) ;
  Serial.write(data1) ; 
  Serial.write(data2) ; 
#else
  Serial.write(cmd | CHANNEL) ;
  Serial.write(data1) ; 
  Serial.write(data2) ; 
#endif
}
 
//
// MIDI note ON message
//
void MidiNoteOn(byte note, byte velocity)
{
  MidiSend(0x90, note, velocity) ; 
#ifdef LEONARDO_LED
  TXLED1;
#endif
}
 
//
// MIDI note OFF message
//
void MidiNoteOff(byte note)
{
  // MidiSend(0x80, note, 0) ; 
  MidiSend(0x90, note, 0) ; 
#ifdef LEONARDO_LED
  TXLED0;
#endif
}
 
void setup() {
  // Initialize the serial interface for 5-pin MIDI
#ifdef LEONARDO
  Serial1.begin(31250) ;
#else
  Serial.begin(31250) ;
#endif
  // Start playing the first note in the sequence
  // This note could be a pick-up!
  noteIndex = 15 ;
  note = sequence[noteIndex][0] ;
  duration = sequence[noteIndex][1] ;
  if (note != REST) {
    MidiNoteOn(note, VELOCITY) ;
  }
}
 
void loop() {
  delay(1) ;
  duration-- ;
  if (duration <= 0) {
    // Current note has expired.
    MidiNoteOff(note) ;
    // Find the next note to be played
    if (noteIndex >= (SEQUENCE-1)) {
        noteIndex = 0 ;
    } else {
        noteIndex += 1 ;
    }
    note = sequence[noteIndex][0] ;
    duration = sequence[noteIndex][1] ;
    // Start playing the next note
    if (note != REST) {
      MidiNoteOn(note, VELOCITY) ;
    }
  }
}