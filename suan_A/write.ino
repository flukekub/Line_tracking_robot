void EEPROMwriteInt(unsigned int add, unsigned int value) {
  byte Hbyte = (value >> 8);
  EEPROM.write(add, Hbyte);
  byte Lbyte = value & 0x00FF;
  EEPROM.write(add + 1, Lbyte);
}
unsigned int EEPROMreadInt(unsigned int add) {
  unsigned int value = 0;
  byte Hbyte = EEPROM.read(add);
  byte Lbyte = EEPROM.read(add + 1);
  value = (Hbyte << 8) + Lbyte;
  return (value);
}
void setting() {
  PV = positional();
  Setpoint = PV - 50;
  while (Serial3.available()) {

    Readbyte = Serial3.read();
    if (Readbyte > 47 && Readbyte < 58) {
      Data = (Data * 10) + (Readbyte - 48);
    } else if (Readbyte == 'S') {
      Status = Data;
      Data = 0;
    } else if (Readbyte == 'P') {
      kps = Data;
      kp = Data / 1000.0;
      EEPROMwriteInt(ADDkp, Data);
      Data = 0;
    } else if (Readbyte == 'I') {
      kis = Data;
      ki = Data / 1000.0;
      EEPROMwriteInt(ADDki, Data);
      Data = 0;
    } else if (Readbyte == 'D') {
      kds = Data;
      kd = Data / 1000.0;
      EEPROMwriteInt(ADDkd, Data);
      Data = 0;
    } else if (Readbyte == 'A') {
      Alphas = Data;
      Alpha = Data / 1000.0;
      EEPROMwriteInt(ADDAlpha, Data);
      Data = 0;
    } else {
      Data = 0;
    }
  }
  Serial3.print(kps);
  Serial3.print(",");
  Serial3.print(kis);
  Serial3.print(",");
  Serial3.print(kds);
  Serial3.print(",");
  Serial3.print(PV);
  Serial3.print(",");
  Serial3.print(Setpoint);
  Serial3.print(",");
  Serial3.print(Alphas);
  Serial3.println("");
}
