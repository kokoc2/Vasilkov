#include <iostream>
#include <math.h>

class Poligon
{
protected:
	int* x = 0;
	int* y = 0;
	int count = 0;
	int size;
public:
	Poligon()
	{
		std::cin >> size;
		x = new int[size];
		y = new int[size];
		for (int i = 0; i < size; i++)
			std::cin >> x[i];
		for (int i = 0; i < size; i++)
			std::cin >> y[i];
	}
	double calculateS()
	{
		double polygon = 0;
		for (int i = 0; i < size - 1; i++)
			polygon += ((x[i] - x[i + 1]) * (y[i] + y[i + 1]))/2.0;
		polygon += ((x[size - 1] - x[0]) * (y[size - 1] + y[0])) / 2.0;
		polygon = abs(polygon);
		return polygon;
	}
	float calculateP()
	{
		double perimetr = 0;
		for (int i = 0; i < size - 1; i++)
			perimetr += sqrt(pow((x[i + 1] - x[i]), 2) + pow((y[i + 1] - y[i]), 2));
		perimetr += sqrt(pow((x[size - 1] - x[0]), 2) + pow((y[size - 1] - y[0]), 2));
		return perimetr;
	}
	friend bool operator^(Poligon p1, Poligon p2)
	{
		bool A = false, B = false, C = false, D = false;
		bool intersection = false;
		for (int i = 0; i < p1.size; i++)
		{
			for (int j = 0; j < p2.size; j++)
			{
				if (p1.x[i] < p2.x[j])
					A = true;
				if (p1.x[i] > p2.x[j])
					B = true;
				if (p1.y[i] > p2.y[j])
					C = true;
				if (p1.y[i] < p2.y[j])
					D = true;
			}
			if (A && B && D && C)
				intersection = true;
			A = false;
			B = false;
			C = false;
			D = false;
		}
		return intersection;
	}
	void console()
	{
		std::cout << "abscissa ";
		for (int i = 0; i < size; i++)
			std::cout << x[i] << " ";
		std::cout << " ordinata ";
		for (int i = 0; i < size; i++)
			std::cout << y[i] << " ";
		std::cout << " Perimetr= " << calculateP() << " Ploshad= " << calculateS() << std::endl;
	}
};

int main()
{
	Poligon p1, p2;
	std::cout << "Poligon1= ";
	p1.console();
	std::cout << "Poligon2= ";
	p2.console();
	/*bool fol = p1 ^ p2;*/
	if (p1 ^ p2)
		std::cout << "Poligon1 peresekaet Poligon2" << std::endl;
	else
		std::cout << "Poligon1 ne peresekaet Poligon2" << std::endl;
	return 0;
}