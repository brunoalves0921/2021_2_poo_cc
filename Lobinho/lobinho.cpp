#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

void setSize(sf::Sprite& sprite, int widte, int height) {
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) widte / dim.width, (float) height / dim.height);
}
struct Entity {
    int x {0};
    int y {0};
    int step {0};
    sf::Sprite sprite;

    Entity(int x, int y, int step, sf::Texture& texture):
        x {x}, y {y}, step {step}, sprite(texture) {
    }

    void draw(sf::RenderWindow& window) {
        this->sprite.setPosition(x * step, y * step);
        setSize(this->sprite, step, step);
        window.draw(this->sprite);
    }
};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};
    sf::Sprite sprite;
    sf::RectangleShape rect;
    Board(int nc, int nl, int step, sf::Texture& texture) {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, 0);
        this->rect.setSize(sf::Vector2f(step, step));
        this->rect.setFillColor(sf::Color::Transparent);
        this->rect.setOutlineColor(sf::Color::Black);
        this->rect.setOutlineThickness(1);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (int i = 0; i < nc; i++) {
            for(int j = 0; j < nl; j++) {
                rect.setPosition(i * step,  j * step);
                window.draw(rect);
            }
        }
    }
};

void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    if (key == move_keys[0])
        entity.x--;
    else if (key == move_keys[1])
        entity.y--;
    else if (key == move_keys[2])
        entity.x++;
    else if (key == move_keys[3])
        entity.y++;
}

int main () {

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    std::string path = cwd;
    std::string lobol = path + "/../images/lobol.png";
    std::string coelho = path + "/../images/coelho.png";
    std::string grama = path + "/../images/grama.jpg";

    const int STEP {100};

    sf::Texture grass_tex;
    grass_tex.loadFromFile(grama);
    sf::Texture wolf_tex;
    wolf_tex.loadFromFile(lobol);
    sf::Texture rabbit_tex;
    rabbit_tex.loadFromFile(coelho);

    Board board(7, 5, STEP, grass_tex);
    Entity wolf(1, 1, STEP, wolf_tex);
    Entity rabbit(3, 3, STEP, rabbit_tex);

    sf::RenderWindow window(sf::VideoMode(board.nc * STEP, board.nl * STEP), "Lobinho");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                moveEntity(event.key.code, wolf, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                moveEntity(event.key.code, rabbit, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
            }
        }

        window.clear();
        board.draw(window);
        wolf.draw(window);
        rabbit.draw(window);
        window.display();
    }

    return 0;

}
