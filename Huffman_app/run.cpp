#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V3.hpp"
#include "Huffman_encoding.hpp"
#include "deseriallize.hpp"
using namespace std;
int main()
{
    string input_name = "NORMAL2-IM-1442-0001.pgm", output_name = "NORMAL2-IM-1427-0001.pgm", encoded_pgm = "encoded_pgm.txt",freq_table="yarabb", decoded_pgm="test.txt"; 
    pgm pic;
    cout << pgmb_read(input_name, pic) << " ERRORS,SUCCESSFUL READ <3" << endl;
    //  cout<< pgmb_write(output_name, pic);


    unordered_map<int, int> frequencyTable;
    buildFreqTable(pic.data, frequencyTable);
    Huffman compressor;
    auto codes = compressor.Encode(frequencyTable);
    serializePgm(pic,codes,encoded_pgm);
    Deseriallize_pgm(encoded_pgm);
  /*for (auto &x : codes)
        cout << x.first << ": " << x.second << '\n';*/


    return 0;
}