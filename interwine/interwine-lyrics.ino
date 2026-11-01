#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
  {    360, "Take" },
  {   1740, "this" },
  {   3080, "heart" },
  {   4340, "to" },
  {   5040, "be" },
  {   5360, "yours," },
  {   7280, "only" },
  {   8280, "yours" },
  {   9660, "And" },
  {  10260, "every" },
  {  10860, "part" },
  {  12800, "of" },
  {  13450, "you" },
  {  14870, "will" },
  {  15450, "be" },
  {  16050, "mine," },
  {  17750, "only" },
  {  18670, "mine" },
  {  20310, "Even" },
  {  20870, "the" },
  {  21110, "ghosts" },
  {  22730, "and" },
  {  23270, "all" },
  {  23510, "the" },
  {  23710, "fears" },
  {  25530, "Even" },
  {  26130, "the" },
  {  26490, "most" },
  {  27390, "uncertain" },
  {  28990, "years," },
  {  30010, "I'll" },
  {  30390, "hold" },
  {  31130, "you" },
  {  31690, "close" },
  {  33850, "It" },  
  {  34270, "starts" },
  {  35670, "tonight," },
  {  39350, "the" },__
  {  39550, "night" },
  {  40050, "when" },
  {  40490, "our" },
  {  40650, "lives" },
  {  41490, "interwine" }
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