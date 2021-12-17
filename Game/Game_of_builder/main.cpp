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
    const int width = 700;
    const int height = 700;
    int N=7, tempX,tempY, moveP1 = 0;
    bool CanMoveRightP1 = true, CanMoveLeftP1 = true, CanMoveUpP1 = true, CanMoveDownP1 = true;
    bool CanMoveRightP2 = true, CanMoveLeftP2 = true, CanMoveUpP2 = true, CanMoveDownP2 = true;

    sf::Font font;//шрифт 
    font.loadFromFile("CyrilicOld.ttf");
    sf::Text text("", font, 20);
    text.setColor(sf::Color(0,0,0));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(250, 330);

    sf::RenderWindow window(sf::VideoMode(width, height),"Game_of_builders");

    std::vector<ms::Rectangle*> Rectangles;// сдесь хранятся стенки
    std::vector<ms::Rectangle*> Rectangles2;

    /////////////////////////////////// создание игрового поля
    for (int k = (height / 7)-4; k < height; k += (height / 7))//наши стенки по горизонтали
    {
        for (int i = 5; i < width; i += 100)
            Rectangles.push_back(new ms::Rectangle(i, k, 90 , 8, false, 34, 139, 34, 150));
    }
    for (int k = (height / 7) - 4; k < height; k += (height / 7))//наши стенки по вертикали
    {
        for (int i = 5; i < width; i += 100)
            Rectangles2.push_back(new ms::Rectangle(k, i, 8, 90, false, 34, 139, 34, 150));
    }

    Rectangles.push_back(new ms::Rectangle(0, height-10, width, 15, true, 210, 105, 30, 255));//большие боковые стенки, добавил ради красоты
    Rectangles.push_back(new ms::Rectangle(width-10, 0, 15, height, true, 210, 105, 30, 255));
    Rectangles.push_back(new ms::Rectangle(0, 0, width, 15, true, 210, 105, 30, 255));
    Rectangles.push_back(new ms::Rectangle(0, 0, 15, height, true, 210, 105, 30, 255));
    ////////////////////////////////////////

    ms::Player p1(350,450,20,255,0,0);// создание игроков (положение X , Y,  размер, цвет(RGB))
    ms::Player p2(350,250,20, 0, 0, 255);
    HOROR.play();
    HOROR.setLoop(true);
    while (window.isOpen())
    {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f pos = window.mapPixelToCoords(pixelPos);// берём координаты мышки
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();// закрытие игры

            if (event.type == sf::Event::MouseButtonPressed)
            {                   
                tempX = pos.x;//забираем координату нажатия курсора Х
                tempY = pos.y;//забираем координату нажатия курсора Y
                if ((event.key.code == sf::Mouse::Left)&((moveP1 == 2) || (moveP1 == 5)))// установка стен
                { 

                    for (const auto& Rectangle : Rectangles)
                    {
                        if ((Rectangle->GetX()+90 > tempX)&(Rectangle->GetY() + 8 > tempY) & (Rectangle->GetX() < tempX) & (Rectangle->GetY() < tempY))
                        {
                            Rectangle->SetPhysics(true);
                            moveP1 += 1;
                        }
                    }
                    for (const auto& Rectangle : Rectangles2)
                    {
                        if ((Rectangle->GetX() + 8 > tempX)& (Rectangle->GetY() + 90 > tempY)& (Rectangle->GetX() < tempX)& (Rectangle->GetY() < tempY))
                        {
                            Rectangle->SetPhysics(true);
                            moveP1 += 1;
                        }
                    }

                }

            }
            //////////////////////////////// условие передвижения
           if ((p1.GetX() == p2.GetX()) & (p2.GetY() == p1.GetY() + 100))// нельзя встать на занятое место
                CanMoveDownP1 = false;
            else 
                CanMoveDownP1 = true;

            if ((p1.GetX() == p2.GetX())& (p2.GetY() == p1.GetY() - 100))
                 CanMoveUpP1 = false;
            else 
                 CanMoveUpP1 = true;

            if ((p1.GetY() == p2.GetY()) & (p2.GetX() == p1.GetX() + 100))
                CanMoveRightP1 = false;
            else
                CanMoveRightP1 = true;

            if ((p1.GetY() == p2.GetY())& (p2.GetX() == p1.GetX() - 100))
                CanMoveLeftP1 = false;
            else
                CanMoveLeftP1 = true;

            for (const auto& Rectangle : Rectangles2)// нельзя пройти через стенки
            {
                if ((Rectangle->GetX() + 54 == p1.GetX()) & (Rectangle->GetY() + 45 == p1.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveLeftP1 = false;
                if ((Rectangle->GetX() - 46 == p1.GetX()) & (Rectangle->GetY() + 45 == p1.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveRightP1 = false;
            }
            for (const auto& Rectangle : Rectangles)
            {
                if ((Rectangle->GetX() + 45 == p1.GetX()) & (Rectangle->GetY() + 54 == p1.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveUpP1 = false;
                if ((Rectangle->GetX() + 45 == p1.GetX()) & (Rectangle->GetY() - 46 == p1.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveDownP1 = false;
            }
            if (p1.GetX() - 100 < 0)// границы экрана
                CanMoveLeftP1 = false;
            if (p1.GetX() + 100 > 700)
                CanMoveRightP1 = false;
            if (p1.GetY() - 100 < 0)
                CanMoveUpP1 = false;
            if (p1.GetY() + 100 > 700)
                CanMoveDownP1 = false;

            //////////////////////////////
            
            ////////////////////////////// перемещение 2 игрока
             if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) & ((moveP1 == 3) || (moveP1 == 4)) & (CanMoveUpP2 == true))
            {
                     p2.Move(-100, 0);
                     moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) & ((moveP1 == 3) || (moveP1 == 4)) & (CanMoveDownP2 == true))
            {
                    p2.Move(100, 0);
                    moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) & ((moveP1 == 3) || (moveP1 == 4)) & (CanMoveLeftP2 == true))
            {
                    p2.Move(0, -100);
                    moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) & ((moveP1 == 4) || (moveP1 == 3)) & (CanMoveRightP2 == true))
            {
                p2.Move(0, 100);
                moveP1 += 1;
            }

            ///////////////////////////////////////////

            /////////////////////////////////////////// тоже самое но для первого игрока
            if ((p1.GetX() == p2.GetX())& (p1.GetY() == p2.GetY() + 100))
                CanMoveDownP2 = false;
            else
                CanMoveDownP2 = true;

            if ((p1.GetX() == p2.GetX())& (p1.GetY() == p2.GetY() - 100))
                CanMoveUpP2 = false;
            else 
                CanMoveUpP2 = true;

            if ((p1.GetY() == p2.GetY()) & (p1.GetX() == p2.GetX() + 100))
                CanMoveRightP2 = false;
            else 
                CanMoveRightP2 = true;

            if ((p1.GetY() == p2.GetY()) & (p1.GetX() == p2.GetX() - 100))
                CanMoveLeftP2 = false;
            else 
                CanMoveLeftP2 = true;

            for (const auto& Rectangle : Rectangles2)
            {
                if ((Rectangle->GetX() + 54 == p2.GetX()) & (Rectangle->GetY() + 45 == p2.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveLeftP2 = false;
                if ((Rectangle->GetX() - 46 == p2.GetX()) & (Rectangle->GetY() + 45 == p2.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveRightP2 = false;
            }
            for (const auto& Rectangle : Rectangles)
            {
                if ((Rectangle->GetX() + 45 == p2.GetX()) & (Rectangle->GetY() + 54 == p2.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveUpP2 = false;
                if ((Rectangle->GetX() + 45 == p2.GetX()) & (Rectangle->GetY() - 46 == p2.GetY()) & (Rectangle->GetPhisics() == true))
                    CanMoveDownP2 = false;
            }

            if (p2.GetX() - 100 < 0)
                CanMoveLeftP2 = false;
            if (p2.GetX() + 100 > 700)
                CanMoveRightP2 = false;
            if (p2.GetY() - 100 < 0)
                CanMoveUpP2 = false;
            if (p2.GetY() + 100 > 700)
                CanMoveDownP2 = false;

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&((moveP1 == 0)|| (moveP1 == 1)) & (CanMoveUpP1 == true))
            {
                p1.Move(-100,0);
                moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))& ((moveP1 == 0) || (moveP1 == 1)) & (CanMoveDownP1 == true))
            {
                p1.Move(100, 0);
                moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))& ((moveP1 == 0) || (moveP1 == 1)) & (CanMoveLeftP1 == true))
            {
                p1.Move(0, -100);
                moveP1 += 1;
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))& ((moveP1 == 0) || (moveP1 == 1)) & (CanMoveRightP1 == true))
            {
                p1.Move(0, 100);
                moveP1 += 1;
            }
            /////////////////////////


            if (moveP1 == 6)// сброс счётчика
                moveP1 = 0;
        }

        window.clear();

        window.draw(background);


        for (const auto& Rectangle : Rectangles2)
            window.draw(*Rectangle->Get());
        for (const auto& Rectangle : Rectangles)
            window.draw(*Rectangle->Get());
        
        window.draw(*p1.Get());
        window.draw(*p2.Get());
        if ((CanMoveRightP1 == false) & (CanMoveLeftP1 == false) & (CanMoveUpP1 == false) & (CanMoveDownP1 == false))
        {
            text.setString("Синий игрок победил");//задает строку тексту
            window.draw(text);//рисую этот текст
        }
        if ((CanMoveRightP2 == false) & (CanMoveLeftP2 == false) & (CanMoveUpP2 == false) & (CanMoveDownP2 == false))
        {
            text.setString("Красный игрок победил");//задает строку тексту
            window.draw(text);//рисую этот текст
        }
        window.display();

        _sleep(100);
    }

    for (const auto& Rectangle : Rectangles)
        delete Rectangle;
    Rectangles.clear();

    for (const auto& Rectangle : Rectangles2)
        delete Rectangle;
    Rectangles2.clear();

    return 0;
}