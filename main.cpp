#include <iostream>
#include <vector>
#include <cmath>

int entropy(int& c){
    int pYa= c/4;
    int pNo = c/4;

    int e = -(pYa *(std::log2(pYa)) + pNo *(std::log2(pNo)));
    std::cout<<e<<"\n";

    return e;
}

int main(){

    std::vector<int> A = {1,1,0,0};
    std::vector<int> B = {0,0,1,1};
    int c = 2;
    entropy(c);



    return 0;
}
