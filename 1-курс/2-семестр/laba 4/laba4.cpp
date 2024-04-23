#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>

#include <iostream>
#include <chrono>
#include <thread>

const unsigned int width = 1366;
const unsigned int height = 768;

class mytext {
private:
    sf::Font f1;

    sf::Text m_text;

    sf::Clock clock; 
    sf::Clock clock2;

    std::string m_str;
    std::string output;
 
    int m_num = 1;
    bool first = 1;
    float ShowtTime;
    float m_dt;
    int first_size = 100;
    sf::SoundBuffer buffer;

    sf::Sound sound;
public:
    mytext() = default;
    mytext(std::string str, float t) {
        setup(str,t);
    }
    void setup(std::string str, float t) {
        ShowtTime = t;
        m_str = str;

        m_text.setFillColor(sf::Color::Red);
        m_text.setPosition(50, 200);
        f1.loadFromFile("fonts/font1.ttf");
        m_text.setFont(f1);
        m_text.setCharacterSize(50);
        m_dt = (ShowtTime) / (m_str.length() - 1);
        buffer.loadFromFile("arigato.ogg");
        sound.setBuffer(buffer);
    }

    int verbAnimationText() {
        if (output.length() < m_str.length()) {
            if (first or  clock.getElapsedTime().asSeconds() > m_dt) {
                output = m_str.substr(0, m_num);
                clock.restart();
                m_text.setString(output);
                m_num++;
                if (first) {
                    clock2.restart();
                    std::cout << clock2.getElapsedTime().asSeconds() << std::endl;
                    first = 0;
                    return 1;
                }
                if (output.length() == m_str.length()) {
                    std::cout << clock2.getElapsedTime().asSeconds() << std::endl;
                    sound.play();
                }
                if (!first) {
                    int r_num = std::rand() % 19 - 9;
                    int get_size = m_text.getCharacterSize();
                    if (get_size + r_num > first_size + 10 or get_size + r_num < first_size - 10){
                        m_text.setCharacterSize(get_size - r_num);
                        }
                    else
                        {
                        m_text.setCharacterSize(get_size + r_num);
                        }
                }
            }   
        }
        return 0;
    }
    
    sf::Text get() {
        return m_text;
    }
};



int main()
{   
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(width, height), "~~TEXT~~");
    window.display();
    mytext text1(std::string("HeLLO"), 50);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        } 
        text1.verbAnimationText();
        window.clear(sf::Color::Black);
        window.draw(text1.get());
        window.display();
        } 
    return 0;
}
