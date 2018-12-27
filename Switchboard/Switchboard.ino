#include <Mouse.h>
#include <Keyboard.h>

int buttonAPin = 9;     // the number of the pushbutton pin
int buttonBPin = 8;
int buttonAState = 0;         // for reading the button
int buttonBState = 0;

boolean pressedA = false;
boolean pressedB = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonAPin, INPUT_PULLUP); // tells the arduino board that the thing in place 2 is input. Either it can have power and have a value of 1 or 0.
  pinMode(buttonBPin, INPUT_PULLUP);

  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  if (buttonAState == LOW && pressedA == false) { // Power is low because when the button is pressed the power goes to ground
    Mouse.press(MOUSE_LEFT);
    pressedA = true;
  }
  else if (buttonAState == HIGH && pressedA == true){
    Mouse.release(MOUSE_LEFT);
    pressedA = false;
  }

  if (buttonBState == LOW && pressedB == false) { // Power is low because when the button is pressed the power goes to ground
    Keyboard.press(' ');
    pressedB = true;
  }
  else if (buttonBState == HIGH && pressedB == true){
    Keyboard.release(' ');
    pressedB = false;
  }
  
}
