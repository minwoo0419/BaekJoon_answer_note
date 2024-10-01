#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
    int answer = bitset<32>(n).count();
    return answer;
}