#include <bits/stdc++.h>
using namespace std;
void deseriallizePgm(string readFile)
{
    ifstream deseriallize;
    deseriallize.open(readFile);
    if (!deseriallize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }
    //deseriallzing width and height
    string height = "";
    string height_final_bits = "";
    string width = "";
    string width_final_bits = "";

    for (int i = 0; i < 4; i++)
    {
        deseriallize.get(height[i]);
        int temp_h = (int)height[i];
        bitset<8> height_bits(temp_h);
        height_final_bits += height_bits.to_string();
    }
    bitset<32> final_height(height_final_bits);
    int HEIGHT = (int)final_height.to_ulong();

    //***************************************************

    for (int i = 0; i < 4; i++)
    {
        deseriallize.get(width[i]);
        int temp_w = (int)width[i];
        bitset<8> width_bits(temp_w);
        width_final_bits += width_bits.to_string();
    }
    bitset<32> final_width(width_final_bits);
    int WIDTH = (int)final_width.to_ulong();
    //deseriallizing the max grey value
    char max_grey;
    deseriallize.get(max_grey);
    int temp_grey = (int)max_grey;
    bitset<8> grey_bits(temp_grey);
    int MAX_GREY = (int)grey_bits.to_ulong();
    //deseriallizing padding bits
    char padding;
    deseriallize.get(padding);
    int temp_padding = (int)padding;
    bitset<8> padding_bits(temp_padding);
    string st_padding_bits;
    st_padding_bits += padding_bits.to_string();
    int padding_size = st_padding_bits.size();
    //deseriallize the data
    char data;
    string data_final_bits = "";
    while (deseriallize.get(data))
    {
        int temp_data = (int)data;
        bitset<8> data_bits(temp_data);
        int DATA = (int)data_bits.to_ulong();
        data_final_bits += to_string(DATA);
    }
    data_final_bits.erase(data_final_bits.end() - padding_size);
    // cout << HEIGHT << " " << WIDTH << " " << temp_grey << " " << MAX_GREY << " " << data_final_bits << endl;
    deseriallize.close();
}
//deseriallzing the frequency table
void deseriallize_freq(string readfile)
{
    ifstream deseriallize;
    deseriallize.open(readfile);
    if (!deseriallize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }
    char data;
    unordered_map<int, int> frequencytabale;
    for (int i = 0; i < 256; i++)
    {
        deseriallize.get(data);
        int temp_data = (int)data;
        bitset<8> data_bits(temp_data);
        int DATA = (int)data_bits.to_ullong();
        frequencytabale[i] = DATA;
        //  cout<<frequencytabale[i]<<" ";
    }
    cout << endl;
    deseriallize.close();
}