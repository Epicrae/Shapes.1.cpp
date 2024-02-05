#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "myFile.hpp"//includes custom header w/id code block
using namespace std;
#include <cstdlib>


//fucntion prototypes
vector<string> parseString(string);// parse a line of text into tokens
void print_id(const std::string& lab_desc);//prints lab desc and id

int main()
{
	print_id("Shapes v.1");

	string line;

	ifstream file_in("Shapes.input.txt");//open input file for reading 
	if (!file_in.is_open()) {
		cout << "Error opening file" << endl;
		return 1;//exit if input file cannot be opened
	}
	ofstream file_out("Shapes.output.txt");//Open output file stream for writing 
	if (!file_out.is_open()) {
		cout << "Error opeing input file";
		return 1;
	}	
    cout << std::fixed << std::setprecision(2);//set decimal places 

	//Process and output for shapes: SQUARE,RECTANGLE,CIRCLE,TRIANGLE,CUBE,BOX,CYLINDER,PRISM.
	while (getline(file_in, line)) {//Read lines from input file untill EOF
	if (line.empty()) continue;// skip empty lines

	vector<string> tokens = parseString(line);
	if (tokens.empty() || tokens[0] == "EOF")//stop if line is empty or EOF
		break;

	// SQUARE Calculation
	if (tokens[0] == "SQUARE" && tokens.size() == 2) {
		double side = atof(tokens[1].c_str()); //Convert the side length from string to double
		double area = side * side;//calculate the area of a square (side^2)
		// Output to console and file
		cout << "SQUARE side=" << side << " area=" << area << endl;
		file_out << "SQUARE side=" << side << " area=" << area << endl;//write to file
	}
	else if (tokens[0] == "SQUARE" && tokens.size() != 2) {//invalid shapes or incorrect dimensions 
		cout << "Invalid Shape" << endl;		
	}
	// RECTANGLE Calculation
	if (tokens[0] == "RECTANGLE" && tokens.size() == 3) {
		double length = atof(tokens[1].c_str());
		double width = atof(tokens[2].c_str());
		double area = length * width;// Calculate the area of the rectangle (length * width)
		// Output to console and file
		cout << "RECTANGLE Length=" << length << " width=" << width << " area=" << area << endl;
		file_out << "RECTANGLE Length=" << length << " width=" << width << " area=" << area << endl;//write to file
	}
	else if (tokens[0] == "RECTANGLE" && tokens.size() != 3){
		cout << "Invalid Shape" << endl;		
	}
	// CIRCLE Calculation
	if (tokens[0] == "CIRCLE" && tokens.size() == 2) {
		double radius = atof(tokens[1].c_str());// Convert the radius from string to double			 
		double pi = 3.14;
		double area = pi * radius * radius;// Calculate the area 
		// Output to console and file
		cout << "CIRCLE Radius=" << radius << " area=" << area << endl;
		file_out << "CIRCLE Radius=" << radius << " area=" << area << endl;
	}
	else if (tokens[0] == "CIRCLE" && tokens.size() != 2) {
		cout << "Invalid Shape" << endl;		
	}
	// TRIANGLE Calculation
	if (tokens[0] == "TRIANGLE" && tokens.size() == 2) {
		double side = atof(tokens[1].c_str());			

		double area = (sqrt(3) / 4) * (side * side);// Calculate the area
		// Output to console and file
		cout << "TRIANGLE side=" << side << " area=" << area << endl;
		file_out << "TRIANGLE side=" << side << " area=" << area << endl;
	}
	else if (tokens[0] == "TRIANGLE" && tokens.size() != 2) {
		cout << "Invalid Shape" << endl;		
	}
	// CUBE Calculation
	if (tokens[0] == "CUBE" && tokens.size() == 2) {
		double side = atof(tokens[1].c_str());
		double surface_area = 6 * side * side;
		double volume = pow(side, 3);
		// Output to console and file
		cout << "CUBE side=" << side << " surface area=" << surface_area << " volume=" << volume << endl;
		file_out << "CUBE side=" << side << " surface area=" << surface_area << " volume=" << volume << endl;
	}
	else if (tokens[0] == "CUBE" && tokens.size() != 2) {
		cout << "Invalid Shape" << endl;		
	}
	// BOX Calculation
	if (tokens[0] == "BOX" && tokens.size() == 4) {
		double length = atof(tokens[1].c_str());
		double width  = atof(tokens[2].c_str());
		double height = atof(tokens[3].c_str());

		double surface_area = 2 * (length * width + length * height + width * height);  // Calculate the surface area
		double box_volume = length * width * height; // Calculate the volume 
		// Output to console and file
		cout << "BOX length=" << length << " width=" << width << " height=" << height << " surface area=" << surface_area << " volume=" << box_volume << endl;		
		file_out << "BOX length=" << length << " width=" << width << " height=" << height << " surface area=" << surface_area << " volume=" << box_volume << endl;
	}
	else if (tokens[0] == "BOX" && tokens.size() != 4) {
		cout << "Invalid Shape" << endl;			
	}
	// CYLINDER Calculation
	if (tokens[0] == "CYLINDER" && tokens.size() == 3) {
		double radius = atof(tokens[1].c_str());
		double height = atof(tokens[2].c_str());

		double surface_area = 2 * 3.14 * radius * (radius + height);// Calculate the surface 
		double volume = 3.14 * radius * radius * height; // Calculate the volume
		// Output to console and file
		cout << "CYLINDER radius=" << radius << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
		file_out<< "CYLINDER radius=" << radius << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;		
	}
	else if (tokens[0] == "CYLINDER" && tokens.size() != 3) {
		cout << "Invalid Shape" << endl;		
	}
	// PRISM Calculation
	if (tokens[0] == "PRISM" && tokens.size() == 3) {
		double side = atof(tokens[1].c_str());
		double height = atof(tokens[2].c_str());

		double base_area = (sqrt(3) / 4) * pow(side, 2);  // Calculate the base area
		double volume = base_area * height;// Calculate the volume
		double surface_area = 2 * base_area + 3 * side * height;   // Calculate the surface area
		// Output to console and file
		cout << "PRISM side=" << side << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
		file_out << "PRISM side=" << side << " height=" << height << " surface area=" << surface_area << " volume=" << volume << endl;
		
	}
	else if (tokens[0] == "PRISM" && tokens.size() != 3) {
		cout << "Invalid shape" << endl;	
	}
}	//close file streams
	file_in.close();
	file_out.close();
	
}
vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}



