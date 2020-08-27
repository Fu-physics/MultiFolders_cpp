#include <iostream>

#include "Distribution.h"

int correlation(int* P_set1, int* P_set2, int long sampleLength, int long tau)
{
    int cc = 0;
    for(int i = 0; i < sampleLength - tau; i++)
    {
        //std::cout << P_set1[i] * P_set2[i];
        cc = cc + P_set1[i] * P_set2[i + tau];

    }

return cc;

}