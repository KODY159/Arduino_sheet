void volumn(){
  potValue = analogRead(potPin);
  int mapPlot = map(potValue, 0, 4095, 0, 100);
  // Serial.println(mapPlot);
  analogWrite(3, mapPlot);
  delay(500);
}