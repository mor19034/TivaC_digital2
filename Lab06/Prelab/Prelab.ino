// asignarle variables a pines:
const int buttonPin = PUSH1;     // numero de pin de pushbutton 

// variables will change:
int buttonState = 0;         // variable para leer el estado del boton
int counter = 0;             //variable que va a llevar el valor del contador
int presionado = 0;

void setup() {     
  // el boton se coloca como input:
  pinMode(buttonPin, INPUT_PULLUP);  
  //iniciar comunicacion serial
  Serial.begin(9600);   
}

void loop() {
  // leer el estado del boton:
  buttonState = digitalRead(buttonPin);

  // revisar si el boton esta presionado.
  if (buttonState == LOW) {
    presionado = 1; //vairable cambia de valor
  }
    if (buttonState == HIGH&&presionado == 1){ //este es el antirebote     
    // aumentar contador:
    counter++;
    presionado = 0; //la variable regresa a su estado original
      
    //imprimir el valor     
    Serial.println(counter);  
  } 
  else {
    // no hace nada:
    Serial.println(counter);  
  }
   //si el contador sube a un valor mayor a 255 se reinicia
   if  (counter > 255) {
    counter = 0;  
        }
  
}
