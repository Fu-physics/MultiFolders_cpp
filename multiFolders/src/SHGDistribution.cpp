// poisson_distribution
#include <iostream>
#include <random>
#include "Distribution.h"



 
/*
-------------------------------   Possion Distribution --------------------------------------------------------
*/
void SHGDistribution(int long sampleLength, int* P_PumpDistribution, int* P_SHGDistribution)
{
    double alpha = 0.000'001; //1.0e-6;
    //double beta = 1.0e-6;
    std::cout << "int(alpha):  " << int(alpha) << std::endl;

    for (int long i = 0; i < sampleLength; i++)
    {
       // std::cout << i << "; " << sampleLength << std::endl;

        P_SHGDistribution[i] = uniform(P_PumpDistribution[i], alpha);
 
       // std::cout << P_SHGDistribution[i] << std::endl;
 
    }
    // std::cout << "End of SHG " << std::endl;

}