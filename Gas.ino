void gas(){
  int gasValue = analogRead(AO_GAS);

  Serial.print("MQ2 sensor AO value: ");
  Serial.println(gasValue);
}