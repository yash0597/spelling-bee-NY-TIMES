

#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/window.h>
#include <bobcat_ui/button.h>
#include <bobcat_ui/textbox.h>
#include <bobcat_ui/input.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>

namespace bobcat {

class Application : public Application_ {
    // UI Components
    Window* window;

    // Main Menu
    TextBox* titleText;
    Button* playButton;
    Button* instructionsButton;
    Button* statsButton;
    Button* quitButton;

    // Instructions Screen
    TextBox* instructionsText;
    Button* backToMenuButtonInstructions;

    // Gameplay Screen
    TextBox* gameTitle;
    TextBox* scrambledText;
    TextBox* hintText;
    TextBox* scoreText;
    TextBox* statusText;
    Input* guessInput;
    Button* submitGuessButton;
    Button* giveUpButton;
    Button* hintButton;
    Button* backToMenuButtonGameplay;
    std::vector<Button*> letterButtons;

    // Game Summary Screen
    TextBox* summaryText;
    Button* replayButton;
    Button* backToMenuButtonSummary;

    // Statistics Screen
    TextBox* statsText;
    Button* clearStatsButton;
    Button* backToMenuButtonStats;

    // Game State
    std::vector<std::string> validWords;
    std::vector<std::string> guessedWords; // Stores correctly guessed words

    std::string currentWord;
    std::string scrambledWord;
    std::string wordFile = "words.txt";
    std::string statsFile = "stats.csv";
    int score = 0;
    int totalRounds = 0;  // Track the total number of rounds
    bool hintUsed = false;
    int roundNumber = 1; // Starts with Round 1


    // Current View
    std::string view;

    // void setup() {
    //     // Initialize Window
    //     window = new Window(100, 100, 700, 600, "Word Scramble Game");

    //     // Main Menu
    //     titleText = new TextBox(200, 50, 300, 50, "Word Scramble Game");
    //     titleText->labelsize(24);

    //     playButton = new Button(250, 150, 200, 50, "Play Game");
    //     instructionsButton = new Button(250, 220, 200, 50, "View Instructions");
    //     statsButton = new Button(250, 290, 200, 50, "View Statistics");
    //     quitButton = new Button(250, 360, 200, 50, "Quit");

    //     // Instructions
    //     instructionsText = new TextBox(50, 50, 600, 400,
    //                                    "Welcome to the Word Scramble Game!\n\n"
    //                                    "Rules:\n"
    //                                    "1. Unscramble the letters to form valid words.\n"
    //                                    "2. Use only the given letters.\n"
    //                                    "3. Scoring is based on word length:\n"
    //                                    "   - 3-letter word: 1 point\n"
    //                                    "   - 4-letter word: 2 points\n"
    //                                    "   - 5+ letter word: 3 points\n\n"
    //                                    "Hints: Use the 'Hint' button to reveal a single letter.\n"
    //                                    "Good luck!");
    //     backToMenuButtonInstructions = new Button(250, 470, 200, 50, "Back to Main Menu");

    //     // Gameplay
    //     // gameTitle = new TextBox(250, 30, 200, 50, "Scrambled Word Game");
    //     scrambledText = new TextBox(50, 100, 600, 50, "Scrambled Letters: ___");
    //     hintText = new TextBox(50, 150, 600, 50, "Hint: No hints given yet.");
    //     scoreText = new TextBox(50, 200, 600, 50, "Score: 0");
    //     statusText = new TextBox(50, 250, 600, 50, "");
    //     guessInput = new Input(250, 310, 200, 40);
    //     submitGuessButton = new Button(150, 380, 150, 50, "Submit Guess");
    //     giveUpButton = new Button(330, 380, 150, 50, "Give Up");
    //     hintButton = new Button(500, 380, 150, 50, "Hint");
    //     backToMenuButtonGameplay = new Button(250, 450, 200, 50, "Back to Main Menu");

    //     // Game Summary
    //     summaryText = new TextBox(50, 50, 600, 400, "");
    //     replayButton = new Button(150, 470, 150, 50, "Play Again");
    //     backToMenuButtonSummary = new Button(330, 470, 200, 50, "Back to Main Menu");

    //     // Statistics
    //     statsText = new TextBox(50, 50, 600, 400, "Game Statistics:\nNo data available.");
    //     clearStatsButton = new Button(250, 470, 200, 50, "Clear Statistics");
    //     backToMenuButtonStats = new Button(250, 530, 200, 50, "Back to Main Menu");

