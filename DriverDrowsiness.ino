// Define the pulse sensor pin
#define pulsePin A0

// Define the vibration motor pin
#define motorPin 9

// Define the threshold for drowsiness
int threshold = 55;

void setup()
{
    // Initialize the pulse sensor pin as an input
    pinMode(pulsePin, INPUT);

    // Initialize the vibration motor pin as an output
    pinMode(motorPin, OUTPUT);

    // Initialize the serial communication for debugging
    Serial.begin(9600);
}

void loop()
{
    // Read the value from the pulse sensor
    int pulseValue = analogRead(pulsePin);

    // Convert the pulse value to beats per minute (BPM)
    int BPM = 60000 / pulseValue;

    // Debugging output
    Serial.print("BPM: ");
    Serial.print(BPM);
    Serial.println(" bpm");

    // If the BPM is below the drowsiness threshold, activate the vibration motor
    if (BPM < threshold)
    {
        digitalWrite(motorPin, HIGH);
    }
    else
    {
        digitalWrite(motorPin, LOW);
    }

    // Wait for 100 ms before taking another measurement
    delay(100);
}
