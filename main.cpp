//
//  main.cpp
//  SortingVisualiser
//
//  Created by Robert Overs on 2/9/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#include "sortvis.hpp"

using namespace std;


// main

int main()
{
    SortVis myVis;
    
    myVis.vis();
}

void SortVis::vis()
{
    
    // events

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    
                    // reset
                    if (event.key.code == sf::Keyboard::R)
                    {
                        it = 0;
                        arr = randArray();
                        sortType = 0;
                        break;
                    }
                    
                    // selection sort
                    if (event.key.code == sf::Keyboard::S)
                    {
                        window.setFramerateLimit(20);
                        
                        it = 0;
                        if (sortType != 0)
                            arr = randArray();
                        sortType = 1;
                        break;
                    }
                    
                    // insertion sort
                    if (event.key.code == sf::Keyboard::I)
                    {
                        window.setFramerateLimit(400);
                        
                        it = 0;
                        if (sortType != 0)
                            arr = randArray();
                        sortType = 2;
                        break;
                    }
                    
                    // heap sort
                    if (event.key.code == sf::Keyboard::H)
                    {
                        window.setFramerateLimit(150);
                        
                        it = 0;
                        it2 = int(arr.size())-1;
                        if (sortType != 0)
                            arr = randArray();
                        sortType = 3;
                        break;
                    }
                    
                    // radix sort
                    if (event.key.code == sf::Keyboard::X)
                    {
                        window.setFramerateLimit(150);
                        
                        it = 1;
                        if (sortType != 0)
                            arr = randArray();
                        sortType = 4;
                        break;
                    }
                    
                    // bubble sort
                    if (event.key.code == sf::Keyboard::B)
                    {
                        window.setFramerateLimit(600);
                        
                        it = 0;
                        if (sortType != 0)
                            arr = randArray();
                        sortType = 5;
                        break;
                    }
                    
                default:
                    break;
            }
        }
        
        // sort
        
        switch (sortType) {
                
            case -1:
                // sorted
                break;
                
            case 0:
                // unsorted
                draw();
                break;
                
            case 1:
                // selection sort
                if (it < arr.size()) {
                    selectionSort(it);
                    it++;
                } else {
                    it = 0;
                    sortType = -1;
                }
                break;
            
            case 2:
                // insertion sort
                if (it < arr.size()) {
                    insertionSort(it);
                    it++;
                } else {
                    it = 0;
                    sortType = -1;
                }
                break;
            
            case 3:
                // heap sort
                if (it < arr.size()) {
                    insertInplace(it);
                    it++;
                } else if (it2 >= 0) {
                    extractMaxInplace(it2);
                    it2--;
                } else {
                    it = 0;
                    it2 = 0;
                    sortType = -1;
                }
                break;
            
            case 4:
                // radix sort
                if (getMax()/it > 0) {
                    radixSort(it);
                    it *= base;
                } else {
                    it = 0;
                    sortType = -1;
                }
                break;
                
            case 5:
                // bubble sort
                if (it < arr.size()-1) {
                    bubbleSort(it);
                    it++;
                } else {
                    it = 0;
                    sortType = -1;
                }
                break;
                    
            default:
                break;
        }
    }
}
