#include <SPI.h>
#include <SD.h>

File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(10, OUTPUT);

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  Serial.println("Ingrese el numero 1 para escoger la opcion de Gombat");
  Serial.println("Ingrese el numero 2 para escoger la opcion de Luigi");
  Serial.println("Ingrese el numero 3 para escoger la opcion de MasterChief");

}

char mostrar = 0;
int archivo, opcion;

void loop()
{
  if (Serial.available() > 0) {
    mostrar = 1;
    archivo = Serial.read();
    if (archivo == '1') {
      Serial.println("Escogio el archivo Gombat");
      opcion=1;
    } else if (archivo == '2') {
      Serial.println("Escogio el archivo Luigi");
      opcion=2;
    } else if (archivo == '3') {
      Serial.println("Escogio el archivo MasterChief");
      opcion=3;
    } else {
      Serial.println("No ingreso ninguna opcion correcta");
      //mostrar = 0;
     
    }

  }
  if (mostrar == 1) {
    switch (opcion) {
      case 1:
        myFile = SD.open("GOMBAT.txt");
        if (myFile) {
          Serial.println("GOMBAT.txt:");

          // read from the file until there's nothing else in it:
          while (myFile.available()) {
            Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        mostrar = 0;
        break;
      case 2:
        myFile = SD.open("LUIGI.txt");
        if (myFile) {
          Serial.println("LUIGI.txt:");

          // read from the file until there's nothing else in it:
          while (myFile.available()) {
            Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        mostrar = 0;
        break;
      case 3:
        myFile = SD.open("MASTERCHIEF.txt");
        if (myFile) {
          Serial.println("MASTERCHIEF.txt:");

          // read from the file until there's nothing else in it:
          while (myFile.available()) {
            Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        mostrar = 0;
        break;


    }

  }

}
