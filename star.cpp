#include "star.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Star::Star()
{
    circle.setFillColor(sf::Color::White);
    _x = Rand(-SCREEN_WIDTH,SCREEN_WIDTH);
    _y = Rand(-SCREEN_HEIGHT,SCREEN_HEIGHT);
    _z = SCREEN_WIDTH;
}

int Star::Rand(int low, int high){
    int r = rand() % (high+abs(low)+1) - abs(low);
    return r;
}

float Star::map(float x, float in_min, float in_max, float out_min, float out_max){
    // Function to scale the value of a variable based on a continuous rate
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Star::update(){
    _z -= VELOCITY;
    _px = map(_x/_z,0,1,0,SCREEN_WIDTH);
    _py = map(_y/_z,0,1,0,SCREEN_HEIGHT);
}

void Star::show(sf::RenderWindow& w){
    // The radius of the stars will change according to the position from the center
    // Note: The further it is, the bigger the radius are
    float r = map(_z,0,SCREEN_WIDTH,6,0);
    circle.setRadius(r);


    circle.setPosition(_px+SCREEN_WIDTH/2,_py+SCREEN_HEIGHT/2);
    w.draw(circle);
}
