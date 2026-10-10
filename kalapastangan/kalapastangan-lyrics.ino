#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     0, "Mamatay" },
  {   1820, "akong" },
  {   2280, "nakangiti" },
  {   4420, "Kapag" },
  {   5040, "ikaw" },
  {   5600, "ang" },
  {   6180, "nasa" },
  {   7480, "aking" },
  {   8160, "tabi" },
  {   8920, "Mabubuhay" },
  {   10440, "akong" },
  {   11120, "nagsisisi" },
  {   13380, "Kapag" },
  {  13740, "'sang" },
  {  14190, "araw" },
  {  14870, "hindi" },
  {  15530, "kita" },
  {  16350, "mapapangiti" },
  {  17790, "Kalapastangan" },
  {  19330, "and" },
  {  19590, "'di" },
  {  19990, "ka" },
  {  20470, "ibigin" },
  {  22530, "Kalokohan" },
  {  23570, "ang" },
  {  23890, "'di" },
  {  24070, "ka" },
  {  24890, "isipin" },
  {  26650, "Kung" },
  {  27100, "ang" },
  {  27330, "mundo" },
  {  28070, "ay" },
  {  28210, "biglang" },
  {  29110, "gugunawin"},
  {  31290, "Ikaw"},  
  {  31730, "ang"},
  {  32110, "una"},
  {  32610, "kong"},
  {  32910, "hahanapin"}
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