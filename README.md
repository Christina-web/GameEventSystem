# GameEventSystem - Singleton Pattern

## Design Pattern Explanation
The Singleton Pattern is a design pattern that restricts the instantiation of a class to only one instance and provides a global point of access to this instance. In this implementation, the `GameEngine` class follows the Singleton Pattern to ensure that there is only one game engine controlling the events within the game. This single instance is responsible for triggering game events (e.g., "enemy appeared" or "level up"), and players (like `Warrior` and `Mage`) are notified about these events through this game engine.

## Benefits
- **Global Access**: Since the Singleton provides a single instance of the `GameEngine`, it can be accessed from anywhere in the code without passing around multiple instances.
- **Centralized Control**: The game events are managed from one place, reducing complexity and ensuring consistency across the game.
- **Memory Efficiency**: Only one instance of the `GameEngine` is created, preventing unnecessary memory usage that might occur with multiple instances.

## Consequences
- **Difficulty in Testing**: The Singleton Pattern makes unit testing more challenging because its instance is global, which might lead to hidden dependencies between tests.
- **Single Point of Failure**: If the Singleton instance is corrupted or malfunctions, the entire game system could be affected since all operations depend on this single instance.
- **Potential Bottleneck**: In a large-scale system, relying on a single instance for game events might become a performance bottleneck if many objects depend on notifications from the Singleton.

