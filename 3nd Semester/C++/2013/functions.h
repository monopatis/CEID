#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "edafous.h"
#include "enaeria.h"
#include "oxhmata.h"

#define SIZ_X 16
#define SIZ_Y 22
#define ARXIKES_FOTIES 15 //το πολύ
#define ARXIKA_OXHMATA 20 //το πολύ

using namespace std;
//Ο χώρος για την εμφάνιση είναι 660*480 
const int SCREEN_WIDTH = 920;
const int SCREEN_HEIGHT = 540;
const int SCREEN_BPP = 32;

SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
bool init();
class functions{
      public:
             void arxikop_xarth();
             void showxarths();
             void game();
             void check_katastash();
             void e3aplosi_foties();
             void pros8iki_fotias(int x,int y);
             void svisimo_fotias(int x,int y);
             void neo_oxima(int x,int y,int types);
             void info_oximatos(int x,int y);
             void loadimages();
             void showimages();
             bool check_xarth();
             int rowcounter();
             int columncounter();
             void dhmiourgia();
             void add();
             void auxisi_hlikias();
             int xarths[SIZ_X][SIZ_Y];
             int x,y,i,k,types,a,b;
             edafous *ed[SIZ_X*SIZ_Y];
             enaeria *en[SIZ_X*SIZ_Y];
             int thesi_x[SIZ_X];
             int thesi_y[SIZ_Y];
             int ID[SIZ_X*SIZ_Y];
             int oxhm;
             char buf[100];
             
};
#endif