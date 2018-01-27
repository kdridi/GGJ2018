#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


/*
 
 resolution : 800 x 600

 pixels : 32 x 32
 map : 32 cases x 24 => 1024 x 768

 pixels : 64 x 64
 map : 16 cases x 12 => 1024 x 768

 map : 16
 
 */

int main(int argc, char* argv[]) {
    cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;
    
    sf::Window App(sf::VideoMode(1024, 768), "myproject");
    
    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}

