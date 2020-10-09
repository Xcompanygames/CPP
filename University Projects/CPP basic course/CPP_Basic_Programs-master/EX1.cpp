

#include <iostream>
#include <string>
void menu();
void as1() {
	int width,height;
	int Area, Perimeter;
	std::cout << "Enter width";
	std::cin >> width;
	std::cout << "Enter height";
	std::cin >> height;
	Area = width * height;
	Perimeter = 2 * width + 2 * height;
	printf("Area:");
	printf("%d\n", Area);
	printf("Perimeter:");
	printf("%d\n", Perimeter);
	menu();

}
void as2() {
	int money = 278;
	std::cin >> money;
	int t; //temp
	printf("\n");
	printf("%d\n", money);
	std::cout << "" << money;
	std::cout << "=100*";
	t = money / 100;
	std::cout << " " << t;

	money = money % (100);
	t = money / 50;
	std::cout << "+50*";
	std::cout << " " << t;

	money = money % (50);
	t = money / 20;
	std::cout << "+20*";
	std::cout << " " << t;

	money = money % (20);
	t = money / 10;
	std::cout << "=10*";
	std::cout << " " << t;

	money = money % (10);
	t = money / 5;
	std::cout << "+5*";
	std::cout << " " << t;

	money = money % (5);
	t = money / 2;
	std::cout << "+2*";
	std::cout << " " << t;

	money = money % (2);
	t = money / 1;
	std::cout << "+1*";
	std::cout << " " << t;
	std::cout << " nis";

	menu();
}
std::string monthname(int month) {
	std::string MonthName = "temp";
	//string mon = "n";
	if (month == 1)
	{
		MonthName = "January";
	}
	else if (month == 2)
	{
		MonthName = "February";
	}
	else if (month == 3)
	{
		MonthName = "March";
	}
	else if (month == 4)
	{
		MonthName = "April";

	}
	else if (month == 5)
	{
		MonthName = "May";

	}
	else if (month == 6)
	{
		MonthName = "June";

	}
	else if (month == 7)
	{
		MonthName = "July";

	}
	else if (month == 8)
	{
		MonthName = "August ";

	}
	else if (month == 9)
	{
		MonthName = "September";

	}
	else if (month == 10)
	{
		MonthName = "October";

	}
	else if (month == 11)
	{
		MonthName = "November";

	}
	else if (month == 12)
	{
		MonthName = "December";

	}
	return MonthName;
}
void as3() {
	int year = 0;
	int month = 0;
//	char mon;
	int Feb = 28;
	//There is 29 days in February 1964.
	// 1  3  5  7  8  10  12 = 31
	// 2 = 28 or 29
	// 4  6  9  11 = 30
	printf("Enter year:");
	std::cin >> year;
	printf("Enter month:");
	std::cin >> month;
	std::string NM = monthname(month); //Matching the number to the name of the month
	//Calc
	if (year % (4) == 0 && year != 2000){
		Feb = 29;
}
   if (month == 1 || month == 3 || month == 5 || month == 7
	   || month == 8 || month == 10 || month == 12)
   {
	   month = 31;
   }
   else if (month == 2)
   {
	   month = Feb;
   }
   else {
	   month = 30;
   }

   printf("There is ");
   std::cout << month;
   printf(" days in ");
   printf("%s", NM.c_str()); //printing the name of the month
   printf(" ");
   std::cout << year;
   menu();

}
void as4() {
	int menuid;
	double ans;
	printf("Please enter a number between 1 to 3");
	std::cin >> menuid;
	if (menuid == 1) {
		int speed;
		double distance;
		printf("I'm calculating time X speed=distance. What are you intrested in?");
		printf("Please enter a distance value (in KM)");
		std::cin >> distance;
		printf("Please enter a speed value (KM/H)");
		std::cin >> speed;
		ans = distance / speed;
		printf("the time is: ");
		printf("%f", ans);
		printf(" hours");
	}
	else if (menuid == 2) {
		int time;
		double distance;
		printf("I'm calculating time X speed=distance. What are you intrested in?");
		printf("Please enter a time value (in hours)");
		std::cin >> time;
		printf("Please enter a distance value (in KM)");
		std::cin >> distance;
		ans = distance / time;
		printf("the speed is: ");
		printf("%f", ans);
		printf(" km/h");
	}
	else if (menuid == 3) {
		int time;
		int speed;
		printf("I'm calculating time X speed=distance. What are you intrested in?");
		printf("Please enter a time value (in hours)");
		std::cin >> time;
		printf("Please enter a speed value (in KM/H)");
		std::cin >> speed;
		ans = speed * time;
		printf("the distance value is: ");
		printf("%f", ans);
		printf(" km");
	}
	menu();
}
void menu() {
	printf("ex1, please enter a number to run a certain assigment");
	printf("\n");
	printf("enter 0 to exit the program");
	printf("\n");
	printf("enter 1 to Area and Perimeter");
	printf("\n");
	printf("enter 2 to Change money");
	printf("\n");
	printf("enter 3 to Print date");
	printf("\n");
	printf("enter 4 to Time, speed and distance");
	printf("\n");
	int menu;
	std::cin >> menu;
	if (menu == 0) {
		exit(0);
	}
	else if (menu == 1) {
		as1();
	}
	else if (menu == 2)
	{
		as2();
	}
	else if (menu == 3)
	{
		as3();
	}
	else if (menu == 4)
	{
		as4();
	}
}
int main()
{

	menu();
}
