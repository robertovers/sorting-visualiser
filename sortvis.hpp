//
//  sortvis.hpp
//  SortingVisualiser
//
//  Created by Robert Overs on 3/9/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#ifndef sortvis_hpp
#define sortvis_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class SortVis
{
public:
    
    // methods
    
    void vis();
    
    void draw();
    
    vector<int> randArray();
    
    // selection sort
    
    void selectionSort(int i);
    
    int getMin(int k);
    
    // insertion sort
    
    void insertionSort(int i);
    
    void insert(int k);
    
    // heap sort
    
    void insertInplace(int k);

    void extractMaxInplace(int k);

    int maxChild(int v);
    
    // radix sort
    
    void radixSort(int i);
    
    void countSort(int e);
    
    int getMax();
    
    int maxNum;
    
    int base = 10;
    
    // bubble sort
    
    void bubbleSort(int i);
    
    // variables
    
    int width = 800;
    
    int height = 600;
    
    int num_bars = 200;
    
    int sortType = 0;
    
    int it = 0;
    
    int it2 = 0;
    
    vector<int> arr = randArray();
    
    // objects
    
    sf::RenderWindow window{sf::VideoMode(width, height), "Sort Vis"};
    
    sf::RectangleShape rectangle{sf::Vector2f(0, 0)};
    
};

#endif /* sortvis_hpp */
