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

vector<int> getBoardingHouses() {
        cout<<"A_V: ";
        for(auto i:house_A_V)
            cout<<i<<", ";
        cout<<endl;
        
        cout<<"A_NV: ";
        for(auto i:house_A_NV)
            cout<<i<<", ";
        cout<<endl;

        cout<<"B_V: ";
        for(auto i:house_B_V)
            cout<<i<<", ";
        cout<<endl;

        cout<<"B_NV: ";
        for(auto i:house_B_NV)
            cout<<i<<", ";
        cout<<endl;
        
        cout<<"NA: ";
        for(auto i: NA)
            cout<<i<<", ";
        cout<<endl;

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

    int capacity;
    // cout<<"Enter the total capacity of all boarding houses (a multiple of 4)"<<endl;
    cin>>capacity;
    sortingHat sh(capacity/4);

  
    while (1)
    {
        string state;
        int roll;
        char clas;
        string food;
        cin>>state;
        if(state != "reg")
            break;
        cin >> roll >> clas >> food;

        Students newStudent(roll, clas, food);
            sh.assignHouse(newStudent);
    }

    sh.getBoardingHouses();


    return 0;
}