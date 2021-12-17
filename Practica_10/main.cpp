#include "rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std::chrono_literals;

int main()
{
    srand(time(0));

    sf::Texture texture;
    if (!texture.loadFromFile("Back.jpg"))
    {
        std::cout << "ERROR: not found Back.jpg" << std::endl;
        return -1;
    }

    sf::Music HOROR;
    if (!HOROR.openFromFile("music.ogg"))
    {
        std::cout << "ERROR: not found music.ogg" << std::endl;
        return -1;
    }

    sf::Sprite background(texture);
    const int width = 1920;
    const int height = 1080;
    int N;
    std::cin >> N;

    sf::RenderWindow window(sf::VideoMode(width, height),"");
    std::vector<ms::Rectangle*> Rectangles;

    for (int i = 0; i <= width; i += width / N)
        Rectangles.push_back(new ms::Rectangle(rand() % width + 1, height, rand() % 10 + 1, rand() % 50 + 1,0 - (rand() % 10 + 1)));


    HOROR.play();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        for (const auto& Rectangle : Rectangles)
        {
            Rectangle->Move();
            if (Rectangle->GetY() < 0)
            {
                Rectangle->SetSPEED(0 - (rand() % 10 + 1));
                Rectangle->SetY(height);
            }
        }

        window.clear();

        window.draw(background);

        for (const auto& Rectangle : Rectangles)
            window.draw(*Rectangle->Get());

        window.display();

        _sleep(50);
    }

    for (const auto& Rectangle : Rectangles)
        delete Rectangle;
    Rectangles.clear();

    return 0;
}