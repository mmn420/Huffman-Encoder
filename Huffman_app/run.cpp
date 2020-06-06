#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V3.hpp"
#include "Huffman.hpp"
using namespace std;
//**********************************************************************

//*******************************README*********************************************************************
// To Compress type for example in terminal: ./a.out image_name.pgm
// To Decompress type for example in terminal: ./a.out -t image_name.frq image_name.enc
//*******************************README*********************************************************************

//***********************************************************************
struct fileName
{
    string imageNameNoExtension;
    string encoded_pgm;
    string freq;
    string output_name;
};
//***********************************************************************

//                      Functions Declarations

//***********************************************************************
void Compress(pgm &read_pic, string imageNameNoExtension);
void Decompress(pgm &write_pic, fileName &file_name);
//***********************************************************************

//                          Main Function

//***********************************************************************
int main(int argc, char *argv[])
{
    fileName file_name;
    if (argc == 2)
    {
        string imageName = argv[1];

        if (imageName.length() < 4)
        {
            cout << "Bad file name\n";
            return -1;
        }

        if (imageName.substr(imageName.length() - 4, 4) != ".pgm")
        {
            cout << "Invalid file extension\n";
            return -1;
        }

        file_name.imageNameNoExtension = imageName.substr(0, imageName.length() - 4);

        pgm read_pic;
        int errorCount = pgmb_read(imageName, read_pic);
        if (errorCount)
        {
            cout << errorCount << " errors encountered\n";
            return -1;
        }
        Compress(read_pic, file_name.imageNameNoExtension);
    }


    else if (argc == 4)
    {
        int flagPos = -1;

        for (int i = 1; i <= 3; i++)
            if (strcmp(argv[i], "-t") == 0)
                flagPos = i;

        if (flagPos == -1 || flagPos == 3)
        {
            cout << "Invalid arguments, did you forget/misplace -t flag?\n";
            return -1;
        }

        file_name.freq = argv[flagPos + 1];

        file_name.encoded_pgm = (flagPos == 1) ? argv[3] : argv[1];

        if (file_name.encoded_pgm.length() < 4 || file_name.freq.length() < 4)
        {
            cout << "Bad file name\n";
            return -1;
        }

        if (file_name.encoded_pgm.substr(file_name.encoded_pgm.length() - 4, 4) != ".enc" || file_name.freq.substr(file_name.freq.length() - 4, 4) != ".frq")
        {
            cout << "Invalid file extension\n";
            return -1;
        }

        file_name.output_name = file_name.encoded_pgm.substr(0, file_name.encoded_pgm.length() - 4) + ".pgm";
        
        pgm write_pic;
        Decompress(write_pic,file_name);
        int errorCount = pgmb_write(file_name.output_name, write_pic);
        if (errorCount)
        {
            cout << errorCount << " errors encountered\n";
            return -1;
        }
    }
    else
    {
        cout << "Invalid arguments specified\n";
    }
    return 0;
}
//***********************************************************************

//                      Functions Definitions

//***********************************************************************
void Compress(pgm &read_pic, string imageNameNoExtension)
{
    unordered_map<int, int> frequencyTable;
    buildFreqTable(read_pic.data, frequencyTable);
    unordered_map<int, int> tempTable;
    for (int i = 0; i < 256; i++)
        if (frequencyTable.count(i))
            tempTable[i] = frequencyTable[i];

    frequencyTable = tempTable;
    Huffman compressor;
    auto codes = compressor.Encode(frequencyTable);
    serializePgm(read_pic, codes, imageNameNoExtension + ".enc");
    serializeFreq(frequencyTable, imageNameNoExtension + ".frq");
    std::cout<<"Image compressed successfully"<<std::endl;
}
//***********************************************************************
void Decompress(pgm &write_pic, fileName &file_name)
{
    Huffman decompressor;
    string encodedData = "";
    deserializePgm(file_name.encoded_pgm, write_pic, encodedData);
    unordered_map<int, int> dFrequencyTable;
    deserializeFreq(file_name.freq, dFrequencyTable);
    write_pic.data = decompressor.Decode(encodedData, dFrequencyTable);
    std::cout<<"Successfull Decompression"<<std::endl;
}
//***********************************************************************