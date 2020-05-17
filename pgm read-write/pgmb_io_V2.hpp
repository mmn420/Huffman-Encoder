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
TODO:THIS VERSION IS DEVELOPED, REVISED & TESTED BY GeekMind2000 
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
// TODO: Change functions' names to be more self-describing, Edit documentation, Create a namespace for Utility functions & enhance it.
#include <bits/stdc++.h>
using namespace std;
//  Function Declarations
//****************************************************************************80
bool pgmb_check_data(int xsize, int ysize, unsigned char maxg, vector<int> &data);
//****************************************************************************80
bool pgmb_read(string input_name, int &xsize, int &ysize, unsigned char &maxg, vector<int> &data);
bool pgmb_read_data(ifstream &input, int xsize, int ysize, vector<int> &data);
bool pgmb_read_header(ifstream &file_in, int &xsize, int &ysize, unsigned char &maxg);
//****************************************************************************80
bool pgmb_write(string file_out_name, int xsize, int ysize, vector<int> &data);
bool pgmb_write_data(ofstream &file_out, int xsize, int ysize, vector<int> &data);
bool pgmb_write_header(ofstream &file_out, int xsize, int ysize, unsigned char maxg);
//****************************************************************************80
bool s_eqi(string s1, string s2);
int s_len_trim(string s);
void s_word_extract_first(string s, string &s1, string &s2);
char ch_cap(char ch);

//****************************************************************************80

char ch_cap(char ch)

//****************************************************************************80
//
//  Purpose:
//
//    CH_CAP capitalizes a single character.
//
//  Discussion:
//
//    This routine should be equivalent to the library "toupper" function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 July 1998
//
//  Author:
//
//    John Burkardt
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
//****************************************************************************80

bool pgmb_check_data(int xsize, int ysize, unsigned char maxg,
                     vector<int> &data)

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_CHECK_DATA checks the data for a binary portable gray map file.
//
//  Discussion:
//
//    XSIZE and YSIZE must be positive, the pointers must not be null,
//    and the data must be nonnegative and no greater than MAXG.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//    Input, unsigned char MAXG, the maximum gray value.
//
//    Input, unsigned char *G, the array of XSIZE by YSIZE data values.
//
//    Output, bool PGMB_CHECK_DATA, is
//    true, if an error was detected, or
//    false, if the data was legal.
//
{
    int i;

    if (xsize <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << "  xsize <= 0.\n";
        cout << "  xsize = " << xsize << "\n";
        return true;
    }

    if (ysize <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << "  ysize <= 0.\n";
        cout << "  ysize = " << ysize << "\n";
        return true;
    }

    if (data.size() <= 0)
    {
        cout << "\n";
        cout << "PGMB_CHECK_DATA: Error!\n";
        cout << " Empty vector.\n";
        return true;
    }

    for (i = 0; i < data.size(); i++)
    {
        if ((int)maxg < data[i])
        {
            cout << "\n";
            cout << "PGMB_CHECK_DATA - Fatal error!\n";
            cout << "  Data exceeds MAXG = " << (int)maxg << "\n";
            cout << "  Pixel("
                 << "," << i << ")=" << data[i] << "\n";
            return true;
        }
    }

    return false;
}
//****************************************************************************80

bool pgmb_read(string input_name, int &xsize, int &ysize,
               unsigned char &maxg, vector<int> &data) //TODO : make maxg an int instead of UC

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_READ reads the header and data from a binary portable gray map file.
//
//  Discussion:
//
//    Thanks to Jonas Schwertfeger for pointing out that, especially on
//    Microsoft Windows systems, a binary file needs to be opened as a
//    binary file!
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_NAME, the name of the file containing the binary
//    portable gray map data.
//
//    Output, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//    Output, unsigned char &MAXG, the maximum gray value.
//
//    Output, unsigned char **G, the array of XSIZE by YSIZE data values.
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
    error = pgmb_read_header(input, xsize, ysize, maxg);

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
    error = pgmb_read_data(input, xsize, ysize, data);

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
//****************************************************************************80

