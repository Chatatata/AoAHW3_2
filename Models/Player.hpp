//
//  Player.hpp
//  AoAHW3_2
//
//  Created by Buğra Ekuklu on 27.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "DOMElement.hpp"

class Player : public DOMElement {
public:
    Player(const UInt64 id = 0, const UInt64 charismaPoint = 0);
    
    //  NOTE: There is no need to dispatch destructor dynamically.
    
    UInt64 getID() const noexcept;
    UInt64 getCharismaPoint() const noexcept;
};
