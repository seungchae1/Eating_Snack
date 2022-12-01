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
private:
	Texture t;
};