#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V3.hpp"
#include "Huffman_encoding.hpp"
using namespace std;
int main()
{
    string input_name = "NORMAL2-IM-1442-0001.pgm", output_name = "new_pic.pgm", encoded_pgm = "encoded_pgm.txt", freq = "freq.txt", decoded_pgm = "decoded_pgm.txt";
    pgm read_pic;
    cout << pgmb_read(input_name, read_pic) << " ERRORS,SUCCESSFUL READ <3" << endl;
    //  cout<< pgmb_write(output_name, pic);

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
    string encodedData = "";
    deserializePgm( encoded_pgm, write_pic, encodedData);
    unordered_map<int, int> dFrequencyTable;
    deserializeFreq(freq, dFrequencyTable);
   write_pic.data=compressor.Decode(encodedData,dFrequencyTable);
  cout << pgmb_write(output_name, write_pic) << " ERRORS,SUCCESSFUL WRITE <3" << endl;
   /* for(int i=0;i<256;++i)
    {
        if(frequencyTable[i]!=dFrequencyTable[i])   cout<<"meshtmamm"<<" ";
  */  
    /*for (auto &x : codes)
        cout << x.first << ": " << x.second << '\n';*/

    return 0;
}