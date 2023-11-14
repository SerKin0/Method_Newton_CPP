#include <iostream>
using namespace std;

float eps = 1e-6;


float f(float x) {
	return x * x - 2 * x - 3;
}


void df(float x0, float& k, float& b) {
	k = (f(x0 + eps) - f(x0)) / eps;
	b = f(x0) - k * x0;
}

float tangent(float x0, int step, int max_step, float left, float right) {
	float k = 0, b = 0;
	df(x0, k, b);
	float x_on_0 = -b / k;
	cout << "x0 = " << x0 << "\t"
		<< "b = " << b << "\t"
		<< "k = " << k << "\t"
		<< "x_on_0 = " << x_on_0 << endl;
	if ((step <= max_step) && (left <= x_on_0) && (x_on_0 <= right)) {
		if (abs(x_on_0 - x0) >= eps) return tangent(x_on_0, step + 1, max_step, left, right);
		else return x0;
	}
	else {
		cout << "Ответ не был найден" << endl;
		return 0;
	}
}


int main() {
	// Границы графика
float left = -2, right = 5;
	cout << tangent(right, 0, 1000, left, right) << endl;
}