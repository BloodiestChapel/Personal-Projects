#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int integer     = 0;
    char character  = '0';
    short shrt      = 0;
    long lng        = 0;
    float flt       = 0.0;
    double dbl      = 0;
    bool boolean    = "true";

    // Variable Sizes in Bytes
    cout << "Variable Sizes in Bytes" << endl;
    cout << "-----------------------" << endl;

    cout << "sizeOf(Integer)        =    " << sizeof(integer) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Character)      =    " << sizeof(character) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Short)          =    " << sizeof(shrt) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Long)           =    " << sizeof(lng) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Float)          =    " << sizeof(flt) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Double)         =    " << sizeof(dbl) << " bytes" << endl;
    cout << endl;
    cout << "sizeOf(Boolean)        =    " << sizeof(boolean) << " bytes" << endl;
    cout << endl;



// Variable Upper/Lower Limits
    cout << "Variable Upper/Lower Limits" << endl;
    cout << "---------------------------" << endl;

    cout << "Integer Upper Limit    =    " << numeric_limits<int>::max() << endl;
    cout << "Integer Lower Limit    =    " << numeric_limits<int>::min() << endl;
    cout << endl;
    cout << "Character Upper Limit  =    " << numeric_limits<char>::max() << endl;
    cout << "Character Lower Limit  =    " << numeric_limits<char>::min() << endl;
    cout << endl;
    cout << "Short Upper Limit      =    " << numeric_limits<short>::max() << endl;
    cout << "Short Lower Limit      =    " << numeric_limits<short>::min() << endl;
    cout << endl;
    cout << "Long Upper Limit       =    " << numeric_limits<long>::max() << endl;
    cout << "Long Lower Limit       =    " << numeric_limits<long>::min() << endl;
    cout << endl;
    cout << "Float Upper Limit      =    " << numeric_limits<float>::max() << endl;
    cout << "Float Lower Limit      =    " << numeric_limits<float>::min() << endl;
    cout << endl;
    cout << "Double Upper Limit     =    " << numeric_limits<double>::max() << endl;
    cout << "Double Lower Limit     =    " << numeric_limits<double>::min() << endl;
    cout << endl;
    cout << "Boolean Upper Limit    =    " << numeric_limits<bool>::max() << endl;
    cout << "Boolean Lower Limit    =    " << numeric_limits<bool>::min() << endl;
    cout << endl;

    return 0;
}