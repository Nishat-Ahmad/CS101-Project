# Casino

## Overview
This project consists of multiple casino games, including Blackjack, Baccarat, Slot Machine, and Deal or No Deal. The games are implemented in C++ and provide a console-based interface for users to interact with. The starting balance for the player is $10,000. The goal is to manage your earnings effectively.

## Files and Structure
- `main.cpp`: This is the entry point of the application where the user is prompted to choose a game to play.
- `BlackJack.h`: Contains the implementation of the Blackjack game.
- `Baccarat.h`: Contains the implementation of the Baccarat game.
- `SlotMachine.h`: Contains the implementation of the Slot Machine game.
- `DealOrNoDeal.h`: Contains the implementation of the Deal or No Deal game.
- `UserInterface.h`: Contains helper functions for displaying rules and the welcome message.

## Dependencies
- C++ standard libraries: `<iostream>`, `<cstdlib>`, `<ctime>`, `<string>`, `<windows.h>`, `<algorithm>`, `<list>`, `<iomanip>`

## How to Play

### Main Menu
Upon starting the program, you will be presented with a main menu where you can choose which game to play:
- Enter `1` to play Blackjack.
- Enter `2` to play Slot Machine.
- Enter `3` to play Baccarat.
- Enter `4` to play Deal or No Deal.
- Enter `0` to exit the program.

### Blackjack
1. You start with a bet and the goal is to beat the dealer without exceeding 21.
2. You can `Hit` to draw another card or `Stand` to keep your current hand.
3. The game compares your hand with the dealer's to determine the winner.

### Baccarat
1. Place a bet on either the Player, Dealer, or a Draw.
2. The game deals two cards each to the Player and the Dealer.
3. Depending on the total points, additional cards may be drawn.
4. The winner is determined based on the hand closest to 9.

### Slot Machine
1. Place a bet and spin the slot machine.
2. The game displays a grid of symbols.
3. Payout is determined based on matching symbols.

### Deal or No Deal
1. Choose a case that contains a random amount of money.
2. Open other cases to reveal their amounts.
3. Receive offers from the banker and decide whether to accept the deal or continue opening cases.
4. The game continues until you either accept an offer or all cases are opened.

## Game Rules
Detailed rules for each game can be accessed within the program by choosing the appropriate options in the main menu.

## Authors
@HassanIqbal715 wrote

Enjoy playing!
