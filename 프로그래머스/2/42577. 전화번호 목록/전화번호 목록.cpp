#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> sets;
    for (int i = 0 ; i < phone_book.size() ; i++){
        sets.insert(phone_book[i]);
    }
    for (auto s : sets){
        for (int i = 1 ; i < s.length() ; i++){
            if (sets.find(s.substr(0, i)) != sets.end()) return false;
        }
    }
    return true;
}