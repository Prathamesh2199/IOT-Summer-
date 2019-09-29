#include <SoftwareSerial.h>

int bluetoothTx = 7;
int bluetoothRx = 8;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
 pinMode(3,OUTPUT); // blue pin of RGB LED
 pinMode(5,OUTPUT); // Green pin of RGB LED
 pinMode(6,OUTPUT); // Red pin of RGB LED

 digitalWrite(3,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,HIGH);
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int color1 = bluetooth.read();
    unsigned int color2 = bluetooth.read();
    unsigned int color = (color2 *256) + color1;
    Serial.println(color);
   
    if (color >= 1000 && color <1255){
    int blue = color;
    blue = map(blue, 1000,1255,0,255);
    int blue1 = 255-blue;
    analogWrite(6,blue1);
    Serial.println(blue1);
    delay(10);

    }
   
    if (color >=2000 && color <2255){
      int green = color;
      green = map(green,2000,2255,0,255);
      int green1 = 255 - green;
      analogWrite(5,green1);
      Serial.println(green1);
      delay(10);
     
    }
   
    if (color >=3000 && color < 3255){
      int red = color;
      red = map(red, 3000, 3255,0,255);
      int red1 = 255 - red;
      analogWrite(3,red1);
      Serial.println(red1);
      delay(10);
    }
   

  }


}
