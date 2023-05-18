//
// Created by Yonatan Rappoport on 14/05/2023.
//

// ****************************** Poem *********************************

// Me: "Just one more bug to go!"; <bug fixed>; Me: "1024 bugs... I love my life choices"


// ************************ Includes ***********************************

#include "Card.h"
#include "Player.h"
#include "utilities.h"


// ************************* Implementation ****************************

Card::Card(CardType type, const CardStats& stats) :
        m_effect(type),
        m_stats(stats)
{

}



void Card::applyEncounter(Player& player) const {

    switch (m_effect) {
        case CardType::Battle:
            if (player.getAttackStrength() >= m_stats.force) {
                // Victory! :)
                printBattleResult(true);
                player.levelUp();
                player.addCoins(m_stats.loot);
            }
            else {
                // Loss... :(
                printBattleResult(false);
                player.damage(m_stats.cost);
            }
            break;

        case CardType::Buff:
            if (player.pay(m_stats.cost)) {
                // In this case the player pays the price, and subsequently gets the buff
                player.buff(m_stats.buff);
            }
            break;

        case CardType::Heal:
            if(player.pay(m_stats.cost)) {
                // In this case the player pays the price, then he is subsequently healed
                player.heal(m_stats.heal);
            }
            break;

        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;

        default:
            break;
    }

}

void Card::printInfo() const {


    // The card's information prints depending on its type (m_effect) and stats (m_stats)

    switch (m_effect) {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;

        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;

        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;

        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;

        default:
            break;
    }

}