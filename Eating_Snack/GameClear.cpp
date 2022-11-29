#include "main.h"
#include "gameClear.h"

void GameClear(RenderWindow* window) {

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