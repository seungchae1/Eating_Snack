#include "main.h"
#include "rule.h"
#include "mainScreen.h"
#include "sprite.h"

void RuleScreen(RenderWindow* window)
{
	Text text;
	Font font;
	font.loadFromFile("resources/ITCKRIST.TTF");

	// 보여줄 문자열 세팅
	text.setString("1 . Go to the canteen and choose a snack. (Select Level)\n\n\n 2 . You can eat snacks by pressing the space bar.\n\n\n 3 . If you can't eat all the snacks during class or if you get caught by the teacher, game over");

	text.setFont(font);

	// 문자 사이즈 세팅
	text.setCharacterSize(26);
	// 포인트과 아니라 픽셀 단위입니다!

	// 색 설정
	text.setFillColor(sf::Color::Black);

	// 텍스트 스타일 설정
	//text.setStyle(sf::Text::Bold);
	text.setPosition(180, 350);

	NewSprite title = NewSprite("img/title.png", 1, 1, 550, 10);
	NewSprite text1 = NewSprite("img/text1.png", 0.5f, 0.5f, 490, 230);
	NewSprite start_btn = NewSprite("img/start_btn.png", 2.5f, 2.5f, 620, ScreenSize::H - 150);

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