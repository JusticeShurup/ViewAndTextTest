#ifndef _MAP_H_
#define _MAP_H_
#include "Tileset.h"
#include "../GameObject.h"
#include <vector>


class Map : public sf::Drawable
{
public: 
	Map(std::string tilesets_map_filename, std::string gameobjects_map_filename);

	void changeTilesetTexture(int x_pos, int y_pos, sf::Texture* new_texture);

	void addGameObject(GameObject* game_object); // Add GameObject to array of GameObject to check collision and Ysort

	void removeGameObject(GameObject* game_object);
	void removeGameObjectByIndex(int index);

	GameObject* getGameObjectByCoordinates(sf::Vector2f coordinates);
	GameObject* getGameObjectByIndex(int index);
	 
	sf::Vector2i getSize();
	sf::Vector2i getTilesetSize();

	bool checkCollisionWithMap(sf::Vector2f coordinates, GameObject* game_obj);
	int returnCollisionWithMap(sf::Vector2f coordinates, GameObject* game_obj);
	

	void update(GameObject* game_obj);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Vector2i size;
	sf::Vector2i tileset_size;

	std::vector<std::vector<Tileset>> tileset_map;
	std::vector<std::vector<std::string>> tileset_signs;

	std::vector<GameObject*> gameobject_map;
	std::vector<std::string> gameobject_names;
};
#endif