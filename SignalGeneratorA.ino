/* Sketch for dataLogger
   Built from AnalogReadSerialOut_test
   modified Apr 09, 2014
   Original sketch written to test data logging gui.
   Gui sends '2' to serial communiation initiating program
   LaunchPad sends serial header information followed by "&"
   LaunchPad then sends serial data to be logged.
   At the end of serial data, LaunchPad sends "@" symbol, indicating
     end of run.
  Based on AnalogInOutSerial sketch from 
  Energia Analog examples by Tom Igoe
  Analog input, analog output, serial output
 
  The circuit:
   PWM output on P1_6 to resistor to analog read on P1_0.  
   Capacitor bridges P1_0 to ground, generating analog signal. 
   Analog read result printed to the serial monitor.
 
modified November 16, 2013 
 This code is in the public domain.
 
 */
#include<Energia.h>   //need this for SPI to work
#include "wiring_analog.c"    // need this for pwm at high frequency, resolution

//const int analogInA = A11;  // Analog input pin that the potentiometer is attached to
const int analogOutA = PF_2; // pwm pin used to establish reference voltage
//const int analogInB = A9;  // Analog input pin that the potentiometer is attached to
const int analogOutB = PF_3; // pwm pin used to establish reference voltage
//int sensorA = 0;        // value read from the pot
//int sensorB = 0;
int maxA = 100;        // max value output to the PWM (analog out)
int offset = 1650;
int per = 700;    // period in mseconds
int per2 = 8000;
//int nLoop =1;
//int i;
int j;
unsigned int time;
int delay1 = 50;  
int pwmClock = 40000; 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
time = 0;
//  readSerial();
/*  Serial.print("number of loops = ");
  Serial.println(nLoop);
  Serial.print("time");
  Serial.print('\t');
  Serial.println("sensor");    
    Serial.println("&");  */   // signals end of header, begin writting data 
  for (int i=0; i<2000; ++i){
    float phase=6.28*time/per;
    float phase2 = 6.28*time/per2;
    float ampC = sin(phase2);
    float ampA = maxA*sin(phase)*ampC+offset;
    float ampB = maxA*cos(phase)*ampC+offset;
    PWMWrite(analogOutA,3300,ampA,pwmClock);
    PWMWrite(analogOutB,3300,ampB,pwmClock);
//    analogWrite(analogOutA,ampA);
//    analogWrite(analogOutB,ampB);
    delay (delay1);
    Serial.print(time);
    Serial.print('\t');
    Serial.print(ampA);  
    Serial.print('\t');
    Serial.println(ampB);  
        time = time + delay1;
/*    for (j=0; j<25; ++j) {
    analogWrite(analogOutPin, j*10);
    delay (200);
    sensorValue = analogRead(analogInA);  
    time +=200;
    Serial.print(time);
    Serial.print('\t');
    Serial.println(sensorA);    
        }*/
 //   for (j=25; j>=0; --j) {
   // analogWrite(analogOutPin, j*10);
/*    delay (200);
    sensorA = analogRead(analogInA);            
    time +=200;
    Serial.print(time);
    Serial.print('\t');
    Serial.println(sensorA);    
 //   }
  }   
   Serial.print(99999);
   Serial.print('\t');
   Serial.println(99999); // signal GUI to end run  */
}   
}

/*void   readSerial() {
//  Serial.println("enter number of loops");
  int k = 0;
  while (Serial.available()<= 0) {
  }
  while (Serial.available() > 0){  
 while(k !=2) {             // when GUI writes "2", program is initiated
   k = Serial.read()-48;
  }}

}*/
