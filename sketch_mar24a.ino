int sensor_MQ=0;
  
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  pinMode(A0,INPUT);
}

void loop()
{
  sensor_MQ = analogRead(A0);
  float voltaje = sensor_MQ * (5.0 / 1023.0); 
  float Rs=1000*((5-voltaje)/voltaje);  //Rs = resistensia del sensor
  double nivel_alcohol=(0.4091*pow(Rs/5463, -1.497))*10; //
 
  Serial.print("sensor_MQ:");
  Serial.print(sensor_MQ);
  Serial.print("    voltaje:");
  Serial.print(voltaje);
  Serial.print("    alcohol:");
  Serial.print(nivel_alcohol);
  Serial.println("mg/100ml");
  delay(100);
  
  if (nivel_alcohol  >= 20 && nivel_alcohol<= 39 ){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    Serial.println("Nivel: grado 0 de alcoholemia ");
    grado_0(); }
  
  if (nivel_alcohol >= 40&& sensor_MQ <= 99){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    grado_1();
   
    Serial.println("Nivel: grado 1 de alcoholemia ");
    }
  if (nivel_alcohol >= 100  && nivel_alcohol <= 149 ){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    grado_2();
    Serial.println("Nivel: grado 2 de alcoholemia ");
    }
  if (nivel_alcohol >= 150){ 
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    grado_3();
    Serial.println("Nivel: grado 3 de alcoholemia ");
    
    }
      
  delay(10);
  
}

void grado_0(){
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  delay(300);
}

void grado_1(){
  digitalWrite(6,HIGH);
  delay(200);
  digitalWrite(6,LOW);
  delay(200);
  
}

void grado_2(){
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);
  
}


void grado_3(){
  digitalWrite(6,HIGH);
  delay(50);
  digitalWrite(6,LOW);
  delay(50);
}
