#include <bits/stdc++.h>
#include "pgmb_io_V2.hpp"
using namespace std;
int main()
{
    string input_name = "NORMAL2-IM-1440-0001.pgm", output_name = "NORMAL2-IM-1427-0001.pgm";
    int xsize, ysize;
    unsigned char maxg;
    vector<int> data;
    cout << pgmb_read(input_name, xsize, ysize, maxg, data) << endl;
    cout << xsize << " " << ysize << endl ;
    //for (int i = 0; i < data.size(); ++i) cout << data[i] << " ";
    cout << endl
         << pgmb_write(output_name, xsize, ysize, data);
    //cout<<endl<<data.size()<<endl;
    // for(int i=0;i<data.size();++i) cout<<data[i]<<" ";
    // for(int i=0;i<data.size();++i) if(data[i]>255||data[i]<0) cout<<data[i]<<endl;

    return 0;
}