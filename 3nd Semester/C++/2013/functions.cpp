#include "functions.h"

//The surfaces
//ΝΑ είναι οπωσδήποτε εδώ!!
SDL_Surface *fire = NULL;
SDL_Surface *stathmos = NULL;
SDL_Surface *oxima2 = NULL;
SDL_Surface *oxima3 = NULL;
SDL_Surface *oxima4 = NULL;
SDL_Surface *oxima5 = NULL;
SDL_Surface *oxima6 = NULL;
SDL_Surface *oxima7 = NULL;
SDL_Surface *oxima[] = {oxima2,oxima3,oxima4,oxima5,oxima6,oxima7};
SDL_Surface *message1 = NULL;
SDL_Surface *message2 = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *velos0 = NULL;
SDL_Surface *velos1 = NULL;
SDL_Surface *velos2 = NULL;
SDL_Surface *velos3 = NULL;
SDL_Surface *velos4 = NULL;
SDL_Surface *velos5 = NULL;
SDL_Surface *velos6 = NULL;
SDL_Surface *velos7 = NULL;
SDL_Surface *velos[] = {velos0,velos1,velos2,velos3,velos4,velos5,velos6,velos7};

//The font that's going to be used
TTF_Font *font = NULL;
//The color of the font
SDL_Color textColor = { 255, 255, 255 };

void FillRect(int x, int y, int w, int h, int color) {
      SDL_Rect rect = {x,y,w,h};
      SDL_FillRect(screen, &rect, color);
}

void functions::arxikop_xarth(){
     for(x=0 ; x<SIZ_X;x++){
             for(y=0; y<SIZ_Y; y++){
                      xarths[x][y]=0;
             }
     }
     srand( time ( 0 ) );
     //kentro
     xarths[SIZ_X-1][SIZ_Y-1]=99;
     //Arxikopoiisi fotion
     k=rand()%ARXIKES_FOTIES +1;
     for(i=0; i<k; i++){
      x=rand()%SIZ_X;
      y=rand()%SIZ_Y;
      do{ 
          x=rand()%SIZ_X;
          y=rand()%SIZ_Y;
        //Oso den einai keno keli 3anaprospathise
        }while (xarths[x][y]!=0);
      xarths[x][y]=1;
     }
     oxhm=rand()%ARXIKA_OXHMATA +1;
     cout<<oxhm<<" arxika oxhmata"<<endl;
     for(i=0;i<oxhm;i++){
        types=rand()%6 +2;
        cout<<"Ena tupou: "<<types<<endl;
        switch(types){
          case 2: case 3: case 4:
            en[i]=new enaeria(types);
            ID[i]=types;
            do{
               x=rand()%SIZ_X;
               y=rand()%SIZ_Y;
            }while(xarths[x][y]!=0);         
            thesi_x[i]=x;
            thesi_y[i]=y;
            xarths[x][y]=en[i]->id;
            break;
         case 5: case 6: case 7:
            ed[i]=new edafous(types);
            ID[i]=types;
            do{
              x=rand()%SIZ_X;
              y=rand()%SIZ_Y;
            }while(xarths[x][y]!=0);    
            thesi_x[i]=x;
            thesi_y[i]=y;
            xarths[x][y]=ed[i]->id; 
            break; 
        }
     }
}

//Emfanisi xarti sto terminal
void functions::showxarths(){
  for(x=0 ; x<SIZ_X; x++){
    for(y=0; y<SIZ_Y; y++){
            cout<<xarths[x][y];
    }
  cout<<endl;
  }
}

void functions::showimages(){
  for(x=0 ; x<SIZ_X; x++){
    for(y=0; y<SIZ_Y; y++){
      if (xarths[x][y]==1){
        FillRect(y*30,x*30,30,30,0x0);
        //Apply the surface to the screen
        apply_surface( y*30, x*30, fire, screen );
      }
      if (xarths[x][y]==99){
        FillRect(y*30,x*30,30,30,0x0);
        //Apply the surface to the screen
        apply_surface( y*30, x*30, stathmos, screen );
      }
      if (xarths[x][y]>1 && xarths[x][y]<8){
        FillRect(y*30,x*30,30,30,0x0);
        apply_surface( y*30, x*30, oxima[xarths[x][y]-2], screen );
      }
      if (xarths[x][y]==0){
        FillRect(y*30,x*30,30,30,0x0);
      }
    }
  }
  //Update the screen
  if( SDL_Flip( screen ) == -1 )
  {
      cout << "Error in SDL_Flip"<< endl;
  }
}

