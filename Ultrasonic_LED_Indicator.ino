const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

    Serial.begin(9600);
}

void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED_BUILTIN, LOW);

 
  if (distance < 50) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (distance < 100) {
    digitalWrite(LED1, HIGH);
  } else if (distance < 150) {
    digitalWrite(LED2, HIGH);
  } else if (distance < 200) {
    digitalWrite(LED3, HIGH);
  }

  delay(300);   
}
