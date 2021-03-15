//  Created by Michael Nunes on 09/10/19.

#include <iostream> // include for console I/O
#include <fstream> // header file for input and output
#include <string> // include string functions
#include <iomanip> // include the format output

using namespace std; // is the standard namespace. cout, cin and a lot of other things are defined in it

void car(); // function to adds cars to the car.txt
void manufacture(); // This function read in two string from the user one of them is the abbreviation for a manufacturer and the another one is for actual name of the manufacturer. Also, this function creates a file call manufactureDateBase.txt and store the abbreviation for a manufacturer and actual name of the manufacturer.
void carDealer(); // this function add dealers to the dealerDatebase.txt. Also, this function reads the dealerDatebase file and store so we can compare dealer names with zipcodes
void dealershipList(); //this function read all the information which is in dealerDatebase and print all the information to the user.
void carList(); // this function read all the information which is in car and print all the information to the user.
void quitProgram(); // fuction to quit the program
void findManufacturer(); //read in from the user a string and then open the manufactureDatebase file , car file and dealerdatebase file and compare things from them. also, print it
void findZipcode(); //  read in from the user a string and then open the manufactureDatebase file , car file and dealerdatebase file and compare things from them. also, print it

/*
 * this function print >>> and read the first and second letter from the input and call functions
 */
int main ()
{
    string principalLetter; // creating a string variable for the principal letter
    string secondLetter; // creating a string variable for the second letter
    
    cout << ">>>"; // print to the user >>>
    cin >> principalLetter; // read from the input the first letter and store in the principal letter variable
    
    if (principalLetter=="a") // check is the first letter is equal to a
    {
        cin >> secondLetter; // read from the input the second letter and store in the secondLetter variable
        if(secondLetter=="c") // check if the second letter is equal to c
            car(); //call the car function and do it
        if(secondLetter=="m") // check if the second letter is equal to m
            manufacture(); //call the manufacture function and do it
        if(secondLetter=="d") // // check if the second letter is equal to d
            carDealer(); //call the carDealer function and do it
    }
    if (principalLetter=="l") // check if the first letter is equal to l
    {
        cin>> secondLetter; // read from the input the second letter and store in the secondLetter variable
        if (secondLetter=="d") // check if the second letter is equal to d
            dealershipList(); // call the dealershipList function and do it
        if (secondLetter=="c") // check if the second letter is equal to c
            carList(); //call the carList function and do it
    }
    if (principalLetter=="f") // check if the first letter is equal to f
    {
        cin >> secondLetter; // read from the input the second letter and store in the secondLetter variable
        if (secondLetter=="m") //check if the second letter is equal to m
            findManufacturer(); //call the findManufacturer function and do it
        if (secondLetter=="z") //check if the second letter is equal to z
            findZipcode(); //call the findZipcode function and do it
    }
    
    if (principalLetter=="q") // check if the first letter is q
    {
        quitProgram(); //call the quitProgram function and do it
        
    }
}

/*
 * read in from the user the next 4 values and store in their variable and then add into the car.txt file.
 */
void car ()
{
    string VIN; // creating a string variable for VIN of the car
    int miles; // creating a integer variable for miles of the car
    string dealershipName; // creating a string variable for the dealership of the car
    int price; // creating an integer variable for price of the car
    cin >> VIN; // read in the string variable from the user and store it in VIN
    cin >> miles; // read in the integer variable from the user and store it in miles
    cin >> dealershipName; // read in the string variable from the user and store it in dealershipName
    cin >> price; // read in the integer variable from the user and store it in price
    
    ofstream carDatebase("car.txt", ios::app); // create the car.txt File so we can add thing to the file
    carDatebase <<VIN << ' ' << miles << ' ' << dealershipName << ' ' << price <<"\n"; // add into the car.txt  the VIN string, the miles integer, the dealership string and the price integer.
    carDatebase.close(); // close the car.txt file
    main(); // return to the main function
}
/*
 * This function read in two string from the user one of them is the abbreviation for a manufacturer and the another one is for actual name of the manufacturer. Also, this function creates a file call manufactureDateBase.txt and store the abbreviation for a manufacturer and actual name of the manufacturer.
 */
void manufacture()
{
    string abbvManufacturer; // creating a string variable for abbreviation for a manufacturer
    string nameManufacturer; // creating a string variable for actual name of the manufacturer
    cin >> abbvManufacturer; // read in the string variable from the user and store it in abbvmanufacturer
    cin >> nameManufacturer; // read in the string variable from the user and store it in nameManufacturer
    ofstream manufactureDatebase ("manufactureDatebase.txt", ios::app); // create the file manufactureDatebase so we can add into the file
    manufactureDatebase << abbvManufacturer << ' ' << nameManufacturer <<"\n"; // add abbeviation for a manufacturer and the actual name of the manufacturer to the manufactureDatebase.txt
    manufactureDatebase.close(); // close the manufactureDatebase.txt file
    main(); // call the main function
}
/*
 *  this function add dealers to the dealerDatebase.txt. Also, this function reads the dealerDatebase file and store so we can compare dealer names with zipcodes
 */
