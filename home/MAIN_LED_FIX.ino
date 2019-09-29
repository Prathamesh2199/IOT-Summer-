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
///////////////////////////////pre upload ERROR////////////////////////////////////
//#error delete this line after you make sure that the Tx and Rx pin are disconnected
//Tx and Rx pins of the HC06 module should not be connected while we upload the
//"Sketch" to the arduino. The code won't be upload if the pins are connected
///////////////////////////////////////////////////////////////////////////////////
char color=0; //store the received byte here

//define the RGB pind
int red = 3;
int green = 5;
int blue = 9;

char received;

void setup()  { 
  Serial.begin(9600);     //Start the serial comunication for the bluetooth module
  pinMode(red, OUTPUT);   //Red color pwm pin defined as output
  pinMode(green, OUTPUT); //Green color pwm pin defined as output
  pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output
  
  //Give first value of the PWM 0, we start with the RGB LEDs off
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);

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

  //LEDs off
  if (color == 'n')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //White
  if (color == 'w')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Red
  if (color == 'r')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Green
  if (color == 'g')
  {
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //Blue
  if (color == 'b')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //Red
  if (color == 'o')
  {
    analogWrite(red,255);
    analogWrite(green,105);
    analogWrite(blue,180);
  }
  //Violet
  if (color == 'v')
  {
    analogWrite(red,148);
    analogWrite(green,255);
    analogWrite(blue,107);
  }
  //Pink
  if (color == 'c')
  {
    analogWrite(red,255);
    analogWrite(green,192);
    analogWrite(blue,203);
  }
  //Yellow 
  if (color == 'y')
  {
    analogWrite(red,0);
    analogWrite(green,51);
    analogWrite(blue,255);
  }  
}
