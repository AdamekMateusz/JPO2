#include "Color_Menu.h"
#include <SFML/Graphics.hpp>

Color_Menu::Color_Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//hand error

	}
	colors[0].setFont(font);
	colors[0].setFillColor(sf::Color::Red);
	colors[0].setString("BLUE");
	colors[0].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 1, height /2));
	
	colors[1].setFont(font);
	colors[1].setFillColor(sf::Color::White);
	colors[1].setString("YELLOW");
	colors[1].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 2, height / 2));	
	colors[2].setFont(font);
	colors[2].setFillColor(sf::Color::White);
	colors[2].setString("GREEN");
	colors[2].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1) * 3, height /2 ));

	colors[3].setFont(font);
	colors[3].setFillColor(sf::Color::White);
	colors[3].setString("BACK");
	colors[3].setPosition(sf::Vector2f(50, 550));

	


	selectedItemIndex = 0;
}

Color_Menu::~Color_Menu()
{

}

void Color_Menu::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		target.draw(this->colors[i], state);
	}
}



void Color_Menu::MoveLeft() {
	if (selectedItemIndex - 1 >= 0) {

		colors[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		colors[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}

void Color_Menu::MoveRight() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		colors[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		colors[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

