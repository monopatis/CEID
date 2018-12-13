#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#include "Toxotis.h"
#include "Xifomaxos.h"
#include "Keli.h"  

int Termination_Error ( )
{
     cout<<"To programma tha termatistei, ta noumera twn metavlhtwn tou arxeiou sou 3epernoun ta epitrepta oria.\n";
     system("PAUSE");
     return EXIT_SUCCESS;
}
      
char* printvaluesfiles(  )
{
     int i;
     char *p, stra[31], c[31];
     fstream myfile;
     p = &c[0];
     fflush(stdin);
     cout << "Enter the name of an existing text file: ";
     gets ( stra );
     myfile.open ( stra );        // open file
     if (myfile.is_open())
     { 
        for ( i=0; i<32; i++ )
         c[i] = myfile.get();      // get character from file
        for ( i=0; i<32; i++ ){
        if ( myfile.good() )
         cout << c[i];}
        myfile.close();           // close file   
     }
     else 
     {
          cout << "Unable to open file.";
     }
     cout << "\n";
     return p;
};


int main( )
{
    cout << "\n\n      KALOSHL8ATE STIS MONOMAXIES      \n\n";  
    char* str = printvaluesfiles( );
    while (*str!='N') str = printvaluesfiles( );
    int N=(*(str+2)-48)*10+(*(str+3)-48), i, a, b, j, P=0, strat, movepith , t, w, f ;
    int Sigma=*(str+7)-48;
    int S1=(*(str+12)-48)*10+(*(str+13)-48), 
        S2=(*(str+18)-48)*10+(*(str+19)-48), 
        S3=(*(str+24)-48)*10+(*(str+25)-48), 
        S4=(*(str+30)-48)*10+(*(str+31)-48), 
        h = (S1+S2+S3+S4);
    int S[4]={S1,S2,S3,S4};
    if (Sigma==3) S4=0;
    else if (Sigma==2)
    {
         S3=0;
         S4=0;
    }
    else if (Sigma!=4)
    {
         return Termination_Error ( );
    }
    int s[5]= { 0, S1, S1+S2, S1+S2+S3, S1+S2+S3+S4} ;
    for (i=0;i<4;i++)
    {
        if ((S[i]>20) || (S[i]<0))
        {
                  return Termination_Error ( );
        }
    }
    char gramma, nikitis, ca;
    bool z=true;
    nikitis = 'O';
    Keli kosmos[N][N];
    Toxotis toxotes[h/2];
    Xifomaxos xifomaxoi[h-h/2];
    vector< Soldier * > typeVector ( 2 );
    typeVector [ 0 ] = & toxotes[0];
    typeVector [ 1 ] = & xifomaxoi[0];
    srand( time ( 0 ) );
    // τοποθέτηση στρατοπέδων στον πίνακα 
    for ( gramma='A'; gramma<(Sigma+'A');)
    {
        a = rand() % N;
        b = rand() % N;
        if ( kosmos[a][b].getkastro() == 'e' )
        {
             kosmos[a][b].setkastro(gramma);
             kosmos[a][b].setplhthos(gramma-'A', S[gramma-'A']);
             t=0;
             w = s[P]/2;
             f = s[P+1]/2;
             for ( j=0; j<2; j++ )
             {
                 for ( strat=w; strat<f; strat++ )
                 {
                     typeVector[j]->setid( t );
                     typeVector[j]->settypecamp ( gramma );
                     typeVector[j]->setx ( a );
                     typeVector[j]->sety ( b );
                     t++;
                     kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.push(typeVector[j]);
                     typeVector[j]++;
                     
                 }
                 w = s[P] - s[P]/2;
                 f = s[P+1] - s[P+1]/2;
             }
             ++gramma;
             ++P;
        }
    }
    // εκτύπωση τοποθέτησης στρατοπέδων
    for ( i=0; i<N; i++ )
    {
        for ( j=0; j<N; j++ )
        {
            kosmos[i][j].printinfo(gramma, Sigma);
        }
        cout << "\n";         
    }
    // έναρξη παιχνιδιού
    while ( z==true )
    {
        cout << "Press ENTER to Continue...\n";
        fflush(stdin);
        ca=getchar();
        if ( ca == '\n' )
        {
        h = (S1+S2+S3+S4)/2;
        typeVector [ 0 ] = & toxotes[0];
        typeVector [ 1 ] = & xifomaxoi[0];
        for ( j=0; j<2; j++ )
        { 
            for ( i=0; i<h; i++ )
            {   
                       if ( typeVector[ j ]->getlife() == true && kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].getplhthos(typeVector[ j ]->gettypecamp()-'A') > 0 )
                       {
                          movepith = rand() % 100;
                          //κίνηση
                          if ( movepith < 80 || ( kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].getkastro() == typeVector[ j ]->gettypecamp() ))
                          {
                              kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].setplhthos(typeVector[ j ]->gettypecamp()-'A',kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].getplhthos(typeVector[ j ]->gettypecamp()-'A')-1);
                              if (kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.size()>0) 
                              {
                                 kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.pop();                                    
                              }
                              typeVector[ j ]->nextmove( typeVector[ j ]->getx(), typeVector[ j ]->gety(), N );
                              kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].setplhthos(typeVector[ j ]->gettypecamp()-'A',kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].getplhthos(typeVector[ j ]->gettypecamp()-'A')+1);                           
                              // έλεγχος για την ύπαρξη παγίδας και κάστρου
                              kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].killpagidakastro( typeVector[ j ] );
                              if (typeVector[ j ]->getlife() == true)
                              {
                                             if ((kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.size()>0) && (typeVector[j]->gettypecamp() != kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.front()->gettypecamp() ))
                                             {
                                                   //μονομαχίες
                                                    kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].battle(typeVector[j]);
                                             }                          
                                             else //τοποθέτηση στην ουρά
                                             {
                                                 kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.push(typeVector[j]);
                                             }
                          
                              }
                          }
                          //παγίδα
                          else
                          {
                                   kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].valepagida( typeVector[ j ] );
                                   kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.pop();
                                   kosmos[typeVector[ j ]->getx()][typeVector[ j ]->gety()].Pointers.push(typeVector[j]);
                          }
                       }
                       typeVector[j]++; 
            }
            h = (S1+S2+S3+S4) - (S1+S2+S3+S4)/2;
        }
        cout << endl;
        h = (S1+S2+S3+S4)/2;
        typeVector [ 0 ] = & toxotes[0];
        typeVector [ 1 ] = & xifomaxoi[0];
        S[0]=S1, S[1]=S2, S[2]=S3, S[3]=S4;
    //Μέτρηση των πεθαμένων
        for ( j=0; j<2; j++ )
        {
           
            for ( i=0; i<h; i++ )
            {
                if ( typeVector[ j ]->getlife() == false )
                {
                     S[typeVector[ j ]->gettypecamp()-'A']--;
                }
                typeVector[j]++;
            }
            h = (S1+S2+S3+S4) - (S1+S2+S3+S4)/2;
        }
        if (S[0]+S[1]+S[2]+S[3]==0)//Έλεγχος για ισοπαλία
        {
            nikitis='E'; 
            z=false;
        }
        //Έλεγχοι για την ύπαρξη νικητή
        else for (i=0;i<4;i++) 
        {
             if ( S[i]==S[0]+S[1]+S[2]+S[3] )
             {
                     nikitis='A'+i;
                     i=4;
                     z=false;
             }
        }
        
        for ( i=0; i<N; i++ )
        {
            for ( j=0; j<N; j++ )
            {
                kosmos[i][j].printinfo( gramma, Sigma );
            }
            cout << "\n";  
        }            
        }
    }
    
    if (nikitis=='E')
       cout << "\nIsopalia\n";
    else
    cout <<"\nNikitis einai o:" << nikitis << "\n";
    system("PAUSE");
    return 0;
    
}
