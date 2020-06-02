#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V3.hpp"
#include "Huffman_encoding.hpp"
using namespace std;
int main()
{
    string input_name = "1.pgm", output_name = "new_pic.pgm", encoded_pgm = "encoded_pgm.txt", freq = "freq.txt", decoded_pgm = "decoded_pgm.txt";
    pgm read_pic;
    cout << pgmb_read(input_name, read_pic) << " ERRORS,SUCCESSFUL READ <3" << endl;
    unordered_map<int, int> frequencyTable;
    buildFreqTable(read_pic.data, frequencyTable);
     unordered_map<int, int> tempTable;
    for (int i = 0; i < 256; i++)
        if (frequencyTable.count(i))
            tempTable[i] = frequencyTable[i];

    frequencyTable = tempTable;
    Huffman compressor;
    auto codes = compressor.Encode(frequencyTable);
    serializePgm(read_pic, codes, encoded_pgm);
    serializeFreq(frequencyTable, freq);

    //*******************************************************
    pgm write_pic;
    Huffman decompressor;
    string encodedData = "";
    deserializePgm(encoded_pgm, write_pic, encodedData);
    unordered_map<int, int> dFrequencyTable;
    deserializeFreq(freq, dFrequencyTable);
  //  auto dCodes = decompressor.Encode(frequencyTable);
   /* for(int i=0;i<256;++i)
    if(dCodes[i]!=codes[i]) cout<<dCodes[i]<<" "<<codes[i]<<endl;*/
   write_pic.data = decompressor.Decode(encodedData, dFrequencyTable);
     // cout<<write_pic.data.size()<<endl;
   cout << pgmb_write(output_name, write_pic) << " ERRORS,SUCCESSFUL WRITE <3" << endl;
   /* for(int i=0;i<256;++i)
    cout<<frequencyTable[i]<<":"<<dFrequencyTable[i]<<endl;
    cout<<frequencyTable.size()<<endl<<dFrequencyTable.size()<<endl;*/
    /* for (auto &x : codes)
        cout << x.first << ":" << x.second << " ";*/
    /*for (auto &x : frequencyTable)
        cout << x.first << ":" << x.second << " ";*/
    return 0;
}