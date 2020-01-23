#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font";
	}

	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(25);


}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W pressed";
	}

	if (input->isKeyDown(sf::Keyboard::J))
	{
		if (input->isKeyDown(sf::Keyboard::K))
		{
			if (input->isKeyDown(sf::Keyboard::L))
			{
				input->setKeyUp(sf::Keyboard::J);
				input->setKeyUp(sf::Keyboard::K);
				input->setKeyUp(sf::Keyboard::L);
				std::cout << "This worked!";
			}
		}
	}
	
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	

}

// Update game objects
void Level::update()
{
	text.setString(std::to_string(input->getMouseX()) + "     " + std::to_string(input->getMouseY()));



}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
	window->draw(text);


}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}