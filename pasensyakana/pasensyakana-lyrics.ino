#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {     22, "Pasensya" },
  {   1032, "ka" },
  {   1070, "na" },
  {   3140, "at" },
  {   3440, "'di" },
  {   3800, "ko" },
  {   4160, "na" },
  {   4540, "rin" },
  {   5260, "madama" },
  {   7040, "Kay" },
  {   7340, "tagal" },
  {   8080, "kitang" },
  {   8780, "hinihintay" },
  {  11640, "Pasensya" },
  {  12740, "ka" },
  {  13120, "na" },
  {  14560, "at" },
  {  14840, "kaya" },
  {  15580, "ko" },
  {  15960, "ng" },
  {  16660, "mag" },
  {  17020, "isa" },
  {  18420, "Kalayaan" },
  {  19820, "sa" },
  {  20200, "kamay" },
  {  20920, "ng" },
  {  21300, "lumbay" },
  {  23080, "Pasensya" },
  {  24160, "ka" },
  {  24540, "na" },
  {  28800, "Pasensya" },
  {  29880, "ka" },
  {  30200, "na" }
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