#include<bits/stdc++.h>

using namespace std;

enum class Severity {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    deque<string> logs;
    const size_t MAX_LOGS = 1000;

    string getCurrentTimestamp() const {
        time_t now = time(nullptr);
        tm* lt = localtime(&now);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", lt);
        return string(buffer);
    }

    string severityToString(Severity s) const {
        switch (s) {
            case Severity::INFO: return "INFO";
            case Severity::WARNING: return "WARNING";
            case Severity::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }

    void storeLog(const string& formattedMessage) {
        if (logs.size() >= MAX_LOGS) {
            logs.pop_front();
        }
        logs.push_back(formattedMessage);
    }

    void logInternal(Severity severity, const string& module, const string& message) {
        string entry = "[" + getCurrentTimestamp() + "] [" + severityToString(severity) + "] [" + module + "] " + message;
        storeLog(entry);
    }

public:
    void log(Severity severity, const string& module, const string& message) {
        logInternal(severity, module, message);
    }

    friend class Auditor;
};

class Auditor {
private:
    string password = "audit123";

    bool authenticate(const string& inputPassword) const {
        return inputPassword == password;
    }

public:
    vector<string> getLogs(const Logger& logger, const string& inputPassword) {
        if (!authenticate(inputPassword)) {
            throw runtime_error("Access denied: authentication failed.");
        }
        return vector<string>(logger.logs.begin(), logger.logs.end());
    }
};

int main() {
    Logger logger;

    logger.log(Severity::INFO, "Network", "Connection established");
    logger.log(Severity::WARNING, "Database", "Query took too long");
    logger.log(Severity::ERROR, "Filesystem", "Disk read failure");
    logger.log(Severity::INFO, "UI", "User clicked button");
    logger.log(Severity::INFO, "Auth", "User login successful");

    Auditor auditor;
    try {
        vector<string> auditLogs = auditor.getLogs(logger, "audit123");
        cout << "\n[Audit Logs Retrieved]\n";
        for (const auto& log : auditLogs) {
            cout << log << "\n";
        }
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}
