#include <iostream>
#include <math.h>

int totalAngle(int hour, int min)
{
	int total = 0, computeAngleHr, computeAngleMin;

	// each hour is 360/12 = 30 degrees
	//each minute is 30/5 = 6 degrees
	const int h = 30;
	const int m = 6;

	total = min*m - hour*h; // get the face value result

	//add if statement to calculate hour hand rotation due to minute hand
	//divide 60 minutes by 5 partition since there is 5 division between hour
	if (min>=12&&min<24) {
		total -= m*1; 
	}
	else if (min>=24&&min<36) {
		total -= m*2;
	}
	else if (min>=36&&min<48) {
		total -= m*3;
	}
	else {
		total -= m*4;
	}

	return total < 180 ? total : 360 - total;
}

int main()
{
	int hours, minutes, result;
	std::cout << "Enter Time in hour: ";
	std::cin >> hours;
	std::cout << "Enter Time in minutes: ";
	std::cin >> minutes;

	result = totalAngle(hours, minutes);

	std::cout << "\t\t" << result << " degrees \n";

	return 0;
}