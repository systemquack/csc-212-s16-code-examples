#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LList.h"

typedef struct {
    double latitude;
    double longitude;
    double radius;
    std::string filter;
    std::string database;
} Params;

bool read_params(int argc, char **args, Params *params) {
    if (argc != 6) {
        std::cout << "Usage: ./search-map <lat> <lon> <radius> <filter> <database>\n";
        std::cout << "\t<lat>\t\tLatitude of query point\n";
        std::cout << "\t<lon>\t\tLongitude of query point\n";
        std::cout << "\t<radius>\tRadius of query\n";
        std::cout << "\t<filter>\tSingle word to filter results (no whitespaces)\n";
        std::cout << "\t<database>\tFile name containing all the locations for a given region\n";
        std::cout << "Example: find all places that contain 'restaurant' under a radius of 10 miles from 42.34,-71.10 in boston.txt\n";
        std::cout << "\t./search-map 42.34 -71.10 10 restaurant boston.txt\n";
        return false;
    } else {
        params->latitude = atof(args[1]);
        params->longitude = atof(args[2]);
        params->radius = atof(args[3]);
        params->filter = args[4];
        params->database = args[5];
        return true;
    }
}

int main(int argc, char **args) {
    std::string line, raw_line;
    double lat, lon;
    std::string name;
    Params params;

    std::clock_t tic, toc;
    unsigned int count;
    LinkedList list;

    // if correct number of parameters
    if (read_params(argc, args, &params)) {
        // open the database
        std::ifstream myfile (params.database);
        if (myfile.is_open()) {
            std::cerr << "Reading all records from " << params.database << " ...\n";
            tic = std::clock();
            // iterate over all lines in the database file
            while (getline(myfile,raw_line)) {
                try {
                    // extract latitude, longitude, and the location words
                    line = raw_line;
                    lat = stod(line.substr(0,line.find_first_of(" ")));
                    line = line.substr(line.find_first_of(" ")+1);
                    lon = stod(line.substr(0,line.find_first_of(" ")));
                    name = line.substr(line.find_first_of(" ")+1);
                    // at this point you have LAT, LON, NAME
                    // TODO: insert every record into the kd-tree
                    list.insert(lat, lon, name);
                } catch(const std::exception &e) {
                    std::cerr << "\tcould not parse line: " << raw_line << "\n"; 
                }
            }
            myfile.close();
            toc = std::clock();
            std::cerr << "\tdone! " << list.getSize() << " records inserted in " << (double)(toc-tic)/CLOCKS_PER_SEC << " secs\n";
            // print results
            std::cerr << "Fetching results ... ";
            tic = std::clock();
            count = list.printNeighbors(params.latitude, params.longitude, params.radius, params.filter);
            toc = std::clock();
            std::cerr << "done!\n\t" << count << " records fetched in " << (double)(toc-tic)/CLOCKS_PER_SEC << " secs\n";
        }
    }

    // successfully ended the program
    return 0;
}
