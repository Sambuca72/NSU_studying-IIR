#include <iostream>
#include <cmath>
// #include <string>
using namespace std;

void solution (const int a, const int b, const int c){
    int D = b * b - 4 * a * c;
    if (D <  0){
        cout << "There is no solution btw" << endl;
    }else if (D == 0){
        cout << (-b) / (2 * a) << endl;
    }else{
        cout << ((-b) - sqrt(D)) / (2 * a) << " " <<  ((-b) + sqrt(D)) / (2 * a) << endl;
    }
    
}

int main (){
    int a, b, c;
    cout << "Enter the coefficients A, B, C of your equation in format (Ax^2 + Bx + C)\n"<< endl;
    cin >> a >> b >> c;

    solution(a, b, c);
    
}