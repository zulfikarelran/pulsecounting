unsigned long fr10s_cnt=0;
unsigned long fr5s_cnt=0;
unsigned long fr1s_cnt=0;

unsigned long fr10s_tmr=0;
unsigned long fr5s_tmr=0;
unsigned long fr1s_tmr=0;

int cnt_pin=18;
int iter1=0;
void IRAM_ATTR read_cnt() {
  fr10s_cnt++;
  fr5s_cnt++;
  fr1s_cnt++;
}


void setup() {
  Serial.begin(500000);
  pinMode(cnt_pin, INPUT);
  delay(1000);
  Serial.println("Program start");
  delay(3000);
  fr10s_tmr=millis();
  fr5s_tmr=millis();
  fr1s_tmr=millis();
  fr10s_cnt=0;
  fr5s_cnt=0;
  fr1s_cnt=0;
  attachInterrupt(cnt_pin, read_cnt, FALLING);
}

void loop() {
  if(iter1>2){
    delay(5);
    return;
  }
  
  
  if(millis()-fr1s_tmr>1000)
  {    
    Serial.println("1s Channel Count= "+String(fr1s_cnt));
    fr1s_tmr=millis();
    fr1s_cnt=0;
  }
}
