#ifndef SOLDIER_H
#define SOLDIER_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Soldier    
{
public:
      virtual int nextmove( int, int, int );
      virtual char getType ( ) const = 0;
      virtual bool getlife( );
      virtual void setlife( bool );     
      virtual void setx ( int );
      virtual int getx ( void ) ;
      virtual void sety ( int );
      virtual int gety ( void );
      virtual int getid( );
      virtual void setid ( int );
      virtual void settypecamp ( char );
      virtual char gettypecamp ( void );
private:      
      bool life;
      char typecamp;
      int x, y, id;
};

#endif
