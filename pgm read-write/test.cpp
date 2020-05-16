#include <bits/stdc++.h>
#include "pgmb_io.hpp"
using namespace std;
int main()
{
    string input_name = "NORMAL2-IM-1440-0001.pgm", output_name = "gmdan";
    int xsize, ysize;
    unsigned char maxg, *g;
    cout << pgmb_read(input_name, xsize, ysize, maxg, &g) << pgmb_write(output_name, xsize, ysize, g);
    return 0;
}