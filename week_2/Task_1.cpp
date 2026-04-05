#include <iostream>
#include<string>
using namespace std;
class Shape {
public:
	virtual float area() = 0;
};
class Circle:public Shape {
private:
	int radius = 0;
public:
	Circle(int r) {
		radius = r;
	}
	float area() {
		return 3.1416 * radius * radius;
	}
};
class Rectangle :public Shape {
private:
	int width, length;
public:
	Rectangle(int w, int l) {
		width = w;
		length = l;
	}
	float area() {
		return width * length;
	}
};
int main() {
	Circle c1(5);
	cout << "the area of the Circle is: " << c1.area() << endl;

	Rectangle r1(3, 5);
	cout << "the area of the rectangle is: "<<r1.area();

	return 0;
}