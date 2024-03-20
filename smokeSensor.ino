#define MQ2pin A4
#define led 10
int sensorValue;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(led,OUTPUT);
Serial.println("Gas sensor Warming up !");
delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  sensorValue=analogRead(MQ2pin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(sensorValue >300){
    Serial.print("| smoke detected ! ");
    digitalWrite(led,HIGH);

  }
  else{
    digitalWrite(led,LOW);
  }
  delay(200);
}
