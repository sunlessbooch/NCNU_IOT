#include <LedControl.h>

 #define DinPin 4
 #define CsPin 5
 #define ClkPin 6
 #define chipno 0 
LedControl lc=LedControl(DinPin,ClkPin,CsPin,chipno); 
LedControl lc1=LedControl(DinPin,ClkPin,CsPin,chipno+1); 

/* we always wait a bit between updates of the display */
unsigned long delaytime=2000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  lc1.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  lc1.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  lc1.clearDisplay(0);
  Serial.begin(9600);
  Serial.println("Program Start Here");
}

void loop() { 
  writeArduinoOnMatrix();
  //rows();
 // columns();
//  single();
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8]={B00011000,
             B00100100,  
             B01000010,  
             B10000001,  
             B11111111,
             B10000001,
             B10000001,
             B00000000};
             

             
  /* now display them one by one with a small delay */
  showchar(lc, &a[0]);
    Serial.println("Now print (A)");
  delay(delaytime);
 showchar(lc1, &a[0]);
    Serial.println("Now print (A)");
  //delay(delaytime);

 
}
void showchar(LedControl obj, byte *chr)
{
 int i = 0 ;
   clearchar(obj);
   //lc.clearDisplay(0) ;
 for(i = 0 ; i <8 ; i++)
 {
   obj.setRow(0,7-i,*(chr+i));
 } 
 
}


void clearchar(LedControl obj)
{
 int i = 0 ;
 for(i = 0 ; i <8 ; i++)
 {
   obj.setColumn(0,i,0x00);
 } 
 
}


