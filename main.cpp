#include <iostream>
#include <string>
#include <vector>

// Player class represents a player in the game
class Player {
public:
    std::string name; // The name of the player (e.g., Warrior, Mage, etc.)

    // Constructor to initialize the player with a given name
    Player(const std::string& name) : name(name) {}

    // Method to simulate the player responding to an event
    void respondToEvent(const std::string& event) {
        // Simple print to demonstrate player response
        if (event == "Enemy appeared!") {
            std::cout << name << " is fighting!" << std::endl;
        } else if (event == "Level up!") {
            std::cout << name << " received event: Level up!" << std::endl;
        } else {
            std::cout << name << " received event: " << event << std::endl;
        }
    }
};

// GameEngine class implementing the Singleton Pattern to control game events
class GameEngine {
private:
    static GameEngine* instance;    // Static instance for Singleton
    std::vector<Player*> players;   // List of registered players

    // Private constructor ensures no direct instantiation (Singleton)
    GameEngine() {}

public:
    // Static method to get the single instance of GameEngine (Singleton)
    static GameEngine* getInstance() {
        if (!instance) {
            instance = new GameEngine();  // Create the instance if it doesn't exist
        }
        return instance;
    }

    // Method to register players to the GameEngine
    void registerPlayer(Player* player) {
        players.push_back(player); // Add player to the list
    }

    // Method to trigger a game event and notify all registered players
    void triggerEvent(const std::string& event) {
        std::cout << "Event Triggered: " << event << std::endl;
        // Notify each registered player about the event
        for (Player* player : players) {
            player->respondToEvent(event); // Each player responds to the event
        }
    }
};

// Initialize the static instance pointer to nullptr (Singleton initialization)
GameEngine* GameEngine::instance = nullptr;

// Main function demonstrating the Singleton pattern
int main() {
    // Get the single instance of the GameEngine (Singleton)
    GameEngine* engine = GameEngine::getInstance();

    // Create two players
    Player player1("Warrior");
    Player player2("Mage");

    // Register players to the GameEngine
    engine->registerPlayer(&player1);
    engine->registerPlayer(&player2);

    // Trigger events in the game
    engine->triggerEvent("Enemy appeared!"); // Notify players about the enemy
    engine->triggerEvent("Level up!");       // Notify players about leveling up

    return 0;
}
