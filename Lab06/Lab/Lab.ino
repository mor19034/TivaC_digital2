// asignarle variables a pines:
#define LED0 RED_LED  
#define LED1 GREEN_LED
const int buttonPin1 = PUSH1;     // numero de pin de pushbutton 
const int buttonPin2 = PUSH2;     // numero de pin de pushbutton 


// variables will change:
int buttonState1 = 0;         // variable para leer el estado del boton 1
int buttonState2 = 0;         // variable para leer el estado del boton 2
int presionado = 0;

  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);  
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP);  
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == LOW or buttonState2 == LOW){
    presionado = 1; //vairable cambia de valor
  }
    if (buttonState1 == HIGH&&presionado == 1 or buttonState2 == HIGH&&presionado == 1){ //este es el antirebote
    digitalWrite(LED0, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(LED1, HIGH);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    digitalWrite(LED0, LOW);   //wait for a second
    delay(1000);
    digitalWrite(LED1, LOW);  //se apaga el led verde
    presionado = 0;
  }
  else {} //no hace nada
}
