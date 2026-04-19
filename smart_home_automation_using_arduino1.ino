int tempPin = A0;
int led = 13;
int button = 7;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int value = analogRead(tempPin);
  float voltage = value * (5.0 / 1023.0);
  float temp = (voltage - 0.5) * 100;

  Serial.print("Temp: ");
  Serial.println(temp);   // 🔥 IMPORTANT

  int buttonstate = digitalRead(button);

  if (temp > 30 || buttonstate == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(500);
}