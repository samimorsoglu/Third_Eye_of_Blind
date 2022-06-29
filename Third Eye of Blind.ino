  
  #include "SD.h"
  #define SD_ChipSelectPin 10
  #include "TMRpcm.h"                   //Microsd kart kütüphanesi eklendi
  #include "SPI.h"
  TMRpcm tmrpcm;  
  const int pingTrigPin = 3;            //Trigger connected to PIN 7   
  const int pingEchoPin = 2;            //Echo connected yo PIN 8   
  int motor=4;                          //Motor to PIN 4   
  int d;
  
  void setup(){   
  Serial.begin(9600);                  //Seri monitör ile iletiþim baþlatýldý
  pinMode(motor, OUTPUT);              //Motor pini çýkýþ olarak atadýk
  pinMode(pingTrigPin, OUTPUT);        //Trig pini çýkýþ olarak atadýk
  pinMode(pingEchoPin, INPUT);         //Echo pini giriþ olarak atadýk
  tmrpcm.speakerPin=9;                 //hoparlör pini 9. pine baðlý
  
  if(!SD.begin(SD_ChipSelectPin))      //seri iletiþim baþlatýlamassa "sd fail" yazdýr
  {
  Serial.println("SD fail");
  }
   
  }
  
  void loop(){
  
   
         
  long duration, cm;              //cm deðiþteni atadýk
  puls();                         //Döngü etiketi
  
  duration = pulseIn(pingEchoPin, HIGH);     //echo pininden gelen sinyali "duration deðiþkenine atadýk.
  cm = microsecondsToCentimeters(duration);  //duration deðiþkenini santimetreye dönüþtürme ve süre atamasý.

  if(cm<=100 && cm>0){   
  d= map(cm, 1, 100, 800, 50);         //cm deðiþkenini motor çalýþma süresine aktar. (motor çalýþma süresi "d" deðiþkenidir.)
  vibrator();                           //mesafe 100cm altýnda ise "vibrator" etiketli döngüye git
  }
  
  if(cm<=30 && cm>0){wav0();}                           //mesafe 30cm altýnda ise "wav1" etiketli döngüye git  
  if(cm<=50 && cm>30){wav1();}                           //mesafe 50cm altýnda ise "wav1" etiketli döngüye git   
  if(cm<=100 && cm>50){wav2();}                           //mesafe 100cm altýnda ise "wav2" etiketli döngüye git 
  if(cm<=150 && cm>100){wav3();}                           //mesafe 150cm altýnda ise "wav3" etiketli döngüye git  
  if(cm<=200 && cm>150){wav4();}                           //mesafe 200cm altýnda ise "wav4" etiketli döngüye git 

     
  Serial.print(cm);    
  Serial.print("cm");                //Seri monitöre santimetre deðiþkenini yazdýr
  Serial.println();   
  delay(100); 
  }



  void puls(){
  digitalWrite(pingTrigPin, LOW);   //sensöre puls ver, sonra gelen puls i oku
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);     
  }

  void vibrator(){                     //motoru "d" deðiþkenine atanan süre kadar durdur ve çalýþtýr.
  digitalWrite(motor, HIGH);   
  delay(d);   
  digitalWrite(motor, LOW);   
  delay(50); 
  }

  void wav0(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("dikkat.wav");     //Dört nolu wav dosyasýný oynat.
  delay(2000);
  }

  void wav1(){               //Döngü etiketi
  tmrpcm.setVolume(2);       //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("50cm.wav");      //Bir nolu wav dosyasýný oynat.
  delay(5000);
  }

  void wav2(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("1metre.wav");     //Ýki nolu wav dosyasýný oynat.
  delay(6000);
  }

  void wav3(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("1_5metre.wav");     //Üç nolu wav dosyasýný oynat.
  delay(5000);
  }

  void wav4(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("2metre.wav");     //Dört nolu wav dosyasýný oynat.
  delay(5000);
  }

    
     
  long microsecondsToCentimeters(long microseconds) //Döngülerin çalýþma hýzlarýnýn ayarlarý.  
  {   
  return microseconds / 29 / 2;   
  }   
     
  #include "SD.h"
  #define SD_ChipSelectPin 10
  #include "TMRpcm.h"                   //Microsd kart kütüphanesi eklendi
  #include "SPI.h"
  TMRpcm tmrpcm;  
  const int pingTrigPin = 3;            //Trigger connected to PIN 7   
  const int pingEchoPin = 2;            //Echo connected yo PIN 8   
  int motor=4;                          //Motor to PIN 4   
  int d;
  
  void setup(){   
  Serial.begin(9600);                  //Seri monitör ile iletiþim baþlatýldý
  pinMode(motor, OUTPUT);              //Motor pini çýkýþ olarak atadýk
  pinMode(pingTrigPin, OUTPUT);        //Trig pini çýkýþ olarak atadýk
  pinMode(pingEchoPin, INPUT);         //Echo pini giriþ olarak atadýk
  tmrpcm.speakerPin=9;                 //hoparlör pini 9. pine baðlý
  
  if(!SD.begin(SD_ChipSelectPin))      //seri iletiþim baþlatýlamassa "sd fail" yazdýr
  {
  Serial.println("SD fail");
  }
   
  }
  
  void loop(){
  
   
         
  long duration, cm;              //cm deðiþteni atadýk
  puls();                         //Döngü etiketi
  
  duration = pulseIn(pingEchoPin, HIGH);     //echo pininden gelen sinyali "duration deðiþkenine atadýk.
  cm = microsecondsToCentimeters(duration);  //duration deðiþkenini santimetreye dönüþtürme ve süre atamasý.

  if(cm<=100 && cm>0){   
  d= map(cm, 1, 100, 800, 50);         //cm deðiþkenini motor çalýþma süresine aktar. (motor çalýþma süresi "d" deðiþkenidir.)
  vibrator();                           //mesafe 100cm altýnda ise "vibrator" etiketli döngüye git
  }
  
  if(cm<=30 && cm>0){wav0();}                           //mesafe 30cm altýnda ise "wav1" etiketli döngüye git  
  if(cm<=50 && cm>30){wav1();}                           //mesafe 50cm altýnda ise "wav1" etiketli döngüye git   
  if(cm<=100 && cm>50){wav2();}                           //mesafe 100cm altýnda ise "wav2" etiketli döngüye git 
  if(cm<=150 && cm>100){wav3();}                           //mesafe 150cm altýnda ise "wav3" etiketli döngüye git  
  if(cm<=200 && cm>150){wav4();}                           //mesafe 200cm altýnda ise "wav4" etiketli döngüye git 

     
  Serial.print(cm);    
  Serial.print("cm");                //Seri monitöre santimetre deðiþkenini yazdýr
  Serial.println();   
  delay(100); 
  }



  void puls(){
  digitalWrite(pingTrigPin, LOW);   //sensöre puls ver, sonra gelen puls i oku
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);     
  }

  void vibrator(){                     //motoru "d" deðiþkenine atanan süre kadar durdur ve çalýþtýr.
  digitalWrite(motor, HIGH);   
  delay(d);   
  digitalWrite(motor, LOW);   
  delay(50); 
  }

  void wav0(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("dikkat.wav");     //Dört nolu wav dosyasýný oynat.
  delay(2000);
  }

  void wav1(){               //Döngü etiketi
  tmrpcm.setVolume(2);       //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("50cm.wav");      //Bir nolu wav dosyasýný oynat.
  delay(5000);
  }

  void wav2(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("1metre.wav");     //Ýki nolu wav dosyasýný oynat.
  delay(6000);
  }

  void wav3(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("1_5metre.wav");     //Üç nolu wav dosyasýný oynat.
  delay(5000);
  }

  void wav4(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatýlacak wav sesinin volüm ayarý.
  tmrpcm.play("2metre.wav");     //Dört nolu wav dosyasýný oynat.
  delay(5000);
  }

    
     
  long microsecondsToCentimeters(long microseconds) //Döngülerin çalýþma hýzlarýnýn ayarlarý.  
  {   
  return microseconds / 29 / 2;   
  }   
   