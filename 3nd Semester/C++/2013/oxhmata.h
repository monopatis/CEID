#ifndef OXHMATA_H
#define OXHMATA_H
#include <iostream>
#include <string>
using std::string;

class oxhmata{

      public:
            oxhmata();

             virtual int get_nero();
             virtual int get_kausima();
             virtual int get_kat_kaus();
             virtual int get_kat_nero();
             virtual int get_katastash();
             virtual int get_type();
             virtual int get_age();
             virtual int get_id();
             virtual string get_name();

             virtual void set_nero(int a);
             virtual void set_kausima(int a);
             virtual void set_kat_kaus(int a);
             virtual void set_kat_nero(int a);
             virtual void set_katastash(int a);
             virtual void set_type(int a);
             virtual void set_age(int a);
             virtual void set_id(int a);

             virtual void decr_nero();
             virtual void decr_kausima();
             virtual void auxisi_hl();
             int nero;
             int kausima,id;
             int kat_kaus;
             int kat_nero;
             int katastash;
             int type;
             int age;
             string name;

};
#endif