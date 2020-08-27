// poisson_distribution
#include <iostream>
#include <random>
#include "Distribution.h"



 
/*
-------------------------------   Possion Distribution --------------------------------------------------------
*/
void poisson(double mean, int long sampleLength, int* PpoissonDistribution)
{
    /* this wil set a random number for each call, which means that it will generate a different sample set for each called */
    std::random_device rd;
    std::mt19937 gen(rd());

    // number of experiments samples, sampleLength
    /* this wil set a same number for each call, which means that it will generate the same sample set for each called */
    // std::default_random_engine generator;  
    
    std::poisson_distribution<int> distribution(mean);

    for (int i=0; i<sampleLength; ++i, ++PpoissonDistribution) 
    {
        *PpoissonDistribution = distribution(gen);
        //std::cout << "i is: " << i << "; *PpossionDistribution is: " << *PpossionDistribution << std::endl;
    }
}

int uniform(int Mphoton, double eta)
{
    /* this wil set a random number for each call, which means that it will generate a different sample set for each called */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution <double> distribution(0.0,1.0);
    int temp = 0;
    for(int i=0; i< Mphoton; i++)
    {
        if(distribution(gen) < eta ) 
        {
            temp +=1;
        }
    }
    //std::cout << "temp is:" << temp << std::endl;
    return temp;
}

/*
-------------------------------   Other Distribution --------------------------------------------------------
*/