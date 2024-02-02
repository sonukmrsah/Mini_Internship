int analogLDR = A0;
int digitalLDR = 12;
int Switch = 13;
int Buzzer = 6;

void setup() {
  pinMode(analogLDR, INPUT);
  pinMode(digitalLDR, INPUT);
  pinMode(Switch, OUTPUT);
  Serial.begin(9600);
}

int Amount_of_light(){
  int LDR_status = analogRead(analogLDR);
  int intensity = map(LDR_status, 1, 1023, 1, 100);
  return intensity;
}

int Light_is_defective(){
  Serial.println(digitalLDR);
  return digitalRead(digitalLDR);
}

void loop() {
  int intensity = Amount_of_light();
  while (intensity >= 30){
    digitalWrite(Switch, LOW);
    intensity = Amount_of_light();
    if (Light_is_defective() == 1){
      Serial.println("Light is defective");
    }
  }
  noTone(Buzzer);
  digitalWrite(Switch, HIGH);
}
