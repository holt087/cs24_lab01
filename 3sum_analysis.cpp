#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vect;
    for (int i = 0; i <nums.size(); i++) {
        for (int j = i+1; j <nums.size(); j++) {
            for (int k = j+1; k <nums.size(); k++) {
                if (nums.at(i) + nums.at(j) + nums.at(k) == 0) { //sorts vector, least to greatest
                    int min = nums.at(i);
                    if (nums.at(j) <= nums.at(i) && nums.at(j) <= nums.at(k)) min = nums.at(j);
                    if (nums.at(k) <= nums.at(i) && nums.at(k) <= nums.at(j)) min = nums.at(k);
                    int max = nums.at(i);
                    if (nums.at(j) >= nums.at(i) && nums.at(j) >= nums.at(k)) max = nums.at(j);
                    if (nums.at(k) >= nums.at(i) && nums.at(k) >= nums.at(j)) max = nums.at(k);
                    int mid =  nums.at(i) + nums.at(j) + nums.at(k) - max - min;
                        
                    vector<int> triple = {min, mid, max};  //checks if three set already in vect
                    bool duplicate = false;
                    for (vector<int> threeSet : vect) {
                        if (triple == threeSet) duplicate = true;
                    }
                    if (duplicate == false) vect.push_back(triple); //if not in vect already, adds it to vect
                }
            }
        }
    }
    return vect;
}

vector<int> createSet(int numOfElem) {
    vector<int> randomSet;
    for (int i = 0; i < numOfElem; i++) {
        randomSet.push_back(rand() % 21 - 10);
    }
    return randomSet; //FIXME, at least one soultion of (-a, -b, a+b), hardcode???
}

double timing(vector<int>& nums) {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = threeSum(nums);
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    return time_ms;
}

int main() {
    vector<int> set;

    set = createSet(200);
    cout << "n = 200  |  time = " << timing(set) << endl;
    set = createSet(400);
    cout << "n = 400  |  time = " << timing(set) << endl;
    set = createSet(800);
    cout << "n = 800 |  time = " << timing(set) << endl;
    set = createSet(1600);
    cout << "n = 1600 |  time = " << timing(set) << endl;

    return 0;
}