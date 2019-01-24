#include<iostream>
#include<cmath>

using namespace std;
//仅判断奇数
bool isPrime(int n)
{
    for(int i = 3; i <= sqrt(n); i+=2 )
        if(n%i == 0)
            return false;
    return true;
}

int countPrimes(int n)
{
    if(n <= 2)
        return 0;
    int count = 1;
    for(int i = 3; i<n; i+=2)
    {
        if(isPrime(i))
            count++;
    }
    return count;
}

int main()
{
    int n = 10;
    int count = countPrimes(n);
    cout<<count<<endl;
    system("pause");
    return 0;
}