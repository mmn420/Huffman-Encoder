#ifndef UTILITY
#define UTILITY
#include <bits/stdc++.h>
using namespace std;
struct pgm
{
    int xsize, ysize;
    unsigned char maxg;
    vector<int> data;
};
//********************************************
void buildFreqTable(vector<int> data, unordered_map<int, int> &frequencyTable)
{
    for (int i = 0; i < data.size(); ++i)
        frequencyTable[data[i]]++;
}
#endif