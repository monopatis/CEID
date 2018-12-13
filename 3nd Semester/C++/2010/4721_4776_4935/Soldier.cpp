#include "Soldier.h"

// επόμενη κίνηση
int Soldier::nextmove( int a, int b , int N )
{
     cout<<"ROW"<<getx()<<",COL"<<gety()<<": "<<gettypecamp()<<getType()<<setfill( '0' ) << setw( 2 ) <<getid();  
     int epomenikinisi;
     epomenikinisi = rand () % 100;                  
     if ( epomenikinisi < 25 )
     {
          b++;
          if ( b == N )
          {
               b = b-2;
          }
     }
     else if ( epomenikinisi < 50 )
     {
          b-- ;
          if ( b == -1 )
          {
               b = b+2;
          }
     }
     else if ( epomenikinisi < 80 )
     {
          a--;
          if ( a == -1 )
          {
               a = a+2;
          }
     }
     else
     {
         a++;
         if ( a == N )
         {
              a = a-2;
         }
     }
     setx ( a );
     sety ( b ) ;
     cout<<"("<<getx()<<","<<gety()<<")\n";
};

void Soldier:: setx ( int a )
{
     x=a;
}    ;

void Soldier:: sety ( int b )
{
     y=b;
}    ;

int Soldier:: getx (  )
{
     return x ;
};

int Soldier:: gety ( )
{
    return y ;
}   ;    

void Soldier::settypecamp ( char a )
{
     typecamp=a;
}    ;

char Soldier::gettypecamp ( void )
{    
     return typecamp;
};

void Soldier::setid ( int a )
{
     id=a;
};
    
int Soldier::getid ( )
{
    return id ;
};

void Soldier::setlife ( bool a )
{
     life = a;
};

bool Soldier::getlife ( )
{
     return life;
};
