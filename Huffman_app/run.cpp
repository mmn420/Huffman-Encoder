#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V2.hpp"
#include "Huffman_encoding.hpp"
using namespace std;
int main()
{
    string input_name = "NORMAL2-IM-1440-0001.pgm", output_name = "NORMAL2-IM-1427-0001.pgm", comp_name = "yarab";
    pgm pic;
    cout << pgmb_read(input_name, pic)<<" ERRORS,SUCCESSFUL READ <3"<<endl;
    //  cout<< pgmb_write(output_name, xsize, ysize, data);

unordered_map<int, int> frequencyTable;
buildFreqTable( pic.data, frequencyTable);

    Huffman compressor;
    
    auto codes = compressor.Encode(frequencyTable);

    for (auto &x : codes)
        std::cout << x.first << ": " << x.second << '\n';
    return 0;
}