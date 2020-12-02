#include "Rule.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
 
using namespace std;

Rule::Rule(){
    conway();
}
Rule::~Rule(){
    sVals.clear();
    bVals.clear();
}
void Rule::conway(){
     rule = "B3/S23";
     if(bVals.size() > 0){
	bVals.clear();
     }
     if(sVals.size() > 0){
	sVals.clear();
     }
     bVals.push_back(3);
     sVals.push_back(2);
     sVals.push_back(3);
}
std::string Rule::golly(){
     return rule;
}
void Rule::golly(string newRule){ 
    checkGolly(convert(newRule));
    rule = newRule;
}
char* Rule::convert(string text){
    char* out = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), out);
    out[text.size()] = '\0';
    return out;
}
std::vector<int> Rule::getBVals(){
    return bVals;
}
std::vector<int> Rule::getSVals(){
    return sVals;
}
bool Rule::eval(bool nw, bool n, bool ne, bool w, bool me, bool e, bool sw, bool s, bool se){
    int count = 0;
    if(nw) count++;
    if(n) count++;
    if(ne) count++;
    if(w) count++;
    if(e) count++;
    if(sw) count++;
    if(s) count++;
    if(se) count++;
    if(me){
	return contains(sVals, count);
    }
    return contains(bVals, count);
}
void Rule::checkGolly(char* golly){
    sVals.clear();
    bVals.clear();
    string message = "Bad golly rule input, rule: ";
    message += golly;
    if(golly[0] != 'B'){
	throw runtime_error(message);
    }
    int count = 0;
    for(int i = 1; golly[i] != '/'; i++){
        if(isdigit(golly[i])){
            bVals.push_back(golly[i]- '0');
        }else{
           throw runtime_error(message);
        }
        count = i;
    }
    if(golly[count+2] != 'S'){
        throw runtime_error(message);
    }
    for(int i = count + 3; golly[i] != '\0'; i++){
        if(isdigit(golly[i])){
            sVals.push_back(golly[i]-'0');
        }else{
	     throw runtime_error(message);
        }
    }
    if(!(is_sorted(bVals.begin(), bVals.end()))||!(is_sorted(sVals.begin(), sVals.end()))){
	throw runtime_error(message);
    }
}
bool Rule::contains(vector<int> vec, int num){
    for(int i : vec){
        if(i == num){
            return true;
        }
    }
    return false;
}

