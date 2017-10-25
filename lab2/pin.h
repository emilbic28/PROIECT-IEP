#ifndef PIN_H
#define PIN_H


 class Pin
 {
 public:
     Pin(int numar,int directia,int starea );
     int numar;
     int directia;
     int stare;
     int get(int stare);
     void set(int p);
     void change();
 };
 #endif // PIN_H
