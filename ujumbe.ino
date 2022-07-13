#include <SoftwareSerial.h>

SoftwareSerial sim800l(2, 3); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted

#define button1 7 //Button pin, on the other pin it's wired with GND
#define input2 6

bool button_State; //Button state
bool input_State;


void setup()
{
 
  pinMode(button1, INPUT); //The button is always on HIGH level, when pressed it goes LOW
  pinMode (input2, INPUT);
  sim800l.begin(9600);   //Module baude rate, this is on max, it depends on the version
  Serial.begin(9600);   
  delay(1000);
}
 
void loop()
{
  

  button_State = digitalRead(button1);   //We are constantly reading the button State
 
  if (button_State == HIGH) {            //And if it's pressed
    Serial.println("Sensor Detected");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    
    SendSMS();                          //And this function is called

 }
 
  if (sim800l.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read()); 
  }
}


 void input(){
   input_State = digitalRead(button1);   //We are constantly reading the button State
 
  if (input_State == HIGH) {            //And if it's pressed
    Serial.println("Sensor Detected");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    
    SendSMS();                          //And this function is called

 }
 
  if (sim800l.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read()); 
  }
 }
void SendSMS()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+255754891671\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  //sim800l.print("AT+CMGS=\"+255754891671\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("Computer component out of the Lab");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}

void SendSMS2()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+255754891671\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  //sim800l.print("AT+CMGS=\"+255754891671\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("System Detect Unecpected movement at Lab 1");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}
 



 
