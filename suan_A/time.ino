void tracktimeri() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/
  int ttt = 0;

  while (1) {
    ttt = ttt + 1;
    //Set max pulse-width
    setting();
    if (ttt > 155) {
      motor(0, 0);
      firstESC.writeMicroseconds(1000);
      break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(140, -200);  //-/200,170
      } else if (diff == 2) {
        motor(-200, 140);
      }
    }

    else {
      /*  if((sensor_read(1)>10||sensor_read(2)>10)&&sensor_read(7)<10){
      diff=1;
    }
    else if((sensor_read(9)>10||sensor_read(8)>10)&&sensor_read(1)<10){
      diff=2;
    }*/

      /////////////////////////////
      if (sensor_read(1) > 10 || sensor_read(2) > 10 || sensor_read(3) > 17) {
        diff = 1;
      } else if (sensor_read(9) > 10 || sensor_read(8) > 10 || sensor_read(7) > 17) {
        diff = 2;
      }
      /////////////////////////
      /*if (error>0){diff=2;}  
        else{
          diff=1;
        }*/

      integrel = error + integrel;
      motorspeed = (error * kp) + ((error - last_error) * kd) + (integrel / ki);  //3,2//1.8
      last_error = error;
      Serial.println(error);
      motor(constrain(40 - motorspeed, -255, 255), constrain(40 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
void tracktimein() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/
  int ttt = 0;

  while (1) {
    ttt = ttt + 1;
    //Set max pulse-width
    setting();
    if (ttt > 40) {
      motor(0, 0);
      firstESC.writeMicroseconds(1000);
      break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 15 && sensor_read(2) < 15 && sensor_read(3) < 15 && sensor_read(4) < 15 && sensor_read(5) < 15 && sensor_read(6) < 15 && sensor_read(7) < 15 && sensor_read(8) < 15 && sensor_read(9) < 15) {
      //motor(50,50);
      motor(40, 40);
    }

    else {
      /*  if((sensor_read(1)>10||sensor_read(2)>10)&&sensor_read(7)<10){
      diff=1;
    }
    else if((sensor_read(9)>10||sensor_read(8)>10)&&sensor_read(1)<10){
      diff=2;
    }*/

      /////////////////////////////
      if (sensor_read(1) > 10 || sensor_read(2) > 10 || sensor_read(3) > 17) {
        diff = 1;
      } else if (sensor_read(9) > 10 || sensor_read(8) > 10 || sensor_read(7) > 17) {
        diff = 2;
      }
      /////////////////////////
      /*if (error>0){diff=2;}  
        else{
          diff=1;
        }*/

      integrel = error + integrel;
      motorspeed = (error * 2) + ((error - last_error) * 20) + (integrel / ki);  //3,2//1.8
      last_error = error;
      Serial.println(error);
      motor(constrain(40 - motorspeed, -255, 255), constrain(40 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
