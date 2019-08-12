#include "Super_Int.h"

using namespace std;

int main(int argc, char *argv[])
{
    Super_int C=4562;
    int i = 4561;
    Super_int Result;
    Result=C;
    Result-=i;
   
    cout<< C <<" - "<<i<<" = "<<Result<< endl;
    return 0;
}
