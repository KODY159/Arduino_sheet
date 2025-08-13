void ledRL(int led[], char t, int time, int r) {
  while (r--) {
    // right to left
    if (t == 'r') { 
      for (int i = sizePin - 1; i >= 0; i--) {
        digitalWrite(led[i], HIGH);
        delay(time);
      }
    } else if (t == 'l') {
      // left to right
      for (int i = 0; i < sizePin; i++) {
        digitalWrite(led[i], HIGH);
        delay(time);
      }
    }
    ledoff();
    delay(time);
  }
}

void ledAnalog(){
  int led[] = {4}; // declare anlog pin to use
  int sizeSPin = sizeof(led) / sizeof(led[0]); //size of pin
  for (int i=0; i<sizeSPin; i++){
    for (int j=0; j<4095; j+=50){
      analogWrite(led[i], j);
    }
  }
}

//led on
void ledOn() {
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], HIGH);
  digitalWrite(led[2], HIGH);
}

//led off
void ledoff() {
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
}