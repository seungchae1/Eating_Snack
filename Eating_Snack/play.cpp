#include "main.h"
#include "play.h"
#include "gameClear.h"
#include "gameOver.h"
#include "sprite.h"

void Play(RenderWindow* window, int l, clock_t c) {

	Text text;
	Font font;
	font.loadFromFile("resources/ITCKRIST.TTF");

	// 보여줄 문자열 세팅
	text.setString("200");

	text.setFont(font);

	// 문자 사이즈 세팅
	text.setCharacterSize(26);
	// 포인트과 아니라 픽셀 단위입니다!

	// 색 설정
	text.setFillColor(sf::Color::Black);

	// 텍스트 스타일 설정
	//text.setStyle(sf::Text::Bold);
	text.setPosition(1350, 10);

	NewSprite teacher = NewSprite("img/teacher.png", 0.8f, 0.8f, 650, 0);
	NewSprite character = NewSprite("img/img3.png", 0.2f, 0.2f, 650, 600);
	NewSprite character2 = NewSprite("img/img3.png", 0.2f, 0.2f, 650, 600);
	NewSprite table = NewSprite("img/img5.png", 0.2f, 0.2f, 650, 600);
	NewSprite Snack_box = NewSprite("img/snack_box.png", 0.3f, 0.5f, 10, 20);
	//과자 양
	int snack_size = 10 + (l * 3);

	NewSprite* snacks = new NewSprite[snack_size];

	for (int i = 0; i < snack_size; i++) {
		switch (l)
		{
			case 1: snacks[i] = *new NewSprite("img/candy.png", 0.15f, 0.15f, (10 + (i * 27)), 24); break;
			case 2: snacks[i] = *new NewSprite("img/jelly.png", 0.15f, 0.15f, (10 + (i * 27)), 24); break;
			case 3: snacks[i] = *new NewSprite("img/honey.png", 0.15f, 0.15f, (10 + (i * 27)), 24); break;
			default:
				break;
		}
	}

	//선생님 시선 
	VertexArray see(Triangles, 3);
	see[0].position = Vector2f(780, 370);
	see[1].position = Vector2f(640, 800);
	see[2].position = Vector2f(940, 800);

	see[0].color = Color::Yellow;
	see[1].color = Color::Yellow;
	see[2].color = Color::Yellow;

	bool seeTouch = false;
	int cnt = 0;
	int eat = 0;
	int t_posi = 640;
	double end = 200.0; //제한시간(초)
	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
			if (e.type == Event::KeyPressed)
			{
				if (e.key.code == Keyboard::Space) {
					eat++; // 먹는 회수 세기
					character.changeP("img/img4.png");

					if (eat % 3 == 0)snack_size--; //세번 누르면 과자 하나씩 -
					if (seeTouch) { // 시선이 닿아있을 때 먹으면 gameover
						Gameover(window);
					}
					if (snack_size <= 0)GameClear(window); // 과자를 다먹으면 gameclear
				}
				else {
					if(character.getImg()=="img/img4.png")character.changeP("img/img3.png");
				}
			}
		}
		if (character.getPosition().x >= 250) //캐릭터 움직임 제한
		{

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				character.move(-5, 0);
				table.move(-5, 0);
			}
		}
		if (character.getPosition().x <= 1000)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right)) //캐릭터 움직임 제한
			{
				character.move(5, 0);
				table.move(5, 0);
			}
		}

		clock_t start = clock() / CLOCKS_PER_SEC; //초단위 변환
		int time = (end - start + c);
		text.setString("time : " + to_string(time));
		if (time <= 0) { Gameover(window); }
		else if (time % 3 == 0) {
			cnt++; //한 번만 실행 시키기
			if (cnt == 1) {
				// 시드값을 얻기 위한 random_device 생성.
				random_device rd;

				// random_device 를 통해 난수 생성 엔진을 초기화 한다.
				mt19937 gen(rd());

				// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
				uniform_int_distribution<int> dis(400, 850);

				t_posi = (int)(dis(gen));
				see[0].position = Vector2f(780, 370); //꼭짓점
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
		window->draw(Snack_box);
		window->draw(text);
		for (int i = 0; i < snack_size; i++) window->draw(snacks[i]);
		window->display();

		seeTouch = false;
		for (int i = character.getPosition().x + 35; i <= character.getPosition().x + 245; i++) {
			if (i >= see[1].position.x && i <= see[2].position.x) { seeTouch = true; break; } // character의 x좌표가 see의 양끝 x좌표 사이에 있으면 seeTouch = true
		}
		//test
		//if(seeTouch) cout << "닿음" << endl;
	}
}