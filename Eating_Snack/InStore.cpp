#include "main.h"
#include "store.h"
#include "play.h"


void InStore(RenderWindow* window)
{
	Texture t1;
	t1.loadFromFile("img/candy.png");
	Sprite candy = Sprite(t1);
	candy.setPosition(100, 250);

	Texture t2;
	t2.loadFromFile("img/jelly.png");
	Sprite jelly = Sprite(t2);
	jelly.setPosition(550, 250);

	Texture t3;
	t3.loadFromFile("img/honey.png");
	Sprite honey = Sprite(t3);
	honey.setPosition(1050, 250);

	Texture t4;
	t4.loadFromFile("img/board.png");
	Sprite board = Sprite(t4);
	board.setScale(2.95f, 1.5f);
	board.setPosition(10, 250);

	Texture t5;
	t5.loadFromFile("img/lv1_2.png");
	Sprite lv1 = Sprite(t5);
	lv1.setScale(0.25f, 0.25f);
	lv1.setPosition(170, 210);

	Texture t6;
	t6.loadFromFile("img/lv2.png");
	Sprite lv2 = Sprite(t6);
	lv2.setScale(0.25f, 0.25f);
	lv2.setPosition(670, 210);

	Texture t7;
	t7.loadFromFile("img/lv3.png");
	Sprite lv3 = Sprite(t7);
	lv3.setScale(0.25f, 0.25f);
	lv3.setPosition(1170, 210);

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