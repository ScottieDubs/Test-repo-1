//Scott Wagner October 9th 2024 CIS 223
//This program uses an array of structures to store the radius, diameter, and area of circles based on the users input.
//It will then write this data to a binary file, read the data from the binary file, then write the data to a text file and read the data from it.

#include <iostream>  //header file for cout, cin and other func
#include <fstream>  //header file for filestream func
#include <iomanip>  //header file for output formatting func
#include <string>  //header file for string func

using namespace std;  //namespace std for cout, cin and other func

struct Circle {  //structure definition for the circle structure

    float radius;  //float holds the radius of a circle

    float diameter;  //float holds diameter of a circle

    float area;  //float holds area of a circle

};

int main()  //main function gets input from user, reads and writes to files, then displays file contents
{

    fstream binaryfile, textfile;  //fstream for both filestreams that will be used, binary and text

    float radius;  //local variable will be used to hold the users input for each circle

    int count = 0, count2 = 0, count3 = 0;  //these are all loop controlled variables for while statements throughout the program

    const int size = 20;  //this is the size of the array of circle structures (no more than 20)

    Circle record[size];  //defines record as a array of the circle structure

    Circle file_output_records[size];  //defines file_output_records as an array of circle structures that will be pulled from the binary file

    string line;  //string line is for displaying lines from a file

    string displayarray[3] = { "Radius: ", "Diameter: ", "Area: " };  //array holds strings that will be useful in displaying information from a file

    cout << "Please enter the radius for 20 circles maximum.\nWhen you want to stop entering radii please type '0'.\n";  //prompts user to enter no more than 20 radii

    while (count < size || radius == 00) {  //while loop goes until 20 radii are entered or the user enters 0

        cin >> radius;  //user inputs radius

        if (radius == 0) {  //if user input is 0

            break; //breaks away from the loop

        }

        else {  //if user input isnt 0

            record[count].radius = radius;  //radius is assigned to the radius variable of the circle structure for the current array count

            record[count].diameter = radius * 2;  //radius times 2 is assigned to diameter

            record[count].area = (3.1459) * (radius * radius);  //radius squared times pi is assigned to area

        }

        count++;  //1 is added to loop controlled variable

    }

    binaryfile.open("binaryfile.dat", ios::out | ios::binary);  //opens binary file for output

    binaryfile.write(reinterpret_cast<char*>(record), sizeof(record));  //writes  data to binary file

    binaryfile.close();  //closes file

    binaryfile.open("binaryfile.dat", ios::in | ios::binary);  //opens binary file for input
    
    binaryfile.read(reinterpret_cast<char*>(file_output_records), sizeof(file_output_records));  //saves binary file info to file_output_records

    binaryfile.close();  //closes file again

    textfile.open("textfile.txt", ios::out);  //opens textfile for output

    while (count2 < count) {  //while loop writes data to text file from file_output_records, uses count as it is the size of array of structures that have saved data. count2 is a new loop controlled variable set to 0

        textfile << left << setw(10) << file_output_records[count2].radius << setw(10) << file_output_records[count2].diameter << setw(10) << file_output_records[count2].area << endl;  //writes data to text file

        count2++;  //adds 1 to count
    }
    
    textfile.close();  //closes text file

    textfile.open("textfile.txt", ios::in);  //opens textfile for input

    cout << "Here are the contents of your text file.(Radius, diameter, and area are not labeled on file)\n";  //prompts user to view display of file info

    while (textfile) {  //while loop goes while textfile is open

        count3 = 0;  //count3 is new loop controlled variable used to control the display of a string to indentify the data on screen

        while (textfile >> line) {  //while loop goes until there are no lines left in the file

            cout << displayarray[count3] << line << "  ";  //displays "Radius: ", "Diameter: ", "Area: " from the array

            count3++;  //loop controlled variable adds 1

            if (count3 == 3) {  //if count3 is equal to 3

                cout << "\n";  //starts new line

                break;  //breaks away from the loop so count3 can be reset to 0

            }
        }
    }

}


