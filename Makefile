# Zadanie:
# 1) Pliki .o powinny zapisywać się w innym miejscu
# 2) Ustawić ściężkę do pliku wynikowego
# 3) Stworzyć odzielne warianty dla budowy debug i release
# 4) Dołączyć potrzebne biblioteki .dll

LIBDIR=lib

OBJS = Main.o Logger.o SplashScreen.o Utilities.o Button.o Menu.o InfoScreen.o ClockScreen.o
CXX = g++
CXXFLAGS = -Wall -std=c++11

LDFLAGS = -L$(LIBDIR)/SFML/lib
CPPFLAGS = -I$(LIBDIR)/SFML/include"

LDDEBUGLIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d -mwindows
LDRELEASELIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -mwindows

debug: $(OBJS)
		$(CXX) -g -o WorkTimer $(OBJS) $(LDDEBUGLIBS) $(LDFLAGS)

Main.o: Main.cpp header/Logger.hpp header/screens.hpp header/EachScreen.hpp
		$(CXX) -g -c Main.cpp $(CPPFLAGS)

Logger.o: header/Logger.hpp header/Utilities.hpp source/Logger.cpp
			$(CXX) -g -c source/Logger.cpp $(CPPFLAGS)

SplashScreen.o: header/SplashScreen.hpp header/Logger.hpp source/SplashScreen.cpp
			$(CXX) -g -c source/SplashScreen.cpp $(CPPFLAGS)

Utilities.o: header/Utilities.hpp source/Utilities.cpp
			$(CXX) -g -c source/Utilities.cpp $(CPPFLAGS)

Button.o: header/Button.hpp header/Logger.hpp source/Button.cpp
			$(CXX) -g -c source/Button.cpp $(CPPFLAGS)

Menu.o: header/Menu.hpp header/Button.hpp header/Logger.hpp source/Menu.cpp source/Button.cpp
			$(CXX) -g -c source/Menu.cpp $(CPPFLAGS)

InfoScreen.o: header/InfoScreen.hpp header/Logger.hpp header/Button.hpp source/InfoScreen.cpp source/Button.cpp
			$(CXX) -g -c source/InfoScreen.cpp $(CPPFLAGS)

ClockScreen.o: header/ClockScreen.hpp header/Logger.hpp header/Button.hpp source/ClockScreen.cpp source/Button.cpp
			$(CXX) -g -c source/ClockScreen.cpp $(CPPFLAGS)

# clean:
# 	$(RM) game $(OBJS)

# build-windows-release: game
