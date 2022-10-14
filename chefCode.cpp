// The chef receives exactly 1 ingredient per day from the market.
// The ingredients never repeat. Every ingredient belongs to 1 of the 3 categories namely FIBER,FAT & CARB.
// Every ingredient has a unique ingredient id which always starts with the category name (ex: FIBERBroccoli, FATCheese, CARBRice)
// Chef’s dish :-
// All of the chef's dishes have a constant number of ingredients.(this will be your program's input)
// All the ingredients used will be fully used in a Dish. The chef doesn’t use some partial quantity of an ingredient.
// All of the chef's dishes must have at least 60% of the ingredients from a single category.
// Chef's Cooking style :-
// If the chef has multiple options of ingredients for the dish, then he takes the oldest possible ones to cook in the order of their arrival.
// After the chef prepares a dish, the ingredients used can Not be reused as they have been already used.
// The chef prepares a maximum of 1 dish per day.
// If the Chef does not have enough ingredients to cook the dish with above mentioned rules, then he does not cook on that day.
// Given the input, number of days the chef receives ingredients (take ingredients as input), and number of ingredients in chef’s dish, output a string which have an entry - if chef doesn’t cook on a given day, and : separate ordered ingredients if chef cooks a dish.

// 6
// FATOil FATCheese FATEgg FIBERSpinach CARBRice FIBERBeans
// 3

// output:    --FATOil:FATCheese:FATEgg--FIBERSpinach:CARBRice:FIBERBeans

// 6
// FATOil FIBERSpinach CARBRice FATCheese FATEgg CARBWheat
// 3

// —FATOil:FIBERSpinach:FATCheese-CARBRice:FATEgg:CARBWheat

// 12
// FATOil FIBERSpinach CARBRice FATCheese FIBERBeans FATEgg FIBERBroccoil CARBPotato CARBCorn FATOlive FIBERCarrot FIBERRadish
// 4

// nlogn * logn ; O(n)

#include <bits/stdc++.h>

using namespace std;

string getType(string ingredient)
{
    if (ingredient.substr(0, 3) == "FAT")
    {
        return "FAT";
    }
    else if (ingredient.substr(0, 4) == "CARB")
    {
        return "CARB";
    }
    else
        return "FIBER";
}

string cookingOrder(int n, vector<string> &ingredients, int chefLimit)
{
    map<string, deque<int>> typeMap;
    string result = "";
    int singleCatLimit = ceil(0.6 * chefLimit), remaining = 0;
    for (int i = 0; i < n; ++i)
    {
        string type = getType(ingredients[i]);
        typeMap[type].push_back(i);
        ++remaining;
        if (remaining >= chefLimit && typeMap[type].size() >= singleCatLimit)
        {
            int otherCatLimit = chefLimit - singleCatLimit;
            int temp = chefLimit;

            while (otherCatLimit && temp)
            {
                int fatTime = typeMap["FAT"].empty() ? 1e9 : typeMap["FAT"][0];
                int fiberTime = typeMap["FIBER"].empty() ? 1e9 : typeMap["FIBER"][0];
                int carbTime = typeMap["CARB"].empty() ? 1e9 : typeMap["CARB"][0];
                if (fatTime < fiberTime && fatTime < carbTime)
                {
                    if ("FAT" != type)
                        --otherCatLimit;
                    result += ingredients[fatTime] + ":";
                    typeMap["FAT"].pop_front();
                }
                else if (fiberTime < fatTime && fiberTime < carbTime)
                {
                    if ("FIBER" != type)
                        --otherCatLimit;
                    result += ingredients[fiberTime] + ":";
                    typeMap["FIBER"].pop_front();
                }
                else
                {
                    if ("CARB" != type)
                        --otherCatLimit;
                    result += ingredients[carbTime] + ":";
                    typeMap["CARB"].pop_front();
                }
                --temp;
            }
            while (temp)
            {
                result += ingredients[typeMap[type][0]] + ":";
                typeMap[type].pop_front();
                --temp;
            }
            result.pop_back();
        }
        else
        {
            result += '-';
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ingredients(n);
    for (int i = 0; i < n; ++i)
        cin >> ingredients[i];
    int chefLimit;
    cin >> chefLimit;
    cout << "RESULT : " << cookingOrder(n, ingredients, chefLimit) << endl;
}