#define sensorPin 8
#define relayPin 7

int lastSensorValue;

void setup()
{
  Serial.begin(9600);
  Serial.println("V2");
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW);
}

void loop()
{
  int sensorValue = digitalRead(sensorPin);
  if (lastSensorValue != sensorValue)
  {
    lastSensorValue = sensorValue;
    if (sensorValue == 1)
    {
      Serial.println("-> OPEN");
      digitalWrite(relayPin, LOW);
    }
    else
    {
      Serial.println("-> CLOSE");
      digitalWrite(relayPin, HIGH);
    }
  }
}
