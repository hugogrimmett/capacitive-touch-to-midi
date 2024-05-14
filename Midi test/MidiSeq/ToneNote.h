//
// The program must define TEMPO before
// including this file. TEMPO is specified
// in beats per minute (BPM).
//
 
// Convert TEMPO (BPM) to one millisecond ticks.
#define TICKS   ((int)((60.0 / TEMPO) * 1000.0))
 
#define SIXTEENTH         (TICKS / 4)
#define EIGHTH            (TICKS / 2)
#define QUARTER           TICKS
#define DOTTED_QUARTER    (TICKS + (TICKS / 2))
#define HALF              (TICKS * 2)
#define DOTTED_HALF       (TICKS * 3)
#define WHOLE             (TICKS * 4)
