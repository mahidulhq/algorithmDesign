#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double FracKnap(vector<int> p, vector<int> w, int c, int n)
{
    vector<pair<double, pair<int,int>>> items;

    for (int i = 0; i < n; i++)
    {
        double ratio = (double)p[i]/w[i];
        items.push_back({ratio, {p[i], w[i]}});
    }

    sort(items.rbegin(), items.rend());

    double totalP = 0.0;
    int rem_cap = c;

    for (int i = 0; i < n; i++)
    {

        int current_p = items[i].second.first;
        int current_w = items[i].second.second;

        if (current_w <= rem_cap)
        {
            totalP += current_p;
            rem_cap -= current_w;
        }
        else
        {

            totalP += rem_cap * items[i].first;
            break;
        }
    }
    return totalP;
}

int main()
{
    vector<int> p;
    vector<int> w;
    int c, n;
    cout << "Enter the number of items :" << endl;
    cin >> n;
    cout << "Enter the price of items :" << endl;
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        p.push_back(price);
    }

    cout << "Enter the weight of items :" << endl;
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        w.push_back(weight);
    }
    cout << "Enter the capacity of the knapsack : " << endl;
    cin >> c;


    double maxP = FracKnap(p, w, c, n);
    cout << "Maximum Profit: " << maxP << endl;

    return 0;
}
