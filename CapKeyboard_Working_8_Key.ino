#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

float oct = 2; // This is the mutiplyer for the octive, .5 is A3, 1 is A4, 2 is A5, 3 is A6.   

float C_high = 523.251;
float B = 493.883;
float A = 440;  // Frequencies of each key, 440 is A440
float G = 391.995;
float F = 349.228;
float E = 329.628;
float D = 293.665;
float C = 261.626;

int speaker = 12;  // Speaker on 12 and GND. Pin 13 causes starup noise

CapacitiveSensor   cs_0_2 = CapacitiveSensor(0,2);        // 10M resistor between pins 0 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_0_3 = CapacitiveSensor(0,3);        // 10M resistor between pins 0 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_0_4 = CapacitiveSensor(0,4);        // 10M resistor between pins 0 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_0_5 = CapacitiveSensor(0,5); 
CapacitiveSensor   cs_0_6 = CapacitiveSensor(0,6); 
CapacitiveSensor   cs_0_7 = CapacitiveSensor(0,7); 
CapacitiveSensor   cs_0_8 = CapacitiveSensor(0,8);
CapacitiveSensor   cs_0_9 = CapacitiveSensor(0,9);

void setup()                    
{
   cs_0_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example CHECK WHAT THIS ACTUALLY 
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long keyC_high =  cs_0_9.capacitiveSensor(30);
    long keyB =  cs_0_2.capacitiveSensor(30);
    long keyA =  cs_0_3.capacitiveSensor(30);
    long keyG =  cs_0_4.capacitiveSensor(30);
    long keyF =  cs_0_5.capacitiveSensor(30);
    long keyE =  cs_0_6.capacitiveSensor(30);
    long keyD =  cs_0_7.capacitiveSensor(30);
    long keyC =  cs_0_8.capacitiveSensor(30);


    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(keyB);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(keyA);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(keyG);                // print sensor output 3
    Serial.print("\t");
    Serial.println(keyF);
    Serial.print("\t");
    Serial.println(keyE); 
    Serial.print("\t");
    Serial.println(keyD);
    Serial.print("\t");
    Serial.println(keyC);
    Serial.print("\t");
    Serial.println(keyC_high); // Ask Liz what a good varible name would be for the other C value
    
    if (keyB > 3000){
      tone(speaker, oct*B,100);
    }
    if (keyA > 3000){
      tone(speaker, oct*A, 100);
    }
    if (keyG > 3000){
      tone(speaker, oct*G, 100);
    }
     if (keyF > 3000){
      tone(speaker, oct*F, 100);
    }
     if (keyE > 3000){
      tone(speaker, oct*E, 100);
    }
    if (keyD > 3000){
      tone(speaker, oct*D, 100);
    }
    if (keyC > 3000){
      tone(speaker, oct*C, 100);
    }
    if (keyC_high > 3000){
      tone(speaker, oct*C_high, 100);
    }
   
}
