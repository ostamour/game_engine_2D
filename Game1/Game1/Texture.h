#ifndef TEXTURE
#define TEXTURE

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "Window.h"

using namespace std;

SDL_Texture* loadTexture(string path);

/*Constant variables*/
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

//The dimensions of the dot
static const int DOT_WIDTH = 20;
static const int DOT_HEIGHT = 20;

//The maximum velocity of the dot
static const int DOT_VEL = 10;

class Texture 
{
public:
	//Default constructor
	Texture();

	Texture(string path);

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile(Window* window);

	//Takes the key presses and adjusts the texture's velocity
	void handleEvent(SDL_Event& e);

	//Deallocates texture
	void free();

	//Shows the texture on the window
	void render(Window* window);
	
	//Moves the texture
	void move(float timeStep);

private:
	
	//The hardware texture
	SDL_Texture* texture_;

	//Position of the texture on the x and y axis 
	float posX_, posY_;
	//Velocity of the texture on the x and y axis
	float velX_, velY_;

	//Image dimensions
	int width_;
	int height_;

	//Image path
	string path_;
};


#endif
