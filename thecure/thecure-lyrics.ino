 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordTiming {
  unsigned long timeMs;
  const char* word;
};

const WordTiming lyrics[] = {
{80, "Why" },
{480, "can't" },
{1120, "you" },
{1540, "come" },
{1840, "stitch" },
{2400, "me" },
{2980, "up?" },
{3380, "Why" }, 
{4500, "can't" }, 
{4760, "ever" },
{5280, "be" },
{5880, "enough" }, 
{6740, "Why?" }, 
{6920, "can't" },  
{7880, "you" },
{8200, "come" }, 
{8480, "stitch" }, 
{9040, "me" }, 
{9660, "up?" },
{10060, "Why" }, 
{10500, "can't" }, 
{11660, "it" }, 
{12060, "ever" }, 
{12280, "be" }, 
{12580, "enough?" },
{18660, "It's" },
{18860, "not" }, 
{19340, "enough" },
{24820, "All" }, 
{25070, "because" }, 
{25730, "my" }, 
{26130, "head" }, 
{26910, "is" }, 
{27130, "full" }, 
{27490, "of" }, 
{27770, "poison," },
{28930, "and" }, 
{29390, "my" }, 
{29990, "heart" },
{30270, "is" }, 
{30470, "full" }, 
{30850, "of" }, 
{31090, "doubt" }, 
{32250, "I" }, 
{32390, "got" }, 
{32770, "toxins" }, 
{33930, "in" },  
{34050, "my" },
{34390, "bloodstream" },
{35450, "you" }, 
{35710, "tried" }, 
{36130, "so" }, 
{36430, "hard" },
{36970, "to" }, 
{37330, "suck" }, 
{38010, "out" }, 
{38930, "And" }, 
{39010, "it" }, 
{39930, "feels" },
{40050, "like" }, 
{40490, "medication," }, 
{42310, "and" }, 
{42510, "it's" }, 
{42790, "good" },
{43410, "for" }, 
{43670, "me" }, 
{44050, "I'm" }, 
{44690, "sure" }, 
{45170, "But" }, 
{45450, "it" }, 
{45730, "don't"}, 
{46070, "matter" }, 
{47010, "how" },
{47350, "your" }, 
{47810, "love" },
{48370, "feels" }, 
{48990, "anymore" }, 
{51070, "It'll" },
{51350, "never" }, 
{51770, "be" }, 
{51930, "the" }, 
{52810, "cure" } 
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