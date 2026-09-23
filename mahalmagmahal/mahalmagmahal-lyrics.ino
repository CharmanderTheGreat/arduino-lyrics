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
  {    40, "Ngunit",       0, 0, true  },
  {  1180, "saka",         7, 0, false },
  {  1880, "na",          12, 0, false },
  {  2160, "lang",         0, 1, false },
  {  2880, "pakakawalan",  5, 1, false },
  {  4980, "Kung",         0, 0, true  },
  {  5220, "may",          5, 0, false },
  {  5660, "sigurado",     0, 0, true  },
  {  6560, "na",           9, 0, false },
  {  6780, "sa",           0, 1, false },
  {  7000, "kawalan",      3, 1, false },
  {  8700, "Mahal",        0, 0, true  },
  {  9340, "ngayon",       6, 0, false },
  { 10400, "ang",          0, 1, false },
  { 10820, "magmahal",     4, 1, false },
  { 12440, "Mahal",        0, 0, true  },
  { 13080, "kita,",        6, 0, false },
  { 14080, "pero",         0, 1, false },
  { 14960, "mahal",        5, 1, false },
  { 18020, "Mahal",        0, 0, true  },
  { 18740, "na",           6, 0, false },
  { 19020, "ang",          9, 0, false },
  { 19700, "bigas",        0, 1, false },
  { 20600, "Pati",         0, 0, true  },
  { 21560, "lata",         5, 0, false },
  { 22520, "ng",          10, 0, false },
  { 22960, "sardinas",     0, 1, false },
  { 24460, "Kung",         0, 0, true  },
  { 24940, "mamahalin",    5, 0, false },
  { 27520, "kita",         0, 1, false },
  { 27980, "ngayon",       5, 1, false },
  { 29480, "Sabay",        0, 0, true  },
  { 30200, "tayong",       6, 0, false },
  { 31140, "magugutom",    0, 1, false },
  { 33080, "'Di",          0, 0, true  },
  { 33260, "sapat",        4, 0, false },
  { 34040, "ang",         10, 0, false },
  { 34460, "sahod",        0, 1, false },
  { 35480, "ko",           6, 1, false },
  { 35960, "Kahit",        0, 0, true  },
  { 37200, "tapat",        6, 0, false },
  { 37860, "ako",         12, 0, false },
  { 38800, "sa 'yo",       0, 1, false },
  { 39720, "Anong",        0, 0, true  },
  { 40600, "silbi",        6, 0, false },
  { 41620, "nitong",       0, 1, false },
  { 42780, "pagmamahal",   0, 0, true  },
  { 44480, "Kung",         0, 0, true  },
  { 44740, "lahat",        5, 0, false },
  { 45380, "din",         11, 0, false },
  { 45700, "ay",           0, 1, false },
  { 46560, "nagmamahal?",  3, 1, false },
  { 48380, "Ayoko",        0, 0, true  },
  { 49320, "lang",         6, 0, false },
  { 50020, "namang",       0, 1, false },
  { 50940, "makita",       7, 1, false },
  { 52040, "ka",          14, 1, false },
  { 55660, "Kinikilig",    0, 0, true  },
  { 57330, "habang",       0, 1, false },
  { 58170, "sa",           7, 1, false },
  { 58450, "hirap",        0, 0, true  },
  { 60010, "ay",           6, 0, false },
  { 61830, "nagdurusa",    0, 1, false }
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