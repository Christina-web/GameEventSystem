#include <iostream>
#include <string>
#include <vector>

// Player class represents a player in the game who can receive notifications about events.
class Player {
public:
    std::string name;

    // Constructor to initialize the player with a name
    Player(std::string name) : name(name) {}

    // Notify the player about a game event
    void notify(const std::string& event) {
        std::cout << name << " received event: " << event << std::endl;
    }
};

// GameEngine class implementing the Singleton Pattern to ensure a single instance controls the game.
class GameEngine {
private:
    static GameEngine* instance;  // Static instance of GameEngine (Singleton)
    std::vector<Player*> players; // List of players to notify about events

    // Private constructor to prevent direct instantiation
    GameEngine() {}

public:
    // Method to access the single instance of GameEngine (Singleton)
    static GameEngine* getInstance() {
        if (!instance) {
            instance = new GameEngine();  // Create the instance if it doesn't exist
        }
        return instance;
    }

    // Register a player to receive game event notifications
    void attach(Player* player) {
        players.push_back(player);
    }

    // Trigger a game event and notify all registered players
    void triggerEvent(const std::string& event) {
        std::cout << "Event Triggered: " << event << std::endl;
        for (Player* player : players) {
            player->notify(event);
        }
    }
};

// Initialize the static instance of GameEngine
GameEngine* GameEngine::instance = nullptr;

// Main function demonstrating the Singleton Pattern
int main() {
    GameEngine* engine = GameEngine::getInstance();  // Get the single GameEngine instance

    // Create two players
    Player player1("Warrior");
    Player player2("Mage");

    // Register the players to receive notifications
    engine->attach(&player1);
    engine->attach(&player2);

    // Trigger events and notify the players
    engine->triggerEvent("Enemy appeared!");
    engine->triggerEvent("Level up!");

    return 0;
}
