  
  #include "SD.h"
  #define SD_ChipSelectPin 10
  #include "TMRpcm.h"                   //Microsd kart k�t�phanesi eklendi
  #include "SPI.h"
  TMRpcm tmrpcm;  
  const int pingTrigPin = 3;            //Trigger connected to PIN 7   
  const int pingEchoPin = 2;            //Echo connected yo PIN 8   
  int motor=4;                          //Motor to PIN 4   
  int d;
  
  void setup(){   
  Serial.begin(9600);                  //Seri monit�r ile ileti�im ba�lat�ld�
  pinMode(motor, OUTPUT);              //Motor pini ��k�� olarak atad�k
  pinMode(pingTrigPin, OUTPUT);        //Trig pini ��k�� olarak atad�k
  pinMode(pingEchoPin, INPUT);         //Echo pini giri� olarak atad�k
  tmrpcm.speakerPin=9;                 //hoparl�r pini 9. pine ba�l�
  
  if(!SD.begin(SD_ChipSelectPin))      //seri ileti�im ba�lat�lamassa "sd fail" yazd�r
  {
  Serial.println("SD fail");
  }
   
  }
  
  void loop(){
  
   
         
  long duration, cm;              //cm de�i�teni atad�k
  puls();                         //D�ng� etiketi
  
  duration = pulseIn(pingEchoPin, HIGH);     //echo pininden gelen sinyali "duration de�i�kenine atad�k.
  cm = microsecondsToCentimeters(duration);  //duration de�i�kenini santimetreye d�n��t�rme ve s�re atamas�.

  if(cm<=100 && cm>0){   
  d= map(cm, 1, 100, 800, 50);         //cm de�i�kenini motor �al��ma s�resine aktar. (motor �al��ma s�resi "d" de�i�kenidir.)
  vibrator();                           //mesafe 100cm alt�nda ise "vibrator" etiketli d�ng�ye git
  }
  
  if(cm<=30 && cm>0){wav0();}                           //mesafe 30cm alt�nda ise "wav1" etiketli d�ng�ye git  
  if(cm<=50 && cm>30){wav1();}                           //mesafe 50cm alt�nda ise "wav1" etiketli d�ng�ye git   
  if(cm<=100 && cm>50){wav2();}                           //mesafe 100cm alt�nda ise "wav2" etiketli d�ng�ye git 
  if(cm<=150 && cm>100){wav3();}                           //mesafe 150cm alt�nda ise "wav3" etiketli d�ng�ye git  
  if(cm<=200 && cm>150){wav4();}                           //mesafe 200cm alt�nda ise "wav4" etiketli d�ng�ye git 

     
  Serial.print(cm);    
  Serial.print("cm");                //Seri monit�re santimetre de�i�kenini yazd�r
  Serial.println();   
  delay(100); 
  }



  void puls(){
  digitalWrite(pingTrigPin, LOW);   //sens�re puls ver, sonra gelen puls i oku
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);     
  }

  void vibrator(){                     //motoru "d" de�i�kenine atanan s�re kadar durdur ve �al��t�r.
  digitalWrite(motor, HIGH);   
  delay(d);   
  digitalWrite(motor, LOW);   
  delay(50); 
  }

  void wav0(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("dikkat.wav");     //D�rt nolu wav dosyas�n� oynat.
  delay(2000);
  }

  void wav1(){               //D�ng� etiketi
  tmrpcm.setVolume(2);       //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("50cm.wav");      //Bir nolu wav dosyas�n� oynat.
  delay(5000);
  }

  void wav2(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("1metre.wav");     //�ki nolu wav dosyas�n� oynat.
  delay(6000);
  }

  void wav3(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("1_5metre.wav");     //�� nolu wav dosyas�n� oynat.
  delay(5000);
  }

  void wav4(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("2metre.wav");     //D�rt nolu wav dosyas�n� oynat.
  delay(5000);
  }

    
     
  long microsecondsToCentimeters(long microseconds) //D�ng�lerin �al��ma h�zlar�n�n ayarlar�.  
  {   
  return microseconds / 29 / 2;   
  }   
     
  #include "SD.h"
  #define SD_ChipSelectPin 10
  #include "TMRpcm.h"                   //Microsd kart k�t�phanesi eklendi
  #include "SPI.h"
  TMRpcm tmrpcm;  
  const int pingTrigPin = 3;            //Trigger connected to PIN 7   
  const int pingEchoPin = 2;            //Echo connected yo PIN 8   
  int motor=4;                          //Motor to PIN 4   
  int d;
  
  void setup(){   
  Serial.begin(9600);                  //Seri monit�r ile ileti�im ba�lat�ld�
  pinMode(motor, OUTPUT);              //Motor pini ��k�� olarak atad�k
  pinMode(pingTrigPin, OUTPUT);        //Trig pini ��k�� olarak atad�k
  pinMode(pingEchoPin, INPUT);         //Echo pini giri� olarak atad�k
  tmrpcm.speakerPin=9;                 //hoparl�r pini 9. pine ba�l�
  
  if(!SD.begin(SD_ChipSelectPin))      //seri ileti�im ba�lat�lamassa "sd fail" yazd�r
  {
  Serial.println("SD fail");
  }
   
  }
  
  void loop(){
  
   
         
  long duration, cm;              //cm de�i�teni atad�k
  puls();                         //D�ng� etiketi
  
  duration = pulseIn(pingEchoPin, HIGH);     //echo pininden gelen sinyali "duration de�i�kenine atad�k.
  cm = microsecondsToCentimeters(duration);  //duration de�i�kenini santimetreye d�n��t�rme ve s�re atamas�.

  if(cm<=100 && cm>0){   
  d= map(cm, 1, 100, 800, 50);         //cm de�i�kenini motor �al��ma s�resine aktar. (motor �al��ma s�resi "d" de�i�kenidir.)
  vibrator();                           //mesafe 100cm alt�nda ise "vibrator" etiketli d�ng�ye git
  }
  
  if(cm<=30 && cm>0){wav0();}                           //mesafe 30cm alt�nda ise "wav1" etiketli d�ng�ye git  
  if(cm<=50 && cm>30){wav1();}                           //mesafe 50cm alt�nda ise "wav1" etiketli d�ng�ye git   
  if(cm<=100 && cm>50){wav2();}                           //mesafe 100cm alt�nda ise "wav2" etiketli d�ng�ye git 
  if(cm<=150 && cm>100){wav3();}                           //mesafe 150cm alt�nda ise "wav3" etiketli d�ng�ye git  
  if(cm<=200 && cm>150){wav4();}                           //mesafe 200cm alt�nda ise "wav4" etiketli d�ng�ye git 

     
  Serial.print(cm);    
  Serial.print("cm");                //Seri monit�re santimetre de�i�kenini yazd�r
  Serial.println();   
  delay(100); 
  }



  void puls(){
  digitalWrite(pingTrigPin, LOW);   //sens�re puls ver, sonra gelen puls i oku
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);     
  }

  void vibrator(){                     //motoru "d" de�i�kenine atanan s�re kadar durdur ve �al��t�r.
  digitalWrite(motor, HIGH);   
  delay(d);   
  digitalWrite(motor, LOW);   
  delay(50); 
  }

  void wav0(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("dikkat.wav");     //D�rt nolu wav dosyas�n� oynat.
  delay(2000);
  }

  void wav1(){               //D�ng� etiketi
  tmrpcm.setVolume(2);       //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("50cm.wav");      //Bir nolu wav dosyas�n� oynat.
  delay(5000);
  }

  void wav2(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("1metre.wav");     //�ki nolu wav dosyas�n� oynat.
  delay(6000);
  }

  void wav3(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("1_5metre.wav");     //�� nolu wav dosyas�n� oynat.
  delay(5000);
  }

  void wav4(){              //D�ng� etiketi
  tmrpcm.setVolume(2);      //Oynat�lacak wav sesinin vol�m ayar�.
  tmrpcm.play("2metre.wav");     //D�rt nolu wav dosyas�n� oynat.
  delay(5000);
  }

    
     
  long microsecondsToCentimeters(long microseconds) //D�ng�lerin �al��ma h�zlar�n�n ayarlar�.  
  {   
  return microseconds / 29 / 2;   
  }   
   