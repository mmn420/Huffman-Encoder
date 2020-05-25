#include <bits/stdc++.h>
#include "utility.hpp"
#include "pgmb_io_V2.hpp"
using namespace std;
int main()
{
    cout << 5555555555;
    string input_name = "NORMAL2-IM-1440-0001.pgm", output_name = "NORMAL2-IM-1427-0001.pgm", comp_name = "yarab";
    cout << 5555555555;
    pgm pic;
    cout << 5555555555;
    cout << pgmb_read(input_name, pic);
    cout << 5555555555;
    comp(comp_name, pic);

    //  cout<< pgmb_write(output_name, xsize, ysize, data);

    //cout<<endl<<data.size()<<endl;
    // for(int i=0;i<data.size();++i) cout<<data[i]<<" ";
    // for(int i=0;i<data.size();++i) if(data[i]>255||data[i]<0) cout<<data[i]<<endl;
    //cout << xsize << " " << ysize << endl ;
    //for (int i = 0; i < data.size(); ++i) cout << data[i] << " ";

    return 0;
}