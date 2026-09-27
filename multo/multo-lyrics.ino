#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     80, "Hindi" },
  {   520, "na" },
  {   2080, "makalaya" },
  {   4700, "dinadalaw" },
  {   6160, "mo" },
  {   6420, "'ko" },
  {   6700, "bawat" },
  {   7280, "gabi" },
  {   9300, "Wala" },
  {   9920, "mang" },
  {  10740, "nakikita" },
  {  13940, "haplos" },
  {  14540, "mo'y" },
  {  15120, "ramdam" },
  {  15820, "pa" },
  {  15920, "rin" },
  {  16200, "sa" },
  {  16540, "dilim" },
  {  18540, "Hindi" },
  {  19140, "na" },
  {  19980, "na-nanaginip" },
  {  23140, "Hindi" },
  {  23740, "na" },
  {  24600, "ma-makagising" },
  {  27760, "Pasindi" },
  {  29200, "na" },
  {  30080, "ng" },
  {  30740, "ilaw" },
  {  32380, "Minumulto" },
  {  33580, "na" },
  {  33840, "'ko" },
  {  34160, "ng" },
  {  34420, "damdamin" },
  {  35300, "ko" },
  {  36440, "ng" },
  {  36740, "damdamin" },
  {  37600, "ko" },
  {  37920, "Hindi" },
  {  38760, "mo" },
  {  39040, "ba" },
  {  39700, "ako" },
  {  40220, "lilisanin?" },
  {  42760, "Hindi" },
  {  43360, "pa" },
  {  43660, "ba" },
  {  44220, "sapat" },
  {  45100, "pagpapahirap" },
  {  46520, "sa 'kin?" },
  {  47100, "Hindi" },
  {  48000, "na" },
  {  48280, "ba" },
  {  48840, "ma-mamamayapa?" },
  {  51220, "Hindi" },
  {  52600, "na" },
  {  52900, "ba" },
  {  53460, "ma-mamamayapa?" },
  {  55480, "Hindi" },
  {  56060, "na" },
  {  56880, "makalaya..." }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);
int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

uint8_t currentCol = 0;
uint8_t currentRow = 0;

void printFittedWord(const char* word) {
  int len = strlen(word);
  bool isCapital = (word[0] >= 'A' && word[0] <= 'Z');

  if (isCapital && (currentCol > 0 || currentRow > 0)) {
    lcd.clear();
    currentRow = 0;
    currentCol = 0;
  } else if (currentCol > 0 && (currentCol + 1 + len > 16)) {
    if (currentRow == 0) {
      currentRow = 1;
      currentCol = 0;
    } else {
      lcd.clear();
      currentRow = 0;
      currentCol = 0;
    }
  }

  if (currentCol > 0) {
    lcd.setCursor(currentCol, currentRow);
    lcd.print(" ");
    currentCol++;
  }

  lcd.setCursor(currentCol, currentRow);
  lcd.print(word);
  currentCol += len;
}

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
      printFittedWord(lyrics[currentWordIndex].word);
      currentWordIndex++;
    }
  }
}