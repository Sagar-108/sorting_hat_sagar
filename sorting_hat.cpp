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

void assignHouse(Students student) {
        char clsn = student.getStudentClass();
        int roll = student.getRollNumber();
        string foodp = student.getFoodPreference();

        if(registered_set.find(roll) == registered_set.end()){

            registered_set.insert(roll);

            if(clsn == 'A' && foodp == "V" && house_A_V.size() < capacity){
                house_A_V.push_back(roll);
            }
            else if(clsn == 'B' && foodp == "V" && house_B_V.size() < capacity){
                house_B_V.push_back(roll);
            }
            else if(clsn == 'A' && foodp == "NV" && house_A_NV.size() < capacity){
                house_A_NV.push_back(roll);
            }
            else if(clsn == 'B' && foodp == "NV" && house_B_NV.size() < capacity){
                house_B_NV.push_back(roll);
            }

            else{
                NA.push_back(roll);
            }

        }
    
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