//
// Created by pinje on 11/14/18.
//

#ifndef VE_LICENSEPLATESORT_H
#define VE_LICENSEPLATESORT_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/format.hpp>
#include <iostream>
#include <map>

using namespace std;

// Begining vector structure
struct StructA {
    string licensePlate;
    int confidenceLvl;
    string imagePath;
};
// Closing vector structure
struct StructB {
    string licensePlate;
    int confidenceLvl;
};
// Template to compare common fields
template<typename CharT, typename Traits>
basic_ostream<CharT, Traits>& operator<<(basic_ostream<CharT, Traits>& os, StructA const& sa) {
    return os << sa.licensePlate << " - " << sa.confidenceLvl<< " - " << sa.imagePath << std::endl;
}
// Compare sort structure
struct Compare
{
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) {
        return lhs.confidenceLvl < rhs.confidenceLvl && lhs.licensePlate < rhs.licensePlate;
    }
};


class licensePlateSort {
    //class members
public:
    explicit licensePlateSort();
    ~licensePlateSort();
    vector<StructA> vectorsortPlate(vector<StructA> list);

private:
    Compare cmp;
    vector<StructB> bStructs;
    vector<pair<string,vector<int>>> r;
    map<string, vector<int> > grouped;
    vector<StructA> intersection;
};

#endif //VE_LICENSEPLATESORT_H
