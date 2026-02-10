// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
const int ledPin = 8;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
lcd.begin(16, 2);
pinMode(switchPin,INPUT);
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
lcd.print("Ask the");

lcd.setCursor(0, 1);
lcd.print("Crystal Ball!");
}

void loop() {
switchState = digitalRead(switchPin);

if (switchState != prevSwitchState) {
if (switchState == LOW) {
reply = random(10);
  lcd.clear();
lcd.setCursor(0, 0);
lcd.print("The ball says:");
lcd.setCursor(0, 1);
switch(reply){
  case 0:
    lcd.print("Yes");
    digitalWrite(ledPin, LOW);
    break;

  case 1:
    lcd.print("Most likely");
    digitalWrite(ledPin, LOW);
    break;

  case 2:
    lcd.print("Certainly");
    digitalWrite(ledPin, LOW);
    break;

  case 3:
    lcd.print("Outlook good");
    digitalWrite(ledPin, LOW);
    break;

  case 4:
    lcd.print("Unsure");
    digitalWrite(ledPin, LOW);
    break;

  case 5:
    lcd.print("Ask again");
    digitalWrite(ledPin, LOW);
    break;

  case 6:
    lcd.print("Doubtful");
    digitalWrite(ledPin, LOW);
    break;

  case 7:
    lcd.print("No");
    digitalWrite(ledPin, LOW);
    break;

  case 8:
    lcd.print("Kas teed nalja?");
    digitalWrite(ledPin, LOW);
    break;

  case 9:
    lcd.print("Eriti hea");
    digitalWrite(ledPin, HIGH);
    break;
}
}
}
prevSwitchState = switchState;
}