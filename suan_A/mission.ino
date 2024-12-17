void white() {
  while (1) {
    if (analogRead(0) > smid && analogRead(2) > smid) {
      motor(0, 0);
      break;
    } else {
      motor(70, 70);
    }
  }
}
void black() {
  while (1) {
    if (analogRead(9) < smid && analogRead(8) < smid) {
      motor(0, 0);
      break;
    } else {
      motor(40, 40);
    }
  }
}
