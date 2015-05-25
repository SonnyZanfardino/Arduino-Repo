#include <Servo.h>

Servo myservo1;  
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pin1= 1;
int val1; 
int v1;
int curr1;
int prev1=0;
unsigned int diff1;                             

int pin2= 2;
int val2; 
int v2;
int curr2;
int prev2=0;
unsigned int diff2;                             

int pin3= 3;
int val3; 
int v3;
int curr3;
int prev3=0;
unsigned int diff3;                             

int pin4= 0;
int val4; 
int v4;
int curr4;
int prev4=0;
unsigned int diff4;                             
                                              
int pin5= 0;
int val5; 
int v5;
int curr5;
int prev5=0;
unsigned int diff5;                             

void setup()
{   
  myservo1.attach(5);                          
  myservo2.attach(6);                          
  myservo3.attach(9);                          
  myservo4.attach(10);                          
  myservo5.attach(11);                          
    
  pinMode(pin1, INPUT);   
  pinMode(pin2, INPUT);   
  pinMode(pin3, INPUT);   
  pinMode(pin4, INPUT);   
  pinMode(pin5, INPUT);   
  
  Serial.begin(9600);                          
}

void loop()
{
   Serial.flush();    
   delay(1000); 
   
  
   val1 = analogRead(pin1);
   v1 = map(val1, 300, 800, 0, 180);           

   val2 = analogRead(pin2);
   v2 = map(val2, 300, 800, 0, 180); 
   
   val3 = analogRead(pin3);
   v3 = map(val3, 300, 800, 0, 180);   
   
   val4 = analogRead(pin4);
   v4 = map(val4, 300, 800, 0, 180);    
   
   val5 = analogRead(pin5);
   v5 = map(val5, 300, 800, 0, 180);           

   
   Serial.println(v1);                       
   curr1 = v1;                                
   diff1 = prev1 - curr1;              

   Serial.println(v2);                       
   curr2 = v2;                                
   diff2 = prev2 - curr2;                      

   Serial.println(v3);                       
   curr3 = v3;                                
   diff3 = prev3 - curr3;                      

   Serial.println(v4);                       
   curr4 = v4;                                
   diff4 = prev4 - curr4;                      

   Serial.println(v5);                       
   curr5 = v5;                                
   diff5 = prev5 - curr5;                      


   if ((diff1)>=40)                            
   {                                          
     v1 = v1 - 40;                          
   }
   if ((diff2)>=40)                            
   {                                          
     v2 = v2 - 40;                          
   }
   if ((diff3)>=40)                            
   {                                          
     v3 = v3 - 40;                          
   }
   if ((diff4)>=40)                            
   {                                          
     v4 = v4 - 40;                          
   }
   if ((diff5)>=40)                            
   {                                          
     v5 = v5 - 40;                          
   }

   
   myservo1.write(v1);                                     
   delay(10);
   prev1=curr1;                   

   myservo2.write(v2);                                     
   delay(10);
   prev2=curr2;                              

   myservo3.write(v3);                                     
   delay(10);
   prev3=curr3;                              

   myservo4.write(v4);                                     
   delay(10);
   prev4=curr4;                              

   myservo5.write(v5);                                     
   delay(10);
   prev5=curr5;                              
   
}
