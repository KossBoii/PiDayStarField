#ifndef STAR_H
#define STAR_H
#include <SFML/Graphics.hpp>
#include "constants.h"

class Star
{
public:
    Star();

    void update();
    void show(sf::RenderWindow &w);
    int Rand(int low, int high);
    float map(float x, float in_min, float in_max, float out_min, float out_max);

    sf::CircleShape circle;
    float _x;
    float _y;
    float _z;
    float _px;
    float _py;
//    float _pz;
};

#endif // STAR_H
