
#include "console.hpp"

#include <iostream>

using namespace std;
using namespace Console;

int main()
{
	console con;
	//con.clear();
	size s = con.size();
	cout << s.width << "x" << s.height << endl;
	con.text_background(dark_blue);
	con.text_color(dark_red);
	bool success = con.size(size(10, 10));
	//if(con.size(size(35, 70)))
	{
		s = con.size();
		cout << s.width << "x" << s.height << endl;
	}
	con.title("testtitle");
	//con.cursor_position(point(10, 10));
	cout << con.text_color();
	cin.get();
	return 0;
}
