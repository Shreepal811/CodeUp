#include<iostream>
#include<algorithm>
#include<math.h>
#include <iomanip>
#include<vector>
using namespace std;

class Point {
    float x, y;

    public:
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float distance(float x_point, float y_point) {
        float sq1 = float(x_point - x) * (x_point - x);
        float sq2 = float(y_point - y) * (y_point - y);
        return sqrt(sq1 + sq2);
    }

    void translate(float dx, float dy) {
        this->x += dx;
        this->y += dy;
    }

    void display() {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};

class Shape : public Point {
    public:
    void get_area() {};
};

class Circle {
    float radius;
    public:

    Circle(float radius) {
        this->radius = radius;
    }

    float get_area() {
        float area = 3.14 * (this->radius)*(this->radius);
        return area;
    }
};

class Square {
    float side;
    public:

    Square(float side) {
        this->side = side;
    }

    float get_area() {
        return this->side * this->side;
    }
};

void GeometryOperations() {
    float x1, x2, y1, y2, new_x, new_y;
    float side, radius;
    cout << "Enter co-ordinates of point-1(x1, y1):";
    cin >> x1 >> y1;
    cout << "Enter co-ordinates of point-2(x2, y2):";
    cin >> x2 >> y2;
    cout << "Enter radius of circle:";
    cin >> radius;
    cout << "Enter side of square:";
    cin >> side;
    cout << "Enter co-ordinates of translation point:";
    cin >> new_x >> new_y;

    Point point(x1, y1);
    Circle circle(radius);
    Square square(side);

    float distance = point.distance(x2, y2);
    float circleArea = circle.get_area();
    float squareArea = square.get_area();
    point.translate(new_x, new_y);

    cout << "Distance: " << distance << endl;
    cout << "Circle Area: " << circleArea << endl;
    cout << "Square Area: " << squareArea << endl;
    cout << "Translated Point1: ";
    point.display();
    cout << endl;
}


void inputArray(int* arr, int size) {
    try {
        cout << "Enter the array elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input! Only integers allowed.");
            }
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        exit(1); 
    }
}

// 1. City
int farthestCity(int * nums,int size,int initialEnergy){
    int city = 0;
    int index = 0;
    while(initialEnergy > 0){
        initialEnergy = initialEnergy - nums[index++];
        if(initialEnergy < 0) break;
        city++;
    }
    return city;
}

// 2.
int findPivotIndex(int * inputArray,int size)
    {
        int totalSum = 0;
        for (int i = 0;i<size;i++)
            totalSum += inputArray[i];

        int leftSum = 0;
        for (int i = 0; i < size; i++)
        {
            int rightSum = totalSum - leftSum - inputArray[i];
            if (leftSum == rightSum)
                return i;
            leftSum += inputArray[i];
        }
        return -1;
    }

// 3.flip
int minFlip(int *nums,int size){
    int zeros = 0,ones = 0;
    for(int i = 0;i<size;i++){
        if(nums[i] == 0) zeros++;
        else ones++;
    }
    return min(zeros,ones);
}

//4. unique element
int unique(int *nums,int size){
    int res = 0;
    for(int i = 0;i<size;i++){
        res = res ^ nums[i];
    }
    return res;
}

//5. pair
bool pairFinder(int *nums,int size,int k){
    sort(nums,nums+size);
    int st = 0 , end = size - 1;
    while(st < end){
        if(nums[st] + nums[end] == k) return true;
        else if(nums[st] + nums[end] < k) st++;
        else end--;
    }
    return false;
}

//6. painter
int minTime(int *nums,int size){
    sort(nums,nums+size);
    int totTime = 0;
    for(int i = 0;i<size;i++){
        totTime += nums[i];
    }
    return totTime - nums[size-1];
}

int main(){
    bool flag = true;
    while(flag) {
        cout << "\n========= MENU =========\n";
        cout << " 1. Efficient Traveler       2. Stand Out Sum\n";
        cout << " 3. Flip the Switch          4. Odd One Out\n";
        cout << " 5. Smart Pair Finder        6. The Minimalist Painter\n";
        cout << " 7. Geometry Operations      0. Exit Program\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between 0 and 7.\n";
            continue;
        }
        switch(choice) {
            case 1:
            {
                    int size;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    int *nums = new int[size];
                    inputArray(nums,size);
                    int initialEnergy;
                    cout<<"Enter the initial Energy"<<endl;
                    cin>>initialEnergy;
                    cout<<"Farthest city reachable: "<<farthestCity(nums,size,initialEnergy)<<endl;
                    break;
            }
            
            case 2:
            {
                    int size;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    int *nums = new int[size];
                    inputArray(nums,size);
                    cout<<"Output : "<<findPivotIndex(nums,size)<<endl;
                    break;
            }
            case 3:
                {
                    int size;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    int *nums = new int[size];
                    inputArray(nums,size);
                    cout<<"Minimum Flips required are : "<<minFlip(nums,5)<<endl;
                    break;
                }
            case 4:
                {
                    int size;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    if(size % 2 == 0){
                        cout<<"Size must be odd"<<endl;
                        break;
                    }
                    int *nums = new int[size];
                    inputArray(nums,size);
                    cout<<"Unique Element is : "<<unique(nums,size)<<endl;
                    break;
                }
            case 5:
                {
                    int size,k;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    int *nums = new int[size];
                    inputArray(nums,size);
                    cout<<"K : ";
                    cin>>k;
                    if(pairFinder(nums,size,k)){
                        cout<<"Pair is available"<<endl;
                    }
                    else{
                        cout<<"Not available"<<endl;
                    }
                    break;
                }
            case 6:
                {
                    int size;
                    cout<<"Enter the size of the array"<<endl;
                    cin>>size;
                    int *nums = new int[size];
                    inputArray(nums,size);
                    cout<<"Minimum time required : "<<minTime(nums,size)<<endl;
                    break;
                }
            case 7:
                GeometryOperations();
            break;
            case 0:
                flag = false;
            break;
            default:
                cout << "Invalid input please enter again:" << endl;
            break;
        }
    }

    return 0;
}


