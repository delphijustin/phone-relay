void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);// switching output pin
pinMode(12,INPUT_PULLUP);// on/off hook collector pin
}
bool currentState=false;
void loop() {
 Serial.println(digitalRead(12)+(2*digitalRead(13)));// write current state to serial port
noTone(8);//disable tone
if(currentState){
  digitalWrite(13,HIGH);// switch on
  tone(8,1024);  // switch on tone
}else{
  digitalWrite(13,LOW);//switch off
  tone(8,512);  // switch off tone
}
delay(2048);// wait anout 2 seconds
if(digitalRead(12)==LOW){ // if phone os active
  delay(2048);// wait 2 seconds
  tone(8,256);// update tone
  delay(2048);//wait another 2 seconds
  if(digitalRead(12)==LOW)
  currentState=!currentState;//invert current state
}
}
