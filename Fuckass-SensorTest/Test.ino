const int trigPin = 9; //RED = BLUE
const int echoPin = 10;//Orange = PURPLE

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // <-- updated line
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}

//sudo chmod a+rw /dev/ttyACM0