bool pgmb_read_data(ifstream &input, int xsize, int ysize, vector<int> &data)

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_READ_DATA reads the data in a binary portable gray map file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 December 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, ifstream &INPUT, a pointer to the file containing the binary
//    portable gray map data.
//
//    Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//    Output, unsigned char *G, the array of XSIZE by YSIZE data values.
//
//    Output, bool PGMB_READ_DATA, is true if an error occurred.
//
{
    bool error;
    int i;
    int j;
    char k;
    unsigned char l;

    for (j = 0; j < ysize; j++)
    {
        for (i = 0; i < xsize; i++)
        {
            input.read(&k, 1);
            l = (unsigned char)k;
            data.push_back((int)l);
            //   *indexg = (unsigned char)c;
            // indexg = indexg + 1;
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
//****************************************************************************80

bool pgmb_read_header(ifstream &input, int &xsize, int &ysize,
                      unsigned char &maxg)

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_READ_HEADER reads the header of a binary portable gray map file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, ifstream &INPUT, a pointer to the file containing the binary
//    portable gray map data.
//
//    Output, int &XSIZE, &YSIZE, the number of rows and columns of data.
//
//    Output, unsigned char &MAXG, the maximum gray value.
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
            xsize = atoi(word.c_str());
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
            ysize = atoi(word.c_str());
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
            maxg = (unsigned char)fred;
            line = rest;
            break;
        }
    }

    return false;
}
//****************************************************************************80
bool pgmb_write(string output_name, int xsize, int ysize, vector<int> &data)

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_WRITE writes the header and data for a binary portable gray map file.
//
//  Discussion:
//
//    Thanks to Jonas Schwertfeger for pointing out that, especially on Microsoft
//    Windows systems, a binary file needs to be opened as a binary file!
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string OUTPUT_NAME, the name of the file to contain the binary
//    portable gray map data.
//
//    Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//    Input, int *G, the array of XSIZE by YSIZE data values.
//
//    Output, bool PGMB_WRITE, is true if an error occurred.
//
{
    bool error;
    ofstream output;
    int i;
    int max_ = 0;
    unsigned char maxg;
    //
    //  Determine the maximum gray value.
    //
    for (i = 0; i < data.size(); i++)
        max_ = max(max_, data[i]);
    maxg = (unsigned char)max_;
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
    error = pgmb_write_header(output, xsize, ysize, maxg);

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
    error = pgmb_write_data(output, xsize, ysize, data);

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
//****************************************************************************80

bool pgmb_write_data(ofstream &output, int xsize, int ysize,
                     vector<int> &data)

//****************************************************************************80
//
//  Purpose:
//
//    PGMB_WRITE_DATA writes the data for a binary portable gray map file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 April 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, ofstream &OUTPUT, a pointer to the file to contain the binary
//    portable gray map data.
//
//    Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//    Input, unsigned char *G, the array of XSIZE by YSIZE data values.
//
//    Output, bool PGMB_WRITE_DATA, is true if an error occurred.
//
{
    unsigned char c;
    int i;
    for (i = 0; i < data.size(); i++)
    {
       c=(unsigned char) data[i]; // TODO: why bitset<8> doesn't work like char.
        output << c;
    }
    output<<endl;

    return false;
}
//****************************************************************************80
bool pgmb_write_header(ofstream &output, int xsize, int ysize,
                       unsigned char maxg)
//****************************************************************************80
//
//  Purpose:
//
//    PGMB_WRITE_HEADER writes the header of a binary portable gray map file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 April 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, ofstream &OUTPUT, a pointer to the file to contain the binary
//    portable gray map data.
//
//    Input, int XSIZE, YSIZE, the number of rows and columns of data.
//
//    Input, unsigned char MAXG, the maximum gray value.
//
//    Output, bool PGMB_WRITE_HEADER, is true if an error occurred.
//
{
    output << "P5"
           << " "
           << xsize << " "
           << ysize << " "
           << (int)maxg << endl;

    return false;
}
//****************************************************************************80
bool s_eqi(string s1, string s2)

//****************************************************************************80
//
//  Purpose:
//
//    S_EQI reports whether two strings are equal, ignoring case.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
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
//****************************************************************************80

int s_len_trim(string s)

//****************************************************************************80
//
//  Purpose:
//
//    S_LEN_TRIM returns the length of a string to the last nonblank.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
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
//****************************************************************************80

void s_word_extract_first(string s, string &s1, string &s2)

//****************************************************************************80
//
//  Purpose:
//
//    S_WORD_EXTRACT_FIRST extracts the first word from a string.
//
//  Discussion:
//
//    A "word" is a string of characters terminated by a blank or
//    the end of the string.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 October 2010
//
//  Author:
//
//    John Burkardt
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