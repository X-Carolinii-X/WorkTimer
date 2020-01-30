#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include <SFML/Graphics/Text.hpp>

namespace Utilities
{
    std::string getTimeStr();
    void sleep( int delay );
    sf::String setPolishLetters( const std::string& text );

    const int WIDTH = 600;
    const int HEIGHT = 600;

    const std::string APP_NAME = "Czasomierz";
    const std::string COUNTDOWN_BUTTON = "Odliczaj czas";
    const std::string INFO_BUTTON = "Informacje";
    const std::string EXIT_BUTTON = "Wyjście";
    const std::string BACK_BUTTON = "Powrót";
    const std::string END_TEXT = "Do zobaczenia :)";

    const std::string INFO_TEXT = "Czasomierz to prosty program\ndo odliczania czasu.";
    const std::string AUTHORS_TEXT = "Wykonali: Paula & Carolinii";

    const int MINUT_CLOCK_BLOCK_SIZE = 14;
    const int SECOND_CLOCK_BLOCK_SIZE = 14;
}

#endif
