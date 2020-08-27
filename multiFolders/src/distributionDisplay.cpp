#include <iostream>
#include <new>

#include "Distribution.h"


void distributionDsipaly(int* P_set1, int long sampleLength, int uplimit)
{

        // display the distribution 
    for (int long i=0; i<50; ++i) 
        std::cout << P_set1[i] << "  ";
    std::cout << std::endl;

    int* p;
    p = new int [uplimit];
    //new int p[uplimit]={};

    for (int long i=0; i<sampleLength; ++i) 
    {
        int number = P_set1[i];
        if (number<uplimit) ++p[number];
    }

    // p[i]/nrolls is the probability of getting intege 'i'; 
    const int nstars = 100;   // maximum number of stars to distribute
    for (int i=0; i<uplimit; ++i)
        std::cout << i << ": " << std::string(p[i]*nstars/sampleLength,'*') << std::endl;
    
    delete[] p;

}

