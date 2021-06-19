#pragma once

#include <vector>
#include <string>

using namespace std;

class dataset {
    private:
    vector<int> airport_ids;
    vector<double> airport_latitudes;
    vector<double> airport_longitudes;
    vector<string> airport_names;
    vector<string> airport_cities;
    vector<string> airport_countries;
    vector<string> airport_IATA;

    string file_name;
    int file_length;

    public:
    dataset();
    dataset(string input_file);
    void printData();
};