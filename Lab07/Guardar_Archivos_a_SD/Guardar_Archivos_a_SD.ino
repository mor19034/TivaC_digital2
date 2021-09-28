File scores;

//*********************************************************************
  //********************* codigo tarjeda SD*******************************
  //reabriendo para escribir
  scores = SD.open("res.txt", FILE_WRITE);
  if (scores) {
    Serial.println("probando");

    scores.seek(0); //se coloca en la posición 0 para reescribir sobre los valores viejos
    scores.print(J1 + "," + J2);  //se imprimen los nuevos resultados separados por una coma
    // close the file:
    scores.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    //Serial.println("error opening test.txt");
    Serial.println("F de F");
  }
  //*********************************************************************
}
//funcion para hacer el split de la lectura serial
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
