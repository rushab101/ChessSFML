#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "ChessBoard.h"
#include "Intro.h"
sf::Music music_intro;
using namespace sf;
//extern sf::Music music_intro;
const float w = 650;
const float h = 650;
class play{
  private:
    sf::Texture texture[14];
	sf::Texture new_intro;
	sf::Sprite new_sprite;
	sf::Texture music_texture;
	sf::Texture stop_music_texture;
	sf::Sprite music_sprite;
	sf::Sprite stop_music_sprite;

      sf::Sprite sprite[15];
      sf::RectangleShape rectangle;
    public:
    play()
  {
    sf::RenderWindow window(sf::VideoMode(w, h), "Chess by Rushab R.");
	int deltaTime = 0;
	int totalTime =0;
	sf::Time second = sf::seconds(10.0f);
	sf::Clock clock;
	int count=0;


	



    texture[0].loadFromFile("E:/C++ Projects/ChessforInterview/images/play-button.png");
    texture[1].loadFromFile("E:/C++ Projects/ChessforInterview/images/refresh-button.png");
    texture[2].loadFromFile("E:/C++ Projects/ChessforInterview/images/board2.png");
	texture[3].loadFromFile("E:/C++ Projects/ChessforInterview/images/board3.png");
	texture[4].loadFromFile("E:/C++ Projects/ChessforInterview/images/board4.png");
	texture[5].loadFromFile("E:/C++ Projects/ChessforInterview/images/board5.png");
	texture[6].loadFromFile("E:/C++ Projects/ChessforInterview/images/board6.png");
	texture[7].loadFromFile("E:/C++ Projects/ChessforInterview/images/board7.png");
	texture[8].loadFromFile("E:/C++ Projects/ChessforInterview/images/board8.png");
	texture[9].loadFromFile("E:/C++ Projects/ChessforInterview/images/board9.png");
	texture[10].loadFromFile("E:/C++ Projects/ChessforInterview/images/board10.png");
	texture[11].loadFromFile("E:/C++ Projects/ChessforInterview/images/board11.png");
	texture[12].loadFromFile("E:/C++ Projects/ChessforInterview/images/board12.png");
	new_intro.loadFromFile("E:/C++ Projects/ChessforInterview/images/board1.png");
	texture[13].loadFromFile("E:/C++ Projects/ChessforInterview/images/board.png");
	music_texture.loadFromFile("E:/C++ Projects/ChessforInterview/images/music.png");
	stop_music_texture.loadFromFile("E:/C++ Projects/ChessforInterview/images/music2.png");
	
      rectangle.setSize(sf::Vector2f(w, h));
        sprite[0].setTexture(texture[0]);
        sprite[1].setTexture(texture[1]);
        sprite[0].setScale(2.0f,2.0f);
        sprite[1].setScale(2.0f,2.0f);
        sprite[0].setPosition(120,20);
        sprite[1].setPosition(400,20);


		music_sprite.setTexture(music_texture);
		music_sprite.setScale(2.0f, 2.0f);
		music_sprite.setPosition(260, 20);

		stop_music_sprite.setTexture(stop_music_texture);
		stop_music_sprite.setScale(2.0f, 2.0f);
		stop_music_sprite.setPosition(260, 20);

        
        rectangle.setFillColor(sf::Color::White);
		


		new_sprite.setTexture(new_intro);
		new_sprite.setScale(0.73f,0.73f);
		new_sprite.setPosition(0, 0);
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

			sprite[12].setTexture(texture[12]);
			sprite[12].setScale(0.73f, 0.73f);
			sprite[12].setPosition(0, 0);

			sprite[13].setTexture(texture[13]);
			sprite[13].setScale(0.73f, 0.73f);
			sprite[13].setPosition(0, 0);





		


		sf::Image icon;
		icon.loadFromFile("E:/C++ Projects/ChessforInterview/images/ok.png");
		window.setIcon(32, 32, icon.getPixelsPtr());

		//sf::Music music;
		music_intro.openFromFile("E:/C++ Projects/ChessforInterview/images/chess.wav");




		music_intro.play();


	
		
    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        sf::Event event;
		window.setFramerateLimit(144);
	




        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
              window.close();
              }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            if (sprite[0].getGlobalBounds().contains(pos.x,pos.y)){
              window.close();
              ChessBoard graphics;
              graphics.MainFunctions(1);
            }
            if (sprite[1].getGlobalBounds().contains(pos.x,pos.y)){
              window.close();
              ifstream in,in2;
              in.open("E:/C++ Projects/ChessforInterview/spritepositions.txt");
              in2.open("E:/C++ Projects/ChessforInterview/boardpositions.txt");
              for(int j=0;j<64;j++){
                int a,b;
                char c,d;
                in>>a>>c;
                spritepositions[j]=a;
                in2>>b>>d;
                board[j]=b;}
              ChessBoard graphics;
              graphics.MainFunctions(0);
            }
			if (music_sprite.getGlobalBounds().contains(pos.x, pos.y)) {
				count++;
				if (count%2!=0){
					music_intro.pause();
				}
				else if (count % 2 == 0) {
					music_intro.play();
				}
			}



            }
      }
		

		sf::Time passed = clock.getElapsedTime();

     window.clear();
     window.draw(rectangle);

	


	 if (passed.asSeconds()<=4 && passed.asSeconds() >= 0){
		 window.draw(sprite[13]);
	 }
	 else if (passed.asSeconds() <= 6 && passed.asSeconds() > 4) {
       window.draw(new_sprite);
	 }

	 else if (passed.asSeconds()<=8 && passed.asSeconds() > 6){
		window.draw(sprite[2]);
	 }
	 else if (passed.asSeconds() <= 10 && passed.asSeconds() > 8) {
		 window.draw(sprite[3]);
	 }
	 else if (passed.asSeconds() <= 12 && passed.asSeconds() > 10) {
		 window.draw(sprite[4]);
	 }
	 else if (passed.asSeconds() <= 14 && passed.asSeconds() > 12) {
		 window.draw(sprite[5]);
	 }
	 else if (passed.asSeconds() <= 16 && passed.asSeconds() > 14) {
		 window.draw(sprite[6]);
	 }
	 else if (passed.asSeconds() <= 18 && passed.asSeconds() > 16) {
		 window.draw(sprite[7]);
	 }
	 else if (passed.asSeconds() <= 20 && passed.asSeconds() > 18) {
		 window.draw(sprite[8]);
	 }
	 else if (passed.asSeconds() <= 22 && passed.asSeconds() > 20) {
		 window.draw(sprite[9]);
	 }
	 else if (passed.asSeconds() <= 24 && passed.asSeconds() > 22) {
		 window.draw(sprite[10]);
	 }

	 else if (passed.asSeconds() <= 26 && passed.asSeconds() > 24) {
		 window.draw(sprite[11]);
	 }

	 else if (passed.asSeconds() > 26) {
		 window.draw(sprite[12]);
	 }



	 if (count % 2 == 0) {
		 window.draw(music_sprite);
	 }


	 if (count%2 != 0) {
		 window.draw(stop_music_sprite);
	 }
	



     window.draw(sprite[0]);
     window.draw(sprite[1]);


	 
	
     window.display();
  } 
	
	

}
};