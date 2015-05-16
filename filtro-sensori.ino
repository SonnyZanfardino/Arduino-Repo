#include <Servo.h>
int previousValue;
int currentValue;
int pin2= 2;
int lettura_sensore;
Servo myservo; 

int noise = 350;//how much the peak are high 

void setup() {
  previousValue = analogRead(0);
  currentValue = previousValue;
  expectedValue = previousValue;
  
  myservo.attach(9);
  pinMode(pin2, INPUT);
  Serial.begin(9600); 
}

void loop() 
{
  lettura_sensore = analogRead(pin2);  //con queste due istruzioni leggo lo stato di ogni sensore,
  Serial.println(lettura_sensore);     //e lo visualizzo nel monitor seriale.
  
  currentValue = analogRead(0);
  if( abs(currentValue-previousValue) > noise){
    previousValue=currentValue;  
  }
  else{
    currentValue=previousValue; 
  } 
  currentValue = analogRead(pin2);
  currentValue = map(currentValue, 300, 1023, 0, 180);
  myservo.write(currentValue);
  delay(100);
}
