#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordStep {
  unsigned long timeMs;
  const char* word;
  uint8_t col;
  uint8_t row;
  bool clearScreen;
};

const WordStep lyrics[] = {
  {   580, "Kitang-kita",   0, 0, true  },
  {  1980, "na",          12, 0, false },
  {  2660, "sa",           0, 1, false },
  {  2920, "kilos",        3, 1, false },
  {  3870, "mong",         9, 1, false },
  {  4760, "kakaiba,",     0, 0, true  },
  {  7080, "ooh,",         9, 0, false },
  {  8550, "ako",          0, 1, false },
  {  8950, "pa",           4, 1, false },
  {  9240, "ba?",          7, 1, false },
  {  9640, "ohh",          11, 1, false },
  { 14100, "Ikaw",         0, 0, true  },
  { 14860, "at",           5, 0, false },
  { 15330, "ako",          8, 0, false },
  { 18520, "Ang",          0, 0, true  },
  { 19240, "magkasama",    4, 0, false },
  { 22230, "sa",           0, 1, false },
  { 22470, "mga",          3, 1, false },
  { 23030, "alaala",       7, 1, false },
  { 25410, "Puwede",       0, 0, true  },
  { 27410, "bang",         7, 0, false },
  { 30110, "kalimutan",    0, 1, false },
  { 31770, "muna",        10, 1, false },
  { 32670, "natin",        0, 0, true  },
  { 33640, "ang",          6, 0, false },
  { 33980, "mundo",       10, 0, false },
  { 37170, "At",           0, 0, true  },
  { 37370, "hawakan",      3, 0, false },
  { 38520, "mo",          11, 0, false },
  { 39550, "ang",          0, 1, false },
  { 39770, "kamay",        4, 1, false },
  { 40900, "ko?",         10, 1, false },
  { 41350, "Magmahalan",   0, 0, true  },
  { 45540, "na",          11, 0, false },
  { 45720, "walang",       0, 1, false },
  { 46530, "iniisip",      7, 1, false },
  { 48570, "na",           0, 0, true  },
  { 48790, "kung",         3, 0, false },
  { 49250, "ano",          8, 0, false },
  { 51960, "Ipakita",      0, 0, true  },
  { 53410, "lang",         8, 0, false },
  { 53950, "ang",          0, 1, false },
  { 54310, "totoong",      4, 1, false },
  { 55970, "tayo",        12, 1, false }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);
int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("@rence.szkyrob");
  delay(1300);
  lcd.clear();
  startPlaybackTime = millis();
}

void loop() {
  unsigned long elapsed = millis() - startPlaybackTime;
  if (currentWordIndex < totalWords) {
    if (elapsed >= lyrics[currentWordIndex].timeMs) {
      if (lyrics[currentWordIndex].clearScreen) {
        lcd.clear();
      }
      lcd.setCursor(lyrics[currentWordIndex].col, lyrics[currentWordIndex].row);
      lcd.print(lyrics[currentWordIndex].word);
      currentWordIndex++;
    }
  }
}