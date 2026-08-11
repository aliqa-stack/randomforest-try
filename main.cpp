#include <iostream>
#include <vector>
#include <cmath>
#include <cmath>
#include <cstdlib>
//still dont understand the formula2

//lierrr kneh


//day3 of learning 
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

double gini(int& labels){
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

double weightGini(std::vector<int>& Rlabels, std::vector<int>& Llabels){
    int totalSize = Rlabels.size() + Llabels.size();
    double leftgini = gini(Llabels);
    double rightgini = gini(Rlabels);


    double w1 = (double)leftgini / totalSize;
    double w2 = (double)rightgini / totalSize;
    
    return w1 * leftgini * w2 * rightgini
}


//lalieerrr ie function
bool split(std::vector<std::vector<double>> data, std::vector<int>& Featureindex,
     double& treshold, int& bestFeatureIndex, std::vector<int>& BestRight,  std::vector<int>& BestLeft){
    std::vector<int> indices (data.size());
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
            std::vector<int>& RightLabels, LeftLabels;
            for(auto idx : rigth_idx) RightLabels.push_back(labels[idx]);
            for(auto idx : left_idx) LeftLabels.push_back(labels[idx]);

            double g = weightgini(RightLabels, Leftlabels)
            if(g < BestGini){
                treshold = candidate;
                BestRigth = right_idx;
                BestLeft = left_idx;
                bestFeatureIndex = feat;
                BestGini = g;
                BestSplit = true;
            }
        }

    }
     
    return BestSplit;

}




int main(){





    return 0;
}
