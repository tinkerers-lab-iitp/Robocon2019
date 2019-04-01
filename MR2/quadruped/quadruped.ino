void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  init_servos();
  
  rest_pos();
  #if 1
  delay(2000);
  
  start_march();
  int start_time = millis();
  while(millis()-start_time<5000) {
    march();  
  }
  stop_march();
  delay(3000);
  straight_pos();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  //march();
}