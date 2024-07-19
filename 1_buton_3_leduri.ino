const int buttonPin = A1;
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime=0;
long debounceDelay =50;
void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin1, ledState);
  digitalWrite(ledPin2, ledState);
  digitalWrite(ledPin3, ledState);
}
void loop(){
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState){
     lastDebounceTime = millis();
  }
  if((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if(buttonState ==HIGH){
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin1, ledState);
  digitalWrite(ledPin2, ledState);
  digitalWrite(ledPin3, ledState);
  lastButtonState=reading;
}
