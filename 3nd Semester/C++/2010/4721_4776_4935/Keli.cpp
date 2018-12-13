#include "Keli.h"

Keli::Keli( )
{
       setkastro('e');
       setpagida ('e');
       for ( int i=0; i<4; i++ )
        setplhthos(i,0);
       setarithmospagidwn ( 0 );
};

void Keli::valepagida( Soldier *vctr )
{

          if ( getpagida() == 'e' || getpagida () ==  vctr->gettypecamp())
          {
                setpagida ( vctr->gettypecamp() ) ;
                setarithmospagidwn(getarithmospagidwn()+1);
                cout<<"ROW"<<vctr->getx()<<",COL"<<vctr->gety()<<": "<<vctr->gettypecamp()<<vctr->getType()<<setfill( '0' ) << setw( 2 ) <<vctr->getid()<<" planted a trap\n";  
          }  
};

void Keli::setarithmospagidwn ( int ap )
{
     arithmospagidwn=ap;
};

int Keli::getarithmospagidwn ( )
{
    return arithmospagidwn ;
};

void Keli::killpagidakastro ( Soldier * vctr )
{
     if ( getarithmospagidwn() > 0 && getpagida() !=vctr->gettypecamp())//αν υπάρχει παγίδα διαφορετικού στρατοπέδου
     {
          setarithmospagidwn(getarithmospagidwn()-1);// αν πέφτουν στρατιώτες σε μια παγίδα αφαιρείται
          if ( getarithmospagidwn() == 0 ) setpagida ('e');
          vctr->setlife(false);
          cout<<"ROW"<<vctr->getx()<<",COL"<<vctr->gety()<<": "<<vctr->gettypecamp()<<vctr->getType()<<setfill( '0' ) << setw( 2 ) <<vctr->getid()<<" killed by trap\n";  
          setplhthos(vctr->gettypecamp()-'A',(getplhthos(vctr->gettypecamp()-'A')-1));
     }
     else if ( getkastro() != 'e' && getkastro() != vctr->gettypecamp() )
     {
          cout<<"ROW"<<vctr->getx()<<",COL"<<vctr->gety()<<": "<<vctr->gettypecamp()<<vctr->getType()<<setfill( '0' ) << setw( 2 ) <<vctr->getid()<<" killed by castle\n";  
          vctr->setlife(false);
          setplhthos(vctr->gettypecamp()-'A',(getplhthos(vctr->gettypecamp()-'A')-1));
     }
};

void Keli::setpagida ( char pag )
{
     pagida=pag;
};

char Keli::getpagida ( )
{
    return pagida ;
};


void Keli::setkastro ( char kas )
{
     kastro=kas;
};

char Keli::getkastro ( )
{
    return kastro ;
};


void Keli::setplhthos ( int i, int pl )
{
     plhthos[i]=pl;
};

int Keli::getplhthos ( int i )
{
    return plhthos[i] ;
};

void Keli::battle ( Soldier *A)
{
     int battlepith,k;
     
     do
     {
       battlepith= rand() % 100;
       if (A->getType()==Pointers.front()->getType())
       {
          k=50;
       }
       else
       {
           k=70;
       }
       if (k=50)
       {
           if (battlepith<k)
           {
              Pointers.front()->setlife ( false );
               cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
              << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<" killed by "
              <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<"\n";  
              setplhthos(Pointers.front()->gettypecamp()-'A', getplhthos(Pointers.front()->gettypecamp()-'A')-1);  
              Pointers.pop();
           }
           else
           {
               cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
               <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<" killed by "
               << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<"\n";
               setplhthos(A->gettypecamp()-'A', getplhthos(A->gettypecamp()-'A')-1); 
               A->setlife (false);
           }
       }
       else
       {
           if (battlepith<k)
           {
              if (A->getType()=='T')
              {
                 Pointers.front()->setlife ( false );
                 cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
                 << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<" killed by "
                 <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<"\n";
                 setplhthos(Pointers.front()->gettypecamp()-'A', getplhthos(Pointers.front()->gettypecamp()-'A')-1); 
                 Pointers.pop();
              }
              else
              {
                  A->setlife (false);
                  cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
                   <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<" killed by "
                   << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<"\n";
                   setplhthos(A->gettypecamp()-'A', getplhthos(A->gettypecamp()-'A')-1); 
              }
           }
           else
           {
               if (A->getType()=='X')
               {
                 Pointers.front()->setlife ( false );
                  cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
                 << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<" killed by "
                 <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<"\n";
                 setplhthos(Pointers.front()->gettypecamp()-'A', getplhthos(Pointers.front()->gettypecamp()-'A')-1); 
                 Pointers.pop();
              }
              else
              {
                  A->setlife (false);
                  cout<<"ROW"<<A->getx()<<",COL"<<A->gety()<<": "
               <<A->gettypecamp()<<A->getType()<<setfill( '0' ) << setw( 2 )<<A->getid()<<" killed by "
               << Pointers.front()->gettypecamp()<<Pointers.front()->getType()<<setfill( '0' ) << setw( 2 ) <<Pointers.front()->getid()<<"\n";
               setplhthos(A->gettypecamp()-'A', getplhthos(A->gettypecamp()-'A')-1); 
              }  
           } 
       } 
     } 
     while ((Pointers.size()>0) && (A->getlife()== true)); 
     if (A->getlife()== true)
     {  
        Pointers.push ( A );//τοποθέτηση στην ουρά
     }                                            
};

void Keli::printinfo ( char gramma, int Sigma )//εκτύπωση
{
     for ( gramma = 'A'; gramma<(Sigma+'A'); gramma++ ){
          cout << gramma << setfill( '0' ) << setw( 2 ) << getplhthos(gramma-'A');          
     }
     cout << "," << setfill( '0' ) << setw( 2 ) << getarithmospagidwn() << getpagida() << "," << getkastro() << " ";
};
