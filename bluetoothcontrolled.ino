//Bluetooth Controlled Robot

#define left_motor_forward 7
#define left_motor_backward 8
#define right_motor_forward 9
#define right_motor_backward 10
#define left_motor_speed 5
#define right_motor_speed 6
#define head_light 1
#define spl 25//left motor speed coeficient
#define spr 20 //right motor speed coeficient
#define sw 2
char flag = 's';

char x;
int spd = 250;
void setup() {
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(head_light, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
 bluetooth(); 
 //line_follow(); // comment this if you want to test sensor value or want to use robot a rc car
//show_the_value(); // only uncomment this if you need to test sensor value in serial monitor
//motor(10 * spl, 10 * spr);  //only uncomment this when you need to test if robot is moving forward
}

void bluetooth() {
  int s = 10; //for adjustable speed system
  char x; //for storing receiving incoming data  
  
  while (1) { //infinite loop
    if (Serial.available() > 0) {
      x = Serial.read();
      Serial.println(x);
      
      if (x == 'F') motor(s * spl, s * spr);
      else if (x == 'B') motor(-s * spl, -s * spr);
      else if (x == 'L') motor(-s * spl, s * spr);
      else if (x == 'R') motor(s * spl, -s * spr);
      else if (x == 'G') motor(0, s * spr);
      else if (x == 'I') motor(s * spl, 0);
      else if (x == 'H') motor(0, -s * spr);
      else if (x == 'J') motor(-s * spl, 0);
      else if (x == 'S') motor(0, 0);
      else if (x == 'U') digitalWrite(head_light, HIGH);
      else if (x == 'u') digitalWrite(head_light, LOW);
      else if (x == '0') s = 0;
      else if (x == '1') s = 1;
      else if (x == '2') s = 2;
      else if (x == '3') s = 3;
      else if (x == '4') s = 4;
      else if (x == '5') s = 5;
      else if (x == '6') s = 6;
      else if (x == '7') s = 7;
      else if (x == '8') s = 8;
      else if (x == '9') s = 9;
      else if (x == 'q') s = 10;
    }
  }
}
void motor(int a, int b){
  if(a>=0){
    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);
  }
  else{
    a=-a;
    digitalWrite(left_motor_forward, 0);
    digitalWrite(left_motor_backward, 1);
  }
  if(b>=0){
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
  }
  else{
    b=-b;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
  }
  analogWrite(left_motor_speed,a);
  analogWrite(right_motor_speed,b);
}