#include <string>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

class PriceDivergenceMonitor
{
  public:
    map<string, float> stockPrice;
    map<string, vector<string>> stockPair;
    PriceDivergenceMonitor(int threshold);
    void RegisterPair(const string& stockOne, const string& stockTwo);
    void UpdatePrice(const string& stockName, int newPrice);
  private:
    int threshold; 
    void ReportDivergence(const string& updatedStockName, int updatedStockPrice, const string& otherStockName, int otherStockPrice);
    // todo: add member variables, if needed
};


PriceDivergenceMonitor::PriceDivergenceMonitor(int threshold) : threshold(threshold)
{
    // todo: complete this constructor as needed
}

/*
The method RegisterPair will be called by the owner of this class each time it wants your class to start monitoring a new pair of correlated stocks.
*/
void PriceDivergenceMonitor::RegisterPair(const string &stockOne, const string &stockTwo)
{
    if (stockPair.find(stockTwo) != stockPair.end()){
        stockPair[stockOne] = vector<string>({stockTwo});
    } else {
        stockPair[stockOne].push_back(stockTwo);
    }
    if (stockPair.find(stockTwo) != stockPair.end()){
        stockPair[stockTwo] = vector<string>({stockOne});
    } else {
        stockPair[stockTwo].push_back(stockOne);
    }
}

/*
The method UpdatePrice will be called by the owner of this class whenever the price of a stock changes. When the price of a stock that is part of a registered pair changes, you should check whether that new price differs from the price of the other stock in the pair by more than the threshold. If it does, call the ReportDivergence method with the appropriate parameters.
*/
void PriceDivergenceMonitor::UpdatePrice(const string &stockName, int newPrice)
{   stockPrice[stockName] = newPrice; // we update the price
    if (stockPair.find(stockName) != stockPair.end()) { // when we find a registered stock
        for (auto& stock: stockPair[stockName]){
            if (abs(stockPrice[stock] - newPrice) > threshold){
                ReportDivergence(stockName, newPrice, stock, stockPrice[stock]);
            }
        }
    }
}

int timeStamp = 0;
vector<string> eventOutput;

void PriceDivergenceMonitor::ReportDivergence(const string& updatedStockName, int updatedStockPrice, const string& otherStockName, int otherStockPrice)
{
    ostringstream os;
    os << timeStamp << " " << updatedStockName << " " << updatedStockPrice << " " << otherStockName << " " << otherStockPrice;
    eventOutput.push_back(os.str());
}

int main()
{
    int tolerance;   
    cin >> tolerance;
    
    PriceDivergenceMonitor pdm(tolerance);
    
    int numLines;
    cin >> numLines;
    string lineType;
    for (int i = 0; i < numLines; i++)
    {
        cin >> lineType;
        
        if (lineType.compare("A") == 0) {
            string productOne, productTwo;
            cin >> productOne >> productTwo;
            pdm.RegisterPair(productOne, productTwo);
        } else if (lineType.compare("P") == 0) {
            string product;
            int price;
            cin >> product >> price;
            pdm.UpdatePrice(product, price);
            timeStamp += 1;
        } else {
            cout << "DEBUG: unknown input type" << endl;
            return -1;
        }
    }
    
    // write out output
    sort(eventOutput.begin(), eventOutput.end());
    for (auto it = eventOutput.begin(); it != eventOutput.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}