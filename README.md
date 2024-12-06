
# Word Scramble Game

A simple word scramble game built using the `bobcat_ui` library. Players unscramble words, score points, use hints, and view game statistics. This project is designed for learning purposes and demonstrates basic game logic, UI interactions, and file handling.

---

## Features

- **Main Menu**: Options to play the game, view instructions, view statistics, and quit.
- **Instructions Screen**: Provides detailed rules of the game.
- **Gameplay Screen**:
  - Scrambled words presented for the player to guess.
  - Scoring based on word length:
    - 3-letter word: 1 point
    - 4-letter word: 2 points
    - 5+ letter word: 3 points
  - One hint per word allowed, revealing the first letter.
  - "Give Up" button to forfeit and view the correct word.
- **Game Summary**: Displays whether the player won or gave up, the score, and the correct word.
- **Statistics Screen**: Tracks rounds played, scores, words, and whether a hint was used.
  - Option to clear statistics.
- **Word Bank**: Words are loaded from `words.txt`.
- **Statistics**: Saved in `stats.csv` and persist across sessions.

---

## File Structure

```plaintext
.
├── Application.h       # Main code for the Word Scramble Game
├── words.txt           # List of words for the game
├── stats.csv           # Saved game statistics
├── Makefile            # Build and compile instructions
├── main.cpp            # Entry point for the game
├── README.md           # Documentation
```

---

## Prerequisites

1. **C++ Compiler**: Ensure you have a modern C++ compiler installed (e.g., `g++`).
2. **bobcat_ui Library**: Make sure `bobcat_ui` is installed and properly linked.
3. **Standard Libraries**: The code uses standard C++ libraries like `<fstream>`, `<string>`, `<vector>`, and `<algorithm>`.

---

## Setup and Compilation

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd <repository_name>
   ```

2. Compile the code using the `Makefile`:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./WordScrambleGame
   ```

---

## Game Instructions

1. **Start the Game**:
   - Click on "Play Game" from the main menu.
2. **Unscramble Words**:
   - Guess the unscrambled word from the scrambled letters.
   - Use the "Hint" button for assistance (limited to one hint per word).
   - Click "Give Up" to forfeit the current round.
3. **Scoring**:
   - Points are based on the length of the correct word.
4. **Statistics**:
   - View your performance across all rounds, including:
     - Round number
     - Outcome (Win/Loss)
     - Score
     - The word played
     - Whether a hint was used.
5. **Clear Statistics**:
   - Reset all saved statistics by clicking "Clear Statistics."

---

## Files

### `words.txt`

This file contains the list of words used in the game. Each word should be on a new line. Example:

```plaintext
shadowing
blending
shimmering
swooping
```

### `stats.csv`

This file saves the game statistics after each round. Example format:

```plaintext
Round 1: Loss, Score: 1, Word: swooping, Hint Used: Yes
Round 2: Win, Score: 7, Word: shadowing, Hint Used: No
Round 3: Loss, Score: 4, Word: shimmering, Hint Used: Yes
Round 4: Win, Score: 3, Word: blending, Hint Used: No
```

---

## Code Structure and Key Methods

### `Application.h`

The main class `Application` encapsulates all the game logic. Key methods include:

1. **`setup()`**:
   - Initializes the UI components and sets the default view to the main menu.

2. **`loadWords()`**:
   - Loads the word list from `words.txt` and shuffles them.

3. **`scrambleWord(const std::string&)`**:
   - Randomly scrambles the letters of a word.

4. **`saveStatistics(bool win)`**:
   - Saves the current round statistics to `stats.csv`.

5. **`resetGame()`**:
   - Resets the game state, including hints, guessed words, and scrambled word.

6. **`handleNavigationClick(Widget* sender)`**:
   - Handles navigation between different screens (menu, game, instructions, statistics).

7. **`handleGameplayClick(Widget* sender)`**:
   - Handles gameplay actions like submitting a guess, giving up, or loading a new word.

8. **`displayGameSummary(bool win)`**:
   - Displays the summary screen after each round.

9. **`updateDisplay()`**:
   - Shows or hides UI components based on the current view.

---

## How to Customize

1. **Modify Word Bank**:
   - Edit `words.txt` to add or remove words.

2. **Change Scoring Rules**:
   - Update the `score` calculation in `handleGameplayClick`.

3. **Customize UI**:
   - Adjust the dimensions or text of UI components in the `setup()` method.

---

## Future Enhancements

- Can like setup the API and fetch words from there 
- Add a timer for each round.
- Implement levels of difficulty (e.g., easy, medium, hard).
- Enable multiplayer mode.
- Add animations for UI transitions.


---

## Credits

- **Developer**: 'Riyansh'
- **Libraries Used**: `bobcat_ui`
