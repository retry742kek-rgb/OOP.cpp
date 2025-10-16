#include <iostream>
#include <fstream>
using namespace std;

class Report {
public:
    string generate() {
        return "Report data";
    }
};

class ReportSaver {
public:
    void saveToFile(const string& data, const string& filename) {
        ofstream file(filename);
        file << data;
        file.close();
    }
};

class EmailSender {
public:
    void send(const string& data, const string& email) {
        cout << "Sending report to " << email << endl;
    }
};

int main() {
    Report report;
    ReportSaver saver;
    EmailSender sender;

    string data = report.generate();
    saver.saveToFile(data, "report.txt");
    sender.send(data, "example@mail.com");
}
