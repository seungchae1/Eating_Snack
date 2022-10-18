#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>

using namespace sf;
using namespace std;

#define w 1500
#define h 900

void Start( RenderWindow* window);
void MainScreen(RenderWindow* window);
void RuleScreen(RenderWindow* window);
void InStore(RenderWindow* window);

int main()
{
	RenderWindow window(VideoMode(w, h), "Eating Snacks!!");
	window.setFramerateLimit(60);

	Start(&window);

}

void Start( RenderWindow * window)
{

	Texture t1;
	t1.loadFromFile("img/img2.png");
	Sprite character = Sprite(t1);
	character.setScale(0.1f, 0.1f);
	character.setPosition(w / 2 - 60, 10);

	Texture t2;
	t2.loadFromFile("img/title.png");
	Sprite title = Sprite(t2);
	title.setScale(2.8f, 2.8f);
	title.setPosition(250, 140);

	Texture t3;
	t3.loadFromFile("img/way_btn.png");
	Sprite start_btn = Sprite(t3);
	start_btn.setScale(2.5f, 2.5f);
	start_btn.setPosition(450, h - 200);

	Texture t4;
	t4.loadFromFile("img/start_btn.png");
	Sprite way_btn = Sprite(t4);
	way_btn.setScale(2.5f, 2.5f);
	way_btn.setPosition(810, h - 200);

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

void MainScreen(RenderWindow* window)
{
	int c;
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

	bool text_box = true;

	while (window->isOpen())
	{
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			character.move(-4,0);
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
		if(text_box)window->draw(textBox);
		if (e.type == Event::MouseButtonPressed) {
			if (e.mouseButton.button == Mouse::Left) text_box = false;
		}
		window->draw(character);
		window->display();
	}
}

void InStore(RenderWindow * window) 
{
	while (window->isOpen())
	{
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

void RuleScreen(RenderWindow* window)
{
	/*
	Text text;
	Font font;
	font.loadFromFile("‪C:\Windows\Fonts\gulim.ttc");

	// 보여줄 문자열 세팅
	text.setString("안녕");

	text.setFont(font);

	// 문자 사이즈 세팅
	text.setCharacterSize(24);
	// 포인트과 아니라 픽셀 단위입니다!

	// 색 설정
	text.setFillColor(sf::Color::Red);

	// 텍스트 스타일 설정 
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	*/
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
	start_btn.setPosition(620, h - 150);

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
		//window->draw(text);
		window->display();
	}
}