#include <iostream>

using namespace std;

class Polytopes 
{
public:
	Polytopes(double rib) {
		this->rib = rib;
	}
	virtual void calcSize() = 0;
	virtual void calcSquare() = 0;

protected:
	double rib;
};

class Icosahedron :public Polytopes 
{
public:
	Icosahedron(double rib) : Polytopes(rib) {}
	void calcSize() override {
		cout << "Size: " << (0.42 * (3 + sqrt(5)) * pow(rib, 3)) << endl;
	}
	void calcSquare() override {
		cout << "Square: " << (5 * sqrt(3) * pow(rib, 2)) << endl;
	}
};

class Dodecahedron :public Polytopes
{
public:
	Dodecahedron(double rib) : Polytopes(rib) {}
	void calcSize() override {
		cout << "Size: " << (7.66 * pow(rib, 3)) << endl;
	}
	void calcSquare() override {
		cout << "Square: " << (20.65 * pow(rib, 2)) << endl;
	}
};

class Tetrahedron :public Polytopes
{
public:
	Tetrahedron(double rib) : Polytopes(rib) {}
	void calcSize() override {
		cout << "Size: " << (0.12 * pow(rib, 3)) << endl;
	}
	void calcSquare() override {
		cout << "Square: " << (sqrt(3) * pow(rib, 2)) << endl;
	}
};

int main() {
	Icosahedron* i = new Icosahedron(3);
	i->calcSize();
	i->calcSquare();
	delete i;
	Dodecahedron* d = new Dodecahedron(3);
	d->calcSize();
	d->calcSquare();
	delete d;
	Tetrahedron* t = new Tetrahedron(3);
	t->calcSize();
	t->calcSquare();
	delete t;
	return 0;
}