#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) const = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(const string& status, int creditHours) const override {
        if (status == "undergraduate")
            return creditHours * 200;
        else if (status == "graduate")
            return creditHours * 300;
        else if (status == "doctoral")
            return creditHours * 400;
        else
            return 0;
    }
};

int main() {
    GraduateStudent grad;
    grad.setResearchTopic("Machine Learning in Healthcare");

    string status = "graduate";
    int creditHours = 9;

    cout << "Research Topic: " << grad.getResearchTopic() << endl;
    cout << "Status: " << status << endl;
    cout << "Credit Hours: " << creditHours << endl;
    cout << "Tuition: $" << grad.getTuition(status, creditHours) << endl;

    return 0;
}
