#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include "Intro.h"


extern win_state ok;

extern bool black_wins;
extern bool white_wins;
extern sf::Music music_intro;

using namespace sf;
class save{
	private:
		 float W = 650;
		 float H = 650;
	public:
		save(){

		}
bool smain()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "Chess by Rushab R.");
    sf::Texture texture[12];
    sf::Sprite sprite[12];
    texture[0].loadFromFile("E:/C++ Projects/ChessforInterview/images/save-disk.png");
    texture[1].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver.png");
	texture[2].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver1.png");
	texture[3].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver2.png");
	texture[4].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver3.png");
	texture[5].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver4.png");
	texture[6].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver5.png");
	texture[7].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver6.png");
	texture[8].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver7.png");
	texture[9].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver8.png");
	texture[10].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver9.png");
	texture[11].loadFromFile("E:/C++ Projects/ChessforInterview/images/gameOver10.png");

        sprite[0].setTexture(texture[0]);
        sprite[0].setScale(2.0f,2.0f);
        sprite[0].setPosition(250,20);
        sprite[1].setTexture(texture[1]);
        sprite[1].setScale(0.73f,0.73f);
        sprite[1].setPosition(0,0);
		sprite[2].setTexture(texture[2]);
		sprite[2].setScale(0.73f, 0.73f);
		sprite[2].setPosition(0, 0);
		sprite[3].setTexture(texture[3]);
		sprite[3].setScale(0.73f, 0.73f);
		sprite[3].setPosition(0, 0);

		sprite[4].setTexture(texture[4]);
		sprite[4].setScale(0.73f, 0.73f);
		sprite[4].setPosition(0, 0);

		sprite[5].setTexture(texture[5]);
		sprite[5].setScale(0.73f, 0.73f);
		sprite[5].setPosition(0, 0);

		sprite[6].setTexture(texture[6]);
		sprite[6].setScale(0.73f, 0.73f);
		sprite[6].setPosition(0, 0);

		sprite[7].setTexture(texture[7]);
		sprite[7].setScale(0.73f, 0.73f);
		sprite[7].setPosition(0, 0);

		sprite[8].setTexture(texture[8]);
		sprite[8].setScale(0.73f, 0.73f);
		sprite[8].setPosition(0, 0);

		sprite[9].setTexture(texture[9]);
		sprite[9].setScale(0.73f, 0.73f);
		sprite[9].setPosition(0, 0);

		sprite[10].setTexture(texture[10]);
		sprite[10].setScale(0.73f, 0.73f);
		sprite[10].setPosition(0, 0);

		sprite[11].setTexture(texture[11]);
		sprite[11].setScale(0.73f, 0.73f);
		sprite[11].setPosition(0, 0);

		sf::Clock clock;


		sf::Image icon;
		icon.loadFromFile("E:/C++ Projects/ChessforInterview/images/ok.png");
		window.setIcon(32, 32, icon.getPixelsPtr());

		sf::Music music;
		music.openFromFile("E:/C++ Projects/ChessforInterview/images/win.wav");

		sf::Music ending;
			ending.openFromFile("E:/C++ Projects/ChessforInterview/images/done.wav");

		if (black_wins) {
			music_intro.pause();
			music.play();
		}
		if (white_wins) {
			music_intro.pause();
			music.play();
		}
		if (!black_wins && !white_wins) {
			music_intro.pause();
			ending.play();
		}



    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
              window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            if (sprite[0].getGlobalBounds().contains(pos.x,pos.y)){
              return true;
              window.close();

              }
            }
          
      }

     window.clear();
	 sf::Time passed = clock.getElapsedTime();
//	 std::cout << black_wins;
	 if (black_wins) {
		 window.draw(sprite[2]);
		 
	 }
	 else if (white_wins) {
		 window.draw(sprite[3]);
	 }
	 else if (!white_wins && !black_wins){
		



		 if (passed.asSeconds() <= 4 && passed.asSeconds() >= 0){
		 window.draw(sprite[1]);
		 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 6 && passed.asSeconds() > 4) {
			 window.draw(sprite[4]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 8 && passed.asSeconds() > 6) {
			 window.draw(sprite[5]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 10 && passed.asSeconds() > 8) {
			 window.draw(sprite[6]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 12 && passed.asSeconds() > 10) {
			 window.draw(sprite[7]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 14 && passed.asSeconds() > 12) {
			 window.draw(sprite[8]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 16 && passed.asSeconds() > 14) {
			 window.draw(sprite[9]);
			 window.draw(sprite[0]);
		 }
		 else if (passed.asSeconds() <= 18 && passed.asSeconds() > 16) {
			 window.draw(sprite[10]);
			 window.draw(sprite[0]);
		 }
		 else if ( passed.asSeconds() > 18) {
			 window.draw(sprite[11]);
			 window.draw(sprite[0]);
		 }

		

	 }


	 
     window.display();
  }
    
    
    return 0;
}
};
