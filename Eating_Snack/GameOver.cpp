#include "main.h"
#include "gameOver.h"
#include "sprite.h"
#include "store.h"

void Gameover(RenderWindow* window) {

	NewSprite title = NewSprite("img/over_title.png", 1.8, 1.8, 300, 50);
	NewSprite btn = NewSprite("img/restart.png", 0.6, 0.6, 600, ScreenSize::H - 200);
	
	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
		}

		if (e.type == Event::MouseButtonPressed) {
			if (e.mouseButton.button == Mouse::Left)
			{
				if (e.mouseButton.x >= 619 && e.mouseButton.x <= 858 && e.mouseButton.y >= 700 && e.mouseButton.y <= 811) {
					InStore(window);
				}
			}
		}
		window->clear(Color::White);
		window->draw(title);
		window->draw(btn);
		window->display();
	}
}