    //     // Callback Assignments
    //     ON_CLICK(playButton, handleNavigationClick);
    //     ON_CLICK(instructionsButton, handleNavigationClick);
    //     ON_CLICK(statsButton, handleNavigationClick);
    //     ON_CLICK(quitButton, handleNavigationClick);
    //     ON_CLICK(backToMenuButtonInstructions, handleNavigationClick);
    //     ON_CLICK(backToMenuButtonGameplay, handleNavigationClick);
    //     ON_CLICK(backToMenuButtonSummary, handleNavigationClick);
    //     ON_CLICK(submitGuessButton, handleGameplayClick);
    //     ON_CLICK(giveUpButton, handleGameplayClick);
    //     ON_CLICK(hintButton, handleHintClick);
    //     ON_CLICK(replayButton, handleReplayClick);
    //     ON_CLICK(clearStatsButton, handleStatsClick);
    //     ON_CLICK(backToMenuButtonStats, handleNavigationClick);

    //     // Start at Main Menu
    //     view = "menu";
    //     updateDisplay();
    // }
    
    void setup() {
    // Initialize Window
    window = new Window(100, 100, 700, 600, "Word Scramble Game");

    // Main Menu
    titleText = new TextBox(250, 50, 200, 50, "Word Scramble Game");
    titleText->labelsize(24); // Larger title for emphasis
    titleText->align(FL_ALIGN_CENTER); // Centered alignment

    playButton = new Button(275, 150, 150, 40, "Play Game");
    instructionsButton = new Button(275, 210, 150, 40, "Instructions");
    statsButton = new Button(275, 270, 150, 40, "Statistics");
    quitButton = new Button(275, 330, 150, 40, "Quit");

    // Instructions Screen
    instructionsText = new TextBox(50, 50, 600, 400,
                                   "Welcome to the Word Scramble Game!\n\n"
                                   "Rules:\n"
                                   "1. Unscramble the letters to form valid words.\n"
                                   "2. Use only the given letters.\n"
                                   "3. Scoring is based on word length:\n"
                                   "   - 3-letter word: 1 point\n"
                                   "   - 4-letter word: 2 points\n"
                                   "   - 5+ letter word: 3 points\n\n"
                                   "Hints: Use the 'Hint' button to reveal a single letter.\n"
                                   "Good luck!");
    instructionsText->align(FL_ALIGN_TOP_LEFT); // Align text to the top left
    instructionsText->box(FL_NO_BOX); // Remove the border

    backToMenuButtonInstructions = new Button(275, 470, 150, 40, "Main Menu");

    // Gameplay Screen
    scrambledText = new TextBox(200, 80, 300, 50, "Scrambled Letters: ___");
    scrambledText->labelsize(18); // Make the scrambled word more prominent
    scrambledText->align(FL_ALIGN_CENTER);

    hintText = new TextBox(200, 140, 300, 30, "Hint: No hints given yet.");
    hintText->labelsize(14);
    hintText->align(FL_ALIGN_CENTER);

    scoreText = new TextBox(50, 20, 150, 30, "Score: 0");
    scoreText->labelsize(14);

    statusText = new TextBox(200, 180, 300, 30, "");
    statusText->labelsize(14);
    statusText->align(FL_ALIGN_CENTER);

    guessInput = new Input(200, 230, 300, 30);
    guessInput->align(FL_ALIGN_CENTER);

    submitGuessButton = new Button(150, 290, 120, 40, "Submit");
    giveUpButton = new Button(290, 290, 120, 40, "Give Up");
    hintButton = new Button(430, 290, 120, 40, "Hint");

    backToMenuButtonGameplay = new Button(275, 370, 150, 40, "Main Menu");

    // Game Summary
    summaryText = new TextBox(100, 100, 500, 300, "");
    summaryText->align(FL_ALIGN_CENTER);

    replayButton = new Button(150, 450, 120, 40, "Play Again");
    backToMenuButtonSummary = new Button(330, 450, 150, 40, "Main Menu");

    // Statistics Screen
    statsText = new TextBox(50, 50, 600, 400, "Game Statistics:\nNo data available.");
    statsText->align(FL_ALIGN_TOP_LEFT);

    clearStatsButton = new Button(200, 470, 150, 40, "Clear Stats");
    backToMenuButtonStats = new Button(380, 470, 150, 40, "Main Menu");

    // Callback Assignments
    ON_CLICK(playButton, handleNavigationClick);
    ON_CLICK(instructionsButton, handleNavigationClick);
    ON_CLICK(statsButton, handleNavigationClick);
    ON_CLICK(quitButton, handleNavigationClick);
    ON_CLICK(backToMenuButtonInstructions, handleNavigationClick);
    ON_CLICK(backToMenuButtonGameplay, handleNavigationClick);
    ON_CLICK(backToMenuButtonSummary, handleNavigationClick);
    ON_CLICK(submitGuessButton, handleGameplayClick);
    ON_CLICK(giveUpButton, handleGameplayClick);
    ON_CLICK(hintButton, handleHintClick);
    ON_CLICK(replayButton, handleReplayClick);
    ON_CLICK(clearStatsButton, handleStatsClick);
    ON_CLICK(backToMenuButtonStats, handleNavigationClick);

    // Start at Main Menu
    view = "menu";
    updateDisplay();
}


