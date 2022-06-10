#include </home/newHomeDir/wrapper_testing/getter.cpp>

int main()
{
    for(int k = 1; k <= 3; k++)
    {
        std::vector<double> results = test();
        
        for(int i = 0; i < results.size(); i++)
        {
            printf("%f \n", results[i]);
        }
    }
}