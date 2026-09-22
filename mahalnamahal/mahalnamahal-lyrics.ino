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
  {   900, "Sa",           0, 0, true  },
  {  1280, "lahat",        3, 0, false },
  {  2780, "'di",          9, 0, false },
  {  2960, "maari,",       0, 1, false },
  {  4080, "'di",          7, 1, false },
  {  4240, "maaring",      0, 0, true  },
  {  5100, "iwan",         8, 0, false },
  {  5980, "Wala",         0, 0, true  },
  {  6620, "ng",           5, 0, false },
  {  7720, "makakapigil",  0, 1, false },
  {  9140, "kahit",        0, 0, true  },
  {  9460, "na",           6, 0, false },
  {  9780, "bagyo",        9, 0, false },
  { 10380, "man",          0, 1, false },
  { 11040, "Paano",        0, 0, true  },
  { 11640, "kung",         6, 0, false },
  { 12760, "ikaw",        11, 0, false },
  { 13040, "na",           0, 1, false },
  { 13220, "mismo",        3, 1, false },
  { 14180, "kusang",       9, 1, false },
  { 14840, "lilisan?",     0, 0, true  },
  { 16100, "Paano",        0, 0, true  },
  { 16720, "ba?",          6, 0, false },
  { 22400, "Kung",         0, 0, true  },
  { 22560, "mawalay",      5, 0, false },
  { 23020, "ka",          13, 0, false },
  { 23160, "sa",           0, 1, false },
  { 23360, "buhay",        3, 1, false },
  { 24000, "ko",           9, 1, false },
  { 24900, "Kung",         0, 0, true  },
  { 25060, "pag-ibig",     5, 0, false },
  { 25540, "mo'y",         0, 1, false },
  { 25860, "maglaho",      5, 1, false },
  { 27440, "Paano",        0, 0, true  },
  { 28060, "na",           6, 0, false },
  { 28220, "kaya",         9, 0, false },
  { 28820, "ang",          0, 1, false },
  { 29040, "mundo?",       4, 1, false },
  { 32480, "Kung",         0, 0, true  },
  { 32660, "sa",           5, 0, false },
  { 32860, "oras",         8, 0, false },
  { 33140, "'di",         13, 0, false },
  { 33260, "ka",           0, 1, false },
  { 33440, "makita",       3, 1, false },
  { 35020, "Kung",         0, 0, true  },
  { 35200, "ika'y",        5, 0, false },
  { 35500, "napakalayo",   0, 1, false },
  { 36620, "na",          11, 1, false },
  { 37540, "May",          0, 0, true  },
  { 37880, "buhay",        4, 0, false },
  { 38200, "pa",          10, 0, false },
  { 38320, "kaya",        13, 0, false },
  { 38840, "'tong",        0, 1, false },
  { 39160, "puso?",        6, 1, false },
  { 42600, "'Yan",         0, 0, true  },
  { 42940, "lang",         5, 0, false },
  { 43160, "ang",         10, 0, false },
  { 43260, "maaari",       0, 1, false },
  { 44180, "natin,",       7, 1, false },
  { 45140, "sadyang",      0, 0, true  },
  { 46050, "matatanggap",  0, 1, false },
  { 48610, "Habang",       0, 0, true  },
  { 49130, "ako'y",        7, 0, false },
  { 49590, "may",          0, 1, false },
  { 49890, "buhay",        4, 1, false },
  { 52850, "Mahal",        0, 0, true  },
  { 53330, "na",           6, 0, false },
  { 53510, "mahal",        9, 0, false },
  { 53930, "kita",         0, 1, false },
  { 55230, "Higit",        0, 0, true  },
  { 55590, "pa",           6, 0, false },
  { 55850, "sa",           9, 0, false },
  { 56070, "iniisip",      0, 1, false },
  { 57850, "mo",           8, 1, false }
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