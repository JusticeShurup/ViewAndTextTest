#include "Map/Map.h"
#include "Camera.h"
#include "TextureContainer/TextureContainer.h"
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test", sf::Style::Default);
	sf::Event event;
	Map map("Map\\Map.txt", "Map\\GameObjectsMap.txt");
	Camera camera(sf::Vector2f(300, 300), sf::Vector2f(300, 300), &window, sf::Vector2i(32 * map.getSize().x, 32 * map.getSize().y));
	bool is_active = true;	

	sf::Text nickname;
	nickname.setFont(TextureContainer::getInstance()->getFont());
	nickname.setCharacterSize(30);
	nickname.setString("Yaroslave");
	nickname.setPosition(300, 300);


	while (is_active) {
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				is_active = false;
				window.close();
			}
		}

		camera.update();
		window.setView(*camera.getView());

		window.clear();
		window.draw(map);
		window.draw(nickname);
		window.display();
	}

	return 0;
}