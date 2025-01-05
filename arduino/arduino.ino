void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,INPUT_PULLUP);
}
bool currentState=false;
void loop() {
 Serial.println(digitalRead(12)+(2*digitalRead(13)));
noTone(8);
if(currentState){
  digitalWrite(13,HIGH);
  tone(8,1024);  
}else{
  digitalWrite(13,LOW);
  tone(8,512);
}
delay(2048);
if(digitalRead(12)==LOW){
  delay(2048);
  tone(8,256);
  delay(2048);
  if(digitalRead(12)==LOW)
  currentState=!currentState;
}
}
