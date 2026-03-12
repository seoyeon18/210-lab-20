#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 3;
class Chair
{
private:
    int legs;
    double *prices;

public:
    // constructors
    Chair()
    {
        prices = new double[SIZE];
        legs = rand() % 2 + 3;  // random select 3 or 4

        const int MIN = 10000, MAX = 99999; 
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100;
    }
    Chair(int l, double p[])
    {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] =p[i];
    }
    //avoid memory leak
    ~Chair() {
        delete[] prices ;
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3)
    {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }
    double getAveragePrices()
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    void print()
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl
             << "Historical avg price: " << getAveragePrices();
        cout << endl
             << endl;
    }
};
int main()
{
    srand(time(0)); // random generator

    cout << fixed << setprecision(2);

    // creating pointer to first chair object
    Chair *chairPtr = new Chair;
     chairPtr->print();
    // chairPtr->setLegs(4);
    // chairPtr->setPrices(121.21, 232.32, 414.14);
    double livingPrices[SIZE] = {525.25, 434.34, 252.52}; // price array
    Chair *livingChair = new Chair(3, livingPrices);      // new constructor fomat
   livingChair->print();

    // creating dynamic chair object with constructor
    
    delete livingChair;
    livingChair = nullptr;

    // creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete chairPtr;      //free memory
    chairPtr = nullptr;

    delete[] collection;  //free array memory
    collection = nullptr;
    return 0;
}
