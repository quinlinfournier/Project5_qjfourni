/**
*  Quinlin Fournier
 * CS 2240
 * Section A
 */
#ifndef WHALES_H
#define WHALES_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using std::ifstream,std::ostream, std::left, std::right, std::setw, std::string, std::vector ;

/**
 * Class that represents the Data collected by NOAA found here: https://www.fisheries.noaa.gov/national/marine-life-distress/nati-onal-stranding-database-public-access?utm_source=chatgpt.com
 *
*Feilds:
*ndn: aka. National Database Number the number assigned to each entry
*in the data list also works as the requirement that each line has something different
*and is in the form of AA-0000-0000000
*commonName: is the common English name that the whale is known by
*species: is the scientific name for each whale type
*state: the abbreviation of the state or local area if they were in the water that the whale was sighted in
*date: the date that the whale was sighted
*Lat: The Latitude that the whale was sighted
*Lon: The longitude that the whale was sighted
*Leng: The length of the whale if measurements were taken
 */
class Whale {

private:
    std::string ndn, commonName, species, state, date;
    double lat, lon, leng;

public:
    //Constructors
    Whale() {
    //Set default Values on feilds
    ndn = "AA-0000-0000000";
    commonName = "Whale, fake";
    species = "N/A";
    state = "N/A";
    date = "00/00/0000";
    lat = 0.0;
    lon = 0.0;
    leng = 0.0;


    }
    Whale(string ndn, string commonName, string species, string state, string date,  double lat, double lon, double leng) {
        this -> ndn = ndn;
        this -> commonName = commonName;
        this -> species = species;
        this -> state = state;
        this -> date = date;
        this -> lat = lat;
        this -> lon = lon;
        this -> leng = leng;
    }

    //Getters

    string getndn() {
        return ndn;
    }

    string getCommonName() {
        return commonName;
    }

    string getSpecies() {
        return species;
    }

    string getState() {
        return state;
    }

    string getDate() {
        return date;
    }

    double getLat() {
        return lat;
    }

    double getLon() {
        return lon;
    }

    double getLeng() {
        return leng;
    }

    //Setters

    void setndn(std::string ndn) {
        this -> ndn = ndn;
    }

    void setCommonName(std::string commonName) {
        this -> commonName = commonName;
    }

    void setSpecies(std::string species) {
        this -> species = species;
    }

    void setState(std::string state) {
        this -> state = state;
    }

    void setDate(std::string date) {
        this -> date = date;
    }

    void setLat(double lat) {
        this -> lat = lat;
    }

    void setLon(double lon) {
        this -> lon = lon;
    }

    void setLeng(double leng) {
        this -> leng = leng;
    }

    //Overload Operators
    friend ostream& operator<<(ostream& outs, const Whale& w) {
        outs << std::left;
         outs << setw(20) << w.ndn;
         outs << setw(19)  << w.commonName;
         outs << setw(20)  << w.species;
         outs << setw(3) << w.state;
        //outs << right;
         outs << std::setprecision(4);
         outs << setw(20)  << w.date;
         outs << setw(10)  << w.lat;
         outs << setw(10) << w.lon;
         outs << setw(10)  << w.leng;
        return outs;

    }

    /**
 * Overload < operator for object comparison
 */
    friend bool operator < (const Whale& lhs, const Whale& rhs) {
        return lhs.leng < rhs.leng;
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Whale& lhs, const Whale& rhs) {
        return lhs.leng > rhs.leng;
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Whale& lhs, const Whale& rhs) {
        return lhs.leng <= rhs.leng;
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Whale& lhs, const Whale& rhs) {
        return lhs.leng >= rhs.leng;
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Whale& lhs, const Whale& rhs) {
        return lhs.leng == rhs.leng;
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Whale& lhs, const Whale& rhs) {
        return lhs.leng != rhs.leng;
    }
};
//Global Functions

//Reads from file and puts it into a vector
void getDataFromFile(string filename, vector<Whale> &whales) {
    std::ifstream fileIn;
    fileIn.open(filename);


    if (fileIn) {
        string header = "";
        getline(fileIn, header);

        //Declare Variables
        string ndn = "", commonName = "", species = "", state = "", date = "";
        double lat = -1, lon = -1, leng = -1;
        char comma, quote;

        // while the file stream is in a good state and we are not at the end of the file (EOF) End Of File
        while (fileIn && fileIn.peek() != EOF) {
            //RE-Declare Variables

            ndn = "", commonName = "", species = "", state = "", date = "";
            lat = -1, lon = -1, leng = -1;
            //Read Nation Database Number
            getline(fileIn, ndn, ',');
            //fileIn >> ndn >> comma;

            //Read Common Name
            //Check to see if there is a double quotes around the commonName
            if (fileIn.peek() == '"') {
               fileIn >> quote;
                getline(fileIn, commonName,'"');
                fileIn >> comma;
            }
            else {
                getline(fileIn, commonName, ',');
            }
            //Read Species
            getline(fileIn, species, ',');
            //Read State
            getline(fileIn, state, ',');
            //Read Date
            getline(fileIn, date, ',');
            //Read Latitude
            fileIn >> lat;
            if (!fileIn) {
                // there was no lat
                lat = 0;
                //Put back in a good state
                fileIn.clear();
            }
            fileIn >> comma;

            //Read Longitude
            fileIn >> lon;
            if (!fileIn) {
                // there was no lon
                lon = 0;
                //Put back in a good state
                fileIn.clear();
            }
            fileIn >> comma;

            //Read Length
            fileIn >> leng;
            if (!fileIn) {
                // there was no leng
                leng = 0;
                //Put back in a good state
                fileIn.clear();
            }
            fileIn >> comma;


            whales.push_back(Whale(ndn, commonName, species, state, date, lat, lon, leng));
        }

    }
    else {
        //Failed to open file
        std::cout << "Unable to open file" << std::endl;
    }

    fileIn.close();
}

/**
 * Given a vetor of large whale data count the number of killer whales
 */
void countKillerWhales(vector<Whale> &whales) {
     int numWhales = 0;
     for (int i = 0; i < whales.size(); i++) {
         if (whales[i].getCommonName() == "Whale, killer") {
             numWhales ++;
         }
     }

    std::cout << "There are " << numWhales << " Killer whales." << std::endl;
}

#endif //WHALES_H
