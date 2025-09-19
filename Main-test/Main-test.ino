/*#include <Servo.h>  
Servo servo;     
int trigPin = 12; // was 5 earlier    
int echoPin = 11; // was 6 earlier   
int servoPin = 7;
long duration, dist, average;   
long averageDist[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         
    delay(100);
    servo.detach(); 
} 

void measureSensorDist() {  
digitalWrite(trigPin, LOW); // guys i removed the digitalwrite 10, cos its not needed
delayMicroseconds(10); // was 5
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // was 15
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

dist = (duration/2) / 29.1;    // in order to getthe distance
}
void loop() { 
  for (int count=0;count<=2;count++) {   //average distance
    measureSensorDist();               
   averageDist[count]=dist;            
    delay(10);              
  }
 dist=(averageDist[0]+averageDist[1]+averageDist[2])/3;    

if ( dist<50 ) {
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
Serial.println(dist);
}
*/
#include <Servo.h>
Servo myServo;

int trigPin = 12;
int echoPin = 11;
int servoPin = 7;

long duration, dist;
long averageDist[3];
bool isOpen = false; // track if lid is open

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(0); // start closed

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void measureSensorDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration / 2) / 29.1;
}

void loop() {
  for (int i = 0; i < 3; i++) {
    measureSensorDist();
    averageDist[i] = dist;
    delay(10);
  }
  dist = (averageDist[0] + averageDist[1] + averageDist[2]) / 3;

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  // Open if close enough, close if far
  if (dist > 0 && dist <= 10 && !isOpen) {
    myServo.write(150);  // open
    isOpen = true;
  } else if (dist > 12 && isOpen) {
    myServo.write(0);    // close
    isOpen = false;
  }

  delay(100);
}