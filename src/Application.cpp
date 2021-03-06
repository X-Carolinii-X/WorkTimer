#include "Application.hpp"
#include "SplashState.hpp"

#include <iostream>
#include <fstream>

// Init functions
void Application::initWindow()
{
	// Create a SFML window using basic options from a config.ini file.
	std::ifstream configFile{ "config/config.ini" };

	// Set default values
	std::string title = "None";
	sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
	unsigned framerateLimit = 120;
	bool verticalSyncEnabled = false;

	if( !configFile.is_open() )
	{
		// Think about error logging system
		std::cout << "Error: cannot find file config.ini\n";
		return;
	}

	// Read window settings from file
	std::getline( configFile, title );
	configFile >> windowBounds.width >> windowBounds.height;
	configFile >> framerateLimit;
	configFile >> verticalSyncEnabled;

	configFile.close();

	// Set window settings
	m_window.create( sf::VideoMode{ windowBounds }, title );
	m_window.setFramerateLimit( framerateLimit );
	m_window.setVerticalSyncEnabled( verticalSyncEnabled );
}

void Application::initIcon()
{
	auto m_icon = sf::Image{};
	if (!m_icon.loadFromFile("res/images/logo.png"))
	{
    	// Think about error logging system
		std::cout << "Error: cannot find logo\n";
	}
	m_window.setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());
}

void Application::initEngine()
{
	m_machine.run( StateMachine::build< SplashState >( m_machine, m_window, true ) );
}

// Constructors
Application::Application()
{
	this->initWindow();
	this->initIcon();
	this->initEngine();
}

// Destruktor
Application::~Application()
{
	// Empty body
}

// Core function
void Application::run()
{
	// Core loop
	while( m_machine.running() )
	{
		m_machine.nextState();
		m_machine.update();
		m_machine.draw();
	}

	// Leaving the scope of Application will cleanup the engine
}