  
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
  Serial.begin(9600);                  //Seri monitör ile iletişim başlatıldı
  pinMode(motor, OUTPUT);              //Motor pini çıkış olarak atadık
  pinMode(pingTrigPin, OUTPUT);        //Trig pini çıkış olarak atadık
  pinMode(pingEchoPin, INPUT);         //Echo pini giriş olarak atadık
  tmrpcm.speakerPin=9;                 //hoparlör pini 9. pine bağlı
  
  if(!SD.begin(SD_ChipSelectPin))      //seri iletişim başlatılamassa "sd fail" yazdır
  {
  Serial.println("SD fail");
  }
   
  }
  
  void loop(){
  
   
         
  long duration, cm;              //cm değişteni atadık
  puls();                         //Döngü etiketi
  
  duration = pulseIn(pingEchoPin, HIGH);     //echo pininden gelen sinyali "duration değişkenine atadık.
  cm = microsecondsToCentimeters(duration);  //duration değişkenini santimetreye dönüştürme ve süre ataması.

  if(cm<=100 && cm>0){   
  d= map(cm, 1, 100, 800, 50);         //cm değişkenini motor çalışma süresine aktar. (motor çalışma süresi "d" değişkenidir.)
  vibrator();                           //mesafe 100cm altında ise "vibrator" etiketli döngüye git
  }
  
  if(cm<=30 && cm>0){wav0();}                           //mesafe 30cm altında ise "wav1" etiketli döngüye git  
  if(cm<=50 && cm>30){wav1();}                           //mesafe 50cm altında ise "wav1" etiketli döngüye git   
  if(cm<=100 && cm>50){wav2();}                           //mesafe 100cm altında ise "wav2" etiketli döngüye git 
  if(cm<=150 && cm>100){wav3();}                           //mesafe 150cm altında ise "wav3" etiketli döngüye git  
  if(cm<=200 && cm>150){wav4();}                           //mesafe 200cm altında ise "wav4" etiketli döngüye git 

     
  Serial.print(cm);    
  Serial.print("cm");                //Seri monitöre santimetre değişkenini yazdır
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

  void vibrator(){                     //motoru "d" değişkenine atanan süre kadar durdur ve çalıştır.
  digitalWrite(motor, HIGH);   
  delay(d);   
  digitalWrite(motor, LOW);   
  delay(50); 
  }

  void wav0(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatılacak wav sesinin volüm ayarı.
  tmrpcm.play("dikkat.wav");     //Dört nolu wav dosyasını oynat.
  delay(2000);
  }

  void wav1(){               //Döngü etiketi
  tmrpcm.setVolume(2);       //Oynatılacak wav sesinin volüm ayarı.
  tmrpcm.play("50cm.wav");      //Bir nolu wav dosyasını oynat.
  delay(5000);
  }

  void wav2(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatılacak wav sesinin volüm ayarı.
  tmrpcm.play("1metre.wav");     //İki nolu wav dosyasını oynat.
  delay(6000);
  }

  void wav3(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatılacak wav sesinin volüm ayarı.
  tmrpcm.play("1_5metre.wav");     //Üç nolu wav dosyasını oynat.
  delay(5000);
  }

  void wav4(){              //Döngü etiketi
  tmrpcm.setVolume(2);      //Oynatılacak wav sesinin volüm ayarı.
  tmrpcm.play("2metre.wav");     //Dört nolu wav dosyasını oynat.
  delay(5000);
  }

    
     
  long microsecondsToCentimeters(long microseconds) //Döngülerin çalışma hızlarının ayarları.  
  {   
  return microseconds / 29 / 2;   
  }   
     
