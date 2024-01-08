#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Material
{
    int quantityAvailable;
    int quantityNeeded;
    int costOfOneUnit;
    int sellingPrice;

    Material(int available, int needed, int cost, int price)
        : quantityAvailable(available), quantityNeeded(needed), costOfOneUnit(cost), sellingPrice(price) {}

    double getProfitMargin() const
    {
        return static_cast<double>(sellingPrice - costOfOneUnit) / quantityNeeded;
    }
};

bool compareMaterials(const Material &a, const Material &b)
{
    return a.getProfitMargin() > b.getProfitMargin();
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Material> materials;

    
    for (int i = 0; i < m; ++i)
    {
        int available, needed, cost, price;
        cin >> available >> needed >> cost >> price;
        materials.emplace_back(available, needed, cost, price);
    }

    sort(materials.begin(), materials.end(), compareMaterials);

    
    double maxAmount = 0.0;
    for (const auto &material : materials)
    {
        int quantityToBuy = min(material.quantityAvailable, n / material.costOfOneUnit);
        maxAmount += quantityToBuy * material.sellingPrice;
        n -= quantityToBuy * material.costOfOneUnit;
    }
    cout << fixed << maxAmount << endl;

    return 0;
}
