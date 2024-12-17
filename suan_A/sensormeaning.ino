int positional() {

  float ssum = ((sensor_read(1) * 10) + (sensor_read(2) * 20) + (sensor_read(3) * 30) + (sensor_read(4) * 40) + (sensor_read(5) * 50) + (sensor_read(6) * 60) + (sensor_read(7) * 70) + (sensor_read(8) * 80) + (sensor_read(9) * 90));
  float saverage = +sensor_read(1) + sensor_read(2) + sensor_read(3) + sensor_read(4) + sensor_read(5) + sensor_read(6) + sensor_read(7) + sensor_read(8) + sensor_read(9);
  int total = ssum / saverage;
  if (saverage == 0) {
    total = 0;
  }
  return total;
}
