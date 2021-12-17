#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

int main()
{
    int x1 = 300, y1 = 300;
    int x2 = 100, y2 = 100;
    int x3 = 400, y3 = 300;
    int g = 10, V = 0, V2=0;
    float d = 0.9;
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::RectangleShape rectangle1(sf::Vector2f(20.f, 100.f));
    rectangle1.setFillColor(sf::Color::Blue);
    rectangle1.setOrigin(10, 50);
    sf::RectangleShape rectangle2(sf::Vector2f(30.f, 70.f));
    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setOrigin(15, 35);
    sf::RectangleShape rectangle3(sf::Vector2f(50.f, 50.f));
    rectangle3.setFillColor(sf::Color::Yellow);
    rectangle3.setOrigin(25, 25);

   


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        rectangle1.setPosition(x1, y1);
        y1 = y1 + V;
        if (y1 < 600-70)
            V = V + g;
        else
            V = 0 - V * d;


        rectangle2.setPosition(x2, y2);
        y2 = y2 + V2;
        if (y2 < 600 - 55)
            V2 = V2 + g;
        else
            V2 = 0 - V2 * d;
        if (x2 < 600-20)
            x2=x2+3;

        if (y3 > 35)
            y3 = y3 -1;
        rectangle3.setPosition(x3, y3);

        window.clear();
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.display();
        _sleep(50);
    }

    return 0;
}