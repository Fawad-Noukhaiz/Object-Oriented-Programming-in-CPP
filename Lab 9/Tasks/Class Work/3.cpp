#include<bits/stdc++.h>

using namespace std;

class PatientRecord {
private:
    string name;
    string patientID;
    string dateOfBirth;

    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<string> billingInfo;

    void addMedicalEntry(const string& entry) {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string& treatment) {
        currentTreatments.push_back(treatment);
    }

    void addBillingEntry(const string& entry) {
        billingInfo.push_back(entry);
    }

    friend class Doctor;
    friend class BillingStaff;

public:
    PatientRecord(string name, string id, string dob)
        : name(move(name)), patientID(move(id)), dateOfBirth(move(dob)) {}

    string getPublicData() const {
        return "Name: " + name + "\nID: " + patientID + "\nDOB: " + dateOfBirth;
    }

    string getMedicalData(const string& role) const {
        if (role == "Doctor") {
            string data = "Medical History:\n";
            for (const auto& entry : medicalHistory) data += "- " + entry + "\n";
            data += "Current Treatments:\n";
            for (const auto& t : currentTreatments) data += "- " + t + "\n";
            return data;
        }
        return "Access Denied: Unauthorized role for medical data.";
    }

    string getBillingData(const string& role) const {
        if (role == "Billing") {
            string data = "Billing Records:\n";
            for (const auto& entry : billingInfo) data += "- " + entry + "\n";
            return data;
        }
        return "Access Denied: Unauthorized role for billing data.";
    }
};

class Doctor {
public:
    void updateMedicalHistory(PatientRecord& record, const string& newEntry) {
        record.addMedicalEntry(newEntry);
    }

    void addTreatment(PatientRecord& record, const string& treatment) {
        record.addTreatment(treatment);
    }

    void viewMedicalData(PatientRecord& record) {
        cout << "[Doctor Accessing Medical Data]\n";
        cout << record.getMedicalData("Doctor") << "\n";
    }
};

class BillingStaff {
public:
    void addBillingDetails(PatientRecord& record, const string& billingEntry) {
        record.addBillingEntry(billingEntry);
    }

    void viewBillingData(PatientRecord& record) {
        cout << "[Billing Accessing Billing Data]\n";
        cout << record.getBillingData("Billing") << "\n";
    }
};

class Receptionist {
public:
    void viewPublicInfo(const PatientRecord& record) {
        cout << "[Receptionist Viewing Public Info]\n";
        cout << record.getPublicData() << "\n";
    }

    void attemptMedicalAccess(PatientRecord& record) {
        cout << "[Receptionist Attempting Medical Access]\n";
        cout << record.getMedicalData("Receptionist") << "\n";
    }

    void attemptBillingAccess(PatientRecord& record) {
        cout << "[Receptionist Attempting Billing Access]\n";
        cout << record.getBillingData("Receptionist") << "\n";
    }
};

int main() {
    PatientRecord patient("John Doe", "P123", "1990-05-12");
    Doctor doc;
    BillingStaff billing;
    Receptionist receptionist;

    doc.updateMedicalHistory(patient, "Diagnosed with hypertension");
    doc.addTreatment(patient, "Prescribed beta-blockers");

    billing.addBillingDetails(patient, "Consultation Fee: $100");
    billing.addBillingDetails(patient, "Medication Cost: $50");

    doc.viewMedicalData(patient);
    billing.viewBillingData(patient);

    receptionist.viewPublicInfo(patient);
    receptionist.attemptMedicalAccess(patient);
    receptionist.attemptBillingAccess(patient);

    return 0;
}
