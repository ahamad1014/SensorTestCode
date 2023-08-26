void setup() {
  Serial.begin(9600);//enable serial monitor
  pinMode(2, INPUT);//define arduino pin
  pinMode(3, OUTPUT);//define arduino pin
}

void loop() {
  balckwhite();//Identification of black and white

}
void balckwhite() {
  bool led = digitalRead(2);
  if (led == 0) {
    Serial.println("Black");
    digitalWrite(3, HIGH);
    
  } else {
    Serial.println("White");
    digitalWrite(3,LOW);
    }
}