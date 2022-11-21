#include <iostream>
#include <vector>
using namespace std;

class AccessLevels {
public:
    int getReadOnly() const { return readOnly; }
    void setReadWrite(int value) { readWrite = value; }
    int getReadWrite() const { return readWrite; }
    void setWriteOnly(int value) { writeOnly = value; }

private:
    int noAccess;  // no access to this int
    int readOnly;  // read-only access to this int
    int readWrite; // read-write access to this int
    int writeOnly; // write-only access to this int
};

/********************************************************/
class SpeedDataCollection {
public:
    void addValue(int speed); // add a new data value
    double averageSoFar() const; // return average speed
private:
    vector<int> speeds;
    double average;
};

void SpeedDataCollection::addValue(int speed) {
    speeds.push_back(speed);
    average = (average * (speeds.size() - 1) + speed) / speeds.size();
}

double SpeedDataCollection::averageSoFar() const {
    return average;
}

int main() {
    SpeedDataCollection sdc;
    for (int i = 1; i <= 100; i++)
        sdc.addValue(i);
    cout << sdc.averageSoFar() << endl;
}



