void beep() {
  tone(buzzer, 600);
  delay(100);
  noTone(buzzer);
}
void error_buzzer() {
  tone(buzzer, 400);
  delay(1000);
  noTone(buzzer);
}


void set_module() {
  Serial.begin(115200);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  firstESC.attach(11);
  value = 1000;
  firstESC.writeMicroseconds(value);
  delay(100);
  /*while(1){

  for(int i=0;i<10;i++){
  Serial.print(analogRead(i));
  Serial.print(",");
    
  }
  Serial.println();
}*/
  calibratewhite();
  calibrateblack();
  calibratewhite();
  calibrateblack();
  digitalWrite(13, HIGH);
  // beep();

  while (digitalRead(10) == 0)
    ;
  digitalWrite(13, LOW);
  //Serial.println("on");
}


void motor(int ma, int mb) {
  if (ma > 0) {
    analogWrite(3, 0);
    analogWrite(4, ma);
  } else {
    analogWrite(3, -ma);
    analogWrite(4, 0);
  }
  if (mb > 0) {
    analogWrite(5, 0);
    analogWrite(6, mb);
  } else {
    analogWrite(5, -mb);
    analogWrite(6, 0);
  }
}
