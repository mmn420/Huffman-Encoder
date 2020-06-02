#ifndef PGMB_IO_V3
#define PGMB_IO_V3
/*
0000000000000000000000000010101111110100000000000000000000000000
0000000000000000000000101110101010010111110000000000000000000000
0000000000000000000011101000100011010000100100000000000000000000
0000000000000000011110101011111000011110101110100000000000000000
0000000000000000110000001010000011110000101010110000000000000000
0000000000000010011011111011101110100101100010010100000000000000
0000000000000111001001000000101000111100110110110110000000000000
0000000000011111101101101110111011100001100100100011100000000000
0000000000111111111111000010000010001011001101101001110000000000 
0000000001111111111111111111101111111001111001111111111000000000
0000000011111111111111111111111111111111111111111111111100000000
0000000111111111111111111111111111111111111111111111111110000000        
0000000111111111111111111111111111111111111111111111111110000000
0000001111111111111111111111111111111111111111111111111111000000 
0000011111111111111111111111111111111111111111111111111111100000
0000111111111111111111111111111111111111111111111111111111110000
0001111111111111111111111111111111111111111111111111111111111000
0000011111111111111111111111111111111111111111111111111111111000
0000000111111111111000100111111111111110001010111111111111100000
0011000001111111110010001111111111111110100000001111111100000000
0011110000011111000110100011111111111111101101100101100000001100
0111111100000100011100111001111111111101001000110000000001111110                
0111111111000001001001101100011111111101101111100100001111111110
0111111111111011011100000111001111111000100100001110111111111110
0111111111000001000111011100011111111010111110100010010111111110
1111111111110111010010010001001111110010010000110111000111111111
1111111111100010010110111011101111010111011110011100010111111111
1111111111101111110111100001001010000101001011110001110111111111
1111111111100000100100111011100010101101101001000100100111111111
1111111111110110111101101110001011100000111101011111101111111111
1111111111100011100100100011101001110111100101110001000111111111
1111111111111000001101110110111011000001001101100100010111111111
1111111111111101101000010100001010010101101000110110111111111111
1111111111110000111101010101011110110100101110011100011111111111
1111111111111010010001110001111000100110000100110001111111111111
1111111111111111000111000101101101101100101110100100111111111111
1111111111111111110001011111100000111111100010001111111111111111
0111111111111111100100001111101011111111111000100111111111111110
0111111111111111111111111111111000011111111111111111111111111110
0111111111111111111111111111010010111111111111111111111111111110
0111111111111111111111111101000111111111111111111111111111111110
0011111111111111111111111100010001111111111111111111111111111100
0011111110011111111111111111110111111111111111111111111111111100
0001111111010111111111111111100011111111111111111111101111111000
0001111111000100011111111111001011111111111011111010000111111000
0001111111010101001010001101011001010010110001100000101111111000
0000111111110001100000100000001100011000000101001110111111110000
0000011111110100111101111011100111000011101111101011111111100000
0000011111111110100100100010111101110110100000100011111111100000
0000001111111100001101101000010001010000111010001111111111000000
0000000111111111011000111110110101000101100011111111111110000000
0000000111111111001110010100011100010111001000111111111110000000
0000000011111111100011110001110110111101111011111111111100000000
0000000001111111110110000101000000100001011111111111111000000000
0000000000111111111111010111101101101011001111111111110000000000
0000000000011111111111110000111100001000011111111111100000000000
0000000000000111111111111111111110111111111111111110000000000000
0000000000000011111111111111111111111111111111111100000000000000
0000000000000000111111111111111111111111111111110000000000000000
0000000000000000011111111111111111111111111111100000000000000000
0000000000000000000011111111111111111111111100000000000000000000
0000000000000000000000111111111111111111110000000000000000000000
0000000000000000000000000011111111111100000000000000000000000000
*/
#include <bits/stdc++.h>
#include "utility.hpp"
using namespace std;
//*****************************************************************************
//
//                          Function Declarations
//
//*****************************************************************************
bool pgmb_check_data(pgm pic);
//*****************************************************************************
bool pgmb_read(string input_name, pgm &pic);
bool pgmb_read_data(ifstream &input, pgm &pic);
bool pgmb_read_header(ifstream &file_in, pgm &pic);
//*****************************************************************************
bool pgmb_write(string file_out_name, pgm pic);
bool pgmb_write_data(ofstream &file_out, pgm pic);
bool pgmb_write_header(ofstream &file_out, pgm pic);
//*****************************************************************************
//
//                          Functions Definitions
//
//*****************************************************************************
bool pgmb_check_data(pgm pic)
//
//  Purpose:
//
//    PGMB_CHECK_DATA checks the data for a binary portable gray map file.
//
//  Parameters:
//
//    input, pgm pic, a struct containing the following:
//
//      Input, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//      Input, int &MAXG, the maximum gray value.
//
//      Input, vector<int> &data, the vector containing pixel values of size XSIZE by YSIZE.
//
//    Output, bool PGMB_CHECK_DATA, is
//    true, if an error was detected, or
//    false, if the data was legal.
//
{
    int i;

    if (pic.xsize <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << "  xsize <= 0.\n";
        cout << "  xsize = " << pic.xsize << "\n";
        return true;
    }

    if (pic.ysize <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << "  ysize <= 0.\n";
        cout << "  ysize = " << pic.ysize << "\n";
        return true;
    }

    if (pic.data.size() <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << " Empty vector.\n";
        return true;
    }

    for (i = 0; i < pic.data.size(); i++)
    {
        if (pic.maxg < pic.data[i])
        {
            cout << "\n";
            cout << "PGMB_CHECK_DATA - Fatal error!\n";
            cout << "  Data exceeds MAXG = " << pic.maxg << "\n";
            cout << "  Pixel("
                 << "," << i << ")=" << pic.data[i] << "\n";
            return true;
        }
    }

    return false;
}
//*****************************************************************************
bool pgmb_read(string input_name, pgm &pic)
//
//  Purpose:
//
//    PGMB_READ reads the header and data from a binary portable gray map file.
//
//  Parameters:
//
//    Input, string INPUT_NAME, the name of the file containing the binary
//    portable gray map data.
//
//    Output, pgm &pic, a struct containing the following:
//
//      Output, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//      Output, int &MAXG, the maximum gray value.
//
//      Output, vector<int> &data, the vector containing pixel values of size XSIZE by YSIZE.
//
//    Output, bool PGMB_READ, is true if an error occurred.
//
{
    bool error;
    ifstream input;

    input.open(input_name, ios::binary);

    if (!input.is_open()) // TODO: how (!input) still works
    {
        cout << "\n";
        cout << "PGMB_READ: Fatal error!\n";
        cout << "  Cannot open the input file " << input_name << "\n";
        return true;
    }
    //
    //  Read the header.
    //
    error = pgmb_read_header(input, pic);

    if (error)
    {
        cout << "\n";
        cout << "PGMB_READ: Fatal error!\n";
        cout << "  PGMB_READ_HEADER failed.\n";
        return true;
    }
    //
    //  Read the data.
    //
    error = pgmb_read_data(input, pic);

    if (error)
    {
        cout << "\n";
        cout << "PGMB_READ: Fatal error!\n";
        cout << "  PGMB_READ_DATA failed.\n";
        return true;
    }
    //
    //  Close the file.
    //
    input.close();

    return false;
}
//*****************************************************************************
bool pgmb_read_data(ifstream &input, pgm &pic)
//
//  Purpose:
//
//    PGMB_READ_DATA reads the data in a binary portable gray map file.
//
//  Parameters:
//
//    Input, ifstream &INPUT, a pointer to the file containing the binary
//    portable gray map data.
//
//    Input/Output, pgm &pic, a struct containing the following:
//
//      Input, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//      Input, int &MAXG, the maximum gray value.
//
//      Output, vector<int> &data, the vector containing pixel values of size XSIZE by YSIZE.
//
//    Output, bool PGMB_READ_DATA, is true if an error occurred.
//
{
    bool error;
    char c;
    unsigned char uc;

    for (int j = 0; j < pic.ysize; j++)
    {
        for (int i = 0; i < pic.xsize; i++)
        {
            input.read(&c, 1);
            uc = (unsigned char)c;
            pic.data.push_back((int)uc);
            error = input.eof();
            if (error)
            {
                cout << "\n";
                cout << "PGMB_READ_DATA - Fatal error!\n";
                cout << "  End of file reading pixel ("
                     << i << ", " << j << ") \n";
                return true;
            }
        }
    }
    return false;
}
//*****************************************************************************
bool pgmb_read_header(ifstream &input, pgm &pic)
//
//  Purpose:
//
//    PGMB_READ_HEADER reads the header of a binary portable gray map file.
//
//  Parameters:
//
//    Input, ifstream &INPUT, a pointer to the file containing the binary
//    portable gray map data.
//
//    Output, pgm &pic, a struct containing the following:
//
//      Output, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//      Output, int &MAXG, the maximum gray value.
//
//    Output, bool PGMB_READ_HEADER, is true if an error occurred.
//
{
    int fred;
    string line;
    string rest;
    int step;
    string word;

    step = 0;

    while (1)
    {
        getline(input, line);

        if (input.eof())
        {
            cout << "\n";
            cout << "PGMB_READ_HEADER - Fatal error!\n";
            cout << "  End of file.\n";
            return true;
        }

        if (line[0] == '#')
        {
            continue;
        }

        if (step == 0)
        {
            s_word_extract_first(line, word, rest);

            if (s_len_trim(word) <= 0)
            {
                continue;
            }

            if (!s_eqi(word, "P5"))
            {
                cout << "\n";
                cout << "PGMB_READ_HEADER - Fatal error.\n";
                cout << "  Bad magic number = \"" << word << "\".\n";
                return true;
            }
            line = rest;
            step = 1;
        }

        if (step == 1)
        {
            s_word_extract_first(line, word, rest);

            if (s_len_trim(word) <= 0)
            {
                continue;
            }
            pic.xsize = atoi(word.c_str());
            line = rest;
            step = 2;
        }

        if (step == 2)
        {
            s_word_extract_first(line, word, rest);

            if (s_len_trim(word) <= 0)
            {
                continue;
            }
            pic.ysize = atoi(word.c_str());
            line = rest;
            step = 3;
        }

        if (step == 3)
        {
            s_word_extract_first(line, word, rest);

            if (s_len_trim(word) <= 0)
            {
                continue;
            }
            fred = atoi(word.c_str());
            pic.maxg = fred;
            line = rest;
            break;
        }
    }

    return false;
}
//*****************************************************************************
bool pgmb_write(string output_name, pgm pic)
//
//  Purpose:
//
//    PGMB_WRITE writes the header and data for a binary portable gray map file.
//
//  Parameters:
//
//    Input, string OUTPUT_NAME, the name of the file to contain the binary
//    portable gray map data.
//
//    Input, pgm pic, a struct containing the following:
//
//      Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//      Input, vector<int> data, the vector containing pixel values of size XSIZE by YSIZE.
//
//      Input, int MAXG, the maximum gray value.
//
//    Output, bool PGMB_WRITE, is true if an error occurred.
//
{
    bool error;
    ofstream output;
    //
    //  Open the file.
    //
    output.open(output_name, ios::binary);

    if (!output.is_open())
    {
        cout << "\n";
        cout << "PGMB_WRITE: Fatal error!\n";
        cout << "  Cannot open the output file " << output_name << "\n";
        return true;
    }
    //
    //  Write the header.
    //
    error = pgmb_write_header(output, pic);

    if (error)
    {
        cout << "\n";
        cout << "PGMB_WRITE: Fatal error!\n";
        cout << "  PGMB_WRITE_HEADER failed.\n";
        return true;
    }
    //
    //  Write the data.
    //
    error = pgmb_write_data(output, pic);

    if (error)
    {
        cout << "\n";
        cout << "PGMB_WRITE: Fatal error!\n";
        cout << "  PGMB_WRITE_DATA failed.\n";
        return true;
    }
    //
    //  Close the file.
    //
    output.close();

    return false;
}
//*****************************************************************************
bool pgmb_write_data(ofstream &output, pgm pic)
//
//  Purpose:
//
//    PGMB_WRITE_DATA writes the data for a binary portable gray map file.
//
//  Parameters:
//
//    Input, ofstream &OUTPUT, a pointer to the file to contain the binary
//    portable gray map data.
//
//    Input, pgm pic, a struct containing the following:
//
//      Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//      Input, vector<int> data, the vector containing pixel values of size XSIZE by YSIZE.
//
//      Input, int MAXG, the maximum gray value.
//
//    Output, bool PGMB_WRITE_DATA, is true if an error occurred.
//
{
    unsigned char c;
    int i;
    for (i = 0; i < pic.data.size(); i++)
        output.put((char)pic.data[i]); // TODO: why bitset<8> doesn't work like char.

    return false;
}
//*****************************************************************************
bool pgmb_write_header(ofstream &output, pgm pic)
//
//  Purpose:
//
//    PGMB_WRITE_HEADER writes the header of a binary portable gray map file.
//
//  Parameters:
//
//    Input, ofstream &OUTPUT, a pointer to the file to contain the binary
//    portable gray map data.
//
//    Input, pgm pic, a struct containing the following:
//
//      Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//      Input, vector<int> data, the vector containing pixel values of size XSIZE by YSIZE.
//
//      Input, int MAXG, the maximum gray value.
//
//    Output, bool PGMB_WRITE_HEADER, is true if an error occurred.
//
{
    output << "P5"
           << endl
           << pic.xsize << " "
           << pic.ysize  << endl
           << pic.maxg << endl;

    return false;
}
#endif