void track_hr() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/


  while (1) {

    //Set max pulse-width
    setting();
    if (sensor_read(1) > 6 && sensor_read(2) > 6) {
      motor(0, 0);
      firstESC.writeMicroseconds(1000);
      break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(140, -130);  //-/200,170
      } else if (diff == 2) {
        motor(-130, 140);
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
      motorspeed = (error * 2) + ((error - last_error) * 20) + (integrel / 300);  //3,2//1.8
      last_error = error;
      Serial.println(error);
      motor(constrain(180 - motorspeed, -255, 255), constrain(180 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
void track_h() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/


  while (1) {

    //Set max pulse-width
    setting();
    if (sensor_read(7) > 6 && sensor_read(8) > 6 && sensor_read(9) > 6) {
      motor(0, 0);
      firstESC.writeMicroseconds(1000);
      break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(140, -130);  //-/200,170
      } else if (diff == 2) {
        motor(-130, 140);
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
void track() {
  /*  value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
}*/


  while (1) {

    //Set max pulse-width
    //setting();
    // if(sensor_read(1)>6&&sensor_read(2)>6&&sensor_read(3)>6&&sensor_read(4)>6&&sensor_read(5)>6&&sensor_read(6)>6&&sensor_read(7)>6&&sensor_read(8)>6&&sensor_read(9)>6){
    //     motor(0,0); break;//firstESC.writeMicroseconds(1000);break;
    //  }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(250, -190);  //-/200,170
      } else if (diff == 2) {
        motor(-190, 250);
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
      } else if (sensor_read(2) > 15 && sensor_read(3) > 16 && sensor_read(7) > 18 && sensor_read(9) < 18) {
        diff = 1;
      }
      /////////////////////////
      /*if (error>0){diff=2;}  
        else{
          diff=1;
        }*/

      integrel = error + integrel;
      motorspeed = (error * 2.3) + ((error - last_error) * 15) + (integrel / 3000);  //3,2//1.8 //6,450
      last_error = error;
      Serial.println(error);
      motor(constrain(180 - motorspeed, -255, 255), constrain(180 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
void trackstwo() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/


  while (1) {

    //Set max pulse-width
    setting();
    if (sensor_read(1) > 10 && sensor_read(2) > 10 && sensor_read(3) > 10 && sensor_read(4) > 10 && sensor_read(5) > 10 && sensor_read(6) > 10 && sensor_read(7) > 10 && sensor_read(8) > 10 && sensor_read(9) > 10) {
      motor(0, 0);
      firstESC.writeMicroseconds(1000);
      break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(100, -250);  //-/200,170
      } else if (diff == 2) {
        motor(-250, 100);
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
      if (sensor_read(1) > 15 || sensor_read(2) > 16 || sensor_read(3) > 18) {
        diff = 1;
      } else if (sensor_read(9) > 15 || sensor_read(8) > 16 || sensor_read(7) > 18) {
        diff = 2;
      } else if (sensor_read(2) > 15 && sensor_read(3) > 16 && sensor_read(7) > 18 && sensor_read(9) < 18) {
        diff = 1;
      } else if (sensor_read(1) > 15 && sensor_read(2) > 16 && sensor_read(8) > 18 && sensor_read(9) < 18) {
        diff = 1;
      }
      /*if (error>0){diff=2;}  
        else{
          diff=1;
        }*/

      integrel = error + integrel;
      motorspeed = (error * 1) + ((error - last_error) * 10) + (integrel / 400);  //3,2//1.8
      last_error = error;
      Serial.println(error);
      motor(constrain(35 - motorspeed, -255, 255), constrain(35 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
void trackslow() {
  /* value=1400;
   for(int i=1000;i<1250;i++){
    firstESC.writeMicroseconds(i);
    delay(10);
   }*/


  while (1) {

    //Set max pulse-width
    setting();
    if (sensor_read(1) > 5 && sensor_read(2) > 5 && sensor_read(3) > 5 && sensor_read(4) > 5 && sensor_read(5) > 5 && sensor_read(6) > 5 && sensor_read(7) > 5 && sensor_read(8) > 5 && sensor_read(9) > 5) {
      motor(0, 0);
      break;  // firstESC.writeMicroseconds(1000);break;
    }
    error = positional() - 50;

    if (sensor_read(1) < 5 && sensor_read(2) < 5 && sensor_read(3) < 5 && sensor_read(4) < 5 && sensor_read(5) < 5 && sensor_read(6) < 5 && sensor_read(7) < 5 && sensor_read(8) < 5 && sensor_read(9) < 5) {
      //motor(50,50);
      if (diff == 1) {
        motor(100, -150);  //-/200,170
      } else if (diff == 2) {
        motor(-150, 100);
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
      if (sensor_read(1) > 15 || sensor_read(2) > 16 || sensor_read(3) > 18) {
        diff = 1;
      } else if (sensor_read(9) > 15 || sensor_read(8) > 16 || sensor_read(7) > 18) {
        diff = 2;
      } else if (sensor_read(2) > 15 && sensor_read(3) > 16 && sensor_read(7) > 18 && sensor_read(9) < 18) {
        diff = 1;
      }
      /*if (error>0){diff=2;}  
        else{
          diff=1;
        }*/

      integrel = error + integrel;
      motorspeed = (error * 3) + ((error - last_error) * 18) + (integrel / 600);  //3,2//1.8
      last_error = error;
      Serial.println(error);
      motor(constrain(80 - motorspeed, -255, 255), constrain(80 + motorspeed, -255, 255));  //130
    }
  }
  motor(0, 0);
  beep();
}
