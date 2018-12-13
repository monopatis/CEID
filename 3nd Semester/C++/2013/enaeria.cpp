#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "oxhmata.h"
#include "enaeria.h"

using std::string;

enaeria::enaeria(int type){
          age=rand()%5;
          if(type==2){
                     name="Canadair";
                      id=2;
                      nero=200;
                      kausima=300;
                      kat_kaus=50;
                      kat_nero=50;
                      katastash=1;
                      }
          else if(type==3){
               name="Tracker";
               id=3;
               nero=300;
               kausima=400;
               kat_kaus=40;
               kat_nero=50;
               katastash=1;
               }
         else if(type==4){
              name="Chinook";
              id=4;
              nero=500;
              kausima=600;
              kat_kaus=60;
              kat_nero=50;
              katastash=1;
              }
}