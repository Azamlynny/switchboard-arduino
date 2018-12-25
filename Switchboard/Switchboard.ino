#include <Mouse.h>

int buttonPin = 9;     // the number of the pushbutton pin
int buttonState = 0;         // for reading the button
boolean pressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP); // tells the arduino board that the thing in place 2 is input. Either it can have power and have a value of 1 or 0.
  Mouse.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && pressed == false) {
    Mouse.press(MOUSE_LEFT);
    pressed = true;
  }
  else if (buttonState == HIGH && pressed == true){
    Mouse.release(MOUSE_LEFT);
    pressed = false;
  }

}
