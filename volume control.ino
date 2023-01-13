float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; 
}
#define POTENTIOMETER_PIN 15
#define buzzer_gpio 21
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer_gpio,OUTPUT);
}

void loop() {
  int analogValue = analogRead (POTENTIOMETER_PIN);
  int brightness = floatMap(analogValue, 0, 4095, 0, 225);
  if (brightness > 200) {
    Serial.println("decrease the volume ");
    digitalWrite(buzzer_gpio, HIGH);
    delay(100);
  }
  digitalWrite(buzzer_gpio, LOW);
  Serial.println(brightness);
  delay(100);
}