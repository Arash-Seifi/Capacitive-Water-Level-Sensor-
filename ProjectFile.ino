const int sensorPin = 2; // Digital pin connected to Electrode 1 and capacitor
const int ledLow = 3;    // LED for low water level
const int ledMid = 4;    // LED for medium water level
const int ledHigh = 5;   // LED for high water level

unsigned long chargeTime; // Variable to store charging time
int waterLevel;           // Variable to store mapped water level

void setup() {
  pinMode(sensorPin, OUTPUT); // Configure the sensor pin as output
  pinMode(ledLow, OUTPUT);
  pinMode(ledMid, OUTPUT);
  pinMode(ledHigh, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Step 1: Discharge the capacitor
  pinMode(sensorPin, OUTPUT); // Set sensor pin as output
  digitalWrite(sensorPin, LOW); // Discharge capacitor to ground
  delay(10); // Wait for capacitor to fully discharge
  
  // Step 2: Measure charging time
  pinMode(sensorPin, INPUT); // Set sensor pin as input
  unsigned long startTime = micros(); // Record start time
  while (digitalRead(sensorPin) == LOW) {
    // Wait until the pin goes HIGH (capacitor is charged)
  }
  chargeTime = micros() - startTime; // Calculate charging time
  
  // Step 3: Determine water level based on charge time
  if (chargeTime < 10800) {
    // Low water level
    digitalWrite(ledLow, HIGH);
    digitalWrite(ledMid, LOW);
    digitalWrite(ledHigh, LOW);
  } else if (chargeTime >= 10900 && chargeTime < 11250) {
    // Medium water level
    digitalWrite(ledLow, LOW);
    digitalWrite(ledMid, HIGH);
    digitalWrite(ledHigh, LOW);
  } else {
    // High water level
    digitalWrite(ledLow, LOW);
    digitalWrite(ledMid, LOW);
    digitalWrite(ledHigh, HIGH);
  }

  // Step 4: Print charge time and water level for debugging
  Serial.print("Charge Time: ");
  Serial.print(chargeTime);
  Serial.println(" microseconds");
  
  delay(500); // Short delay for stability
}
