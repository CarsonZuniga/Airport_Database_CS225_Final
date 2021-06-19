#include "dataset.h"
#include <stdio.h>

using namespace std;

dataset::dataset(){

}

dataset::dataset(string input_file){
    // airport id, name, city, country, IATA, ICAO, latitude, longitude,
    // altitude, timezone, DST, Tz database time zone, type, source
    // Only need to read string 0, 1, 2, 3, 4, 6, 7
    ifstream my_file;
    my_file.open(input_file);
    if(!my_file){
        cout << "Could Not Open File." << endl;
        return;
    }
    cout << "Processing file: " << input_file << endl;
    file_name = input_file;

    string line;
    while(getline(my_file, line)){
        int string_number = 0;
        stringstream s_stream(line);
        while(s_stream.good()){
            string substring;
            getline(s_stream, substring, ',');
            if(string_number == 0)
                airport_ids.push_back(stoi(substring));
            else if(string_number == 1)
                airport_names.push_back(substring)
            else if(string_number == 2)
                airport_cities.push_back(substring);
            else if(string_number == 3)
                airport_countries.push_back(substring);
            else if(string_number == 4)
                airport_IATA.push_back(substring);
            else if(string_number == 6)
                airport_latitudes.push_back(stod(substring));
            else if(string_number == 7)
                airport_longitudes.push_back(stod(substring));
            string_number++;
        }
    }
    file_length = airport_ids.size();
    cout << "Done processing " << input_file << endl;
    my_file.close();
}

void dataset::printData(){
    for(int i = 0; i < file_length; i++){
        cout << airport_ids[i] << ", "
        << airport_names[i] << ", "
        << airport_cities[i] << ", "
        << airport_countries[i] << ", "
        << airport_IATA[i] << ", "
        << airport_latitudes[i] << ", "
        << airport_longitudes[i] << endl;
    }
}