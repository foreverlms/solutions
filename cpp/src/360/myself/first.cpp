#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
    string s;
    cin >> s;
    map<char,int> counter;

    for (auto single : s)
    {
        counter[single]++;
    }
    int max_ = 0;
    for(auto it= begin(counter); it != end(counter); it++){
        if(it->second > max_)
            max_ = it->second;
    }
    
    cout << max_;
}