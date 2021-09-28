//******librerias************
#include <SPI.h>
#include <SD.h>
//----Variables generales----
File root;
char opcion = '0';
uint8_t control = 0;
char inByte; //variable que ingresa el usuario
//----Prototipos-------
void printDirectory(File dir, int numTabs);
void readText(char dir);

void setup()
{
  // Iniciar comunicacion serial y esperar a que el puerto respoda:
  Serial.begin(115200);
  SPI.setModule(0); //esto indica que puertos se van a usar

  Serial.print("Initializing SD card...");
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) { //si no esta bien conectado sale error
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  Serial.println("done!");
}

void loop()
{
  if (control == 0) { //esto sirve como bandera para que los mensajes que salen en la terminal se queden estáticos hasta que se
    //seleccione una opción y despligue los datos.
    root = SD.open("/"); //se almacena la lectura de la SD en una variable.
    printDirectory(root, 0); //se imprime lo que contiene la varibale (datos que hay dentro de la SD).
    Serial.println("Escriba la posicion del archivo que desea ver: ");
    control++; //al aumentar el valor de control se asegura que el mensaje de menu no aparesca hasta que se halla seleccionado
  }             //una opcion.
  if (Serial.available()) {
    inByte = Serial.read();//se guarda el valor enviado por serial
  }
  if (inByte == '1') {//si el valor recibido es un 1
    opcion = '1'; //se coloca un 1 a la opcion 
    control--; //se coloca en 0 control para que se muestre el menu de nuevo.
  }
  if (inByte == '2') {//misma logica que cuando se recibe un 1
    opcion = '2';
    control--;
  }
  if (inByte == '3') {//misma logica que cuando se recibe un 1
    opcion = '3';
    control--;
  }
  if (inByte == '4') {//misma logica que cuando se recibe un 1
    opcion = '4';
    control--;
  }  
  readText(opcion);
  opcion = '0'; //se asegura que opcion siempre sea 0 para evitar que se muestre valores no deseados
}

void readText(char dir) {
  uint8_t seleccion;
  File archivo;
  switch (dir) {//Se abre el archivo dependiendo del valor que tenga la variable opcion 
    case '1':
      archivo = SD.open("pikachu.txt");
      seleccion = 1; //habilita la rutina de mostrar el contenido
      break;
    case '2':
      archivo = SD.open("pacman.txt");
      seleccion = 1;
      break;
    case '3':
      archivo = SD.open("spider.txt");
      seleccion = 1;
      break;
    case '4':
      archivo = SD.open("BAD_BU~1.txt");
      seleccion = 1;
      break;
    default:
      seleccion = 0;//inhabilita la rutina de mostrar el contenido
      break;
  }
  if (seleccion == 1) {//rutina que sirve para mostrar la informacion guardada en el archivo seleccionado
    if (archivo) {
      Serial.println(archivo.name());

      // read from the file until there's nothing else in it:
      while (archivo.available()) {
        Serial.write(archivo.read());
      }
      // close the file:
      archivo.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
  }
}

void printDirectory(File dir, int numTabs) {//en esta rutina se muestra el contenido guardado en la SD
  dir.rewindDirectory();
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
