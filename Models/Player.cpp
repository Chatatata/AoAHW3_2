//
//  Player.cpp
//  AoAHW3_2
//
//  Created by Buğra Ekuklu on 27.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "Player.hpp"

Player::Player(const UInt64 id,
               const UInt64 charismaPoint)
: DOMElement(id, charismaPoint)
{
    //  Empty implementation
}


UInt64
Player::getID() const noexcept
{
    return index;
}


UInt64
Player::getCharismaPoint() const noexcept
{
    return data;
}
