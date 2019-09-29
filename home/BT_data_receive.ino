/* RGB LED strip with arduino and Android App bluetooth connection
 *  http://www.electronoobs.com
 *  
ARDUINO       RGB      
  3          RED
  5          GREEN
  9          BLUE

Bluetooth HC-06 module and Arduino
ARDUINO    Bluetooth HC-06 
 0 (RX)       TX
 1 (TX)       RX
 5V           VCC
 GND          GND
 */

int color = 0;

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
 } 
 
void loop()  { 
  
  if(Serial.available()>0){
    // read the bluetoot data and store it
    color = Serial.read();
    char Rec = char(color);
    if (Rec != '0')
    {
    Serial.println(Rec); //This is to visualise the received character on the serial monitor
    }
  }
}
  
  

