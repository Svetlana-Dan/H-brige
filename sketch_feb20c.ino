#define pinmode6 6
#define pinmode5 5

void setup() {
  Serial.begin(9600);
  pinMode(pinmode5, OUTPUT);
  pinMode(pinmode6, OUTPUT);
}
int dir = 120; 


void loop() {
  while (Serial.available() > 1){
    dir = Serial.parseInt();
    Serial.println(dir);
  }
  run_h_brige(dir, 1);
}

void run_h_brige(int velocity, int direction) {
  //0 - против часовой, 1 - по часовой
  if(direction == 0){
    analogWrite(pinmode5, velocity);
    pinMode(pinmode5, OUTPUT);
    pinMode(pinmode6, INPUT);
  }
  if(direction == 1){
    analogWrite(pinmode6, velocity);
    pinMode(pinmode6, OUTPUT);
    pinMode(pinmode5, INPUT);
  }
}
