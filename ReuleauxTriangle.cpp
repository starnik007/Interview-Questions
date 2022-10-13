// C++ Program to find the biggest Reuleaux triangle
// inscribed within in a square which in turn
// is inscribed within an equilateral triangle
#include <bits/stdc++.h>
using namespace std;

// Function to find the biggest reuleaux triangle
float Area(float a)
{

	// side cannot be negative
	if (a < 0)
		return -1;

	// height of the reuleaux triangle
	float x = 0.464 * a;

	// area of the reuleaux triangle
	float A = 0.70477 * pow(x, 2);

	return A;
}

// Driver code
int main()
{
	float a = 5;
	cout << Area(a) << endl;

	return 0;
}
