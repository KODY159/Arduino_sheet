void buzzerON(){
  digitalWrite(26, HIGH);
  delay(500);
  digitalWrite(26, LOW);
  delay(500);
}


void buzzerON2(int r, int volum, int t){
  for (int i=0; i<r; i++){
    analogWrite(26, volum);
    delay(t);
    analogWrite(26, 0);
    delay(t);
  }
}