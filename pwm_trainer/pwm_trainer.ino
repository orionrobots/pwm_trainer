

void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int rInput = analogRead(A0);
  int gInput = analogRead(A1);
  int bInput = analogRead(A2);
  // print out the value you read:
  Serial.print(rInput);
  Serial.print(", ");
  Serial.print(gInput);
  Serial.print(", ");
  Serial.println(bInput);
  delay(1);  // delay in between reads for stability
}
