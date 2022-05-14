#include "Camera.h"

Camera::Camera(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window, sf::Vector2i map_end) {
	default_height = size.y;
	default_width = size.x;
	view = sf::View(position, size);
	view_for_render = sf::View(position, size);
	game_window = window;

	end_x = map_end.x;
	end_y = map_end.y;

	camera_locked_x = true;
	camera_locked_y = true;

	changed_for_render = false;
}

sf::View* Camera::getDefaultView() {
	setSize(300, 300);
	return &view;
}

void Camera::setSize(float x, float y) {
	view.setSize(x, y);
	game_window->setView(view);
}

void Camera::setSize(sf::Vector2f size) {
	view.setSize(size);
	game_window->setView(view);
}

void Camera::setPosition(float x, float y) {
	view.setCenter(x, y);
	game_window->setView(view);
}

void Camera::setPosition(sf::Vector2f position) {
	view.setCenter(position);
	game_window->setView(view);
}

void Camera::changeCameraToRender(sf::Vector2f center, sf::Vector2f size) {
	if (!changed_for_render) {
		view.setCenter(center);
		view.setSize(size);
	}
	else {
		view.setSize(size);
	}
	game_window->setView(view);
	changed_for_render = !changed_for_render;
}

bool Camera::isCameraLockedX() {
	return camera_locked_x;
}

bool Camera::isCameraLockedY() {
	return camera_locked_y;
}

void Camera::update() {
	int m = 3; 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		view.move(sf::Vector2f(0, -0.15 * m));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		view.move(sf::Vector2f(0, 0.15 * m));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		view.move(sf::Vector2f(-0.15 * m, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		view.move(sf::Vector2f(0.15 * m, 0));
	}
}

sf::Transform Camera::getTransform(float x, float y, int width, int height) {
	sf::View new_view(sf::Vector2f(x, y), sf::Vector2f(width, height));
	return new_view.getTransform();
}

sf::View* Camera::getView() {
	return &view;
}

sf::View* Camera::getRenderView() {
	return &view_for_render;
}

sf::RenderWindow* Camera::getWindow() const {
	return game_window;
}