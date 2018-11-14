//
// Created by pinje on 11/14/18.
//

#include "licensePlateSort.h"
// Constructer
licensePlateSort::licensePlateSort() {

}
// Destructure
licensePlateSort::~licensePlateSort() {

}
// Sorting member function
vector<StructA> licensePlateSort::vectorsortPlate(vector<StructA> list){
    // Get vector group similar license plate together and place confidence level of repective on an array
    // map<string, vector<int> > grouped;
    for (auto it2 = list.begin(); it2 != list.end(); ++it2) {
        grouped[it2->licensePlate].push_back(it2->confidenceLvl);
    }
    // Create a vector to house license plate and confidence level
    // xxxx: 2,3,7,8
    for (auto it = grouped.begin(); it != grouped.end(); ++it) {
        r.push_back(make_pair(it->first,it->second));
    }
    // Open up vector to get maximum element confidence level
    for(auto i = r.begin(); i!=r.end(); i++) {
        auto maxPercentage = max_element(i->second.begin(), i->second.end());
        if(maxPercentage[0]){
            bStructs.push_back({i->first,maxPercentage[0]});
        }
    }
    // Sort both begining vector (list) and new vector (bStruct)
    sort(list.begin(), list.end(), cmp);
    sort(bStructs.begin(), bStructs.end(), cmp);
    // Find the intersection to get the common member from both vectors
    set_intersection(list.begin(), list.end(),
                     bStructs.begin(), bStructs.end(),
                     back_inserter(intersection), cmp);
//    copy(intersection.begin(), intersection.end(),
//         ostream_iterator<StructA>(cout, ""));

    return intersection;

}