#ifndef UTILITY
#define UTILITY
#include <bits/stdc++.h>
using namespace std;
//*****************************************************************************
// Functions declarations
bool s_eqi(string s1, string s2);
int s_len_trim(string s);
void s_word_extract_first(string s, string &s1, string &s2);
char ch_cap(char ch);
void buildFreqTable(vector<int> data, unordered_map<int, int> &frequencyTable);
//*****************************************************************************
struct pgm
//
//    Purpose:
//
//      struct pgm holds all the contents of a pgm file: header and pixel data.
//
//    Members:
//
//      int xsize,ysize , are the height and width of the picture.
//
//      int maxg , is the max value that a pixel value can get.
//
//      vector<int>data , contains the pixel data, of size xsize*ysize.
//
{
    int xsize, ysize, maxg;
    vector<int> data;
};
//*****************************************************************************
void buildFreqTable(vector<int> data, unordered_map<int, int> &frequencyTable)
//
//  Purpose:
//
//    buildFreqTable builds the frequency table needed for constructing huffman tree.
//
//  Parameters:
//
//    Input, vector<int> data, contaning the pixel values.
//
//    Output, unordered_map<int, int> &frequencyTable, containing the frequency table mapped as int to int.
//
{
    for (int i = 0; i < data.size(); ++i)
        frequencyTable[data[i]]++;
}
//*****************************************************************************
void serializePgm(pgm pic, unordered_map<int, string> codes, string fileName)
{
    string eight_bits = "";
    int padding_bits = 0;
    string eight_temp = "";
    int integer_bits = 0;
    char output_bits;
    ofstream serialize;

    serialize.open(fileName, std::ios::binary);

    if (!serialize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        //return;
    }

    // serialize the height and width in 4 bytes
    bitset<32> header_xsize(pic.xsize);
    bitset<32> header_ysize(pic.ysize);
    string h_xsize = header_xsize.to_string();
    string h_ysize = header_ysize.to_string();
    string temp_x = "", temp_y = "", final_x = "", final_y = "";

    for (int i = 0; i < 32; ++i)
    {
        temp_x += h_xsize[i];
        temp_y += h_ysize[i];
        if ((i + 1) % 8 == 0)
        {
            integer_bits = stoi(temp_x, 0, 2);
            final_x += char(integer_bits);
            integer_bits = stoi(temp_y, 0, 2);
            final_y += char(integer_bits);
            temp_x.clear();
            temp_y.clear();
        }
    }
    for (int i = 0; i < 4; ++i)
        serialize.put(final_x[i]);
    for (int i = 0; i < 4; ++i)
        serialize.put(final_y[i]);
    //serialize the max gray value in 1 byte.
    bitset<8> maxg_binary(pic.maxg);
    string max_value = maxg_binary.to_string();
    integer_bits = stoi(max_value, 0, 2);
    output_bits = (char)integer_bits;
    serialize.put(output_bits);
    // SERIALIZING PIXELS' DATA.
    for (int i = 0; i < pic.data.size(); ++i)
        eight_bits.append(codes[pic.data[i]]); //TODO OPTIMIZE, space complexity: HIGH
    //determinning the padding bits and writing it in the beginning of the data.
    padding_bits = 8 - ((eight_bits.size()) % 8);
    if (padding_bits < 8 && padding_bits > 0) //saving the number of the padding bits in the beginning of the data
    {
        output_bits = (char)padding_bits;
        serialize.put(output_bits);
    }

    for (int i = 0; i < eight_bits.size(); ++i)
    {
        eight_temp += eight_bits[i];
        if ((i + 1) % 8 == 0)
        {
            integer_bits = stoi(eight_temp, 0, 2);
            output_bits = (char)integer_bits;
            serialize.put(output_bits);
            eight_temp.clear();
        }
        if (padding_bits < 8 && padding_bits > 0 && i == eight_bits.size() - 1)
        {
            while (padding_bits--)
                eight_temp += "0";

            integer_bits = stoi(eight_temp, 0, 2);
            output_bits = (char)integer_bits;
            serialize.put(output_bits);
        }
    }
    serialize.close();
}
//*****************************************************************************
void serializeFreq(unordered_map<int, int> frequencyTable, string fileName)
{
    ofstream output;
    output.open(fileName, std::ios::binary);
    if (!output.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }

    string temp_freq = "", final_freq = "", string_freq = "";
    int integer_bits = 0;
    for (int i = 0; i < 256; ++i)
    {
        bitset<32> freq(frequencyTable[i]);
        string_freq = freq.to_string();

        for (int i = 0; i < 32; ++i)
        {
            temp_freq += string_freq[i];

            if ((i + 1) % 8 == 0)
            {
                integer_bits = stoi(temp_freq, 0, 2);
                output.put(char(integer_bits));
                temp_freq.clear();
            }
        }
    }
    output.close();
}
//*****************************************************************************
void deserializePgm(string readFile, pgm &pic, string &encodedData)
{
    ifstream deserialize;
    deserialize.open(readFile, std::ios::binary);
    if (!deserialize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }
    //deseriallzing width and height in four bytes each
    string height = "";
    string height_final_bits = "";
    string width = "";
    string width_final_bits = "";

    for (int i = 0; i < 4; i++)
    {
        deserialize.get(height[i]);
        int temp_h = (int)height[i];
        bitset<8> height_bits(temp_h);
        height_final_bits += height_bits.to_string();
    }
    bitset<32> final_height(height_final_bits);
    pic.xsize = (int)final_height.to_ulong();

    for (int i = 0; i < 4; i++)
    {
        deserialize.get(width[i]);
        int temp_w = (int)width[i];
        bitset<8> width_bits(temp_w);
        width_final_bits += width_bits.to_string();
    }
    bitset<32> final_width(width_final_bits);
    pic.ysize = (int)final_width.to_ulong();
    //deseriallizing the max grey value in one byte
    char max_grey;
    deserialize.get(max_grey);
    unsigned char uc = (unsigned char)max_grey;
    pic.maxg = (int)uc;
    //deseriallizing padding bits
    char char_padding;
    deserialize.get(char_padding);
    unsigned char uc_padding = (unsigned char)char_padding;
    int padding_bits = (int)uc_padding;
    //deseriallize the data
    char data;
    while (deserialize.get(data))
    {
        int temp_data = (int)data;
        bitset<8> data_bits(temp_data);
        encodedData += data_bits.to_string();
    }
    while (padding_bits--)
        encodedData.pop_back();
    //cout << pic.xsize << " " << pic.ysize << " " << pic.maxg << endl;
    deserialize.close();
}
//*****************************************************************************
//deseriallzing the frequency table
void deserializeFreq(string readfile, unordered_map<int, int> &frequencyTable)
{
    ifstream deserialize;
    deserialize.open(readfile, std::ios::binary);
    if (!deserialize.is_open())
    {
        cout << "FILE DID NOT OPEN PROPERLY" << endl;
        return;
    }

    char char_freq;
    int int_freq, freq;
    string str_freq = "";
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deserialize.get(char_freq);
            int_freq = (int)char_freq;
            bitset<8> bit_freq(int_freq);
            str_freq += bit_freq.to_string();
        }
        long long x = 0;
        for (int k = 0; k < 32; k++)
        {
            x <<= 1;
            x += (str_freq[k] == '0') ? 0 : 1;
        }
        if (x != 0)
            frequencyTable[i] = x;
        str_freq.clear();

    }
    deserialize.close();
}
int file_size(string file_name)
{
    ifstream fileSize(file_name, ios::binary);
    fileSize.seekg(0, ios::end);
    int size = fileSize.tellg();
    return size;
}
//*****************************************************************************
bool s_eqi(string s1, string s2)
//
//  Purpose:
//
//    S_EQI reports whether two strings are equal, ignoring case.
//
//  Parameters:
//
//    Input, string S1, S2, two strings.
//
//    Output, bool S_EQI, is true if the strings are equal.
//
{
    int i;
    int nchar;
    int s1_length;
    int s2_length;

    s1_length = s1.length();
    s2_length = s2.length();

    if (s1_length < s2_length)
    {
        nchar = s1_length;
    }
    else
    {
        nchar = s2_length;
    }
    //
    //  The strings are not equal if they differ over their common length.
    //
    for (i = 0; i < nchar; i++)
    {

        if (ch_cap(s1[i]) != ch_cap(s2[i]))
        {
            return false;
        }
    }
    //
    //  The strings are not equal if the longer one includes nonblanks
    //  in the tail.
    //
    if (nchar < s1_length)
    {
        for (i = nchar; i < s1_length; i++)
        {
            if (s1[i] != ' ')
            {
                return false;
            }
        }
    }
    else if (nchar < s2_length)
    {
        for (i = nchar; i < s2_length; i++)
        {
            if (s2[i] != ' ')
            {
                return false;
            }
        }
    }

    return true;
}
//*****************************************************************************
int s_len_trim(string s)
//
//  Purpose:
//
//    S_LEN_TRIM returns the length of a string to the last nonblank.
//
//  Parameters:
//
//    Input, string S, a string.
//
//    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
//    If S_LEN_TRIM is 0, then the string is entirely blank.
//
{
    int n;

    n = s.length();

    while (0 < n)
    {
        if (s[n - 1] != ' ')
        {
            return n;
        }
        n = n - 1;
    }

    return n;
}
//*****************************************************************************
void s_word_extract_first(string s, string &s1, string &s2)
//
//  Purpose:
//
//    S_WORD_EXTRACT_FIRST extracts the first word from a string.
//
//  Parameters:
//
//    Input, string S, the string.
//
//    Output, string &S1, the first word (initial blanks removed).
//
//    Output, string &S2, the remainder of the string, after removing
//    the first word (initial blanks removed).
//
{
    int i;
    int mode;
    int s_len;

    s_len = s.length();
    s1 = "";
    s2 = "";
    mode = 1;

    for (i = 0; i < s_len; i++)
    {
        if (mode == 1)
        {
            if (s[i] != ' ')
            {
                mode = 2;
            }
        }
        else if (mode == 2)
        {
            if (s[i] == ' ')
            {
                mode = 3;
            }
        }
        else if (mode == 3)
        {
            if (s[i] != ' ')
            {
                mode = 4;
            }
        }
        if (mode == 2)
        {
            s1 = s1 + s[i];
        }
        else if (mode == 4)
        {
            s2 = s2 + s[i];
        }
    }

    return;
}
//*****************************************************************************
char ch_cap(char ch)
//
//  Purpose:
//
//    CH_CAP capitalizes a single character.
//
//  Parameters:
//
//    Input, char CH, the character to capitalize.
//
//    Output, char CH_CAP, the capitalized character.
//
{
    if (97 <= ch && ch <= 122)
    {
        ch = ch - 32;
    }

    return ch;
}
//*****************************************************************************

#endif