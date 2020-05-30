#include <bits/stdc++.h>
using namespace std;
void Deseriallize_pgm(string filename)
{
    ifstream deseriallize;
    deseriallize.open(filename);
    if (!deseriallize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }
    //deseriallzing width and height
        string height = "";
        string height_final_bits = "";
    for (int i = 0; i < 4; i++)
    {
        deseriallize.get(height[i]);
        int temp_h = (int) height[i];
        bitset<8> height_bits(temp_h);
        height_final_bits += height_bits.to_string();
    }
    bitset<32> final_height(height_final_bits);
    int HEIGHT = (int) final_height.to_ulong();
    string width = "";
    cout<<HEIGHT<<endl;
    deseriallize.close();
   /* for (i = 0; i < 4; i++) 
    {
        deseriallize.get(width[i]);
    } */
}
