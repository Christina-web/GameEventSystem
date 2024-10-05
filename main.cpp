#include <iostream>
#include <string>
#include <vector>

// Player class
class Player {
public:
    std::string name;
    Player(std::string name) : name(name) {}
    void notify(const std::string& event) {
        std::cout << name << " received event: " << event << std::endl;
    }
};

// GameEngine Singleton
class GameEngine {
private:
    static GameEngine* instance;
    std::vector<Player*> players;
    GameEngine() {} // Private constructor

public:
    static GameEngine* getInstance() {
        if (!instance) {
            instance = new GameEngine();
        }
        return instance;
    }

    void attach(Player* player) {
        players.push_back(player);
    }

    void triggerEvent(const std::string& event) {
        std::cout << "Event Triggered: " << event << std::endl;
        for (Player* player : players) {
            player->notify(event);
        }
    }
};

// Initialize the static instance
GameEngine* GameEngine::instance = nullptr;

// Main function demonstrating Singleton Pattern
int main() {
    GameEngine* engine = GameEngine::getInstance();

    Player player1("Warrior");
    Player player2("Mage");

    engine->attach(&player1);
    engine->attach(&player2);

    engine->triggerEvent("Enemy appeared!");
    engine->triggerEvent("Level up!");

    return 0;
}
