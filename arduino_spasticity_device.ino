const int ledPin =  12;// the number of the output pin

// Variables will change:
int ledState = LOW;             // ledState used to set the motor state

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time motor was updated

// constants won't change:
const long interval = 5000;           // interval at which to spin (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you put code that needs to be running all the time.

  // check to see if it's time to spin the motor; that is, if the difference
  // between the current time and last time you spun the motor is bigger than
  // the interval at which you want to spin the motor.
  unsigned long currentMillis = millis();
  if (currentMillis < 20000){
  if (currentMillis - previousMillis >= interval) {
    // save the last time you spun the motor
    previousMillis = currentMillis;

    // if the motor is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the motor with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  }
  else {
    pinMode(ledPin, INPUT);
  }
}
