#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const double MAX_CAP = 40000;
const double KILO_CONV = .840;
const double LBS_CONV = 1.85;

class FuelGauge
{
private:
    
	double volume;

	double convLiter(double quantity, char unit)
	{
		double converted = 0;
		if (quantity >= 0)
		{
			if (unit == 'l')
				converted = quantity;
			else if (unit == 'k')
				converted = quantity / KILO_CONV; 
			else if (unit == 'p')
				converted = quantity / LBS_CONV;
			else
				converted = -1;
		}
		return converted;
	}
    
public:
    
	FuelGauge()
	{
		volume = 0;	//in litres
	}
	FuelGauge(double volume0)
	{
		if (volume0 >= 0 && volume0 < MAX_CAP)
			volume = volume0;
		else
			volume = -1;
	}
	double getFuelLevel(char unit)
	{
		double fuel = 0;
		if (unit == 'l')
			fuel = volume;
		else if (unit == 'k')
			fuel = volume * KILO_CONV;
		else if (unit == 'p')
			fuel = volume * LBS_CONV;
		else
			fuel = -1;
		return fuel;
	}

	bool refuel(double quantity, char unit)
	{
		bool refuelled = false;
		if (quantity > 0 && quantity < MAX_CAP)
		{
			refuelled = true;
			if (unit == 'l' || unit == 'k' || unit == 'p' )
				volume += convLiter(quantity, unit);
			else
				refuelled = false;
		}
		else
			refuelled = false;
		return refuelled;
	}
	bool consume(double quantity, char unit)
	{
		bool consumed = false;
		if (quantity > 0 && quantity <= volume)
		{
			consumed = true;
			if (unit == 'l' || unit == 'k' || unit == 'p' )
				volume -= convLiter(quantity, unit);
			else
				consumed = false;
		}
		else
			consumed = false;
		return consumed;
	}
};

int main()
{
	cout << fixed << setprecision(2);

	FuelGauge case1;
	case1.refuel(23, 'l');
	case1.consume(10, 'k');
	cout << "Case 1";
	cout << setw(8) << case1.getFuelLevel('l') << " L";
	cout << setw(8) << case1.getFuelLevel('k') << " kg";
	cout << setw(8) << case1.getFuelLevel('p') << " lbs" << endl;

	FuelGauge case2(14);
	case2.consume(20, 'l');
	case2.refuel(5e4, 'l');
	cout << "Case 2";
	cout << setw(8) << case2.getFuelLevel('l') << " L";
	cout << setw(8) << case2.getFuelLevel('k') << " kg";
	cout << setw(8) << case2.getFuelLevel('p') << " lbs" << endl;

	FuelGauge case3(1000);
	case3.consume(200, 'm');
	case3.refuel(500, 'g');
	cout << "Case 3";
	cout << setw(8) << case3.getFuelLevel('m') << " L";
	cout << setw(8) << case3.getFuelLevel('g') << " kg";
	cout << setw(8) << case3.getFuelLevel('p') << " lbs" << endl;

	return EXIT_SUCCESS;
}
