int volume = 0;
int volumePin = A0;

int lowPass = 0;
int lowPassPin = A1;

int buttonState = 0;
int buttonPin = 2;

int pressedState = 0;
int pressedPin = 7;

int UDPin = A4;
int UD;

int LRPin = A5;
int LR;

int currentInput = 0;
const int numInputs = 6;

void setup()
{
    pinMode(pressedPin, INPUT);
    digitalWrite(pressedPin, HIGH);
    Serial.begin(9600);
}

void loop()
{
    // Read values from analog pins based on the current analog input
    switch (currentInput) {
        case 0:
            volume = analogRead(volumePin);
            break;
        case 1:
            lowPass = analogRead(lowPassPin);
            break;
        case 2:
            buttonState = digitalRead(buttonPin);
            break;
        case 3:
            LR = analogRead(LRPin);
            break;
        case 4:
            UD = analogRead(UDPin);
            break;
        case 5:
            pressedState = digitalRead(pressedPin);
            break;
    }
    // Print values to the Serial Monitor
    Serial.print(volume);
    Serial.print(" ");
    Serial.print(lowPass);
    Serial.print(" ");
    Serial.print(buttonState);
    Serial.print(" ");
    Serial.print(UD);
    Serial.print(" ");
    Serial.print(LR);
    Serial.print(" ");
    Serial.print(pressedState);
    Serial.print("\n");
  
    currentInput = (currentInput + 1) % numInputs;  // Move to the next analog input
    delay(10);  // Add a delay to avoid flooding the Serial Monitor
}
