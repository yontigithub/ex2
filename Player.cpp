//
// Created by Yonatan Rappoport on 11/05/2023.
//

// ****************************** Poem *********************************

// I hate their love or lack thereof. why await pair doves to loop and swoop from above?


// **************************** Includes *******************************

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "utilities.h"


// TODO: change all char* to std::string

// ************************* Implementation ****************************

Player::Player(const std::string &name, const int maxHP, const int force) {

    // Inserts all the necessary parameter values given into the implicitly passed object

    this->m_name = std::string(name); // default for name if spaces in it?
    this->m_level = 1;

    if (force < 0) {
        this->m_force = 5;
    }
    else {
        this->m_force = force;
    }

    if (maxHP <= 0) {
        this->m_maxHp = 100;
        this->m_HP = 100;
    }
    else {
        this->m_maxHp = maxHP;
        this->m_HP = maxHP;
    }

    this->m_coins = 0;
}

Player::Player(const std::string &name, const int maxHP) :
        Player(name, maxHP, 5) // Aided by the previously implemented: Player constructor
{

}

Player::Player(const std::string &name) :
        Player(name, 100) // Yet again uses the existing constructor with passed argument
{

}

Player::~Player() {

}

Player::Player(const Player& p) :
        m_level(p.m_level), // Set object's level to the given level of parameter: player
        m_force(p.m_force), // Set object's force to the given force of parameter: player
        m_maxHp(p.m_maxHp), // Set object's maxHP to the given maxHP of parameter: player
        m_HP(p.m_HP),       // Set object's HP to equal the given HP of parameter: player
        m_coins(p.m_coins)  // Set object's coins to the given coins of parameter: player
{
    m_name = std::string(p.m_name); // Copy the given players name into the object's name
}


void Player::printInfo() const {
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp() {

    if (m_level < 10) {
        // If (m_level >= 10) than we've reached the limit and there's no need to levelUp
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(const int x) {
    if (x > 0) {
        m_force += x;
    }
}

void Player::heal(const int x) {
    if (x < 0) {
        return; // Can't be healed in negative amounts, so there's no need to continue on
    }
    m_HP = std::min(m_maxHp, m_HP + x); // The min() function keeps the HP to maxHP at maximum
}

void Player::damage(int x) {
    if (x < 0) {
        return; // Can't do damage in negative amounts, so there's no need to continue on
    }
    m_HP = std::max(0, m_HP - x); // The max() function is used to keep the HP to 0 at minimum
}

bool Player::isKnockedOut() const {
    return (m_HP == 0);
}

void Player::addCoins(int x) {
    if (x > 0) {
        m_coins += x;
    }
}

bool Player::pay(int x) {
    if (x > m_coins) {
        return false; // In this case the player doesn't have enough money to pay the fee
    }

    m_coins -= x; // Deduct x coins from the player's money sum, in order to pay the cost
    return true;
}

int Player::getAttackStrength() const {
    return m_level + m_force;
}