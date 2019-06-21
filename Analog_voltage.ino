#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;


void setup() 
{
 Serial.begin(9600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.print("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  if (SD.exists("datalog.txt")) {
    Serial.println("datalog.txt exists.");
  } else {
    Serial.println("datalog.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating datalog.txt...");
File dataFile = SD.open("datalog.txt", FILE_WRITE);
  dataFile.close();

  // Check to see if the file exists:
  if (SD.exists("datalog.txt")) {
    Serial.println("datalog.txt exists.");
  } else {
    Serial.println("datalog.txt doesn't exist.");
  }
}
void loop() 
{
  int dataString;
 
  
  for (int i=0;i<100;i++)
  {
     int dataString = analogRead(A0);
     File dataFile = SD.open("datalog.txt", FILE_WRITE);
     if (dataFile)
     {
         dataFile.println(dataString);
         dataFile.close();
         Serial.println(dataString);
     }

     else
     {
         Serial.println("error opening datalog.txt");
     }
 
     delay(5000);
  }
}




  
