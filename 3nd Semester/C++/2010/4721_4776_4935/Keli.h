#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#ifndef KELI_H
#define KELI_H

#include "Toxotis.h"
#include "Xifomaxos.h"

class Keli
{
public:
       Keli( );
       void valepagida ( Soldier * );
       void killpagidakastro ( Soldier * );
       void setarithmospagidwn ( int );
       int getarithmospagidwn ( ) ;  
       void setpagida ( char );
       char getpagida ( ) ;
       void setkastro ( char );
       char getkastro ( ) ;
       int getplhthos ( int );
       void setplhthos ( int , int ); 
       queue < Soldier * > Pointers;
       void battle ( Soldier * );
       void printinfo ( char, int ) ;
private:       
       int arithmospagidwn ;
       char pagida;  
       char kastro; 
       int plhthos[4];
                  
};

#endif

