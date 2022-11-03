#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <random>

using namespace sf;
using namespace std;

//#define => enum
enum ScreenSize {
	W = 1500,
	H = 900
};

void Start( RenderWindow* window);
void MainScreen(RenderWindow* window);
void RuleScreen(RenderWindow* window);
void InStore(RenderWindow* window);
void Play(RenderWindow* window, int l);
void Gameover(RenderWindow* window);

int main()
{
	RenderWindow window(VideoMode(ScreenSize::W, ScreenSize::H), "Eating Snacks!!");
	window.setFramerateLimit(60);

	Start(&window);

}

void Start( RenderWindow * window)
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
		//window->draw(text);
		window->display();
	}
}
void MainScreen(RenderWindow* window)
{
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
					if (e.mouseButton.x >= 160 && e.mouseButton.x <= 351 && e.mouseButton.y >= 310 && e.mouseButton.y <= 499) { Play(window, 1); }
					else if (e.mouseButton.x >= 560 && e.mouseButton.x <= 850 && e.mouseButton.y >= 318 && e.mouseButton.y <= 480) { Play(window, 1); }
					else if (e.mouseButton.x >= 1110 && e.mouseButton.x <= 1319 && e.mouseButton.y >= 290 && e.mouseButton.y <= 529) { Play(window, 1);}
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

void Play(RenderWindow * window, int l) {
	Texture t1;
	t1.loadFromFile("img/teacher.png");
	Sprite teacher = Sprite(t1);
	teacher.setPosition(650, 0);
	teacher.setScale(0.8f, 0.8f);

	Texture t2;
	t2.loadFromFile("img/img3.png");
	Sprite character = Sprite(t2);
	character.setScale(0.2f, 0.2f);
	character.setPosition(650, 600);

	Texture t3;
	t3.loadFromFile("img/img5.png");
	Sprite table = Sprite(t3);
	table.setScale(0.2f, 0.2f);
	table.setPosition(650,600);

	Texture t4;
	t4.loadFromFile("img/snack_box.png");
	Sprite Snacks = Sprite(t4);
	Snacks.setScale(0.3f, 0.5f);
	Snacks.setPosition(10,20);

	VertexArray see(Triangles, 3);
	see[0].position = Vector2f(780,370);
	see[1].position = Vector2f(640,800);
	see[2].position = Vector2f(940,800);

	see[0].color = Color::Yellow;
	see[1].color = Color::Yellow;
	see[2].color = Color::Yellow;
	
	bool seeTouch;
	int cnt=0;
	int t_posi = 640;
	double end = 200.0;
	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			character.move(-5, 0);
			table.move(-5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			character.move(5, 0);
			table.move(5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			character.move(0, -5);
			table.move(0, -5);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			character.move(0, 5);
			table.move(0, 5);
		}

		clock_t start = clock() / CLOCKS_PER_SEC; //초단위 변환
		int time = (end-start);
		if (time <= 0) { Gameover(window); }
		else if (time % 3 == 0) {
			cnt++;
			if (cnt == 1) {
				// 시드값을 얻기 위한 random_device 생성.
				random_device rd;

				// random_device 를 통해 난수 생성 엔진을 초기화 한다.
				mt19937 gen(rd());

				// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
				uniform_int_distribution<int> dis(400, 1000);

				t_posi = (int)(dis(gen));
				see[0].position = Vector2f(780, 370);
				see[1].position = Vector2f(t_posi, 800);
				see[2].position = Vector2f(t_posi + 230, 800);
			}
		}
		else cnt = 0;

		window->clear(Color::White);
		window->draw(see);
		window->draw(teacher);
		window->draw(table);
		window->draw(character);
		window->draw(Snacks);
		window->display();

		seeTouch = false;
		for(int i=character.getPosition().x+35; i<=character.getPosition().x+245; i++){
			if (i >= see[1].position.x && i <= see[2].position.x) { seeTouch = true; break; }
		}
		//tsest
		if(seeTouch) cout << "닿음" << endl;
	}
}
void Gameover(RenderWindow * window) {

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