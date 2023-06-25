#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
const int MAxMenuOptions = 4;
class Menu
{
private:
	int MenuOptionSelected;
	Text MenuHeading;
	RectangleShape MenuBackgrounImage, MenubackgroundShade;
	Texture MainMenuImage;
	Text MainOptionsProvided[MAxMenuOptions];
	//------------>> Objects of Fonts......
	Font Algerian, MilkShake, Thunder;
public:
	Menu(float Width, float Height);
	void MoveUp();
	void MoveDown();
	int get_SelectedOption();
	void Draw(RenderWindow& Windows);
	~Menu() {}
};