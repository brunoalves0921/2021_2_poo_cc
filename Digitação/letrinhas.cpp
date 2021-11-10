#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>


struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pincel(sf::RenderWindow& window) : window(window){
        if(!font.loadFromFile("../Ubuntu.ttf"))
            std::cout << "Erro no carregamento da font\n";
        text.setFont(font);
    }

    void write(std::string str, int x, int y, int size, sf::Color color) {
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Bubble {
    int x;
    int y;
    char letter;
    int speed;
    bool alive {true};

    static const int radius { 20 };

    Bubble(int x, int y, char letter, int speed): x{x}, y{y}, letter{letter}, speed{speed} {
    }

    void update() {
        this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape circle (Bubble::radius);
        circle.setPosition(x, y);
        circle.setFillColor(sf::Color::White);
        window.draw(circle);

        static Pincel pincel(window);
        pincel.write(std::string(1, letter), x + 0.5 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Blue);
    }

};

struct Board {
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    Pincel pencil;

    int hits { 0 };
    int miss { 0 };

    Board(sf::RenderWindow& window): window(window), pencil(window) {
        bubbles.push_back(Bubble(100, 100, 'A', 1));
        bubbles.push_back(Bubble(200, 100, 'B', 2));
        bubbles.push_back(Bubble(300, 100, 'C', 3));
    }

    void update() {
        if (this->check_new_bubble())
            this->add_new_bubble();

        for (Bubble& bubble : bubbles) {
            bubble.update();
        }
        this->mark_outside_bubbles();
        this->remove_dead_bubbles();
    }

    void remove_dead_bubbles() {
        std::vector<Bubble> vivas;
        for (Bubble& bubble : bubbles) {
            if (bubble.alive) {
                vivas.push_back(bubble);
            }
        }
        this->bubbles = vivas;
    }
    void mark_outside_bubbles() {
        for (Bubble& bubble : bubbles) {
            if (bubble.y + 2 * Bubble::radius > (int) this->window.getSize().y) {
                if (bubble.alive) {
                    bubble.alive = false;
                    this->miss++;
                }
            }
        }
    }

    void mark_by_hit(char letter) {
        for (Bubble& bubble : bubbles) {
            if (bubble.letter == letter) {
                bubble.alive = false;
                this->hits++;
                break;
            }
        }
    }

   bool check_new_bubble() {
       static const int new_bubble_timeout { 60 };
       static int new_bubble_timer { 0 };

       new_bubble_timer--;
       if (new_bubble_timer <= 0) {
           new_bubble_timer = new_bubble_timeout;
           return true;
       }
       return false;
    }

    void add_new_bubble() {
        int x = rand() % ((int) this->window.getSize().x -2 * Bubble::radius);
        int y = - 2 * Bubble::radius;
        int speed = rand() % 5 + 1;
        char letter = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letter, speed));
    }
   void draw() {
        pencil.write("Acertou: " + std::to_string(this->hits) + "\n" + "Vacilou: " + std::to_string(this->miss), 10, 10, 20, sf::Color::White);
        pencil.write("Bubbles Vivas: " + std::to_string(this->bubbles.size()), 10, 55, 20, sf::Color::White);
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }
};
struct Game {
    sf::RenderWindow window;
    Board board;
    std::function<void()> on_update;

    Game() : window(sf::VideoMode(800,600), "Bubbles"), board(window) {
        this->on_update = [&]() {
            this->draw();
        };
        window.setFramerateLimit(60);
    }

    void process_Events() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::TextEntered) {
                char code = static_cast<char>(event.text.unicode);
                code = toupper(code);
                board.mark_by_hit(code);
            }
        }
    }

    void draw() {
        board.update();

        window.clear(sf::Color::Black);
        board.draw();
        window.display();

        if (board.miss > 2) {
            this->on_update = [&]() {
                this->gameover();
            };
        }
    }

    void gameover() {
        static Pincel pincel(window);
        window.clear(sf::Color::Red);
        pincel.write("Game Over =[", 250, 300, 50, sf::Color::White);
        window.display();
    }

    void main_loop() {
        while (window.isOpen()) {
            process_Events();
            on_update();
        }
    }
};

int main() {
    Game game;
    game.main_loop();
    return 0;
}