//Prateek
//wwww.justdoelectronics.com
//https://www.youtube.com/c/JustDoElectronics/videos


//Prteek
//www.prateeks.in

#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { 12, 11, 10, 9 };
byte colPins[COLS] = { 8, 7, 6 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "1234";
String mypassword;

int redled = 13;
int lock = 2;

int counter = 0;
int attempts = 0;
int max_attempts = 3;

void setup() {
  Serial.begin(9600);

  pinMode(redled, OUTPUT);
  pinMode(lock, OUTPUT);

  digitalWrite(redled, LOW);
  digitalWrite(lock, LOW);

  Serial.println("enter password");
}

void loop() {

  keypadfunction();
}

void keypadfunction() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    counter = counter + 1;
  }
  if (key == '1') {

    mypassword = mypassword + 1;
  }

  if (key == '2') {

    mypassword = mypassword + 2;
  }

  if (key == '3') {

    mypassword = mypassword + 3;
  }

  if (key == '4') {

    mypassword = mypassword + 4;
  }

  if (key == '5') {

    mypassword = mypassword + 5;
  }

  if (key == '6') {

    mypassword = mypassword + 6;
  }

  if (key == '7') {

    mypassword = mypassword + 7;
  }

  if (key == '8') {

    mypassword = mypassword + 8;
  }

  if (key == '9') {

    mypassword = mypassword + 9;
  }

  if (key == '0') {

    mypassword = mypassword + 0;
  }


  if (key == '*') {
    Serial.println(mypassword);

    if (password == mypassword) {
      digitalWrite(lock, HIGH);
      delay(5000);
      digitalWrite(lock, LOW);
      mypassword = "";
      counter = 0;
    } else {
      Serial.println("wrong");
      digitalWrite(lock, LOW);
      attempts = attempts + 1;
      if (attempts >= max_attempts) {
        digitalWrite(redled, HIGH);
        delay(5000);
        digitalWrite(redled, LOW);
        attempts = 0;
      }
      mypassword = "";
      counter = 0;
    }
  }
}
