#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize the I2C LCD
const byte ROWS = 4;  // Number of rows in the keypad
const byte COLS = 3;  // Number of c

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  // Keypad row pins connected to Arduino
byte colPins[COLS] = {5, 4, 3};  // Keypad column pins connected to Arduino

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int selectedOption = 0;

void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Menu");
  lcd.setCursor(0, 1);
  lcd.print("----------------");

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. Rice, meat");
  lcd.setCursor(0, 1);
  lcd.print("2. Ugali, meat");
  
  char key = keypad.getKey();
  if (key) {
    if (key == '1') {
      selectedOption = 1;
      lcd.clear();
      lcd.print("Your rice will be");
      lcd.setCursor(0, 1);
      lcd.print("served shortly");
    } else if (key == '2') {
      selectedOption = 2;
      lcd.clear();
      lcd.print("Your ugali will be");
      lcd.setCursor(0, 1);
      lcd.print("served shortly");
    }
    delay(2000);
    lcd.clear();
  }
}
