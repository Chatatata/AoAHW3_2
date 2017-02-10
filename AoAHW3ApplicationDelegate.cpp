//
//  AoAHW3ApplicationDelegate.cpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "AoAHW3ApplicationDelegate.hpp"

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

#include "Models/Player.hpp"
#include "Strategies/HeapSortStrategy.cpp"

UInt16
AoAHW3ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    using StringStream = std::stringstream;
    using InputFileStream = std::ifstream;
    using OutputFileStream = std::ofstream;
    using HighResolutionClock = std::chrono::high_resolution_clock;
    using Container::Array;
    
    if (arguments.getLength() == 3) {
        Array<Player> array;
        
        InputFileStream inputFile("ClanA.txt");
        OutputFileStream outputFile("A_sorted.txt");
        String feed;
        UInt64 inputLength = std::stoll(arguments[2]);
        
        for (UInt64 i = 0; !inputFile.eof() && i < inputLength; ++i) {
            inputFile >> feed;
            inputFile >> feed;
            
            array.append(Player(i, std::stoll(feed)));
        }
        
        HeapSortStrategy<Player> hss(array);
        
        auto startTime = HighResolutionClock::now();
        
        hss.sort();
        
        auto endTime = HighResolutionClock::now();
        
        printf("Heap sort duration: %llu nanoseconds\n", std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count());
        
        for (UInt64 i = 0; i < hss.getArray().getLength() - 1; ++i) {
            outputFile
            << hss.getArray()[i].getID()
            << "\t"
            << hss.getArray()[i].getCharismaPoint()
            << std::endl;
        }
            
        return 0;
    } else if (arguments.getLength() == 2) {
        fprintf(stderr, "not implemented\n");
        
        return 1;
    } else {
        fprintf(stderr, "wrong number of input argument(s), expected 1 or 2\n");
        
        return 9;
    }
}




