void functions::loadimages(){
  //Open the font
  font = TTF_OpenFont( "gfx/Ubuntu-L.ttf", 18 );
  //If there was an error in loading the font
  // if( font == NULL )
  // {
  //   return false;
  // }
  //Load the image
  fire = load_image( "gfx/fire_small.png" );
  //If there was a problem in loading the image
  if( fire == NULL )
  {
      cout << "Error in image load"<< endl;
  }
  stathmos = load_image( "gfx/stathmos_small.png" );
  oxima[2-2] = load_image( "gfx/aeroplano_small.png" );
  oxima[3-2] = load_image( "gfx/elikoptero_small2.png" );
  oxima[4-2] = load_image( "gfx/elikoptero_small.png" );
  oxima[5-2] = load_image( "gfx/amaxi_small.png" );
  oxima[6-2] = load_image( "gfx/fortigo_small.png" );
  oxima[7-2] = load_image( "gfx/fortigo2_small.png" );
  velos[0] = load_image( "gfx/velos7.png" );
  velos[1] = load_image( "gfx/velos0.png" );
  velos[2] = load_image( "gfx/velos1.png" );
  velos[3] = load_image( "gfx/velos2.png" );
  velos[4] = load_image( "gfx/velos3.png" );
  velos[5] = load_image( "gfx/velos4.png" );
  velos[6] = load_image( "gfx/velos5.png" );
  velos[7] = load_image( "gfx/velos6.png" );
}

void functions::info_oximatos(int x,int y){
  if (x<SIZ_X && y<SIZ_Y){
    switch(xarths[x][y]){
      case 2: case 3: case 4:
        for(i=0;i<oxhm;i++){
          cout << i << endl;
            if (thesi_x[i]==x && thesi_y[i]==y) {
              cout << i << endl;
              break;
            }
        }
        snprintf(buf, sizeof(buf), "Enaerio sto (%d,%d) Typou %s, %d xronon, Kausimo: %d, Nero: %d",
                         x ,y, en[i]->get_name().c_str(), en[i]->get_age(), en[i]->get_kausima(), en[i]->get_nero() );
        //cout << en[i]->nero<< endl;
        //Render the text
        message2 = TTF_RenderText_Solid( font, buf, textColor );
        //Apply the images to the screen
        FillRect(0,500,660,300,0x0);
        apply_surface( 0, 500, message2, screen );
        break;
      case 5: case 6: case 7:
        for(i=0;i<oxhm;i++){
          cout << i << endl;
            if (thesi_x[i]==x && thesi_y[i]==y) {
              cout << i << endl;
              break;
            }
        }
        snprintf(buf, sizeof(buf), "Edafous sto %d,%d Typou %s, %d xronon, Kausimo: %d, Nero: %d",
                         x ,y, ed[i]->get_name().c_str(), ed[i]->get_age(), ed[i]->get_kausima(), ed[i]->get_nero() );
        message2 = TTF_RenderText_Solid( font, buf, textColor );
        //Apply the images to the screen
        FillRect(0,500,660,300,0x0);
        apply_surface( 0, 500, message2, screen );
        break;
    }
  }
}

void functions::pros8iki_fotias(int x,int y){
  if (x<SIZ_X && y<SIZ_Y){
    if (xarths[x][y]==0){
      xarths[x][y]=1;
      snprintf(buf, sizeof(buf), "Prostethike fotia sto (%d,%d)", x ,y);
      //Render the text
      message1 = TTF_RenderText_Solid( font, buf, textColor );
      //Apply the images to the screen
      FillRect(0,480,660,20,0x0);
      apply_surface( 0, 480, message1, screen );
    }
    else cout << "Yparxei kati allo sto" << x <<"," <<y<<endl;
  }
}


