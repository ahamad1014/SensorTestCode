void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(2);
  if(touchValue == 1)
  {
    digitalWrite(13,HIGH);
    Serial.println("high");
  }
  else
  {
    digitalWrite(13,LOW);
    Serial.println("low");
  }

}