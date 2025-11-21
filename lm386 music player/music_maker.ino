//Musical Maker

//Config
int speaker = 11; //pin for sound output (use a PWM pin denoted by a ~ by the pins)
int bpm = 120;

float period = 60000.0 / bpm;
//Edit your music here

//Note: The natural key's are represented in lowercase.
// For sharps, we would use a capital/uppercase. Represent any flats as sharps.
// The last part of the note is the type. Put 1 for a whole note, 0.5 for a half-note, etc.
// Optionally, you can add delays if you want staccato.
// Rests are denoted by the note '-' (a dash), octave doesn't matter, but still use the beat.
void song(){
char notes[]  = {'e','D','e','D','e','b','d','c','a','-','c','e','a','b','-','e','G','b','c','-','e','e','D','e','D','e','b','d','c','a'};
int octaves[] = { 5 , 5 , 5 , 5 , 5 , 4 , 5 , 5 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 4 , 5 , 5 , 4 };
float beats[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,1.0,0.5,0.5,0.5,0.5,0.5,0.5,0.5,1.0};

int notes_len = sizeof(notes) / sizeof(notes[0]);
int octaves_len = sizeof(octaves) / sizeof(octaves[0]);
int beats_len = sizeof(beats) / sizeof(beats[0]);
int min_len = notes_len;
if(octaves_len < min_len) min_len = octaves_len;
if(beats_len   < min_len) min_len = beats_len;

for(int i=0; i<min_len; i++)
{ note(notes[i], octaves[i], beats[i]);}
}



const float NOTES[9][12] PROGMEM = {
  // Octave 0
  {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87},
  // Octave 1
  {32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74},
  // Octave 2
  {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47},
  // Octave 3
  {130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94},
  // Octave 4
  {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88},
  // Octave 5
  {523.25, 554.37, 587.33, 622.25, 659.26, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77},
  // Octave 6
  {1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53},
  // Octave 7
  {2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07},
  // Octave 8
  {4186.01, 4434.92, 4698.64, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040.00, 7458.62, 7902.13}
};


void setup() {
}

void loop() {
  song();
  delay(10000); //Delay after song is played (in ms)
}

void note(char key, int octave, float beat) {
  int i = noteIndex(key, octave);

  if(i < 0){ delay(beat * period); return;} 
  
  octave = constrain(octave, 0, 8);

  float freq = pgm_read_float(&NOTES[octave][i]);

  // Edit the last number in the function below to change the stacatto.
  tone(speaker, freq, (beat * period * 0.99));
  delay(beat * period);
}


int noteIndex(char key, int &octave){
    switch(key)
    {
      case 'c': return 0;
      case 'C': return 1;
      case 'd': return 2;
      case 'D': return 3;
      case 'e': return 4;
      case 'E': return 5;  //E# is equal to F
      case 'f': return 5;
      case 'F': return 6;
      case 'g': return 7;
      case 'G': return 8;
      case 'a': return 9;
      case 'A': return 10;
      case 'b': return 11;

      case 'B': octave++; return 0;
      case '-': return -1;
      default: return -1;
    }
}