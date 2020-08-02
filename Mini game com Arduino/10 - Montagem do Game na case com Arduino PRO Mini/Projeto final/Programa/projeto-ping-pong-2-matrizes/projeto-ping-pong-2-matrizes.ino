#include <LedControl.h>

#define DATA_PIN    12
#define CLOCK_PIN   11
#define CS_PIN      10
#define NUM_DEVICES 2
#define KNOB_PIN    A0
#define RANDOM_PIN  A1
#define SPEAKER_PIN 7

#define N_a   440
#define N_f   349
#define N_cH  523
#define N_eH  659
#define N_fH  698
#define N_gS  415

int step_col, step_row, subidas, OLD_X, sensor, row, col, sc, sr, dly;
int row_bar = 0;
int X = 4;
int cnt = 0;
int desarma = 0;

boolean showBars_enabled = false;

LedControl LC = LedControl(DATA_PIN, CLOCK_PIN, CS_PIN, NUM_DEVICES);

byte MSG[8 * 20];
byte SPACE[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
byte W[8] = {
  B00000000,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B01100110,
  B00000000
};
byte I[8] = {
  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,
  B00000000
};
byte N[8] = {
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000
};
byte E[8] = {
  B00000000,
  B01111110,
  B01000000,
  B01111100,
  B01000000,
  B01000000,
  B01111110,
  B00000000
};
byte R[8] = {
  B00000000,
  B01111100,
  B01000010,
  B01111100,
  B01001000,
  B01000100,
  B01000010,
  B00000000
};

void loose()
{
  delay(80);

  for (row = 0; (row < 16); row++) {
    setROW(row, 0xFF);
    tone(SPEAKER_PIN, (row * 500), 10);
    delay(20);
  }

  delay(130);

  for (row = 15; (row >= 0); row--) {
    setROW(row, 0x00);
    tone(SPEAKER_PIN, (row * 500), 10);
    delay(20);
  }
}

void showBars(boolean show)
{
  showBars_enabled = show;

  if (show) {
    row_bar = (2 + random(5));
  }

  setROW(row_bar, (show == true ? 0xFF : 0x00));
}

void setLED(int l, int c, boolean state)
{
  int disp = 0;

  if (l > 7) {
    l = (l - 8);
    disp = 1;
  }

  LC.setLed(disp, l, c, state);
}

void setROW(int r, char ch)
{
  int disp = 0;

  if (r > 7) {
    r = (r - 8);
    disp = 1;
  }

  LC.setRow(disp, r, ch);
}

void copyLetter(byte *ch, int pos)
{
  int i;

  for (i = 0; (i < 8); i++) {
    *(MSG + i + (pos * 8)) = *( ch + i);
  }
}

void showMSG(int qtde, int tempo)
{
  int idx;

  LC.clearDisplay(0);
  LC.clearDisplay(1);

  for (idx = 0; (idx < (8 * qtde)); idx++) {
    for (row = 0; (row < 16); row++) {
      setROW(row, *(MSG + row + idx));
    }

    delay(tempo);
  }

  LC.clearDisplay(0);
  LC.clearDisplay(1);
}

void beep(int frequencyInHertz, long timeInMilliseconds)
{
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));

  for (row = 0; (row < 16); row++) {
    setROW(row, 0xFF);
  }

  for (x = 0; (x < loopTime); x++) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(delayAmount);
  }

  LC.clearDisplay(0);
  LC.clearDisplay(1);

  delay(20);
}

void march()
{
  beep(N_a, 500);
  beep(N_a, 500);
  beep(N_a, 500);
  beep(N_f, 350);
  beep(N_cH, 150);

  beep(N_a, 500);
  beep(N_f, 350);
  beep(N_cH, 150);
  beep(N_a, 1000);

  beep(N_eH, 500);
  beep(N_eH, 500);
  beep(N_eH, 500);
  beep(N_fH, 350);
  beep(N_cH, 150);

  beep(N_gS, 500);
  beep(N_f, 350);
  beep(N_cH, 150);
  beep(N_a, 1000);
}

void winner()
{
  copyLetter(SPACE, 0);
  copyLetter(SPACE, 1);

  copyLetter(W, 2);
  copyLetter(I, 3);
  copyLetter(N, 4);
  copyLetter(N, 5);
  copyLetter(E, 6);
  copyLetter(R, 7);

  copyLetter(SPACE, 8);
  copyLetter(SPACE, 9);

  showMSG(9, 80);

  march();

  setup();
}

void setup() 
{
  pinMode(KNOB_PIN, INPUT);      // Potentiometer 10K Linear (GND, KNOB_PIN, +5v)
  pinMode(RANDOM_PIN, INPUT);    // Random Seed
  pinMode(SPEAKER_PIN, OUTPUT);  // Passive Buzzer

  LC.shutdown(0, false);
  LC.setIntensity(0, 8);
  LC.clearDisplay(0);

  LC.shutdown(1, false);
  LC.setIntensity(1, 8);
  LC.clearDisplay(1);

  randomSeed(analogRead(RANDOM_PIN) * millis());

  loose();

  dly = 500;

  setLED(15, X, true);
  setLED(15, (X + 1), true);
  setLED(15, (X + 2) , true);
  OLD_X = (-1);
  subidas = 0;

  step_col = 1;
  step_row = 1;

  sc = step_col;
  sr = step_row;

  row = ((-1) + random(3));
  col = random(8);

  showBars(false);
}

void loop()
{
  sensor = analogRead(KNOB_PIN);

  X = map(sensor, 0, 980, 1, 6);

  if (X != OLD_X) {
    OLD_X = X;
    setROW(15, 0x00);
    setLED(15, (X - 1), true);
    setLED(15, X, true);
    setLED(15, (X + 1), true);
  }

  if (cnt == 0) {
    setLED(row, col, false);

    if ((subidas == 1 || random(2) == 1) && showBars_enabled == false && row == 0) {
      showBars(true);
      subidas = 0;
      desarma = (2 + random(5));
    }

    if ((subidas == desarma) && (showBars_enabled == true)) {
      showBars(false);
      subidas = 0;
    }

    if (col == 7) {
      sc = -step_col;
      tone(SPEAKER_PIN, 1000, 20);
    }

    if (col == 0) {
      sc = step_col;
      tone(SPEAKER_PIN, 1000, 20);
    }

    if (row == 0) {
      sr = step_row;
      subidas++;
      dly -= 5;
      tone(SPEAKER_PIN, 1000, 20);
    }

    if (dly <= 190) {
      winner();
    }

    if (showBars_enabled == true && sr > 0 && row < row_bar) {
      if (row == (row_bar - 1)) {
        sr = -step_row;
        tone(SPEAKER_PIN, 1000, 20);
      }
    }

    if (row == 14)
    {
      if (col >= (X - 1) && col <= (X + 1)) {
        sr = -step_row;
        tone(SPEAKER_PIN, 1500, 20);
      }
      else if (col == (X - 2) && (sc > 0)) {
        sr = -step_row;
        sc = -step_col;
        tone(SPEAKER_PIN, 1500, 20);
      }
      else if (col == (X + 2) && (sc < 0)) {
        sr = -step_row;
        sc = step_col;
        tone(SPEAKER_PIN, 1500, 20);
      }
    }

    row += sr;
    col += sc;

    if (col == 8) {
      col = 7;
    }

    if (col == (-1)) {
      col = 0;
    }

    setLED(row, col, true);

    if (row == 15) {
      setup();
    }
  }

  cnt++;

  if (cnt == dly) {
    cnt = 0;
  }
}
