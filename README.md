# Tic-Tac-Toe AI Game

This is a Tic-Tac-Toe game implementation with an artificial intelligence player written in C using the mini-max algorithm. The game allows a player to play against the AI, where the player always starts first and plays as X.

## How to Play

### Clone the repo

```bash
git clone https://github.com/henrish0/jogo-da-velha.git
```

### Build the project

```bash
cd jogo-da-velha/
./scripts/build.sh
```

Run the game

```bash
./velha
```

You can also see **[releases](https://github.com/henrish0/jogo-da-velha/releases)** for the compiled Windows version.

## Game Rules

- The game is played on a 3x3 grid.
- The player starts first and plays as X.
- The AI plays as O.
- Players take turns placing their mark on an empty cell in the grid.
- The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the game.
- If all cells are filled and no player has won, the game is a tie.
- The starting player alternates between games, so the AI plays next.

## How the AI Works

The AI player uses the mini-max algorithm to determine the best move to make at any given time. The algorithm works by simulating all possible moves that the AI and the player can make from the current state of the game, and choosing the move that maximizes the AI's chances of winning (or minimizes the player's chances of winning, if the AI cannot win).

The AI player assigns a score to each possible move, with a higher score indicating a better move. The score is calculated recursively by simulating all possible moves from the current state of the game and evaluating each resulting state. The evaluation function assigns a score to each state based on how likely it is that the AI will win from that state.
