#include <iostream>
#include <vector>
#include <cmath>
#include <cmath>
#include <cstdlib>


//day2 of learning 
struct Node{
    bool isLeaf = false;
    int Featureindex;
    double treshold;
    int predictedClass;
    Node* left;
    Node* rigth;

};

struct DecisionTree{
    Node* root;
    int maxDepths;
    int minSampleSplit;
    int numFeaturesToCon;
}

double gini(std::vector<int> labels){
    std::map<int,int> count;

    for(auto& label ; labels){
        count[label]++;

    }
    int total = labels.size()
    double impurity = 1.0;
    for(auto& jumlah ; count){
        double p = jumlah / total;
        impurity -= p * p;
    }

    return impurity;

}

bool split(std::vector<std::vector<double>> data, std::vector<int>& Featureindex, double& treshold, int& numfeaturesTocon){
    std::vector<int> indices (data.size());
    int sqrtFeature = std::sqrt(numfeaturesTocon);
    double treshold = 0.0;
    bool BestSplit = false;
    double BestGini = std::numeric_limits<double>::max();

    for(auto& feat : Featureindex){
        for(size_t i = 0; i < data.size(); i++){
            int candidate = data[i][feat];
           
                std::vector<int> left_idx, rigth_idx;
                for(size_t j = 0; j < data.size(); j++){
                    if(data[j][feat] < candidate){
                        left_idx.push_back(j);

                    } else{
                        rigth_idx.push_back(j);
                    }
                }
            if(left_idx.empty() || rigth_idx.empty()) continue;
        }

    }
     
    return BestSplit;

}




int main(){





    return 0;
}
