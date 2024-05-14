// Integer MIDI note numbers for NOTE ON/NOTE OFF
// Lowest frequency on piano:  A0 (27.5 Hz)
// Highest frequency on piano: C8 (4186.01 Hz)
// Middle C is C4 (Roland convention; Yamaha is C3)
 
#define NOTE_C0   12
#define NOTE_Cs0  13
#define NOTE_D0   14
#define NOTE_Ds0  15
#define NOTE_E0   16
#define NOTE_F0   17
#define NOTE_Fs0  18
#define NOTE_G0   19
#define NOTE_Gs0  20
#define NOTE_A0   21
#define NOTE_As0  22
#define NOTE_B0   23
 
#define NOTE_C1   24
#define NOTE_Cs1  25
#define NOTE_D1   26
#define NOTE_Ds1  27
#define NOTE_E1   28
#define NOTE_F1   29
#define NOTE_Fs1  30
#define NOTE_G1   31
#define NOTE_Gs1  32
#define NOTE_A1   33
#define NOTE_As1  34
#define NOTE_B1   35
 
#define NOTE_C2   36
#define NOTE_Cs2  37
#define NOTE_D2   38
#define NOTE_Ds2  39
#define NOTE_E2   40
#define NOTE_F2   41
#define NOTE_Fs2  42
#define NOTE_G2   43
#define NOTE_Gs2  44
#define NOTE_A2   45
#define NOTE_As2  46
#define NOTE_B2   47
 
#define NOTE_C3   48
#define NOTE_Cs3  49
#define NOTE_D3   50
#define NOTE_Ds3  51
#define NOTE_E3   52
#define NOTE_F3   53
#define NOTE_Fs3  54
#define NOTE_G3   55
#define NOTE_Gs3  56
#define NOTE_A3   57
#define NOTE_As3  58
#define NOTE_B3   59
 
#define NOTE_C4   60
#define NOTE_Cs4  61
#define NOTE_D4   62
#define NOTE_Ds4  63
#define NOTE_E4   64
#define NOTE_F4   65
#define NOTE_Fs4  66
#define NOTE_G4   67
#define NOTE_Gs4  68
#define NOTE_A4   69
#define NOTE_As4  70
#define NOTE_B4   71
 
#define NOTE_C5   72
#define NOTE_Cs5  73
#define NOTE_D5   74
#define NOTE_Ds5  75
#define NOTE_E5   76
#define NOTE_F5   77
#define NOTE_Fs5  78
#define NOTE_G5   79
#define NOTE_Gs5  80
#define NOTE_A5   81
#define NOTE_As5  82
#define NOTE_B5   83
 
#define NOTE_C6   84
#define NOTE_Cs6  85
#define NOTE_D6   86
#define NOTE_Ds6  87
#define NOTE_E6   88
#define NOTE_F6   89
#define NOTE_Fs6  90
#define NOTE_G6   91
#define NOTE_Gs6  92
#define NOTE_A6   93
#define NOTE_As6  94
#define NOTE_B6   95
 
#define NOTE_C7   96
#define NOTE_Cs7  97
#define NOTE_D7   98
#define NOTE_Ds7  99
#define NOTE_E7   100
#define NOTE_F7   101
#define NOTE_Fs7  102
#define NOTE_G7   103
#define NOTE_Gs7  104
#define NOTE_A7   105
#define NOTE_As7  106
#define NOTE_B7   107
 
#define NOTE_C8   108
#define NOTE_Cs8  109
#define NOTE_D8   110
#define NOTE_Ds8  111
#define NOTE_E8   112
#define NOTE_F8   113
#define NOTE_Fs8  114
#define NOTE_G8   115
#define NOTE_Gs8  116
#define NOTE_A8   117
#define NOTE_As8  118
#define NOTE_B8   119
 
#define NOTE_C9   120
#define NOTE_Cs9  121
#define NOTE_D9   122
#define NOTE_Ds9  123
#define NOTE_E9   124
#define NOTE_F9   125
#define NOTE_Fs9  126
#define NOTE_G9   127
 
#define NOTESIZE ((9*12)+8)
 
int midiNoteNumbers[NOTESIZE] = {
  NOTE_C0,  NOTE_Cs0, NOTE_D0,  NOTE_Ds0, NOTE_E0,  NOTE_F0,
  NOTE_Fs0, NOTE_G0,  NOTE_Gs0, NOTE_A0,  NOTE_As0, NOTE_B0,
 
  NOTE_C1,  NOTE_Cs1, NOTE_D1,  NOTE_Ds1, NOTE_E1,  NOTE_F1,
  NOTE_Fs1, NOTE_G1,  NOTE_Gs1, NOTE_A1,  NOTE_As1, NOTE_B1,
 
  NOTE_C2,  NOTE_Cs2, NOTE_D2,  NOTE_Ds2, NOTE_E2,  NOTE_F2,
  NOTE_Fs2, NOTE_G2,  NOTE_Gs2, NOTE_A2,  NOTE_As2, NOTE_B2,
 
  NOTE_C3,  NOTE_Cs3, NOTE_D3,  NOTE_Ds3, NOTE_E3,  NOTE_F3,
  NOTE_Fs3, NOTE_G3,  NOTE_Gs3, NOTE_A3,  NOTE_As3, NOTE_B3,
 
  NOTE_C4,  NOTE_Cs4, NOTE_D4,  NOTE_Ds4, NOTE_E4,  NOTE_F4,
  NOTE_Fs4, NOTE_G4,  NOTE_Gs4, NOTE_A4,  NOTE_As4, NOTE_B4,
 
  NOTE_C5,  NOTE_Cs5, NOTE_D5,  NOTE_Ds5, NOTE_E5,  NOTE_F5,
  NOTE_Fs5, NOTE_G5,  NOTE_Gs5, NOTE_A5,  NOTE_As5, NOTE_B5,
 
  NOTE_C6,  NOTE_Cs6, NOTE_D6,  NOTE_Ds6, NOTE_E6,  NOTE_F6,
  NOTE_Fs6, NOTE_G6,  NOTE_Gs6, NOTE_A6,  NOTE_As6, NOTE_B6,
 
  NOTE_C7,  NOTE_Cs7, NOTE_D7,  NOTE_Ds7, NOTE_E7,  NOTE_F7,
  NOTE_Fs7, NOTE_G7,  NOTE_Gs7, NOTE_A7,  NOTE_As7, NOTE_B7,
 
  NOTE_C8,  NOTE_Cs8, NOTE_D8,  NOTE_Ds8, NOTE_E8,  NOTE_F8,
  NOTE_Fs8, NOTE_G8,  NOTE_Gs8, NOTE_A8,  NOTE_As8, NOTE_B8,
 
  NOTE_C9,  NOTE_Cs9, NOTE_D9,  NOTE_Ds9, NOTE_E9,  NOTE_F9,
  NOTE_Fs9, NOTE_G9
} ;