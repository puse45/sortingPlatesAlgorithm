#include <vector>
#include <iostream>
#include "licensePlateSort.h"

using namespace std;

int main()
{
//    Compare cmp;
    vector<StructA> aStructs;
    vector<StructA> results;
    aStructs = {
            {"KCB456H", 40,"home/pictures/lp1.jpg"},
            {"KCB456H", 43,"home/pictures/lp2.jpg"},
            {"KBF628B", 88,"home/pictures/lp8.jpg"},
            {"KBM489Z", 61,"home/pictures/lp3.jpg"},
            {"KBX528K", 78,"home/pictures/lp4.jpg"},
            {"KBM489Z", 45,"home/pictures/lp5.jpg"},
            {"KCB456H", 59,"home/pictures/lp6.jpg"},
            {"KBF628K", 60,"home/pictures/lp7.jpg"},
            {"KBF628K", 84,"home/pictures/lp8.jpg"},
            {"KBX528K", 79,"home/pictures/lp9.jpg"},
            {"KBX528K", 90,"home/pictures/lp10.jpg"},
            {"KBM489Z", 84,"home/pictures/lp11.jpg"},
            {"KBM489Z", 84,"home/pictures/lp11.jpg"},
    };

    licensePlateSort lps;
    results = lps.vectorsortPlate(aStructs);

    for(auto r = results.begin(); r!=results.end(); ++r){
        cout << "{" << r->licensePlate << " " << r->confidenceLvl << " " << r->imagePath << " } " << endl;
    }

    return 0;
}