void carDealer()
{
    string dealerName; // creating a string variable for dealername
    int zipCode; // creating an integer variable for zipcode
    string phoneNumber; // creating a string variable for phoneNumber
    cin >> dealerName; //read in the string variable for dealername
    cin >> zipCode; //read in the integer variable for zipCode
    cin >> phoneNumber; //read in the string variable for phoneNumber
    
    string dealerFalse; // creating a string variable for second dealer
    int zipCodeFalse; // creating an integer for second zipcode
    string phonenumberFalse; // creating a string for the second phonenumber
    
    ofstream dealerDatebase ("dealerDatebase.txt", ios::app); // create the file dealerDatebase so we can add into the file
    ifstream openFile ("dealerDatebase.txt"); // open the dealerDatebase in order to read what it is in the file
    while(openFile >> dealerFalse >> zipCodeFalse >> phonenumberFalse) // read every line from the file and store it in this variable until there is nothing in the file
        if (dealerName == dealerFalse && zipCode == zipCodeFalse) // check if dealername is equal to the dealer false. also, check if zipcode is equal to zipcode false
        {
            
            cout << "this user already exist \n"; // print this user already exist to the user
            dealerDatebase.close(); // close dealerDatebase file
            main(); // return to main function
        }
    if (dealerName!=dealerFalse && zipCode != zipCodeFalse) // check if dealername is not equal to the dealer false. also, check if zipcode is not equal to zipcode false
    {
        dealerDatebase << dealerName << ' ' << zipCode << ' ' << phoneNumber <<"\n"; // add the dealername, zipcode and phonenumber to the dealerDatebase file
    }
    if (dealerName!= dealerFalse && zipCode == zipCodeFalse) // check if dealername is not equal to the dealer false. also, check if zipcode is equal to zipcode false
    {
        dealerDatebase << dealerName << ' ' << zipCode << ' ' << phoneNumber <<"\n"; // add the dealername, zipcode and phonenumber to the dealerDatebase file
    }
    if (dealerName==dealerFalse && zipCode!= zipCodeFalse){ // check if dealername is equal to the dealer false. also, check if zipcode is not equal to zipcode false
        dealerDatebase << dealerName << ' ' << zipCode << ' ' << phoneNumber <<"\n"; // add the dealername, zipcode and phonenumber to the dealerDatebase file
    }
    
    dealerDatebase.close(); // close the dealerDatebase file
    main(); // return to the main function
    
}
/*
 * this function read all the information which is in dealerDatebase and print all the information to the user.
 */
void dealershipList()
{
    string dealernamePrint; // creating a string variable for the dealer name;
    int zipcodePrint; // creating an integer variable for the zip code;
    string phonenumberPrint; // creating a string variable for the Phonenumber;
    ifstream theFile("dealerDatebase.txt"); // open the dealerDatebase file
    while (theFile >> dealernamePrint >> zipcodePrint >> phonenumberPrint){ // from the dealerDatebase file read the first string and store it in dealernamePrint, second integer and store it in the zipcodePrint and third string and store it phonenumberPrint until there is not not value in the file
        cout << left << setw(20) << dealernamePrint << " " << zipcodePrint << " " << phonenumberPrint <<"\n"; // print the dealername, zipcode and phonenumber with a with of 20 from the left.
    }
    main(); // return  to the main function
}
/*
 * this function read all the information which is in car and print all the information to the user.
 */
void carList()
{
    string VINPrint; // creating a string variable for the VIN of the car
    int milesPrint; // creating an integer variable for the miles of the car
    string dealershipNamePrint; // creating a string variable for the dealership of the car
    int pricePrint; // creating an integer variable for the price of the car
    ifstream readFile("car.txt"); // open the car file
    while (readFile >> VINPrint >> milesPrint >> dealershipNamePrint >>pricePrint) // from the car file read the fist string and store it in the VIN of the car, read the second value and store it in the milesPrint, read the third value and store it in dealership and read the four value and store in the price and continue to do until there is not more information in the car file
    {
        cout <<VINPrint << " " << milesPrint << " " << dealershipNamePrint << " " << pricePrint <<"\n"; // print to the user the VIN of the car, miles of the car, dealership of the car and price of the car with space between each one.
    }
    main(); // return to the main function
}
/*
 * read in from the user a string and then open the manufactureDatebase file , car file and dealerdatebase file and compare things from them. also, print it
 */

