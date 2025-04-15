#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Whales.h"
using namespace std;

// Globals
string getNdnKey(Whale& w) {
    return w.getndn();
}

string getNdmSpeciesKey(Whale& w) {
    return w.getndn() + w.getSpecies();
}

int main() {
    // Load Whales
    vector<Whale> whales;
    getDataFromFile( "../CleanedLargeWhales-2005-2015-1-27.csv", whales);
    cout <<"Vector size: "<<whales.size() <<endl;

    vector<int> tableSizes = {1263, 1401, 1601, 2625, 3158};
    // Write to file
    ofstream out2("../all_collisions.csv");
    out2 << "TableType, TableSize, Index, Collisions\n";
    for (int t = 0; t < 5; t++) {

        int collisions = 0;


        // SEPARATE CHAINING — getNdnKey
        SeparateChaining<string> sepNdn(tableSizes[t]);
        collisions = 0;
        for (int i = 0; i < whales.size(); i++) {
            string key = getNdnKey(whales[i]);
            string value = whales[i].getndn();
            sepNdn.insert(key, value, collisions);

            out2 << "SeparateChaining NdnKey," << tableSizes[t] << "," << i << "," << collisions << "\n";
        }

        // SEPARATE CHAINING — getNdmSpeciesKey
        SeparateChaining<string> sepNdmSpecies(tableSizes[t]);
        collisions = 0;
        for (int i = 0; i < whales.size(); i++) {
            string key = getNdmSpeciesKey(whales[i]);
            string value = whales[i].getndn();
            sepNdmSpecies.insert(key, value, collisions);
            out2 << "SeparateChaining NdnSpeciesKey," << tableSizes[t] << "," << i << "," << collisions << "\n";
        }

        // OPEN ADDRESSING — getNdnKey
        LinearProbing<string> linNdn(tableSizes[t]);
        collisions = 0;
        for (int i = 0; i < whales.size(); i++) {
            string key = getNdnKey(whales[i]);
            string value = whales[i].getndn();
            linNdn.insert(key, value, collisions);
            out2 << "OpenAddressing Ndn," << tableSizes[t] << "," << i << "," << collisions << "\n";
        }
        cout << "Original Size: " << tableSizes[t] << " OpenAddressing Ndn Size: " << linNdn.getTableSize() << endl;

        // OPEN ADDRESSING — getNdmSpeciesKey
        LinearProbing<string> linNdnSpecies(tableSizes[t]);
        collisions = 0;
        for (int i = 0; i < whales.size(); i++) {
            string key = getNdmSpeciesKey(whales[i]);
            string value = whales[i].getndn();
            linNdnSpecies.insert(key, value, collisions);
            out2 << "OpenAddressing NdnSpecies," << tableSizes[t]  << "," << i << "," << collisions << "\n";
        }
        cout << "Original Size: " << tableSizes[t] << " OpenAddressing NdnSpecies Size: " << linNdnSpecies.getTableSize() << endl;


    }
    out2.close();

    return 0;

    }