void functions::svisimo_fotias(int x,int y){
  if (x<SIZ_X && y<SIZ_Y){
    if (xarths[x][y]==1){
      xarths[x][y]=0;
      snprintf(buf, sizeof(buf), "Svistike fotia sto (%d,%d)", x ,y);
      //Render the text
      message1 = TTF_RenderText_Solid( font, buf, textColor );
      //Apply the images to the screen
      FillRect(0,480,660,20,0x0);
      apply_surface( 0, 480, message1, screen );
    }
    else cout << "Yparxei kati allo sto" << x <<"," <<y<<endl;
  }
}

void functions::neo_oxima(int x,int y,int types){
        int X = x;
      int Y = y;
  if (X<SIZ_X && Y<SIZ_Y){
    // 
// 
//  
       for (i=0; i<oxhm; i++){
        if(ID[i]>=2 && ID[i]<=4){
          cout << "i:" <<i <<" get_name: "<<en[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
        if(ID[i]>4){
          cout << "i:" <<i <<" get_name: "<<ed[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
      }
// 
// 
// 
//

    if (xarths[X][Y]==0){
      int k=oxhm;
      oxhm++;
      if (types<5){
            en[k]=new enaeria(types);
            ID[k]=types;         
            thesi_x[k]=X;
            thesi_y[k]=Y;
            xarths[x][y]=en[k]->id;
            snprintf(buf, sizeof(buf), "Prostethike oxima sto (%d,%d) typou %s", X ,Y,en[k]->get_name().c_str());
      }
      else {
            ed[k]=new edafous(types);
            ID[k]=types;   
            thesi_x[k]=X;
            thesi_y[k]=Y;
            xarths[x][y]=ed[k]->id; 
            snprintf(buf, sizeof(buf), "Prostethike oxima sto (%d,%d) typou %s", X ,Y,ed[k]->get_name().c_str());
        }
      //Render the text
      message1 = TTF_RenderText_Solid( font, buf, textColor );
      //Apply the images to the screen
      FillRect(0,480,660,20,0x0);
      apply_surface( 0, 480, message1, screen );
      for (i=0; i<oxhm; i++){
        if(ID[i]>=2 && ID[i]<=4){
          cout << "i:" <<i <<" get_name: "<<en[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
        if(ID[i]>4){
          cout << "i:" <<i <<" get_name: "<<ed[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
      }
    }
  }
}
  

void functions::e3aplosi_foties(){
  for(i=0; i<oxhm; i++){
    if(ID[i]>=2 && ID[i]<=4 && en[i]->get_katastash()==0){
     en[i]->set_katastash(1);
    }
    else if(ID[i]>4 && ID[i]<=7 && ed[i]->get_katastash()==0){
     ed[i]->set_katastash(1);
    }
  }
  short int anemos = (rand() % 8);
  cout << "O anemos : " << anemos << endl; 
  //Emfanisi velous anemou
  apply_surface( 660, 0, velos[anemos], screen );
  if( SDL_Flip( screen ) == -1 )
  {
      cout << "Error in SDL_Flip"<< endl;
  }
  for(x=0 ; x<SIZ_X; x++){
    for(y=0; y<SIZ_Y; y++){
      if (xarths[x][y]==1){
        //cout <<"Vrika fotia sto "<< x << ","<< y << endl;
        switch (anemos){
          case 0:
              if ((x-1 >= 0) && (y-1 >= 0) && xarths[x-1][y-1]!=1 && xarths[x-1][y-1]!=99)
                xarths[x-1][y-1]=11;
              break;
          case 7:
              if ((y-1 >= 0) && xarths[x][y-1]!=1 && xarths[x][y-1]!=99) 
                xarths[x][y-1]=11;
              break;
          case 6:
              if ((x+1 < SIZ_X) && (y-1 >= 0) && xarths[x+1][y-1]!=1 && xarths[x+1][y-1]!=99) 
                xarths[x+1][y-1]=11;
              break;
          case 5:
              if ((x+1 < SIZ_X) && xarths[x+1][y]!=1 && xarths[x+1][y]!=99)
                xarths[x+1][y]=11;
              break;
          case 4:
              if ((x+1 < SIZ_X) && (y+1 < SIZ_Y) && xarths[x+1][y+1]!=1 && xarths[x+1][y+1]!=99)
                xarths[x+1][y+1]=11;
              break;
          case 3:
              if ((y+1 < SIZ_Y) && xarths[x][y+1]!=1 && xarths[x][y+1]!=99) 
                xarths[x][y+1]=11;
              break;
          case 2:
              if ((x-1 >= 0) && (y+1 < SIZ_Y) && xarths[x-1][y+1]!=1 && xarths[x-1][y+1]!=99)
                xarths[x-1][y+1]=11;
              break;
          case 1:
              if ((x-1 >= 0) && xarths[x-1][y]!=1 && xarths[x-1][y]!=99)
                xarths[x-1][y]=11;
              break;
        }
      }
    }
  }  
  for(x=0 ; x<SIZ_X ; x++){
    for(y=0 ; y<SIZ_Y ; y++){
      if (xarths[x][y]==11) xarths[x][y]=1;
    }
  }
}

void functions::game(){
  //sto parakatw kwdika ulopoieitai to sbhsimo ths fwtias
  //an dipla sto ekastwte oxhma uparxei fwtia 
  //sbhnetai apo to oxhma kai katanalwnetai ena poso tou nerou
  //to oxhma bebaia sbhnei fwtia an kai mono an h katastash tou einai energh dld 1.

  cout<<"svisimo_fotias"<<endl;
  for(i=0;i<oxhm;i++){
        a=thesi_x[i];
        b=thesi_y[i];
        cout <<xarths[a][b]<<endl;
        if(ID[i]<5 && en[i]->get_katastash()==1){
          cout<<"oxhma 1"<<endl;
          if( (a+1)<SIZ_X && (b-1)>=0 && xarths[a+1][b-1]==1){
            xarths[a+1][b-1]=0;
            en[i]->decr_nero();
          }
          else if((a+1)<SIZ_X && xarths[a+1][b]==1 ){
            xarths[a+1][b]=0;
            en[i]->decr_nero();
          }
          else if( (a+1)<SIZ_X && (b+1)<SIZ_Y && xarths[a+1][b+1]==1){
            xarths[a+1][b+1]=0;
            en[i]->decr_nero();
          }
          else if((b-1)>=0 && xarths[a][b-1]==1){
              xarths[a][b-1]=0;
            en[i]->decr_nero();
          }
          else if((b+1)<SIZ_Y &&xarths[a][b+1]==1 ){
            xarths[a][b+1]=0;
            en[i]->decr_nero();
          }
          else if((a-1)>=0 && (b-1)>=0 && xarths[a-1][b-1]==1){
            xarths[a-1][b-1]=0;
            en[i]->decr_nero();
          }
          else if((a-1)>=0 && xarths[a-1][b]==1 ){
            xarths[a-1][b]=0;
            en[i]->decr_nero();
          }
          else if((a-1)>=0 && (b+1)<SIZ_Y && xarths[a-1][b+1]==1 ){
            xarths[a-1][b+1]=0;
            en[i]->decr_nero();
          }
          SDL_Delay( 25 );
        }
        else if(ID[i]>4 && ed[i]->katastash==1){
          cout<<"oxhma 2"<<endl;
          if( (a+1)<SIZ_X && (b-1)>=0 && xarths[a+1][b-1]==1){
            xarths[a+1][b-1]=0;
            ed[i]->decr_nero();
          }
          else if((a+1)<SIZ_X && xarths[a+1][b]==1 ){
            xarths[a+1][b]=0;
            ed[i]->decr_nero();
          }
          else if( (a+1)<SIZ_X && (b+1)<SIZ_Y && xarths[a+1][b+1]==1){
            xarths[a+1][b+1]=0;
            ed[i]->decr_nero();
          }
          else if((b-1)>=0 && xarths[a][b-1]==1){
              xarths[a][b-1]=0;
            ed[i]->decr_nero();
          }
          else if((b+1)<SIZ_Y &&xarths[a][b+1]==1 ){
            xarths[a][b+1]=0;
            ed[i]->decr_nero();
          }
          else if((a-1)>=0 && (b-1)>=0 && xarths[a-1][b-1]==1){
            xarths[a-1][b-1]=0;
            ed[i]->decr_nero();
          }
          else if((a-1)>=0 && xarths[a-1][b]==1 ){
            xarths[a-1][b]=0;
            ed[i]->decr_nero();
          }
          else if((a-1)>=0 && (b+1)<SIZ_Y && xarths[a-1][b+1]==1 ){
            xarths[a-1][b+1]=0;
            ed[i]->decr_nero();
          }
          SDL_Delay( 25 );
        } 
        showimages(); 
  }
  //showxarths();

 cout<<"exw erthei kai sthn kinish"<<endl;
//kinisi oxhmatwn
//ta oxhmata kateuthhnontai pros tis fwties
//sugkekrimena elegxoun an uparxei paradipla tous fwtia k kateuthunontai pros auth
//prwta elegxoume an to koutaki sto opoio paei na kinhthei einai entos twn oriwn tou xarth
 //kathws epishs k an einai adeio h an einai to keli tou kentrou ths purosbestikhs
 //an ola ta parapanw plhrountai metakineitai to oxhma k meiwnontai ta kausima tou kata 
 //thn dedomenh katanalwsh kausimou
// 
// 
//  
       for (i=0; i<oxhm; i++){
        if(ID[i]>=2 && ID[i]<=4){
          cout << "i:" <<i <<" get_name: "<<en[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
        if(ID[i]>4){
          cout << "i:" <<i <<" get_name: "<<ed[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
      }
// 
// 
// 
// 
    for(i=0;i<oxhm;i++){
      cout<<"To oxima: "<<i<<endl;
      a=thesi_x[i];
      b=thesi_y[i];
      cout << "To a:"<<a<<" kai to b:"<<b<<endl;
      if((xarths[a+2][b-2]==1 || xarths[a+2][b-1]==1)
      && (a+2)<SIZ_X && (b-2)>=0 && (b-1)>=0 && (a+1)<SIZ_X
      && xarths[a+1][b-1]==0 && xarths[a+1][b-1]!=99){
            thesi_x[i]=thesi_x[i] +1;
            cout<<"H thesi_x einai tora: "<<thesi_x[i]<<endl;
            thesi_y[i]=thesi_y[i] -1;
          if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a+2][b]==1 || xarths[a+2][b+1]==1) && (a+2)<SIZ_X && (b+1)<SIZ_Y && (a+1)<SIZ_X && xarths[a+1][b]==0 && xarths[a+1][b]!=99){
        thesi_x[i]=thesi_x[i]+1;
        cout<<"H thesi_x einai tora: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i];
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a+2][b+2]==1 || xarths[a+1][b+2]==1) && (a+2)<SIZ_X && (b+2)<SIZ_Y && (a+1)<SIZ_X && (a+1)<SIZ_X && (b+1)<SIZ_Y && xarths[a+1][b+1]==0 && xarths[a+1][b+1]!=99){
        thesi_x[i]=thesi_x[i] +1;
        cout<<"460: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i] +1;
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a][b+2]==1 || xarths[a-1][b+2]==1) && (b+2)<SIZ_Y && (a-1)>=0 && (b+1)<SIZ_Y && xarths[a][b+1]==0 && xarths[a][b+1]!=99){
        thesi_x[i]=thesi_x[i];
        cout<<"483: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i] +1;
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a-2][b-2]==1 || xarths[a-2][b+1]==1) &&
       (a-2)>=0 && (b-2)>=0 && (b+1)<SIZ_Y && (a-1)>=0 && 
       xarths[a-1][b+1]==0 && xarths[a-1][b+1]!=99){
        thesi_x[i]=thesi_x[i] -1;
        cout<<"506: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i] +1;
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a-2][b]==1 || xarths[a-2][b-1]==1) && (a-2)>=0 && (b-1)>=0 && (a-1)>=0 && xarths[a-1][b]==0 && xarths[a-1][b]!=99){
        thesi_x[i]=thesi_x[i]-1;
        thesi_y[i]=thesi_y[i];
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
        cout<<"549: "<<endl;
      }
      else if((xarths[a-2][b-2]==1 || xarths[a-1][b-2]) && (a-2)>=0 && (a-1)>=0 && (b-2)>=0 && (b-1)>=0 && xarths[a-1][b-1]==0 && xarths[a-1][b-1]!=99){
        thesi_x[i]=thesi_x[i]-1;
        cout<<"552: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i]-1;
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else if((xarths[a][b-2]==1 || xarths[a+1][b-2]==1) && (b-2)>=0 && (a+1)<SIZ_X && (b-1)>=0 && xarths[a][b-1]==0 && xarths[a][b-1]!=99){
        thesi_x[i]=thesi_x[i];
        cout<<"575: "<<thesi_x[i]<<endl;
        thesi_y[i]=thesi_y[i] -1;
        if(ID[i]<5){
              if(en[i]->get_katastash()==1){
                en[i]->decr_kausima();
                xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
              }
          }
          else{
            if(ed[i]->get_katastash()==1){
              ed[i]->decr_kausima();
              xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
              if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                  xarths[a][b]=0;
                }
            }
          }
      }
      else{
        short int temp = (rand() % 8);
        cout<<"Xarths["<<a<<"]["<<b<<"]: "<<xarths[a][b]<<endl;
        switch (temp){
          case 0:
              if ((b-1 >= 0) && (a-1)>=0 && xarths[a-1][b-1]==0 && xarths[a-1][b-1]!=99){
                thesi_x[i]=thesi_x[i]-1;
                thesi_y[i]=thesi_y[i] -1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }
            }
              break;
          case 7:
              if ((b-1)>=0 && xarths[a][b-1]==0 ){       
                thesi_x[i]=thesi_x[i];
                thesi_y[i]=thesi_y[i] -1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                } 
            }            
              break;
          case 6:
              if ((a+1 < SIZ_X) && (b-1 >= 0) && xarths[a+1][b-1]==0 ){
            
                thesi_x[i]=thesi_x[i] + 1;
                cout<<"Seira 654: "<<endl;
                thesi_y[i]=thesi_y[i] -1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
              }
              break;
          case 5:
              if ((a+1 < SIZ_X) && xarths[a+1][b]==0){
                
                thesi_x[i]=thesi_x[i] + 1;
                thesi_y[i]=thesi_y[i];
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
            }
              break;
          case 4:
              if ((a+1 < SIZ_X) && (b+1 < SIZ_Y)  && xarths[a+1][b+1]==0){
                
                thesi_x[i]=thesi_x[i] + 1;
                thesi_y[i]=thesi_y[i] +1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
            }
              break;
          case 3:
              if ((b+1 < SIZ_Y)  && xarths[a][b+1]==0){
                
                thesi_x[i]=thesi_x[i];
                thesi_y[i]=thesi_y[i] +1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
            }
              break;
          case 2:
              if ((a-1 >= 0) && (b+1 < SIZ_Y) && xarths[a-1][b+1]==0){
                
                thesi_x[i]=thesi_x[i] - 1;
                cout<<"Hh thesi_x einai tora: "<<thesi_x[i]<<endl;
                thesi_y[i]=thesi_y[i] +1;
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
            }
              break;
          case 1:
              if ((a-1 >= 0) && xarths[a-1][b]==0){
              
                thesi_x[i]=thesi_x[i] - 1;
                cout<<"Hhh thesi_x einai tora: "<<thesi_x[i]<<endl;
                thesi_y[i]=thesi_y[i];
                if(ID[i]<5){
                  if(en[i]->get_katastash()==1){
                    en[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=en[i]->get_id();
                      if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                        xarths[a][b]=0;
                      }
                  }
                }
                else{
                  if(ed[i]->get_katastash()==1){
                    ed[i]->decr_kausima();
                    xarths[thesi_x[i]][thesi_y[i]]=ed[i]->get_id();
                    if(xarths[a][b]!=99){ //gia na mn allazei id to kentro
                      xarths[a][b]=0;
                    }
                  }
                }   
            }
              break;
        }

            }
      cout<< "Apo ("<<a<<","<<b<<") -> ("<< thesi_x[i]<<","<<thesi_y[i]<<")"<<endl;
      showimages();
      SDL_Delay( 25 );
    }
    cout<<"\tTELOS KINISIS"<<endl;
    // 
// 
//  
       for (i=0; i<oxhm; i++){
        if(ID[i]>=2 && ID[i]<=4){
          cout << "i:" <<i <<" get_name: "<<en[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
        if(ID[i]>4){
          cout << "i:" <<i <<" get_name: "<<ed[i]->get_name()<<" thesi_x: "<<thesi_x[i]<<" thesi_y: "<<thesi_y[i]<<endl;
        }
      }
// 
// 
// 
//
    //showxarths();
}

void functions::auxisi_hlikias(){
  for(i=0;i<oxhm;i++){
    cout << ID[i] << endl;
    if(ID[i]<5){
        en[i]->auxisi_hl();
        cout << "Hlikia:" << en[i]->get_age();
        if (en[i]->get_age()>50){
          en[i]->set_katastash(2);
          if (xarths[thesi_x[i]][thesi_y[i]]==en[i]->get_id()){
            xarths[thesi_x[i]][thesi_y[i]]=0;
          }
        }
    }    
    else{
        ed[i]->auxisi_hl();
        if (ed[i]->get_age()>50){
          ed[i]->set_katastash(2);
          if (xarths[thesi_x[i]][thesi_y[i]]==ed[i]->get_id()){
            xarths[thesi_x[i]][thesi_y[i]]=0;
          }
        }
    }

  }
}

void functions::check_katastash(){
  cout<<"Einai sto check_katastash"<<endl;
  for(i=0;i<oxhm;i++){
    cout << i << " apo "<< oxhm<< endl;
    a=thesi_x[i];
    b=thesi_y[i];
    if(xarths[a][b]==1){
          thesi_x[i]=SIZ_X-1;
          thesi_y[i]=SIZ_Y-1;
          if(ID[i]>=2 && ID[i]<=4){
            cout<<"to oxhma "<<i<<" kahke kai metaferthike sto kentro"<<endl;
            en[i]->set_katastash(0);
            
          }
          else{
            cout<<"to oxhma "<<i<<" kahke kai metaferthike sto kentro"<<endl;
            ed[i]->set_katastash(0);
            
          }
          xarths[a][b]=0;
          
    }    
    if(ID[i]>=2 && ID[i]<=4){
      if(en[i]->get_nero()==0 || en[i]->get_kausima()==0){
        thesi_x[i]=SIZ_X-1;
        thesi_y[i]=SIZ_Y-1;
        if(en[i]->get_id()==2){
          en[i]->set_nero(200);
          en[i]->set_kausima(300);
        }
        else if(en[i]->get_id()==3){
          en[i]->set_nero(3000);
          en[i]->set_kausima(4000);
        }
        else{
          en[i]->set_nero(500);
          en[i]->set_kausima(600);
        }
        cout<<"to "<<en[i]->get_name()<<"metaferthike sto kentro"<<endl;
        xarths[a][b]=0;
      }
    }
  if(ID[i]>=5 && ID[i]<=7){
    if(ed[i]->get_nero()==0 || ed[i]->get_kausima()==0){
      thesi_x[i]=SIZ_X-1;
      thesi_y[i]=SIZ_Y-1;
      if(ed[i]->get_id()==5){
          ed[i]->set_nero(80);
          ed[i]->set_kausima(70);
        }
        else if(ed[i]->get_id()==6){
          ed[i]->set_nero(100);
          ed[i]->set_kausima(75);
        }
        else{
          ed[i]->set_nero(100);
          ed[i]->set_kausima(80);
        }

      cout<<"to "<<ed[i]->get_name()<<"metaferthike sto kentro"<<endl;
      xarths[a][b]=0;
    }
   }
  }
}

bool functions::check_xarth(){
  int i=0;
  for(x=0 ; x<SIZ_X ; x++){
    for(y=0 ; y<SIZ_Y ; y++){
      if (xarths[x][y]==1) i++;
    }
  }
  if (i==(SIZ_Y*SIZ_X)-1) return true;
  else return false;
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Rectangle to hold the offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Φωτιές στην πόλη", NULL );
    SDL_Surface* icon = SDL_LoadBMP("gfx/fire.bmp");
    Uint32 colorkey = SDL_MapRGB(icon->format, 255, 255, 255);
    SDL_SetColorKey(icon, SDL_SRCCOLORKEY, colorkey);  
    SDL_WM_SetIcon(icon, NULL);
    //If everything initialized fine
    return true;
}