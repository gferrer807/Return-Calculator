// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
	long int start;
	long double income;
	int days;
	long double percent;
	long double startpercent;
	int count = 0;
	char question;
	bool state = true;
	double weeklyamount;
	int day = 0;
	long double losses;

	cout << "This is an ROI calculator to calculate the daily return for x percent for x days" << endl;
	cout << "Enter a starting amount: ";
	cin >> start;
	cout << "What percentage are you willing to stake? (50% would be .5): ";
	cin >> startpercent;
	cout << "Please enter the daily return (20% would be .2): ";
	cin >> percent;
	cout << "Please enter the amount of days: ";
	cin >> days;
	cout << "Would you like to add a weekly amount? (Y for yes, N for no): ";
	cin >> question;
	if (question == 'N') {
		state = false;
	}
	cout << "Would you like to account for potential losses? ";
	cout << "This would be for factoring in unkown variance. (Y for yes, N for no): ";
	cin >> question;
	cout << "How much in losses would you like to be added to your total?(10% would be .1): ";
	cin >> losses;

	start = (start*startpercent);

	for (int i = 0; i < days; i++) {
		day++;
		income = (start*percent);               //40
		start = income + start;
		cout << "Your earnings for Day " << day << " was " << start << endl;
		count++;
		if (count == 7 && state == true) {
			cout << "Please enter your weekly contribution: ";
			cin >> weeklyamount;
			start = start + weeklyamount;
			cout << "Your weekly contribution would make your stake holdings ";
			cout << start << endl;
			count = 0;
		}
	}


	losses = (start*losses);
	start = start - losses;
	cout << "With user entered possible losses accounted for, your total return would be: ";
	cout << start;

	cout << endl;


	return 0;
}


