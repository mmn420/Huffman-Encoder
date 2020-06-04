#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V3.hpp"
#include "Huffman_encoding.hpp"
using namespace std;

int main(int argc, char *argv[])
{

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

        string imageNameNoExtension = imageName.substr(0, imageName.length() - 4);

        pgm read_pic;
        int errorCount = pgmb_read(imageName, read_pic);
        if (errorCount)
        {
            cout << errorCount << " errors encountered\n";
            return -1;
        }

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
        //To calculate the files sizes
        ifstream compressedImage_size(imageNameNoExtension + ".enc", ios::binary);
        compressedImage_size.seekg(0, ios::end);
        int CompressedImageSize = compressedImage_size.tellg();
        ifstream OriginalImage_size(imageNameNoExtension + ".pgm", ios::binary);
        OriginalImage_size.seekg(0, ios::end);
        int OriginalImageSize = OriginalImage_size.tellg();
        float Compression_Ratio = ((float)OriginalImageSize/(float)CompressedImageSize);
        cout<<"Size Before= "<< OriginalImageSize<<endl<<"Size After ="<<CompressedImageSize<<endl<<"The Compression Ratio is " <<Compression_Ratio<<endl;

    }
    //*******************************************************
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

        string encoded_pgm;
        string freq;
        string output_name;

        freq = argv[flagPos + 1];

        encoded_pgm = (flagPos == 1) ? argv[3] : argv[1];

        if (encoded_pgm.length() < 4 || freq.length() < 4)
        {
            cout << "Bad file name\n";
            return -1;
        }

        if (encoded_pgm.substr(encoded_pgm.length() - 4, 4) != ".enc" || freq.substr(freq.length() - 4, 4) != ".frq")
        {
            cout << "Invalid file extension\n";
            return -1;
        }

        output_name = encoded_pgm.substr(0, encoded_pgm.length() - 4) + ".pgm";

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
        int errorCount = pgmb_write(output_name, write_pic);
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
    /* for(int i=0;i<256;++i)
    cout<<frequencyTable[i]<<":"<<dFrequencyTable[i]<<endl;
    cout<<frequencyTable.size()<<endl<<dFrequencyTable.size()<<endl;*/
    /* for (auto &x : codes)
        cout << x.first << ":" << x.second << " ";*/
    /*for (auto &x : frequencyTable)
        cout << x.first << ":" << x.second << " ";*/
}