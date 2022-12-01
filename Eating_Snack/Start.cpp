#include "main.h"
#include "start.h"
#include "rule.h"
#include "mainScreen.h"
#include "sprite.h"


void Start(RenderWindow* window)
{
	NewSprite character= NewSprite("img/img2.png", 0.1f, 0.1f, ScreenSize::W / 2 - 60, 10);
	NewSprite title = NewSprite("img/title.png", 2.8f, 2.8f, 250, 140);
	NewSprite start_btn = NewSprite("img/way_btn.png", 2.5f, 2.5f, 450, ScreenSize::H - 200);
	NewSprite way_btn = NewSprite("img/start_btn.png", 2.5f, 2.5f, 810, ScreenSize::H - 200);

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