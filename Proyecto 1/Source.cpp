#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Lienzo.h"
#include "Menu.h"
#include "Herramientas.h"


using namespace sf;
using namespace std;

int main() {
	int op;
	bool juego = false;
	Lienzo * lienzoP,* lienzoM,* lienzoG;
	Herramientas* tabla;

	while (juego != true) {
		system("cls");
		cout << "**Bienvenido a Paint**" << endl;
		cout << "Elige un lienzo para comenzar: " << endl;
		cout << "1. Lienzo Chico" << endl;
		cout << "2. Lienzo Mediano" << endl;
		cout << "3. Lienzo Grande" << endl;
		cout << "4. Salir" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			system("cls");
			lienzoP = new Lienzo(500, 300, "Lienzo Pequeño");
			break;

		case 2:
			system("cls");
			lienzoM = new Lienzo(700, 400, "Lienzo Mediano");
			break;

		case 3:
			system("cls");
			lienzoG = new Lienzo(900, 600, "Lienzo Grande");
			break;

		case 4:
			juego = true;
			break;
		}
		system("cls");
		cout << "Vuelve pronto :D" << endl;
	}
	

	return 0;
}

/*
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
	return 0;
}*/
