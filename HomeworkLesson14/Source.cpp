#include <iostream>
#include <stack>

using namespace std;

class Engine {
public:
	string engineNo = "";
	string company = "";
	double volume = 0;

	Engine() {}

	Engine(string eNo, string comp, double vol) : engineNo(eNo), company(comp), volume(vol) {}

	friend ostream& operator<<(ostream& out, const Engine obj) {
		out << "=> Engine: \nEngine Number: " << obj.engineNo << "\nCompany: " << obj.company << "\nVolume: " << obj.volume;
		return out;
	}
};

class Vehicle {
public:
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;

	Vehicle(string vend, string mod, Engine eng) {
		id = staticId++;
		vendor = vend;
		model = mod;
		engine = eng;
	}

	virtual void Show() {
		cout << "ID: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n" << engine << endl;
	}

};
int Vehicle::staticId = 789;

class Car : public Vehicle {
public:
	bool hasSpoiler;
	Car(string vend, string mod, Engine eng, bool hasSpoiler) : Vehicle(vend, mod, eng) {
		this->hasSpoiler = hasSpoiler;
	}

	void Show() override {
		cout << "=====> CAR <=====\n";

		Vehicle::Show();
		cout << "Spoiler: " << (hasSpoiler ? "Var" : "Yox") << endl;
	}
};

class Ship : public Vehicle {
public:
	bool hasSail;
	Ship(string vend, string mod, Engine eng, bool hasSail) : Vehicle(vend, mod, eng) {
		this->hasSail = hasSail;
	}

	void Show() override {
		cout << "=====> SHIP <=====\n";
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "Var" : "Yox") << endl;
	}
};

class Garage {
public:
	stack<Vehicle*> vehicles;

	void ShowAllVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

void main() {
	Garage* garage = new Garage();
	garage->vehicles.push(new Car("BMW", "M4", Engine("3.0L", "L-6", 3.0), true));
	garage->vehicles.push(new Ship("Yamaha", "2522SD", Engine("256", "Yamaha Marine", 1.8), false));

	garage->ShowAllVehicles();
	delete garage;
}