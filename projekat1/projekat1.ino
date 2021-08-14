int tempSenzor = 0;
int segA = 2;//pale se segmenti a,b,c,d,e,f,g i tacka pt
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;
int segPt = 13;

int d1 = 9;//pale se cifre
int d2 = 10;
int d3 = 11;
int d4 = 12;

char inChar='b';

int delayTime = 900;//moglo je i bez ovoga samo kasnije da se pise obican delay(neka vrednost)
int counter = 0;
float temperatura = 1.2;//nije od nekog znacaja posto ga svakako koristim samo abc=1,odnosno kod a,ostalo mi ne treba nista na displeju
int abc = 0; //za a i b

//boolean ispisujCrtice = false;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(12, OUTPUT);// sta su input i output
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(0, INPUT);
  
  while(abc==0){//pisano u setapu kao neko default-no stanje sa ispisom crtica
  Serial.println("Konverzija neaktivna");
 // delay(500);
  nultoStanje();
  
  if((char)Serial.read()== 'a'){//u slucaju da je na serialu uneto a,sta se dalje desava sa tim a
    abc=1;
  }
}
}

void loop() {

while(abc==1){
if (Serial.available()){//sve ovo je provera dal je a ili b uneto sa seriala,dal je ista uneto sa seriala
   inChar = (char)Serial.read();
   if(inChar=='b')//inace abc=1 je uneto a,a abc=0 je kod default-a i nakon ako se unese b isto ga gleda
   abc=0;

}
  if (counter % 500 == 0)//cekanje obicno kao delay
  {
    int procitaj = analogRead(tempSenzor);//cita vrednost senzora
    float bla = (procitaj * 5.0);//mnozi sa 5 da bi kasnije mogli da podelimo,pomnozimo i dobijemo ok vrednbosti za displej
    bla /= 1024.0;
    temperatura = bla * 100.0;
    Serial.print(temperatura);
    Serial.println(" stepeni");
   counter = 0;
  }

  counter ++;

  selectDigit(1);//posto je loop selectDigit mi prvo gasi tu cifru da bi kasnije preko izracunatog sendDigita znao koje segmente pali i da upali tu cifru
  sendDigit(prva(temperatura));//ostatak je sve jedno te isto doduse sa tackom i kruzicem za stepen
  delayMicroseconds(delayTime);

  digitalWrite(d1, HIGH);
  selectDigit(2);
  sendDigit(druga(temperatura));
  tacka();
  delayMicroseconds(delayTime);

  digitalWrite(d2, HIGH);
  selectDigit(3);
  sendDigit(treca(temperatura));
  delayMicroseconds(delayTime);

  digitalWrite(d3, HIGH);
  digitalWrite(segPt, HIGH);
  selectDigit(4);
  kruzic();
  delayMicroseconds(delayTime);
  digitalWrite(d4, HIGH);


  }

   if(abc==0){ //sa unetog b proverava dal ce biti uneto a i ako oce da ga vrati gore na izracunavanje i ispis,inace stalno se ovako proverava zbog displeja kad ce sta da ispise
        if (Serial.available()){
   inChar = (char)Serial.read();
   if(inChar=='a')
   abc=1;
    }

 Serial.println("Konverzija neaktivna,unesi a da bi postala aktivna");//za nultostanje
// delay(500);
  dd1();
  dd2();
  dd3();
  dd4();
  
  nultoStanje();
  }
}


void clearDisplay(){
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}

void jedan()//za senddigit kako pali brojke
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);//tacka tackica

}
void dva()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void tri()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void cetiri()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void pet()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void sest()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void sedam()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);

}
void osam()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void devet()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);

}
void nula()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);

}

void kruzic()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}

void tacka()
{
  digitalWrite(segPt, HIGH);
}

void nultoStanje()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
  delay(5);
  
}

void selectDigit(int d)//objasnjeno iznad sta radi(gasi prvo zbog loop-a)
{
  switch (d)
  {
    case 1:
      digitalWrite(d1, LOW);
      break;
    case 2:
      digitalWrite(d2, LOW);
      break;
    case 3:
      digitalWrite(d3, LOW);
      break;
    default:
      digitalWrite(d4, LOW);
      break;
  }
}

void dd1(){//paljenje i gasenje za cele cifre
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
 delay(5);
  }
 void dd2(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  delay(5);
  }
 void dd3(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
  delay(5);
  }
 void dd4(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
   delay(5);
  }


void sendDigit(int x)//ono sto izracuna gore,prosledjuje tu vrednost i ulazi u case u koji treba i radi funkciju paljenja tog nekog broja
{
  switch (x)
  {
    case 1:
      jedan();
      break;
    case 2:
      dva();
      break;
    case 3:
      tri();
      break;
    case 4:
      cetiri();
      break;
    case 5:
      pet();
      break;
    case 6:
      sest();
      break;
    case 7:
      sedam();
      break;
    case 8:
      osam();
      break;
    case 9:
      devet();
      break;
    case 10:
      kruzic();
      break;
    default:
      nula();
      break;
  }
}

int prva(float x)//za sendDigit sluzi kad se pozove da onu trenutno tempis uzme i makne prvu cifru i takvu je vrati gde treba(u int)
{
  float podeli = x / 10.0;
  return (int)podeli;
}

int druga(float x)//isto sve kao gore napisano samo sto 10.0 mnozi sa prvom i kad oduzme ono prosledjeno od toga,dobija se drugi broj,kad kazem prvi i drugi mislim na desetice i jedinice
{
  float podeli = x - (10.0 * prva(x));
  return (int)podeli;
}

int treca(float x)//sve je isto
  float podeli = x - (10.0 * prva(x)) - druga(x);
  podeli *= 10;
  return (int)divided;
}
