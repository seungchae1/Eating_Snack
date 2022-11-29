#include "main.h"
#include "gameOver.h"

void Gameover(RenderWindow* window) {

	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
		}

		window->clear(Color::White);
		window->display();
	}
}