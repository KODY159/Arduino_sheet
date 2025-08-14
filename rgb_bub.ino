void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

int rgb(int r, int g, int b, int t){
  analogWrite(2, r);
  analogWrite(4, g);
  analogWrite(5, b);
  delay(t);
}

void loop() {
  long r = random(0, 256);
  long g = random(0, 256);
  long b = random(0, 256);
  
  rgb(r, g, b, 500);
  delay(1000);
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}