void calibratewhite() {
  while (1) {
    if (analogRead(1) > smid) {
      break;
    }
    for (int i = 0; i < 10; i++) {
      smin[i] = min(smin[i], analogRead(i));
    }
    smin[14] = min(smin[14], analogRead(14));
  }
}
void calibrateblack() {
  while (1) {
    if (analogRead(1) < smid) {
      break;
    }

    for (int i = 0; i < 10; i++) {
      smax[i] = max(smax[i], analogRead(i));
    }
    smax[14] = max(smax[14], analogRead(14));
  }
}
int sensor_read(int i) {
  int smean = constrain((analogRead(i) - smin[i]) / ((smax[i] - smin[i]) / 50) - 23, 0, 20);
  return smean;  //(smean-20)*(-1);
}
void sensor_test() {
  while (1) {
    Serial.print(sensor_read(0));
    Serial.print(",");
    Serial.print(sensor_read(1));
    Serial.print(",");
    Serial.print(sensor_read(2));
    Serial.print(",");
    Serial.print(sensor_read(3));
    Serial.print(",");
    Serial.print(sensor_read(4));
    Serial.print(",");
    Serial.print(sensor_read(5));
    Serial.print(",");
    Serial.print(sensor_read(6));
    Serial.print(",");
    Serial.print(sensor_read(7));
    Serial.print(",");
    Serial.print(sensor_read(8));
    Serial.print(",");
    Serial.print(sensor_read(9));
    Serial.print(",");
    Serial.print(sensor_read(14));
    Serial.println();
    delay(10);
  }
}
