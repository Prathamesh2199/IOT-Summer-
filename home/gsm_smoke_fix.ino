int led = 10;
int smokeA0 = A5;
// My threshold value
int sensorThres = 300; //Change this thresold value according to your sensitivity

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    
     Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+918108932222\"\r"); // Replace x with mobile number
     Serial.println("Gas Leakage Alert");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     delay(100);
     digitalWrite(led,HIGH);
     Serial.println("ATD8108932222;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;

  }
  else
  {
    
    digitalWrite(led,LOW);
  }
  delay(50);
}
