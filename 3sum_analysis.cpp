#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> unique;
    vector<vector<int>> vect;

    for (int i = 0; i <nums.size(); i++) {
        for (int j = i+1; j <nums.size(); j++) {
            for (int k = j+1; k <nums.size(); k++) {
                if (nums.at(i) + nums.at(j) + nums.at(k) == 0) {
                    vector<int> triple = {nums.at(i), nums.at(j), nums.at(k)};
                    sort(triple.begin(), triple.end());
                    unique.insert(triple);
                }
            }
        }
    }
    for (const auto& triplet : unique) {
        vect.push_back(triplet);
    }

    return vect;
}

vector<vector<int>> betterThreeSum(vector<int>& nums) {   
    sort(nums.begin(), nums.end());
    vector<vector<int>> resultVect;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums.at(i) == nums.at(i-1)) continue;
        int beg = i+1;
        int end = nums.size()-1;
        while (beg < end) {
            int sum = nums.at(i) + nums.at(beg) + nums.at(end);
            if (sum == 0) {
                resultVect.push_back({nums.at(i), nums.at(beg), nums.at(end)});
                beg++;
                end--;
                while (beg < end && nums.at(beg) == nums.at(beg - 1)) beg++;
                while (beg < end && nums.at(end) == nums.at(end + 1)) end--;
            }
            else if (sum < 0) beg++;
            else if (sum > 0) end--;
        }
    }
    return resultVect;
}

vector<int> createSet(int numOfElem) {
    vector<int> randomSet;
    for (int i = 0; i < numOfElem; i++) {
        randomSet.push_back(rand() % 21 - 10);
    }
    return randomSet;
}

double timing(vector<int>& nums, char c) {
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result;
    if (c == 'b') result = betterThreeSum(nums);
    else result = threeSum(nums);
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    return time_ms;
}

int main() {
    vector<int> set;

    set = createSet(200);
    cout << "n = 200  |  time = " << timing(set, 'a') << endl;
    cout << "n = 200  |  time = " << timing(set, 'b') << endl;
    set = createSet(400);
    cout << "n = 400  |  time = " << timing(set, 'a') << endl;
    cout << "n = 400  |  time = " << timing(set, 'b') << endl;
    set = createSet(800);
    cout << "n = 800  |  time = " << timing(set, 'a') << endl;
    cout << "n = 800  |  time = " << timing(set, 'b') << endl;
    set = createSet(1600);
    cout << "n = 1600 |  time = " << timing(set, 'a') << endl;
    cout << "n = 1600 |  time = " << timing(set, 'b') << endl;
    set = createSet(2400);
    cout << "n = 2400 |  time = " << timing(set, 'a') << endl;
    cout << "n = 2400 |  time = " << timing(set, 'b') << endl;
    set = createSet(3200);
    cout << "n = 3200 |  time = " << timing(set, 'a') << endl;
    cout << "n = 3200 |  time = " << timing(set, 'b') << endl;

    // TEST purposes
    // auto result = betterThreeSum(set);
    // for (auto triple : result) {
    //     for (auto one : triple) {
    //         cout << one << ", ";
    //     }
    //     cout << endl;
    // }

    return 0;
}