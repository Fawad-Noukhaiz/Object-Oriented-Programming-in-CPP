#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

const string baseLogFile = "log.txt";
const int maxFileSize = 1048576;

int getNextLogNumber() {
    int num = 1;
    while (fs::exists("log" + to_string(num) + ".txt")) {
        num++;
    }
    return num;
}

void rotateLog() {
    int nextNum = getNextLogNumber();
    fs::rename(baseLogFile, "log" + to_string(nextNum) + ".txt");
}

void writeLog(const string& message) {
    if (fs::exists(baseLogFile) && fs::file_size(baseLogFile) >= maxFileSize) {
        rotateLog();
    }
    ofstream file(baseLogFile, ios::app);
    file << message << endl;
    file.close();
}

int main() {
    for (int i = 0; i < 100000; i++) {
        writeLog("This is a sample log entry number " + to_string(i));
    }
    return 0;
}
