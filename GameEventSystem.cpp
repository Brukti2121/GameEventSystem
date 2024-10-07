#include <iostream>
#include <string>

// Singleton GameEngine class
class GameEngine
{
private:
    static GameEngine* instance;  // Static pointer to hold the single instance

public:
    // Static method to provide access to the single instance
    static GameEngine* getInstance()
    {
        if (!instance)
        {
            instance = new GameEngine();
        }
        return instance;
    }

    // Method to trigger game events
    void triggerEvent(const std::string& event)
    {
        std::cout << "[GameEngine] Event Triggered: " << event << std::endl;
    }

    // Simulates player actions
    void playerAction(const std::string& playerName, const std::string& action)
    {
        std::cout << "[GameEngine] " << playerName << " " << action << std::endl;
    }
};

// Initialize the static instance variable to nullptr
GameEngine* GameEngine::instance = nullptr;

// Main function to test the Singleton GameEngine
int main()
{
    // Get the singleton instance of the GameEngine
    GameEngine* engine = GameEngine::getInstance();

    // Trigger game events
    engine->triggerEvent("Enemy appeared!");
    engine->triggerEvent("Treasure found!");

    // Simulate player actions
    engine->playerAction("Player1", "attacks the enemy.");
    engine->playerAction("Player2", "collects the treasure.");

    // Another game event and player action
    engine->triggerEvent("Player leveled up!");
    engine->playerAction("Player1", "casts a spell.");

    return 0;
}
