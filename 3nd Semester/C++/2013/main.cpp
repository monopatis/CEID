#include "functions.h"

functions f;
SDL_Event event;
int x, y;
int main(){
	//Make sure the program waits for a quit
    bool quit = false;
	cout<<"KALOSHL8ATE"<<endl;
	cout<<"Arxikopoiisi xarti"<<endl;
	f.arxikop_xarth();
	//Initialize
    if( init() == false )
    {
        return 1;
    }
    cout<<"Emfanisi xarti"<<endl;
    f.showxarths();
    f.loadimages();
    f.showimages();
	//While the user hasn't quit
    while( quit == false )
    {
		//While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
			switch (event.type) {
            case SDL_MOUSEMOTION:
                // printf("Mouse moved by %d,%d to (%d,%d)\n", 
                //        event.motion.xrel, event.motion.yrel,
                //        event.motion.x, event.motion.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("Mouse button %d pressed at (%d,%d), \n",
                       event.button.button, event.button.x/30, event.button.y/30);
                f.info_oximatos(event.button.y/30,event.button.x/30);
                f.showxarths();
                f.showimages();
                break;
            //If a key was pressed
            case SDL_KEYDOWN:
                printf("The %s key was pressed! (%d) \n",
                       SDL_GetKeyName(event.key.keysym.sym),event.key.keysym.sym);
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_DOWN:
                        if(f.check_xarth()){
                            cout<<"Yparxei pantou fotia!"<<endl;
                            quit = true;
                        }
                        else{
                            cout<<"E3aplosi fotiwn!"<<endl;
                            f.e3aplosi_foties();
                            f.check_katastash();
                            f.game();
                            f.check_katastash();
                            f.auxisi_hlikias();
                            cout<<"Emfanisi xarti"<<endl;
                            f.showxarths();
                            f.showimages();
                        }
                        break;    
                    case SDLK_f:
                        //!!!!!Prosoxi x,y anapoda!!
                        SDL_GetMouseState(&x, &y);
                        f.pros8iki_fotias(y/30,x/30);
                        f.showxarths();
                        f.showimages();
                        break;
                    case SDLK_d:
                        //!!!!!Prosoxi x,y anapoda!!
                        SDL_GetMouseState(&x, &y);
                        f.svisimo_fotias(y/30,x/30);
                        f.showxarths();
                        f.showimages();
                        break;
                    case SDLK_2: case SDLK_3: \
                    case SDLK_4: case SDLK_5: \
                    case SDLK_6: case SDLK_7:
                        SDL_GetMouseState(&x, &y);
                        f.neo_oxima(y/30,x/30, event.key.keysym.sym-48);
                        f.showxarths();
                        f.showimages();
                        break;
                }
                break;
            case SDL_QUIT:
                quit = true;
                break;
        	}
			//getchar();
			//Wait 0.5 seconds
	    	//SDL_Delay( 500 );
	    }
	}
}