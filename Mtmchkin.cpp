//
// Created by Yonatan Rappoport on 14/05/2023.
//


// ****************************** Poem *********************************

// Code's strength comes from comment's consistent lengths. Spit gold bars till 90 chars!


// **************************** Includes *******************************

#include "Mtmchkin.h"
#include "Player.h"
#include "Card.h"


// ************************* Implementation ****************************

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
        m_player(Player(playerName)), // Set m_player with appropriate Player constructor
        m_gameStatus(GameStatus::MidGame), // Set m_gameStatus to the game status MidGame
        m_deck((Card*)malloc(sizeof(Card) * numOfCards)), // Memory allocation for m_deck
        m_cardNum(numOfCards), // Set m_cardNum to the num of cards given with numOfCards
        m_card(0) // Set m_card to the 1st card position to draw from the deck which is 0
{

    for (int i = 0; i < numOfCards; i++) {
        m_deck[i] = cardsArray[i]; // Copy cardsArray's content to m_deck with copy c'tor
    }

}

void Mtmchkin::playNextCard() {

    (*m_deck).printInfo(); // Print the top card information using the appropriate method
    (*m_deck).applyEncounter(m_player); // Preform the top card's encounter on the player
    m_player.printInfo(); // Print the player's information using the .printInfo() method

    // Iterate to the next card, both the top card (m_deck++) and the position (m_card++)
    m_deck++;
    m_card++;

    // If we reach the end of the deck, nullify m_card and rewind m_deck to its beginning
    if (m_card == m_cardNum) {
        m_card = 0;
        m_deck -= m_cardNum;
    }
}

bool Mtmchkin::isOver() const {
    // Return a statement that is true if either of the two game ending conditions is met
    return (m_player.getLevel() == 10 || m_player.isKnockedOut());
}

GameStatus Mtmchkin::getGameStatus() const {
    if (!isOver()) {
        // !isOver => the game is continuing => the game is still in MidGame, using logic
        return GameStatus::MidGame;
    }

    if (m_player.getLevel() == 10) {
        // The player reached the 10th level, and thus has fulfilled all winning criteria
        return GameStatus::Win;
    }

    if(m_player.isKnockedOut()) {
        // The player is knocked out which indicates he has zero HP and has lost the game
        return GameStatus::Loss;
    }

    // This will never be reached, because one of the three conditions above must be true
    return GameStatus::Loss;
}

