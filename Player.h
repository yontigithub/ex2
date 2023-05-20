//
// Created by Yonatan Rappoport on 11/05/2023.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>

class Player {
public:
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int x);
    void heal(int x);
    void damage(int x);
    bool isKnockedOut() const;
    void addCoins(int x);
    bool pay(int x);
    int getAttackStrength() const;

    Player(const std::string &name, int maxHP, int force);
    Player(const std::string &name, int maxHP);
    Player(const std::string &name);
    ~Player();
    Player(const Player& player);


private:
    std::string m_name;
    int m_level, m_force, m_maxHp, m_HP, m_coins;
};

#endif //EX2_PLAYER_H
