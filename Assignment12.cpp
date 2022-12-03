#include<iostream>
#include<map>

using namespace std;

typedef map<string, int> populationMap;

int main(){
    string state;
    int popu;
    populationMap population;
    
    population["Uttar Pradesh"] = 199812341;
    population["Maharashtra"] = 112374333;
    population["Bihar"] = 10409942;
    population["West Bengal"] = 91276115;
    population["Madhya Pradesh"] = 72626809;

    cout << "Enter State : ";
    string name;
    cin >> name;

    int num = population[name];

    cout << "Population of " << name << " is " << num;
    return 0;
}