const int pinTrigger = 2;  //Variable que contiene el número del pin al cual conectamos la señal "trigger"
const int pinEcho = 3;   //Variable que contiene el número del pin al cual conectamos la señal "echo"

void setup() {
  Serial.begin(9600);//Configuramos la comunicación serial
  pinMode(pinTrigger, OUTPUT); //Configuramoms el pin de "trigger" como salida
  pinMode(pinEcho, INPUT);  //Configuramoms el pin de "echo" como entrada
  digitalWrite(pinTrigger, LOW);//Ponemos en voltaje bajo(0V) el pin de "trigger"
}

void loop()
{

  unsigned long t; //Variable de tipo unsigned long que contendrá el tiempo que le toma a la señal ir y regresar
  float d; //Variable de tipo float que contendrá la distancia en cm

  digitalWrite(pinTrigger, HIGH);//Ponemos en voltaje alto(5V) el pin de "trigger"
  delayMicroseconds(10);//Esperamos en esta línea para conseguir un pulso de 10us
  digitalWrite(pinTrigger, LOW);//Ponemos en voltaje bajo(0V) el pin de "trigger"
  
  t = pulseIn(pinEcho, HIGH);         //Utilizamos la función  pulseIn() para medir el tiempo del pulso/echo
  d = t * 0.000001 * 34300.0 / 2.0; //Obtenemos la distancia considerando que la señal recorre dos veces la distancia a medir y que la velocidad del sonido es 343m/s
  
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  delay(1000);          //Nos mantenemos en esta línea durante 100ms antes de terminar el loop
}