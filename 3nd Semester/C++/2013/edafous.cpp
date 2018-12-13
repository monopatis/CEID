#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "oxhmata.h"
#include "edafous.h"

using std::string;

edafous::edafous(int type){
          age=rand()%5;
          if(type==5){
                      name="Scania";
                      id=5;
                      nero=80;
                      kausima=70;
                      kat_kaus=5;
                      kat_nero=20;
                      katastash=1;
                      }
          else if(type==6){
               name="Daf";
               id=6;
               nero=100;
               kausima=75;
               kat_kaus=7;
               kat_nero=25;
               katastash=1;
               }
         else if(type==7){
              name="Man";
              id=7;
              nero=100;
              kausima=80;
              kat_kaus=9;
              kat_nero=20;
              katastash=1;
              }
}
