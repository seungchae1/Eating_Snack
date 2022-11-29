#include "main.h"
#include "start.h"
#include "rule.h"
#include "mainScreen.h"

void Start(RenderWindow* window)
{

	Texture t1;
	t1.loadFromFile("img/img2.png");
	Sprite character = Sprite(t1);
	character.setScale(0.1f, 0.1f);
	character.setPosition(ScreenSize::W / 2 - 60, 10);

	Texture t2;
	t2.loadFromFile("img/title.png");
	Sprite title = Sprite(t2);
	title.setScale(2.8f, 2.8f);
	title.setPosition(250, 140);

	Texture t3;
	t3.loadFromFile("img/way_btn.png");
	Sprite start_btn = Sprite(t3);
	start_btn.setScale(2.5f, 2.5f);
	start_btn.setPosition(450, ScreenSize::H - 200);

	Texture t4;
	t4.loadFromFile("img/start_btn.png");
	Sprite way_btn = Sprite(t4);
	way_btn.setScale(2.5f, 2.5f);
	way_btn.setPosition(810, ScreenSize::H - 200);

	while (window->isOpen())
	{
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
		}

		if (e.type == Event::MouseButtonPressed) {
			if (e.mouseButton.button == Mouse::Left)
			{
				if (e.mouseButton.x >= 449 && e.mouseButton.x <= 689 && e.mouseButton.y >= 701 && e.mouseButton.y <= 810) {
					RuleScreen(window);
				}
				if (e.mouseButton.x >= 809 && e.mouseButton.x <= 1049 && e.mouseButton.y >= 701 && e.mouseButton.y <= 810) {
					MainScreen(window);
				}
			}
		}

		window->clear(Color::White);
		window->draw(character);
		window->draw(title);
		window->draw(start_btn);
		window->draw(way_btn);
		window->display();
	}
}