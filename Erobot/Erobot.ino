#include <ATX2.h> // ATX2 Board
int L1,C1,C2,R2,BL,BR;
int i = 1;

void setup()
{
  glcd(0,0, "Ready");
  servo(3,80); delay(100);
  while(in(30));
  while(!in(30));
  glcdClear();
  stateup();
 // lineb();
  // ss(10000);
}

void loop()
{
  L1 = analog(0);
  C1 = analog(1);
  C2 = analog(1);
  R2 = analog(3);
  BL = analog(4);
  BR = analog(5);
  if (C1 < 300 && C2 < 300 || L1 < 300 && C1 < 300 || C2 < 300 && R2 < 300 || L1 < 300 && R2 < 300)
  { 
    switch (i) 
    { 
    case 1:rr(); break;//r180(); lineb(); fl90(); lineb(); break;
    case 2:shoot(); r180(); break;
    case 3:ll(); lineb(); break;
    case 4:rr(); break;
    case 5:rr(); break;
    case 6:shoot(); r180(); break;
    case 7:ll(); lineb(); fr90(); break;
    case 8:rr(); lineb(); break;
    case 9:shoot(); r180(); break;
    case 10:ll(); lineb(); break;
    case 11:rr(); fr90(); break;
    case 12:r180(); break;
    case 13:rr(); break;
    case 14:ll(); fr90(); break;
    case 15:ll(); break;
    case 16:shoot(); r180(); break;
    case 17:rr(); lineb(); break;
    case 18:rr(); lineb(); break;
    case 19:rr(); lineb(); break;
    case 20:ll(); lineb(); break;
    case 21:ll(); lineb(); break;
    case 22:r180(); lineb(); break;
    case 23:rr(); fr90(); rr(); bfr90(); break;
    case 24: ss(10000000); break;
    }
    i++;
  }
  else if (L1 < 400) {motor(1, 60); motor(2, 5);}
  else if (R2 < 400) {motor(1, 5); motor(2, 60);}

  else ff(10);

}
void ff(int x) {motor(1,52); motor(2,50); sleep(x);}
void ss(int x) {motor(1,0); motor(2,00); sleep(x);}
void bb(int x) {motor(1,-32); motor(2,-30); sleep(x);}

void sbr() {ss(50); bb(450); ss(500);}

void rr() {ss(250); bb(300);motor(1,32); motor(2,-30);sleep(300);ss(200);}
void ll() {ss(250); bb(300); motor(1,-30); motor(2,30);sleep(300);ss(200);}
void r180() {ss(250); bb(300); sr(30); sleep(630);ss(200);}

void r90() {motor(1,32); motor(2,-30);sleep(350);}
void l90() {motor(1,-30); motor(2,30);sleep(350);}

void rbf() {bb(2000); r180();}

void fl90() {ff(600); ss(300); ll();}
void fr90() {ff(600); ss(300); rr();}
void bfl90() {ff(725); ss(300); l90();}
void bfr90() {ff(725); ss(300); r90();}

//void TrkL() {motor(1,52); motor(2,00);sleep(200); ff(200); motor(1,02); motor(2,50);sleep(200);}
//void TrkR() {motor(1,2); motor(2,50);sleep(200); ff(200); motor(1,52); motor(2,00);sleep(200);}

void lineb()//for + only
{
  /*
  ss(200);
 while(analog(4) > 600 && analog(5) > 600) {bk(20); sleep(1);
  if(analog(4) < 600 && analog(5) > 600)
   {
     while(analog(4) > 600)  {motor(1,0);motor(2,-35);sleep(100);}
   }
 if(analog(4) > 600 && analog(5) < 600)
   {
     while(analog(5) > 600)  {motor(1,-35);motor(2,0);sleep(100);}
   }*/
   while(analog(4) > 500 && analog(5) > 500){bk(25); sleep(10);}
   while(analog(4) < 500 && analog(5) > 500){if(analog(4) < 500){if(analog(4) > 500){fd(20); sleep(30);} motor(1, 0); motor(2, -20); sleep(100);}}
   while(analog(4) > 500 && analog(5) < 500){if(analog(5) < 500) {if(analog(5) > 500){fd(20); sleep(30);} motor(1, -20); motor(2, 0); sleep(100);}}

   ss(200);
}

void reload(){servo(3,80); delay(100);}
void shoot(){ss(500); bb(500); ss(500); servo(3,00); delay(100); reload();}

void stateup() { ff(400); ss(500); r90(); ss(500); bfr90(); }
