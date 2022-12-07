#pragma once

class NewSprite : public Sprite
{
public:
	NewSprite():Sprite() {}
	NewSprite(String img, float sizeX, float sizeY, int posX, int posY)
		:Sprite(), thisImg(img)
	{
		t.loadFromFile(img);
		setTexture(t);
		setScale(sizeX, sizeY);
		setPosition(posX, posY);
	}
	void changeP(String img) {
		thisImg = img;
		t.loadFromFile(img);
		setTexture(t); 
	}
	String getImg() {
		return thisImg;
	}
private:
	Texture t;
	String thisImg;
};