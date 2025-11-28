#include <iostream>

class RestrictWrapper {
private:
    int& ref;
    const int minValue;
    const int maxValue;
    int getCounter = 0;
    int setCounter = 0;

public:
    RestrictWrapper(int& variable, int minVal, int maxVal)
        : ref(variable), minValue(minVal), maxValue(maxVal) {}
    
    int get() {
        getCounter++;
        return ref;
    }
    
    void set(int value) {
        setCounter++;
        if (value < minValue) {
            ref = minValue;
        } else if (value > maxValue) {
            ref = maxValue;
        } else {
            ref = value;
        }
    }
    
    int getCount() const {
        return getCounter;
    }
    
    int setCount() const {
        return setCounter;
    }
};

int main()
{
    int x = 100;
    RestrictWrapper w(x, 0, 300);
    std::cout << w.get() << std::endl;    
    w.set(-200);
    std::cout << w.get() << std::endl;   
    w.set(300);
    w.set(400);
    w.set(500);
    std::cout << w.get() << std::endl;   

    std::cout << w.getCount() << std::endl; 
    std::cout << w.setCount() << std::endl; 
}
