#include "main.h"
#include "mainScreen.h"
#include "store.h"

void MainScreen(RenderWindow* window)
{

	Text text;
	Text text2;
	Font font;
	font.loadFromFile("resources/ITCKRIST.TTF");

	// 보여줄 문자열 세팅
	text.setString("Go to the canteen and choose a snack.");
	text2.setString("Please use the rudder key.");

	text.setFont(font);
	text2.setFont(font);

	// 문자 사이즈 세팅
	text.setCharacterSize(26);
	text2.setCharacterSize(26);
	// 포인트과 아니라 픽셀 단위입니다!

	// 색 설정
	text.setFillColor(sf::Color::Black);
	text2.setFillColor(sf::Color::Black);

	// 텍스트 스타일 설정
	//text.setStyle(sf::Text::Bold);
	text.setPosition(200, 700);
	text2.setPosition(200, 700);

	Texture t1;
	t1.loadFromFile("img/img2.png");
	Sprite character = Sprite(t1);
	character.setScale(0.12f, 0.12f);
	character.setPosition(650, 350);

	Texture t2;
	t2.loadFromFile("img/text_box.png");
	Sprite textBox = Sprite(t2);
	textBox.setScale(2.4f, 1.7f);
	textBox.setPosition(25, 610);

	Texture t3;
	t3.loadFromFile("img/store.png");
	Sprite store = Sprite(t3);
	store.setScale(0.5f, 0.5f);
	store.setPosition(950, -120);

	int click_cnt = 0;
	while (window->isOpen())
	{
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}

			if (e.type == Event::KeyPressed)
			{
				if (e.key.code == Keyboard::Space) {
					click_cnt++;
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			character.move(-4, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			character.move(4, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			character.move(0, -4);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			character.move(0, 4);
		}
		if (character.getPosition().x >= 905 && character.getPosition().y <= 30) InStore(window);

		window->clear(Color::White);
		window->draw(store);
		if (click_cnt == 0) {
			window->draw(textBox);
			window->draw(text);
		}
		if (click_cnt == 1) {
			window->draw(textBox);
			window->draw(text2);
		}
		window->draw(character);
		window->display();
	}
}