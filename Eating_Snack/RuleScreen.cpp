#include "main.h"
#include "rule.h"
#include "mainScreen.h"

void RuleScreen(RenderWindow* window)
{
	Text text;
	Font font;
	font.loadFromFile("resources/ITCKRIST.TTF");

	// ������ ���ڿ� ����
	text.setString("1 . Go to the canteen and choose a snack. (Select Level)\n\n\n 2 . You can eat snacks by pressing the space bar.\n\n\n 3 . If you can't eat all the snacks during class or if you get caught by the teacher, game over");

	text.setFont(font);

	// ���� ������ ����
	text.setCharacterSize(26);
	// ����Ʈ�� �ƴ϶� �ȼ� �����Դϴ�!

	// �� ����
	text.setFillColor(sf::Color::Black);

	// �ؽ�Ʈ ��Ÿ�� ����
	//text.setStyle(sf::Text::Bold);
	text.setPosition(180, 350);

	Texture t1;
	t1.loadFromFile("img/title.png");
	Sprite title = Sprite(t1);
	title.setScale(1, 1);
	title.setPosition(550, 10);

	Texture t2;
	t2.loadFromFile("img/text1.png");
	Sprite text1 = Sprite(t2);
	text1.setScale(0.5f, 0.5f);
	text1.setPosition(490, 230);

	Texture t4;
	t4.loadFromFile("img/start_btn.png");
	Sprite start_btn = Sprite(t4);
	start_btn.setScale(2.5f, 2.5f);
	start_btn.setPosition(620, ScreenSize::H - 150);

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
				if (e.mouseButton.x >= 619 && e.mouseButton.x <= 858 && e.mouseButton.y >= 750 && e.mouseButton.y <= 861) {
					MainScreen(window);
				}
			}
		}
		window->clear(Color::White);
		window->draw(title);
		window->draw(text1);
		window->draw(start_btn);
		window->draw(text);
		window->display();
	}
}