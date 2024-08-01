
int rLEDPin = 6;
int gLEDPin = 5;
int bLEDPin = 3;

void setup() {
  Serial.begin(115200);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int rInput = analogRead(A2);
  int gInput = analogRead(A1);
  int bInput = analogRead(A0);
  analogWrite(rLEDPin, 255 - (rInput / 4));
  analogWrite(gLEDPin, 255 - (gInput / 4));
  analogWrite(bLEDPin, 255 - (bInput / 4));
  // print out the value you read:
  Serial.print(rInput);
  Serial.print(", ");
  Serial.print(gInput);
  Serial.print(", ");
  Serial.println(bInput);
  delay(1);  // delay in between reads for stability
}
