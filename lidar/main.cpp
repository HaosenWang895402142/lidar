#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "line");
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(10, 10)),
        sf::Vertex(sf::Vector2f(150, 150))
    };

    std::vector<sf::Int16> samples = line;
    //buffer.loadFromSamples(samples[0], samples.size(), 2, 44100);
    sf::SoundBuffer buffer;
    buffer.loadFromSamples(samples[0], samples.size(), 2, 44100);
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(line, 2, sf::Lines);
        window.display();

    }

    return 0;
}
