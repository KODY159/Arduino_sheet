

int ultra(String s) {
  long duration, cm, inch, mm;
  pinMode(pingPin, OUTPUT);

  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  cm = duration / 29 / 2;
  mm = cm * 10;
  inch = cm / 2.54;

  if (s == "cm") {
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    return cm;
  } else if (s == "mm") {
    Serial.print(mm);
    Serial.print("mm");
    Serial.println();
    delay(100);
    return mm;
  } else if (s == "in") {
    Serial.print(inch);
    Serial.print("inch");
    Serial.println();
    delay(100);
    return inch;
  }
}
