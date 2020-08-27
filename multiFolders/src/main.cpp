// poisson_distribution
#include <iostream>
#include <random>
#include <fstream>

#include "Distribution.h"

int main()
{
    // ------------------------------------ distribution parameters setting --------------------------
    int long sampleLength = 1000;               // distribution sample size
    int set1[sampleLength];      // distribution array
    int set2[sampleLength];      // distribution array
    int* P_set1 = set1;   // pointer to distribution
    int* P_set2 = set2;   // pointer to distribution

    double meanSet1 = 1000;                          // average parameter for distribution generation
    double meanSet2 = 1000;                          // average parameter for distribution generation
    std::cout << "meanSet1 is: " << meanSet1 << std::endl;
    std::cout << "meanSet2 is: " << meanSet2 << std::endl;

    // -------------------------------------- generate the pump distribution --------------------------------
    // generate the distribution via pointer reference
    poisson(meanSet1, sampleLength, P_set1);
    poisson(meanSet2, sampleLength, P_set2);

    // display the distribution 
    distributionDsipaly( set1, sampleLength, 3);
    distributionDsipaly( set2, sampleLength, 3);

    //----------------------------------------- distribution display -----------------------------------

    int setSHG1[sampleLength];      // SHG distribution array
    int* P_setSHG1 = setSHG1;       // pointer to SHG distribution

    int setSHG2[sampleLength];      // SHG distribution array
    int* P_setSHG2 = setSHG2;       // pointer to SHG distribution

    SHGDistribution(sampleLength, set1, P_setSHG1);
    distributionDsipaly( setSHG1, sampleLength, 3);

    SHGDistribution(sampleLength, set1, P_setSHG2);
    distributionDsipaly( setSHG2, sampleLength, 3);

    //SHGDistribution(sampleLength, P_set2, P_setSHG2);
    //distributionDsipaly( P_setSHG2, sampleLength, 3);

    //------------------------------------------------- correlation ---------------------------------
    
    std::ofstream P_file;
    P_file.open("cc.dat");

    P_file << "#<P_set1*P_set1>" << ','<< "<P_set2*P_set2>" << ','<< "<P_set1*P_set2>" << std::endl;


    int cc;
    for (long int tau = 0; tau < 8; tau++)
    {
        std::cout <<"tau = " << tau << ' ';
        P_file <<"tau = " << tau << ' ';

        cc = correlation(P_setSHG1, P_setSHG1, sampleLength, tau);
        std::cout << " <P_set1, P_set1> = " << cc << "   ;";
        P_file << cc << ' ';

        cc = correlation(P_setSHG2, P_setSHG2, sampleLength, tau);
        std::cout << "<P_set2, P_set2> = " << cc << "   ;";
        P_file << cc << ' ';

        cc = correlation(P_setSHG1, P_setSHG2, sampleLength, tau);
        std::cout << "<P_set1, P_set2> = " << cc << std::endl;
        P_file << cc << std::endl;
    }


    P_file.close();


    int pumpPhoton = 1000'000;
    double eta = 1.0e-6;
    int SHGphoton;
    SHGphoton = uniform(pumpPhoton, eta);
    std::cout << "SHGphoton = " << SHGphoton << std::endl;

    // --------------------------------------------- end  -----------------------------------------------
    return 0;
}
