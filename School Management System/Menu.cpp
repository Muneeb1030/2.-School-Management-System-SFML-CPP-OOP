#include"AllLibIncluded.h"
Menu::Menu(float Width, float Height)
{
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	Thunder.loadFromFile("Fonts/Thunder.ttf");

	MainMenuImage.loadFromFile("Backgrounds/MainMenu.jpg");

	MenuBackgrounImage.setSize(Vector2f(1000, 650));
	MenuBackgrounImage.setTexture(&MainMenuImage);

	MenuHeading.setFont(Algerian);
	MenuHeading.setString("Main Menu");
	MenuHeading.setFillColor(Color(105, 105, 105));
	MenuHeading.setCharacterSize(80);
	MenuHeading.setOutlineThickness(3);
	MenuHeading.setOutlineColor(Color(255, 255, 255));
	MenuHeading.setPosition(Vector2f(30, 50));

	MenubackgroundShade.setSize(Vector2f(250, 400));
	MenubackgroundShade.setFillColor(Color(255, 255, 255, 100));
	MenubackgroundShade.setOutlineThickness(4);
	MenubackgroundShade.setOutlineColor(Color(105, 105, 105, 200));
	MenubackgroundShade.setPosition(Vector2f(Width / 9, Height / 4));

	MainOptionsProvided[0].setFont(Thunder);
	MainOptionsProvided[0].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[0].setString("Admin");
	MainOptionsProvided[0].setCharacterSize(70);
	MainOptionsProvided[0].setOutlineColor(Color::White);
	MainOptionsProvided[0].setOutlineThickness(3);
	MainOptionsProvided[0].setPosition(Vector2f(Width / 7.5, Height / 3.75));

	MainOptionsProvided[1].setFont(MilkShake);
	MainOptionsProvided[1].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[1].setString("Teacher");
	MainOptionsProvided[1].setCharacterSize(70);
	MainOptionsProvided[1].setOutlineColor(Color::White);
	MainOptionsProvided[1].setOutlineThickness(3);
	MainOptionsProvided[1].setPosition(Vector2f(Width / 7.5, Height / 2.40));

	MainOptionsProvided[2].setFont(Thunder);
	MainOptionsProvided[2].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[2].setString("Student");
	MainOptionsProvided[2].setCharacterSize(70);
	MainOptionsProvided[2].setOutlineColor(Color::White);
	MainOptionsProvided[2].setOutlineThickness(3);
	MainOptionsProvided[2].setPosition(Vector2f(Width / 7.9, Height / 1.80));

	MainOptionsProvided[3].setFont(MilkShake);
	MainOptionsProvided[3].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[3].setString("Exit");
	MainOptionsProvided[3].setCharacterSize(70);
	MainOptionsProvided[3].setOutlineColor(Color::White);
	MainOptionsProvided[3].setOutlineThickness(3);
	MainOptionsProvided[3].setPosition(Vector2f(Width / 5.9, Height / 1.40));

	MenuOptionSelected = 0;
}
void Menu::Draw(RenderWindow& Windows)
{
	Windows.draw(MenuBackgrounImage);
	Windows.draw(MenubackgroundShade);
	Windows.draw(MenuHeading);
	for (int i = 0; i < MAxMenuOptions; i++)
	{
		Windows.draw(MainOptionsProvided[i]);
	}
}
void Menu::MoveUp()
{
	if (MenuOptionSelected - 1 >= 0)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
		MenuOptionSelected--;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color::Black);
	}
}
void Menu::MoveDown()
{
	if (MenuOptionSelected + 1 < MAxMenuOptions)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
		MenuOptionSelected++;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color::Black);
	}
}
int Menu::get_SelectedOption()
{
	return MenuOptionSelected;
}