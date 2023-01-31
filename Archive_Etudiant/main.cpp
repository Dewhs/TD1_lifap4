#include "Image.h"
#include <iostream>
#include <string>


using namespace std;
int main()
{
    Pixel test;
    Image monImage(100,100);
    monImage.dessinerRectangle(50,50,75,75,test);
    monImage.testRegression();
    return 0;
}
