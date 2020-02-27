#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int main (int argc,char** argv)
{	
	
	
	int done=1;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	screen=SDL_SetVideoMode(1350,632,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("chargement d'image en SDL",NULL);
	
	SDL_Rect screen_rect;
	screen_rect.x=0;
	screen_rect.y=0;
	//screen_rect.w = 600;
	//screen_rect.h = 400;	
	
	//-------------------Forest

	SDL_Surface *background=NULL;
	background=IMG_Load("Background.png");
	
	SDL_Rect background_rect;
	background_rect.x = 0;
	background_rect.y = 0;
	//background_rect.w = 1350;
	//background_rect.h = 800;	
	//screen_rect.w = background->w;
	//screen_rect.h = background->h;

	/*//--------------------TomatoLogo

	SDL_Surface *tomato_logo=NULL;
	tomato_logo=IMG_Load("TomatoLogo.png");
	
	SDL_Rect tomato_logo_rect;
	tomato_logo_rect.x = 505;
	tomato_logo_rect.y = 10;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;*/

	//--------------------catchUp

	SDL_Surface *tomato_logo=NULL;
	tomato_logo=IMG_Load("TomatoLogo.png");
	
	SDL_Rect tomato_logo_rect;
	tomato_logo_rect.x = 505;
	tomato_logo_rect.y = 10;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;

	//--------------------Play

	SDL_Surface *play_button=NULL;
	play_button=IMG_Load("Play.png");
	
	SDL_Rect play_button_rect;
	play_button_rect.x = 505;
	play_button_rect.y = 372;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;

	//--------------------Settings

	SDL_Surface *settings_button=NULL;
	settings_button=IMG_Load("Settings.png");
	
	SDL_Rect settings_button_rect;
	settings_button_rect.x = 505;
	settings_button_rect.y = 452;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;
	
	//--------------------Toto

	SDL_Surface *tutorial_button=NULL;
	tutorial_button=IMG_Load("Tutorial.png");
	
	SDL_Rect tutorial_button_rect;
	tutorial_button_rect.x = 505;
	tutorial_button_rect.y = 532;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;

	//--------------------Credit

	SDL_Surface *credit_button=NULL;
	credit_button=IMG_Load("Credit.png");
	
	SDL_Rect credit_button_rect;
	credit_button_rect.x = 950;
	credit_button_rect.y = 535;
	//play_button_rect.w = 300;
	//play_button_rect.h = 800;
	
	//--------------------
	
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s\n",Mix_GetError());
	}
	Mix_Music *music; //construct mix_music_pointer
	music=Mix_LoadMUS("Background_music.mp3"); //Load the music
	Mix_PlayMusic(music, -1);//play music;
		
	while(done)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					done=0;
				break;
			}
		}
	SDL_BlitSurface(background,NULL,screen,&screen_rect);
	SDL_BlitSurface(tomato_logo,NULL,screen,&tomato_logo_rect);
	SDL_BlitSurface(credit_button,NULL,screen,&credit_button_rect);
	SDL_BlitSurface(play_button,NULL,screen,&play_button_rect);
	SDL_BlitSurface(settings_button,NULL,screen,&settings_button_rect);
	SDL_BlitSurface(tutorial_button,NULL,screen,&tutorial_button_rect);
	SDL_Flip(screen);
	}
	SDL_FreeSurface(background);
	SDL_FreeSurface(tomato_logo);
	SDL_FreeSurface(play_button);
	SDL_FreeSurface(settings_button);
	SDL_FreeSurface(tutorial_button);
	SDL_FreeSurface(credit_button);
	Mix_FreeMusic(music);
	Mix_CloseAudio();

	return 0;
}
