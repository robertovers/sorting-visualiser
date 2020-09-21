//
//  sortvis.cpp
//  SortingVisualiser
//
//  Created by Robert Overs on 3/9/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#include "sortvis.hpp"

using namespace std;


// MAIN FUNCTIONS

// draw

void SortVis::draw()
{
    window.clear(sf::Color(50, 50, 50));
    
    for (int i=0; i<=num_bars; i++) {
        int v = arr[i];
        float col = (float(v)/float(height))*250;
        rectangle.setSize(sf::Vector2f(width / num_bars, v));
        rectangle.setPosition(i*(width / num_bars), height - v);
        rectangle.setFillColor(sf::Color(250-col, col, 115));
        window.draw(rectangle);
    }
    
    window.display();
}

// generate array

vector<int> SortVis::randArray()
{
    vector<int> arr;
    for (int i=0; i<=num_bars; i++) {
        arr.push_back(i*(height / num_bars)*0.9);
    }
    
    random_shuffle(arr.begin(), arr.end());
    
    return arr;
}


// SORTING FUNCTIONS

// selection sort

void SortVis::selectionSort(int i)
{
        int curMin = getMin(i);
        swap(arr[i], arr[curMin]);
        draw();
}

int SortVis::getMin(int k)
{
    int min = k;
    for (int i=k; i<arr.size(); i++) {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}

// insertion sort

void SortVis::insertionSort(int i)
{
        insert(i);
}

void SortVis::insert(int k)
{
    while (k > 0 && arr[k-1] > arr[k]) {
        swap(arr[k-1], arr[k]);
        k--;
        draw();
    }
}

// heap sort

void SortVis::insertInplace(int k)
{
    int cur = k;
    int parent = (cur - 1) / 2;
    while (cur > 0 && arr[parent] < arr[cur]) {
        swap(arr[cur], arr[parent]);
        cur = parent;
        parent = (parent - 1) / 2;
        draw();
    }
}

void SortVis::extractMaxInplace(int k)
{
    if (k >= 1) {
        swap(arr[0], arr[k]);
    }
    int cur = 0;
    int next = maxChild(cur);
    while (next != -1 && next < k && arr[cur] < arr[next]) {
        swap(arr[cur], arr[next]);
        cur = next;
        next = maxChild(cur);
        draw();
    }
    draw();
}

int SortVis::maxChild(int v)
{
    int left = 2 * v + 1;
    int right = 2 * v + 2;
    if (left > arr.size()-1) {
        return -1;
    }
    else if (left == arr.size()-1) {
        return left;
    }
    else {
        if (arr[left] > arr[right]) {
            return left;
        }
        return right;
    }
}

// radix sort

void SortVis::radixSort(int i)
{
    countSort(i);
}

void SortVis::countSort(int e)
{
    int n = int(arr.size());
    int key;
    vector<int> arrCopy = arr;
    vector<int> output;
    vector<int> count;
    vector<int> pos;

    for (int i=0; i<n; i++) {
        output.push_back(0);
        count.push_back(0);
        pos.push_back(0);
    }

    for (int i=0; i<n; i++) {
        key = arrCopy[i]/e%base;
        count[key]++;
    }

    for (int i=1; i<base; i++) {
        pos[i] = pos[i-1] + count[i-1];
    }

    for (int i=0; i<n; i++) {
        key = arrCopy[i]/e%base;
        arr[pos[key]] = arrCopy[i];
        pos[key]++;
        draw();
    }
}

int SortVis::getMax()
{
    int max = arr[0];
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// bubble sort

void SortVis::bubbleSort(int i)
{
    for (int j=0; j<arr.size()-i-1; j++) {
        if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
        draw();
    }
}

