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

int main(){

    return 0;
}