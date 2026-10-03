#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {   1060, "And" },
  {   1400, "tell" },
  {   1860, "me" },
  {   2280, "you" },
  {   2660, "love" },
  {   3520, "me" },
  {   4640, "come" },
  {   5120, "back" },
  {   5560, "and" },
  {   5940, "haunt" },
  {   6780, "me" },
  {   8060, "Oh," },
  {   8480, "and" },
  {   8860, "I" },
  {   9180, "rush" },
  {  10040, "to" },
  {  10820, "the" },
  {  11140, "start" },
  {  14500, "Runnin'" },
  {  15380, "in" },
  {  15720, "circles" },
  {  17760, "chasin'" },
  {  18720, "our" },
  {  19000, "tails" },
  {  21080, "Comin'" },
  {  22320, "back" },
  {  23180, "as" },
  {  23960, "we" },
  {  24400, "are" },
  {  27280, "Nobody" },
  {  28840, "said" },
  {  29780, "it" },
  {  30080, "was" },
  {  30540, "easy" },
  {  33840, "Oh," },
  {  34280, "it's" },
  {  34540, "such" },
  {  35040, "a" },
  {  35360, "shame" },
  {  36240, "for" },
  {  36660, "us" },
  {  37040, "to" },
  {  37420, "part" },
  {  40390, "Nobody" },
  {  41950, "said" },
  {  42890, "it" },
  {  43190, "was" },
  {  43690, "easy" },
  {  46870, "No" },
  {  47710, "one" },
  {  48170, "ever" },
  {  48850, "said" },
  {  49410, "it" },
  {  49770, "would" },
  {  50170, "be" },
  {  50550, "so" },
  {  51370, "hard" },
  {  55950, "I'm" },
  {  56350, "goin'" },
  {  57150, "back" },
  {  57590, "to" },
  {  57990, "the" },
  {  58350, "start" }
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