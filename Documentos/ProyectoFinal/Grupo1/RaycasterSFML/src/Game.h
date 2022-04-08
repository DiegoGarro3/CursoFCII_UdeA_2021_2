#include "Platform/Platform.hpp"
using namespace std;

class Game {
	const static int width = 24; // número de pruebas

    public:
        Game(int, int, int [][width], double, double, double, double, double, double, double);

        void loop(sf::RenderWindow& window);

    private:
		// Información del mundo
		int screenWidth, screenHeight;
		double frameRate, frameTime;
		int worldMap[width][width];
		sf::RectangleShape worldFloor;
		sf::Color floorColor;

		// Infomración del jugador
		double posX, posY;
		double dirX, dirY;
		double planeX, planeY;

		// Información de cada rayo
		sf::Vector2f rayDir;
		int rayMapX, rayMapY;
		double raySideDistX, raySideDistY;
		double rayDeltaDistX, rayDeltaDistY;
		double rayPerpWallDist;
		int rayStepX, rayStepY;
		int rayHit;
		int raySide;
		int lineHeight;
		int drawStart, drawEnd;
		sf::Color lineColor;
};