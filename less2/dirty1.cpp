#include <iostream>
#include <fstream>
using namespace std;

class Report {
public:
    void generateReport() {
        cout << "Generating report..." << endl;
    }

    void saveToFile(string filename) {
        ofstream file(filename);
        file << "Report data";
        file.close();
    }

    void sendEmail(string email) {
        cout << "Sending report to " << email << endl;
    }
};

int main() {
    Report r;
    r.generateReport();
    r.saveToFile("report.txt");
    r.sendEmail("example@mail.com");
}
