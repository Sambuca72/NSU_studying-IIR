#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main() {
    vector<int> nums = {1,2,2,3,4};

    string hw = "Hello world";
    
    map<string, int> maptest;
    
    maptest ["one"] = 1;
    maptest ["two"] = 2;
    
    cout << hw << endl;
    
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\n";
    }
    
    cout << maptest["two"]<<"\n";
    
    string x = "abc";
    string y = "def";
    if (x != y) {
        cout << "not equal" << std::endl;
    }else {
        cout << "equal" << std::endl;
    }

    if (x < y) {
        cout << "less" << std::endl;
    }else {
        cout << "not less" << std::endl;
    }
    return 0;
}