    void loadWords() {
        validWords.clear();
        std::ifstream file(wordFile);
        std::string word;
        while (file >> word) {
            validWords.push_back(word);
        }
        std::shuffle(validWords.begin(), validWords.end(), std::default_random_engine(std::time(0)));
        currentWord = validWords.front();
        scrambledWord = scrambleWord(currentWord);
    }

    std::string scrambleWord(const std::string& word) {
        std::string scrambled = word;
        std::shuffle(scrambled.begin(), scrambled.end(), std::default_random_engine(std::time(0)));
        return scrambled;
    }

    void saveStatistics(bool win) {
    std::ofstream file(statsFile, std::ios::app);
    file << "Round " << roundNumber << ": " << (win ? "Win" : "Loss")
         << ", Score: " << score
         << ", Word: " << currentWord
         << ", Hint Used: " << (hintUsed ? "Yes" : "No") << "\n";
    file.close();

    roundNumber++; // Increment the round number for the next game
}


//    void resetGame() {
//     score = 0;
//     hintUsed = false;
//     guessedWords.clear(); // Clear previous guesses
//     hintText->label("Hint: No hints given yet."); // Reset hint text
//     loadWords(); // Load a new set of words
// }
     void resetGame() {
    score = 0; // Reset the score
    hintUsed = false; // Reset the hint usage flag
    guessedWords.clear(); // Clear any previously guessed words

    // Reset all relevant UI components
    hintText->label("Hint: No hints given yet."); // Reset the hint text
    statusText->label(""); // Clear the "Correct word was..." or other status messages

    // Load a new set of words
    loadWords();
    if (!validWords.empty()) {
        currentWord = validWords.front(); // Set the first word
        scrambledWord = scrambleWord(currentWord); // Scramble the new word
    }
}


    void displayGameSummary(bool win) {
    saveStatistics(win); // Save round stats
    std::string summary = "Game Over!\n";
    summary += win ? "You won!\n" : "You gave up!\n";
    summary += "Final Score: " + std::to_string(score) + "\n";
    summary += "The correct word was: " + currentWord + "\n"; // Show the correct word
    summaryText->label(summary.c_str());
    
    // Reset hint for the next round
    hintText->label("Hint: No hints given yet.");
    hintUsed = false;

    view = "summary";
    updateDisplay();
}


    void updateDisplay() {
        hideAll();
        if (view == "menu") {
            titleText->show();
            playButton->show();
            instructionsButton->show();
            statsButton->show();
            quitButton->show();
        } else if (view == "instructions") {
            instructionsText->show();
            backToMenuButtonInstructions->show();
        } else if (view == "game") {
            // gameTitle->show();
            scrambledText->label(("Scrambled Letters: " + scrambledWord).c_str());
            scrambledText->show();
            hintText->show();
            scoreText->label(("Score: " + std::to_string(score)).c_str());
            scoreText->show();
            statusText->show();
            guessInput->show();
            guessInput->value("");
            submitGuessButton->show();
            giveUpButton->show();
            hintButton->show();
            backToMenuButtonGameplay->show();
        } else if (view == "summary") {
            summaryText->show();
            replayButton->show();
            backToMenuButtonSummary->show();
        } else if (view == "stats") {
            statsText->show();
            clearStatsButton->show();
            backToMenuButtonStats->show();
        }
    }

    void hideAll() {
        titleText->hide();
        playButton->hide();
        instructionsButton->hide();
        statsButton->hide();
        quitButton->hide();
        instructionsText->hide();
        backToMenuButtonInstructions->hide();
        scrambledText->hide();
        hintText->hide();
        scoreText->hide();
        statusText->hide();
        guessInput->hide();
        submitGuessButton->hide();
        giveUpButton->hide();
        hintButton->hide();
        backToMenuButtonGameplay->hide();
        summaryText->hide();
        replayButton->hide();
        backToMenuButtonSummary->hide();
        statsText->hide();
        clearStatsButton->hide();
        backToMenuButtonStats->hide();
    }

