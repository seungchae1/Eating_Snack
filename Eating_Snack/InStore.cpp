#include "main.h"
#include "store.h"
#include "play.h"
#include "sprite.h"


void InStore(RenderWindow* window)
{
	NewSprite candy = NewSprite("img/candy.png",1,1, 100, 250);
	NewSprite jelly = NewSprite("img/jelly.png",1,1, 550, 250);
	NewSprite honey = NewSprite("img/honey.png",1,1, 1050, 250);
	NewSprite board = NewSprite("img/board.png", 2.95f, 1.5f, 10, 250);
	NewSprite lv1 = NewSprite("img/lv1.png", 0.25f, 0.25f, 170, 210);
	NewSprite lv2 = NewSprite("img/lv2.png", 0.25f, 0.25f, 670, 210);
	NewSprite lv3 = NewSprite("img/lv3.png", 0.25f, 0.25f, 1170, 210);

	while (window->isOpen())
	{
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
			if (e.type == Event::MouseButtonPressed) {
				if (e.mouseButton.button == Mouse::Left)
				{
					if (e.mouseButton.x >= 160 && e.mouseButton.x <= 351 && e.mouseButton.y >= 310 && e.mouseButton.y <= 499) { Play(window, 1, clock() / CLOCKS_PER_SEC); }
					else if (e.mouseButton.x >= 560 && e.mouseButton.x <= 850 && e.mouseButton.y >= 318 && e.mouseButton.y <= 480) { Play(window, 2, clock() / CLOCKS_PER_SEC); }
					else if (e.mouseButton.x >= 1110 && e.mouseButton.x <= 1319 && e.mouseButton.y >= 290 && e.mouseButton.y <= 529) { Play(window, 3, clock() / CLOCKS_PER_SEC); }
				}
			}
		}
		window->clear(Color::White);
		window->draw(board);
		window->draw(candy);
		window->draw(jelly);
		window->draw(honey);
		window->draw(lv1);
		window->draw(lv2);
		window->draw(lv3);
		window->display();
	}
}