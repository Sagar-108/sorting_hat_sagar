// including required header files
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// implementing Sttudents class
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

// method to get student roll number
    int getRollNumber() 
    {
        return roll_num;
    }

// method to get student class

    char getStudentClass() 
    {
        return class_name;
    }

// method to get student food preference

    string getFoodPreference()
    {
        return food;
    }
};


// implementing sorting hat class
class sortingHat
{

public:

// dynamically taking input capacity of each boarding house
    sortingHat(int cap){
        capacity = cap;
    }

// method to assign valid boarding house to a student
void assignHouse(Students student) {
        char clsn = student.getStudentClass();
        int roll = student.getRollNumber();
        string foodp = student.getFoodPreference();

        // check for duplicate entries
        if(registered_set.find(roll) == registered_set.end()){

            registered_set.insert(roll);

            // check if the valid house is house_A_V and also ensuring capacity limit
            if(clsn == 'A' && foodp == "V" && house_A_V.size() < capacity){
                house_A_V.push_back(roll);
            }

            // check if the valid house is house_B_V and also ensuring capacity limit
            else if(clsn == 'B' && foodp == "V" && house_B_V.size() < capacity){
                house_B_V.push_back(roll);
            }

            // check if the valid house is house_A_NV and also ensuring capacity limit
            else if(clsn == 'A' && foodp == "NV" && house_A_NV.size() < capacity){
                house_A_NV.push_back(roll);
            }

            // check if the valid house is house_B_NV and also ensuring capacity limit
            else if(clsn == 'B' && foodp == "NV" && house_B_NV.size() < capacity){
                house_B_NV.push_back(roll);
            }

            // if the capacity of valid house is full then adding the student to NA 
            // which means the student can not be assigned any boarding house
            else{
                NA.push_back(roll);
            }

        }
    
    }


// method to print the rolls of student boarded in each of the four boarding houses
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
        // if the state is not reg i.e. the state is fin then take no more input and display the result
        if(state != "reg")
            break;
        cin >> roll >> clas >> food;

        // calling the student class
        Students newStudent(roll, clas, food);
        // assigning boarding house to the newly enrolled student
        sh.assignHouse(newStudent);
    }

    // displaying the boarding houses with the roll numbers of students enrolled in them
    sh.getBoardingHouses();


    return 0;
}