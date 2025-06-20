
#include <Servo.h>

// Metal Sensor Pin
const int Metal1Pin = 4;     
const int Metal2Pin = 5;     
const int Metal3Pin = 6;
//Supplementary Metal Sensor
/* const int Metal4Pin = 7;    
const int Metal5Pin = 8*/    

// IR Distance Sensor Pin
const int Distance1Pin = A0;
const int Distance2Pin = A1;   
const int Distance3Pin = A2;
//Supplementary IR Sensor
/*const int Distance4Pin = A3;    
const int Distance5Pin = A4*/    

// Motor Pin
const int MotorPin = 8;      

// Distance Threshold
const int Threshold = 19;

Servo myServo;

void setup() {
  pinMode(Metal1Pin, INPUT);
  pinMode(Metal2Pin, INPUT);
  pinMode(Metal3Pin, INPUT);
  /*pinMode(Metal4Pin, INPUT);
  pinMode(Metal5Pin, INPUT);*/

  myServo.attach(MotorPin, 500, 2500);
  Serial.begin(9600);
  myServo.writeMicroseconds(1500);  //The default value must be the middle value
}

void loop() {
  bool MetalDetected = (digitalRead(Metal1Pin) == HIGH) || (digitalRead(Metal2Pin) == HIGH) || (digitalRead(Metal3Pin) == HIGH)/*|| (digitalRead(Metal4Pin) == HIGH) || (digitalRead(Metal5Pin) == HIGH)*/;
  int volt1 = map(analogRead(Distance1Pin), 0, 1023, 0, 5000); //Convert analog signal (0~1023) to voltage (0~5000mV) 
  int volt2 = map(analogRead(Distance2Pin), 0, 1023, 0, 5000); 
  int volt3 = map(analogRead(Distance3Pin), 0, 1023, 0, 5000); 
  /*int volt4 = map(analogRead(Distance4Pin), 0, 1023, 0, 5000); 
  int volt5 = map(analogRead(Distance5Pin), 0, 1023, 0, 5000); */

  int Distance1 = (27.61 / (volt1 - 0.1696)) * 1000;          //Convert voltage to distance(cm)
  int Distance2 = (27.61 / (volt2 - 0.1696)) * 1000; 
  int Distance3 = (27.61 / (volt3 - 0.1696)) * 1000;
  /* int Distance4 = (27.61 / (volt4 - 0.1696)) * 1000; 
  int Distance5 = (27.61 / (volt5 - 0.1696)) * 1000;*/
  //Return 1 if distance is less than threshold
  bool ObjectDetected = (Distance1 < Threshold) || (Distance2 < Threshold) || (Distance3 < Threshold)/*|| (Distance4 < Threshold) || (Distance5 < Threshold)*/;

  Serial.print("Metal: ");
  Serial.print(MetalDetected);
  Serial.print(" | IR Sensor Detected: ");
  Serial.println(ObjectDetected);

  if (MetalDetected && ObjectDetected) {
    delay(1000);                            //Short delay after signal detection
    myServo.writeMicroseconds(2500);        //Rotate 90 degrees counterclockwise
    delay(6000);                            //Delay for carton to drop
    myServo.write(1500);                    //Return to original position
  } else if (!MetalDetected && ObjectDetected) {
    delay(1000);                            
    myServo.writeMicroseconds(500);         //Rotate 90 degrees clockwise
    delay(6000);                            
    myServo.writeMicroseconds(1500);     
  }

  delay(200); //Status check interval
}
