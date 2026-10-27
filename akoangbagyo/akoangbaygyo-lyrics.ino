#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     20, "Ako," },
  {   1440, "ako," },
  {   2360, "ako" },
  {   2900, "ang" },
  {   3200, "bagyo" },
  {   5120, "Kulimlim" },
  {   5760, "ng" },
  {   6060, "langit" },
  {   7400, "sa" },
  {   7920, "inyong" },
  {   8900, "dalawa" },
  {  10820, "Bulong" },
  {  11380, "ko" },
  {  11720, "sa" },
  {  12100, "hangin" },
  {  13140, "\"sana" },
  {  13860, "di" },
  {  14220, "kayo" },
  {  14560, "masaya\"" },
  {  16560, "sa" },
  {  16740, "tibay" },
  {  17500, "ng" },
  {  17840, "bahay" },
  {  18880, "na" },
  {  19600, "titirhan" },
  {  20700, "nyo" },
  {  22440, "tatangayin" },
  {  23730, "ko" },
  {  24250, "bawat" },
  {  24950, "yero" },
  {  27690, "dilim" },
  {  28770, "ng" },
  {  28890, "paligid" },
  {  30310, "buhos" },
  {  31030, "ng" },  
  {  31630, "emosyon" },
  {  33730, "Tunog" },
  {  34210, "ng" },
  {  34610, "pag" },
  {  35590, "ibig" },
  {  35990, "sa" },
  {  36370, "sama" },
  {  37330, "ng" },
  {  37430, "panahon" },
  {  39430, "Sa" },
  {  39610, "tibay" },
  {  40590, "ng" },
  {  40710, "bahay" },
  {  41750, "na" },
  {  42450, "titirhan" },  
  {  43510, "nyo" },
  {  45350, "Gigibain" },
  {  46550, "ko" },
  {  47130, "mga" },
  {  47790, "pader" },
  {  48510, "nyo" },
  {  50290, "Dahil" },
  {  50730, "ako," },
  {  52350, "ako" },
  {  52990, "ang" },
  {  53210, "bagyo" }
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
  } 
  else if (currentCol > 0 && (currentCol + 1 + len > 16)) {
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