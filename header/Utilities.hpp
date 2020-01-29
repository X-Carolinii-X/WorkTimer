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

    const int width = 600;
    const int height = 600;

    const std::string appName = "Czasomierz";
    const std::string countdownButton = "Odliczaj czas";
    const std::string infoButton = "Informacje";
    const std::string exitButton = "Wyjście";
    const std::string backButton = "Powrót";
    const std::string endText = "Do zobaczenia :)";

    const std::string infoText = "Czasomierz to prosty program\ndo odliczania czasu.";
    const std::string authorsText = "Wykonali: Paula & Carolinii";

    const int MINUT_CLOCK_BLOCK_SIZE = 14;
    const int SECOND_CLOCK_BLOCK_SIZE = 14;
}

#endif
