#define DECODE_NEC
#include <IRremote.hpp>

// Motor pins
const int in1 = 12;
const int in2 = 11;
const int in3 = 10;
const int in4 = 9;

// IR receiver pin
const int recvPin = 7;

// IR codes (CHANGE if needed)
const unsigned long IR_FORWARD = 0xF30CFF00; // RIGHT
const unsigned long IR_STOP    = 0xE916FF00; // OK
const unsigned long IR_BACKWARD = 0xE718FF00;
const unsigned long IR_LEFT     = 0xF708FF00;
const unsigned long IR_RIGHT    = 0xE31CFF00;


unsigned long lastCommand = 0;
unsigned long lastTime = 0;
const unsigned long timeout = 200; // ms

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  stopMotors();

  Serial.begin(9600);
  IrReceiver.begin(recvPin, ENABLE_LED_FEEDBACK);

  Serial.println("IR Forward / Stop Ready");
}

void loop() {

  if (IrReceiver.decode()) {

    // Save command (ignore repeat flag issues)
    lastCommand = IrReceiver.decodedIRData.decodedRawData;
    lastTime = millis();

    Serial.print("IR: 0x");
    Serial.println(lastCommand, HEX);

    IrReceiver.resume();
  }

  // ---- ACTIONS ----
  if (lastCommand == IR_FORWARD) {
    // FORWARD
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if (lastCommand == IR_BACKWARD) {
    // BACKWARD
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (lastCommand == IR_LEFT) {
    // TURN LEFT
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if (lastCommand == IR_RIGHT) {
    // TURN RIGHT
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (lastCommand == IR_STOP) {
    stopMotors();
  }



  // Auto stop when button released
  if (millis() - lastTime > timeout) {
    stopMotors();
    lastCommand = 0;
  }
}


