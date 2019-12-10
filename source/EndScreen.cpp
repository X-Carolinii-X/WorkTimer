#include "../header/EndScreen.hpp"

EndScreen::EndScreen() :    endText_( sf::Text() ),
                            font_( sf::Font() ), fontSize_( 0 ),
                            event_( sf::Event() ), running_( true )
{
	setFont();
    setFontSize();
    setText();
	setTextPosition();
}

EndScreen::~EndScreen()
{

}

void EndScreen::setFont()
{
    if( !font_.loadFromFile( "resource/fonts/Akronim-Regular.ttf" ) )
    {
        std::cout << "Nie udalo sie wczytac czcionki...";
        Logger::getLogger().write( Logger::ERROR, "Czcionka nie została ustawiona" );
    }
}

void EndScreen::setFontSize( int fontSize )
{
    fontSize_ = fontSize;
}

int EndScreen::getFontSize()
{
	return fontSize_;
}

void EndScreen::setText()
{
    endText_.setFont( font_ );
    endText_.setCharacterSize( getFontSize() );
    endText_.setFillColor( sf::Color::Red );
    endText_.setStyle( sf::Text::Bold );
	endText_.setString( Utilities::endText );
}

void EndScreen::setTextPosition()
{
    float positionX = Utilities::width * 0.5 - endText_.getGlobalBounds().width * 0.5;
    float positionY = Utilities::height * 0.5 - endText_.getGlobalBounds().height;
    endText_.setPosition( sf::Vector2f( positionX, positionY ) );
}

int EndScreen::run( sf::RenderWindow &app )
{
	while( running_ )
    {
        while( app.pollEvent( event_ ) )
        {
            switch( event_.type )
            {
                case sf::Event::Closed:
                {
                    app.close();
                    return -1;
                    break;
                }
                default:
                {
                    Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    break;
                }
            }
        }
        app.clear();
        app.draw( endText_ );
        app.display();
		Utilities::sleep(2500);
		app.close();
        return -1;
    }
    return -1;
}