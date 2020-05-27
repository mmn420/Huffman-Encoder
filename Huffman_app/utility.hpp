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