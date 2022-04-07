#include "Platform/Platform.hpp"
#include "Game.h"

using namespace std;

Game::Game(int screenWidthIn, int screenHeightIn, int worldMapIn[width][width], double frameRateIn, double posXIn, double posYIn, double dirXIn, double dirYIn, double planeXIn, double planeYIn) {
	frameRate = frameRateIn;
	frameTime = 1.f / frameRate;
	screenWidth = screenWidthIn;
	screenHeight = screenHeightIn;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < width; j++)
			worldMap[i][j] = worldMapIn[i][j];

	posX = posXIn;
	posY = posYIn;
	dirX = dirXIn;
	dirY = dirYIn;
	planeX = planeXIn;
	planeY = planeYIn;

	sf::Vector2f rayDir(0.f, 0.f);
}

void Game::loop(sf::RenderWindow& window) {
	sf::RectangleShape worldFloor(sf::Vector2f(screenWidth, screenHeight));
	sf::Color floorColor(0,255,0);
	worldFloor.setPosition(0, (int)screenHeight/2);
	worldFloor.setFillColor(floorColor);
	window.draw(worldFloor);

	for (int x = 0; x < screenWidth; x++) {
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = int(posX);
		int mapY = int(posY);

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while(hit == 0) {
			if(sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(worldMap[mapX][mapY] > 0) hit = 1;
		}

		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(screenHeight / perpWallDist);

		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;

		switch(worldMap[mapX][mapY]) {
			case 1:  lineColor = sf::Color::Red;    break;
			case 2:  lineColor = sf::Color::Magenta;  break;
			case 3:  lineColor = sf::Color::Blue;   break;
			case 4:  lineColor = sf::Color::White;  break;
			default: lineColor = sf::Color::Yellow; break;
		}

		if (side == 1) {
			lineColor.r = lineColor.r/2;
			lineColor.g = lineColor.g/2;
			lineColor.b = lineColor.b/2;
		}

		sf::Vertex line[2] = {
			sf::Vertex(sf::Vector2f(x, drawStart), lineColor),
			sf::Vertex(sf::Vector2f(x, drawEnd), lineColor)
		};

		window.draw(line, 2, sf::Lines);
	}

	double moveSpeed = frameTime * 5.0;
	double rotSpeed = frameTime * 3.0;

	// Moverse adelante
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	// Moverse atrás
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}
	// Rotar a la derecha
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	// Rotar a la izquierda
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}