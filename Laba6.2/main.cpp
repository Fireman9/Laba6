#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Service {
public:
	Service(string naming, string description) {
		this->naming = naming;
		this->description = description;
	}
	string getNaming() {
		return this->naming;
	}
	string getDescription() {
		return this->description;
	}

private:
	string naming;
	string description;
};

class PassportOffice {
public:
	PassportOffice() {
		this->services.push_back(new Service("Passport issuance", "- Birth certificate,\n"
			"- certificate from the Housing Office (utility bills)\n"
			"- photo 3x4.\n"));
		this->services.push_back(new Service("Foreign passport issuance", "- Passport\n"
			"- certificate of outstanding criminal record\n"
			"- certificate from the military registration and enlistment office\n"));
		this->services.push_back(new Service("Residence permit", "- Passport with a note on discharge from the previous place of residence\n"
			"- application for registration\n"
			"- certificate of registration\n"));
		this->services.push_back(new Service("Statement", "- Certificate of utility bills from the place of current registration\n"
			"- statement for discharge\n"
			"- passport\n"));
		this->services.push_back(new Service("Renewal of passport", "In case of loss, the citizen writes an application for "
			"the issuance of a new passport, which indicates the reason for renewal.\n"
			"If the passport is lost, then the citizen must pay a fine.\n"
			"If the passport is stolen, then the passport office fulfills a "
			"request to the police about the existence of an initiated case of theft\n"));
	}
	void getInfo() {
		while (true) {
			string temp;
			for (int i = 0; i < services.size(); i++) {
				cout << i + 1 << ": " << services[i]->getNaming() << endl;
			}
			cout << "Enter 0 for exit" << endl;
			getline(cin, temp);
			if (temp == "0") {
				break;
			}
			cout << services[stoi(temp) - 1]->getDescription();
			system("pause");
		}
	}
	int getServiceCount() {
		return services.size();
	}

private:
	vector<Service*> services;
};

int main() {
	PassportOffice* p = new PassportOffice();
	p->getInfo();
	delete p;
	return 0;
}