    void handleNavigationClick(Widget* sender) {
        if (sender == playButton) {
            resetGame();
            view = "game";
        } else if (sender == instructionsButton) {
            view = "instructions";
        } else if (sender == statsButton) {
            view = "stats";
            displayStatistics();
        } else if (sender == quitButton) {
            window->hide();
        } else {
            view = "menu";
        }
        updateDisplay();
    }

    // void handleGameplayClick(Widget* sender) {
    //     if (sender == submitGuessButton) {
    //         std::string guess = guessInput->value();
    //         if (guess == currentWord) {
    //             score += guess.length() < 4 ? 1 : (guess.length() == 4 ? 2 : 3);
    //             displayGameSummary(true);
    //         } else {
    //             statusText->label("Incorrect. Try again.");
    //         }
    //     } else if (sender == giveUpButton) {
    //         statusText->label(("The correct word was: " + currentWord).c_str());
    //         displayGameSummary(false);
    //     }
    //     updateDisplay();
    // }
     
//     void handleGameplayClick(Widget* sender) {
//     if (sender == submitGuessButton) {
//         std::string guess = guessInput->value();
//         if (guess == currentWord) {
//             // Correct guess logic
//             score += guess.length() < 4 ? 1 : (guess.length() == 4 ? 2 : 3);
//             guessedWords.push_back(guess); // Add to guessed words
//             statusText->label("Correct! Here's the next word.");

//             // Load a new word
//             validWords.erase(std::remove(validWords.begin(), validWords.end(), currentWord), validWords.end());
//             if (!validWords.empty()) {
//                 currentWord = validWords.front();
//                 scrambledWord = scrambleWord(currentWord);
//                 hintUsed = false;
//                 updateDisplay(); // Refresh display for the new word
//             } else {
//                 // No more words left
//                 statusText->label("You completed all words! Click 'Give Up' to end the game.");
//             }
//         } else {
//             statusText->label("Incorrect. Try again.");
//         }
//     } else if (sender == giveUpButton) {
//         // End the game and show summary
//         statusText->label(("The correct word was: " + currentWord).c_str());
//         displayGameSummary(false);
//     }
//     updateDisplay();

// }
   void handleGameplayClick(Widget* sender) {
    if (sender == submitGuessButton) {
        std::string guess = guessInput->value();
        if (guess == currentWord) {
            // Correct guess logic
            score += guess.length() < 4 ? 1 : (guess.length() == 4 ? 2 : 3);
            guessedWords.push_back(guess); // Add to guessed words
            statusText->label("Correct! Here's the next word.");

            // Load a new word
            validWords.erase(std::remove(validWords.begin(), validWords.end(), currentWord), validWords.end());
            if (!validWords.empty()) {
                currentWord = validWords.front();
                scrambledWord = scrambleWord(currentWord);
                hintUsed = false;
                hintText->label("Hint: No hints given yet."); // Reset hint section
                updateDisplay(); // Refresh display for the new word
            } else {
                // No more words left
                statusText->label("You completed all words! Click 'Give Up' to end the game.");
            }
        } else {
            statusText->label("Incorrect. Try again.");
        }
    } else if (sender == giveUpButton) {
        // End the game and show the correct word
        statusText->label(("The correct word was: " + currentWord).c_str());
        displayGameSummary(false);
    }
    updateDisplay();
}



    void handleHintClick(Widget* sender) {
        if (!hintUsed) {
            hintUsed = true;
            hintText->label(("Hint: " + currentWord.substr(0, 1) +
                             std::string(currentWord.length() - 1, '_')).c_str());
        } else {
            showMessage("Hint already used!");
        }
    }

    void handleReplayClick(Widget* sender) {
        resetGame();
        view = "game";
        updateDisplay();
    }

   void handleStatsClick(Widget* sender) {
    if (sender == clearStatsButton) {
        std::ofstream file(statsFile, std::ios::trunc); // Clear the statistics file
        file.close();
        statsText->label("Game Statistics:\nNo data available.");
        roundNumber = 1; // Reset the round number
    }
    updateDisplay();
}

    


    void displayStatistics() {
        std::ifstream file(statsFile);
        std::string stats, line;
        stats = "Game Statistics:\n";
        while (std::getline(file, line)) {
            stats += line + "\n";
        }
        file.close();
        if (stats == "Game Statistics:\n") {
            stats += "No data available.";
        }
        statsText->label(stats.c_str());
    }

public:
    Application() {
         roundNumber = 1;
        setup();
        window->show();
    }
};

}

#endif

