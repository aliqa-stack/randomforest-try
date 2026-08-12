#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <algorithm>
//still dont understand the formula2

//lierrr kneh
//istigfar 


//day4 of learning 
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


    double w1 = (double)Llabels.size() / totalSize;
    double w2 = (double)Rlabels.size() / totalSize;
    
    return w1 * leftgini + w2 * rightgini
}


//lalieerrr ie function
bool split(std::vector<std::vector<double>>& data, std::vector<int>& Featureindex,
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

std::vector<int> pickRandomFeatures(int totalFeatures) {
    // 1. buat list semua index fitur: [0, 1, 2, ..., totalFeatures-1]
    std::vector<int> allFeatures(totalFeatures);
    std::iota(allFeatures.begin(), allFeatures.end(), 0);

    // 2. acak urutannya
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::shuffle(allFeatures.begin(), allFeatures.end(), gen);

    // 3. hitung berapa banyak fitur yang mau diambil
    int m = std::max(1, (int)std::sqrt(totalFeatures));  // minimal 1, jaga-jaga kalau totalFeatures kecil

    // 4. ambil m elemen pertama dari hasil shuffle
    std::vector<int> selected(allFeatures.begin(), allFeatures.begin() + m);

    return selected;
}

int majorityClass(std::vector<int>& labels, std::vector<int>& indices){
    std::map<int, int> count;
    for(int idx : indices){
        count[labels[idx]];
    }

    int BestCount = -1;
    int Bestclass = -1;

    for(auto [cls, c] : count){
        if(c > Bestcount) BestCount = c; Bestclass = cls;
    }

    return Bestclass;
}

bool isPure(std::vector<int>& labels, std:vector<int>& indices){
    for(size_t i = 0 ; i < indices.size(); i++){
        if(labels[indices[i]] != labels[indices[0]]) return false;
    }

    return true;
}

Node* BuildTree(std::vector<std::vector<double>>& data,
     int depths, int maxDepth, std::vector<int>& labels, std::vector<int>& indices, int minSampleSplit){
    Node* node = new Node();
    bool found = split(data, Featureindex, treshold, bestFeatureindex, BestRight, BestLeft);

    std::vectro<int> featureSubset = pickRandomFeatures(data[0].size());
    int Besfeaturs; double Besttreshold;
    std::vector<int> leftIdx, rightIdx;
    size_t Samplecount = indices.size();
    bool stop = (depths > maxDepth || Samplecount < (size_t)minsSampleSplit);

        if(stop){
            node-> isLeaf = true;
            node->predictedClass = majorityClass(labels, indices);
            
            return node;
            
        }
        if(!found){
            node-> isleaf = true;
            //split data nya
        
        }

    node->isLeaf = false;
    node->featureIndex = bestFeature;
    node->threshold = bestThreshold;
    node->left  = buildTree(data, labels, leftIdx,  depth + 1, maxDepth, minSamplesSplit);
    node->right = buildTree(data, labels, rightIdx, depth + 1, maxDepth, minSamplesSplit);

    return node;
}




int main(){





    return 0;
}
