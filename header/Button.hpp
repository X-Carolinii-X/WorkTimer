#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Utilities.hpp"

enum class ButtonState : short unsigned
{
	BUTTON_IDLE = 0,
	BUTTON_HOVER,
	BUTTON_ACTIVE
};

class Button
{
public:
	// Constructors
	Button( float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor );

	// Destructor
	~Button();

	// Functions
	void update( const sf::Vector2f& mousePos );
	void render( sf::RenderTarget* target );

	// Accessors
	const bool isPressed() const;

private:
	// Variables
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	// Text colors
	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	// Button colors
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	// Button state
	ButtonState buttonState;
};

#endif