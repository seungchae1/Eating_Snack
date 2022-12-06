#include "main.h"
#include "start.h"

int main()
{
	RenderWindow window(VideoMode(ScreenSize::W, ScreenSize::H), "Eating Snacks!!");
	window.setFramerateLimit(60);
	Start(&window);

}