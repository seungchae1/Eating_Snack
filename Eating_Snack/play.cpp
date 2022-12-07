#include "main.h"
#include "play.h"
#include "gameClear.h"
#include "gameOver.h"
#include "sprite.h"

void Play(RenderWindow* window, int l, clock_t c) {

	Text text;
	Font font;
	font.loadFromFile("resources/ITCKRIST.TTF");

	// ������ ���ڿ� ����
	text.setString("200");

	text.setFont(font);

	// ���� ������ ����
	text.setCharacterSize(26);
	// ����Ʈ�� �ƴ϶� �ȼ� �����Դϴ�!

	// �� ����
	text.setFillColor(sf::Color::Black);

	// �ؽ�Ʈ ��Ÿ�� ����
	//text.setStyle(sf::Text::Bold);
	text.setPosition(1350, 10);

	NewSprite teacher = NewSprite("img/teacher.png", 0.8f, 0.8f, 650, 0);
	NewSprite character = NewSprite("img/img3.png", 0.2f, 0.2f, 650, 600);
	NewSprite character2 = NewSprite("img/img3.png", 0.2f, 0.2f, 650, 600);
	NewSprite table = NewSprite("img/img5.png", 0.2f, 0.2f, 650, 600);
	NewSprite Snack_box = NewSprite("img/snack_box.png", 0.3f, 0.5f, 10, 20);
	//���� ��
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

	//������ �ü� 
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
	double end = 200.0; //���ѽð�(��)
	while (window->isOpen()) {
		Event e;
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) {
				window->close();
			}
			if (e.type == Event::KeyPressed)
			{
				if (e.key.code == Keyboard::Space) {
					eat++; // �Դ� ȸ�� ����
					character.changeP("img/img4.png");

					if (eat % 3 == 0)snack_size--; //���� ������ ���� �ϳ��� -
					if (seeTouch) { // �ü��� ������� �� ������ gameover
						Gameover(window);
					}
					if (snack_size <= 0)GameClear(window); // ���ڸ� �ٸ����� gameclear
				}
				else {
					if(character.getImg()=="img/img4.png")character.changeP("img/img3.png");
				}
			}
		}
		if (character.getPosition().x >= 250) //ĳ���� ������ ����
		{

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				character.move(-5, 0);
				table.move(-5, 0);
			}
		}
		if (character.getPosition().x <= 1000)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right)) //ĳ���� ������ ����
			{
				character.move(5, 0);
				table.move(5, 0);
			}
		}

		clock_t start = clock() / CLOCKS_PER_SEC; //�ʴ��� ��ȯ
		int time = (end - start + c);
		text.setString("time : " + to_string(time));
		if (time <= 0) { Gameover(window); }
		else if (time % 3 == 0) {
			cnt++; //�� ���� ���� ��Ű��
			if (cnt == 1) {
				// �õ尪�� ��� ���� random_device ����.
				random_device rd;

				// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
				mt19937 gen(rd());

				// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
				uniform_int_distribution<int> dis(400, 850);

				t_posi = (int)(dis(gen));
				see[0].position = Vector2f(780, 370); //������
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
			if (i >= see[1].position.x && i <= see[2].position.x) { seeTouch = true; break; } // character�� x��ǥ�� see�� �糡 x��ǥ ���̿� ������ seeTouch = true
		}
		//test
		//if(seeTouch) cout << "����" << endl;
	}
}