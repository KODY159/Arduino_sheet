void MotionFunc(){
  val = digitalRead(Motion);
  Serial.print("val = ");
  Serial.println(val);
  if (val == 1) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}