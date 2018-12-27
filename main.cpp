#include <iostream>
#include <SFML/Graphics.hpp>
#include <constants.h>
#include <star.h>
#include <time.h>

/*  Author: Tony Truong
 *  Project: Star Field Project for Pi Day
 *  Date: Spring Semester 2018 at Pasadena City College
 *  Description: This is the program to use the mathematics knowledge to create the star field illusion
 *      zooming out the screen like the user is in the spaceship moves forward through the asteroids
 *
 */

using namespace std;

int main()
{
    srand(time(0));
    Star stars[NUMB_OF_STARS];             // Array of stars will flow out on the screen

    // Setup the window frame to draw the graphics out to the screen
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pi Day Project");
    window.setFramerateLimit(60);

    // While the window is in process
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){             // Keep catching the event
            if(event.type==sf::Event::Closed)       // If press close
                window.close();                     // close the window frame
        }
        window.clear();                             // clear the previous graphics on the frame

        //------------------------------------ MAIN PROCESS---------------------------------------------
        for(int i=0;i<NUMB_OF_STARS;i++){
            // If the star goes out of the main screen, reset it to a random position with initial size
            if(stars[i].circle.getPosition().x>SCREEN_WIDTH || stars[i].circle.getPosition().x<0 ||
                    stars[i].circle.getPosition().y>SCREEN_HEIGHT || stars[i].circle.getPosition().y<0){
                stars[i]._x = stars[i].Rand(-SCREEN_WIDTH,SCREEN_WIDTH);
                stars[i]._y = stars[i].Rand(-SCREEN_HEIGHT,SCREEN_HEIGHT);
                stars[i]._z = SCREEN_WIDTH;

                stars[i]._px = stars[i].map(stars[i]._x/stars[i]._z,0,1,0,SCREEN_WIDTH/2);
                stars[i]._py = stars[i].map(stars[i]._y/stars[i]._z,0,1,0,SCREEN_HEIGHT/2);
            }
            stars[i].update();                  // update the params of the star
            stars[i].show(window);              // draw the star(circle) out on the frame
        }
        window.display();                       // display the frame with all stars (circles) drawn
    }
    return 0;
}


