#define TRIG 9
#define ECHO 10
#define BUZZER 6
#define LED_GRUEN 2
#define LED_GELB 3
#define LED_ROT 4

long duration;
long distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_GRUEN, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_ROT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Ultraschall auslösen
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distanz: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Parksystem Logik
  if (distance > 50) {
    // Grün: LED an, langsames Piepen
    digitalWrite(LED_GRUEN, HIGH);
    digitalWrite(LED_GELB, LOW);
    digitalWrite(LED_ROT, LOW);

    tone(BUZZER, 1000); // 1 kHz Ton
    delay(200);          // Tondauer
    noTone(BUZZER);
    delay(800);          // Pause → langsames Piepen

  } else if (distance > 20) {
    // Gelb: LED an, schneller Piepen
    digitalWrite(LED_GRUEN, LOW);
    digitalWrite(LED_GELB, HIGH);
    digitalWrite(LED_ROT, LOW);

    tone(BUZZER, 1000); 
    delay(150);          // Ton kurz
    noTone(BUZZER);
    delay(150);          // kurze Pause → schneller Piepton

  } else {
    // Rot: LED an, dauerhafter Ton
    digitalWrite(LED_GRUEN, LOW);
    digitalWrite(LED_GELB, LOW);
    digitalWrite(LED_ROT, HIGH);

    tone(BUZZER, 1000);  // Dauerpiepston
    delay(200);           // Kurze Schleifenpause, Ton bleibt an
  }
}
