#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Students
{
private:
    int roll_num;
    char class_name;
    string food;

public:
    Students(int r, char cl, string myFood)
    {
        roll_num = r;
        class_name = cl;
        food = myFood;
    }

    int getRollNumber() 
    {
        return roll_num;
    }

    char getStudentClass() 
    {
        return class_name;
    }

    string getFoodPreference()
    {
        return food;
    }
};


class sortingHat
{

public:
    sortingHat(int cap){
        capacity = cap;
    }

private:
    vector<int> house_A_V;
    vector<int> house_A_NV;
    vector<int> house_B_V;
    vector<int> house_B_NV;
    vector<int> NA;
    unordered_set<int> registered_set;
    int capacity;
};



int main(){

    return 0;
}