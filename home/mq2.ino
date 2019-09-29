
int led = 10;
int smokeA0 = A5;

// Your threshold value. You might need to change it.
int sensorThres = 300;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  { digitalWrite(led,HIGH);

}

else {

digitalWrite(led,LOW);

}
  delay(100);
}