void findManufacturer()
{
    string namemanufacturerFind; // creating a atring variable for the name of the manufacturer
    cin >> namemanufacturerFind; // read in from the user the name of the manufacturer
    
    ifstream manufacturerFind("manufactureDatebase.txt"); // open the manufactureDatebase.txt file so we can read the file
    string abbvmanufacturerFind; // creating a atring variable for the abbreviation of the manufacturer
    string actualnameFind; // creating a atring variable for the name of the manufacturer
    
    while (manufacturerFind >> abbvmanufacturerFind >> actualnameFind){ // read in every string from the file and store it until there is nothing in the file
        if(namemanufacturerFind==actualnameFind){ // check if the name of the manufacture is equal to the actual name of the manufacturer
            ifstream carFind("car.txt"); // open the car.txt file so we can read the file
            string VINFind; // creating a string variable for the name of the manufacturer
            int milesFind; // creating an integer variable for the miles
            string dealershipFind; // creating a string variable for the dealer name
            int priceFind; // creating an integer variable for the price
            while(carFind >> VINFind >> milesFind >> dealershipFind >> priceFind){ // read in every string and integer from the file and store it until there is nothing in the file
                if (abbvmanufacturerFind.at(0)==VINFind.at(0) && abbvmanufacturerFind.at(1)==VINFind.at(1) && abbvmanufacturerFind.at(2)==VINFind.at(2)){ // check if the first three letters of the VIN and abbrevition are equals
                    ifstream dealerFind("dealerDatebase.txt"); // open the dealerDatebase .txt file so we can read the file
                    string dealernameFind; // creating a string variable for the dealer name
                    int zipcodeFind; // creating an integer variable for the zip code
                    string phonenumberFind; // creating a string variable for the phoneNumber
                    while(dealerFind >>dealernameFind >>zipcodeFind >> phonenumberFind){ // read in every string and integer from the file and store it until there is nothing in the file
                        if(dealershipFind==dealernameFind){ // check if the dealershipFind is equal to dealernameFind
                            cout << actualnameFind << ":" << milesFind << " miles, $"  <<priceFind<<": " << dealernameFind <<"[("
                            << phonenumberFind.at(0) << phonenumberFind.at(1) << phonenumberFind.at(2) <<")" << phonenumberFind.at(3) <<phonenumberFind.at(4)<< phonenumberFind.at(5)
                            <<"-" << phonenumberFind.at(6)<< phonenumberFind.at(7)<< phonenumberFind.at(8)<< phonenumberFind.at(9)<<"]"<< endl; // print to the user the actualnamefind, miles, price, dealername and phonenumber.
                            
                        }
                    }
                }
            }
        }
    }
    main(); // return to the main function
}
/*
 * read in from the user a string and then open the manufactureDatebase file , car file and dealerdatebase file and compare things from them. also, print it
 */
void findZipcode()
{
    int zipcodeEnter; // creating an integer variable for the zip code enter
    cin >> zipcodeEnter; // read in from the user the zipcode enter
    
    ifstream dealerFind2("dealerDatebase.txt"); // // open the dealerDatebase.txt file so we can read the file
    string dealernameFind2; // creating a string variable for the dealer name
    int zipcodeFind2; // creating an integer variable for the zip code
    string phonenumberFind2; // creating a string variable for the phoneNumber
    
    while(dealerFind2 >>dealernameFind2 >>zipcodeFind2 >> phonenumberFind2){ // read in every string and integer from the file and store it until there is nothing in the file.
        if (zipcodeFind2==zipcodeEnter){ // check if zipcodeFind2 is equal to the zipcodeEnter
            ifstream carFind2("car.txt"); // open the car.txt file so we can read the file
            string VINFind2; // creating a string variable for the name of the manufacturer
            int milesFind2; // creating an integer variable for the miles
            string dealershipFind2; // creating a string variable for the dealer name
            int priceFind2; // creating an integer variable for the price
            while(carFind2 >> VINFind2 >> milesFind2 >> dealershipFind2 >> priceFind2){ //// read in every string and integer from the file and store it until there is nothing in the file
                if(dealershipFind2==dealernameFind2){ // check if dealershipFind2 is equal to dealernameFind2
                    ifstream manufacturerFind2("manufactureDatebase.txt"); //// open the manufactureDatebase.txt file so we can read the file
                    string abbvmanufacturerFind2; // creating a atring variable for the abbreviation of the manufacturer
                    string actualnameFind2; // creating a atring variable for the name of the manufacturer
                    while (manufacturerFind2 >> abbvmanufacturerFind2 >> actualnameFind2)
                        if (abbvmanufacturerFind2.at(0)==VINFind2.at(0) && abbvmanufacturerFind2.at(1)==VINFind2.at(1) && abbvmanufacturerFind2.at(2)==VINFind2.at(2)){ // check if the first three letters of the VIN and abbrevition are equals
                            cout << actualnameFind2 << ":" << milesFind2 << " miles, $"  <<priceFind2<<": " << dealernameFind2 <<"[("
                            << phonenumberFind2.at(0) << phonenumberFind2.at(1) << phonenumberFind2.at(2) <<")" << phonenumberFind2.at(3) <<phonenumberFind2.at(4)<< phonenumberFind2.at(5)
                            <<"-" << phonenumberFind2.at(6)<< phonenumberFind2.at(7)<< phonenumberFind2.at(8)<< phonenumberFind2.at(9)<<"]"<< endl; // print to the user the actualnamefind, miles, price, dealername and phonenumber.
                            
                        }
                }
            }
        }
    }
    main(); // return to the main function
}

/*
 * this function quit the program and print thanks for using this datebase system
 */
void quitProgram()
{
    cout << "thanks for using this datebase system\n"; // print to the user thanks for using this datebase system
}



