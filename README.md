# TicTacToe

A console-based two-player Tic-Tac-Toe game written in C++.

## How to Play

Run `TicTacToe.exe`. Players take turns placing **X** and **O** on a 3×3 board. On your turn, enter the row number (1–3) and column letter (A–C), for example: `1 A`.

The game ends when a player gets three in a row (horizontally, vertically, or diagonally) or the board is full (draw).

## Files

| File | Description |
|------|-------------|
| `TicTacToe.h`  | Board class declaration |
| `TicTacToe.cpp` | Implementation and `main()` |
| `TicTacToe.hpp` | Single-header implementation (alternative) |
| `minimax.cpp`   | Placeholder for AI logic |
| `TicTacToe.exe` | Pre-built executable |

## Build

Compile with any C++ compiler:

```bash
g++ TicTacToe.cpp -o TicTacToe.exe
```
