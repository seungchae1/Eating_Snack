#pragma once

class NewSprite : public Sprite
{
public:
	NewSprite():Sprite() {}
	NewSprite(String img, float sizeX, float sizeY, int posX, int posY)
		:Sprite()
	{
		t.loadFromFile(img);
		setTexture(t);
		setScale(sizeX, sizeY);
		setPosition(posX, posY);
	}
	void changeP(String img) {
		time_t start, finish;
		double duration=0;

		start = time(NULL);
		Texture newt;
		newt.loadFromFile(img);
		setTexture(newt);
		while (duration>3)
		{
			cout << duration << endl;
			finish = time(NULL);
			duration = (double)(finish - start);
		}
		setTexture(t);
	}
private:
	Texture t;
};