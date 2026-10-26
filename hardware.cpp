
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

// ---------------- PIN CONFIGURATION ----------------

#define IR_SENSOR 27

#define BUTTON1 25
#define BUTTON2 26

#define MOTOR_MOSFET 23

#define DF_RX 16   // ESP32 RX2
#define DF_TX 17   // ESP32 TX2

// Most IR obstacle sensors have LOW output on detection.
// Change to HIGH if your sensor works the opposite way.
#define IR_DETECTED LOW

// ---------------- DFPLAYER SETUP ----------------

HardwareSerial dfSerial(2);
DFRobotDFPlayerMini player;

// ---------------- BUTTON DEBOUNCING ----------------

unsigned long debounceDelay = 50;

int lastReading1 = HIGH;
int stableState1 = HIGH;
unsigned long lastDebounce1 = 0;

int lastReading2 = HIGH;
int stableState2 = HIGH;
unsigned long lastDebounce2 = 0;

// Detect a new button press
bool buttonPressed(int pin,
                   int &lastReading,
                   int &stableState,
                   unsigned long &lastDebounceTime) {

  int reading = digitalRead(pin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
    lastReading = reading;
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != stableState) {
      stableState = reading;

      if (stableState == LOW) {
        return true;
      }
    }
  }

  return false;
}

// ---------------- MOTOR CONTROL ----------------

void motorON() {
  digitalWrite(MOTOR_MOSFET, HIGH);
}

void motorOFF() {
  digitalWrite(MOTOR_MOSFET, LOW);
}

// ---------------- AUDIO FUNCTIONS ----------------

void playObstacleSound() {
  Serial.println("Obstacle detected!");
  Serial.println("Playing audio 0001");

  player.playMp3Folder(1);
}

void playRhymes() {
  Serial.println("Button 1 pressed");
  Serial.println("Playing Nursery Rhymes - 0002");

  player.playMp3Folder(2);
}

void playTables() {
  Serial.println("Button 2 pressed");
  Serial.println("Playing Tables - 0003");

  player.playMp3Folder(3);
}

// ---------------- SETUP ----------------

void setup() {

  Serial.begin(115200);

  // Configure pins
  pinMode(IR_SENSOR, INPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  pinMode(MOTOR_MOSFET, OUTPUT);

  // Initially switch motor OFF
  motorOFF();

  // Initialize DFPlayer Mini
  dfSerial.begin(9600, SERIAL_8N1, DF_RX, DF_TX);

  Serial.println("Initializing DFPlayer Mini...");

  if (!player.begin(dfSerial)) {

    Serial.println("DFPlayer Mini initialization failed!");
    Serial.println("Check SD card and connections.");

    while (true) {
      delay(1000);
    }
  }

  Serial.println("DFPlayer Mini ready!");

  // Set volume (0 to 30)
  player.volume(20);

  // Check obstacle at startup
  if (digitalRead(IR_SENSOR) == IR_DETECTED) {
    motorOFF();
    playObstacleSound();
  } else {
    motorON();
  }

  Serial.println("Robot system started!");
}

// ---------------- MAIN LOOP ----------------

void loop() {

  // Read IR sensor
  bool obstacleDetected =
      (digitalRead(IR_SENSOR) == IR_DETECTED);

  static bool previousObstacle = false;

  // OBSTACLE DETECTION
  if (obstacleDetected) {

    // Immediately stop motor
    motorOFF();

    // Play sound only once when obstacle first appears
    if (!previousObstacle) {
      playObstacleSound();
    }
  }

  // When obstacle is removed
  else {

    motorON();

    if (previousObstacle) {
      Serial.println("Obstacle removed!");
      Serial.println("Motor ON");
    }
  }

  previousObstacle = obstacleDetected;

  // BUTTON 1: NURSERY RHYMES
  if (buttonPressed(BUTTON1, lastReading1,
                    stableState1, lastDebounce1)) {

    playRhymes();
  }

  // BUTTON 2: TABLES
  if (buttonPressed(BUTTON2, lastReading2,
                    stableState2, lastDebounce2)) {

    playTables();
  }

  delay(5);
}
