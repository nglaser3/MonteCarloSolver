#include <iostream>
#include "src/LegendreTally.C"

int main()
{
    /*
    LegendreTally leg(20);
    std::vector<std::vector<double>> cs{leg.getBaseCoeffs()};
    std::vector<std::vector<double>> ps{leg.getBasePowers()};
    for (int n = 0; n <= 20; n++)
    {
        std::cout<<"Order "<<n<<std::endl;
        std::vector<double> c{cs[n]};
        std::vector<double> p{ps[n]};
        for (int i = 0; i < c.size(); i++)
        {
            std::cout<<"      ^ "<<p[i]<<"  * "<<c[i]<<std::endl;
        }
        
    }*/
    std::vector<double> vec(5,1);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout<<vec[i]<<"   ";
    }
    

    return 0;
}