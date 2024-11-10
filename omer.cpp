#include<iostream>
#include "faizan.h"
#include<string>
#include<sstream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<set>
#include<time.h>
#include<cstdio>
#include<windows.h>  //For Sleep() function
using namespace std;
class Authentication{                               //for authentication
    public:
    bool validpassword(string password){
    if(password.length()<8||password.length()>=13){
        return false;
    }
    bool upper=false;
    bool lower=false;
    bool special=false;
    bool digit=false;
    for(int i=0;i<password.length();i++){
        char c=password[i];
		if(isupper(c)){

            upper=true;
        }
        else if(islower(c)){
            lower=true;
        }
        else if(isdigit(c)){
            digit=true;
        }
        else if(!isalnum(c)){
            special=true;
        }
    }
    return upper&&lower&&digit&&special;
}
 void admin_authentication() {
    ifstream infile("admin_password.txt");
    if (!infile) {
        cout << "Password file not found." << endl;
        return;
    }
    string saved_password;
    getline(infile, saved_password);
    infile.close();

    string password;
    bool authenticated = false;
    while (!authenticated) {
        cout<< "Enter password: ";
        cin >> password;
     
        if (password == saved_password && validpassword(password)) {
            authenticated = true;
            cout <<"\t\tWaiting for Authentication! Please wait...\n";
            Sleep(2000);
            system("cls");
            cout<<"\n\t\t\tAuthentication completed!\n";
            cout << "\t\t\tPress any key to continue...\n";
            system("pause > nul"); // Wait for the user to press any key
        } else {
            cout << "Invalid admin password. Please try again." <<endl;
        }
    }
}
};
//vehicle
class Vehicle{
    private:
    string company_name;
    string model;
    string no_plate;
    string color;
    string type;
    float price;
    bool isAvailable=true;
    public:
    Vehicle(){}
    string getcopmanyname()
    {
        return company_name;
    }
    string  getmodel(){
        return model;
    }
    string  getnoPlate(){
        return no_plate;
    }
    string  getcolor(){
        return color;
    }
    float getprice(){
        return price;
    }
    bool getavailable(){
        return isAvailable;
    }
    string gettype(){
        return  type;
    }
   void setCompanyName(const string& companyName) {
    company_name = companyName;
}

void setModel(const string& modelName) {
    model = modelName;
}

void setNumberPlate(const string& numberPlate) {
    no_plate = numberPlate;
}

void setColor(const string& vehicleColor) {
    color = vehicleColor;
}

void setPrice(float vehiclePrice) {
    price = vehiclePrice;
}

void setAvailability(bool availability) {
    isAvailable = availability;
}

void setType(const string& vehicleType) {
    type = vehicleType;
}

    
    void virtual setvehicledetails(){
        cout<<"\n\n";
        cout<<"Enter the Company name:\n";
        cin>>company_name;
        cout<<"Enter the model:\n";
        cin.ignore();
        cin>>model;
        cout<<"Enter the number plate:\n";
        cin>>no_plate;
        cout<<"Enter the color:\n";
        cin>>color;
        cout<<"Enter the Vehicle type:\n";
        cin>>type;
        cout<<"Enter the rent for one hour:\n";
        cin>>price;
        cout<<"Enter the availability status: "<<"1=available 0=not available\n";
        cin>>isAvailable;
    }
    void virtual storeVehiclesinfo() {
    ofstream outFile("vehicle_info.txt", ios::app);
    if (outFile.is_open()) {
        outFile<< getcopmanyname() << endl;
        outFile << getmodel() << endl;
        outFile  << getnoPlate() << endl;
        outFile << getcolor() << endl;
        outFile<<gettype()<<endl;
        outFile<<getprice()<<endl;
        outFile<<getavailable()<<endl;
        cout << "Vehicle information stored successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open the file for Vehicle data." << endl;
    }
}
    
   void virtual display()
{
   system("cls");
   cout<<"\n\n";
   
   cout<<"\t\tCompany Name:         "<<getcopmanyname()<<endl;
   cout<<"\t\tModel Name:           "<<getmodel()<<endl;
   cout<<"\t\tNumber Plate:         "<<getnoPlate();
   cout<<"\t\tColor:                "<<getcolor()<<endl;
   cout<<"\t\tType:                 "<<gettype()<<endl;
   cout<<"\t\tPrice:                "<<getprice()<<endl;
   cout<<"\t\tAvailability:         "<<getavailable()<<endl;
   cout<<"===============================================\n";

}

};

class Car : public Vehicle {
private:
string transmission;
int mileage;
   public:
   void setTransmission(const string t){
    transmission =t;
   } 
   void setmileage(int m){
    mileage=m; 
   }
    Car(){}
    string gettransmission(){return transmission;}
    int getmileage(){return mileage;}
    void setvehicledetails()override{
         cout<<"Enter the Company name:\n";
         string companyname;
        cin>>companyname;
       setCompanyName(companyname);
        cout<<"Enter the model:\n";
        string model;
        cin.ignore();
        cin>>model;
         setModel(model);
        cout<<"Enter the number plate:\n";
        string noplate;
        cin>>noplate;
        setNumberPlate(noplate);
        cout<<"Enter the color:\n";
        string color;
        cin>>color;
        setColor(color);
       
        cout<<"Enter the mileage:\n";
        cin>>mileage;
        setmileage(mileage);
       
        cout<<"Enter the rent for one hour:\n";
        double price;
        cin>>price;
        setPrice(price);
        cout<<"Enter the availability status:\n 1=available \n0=not available\n";
        bool isAvailable;
        cin>>isAvailable;
        setAvailability(isAvailable);
       
    }
    void virtual storeVehiclesinfo() {
    ofstream outFile("car_info.txt", ios::app);
    if (outFile.is_open()) {
         outFile  << getnoPlate() << endl;
        outFile<< getcopmanyname() << endl;
        outFile << getmodel() << endl;
       
        outFile << getcolor() << endl;
        outFile <<getmileage()<<endl;
        outFile<<getprice()<<endl;
        outFile<<getavailable()<<endl;
        cout << "Vehicle information stored successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open the file for Vehicle data." << endl;
    }
}
    
   void viewCarDetailsFromFile() {
    system("cls");
    cout << "\t\t Total Available Cars\n";
    ifstream carDetailsFile("car_info.txt");
    if (carDetailsFile.is_open()) {
        string line;
        int count = 0;
        // Read and display each line (car details) from the file
        while (getline(carDetailsFile, line)) {
            // Split the line into individual details
            stringstream ss(line);
            string companyName, modelName, numberPlate,
             color, transmission, type, availability;
            int mileage;
            double price;
            // Extract details from the line
            ss >> companyName >> modelName >> numberPlate >> color >>  mileage >>  price >> availability;
            // Display the details
            cout<<"\n\n";
            
            cout << "\t\tCompany Name: " << companyName <<endl;
            cout << "\t\tModel Name: " << modelName << endl;
            cout << "\t\tNumber Plate: " << numberPlate << endl;
            cout << "\t\tColor: " << color << endl;
          
            cout << "\t\tMileage: " << mileage << endl;
           
            cout << "\t\tPrice: " << price << endl;
            cout << "\t\tAvailability: " << availability << endl;
            cout << "=================================================" << endl;
            ++count;
        }
        if (count == 0) {
            cout << "No cars available at the moment." << endl;
        }
        carDetailsFile.close();
    } else {
        cout <<"Unable to open the file for reading car details." << endl;
    }
}

};
class Van : public Vehicle {
private:
int cargocapacity;
   public:
   void setcargocapacity(int a){
    cargocapacity=a;
   }
    Van(){}
    int getcapacity(){return cargocapacity;}
        void setvehicledetails()override{
        cout<<"Enter the Company name: ";
        string companyname;
        cin>>companyname;
       setCompanyName(companyname);
      
        cout<<"Enter the model: ";
         string model;
        cin.ignore();
        cin>>model;
         setModel(model);
       
        cout<<"Enter the number plate: ";
        string noplate;
        cin>>noplate;
        setNumberPlate(noplate);
        cout<<"Enter the color: ";
          string color;
        cin>>color;
        setColor(color);
        cout<<"Enter cargo capacity:";
        cin>>cargocapacity;
        setcargocapacity(cargocapacity);
        cout<<"Enter the rent for one hour:";
        double price;
        cin>>price;
        setPrice(price);
        cout<<"Enter the availability status: "<<"1=available 0=not available ";
         bool isAvailable;
        cin>>isAvailable;
        setAvailability(isAvailable);
    }
    void virtual storeVehiclesinfo() {
    ofstream outFile("van_info.txt", ios::app);
    if (outFile.is_open()) {
        outFile  << getnoPlate() << endl;
        outFile<< getcopmanyname() << endl;
        outFile << getmodel() << endl;
        outFile << getcolor() << endl;
        outFile << cargocapacity << endl;
        outFile<<getprice()<<endl;
        outFile<<getavailable()<<endl;
        Sleep(700);
        cout<< "Vehicle information stored successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open the file for Vehicle data." << endl;
    }
}
    
    void display() override {
    system("cls");
    cout <<"\t\t Total Available Vans\n";
    ifstream vanDetailsFile("van_info.txt");
    if (vanDetailsFile.is_open()) {
        string line;
        int count = 0;
        // Read and display each line (van details) from the file
        while (getline(vanDetailsFile, line)) {
            // Split the line into individual details
            stringstream ss(line);
            string companyName, modelName, numberPlate, color;
            int cargoCapacity;
            double price;
            bool availability;
            // Extract details from the line
            ss >> companyName >> modelName >> numberPlate >> 
            color >> cargoCapacity >> price >> availability;
            // Display the details
            
            cout << "\t\tNumber Plate:      " << numberPlate << endl;
            cout << "\t\tCompany Name:      " << companyName << endl;
            cout << "\t\tModel Name:        " << modelName << endl;
            cout << "\t\tColor:             " << color << endl;
            cout << "\t\tCargo Capacity:    " << cargoCapacity << " cubic feet" << endl;
            cout << "\t\tPrice:             " << price << endl;
            cout << "\t\t\vailability:      " << availability  << endl;
            cout << "=============================================" << endl;
            ++count;
        }
        if (count == 0) {
            cout << "No vans available at the moment." << endl;
        }
        vanDetailsFile.close();
    } else {
        cout << "Unable to open the file for reading van details." << endl;
    }
}



};

class customer{
    private:
    string name,CNIC,address,email,contact;
    
    set<string> registeredCNICs;
    public:
    string getname(){return name;}
    string getCNIC(){return CNIC;}
    string getaddress(){return address;}
    string getemail(){return email;}
    string getcontact(){return contact;}
    void setData()  {
        cout << "Enter Customer Name: ";
        
        getline(cin,name);
        //cin.ignore();
        cout << "Enter CNIC: ";
        cin >> CNIC;
        cout << "Enter Address: ";
         cin.ignore();
        getline(cin,address);
        cout<< "Enter Email: ";
        // cin.ignore();
        cin>>email;
        cout << "Enter Contact Number: ";
        //cin.ignore();
        cin >> contact;
        cin.ignore();
    }
    void storeCustomerInfo(const customer& customer) {
    ofstream outFile("customer_info.txt", ios::app);
    if (outFile.is_open()) {
        outFile<< customer.name << endl;
        outFile << customer.contact << endl;
        outFile  << customer.CNIC << endl;
        outFile << customer.address << endl;
        outFile<<customer.email<<endl;
        Sleep(1000);
        cout << "Customer information stored successfully." << endl;
        outFile.close();
    } else {
        cout << "Unable to open the file for customer data." << endl;
    }
}
///////////////
        void customerchoices(){
    cout<<"\n\n";
    
	       cout<<"\t\t>) press 1 for vehicle renting\n";
	       cout<<"\t\t>) press 2 for vehicle return\n";
           cout<<"\t\t>) press 3 to view all vehilce\n";
           cout<<"\t\t>) press 4 to go back to main\n";
           cout<<"\t\t>) press 5 to view his rental report\n";
           cout<<"\t\t>) press 0 for exit\n";
	     
}

 void registerCustomer() {
    string name, CNIC, address, email;
    long long int contact;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter CNIC: ";
    cin >> CNIC;
    
    ifstream inFile("customer_info.txt");
    string line;
    bool cnicExists = false;
    while (getline(inFile, line)) {
        if (line == CNIC) {
            cnicExists = true;
            break;
        }
    }
    inFile.close();
    if (cnicExists) {
        cout << "Customer with the same CNIC already exists." << endl;
        string loginChoice;
        while (true) {
            cout << "Do you want to login (L) or exit (E)? ";
            cin >> loginChoice;
            if (loginChoice == "L" || loginChoice == "l") {
                if (loginCustomer()) {
                    return;
                }
            } else if (loginChoice == "E" || loginChoice == "e") {
                exit(0);
            } else {
                cout << "Invalid choice. Please enter L to login or E to exit." << endl;
            }
        }
    }
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Contact Number: ";
    cin >> contact;
    registeredCNICs.insert(CNIC);
    ofstream cust("customer_car_rent.txt",ios::app);
    ofstream outFile("customer_info.txt", ios::app);
    if (outFile.is_open()) {
        outFile << name << "\n" << CNIC << "\n" << address << "\n" << email << "\n" << contact << endl;
         cust << name << "\n" << CNIC << "\n" << address << "\n" << email << "\n" << contact << endl;
        outFile.close();
        cust.close();
        Sleep(1500);
        cout << "Customer registered successfully." << endl;
    } else {
        cout << "Unable to open the file for customer registration." << endl;
    }
}
 bool loginCustomer() {
    string CNIC;
    cout << "Enter CNIC: ";
    cin >> CNIC;

    // Read customer data from file
    ifstream inFile("customer_info.txt");
    if (!inFile) {
        cout <<"Customer data file not found." << endl;
        return false;
    }

    string name, cnic, address, email, contact;
    bool customerFound = false;
    while (getline(inFile, name)) {
        getline(inFile, cnic);
        getline(inFile, address);
        getline(inFile, email);
        getline(inFile, contact);       
        if (cnic == CNIC) {
            cout << "\t\tCustomer login successful!" << endl;
            customerFound = true;
            break;
        }
    }
    
    inFile.close();

    if (!customerFound) {
        cout << "Invalid CNIC. Login failed." << endl;
    }

    return customerFound;
}
void returnCar() {          //return car function
    string plate;
    cout << "Enter the license plate number of the car to return: ";
    cin.ignore();
    getline(cin, plate);

    ifstream rentedCarsFile("rented_car.txt");
    ofstream tempFile("temp.txt"); // Open in write mode
    ofstream carinfo("car_info.txt",ios::app);
    if (!rentedCarsFile.is_open()) {
        cerr << "Error: Unable to open rented car file." << endl;
        return;
    }
    if (!tempFile.is_open()) {
        cerr << "Error: Unable to create temporary file." << endl;
        rentedCarsFile.close(); // Close the file before returning
        return;
    }

    bool carFound = false;
    string line;
    while (getline(rentedCarsFile, line)) {
        if (line == plate) {
            carFound = true;
            carinfo<<line<<endl;
            // Skip all lines related to the car by not writing them to the temp file
            for (int i = 0; i < 6; ++i) {
                getline(rentedCarsFile, line);
                carinfo<<line<<endl;
            }
        } else {
            tempFile << line << endl;
        }
    }
    rentedCarsFile.close();
    tempFile.close();

    if (!carFound) {
        cout << "Car with license plate " << plate << " was not found in the rented cars list." << endl;
        remove("temp.txt"); // Remove the temporary file
    } else {
        if (remove("rented_car.txt") != 0) {
            cerr << "Error: Unable to remove rented car file." << endl;
            return;
        }
        if (rename("temp.txt", "rented_car.txt") != 0) {
            cerr << "Error: Unable to rename temporary file." << endl;
            return;
        }
        cout << "Car with license plate " << plate << " has been successfully returned." << endl;
    }
}
void returnVan() {          //return van function
    string plate;
    cout << "Enter the license plate number of the van to return: ";
    cin.ignore();
    getline(cin, plate);

    ifstream rentedCarsFile("rented_van.txt");
    ofstream tempFile("temp.txt"); // Open in write mode
    ofstream carinfo("van_info.txt",ios::app);
    if (!rentedCarsFile.is_open()) {
        cerr << "Error: Unable to open rented van file." << endl;
        return;
    }
    if (!tempFile.is_open()) {
        cerr << "Error: Unable to create temporary file." << endl;
        rentedCarsFile.close(); // Close the file before returning
        return;
    }

    bool carFound = false;
    string line;
    while (getline(rentedCarsFile, line)) {
        if (line == plate) {
            carFound = true;
            carinfo<<line<<endl;
            // Skip all lines related to the car by not writing them to the temp file
            for (int i = 0; i < 6; ++i) {
                getline(rentedCarsFile, line);
                carinfo<<line<<endl;
            }
        } else {
            tempFile << line << endl;
        }
    }
    rentedCarsFile.close();
    tempFile.close();

    if (!carFound) {
        cout << "Van with license plate " << plate << " was not found in the rented vans list." << endl;
        remove("temp.txt"); // Remove the temporary file
    } else {
        if (remove("rented_van.txt") != 0) {
            cerr << "Error: Unable to remove rented van file." << endl;
            return;
        }
        if (rename("temp.txt", "rented_van.txt") != 0) {
            cerr << "Error: Unable to rename temporary file." << endl;
            return;
        }
        cout << "Van with license plate " << plate << " has been successfully returned." << endl;
    }
}
};
class Rental {
    private:
    
    customer c;
    Car car;
    Van van;
    string rentalDate;

public:
 string getCurrentDateTime() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char dateTime[50];
        strftime(dateTime, sizeof(dateTime), "%d/%m/%Y %H:%M:%S", ltm);
        return string(dateTime);
    }
    Rental() {
        rentalDate = getCurrentDateTime();
    }

struct rcar {
    string c1; // plate
    string c2; // brand
    string c3; // model
    string c4; // color
    string c5; // mileage
    string c6; // price
    string c7; // availability
};
// Function to generate a unique transaction ID
string generateTransactionID() {
    // Get the current time as a string
    time_t currentTime = time(nullptr);
    string timestamp = to_string(currentTime);

    // Generate a random number
    int randomNum = rand() % 10000; // Adjust the range as needed
    string randomStr = to_string(randomNum);

    // Concatenate timestamp and random number to form the transaction ID
    string transactionID = timestamp + "-" + randomStr;

    return transactionID;
}
void rentCar(const string& rentalDate) {            // rent car function
    rcar m;
    ifstream carsFile("car_info.txt");
    ofstream tempFile("temp.txt");

    if (carsFile.is_open() && tempFile.is_open()) {
        bool carFound = false;
        string plate;

        cout << "Enter the license plate number to rent a specific car: ";
        cin.ignore();
        getline(cin, plate);

        while (true) {
            getline(carsFile, m.c1); // plate
            getline(carsFile, m.c2); // brand
            getline(carsFile, m.c3); // model
            getline(carsFile, m.c4); // color
            getline(carsFile, m.c5); // mileage
            getline(carsFile, m.c6); // price
            getline(carsFile, m.c7); // availability

            if (carsFile.eof()) {
                // Write the last car details to the temp file (if it's not the rented car)
                if (m.c1 != plate) {
                    tempFile << m.c1 << endl << m.c2 << endl << m.c3 << endl
                             << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
                }
                break;
            }

            if (m.c1 == plate) {
                carFound = true;
                cout << "Details of the car with license plate " << plate << ":\n";
                cout << "Brand: " << m.c2 << endl;
                cout << "Model: " << m.c3 << endl;
                cout << "Color: " << m.c4 << endl;
                cout << "Mileage: " << m.c5 << endl;
                cout << "Price per Hour: " << m.c6 << endl;

                int hours;
                cout << "Enter the number of hours to rent the car: ";
                cin >> hours;

                double rentPerHour = stod(m.c6);
                double totalRent = rentPerHour * hours;
                // Generate unique transaction ID
                string transactionID = generateTransactionID();

                // Store rental information in rented_car.txt
                ofstream rentedCars("rented_car.txt", ios::app);
                rentedCars << m.c1 << endl << m.c2 << endl << m.c3 << endl
                           << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
                rentedCars.close();
                // Store rental information in rental_car_info.txt
                ofstream rentalInfoFile("rental_car_info.txt", ios::app);
                rentalInfoFile << "Transaction ID: " << transactionID <<endl;
                rentalInfoFile << "License Plate: " << m.c1 << endl;
                rentalInfoFile << "Brand: " << m.c2 << endl;
                rentalInfoFile << "Model: " << m.c3 << endl;
                rentalInfoFile << "Color: " << m.c4 << endl;
                rentalInfoFile << "Mileage: " << m.c5 << endl;
                rentalInfoFile << "Price per Hour: $" << rentPerHour << endl;
                rentalInfoFile << "Rental Date: " << rentalDate << endl;
                rentalInfoFile << "Rental Duration: " << hours << " hour(s)" << endl;
                rentalInfoFile << "Total Rent: $" << totalRent << endl;
                rentalInfoFile << "================================" << endl;
                rentalInfoFile.close();

                cout << "Car with license plate " << plate << " has been rented successfully for " << hours << " hours." << endl;
                cout << "Total rent: $" << totalRent << endl;
            } else {
                // Write other cars' details to the temp file
                tempFile << m.c1 << endl << m.c2 << endl << m.c3 << endl
                         << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
            }
        }

        if (!carFound) {
            cout << "Car with license plate " << plate << " not found." << endl;
        }

        carsFile.close();
        tempFile.close();

        // Replace the original file with the temp file to remove the rented car
        remove("car_info.txt");
        rename("temp.txt", "car_info.txt");
    } else {
        cout << "Unable to open the file." << endl;
    }
}
void viewRentedCars() {             // view rented cars function
    ifstream rentedCarsFile("rented_car.txt");
    if (rentedCarsFile.is_open()) {
        cout << "Rented Cars:\n";
        rcar m;
        while (true) {
            
            getline(rentedCarsFile, m.c1); // plate
            getline(rentedCarsFile, m.c2); // brand
            getline(rentedCarsFile, m.c3); // model
            getline(rentedCarsFile, m.c4); // color
            getline(rentedCarsFile, m.c5); // mileage
            getline(rentedCarsFile, m.c6); // price
            getline(rentedCarsFile, m.c7); // availability
            if (rentedCarsFile.eof()) {
                break;
            }
            cout<<BACKGROUND_BLUE;
            cout << "\t\tLicense Plate:         " << m.c1 << endl;
            cout << "\t\tBrand:                 " << m.c2 << endl;
            cout << "\t\tModel:                 " << m.c3 << endl;
            cout << "\t\tColor:                 " << m.c4 << endl;
            cout << "\t\tMileage:               " << m.c5 << endl;
            cout << "\t\tPrice per Hour:        " << m.c6<<"$" << endl;
            cout << "\t\tAvailability:          " << m.c7  << endl;
            cout << "===================================================" << endl;
        }
        rentedCarsFile.close();
    } else {
        cout << "Unable to open rented car information file." << endl;
    }
}

void rentVan(const string& rentalDate) {           // rent van function
    rcar m;
    ifstream vansFile("van_info.txt");
    ofstream tempFile("temp.txt");

    if (vansFile.is_open() && tempFile.is_open()) {
        bool carFound = false;
        string plate;

        cout << "Enter the license plate number to rent a specific car: ";
        cin.ignore();
        getline(cin, plate);

        while (true) {
            getline(vansFile, m.c1); // plate
            getline(vansFile, m.c2); // brand
            getline(vansFile, m.c3); // model
            getline(vansFile, m.c4); // color
            getline(vansFile, m.c5); // mileage
            getline(vansFile, m.c6); // price
            getline(vansFile, m.c7); // availability

            if (vansFile.eof()) {
                // Write the last car details to the temp file (if it's not the rented car)
                if (m.c1 != plate) {
                    tempFile << m.c1 << endl << m.c2 << endl << m.c3 << endl
                             << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
                }
                break;
            }

            if (m.c1 == plate) {
                carFound = true;
                cout << "Details of the car with license plate " << plate << ":\n";
                cout << "Brand: " << m.c2 << endl;
                cout << "Model: " << m.c3 << endl;
                cout << "Color: " << m.c4 << endl;
                cout << "Mileage: " << m.c5 << endl;
                cout << "Price per Hour: " << m.c6 << endl;

                int hours;
                cout << "Enter the number of hours to rent the car: ";
                cin >> hours;

                double rentPerHour = stod(m.c6);
                double totalRent = rentPerHour * hours;
                // Generate unique transaction ID
                string transactionID = generateTransactionID();

                // Store rental information in rented_car.txt
                ofstream rentedCars("rented_van.txt", ios::app);
                rentedCars << m.c1 << endl << m.c2 << endl << m.c3 << endl
                           << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
                rentedCars.close();
                // Store rental information in rental_car_info.txt
                ofstream rentalInfoFile("rental_van_info.txt", ios::app);
                rentalInfoFile << "Transaction ID: " << transactionID <<endl;
                rentalInfoFile << "License Plate: " << m.c1 << endl;
                rentalInfoFile << "Brand: " << m.c2 << endl;
                rentalInfoFile << "Model: " << m.c3 << endl;
                rentalInfoFile << "Color: " << m.c4 << endl;
                rentalInfoFile << "Mileage: " << m.c5 << endl;
                rentalInfoFile << "Price per Hour: $" << rentPerHour << endl;
                rentalInfoFile << "Rental Date: " << rentalDate << endl;
                rentalInfoFile << "Rental Duration: " << hours << " hour(s)" << endl;
                rentalInfoFile << "Total Rent: $" << totalRent << endl;
                rentalInfoFile << "================================" << endl;
                rentalInfoFile.close();

                cout << "Van with license plate " << plate << " has been rented successfully for " << hours << " hours." << endl;
                cout << "Total rent: $" << totalRent << endl;
            } else {
                // Write other cars' details to the temp file
                tempFile << m.c1 << endl << m.c2 << endl << m.c3 << endl
                         << m.c4 << endl << m.c5 << endl << m.c6 << endl << m.c7 << endl;
            }
        }

        if (!carFound) {
            cout << "Van with license plate " << plate << " not found." << endl;
        }

        vansFile.close();
        tempFile.close();

        // Replace the original file with the temp file to remove the rented car
        remove("van_info.txt");
        rename("temp.txt", "car_info.txt");
    } else {
        cout << "Unable to open the file." << endl;
    }
}
void viewRentedVan() {              // view rented van function
    ifstream rentedCarsFile("rented_van.txt");
    if (rentedCarsFile.is_open()) {
        cout << "Rented Cars:\n";
        rcar m;
        while (true) {
            getline(rentedCarsFile, m.c1); // plate
            getline(rentedCarsFile, m.c2); // brand
            getline(rentedCarsFile, m.c3); // model
            getline(rentedCarsFile, m.c4); // color
            getline(rentedCarsFile, m.c5); // mileage
            getline(rentedCarsFile, m.c6); // price
            getline(rentedCarsFile, m.c7); // availability
            if (rentedCarsFile.eof()) {
                break;
            }
            
            cout << "\t\tLicense Plate:        " << m.c1 << endl;
            cout << "\t\tBrand:                " << m.c2 << endl;
            cout << "\t\tModel:                " << m.c3 << endl;
            cout << "\t\tColor:                " << m.c4 << endl;
            cout << "\t\tCargo Capacity:       " << m.c5 << endl;
            cout << "\t\tPrice per Hour:       " << m.c6<<" $" << endl;
            cout << "\t\tAvailability:         " << m.c7<< endl;
            cout << "==============================================================" << endl;
        }
        rentedCarsFile.close();
    } else {
        cout << "Unable to open rented car information file." << endl;
    }
}

friend void displayallRentalReports();
friend void displayallvanrentalreport();
};
class customer_manager{
    public:
   void display_manager() {
    cout<<"\n\n";
    
    cout << "\t\t1. Check total cars" << endl;
    cout << "\t\t2. Check cars on rent" << endl;
    cout << "\t\t3. View all customers" << endl;
    cout << "\t\t4. View all rental reports" << endl;
    cout << "\t\t5. Go back to main" << endl;
   
}
    friend void view_all_customer();
};
class Administrator{
    public:
    void displayAdminMenu() {
         cout<<"\n\n";

    cout << "\t\t1. Add vehicle" << endl;
    cout <<  "\t\t2. Remove vehicle" << endl;
    cout << "\t\t3. Update vehicle info" <<endl;
    cout << "\t\t4. View all rental reports" <<  endl;
     cout << "\t\t5. View specific rental reports" <<  endl;
      cout << "\t\t6. Add customer" << endl;
    cout <<  "\t\t7. Remove customer" << endl;
    cout << "\t\t8. Update customer info" <<endl;
    cout << "\t\t9. View all customers" << endl;
    cout <<"\t\t10. View all vehicles" <<  endl;
    cout<<"\t\t11. View specific Customer"<<endl;
    cout<<"\t\t12. View specific  vehicle"<<endl;
    cout<<"\t\t13. Go back to main"<<endl;
    cout <<"\t\t0. Exit"  << endl;
}
   void add_customer() {                   // add customer
    string name, CNIC, address, email;
    long long int contact;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter CNIC: ";
    cin >> CNIC;

    // Check if the CNIC already exists in the database
    ifstream inFile("customer_info.txt");
    string line;
    bool cnicExists = false;
    while (getline(inFile, line)) {
        if (line == CNIC) {
            cnicExists = true;
            break;
        }
    }
    inFile.close();
    if (cnicExists) {
        cout << "Customer with the same CNIC already exists." << endl;
        return;
    }

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Contact Number: ";
    cin >> contact;

    // Append customer details to the customer_info.txt file
    ofstream outFile("customer_info.txt", ios::app);
    if (outFile.is_open()) {
        outFile << name << "\n" << CNIC << "\n" << address << "\n" << email << "\n" << contact << endl;
        outFile.close();
        cout << "Customer registered successfully." << endl;
    } else {
        cout << "Unable to open the file for customer registration." << endl;
    }
} 
void findCustomer(const string& cnic) {             // find customer function
    ifstream customerFile("customer_info.txt");
    string name,id,address,email,contact;
    bool found = false;

    while (getline(customerFile, name)) {
        getline(customerFile, id);
        getline(customerFile, address);
        getline(customerFile, email);
        getline(customerFile, contact);

        // Check if the CNIC matches
        if (id == cnic) {
            found = true;
            
            cout << "\tCustomer found:\n";
            cout << "\t\tName:               " << name << endl;
            cout << "\t\tCNIC:               " << id << endl;
            cout << "\t\tAddress:            " << address << endl;
            cout << "\t\tEmail:              " << email<<endl;
            cout << "\t\tContact:            " <<contact<<endl;
            cout <<"========================================"<<endl; // Display the additional line
            break;  // Stop searching after finding the customer
        }
    }

    if (!found) {
        cout << "Customer with CNIC " << cnic << " not found." << endl;
    }
    customerFile.close();
}
struct searchcar
{
    string c1;
    string c2;
    string c3;
    string c4;
    string c5;
    string c6;
    string c7;
};
void find_car(const string& carID) {                // find car function
    ifstream carDetailsFile("car_info.txt");
    if (carDetailsFile.is_open()) {
        searchcar car;
        bool found = false;
        while (carDetailsFile >> car.c1 >> car.c2 >> car.c3 >> car.c4 >> car.c5 >> car.c6 >> car.c7) {
            if (car.c1 == carID) {
                found = true;
                
                cout << "\t\tCar Details:\n";
                cout<<"\t\tPlate Number:             "<< car.c1 << endl;
                cout <<"\t\tCompany Name:            "<<car.c2 << endl;
                cout <<"\t\tModel Name:              "<< car.c3 << endl;
                cout<<"\t\tColor:                    "<< car.c4 << endl;
                cout <<"\t\tMilleage:                "<< car.c5 << endl;
                cout <<"\t\tRent per Hour:           "<< car.c6 << endl;
                cout <<"\t\tAvailability:            "<< car.c7 << endl;
                cout<<"============================================\n";
                break;
            }
        }
        if (!found) {
            cout << "Car with ID " << carID << " not found." << endl;
        }
        carDetailsFile.close();
    } else {
        cout << "Unable to open the file for reading car details." << endl;
    }
}
void find_van(const string& carID) {                // find van function
    ifstream carDetailsFile("van_info.txt");
    if (carDetailsFile.is_open()) {
        searchcar car;
        bool found = false;
        while (carDetailsFile >> car.c1 >> car.c2 >> car.c3 >> car.c4 >> car.c5 >> car.c6 >> car.c7) {
            if (car.c1 == carID) {
                found = true;
               
                cout << "\t\tVan Details:\n";
                cout<<"\t\tPlate Number:             "<< car.c1 << endl;
                cout <<"\t\tCompany Name:            "<<car.c2 << endl;
                cout <<"\t\tModel Name:              "<< car.c3 << endl;
                cout<<"\t\tColor:                    "<< car.c4 << endl;
                cout <<"\t\tMilleage:                "<< car.c5 << endl;
                cout <<"\t\tRent per Hour:           "<< car.c6 << endl;
                cout <<"\t\tAvailability:            "<< car.c7 << endl;
                cout<<"=================================================\n";
                break;
            }
        }
        if (!found) {
            cout << "Car with ID " << carID << " not found." << endl;
        }
        carDetailsFile.close();
    } else {
        cout << "Unable to open the file for reading car details." << endl;
    }
}
struct updatedCar {
    string plate;
    string brand;
    string model;
    string color;
    string mileage;
    string price;
    bool availability;
};
void update_car(const string& plateNumber) {
    ifstream inFile("car_info.txt");
    ofstream tempFile("temp_car_info.txt");

    if (!inFile || !tempFile) {
        cerr << "Error: Unable to open car information files." << endl;
        return;
    }

    bool carFound = false;
    string line;
    updatedCar updatedCar;
    while (getline(inFile, line)) {
        if (line == plateNumber) {
            carFound = true;
            updatedCar.plate = line;  // Store the plate number
            // Read and store the updated details for each attribute
            cout << "Enter brand: ";
            cin.ignore();
            getline(cin, updatedCar.brand);

            cout << "Enter model: ";
            getline(cin, updatedCar.model);

            cout << "Enter color: ";
            getline(cin, updatedCar.color);

            cout << "Enter mileage: ";
            getline(cin, updatedCar.mileage);

            cout << "Enter price: ";
            getline(cin, updatedCar.price);

            cout << "Enter availability (1 for available, 0 for not available): ";
            cin >> updatedCar.availability;
            cin.ignore(); // Clear the newline character from the input buffer
        } else {
            // If the current line doesn't match the plate number, write it to the temp file as is
            tempFile << line << endl;
        }
    }

    inFile.close();

    if (carFound) {
        // Write the updated car details to the temp file
        tempFile << updatedCar.plate << endl;
        tempFile << updatedCar.brand << endl;
        tempFile << updatedCar.model << endl;
        tempFile << updatedCar.color << endl;
        tempFile << updatedCar.mileage << endl;
        tempFile << updatedCar.price << endl;
        tempFile << updatedCar.availability << endl;
        cout << "Car details updated successfully." << endl;
    } else {
        cout << "Error: Car with plate number " << plateNumber << " not found." << endl;
    }

    tempFile.close();

    // Rename the temporary file to overwrite the original car_info file
    if (carFound) {
        remove("car_info.txt");
        rename("temp_car_info.txt", "car_info.txt");
    }
}
void update_van(const string& plateNumber) {            //update van function
    ifstream inFile("van_info.txt");
    ofstream tempFile("temp_van_info.txt");

    if (!inFile || !tempFile) {
        cerr << "Error: Unable to open car information files." << endl;
        return;
    }

    bool carFound = false;
    string line;
    updatedCar updatedCar;
    while (getline(inFile, line)) {
        if (line == plateNumber) {
            carFound = true;
            updatedCar.plate = line;  // Store the plate number
            // Read and store the updated details for each attribute
            cout << "Enter brand: ";
            cin.ignore();
            getline(cin, updatedCar.brand);

            cout << "Enter model: ";
            getline(cin, updatedCar.model);

            cout << "Enter color: ";
            getline(cin, updatedCar.color);

            cout << "Enter Cargo capacity: ";
            getline(cin, updatedCar.mileage);

            cout << "Enter price: ";
            getline(cin, updatedCar.price);

            cout << "Enter availability (1 for available, 0 for not available): ";
            cin >> updatedCar.availability;
            cin.ignore(); // Clear the newline character from the input buffer
        } else {
            // If the current line doesn't match the plate number, write it to the temp file as is
            tempFile << line << endl;
        }
    }

    inFile.close();

    if (carFound) {
        // Write the updated car details to the temp file
        tempFile << updatedCar.plate << endl;
        tempFile << updatedCar.brand << endl;
        tempFile << updatedCar.model << endl;
        tempFile << updatedCar.color << endl;
        tempFile << updatedCar.mileage << endl;
        tempFile << updatedCar.price << endl;
        tempFile << updatedCar.availability << endl;
        cout << "Van details updated successfully." << endl;
    } else {
        cout << "Error: Van with plate number " << plateNumber << " not found." << endl;
    }

    tempFile.close();

    // Rename the temporary file to overwrite the original car_info file
    if (carFound) {
        remove("van_info.txt");
        rename("temp_van_info.txt", "van_info.txt");
    }
}



 void remove_customer()                       //remove customer function
    {
        string cnic;
        cout << "Enter CNIC of the customer you want to remove: ";
        cin >> cnic;

        ifstream inFile("customer_info.txt");
        ofstream outFile("temp.txt");
        if (!inFile || !outFile) {
            cout << "Error: Unable to open customer data file." << endl;
            return;
        }

        string line;
        bool customerFound = false;
        while (getline(inFile, line)) {
            if (line == cnic) {
                // Skip lines corresponding to the customer to be removed
                for (int i = 0; i < 4; ++i) {
                    getline(inFile, line);
                }
                customerFound = true;
            }
            else {
                // Write lines of customers other than the one to be removed to the temp file
                outFile << line << endl;
            }
        }
        inFile.close();
        outFile.close();
        if (customerFound) {
            remove("customer_info.txt");
            rename("temp.txt", "customer_info.txt");
            cout << "Customer with CNIC " << cnic << " removed successfully." << endl;
        }
        else {
            cout << "Customer with CNIC " << cnic << " not found." << endl;
            remove("temp.txt");
        }
    }
     void update_customer_info() {
    ifstream inFile("customer_info.txt");
    ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        cout << "Error: Unable to open customer data file." << endl;
        return;
    }

    string cnicToUpdate;
    cout << "Enter the CNIC of the customer to update their data: ";
    cin >> cnicToUpdate;
    cin.ignore(); // Ignore the newline character

    string name, CNIC, address, email;
    long long int contact;
    bool customerFound = false;

    while (getline(inFile, name)) {
        // Read the data for the current customer
        getline(inFile, CNIC);
        
        inFile.ignore(); // Ignore the newline character
        inFile >> contact;
        getline(inFile, address);
        getline(inFile, email);

        if (CNIC == cnicToUpdate) {
            customerFound = true;
            cout << "Enter the updated name of the customer: ";
            getline(cin, name);
            cout << "Enter the updated contact of the customer: ";
            cin >> contact;
            cin.ignore(); // Ignore the newline character
            cout << "Enter the updated CNIC of the customer: ";
            getline(cin, CNIC);
            cout << "Enter the updated address of the customer: ";
            getline(cin, address);
            cout << "Enter the updated email of the customer: ";
            getline(cin, email);
        }

        // Write the customer data to the output file
        outFile << name << endl;
         outFile << CNIC << endl;
        outFile << address << endl;
        outFile << email << endl;
         outFile << contact << endl;
    }

    inFile.close();
    outFile.close();

    if (!customerFound) {
        cout << "No record found for the entered CNIC." << endl;
        remove("temp.txt"); // Delete the temporary file if no updates were made
    } else {
        // Replace the original file with the updated file
        remove("customer_info.txt");
        rename("temp.txt", "customer_info.txt");
        cout << "Customer information updated successfully." << endl;
    }
}
    friend void viewcar();
    friend void add_car();
    friend void remove_car();
    friend void add_van();
    friend void remove_van();
    friend void viewvan();
    
};
///-------------------friend functions-------------------/////////////////////
void displayallRentalReports() {               // view all rental reports
    ifstream rentalInfoFile("rental_car_info.txt");
    if (rentalInfoFile.is_open()) {
        string line;
        while (getline(rentalInfoFile, line)) {
            cout << line << endl; // Simply output each line of the rental report
        }
        rentalInfoFile.close();
    } else {
        cout << "Unable to open rental information file." << endl;
    }
}
void displayallvanrentalreport() {               // view all rental reports
    ifstream rentalInfoFile("rental_van_info.txt");
    if (rentalInfoFile.is_open()) {
        string line;
        while (getline(rentalInfoFile, line)) {
            cout << line << endl; // Simply output each line of the rental report
        }
        rentalInfoFile.close();
    } else {
        cout << "Unable to open rental information file." << endl;
    }
}
void display_specific_Rental_Report(const string& transactionID) {
    ifstream rentalInfoFile("rental_car_info.txt");
    if (rentalInfoFile.is_open()) {
        string line;
        bool found = false;
        while (getline(rentalInfoFile, line)) {
            if (line.find("Transaction ID: " + transactionID) != string::npos) {
                found = true;
                // Output the rental report starting from the transaction ID
                cout << line << endl;
                while (getline(rentalInfoFile, line) && line != "================================") {
                    cout << line << endl;
                }
                break; // Exit the loop after finding and displaying the rental report
            }
        }
        if (!found) {
            cout << "Rental report with transaction ID " << transactionID << " not found." << endl;
        }
        rentalInfoFile.close();
    } else {
        cout << "Unable to open rental information file." << endl;
    }
}

void display_specific_van_Rental_Report(const string& transactionID) {
    ifstream rentalInfoFile("rental_van_info.txt");
    if (rentalInfoFile.is_open()) {
        string line;
        bool found = false;
        while (getline(rentalInfoFile, line)) {
            if (line.find("Transaction ID: " + transactionID) != string::npos) {
                found = true;
                // Output the rental report starting from the transaction ID
                cout << line << endl;
                while (getline(rentalInfoFile, line) && line != "================================") {
                    cout << line << endl;
                }
                break; // Exit the loop after finding and displaying the rental report
            }
        }
        if (!found) {
            cout << "Rental report with transaction ID " << transactionID << " not found." << endl;
        }
        rentalInfoFile.close();
    
    } else {
        cout << "Unable to open rental information file." << endl;
    }
}

void view_all_customer() {
    ifstream inFile("customer_info.txt");
    if (!inFile) {
        cout << "Unable to open customer data file." << endl;
        return;
    }

    string line;
    int customerCount = 0;

    cout << "==============================================\n";
    cout<< "           All Customers Information         \n";
    cout<< "==============================================\n";

    while (getline(inFile, line)) {
         
        cout << "Customer Name: " <<line << endl;
        getline(inFile, line);
        cout << "Contact Number: "<< line << endl;   
        getline(inFile, line); 
        cout << "CNIC: " << line << endl;
        getline(inFile, line);
        cout << "Address: " <<line << endl;
        getline(inFile, line); 
        cout << "Email: " <<line << endl;
        
        
        cout << "----------------------------------------------" << endl;
        customerCount++;
    }

    if (customerCount == 0) {
        cout << "No customers found." << endl;
    } else {
        cout << "Total Customers: " << customerCount << endl;
    }

    inFile.close();
}

void add_car()              // add car function
 {
    Car car;
    car.setvehicledetails();
    car.storeVehiclesinfo();
}
void add_van()              // add van function
{
    Van van;
    van.setvehicledetails();
    van.storeVehiclesinfo();
}
void remove_car() {            // remove car function
    string plateNumber;
    cout << "Enter the number plate of the car you want to remove: ";
    cin >> plateNumber;

    ifstream inFile("car_info.txt");
    ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        cout << "Error: Unable to open vehicle data file." << endl;
        return;
    }

    string line;
    bool carFound = false;
    while (getline(inFile, line)) {
        if (line == plateNumber) {
            // Skip lines corresponding to the car to be removed
            for (int i = 0; i < 6; ++i) {
                getline(inFile, line);
            }
            carFound = true;
        } else {
            // Write lines of cars other than the one to be removed to the temp file
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();
    if (carFound) {
        remove("car_info.txt");
        rename("temp.txt", "car_info.txt");
        cout << "Car with number plate " << plateNumber << " removed successfully." << endl;
    } else {
        cout << "Car with number plate " << plateNumber << " not found." << endl;
        remove("temp.txt");
    }
}
void remove_van() {            // remove car function
    string plateNumber;
    cout << "Enter the number plate of the car you want to remove: ";
    cin >> plateNumber;

    ifstream inFile("van_info.txt");
    ofstream outFile("temp.txt");
    if (!inFile || !outFile) {
        cout << "Error: Unable to open vehicle data file." << endl;
        return;
    }

    string line;
    bool carFound = false;
    while (getline(inFile, line)) {
        if (line == plateNumber) {
            // Skip lines corresponding to the car to be removed
            for (int i = 0; i < 6; ++i) {
                getline(inFile, line);
            }
            carFound = true;
        } else {
            // Write lines of cars other than the one to be removed to the temp file
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();
    if (carFound) {
        remove("van_info.txt");
        rename("temp.txt", "car_info.txt");
        cout << "Van with number plate " << plateNumber << " removed successfully." << endl;
    } else {
        cout << "Van with number plate " << plateNumber << " not found." << endl;
        remove("temp.txt");
    }
}
void viewcar() {
    system("cls");
    cout << "\t\t Total Available Cars\n";
    ifstream carDetailsFile("car_info.txt");
    if (carDetailsFile.is_open()) {
        string numberPlate, companyModel, modelName, color, mileage, rentPerHour, availability;
        int count = 0;
        while (carDetailsFile >> numberPlate >> companyModel >> modelName >> color >> mileage >> rentPerHour >> availability) {
           
            cout << "\t\tNumber Plate:       " << numberPlate << endl;
            cout << "\t\tCompany Model:      " << companyModel << endl;
            cout << "\t\tModel Name:         " << modelName << endl;
            cout << "\t\tColor:              " << color << endl;
            cout << "\t\tMileage:            " << mileage << endl;
            cout << "\t\tRent per Hour:      " << rentPerHour << endl;
            cout << "\t\tAvailability:       " << availability << endl;
            cout << "============================================\n";
            ++count;
        }
        if (count == 0) {
            cout << "No cars available at the moment." << endl;
        }
        carDetailsFile.close();
    } else {
        cout << "Unable to open the file for reading car details." << endl;
    }
}
void viewvan() {                
    system("cls");
    cout << "\t\t Total Available Vans\n";
    ifstream carDetailsFile("van_info.txt");

    // Check if the file is open
    if (!carDetailsFile.is_open()) {
        cerr << "Unable to open the file for reading car details." << endl;
        return;
    }

    string numberPlate, companyModel, modelName, color, cargo, rentPerHour, availability;
    int count = 0;

    // Read data from the file
    while (carDetailsFile >> numberPlate >> companyModel >> modelName >> color >> cargo >> rentPerHour >> availability) {
       
        cout << "\t\tNumber Plate:              " << numberPlate << endl;
        cout << "\t\tCompany Model:             " << companyModel << endl;
        cout << "\t\tModel Name:                " << modelName << endl;
        cout << "\t\tColor:                     " << color << endl;
        cout << "\t\tCargo Capacity:            " << cargo << endl;
        cout << "\t\tRent per Hour:             " << rentPerHour << endl;
        cout << "\t\tAvailability:              " << availability << endl;
        cout << "===============================================\n";
        ++count;
    }

    // Check if any cars were found
    if (count == 0) {
        cout << "No vans available at the moment." << endl;
    }

    // Close the file
    carDetailsFile.close();
}

void printstyletext()           // front Entry
{
    cout<<endl;
    
    cout <<"\t\t=================================================================\n";
    cout <<  "\t\t\t\t WELCOME TO AUTOLINK RENTALS\n";
    cout << "\t\t=================================================================\n";
    cout << endl;
    cout << "\t\t\t\t  Made by: Umer Jabbar\n";
    cout << "\t\t\t\t  Made by: Ali Hussnain\n";
    cout << "\t\t\t\t  (2023-CS-611)\n";
    cout << "\t\t\t\t  (2023-CS-613)\n";
    cout << "\t\t\t\t  Powered by: PakeWheels.com\n";
    cout << "\t\t\t\t =====================\n";
    
    cout << "\t\t\t\t Feel Free To Choose the Best Cars\n";
    
}
///* ======================================================================////////////////
int main() {
        printstyletext();
        Car car;
        Van van;
        Authentication authenticate;
        Vehicle vehicle;
        customer cus;
        Rental rental;
        Administrator admin;
        customer_manager cusmanager;
        string plate;           //plate for rent
         bool isAuthenticated = false; // for customer manager
         string  updateCar; // for update car info
         string  updatevan; // for update van info
         string cn;     // for cnic finding customer
         string cr;    // for cr  finding car
         string vr;    // for vr finding van
         string transactionID;  // for finding particular rental report for car
         string transactionid;  // for finding particular rental report for van
         cout<<"Press any key to continue\n";
    system("pause > nul"); // Wait for the user to press any key (Windows specific)
    string choice;
    system("cls");
     while(true){
        
    cout<< "=================================================================\n";
    cout<<"Are you\n1) admin\n2)customer_manager\n3)customer\n";
    cout<<"Choice: ";
    cin>>choice;
    Sleep(1000);
    system("cls");
        if (choice == "customer" || choice == "CUSTOMER") {
    while (true) {
        cout << "1. Register\n2. Login\nEnter your choice (0 to exit): ";
        int cuschoice;
        cin >> cuschoice;
       
        if (cuschoice == 0) {
            break; // Exit the customer section loop
        }

        if (cuschoice == 1) {
            cus.registerCustomer();
            system("cls");
        } else if (cuschoice == 2) {
            while (!cus.loginCustomer()) {
                system("cls");
                cout << "Login failed. Please try again or press 0 to exit\n";
                cin >> cuschoice;
                if (cuschoice == 0) {
                    break; // Exit the login loop
                }
            }
        }

        // Add the flag variable to control the loop
        bool exitCustomerLoop = false;
        while (!exitCustomerLoop) {
            cus.customerchoices();
            int choice;
            cin >> choice;
            switch (choice) {
                case 0:
                exit(0);
                case 1:
                int rentchoice;
                cout<<"1. To rent cars\n";
                cout<<"2. To rent vans\n";
                cin>>choice;
                if(choice==1){
                    viewcar();
                    rental.rentCar(rental.getCurrentDateTime());
                }
                else{viewvan();
                rental.rentVan(rental.getCurrentDateTime());}
                    break;
                case 2:
                 int returnchoice;
                cout<<"1. To return cars\n";
                cout<<"2. To return vans\n";
                cin>>choice;
                switch (returnchoice)
                {
                case 1:
                    cus.returnCar();
                    break;
                case 2:
                cus.returnVan();
                break;
                default:
                cout<<"invalid choice";
                    break;
                }
                    break;
                case 3:
                int viewchoice;
                cout<<"1. To view  all cars\n";
                cout<<"2. To view all vans\n";
                cin>>viewchoice;
                switch (viewchoice)
                {
                case 1:
                    viewcar();
                    break;
                case 2:
                    viewvan();
                default:
                cout<<"invalid choice";
                    break;
                }
                    
                    break;
                case 4:
                main();
                break;
                case 5:
                 int reportchoice;
                cout<<"1. To view his rental report for cars\n";
                cout<<"2. To view his rental report for vans\n";
                cin>>choice;
                switch (reportchoice)
                {
                case 1:
                cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionID;
                display_specific_Rental_Report(transactionID);
                    break;
                case 2:
                 cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionID;
                display_specific_van_Rental_Report(transactionID);
                break;
                default:
                cout<<"invalid  choice";
                    break;
                }
               
                break;    
                default:
                    break;
            }

            // Check if the user wants to exit the customer loop
            cout << "Do you want to go back to the main menu? (yes/no): ";
            string backToMainMenu;
            cin >> backToMainMenu;
            if (backToMainMenu == "yes" || backToMainMenu == "YES") {
                exitCustomerLoop = true;
                main();
            }
            else{exit;}
        }
    }
    break; // Exit the main loop
}

   else if (choice == "admin" || choice == "ADMIN") {
    while (true) {
        authenticate.admin_authentication();
        system("cls");
        admin.displayAdminMenu();
        int choice;
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
            int addchoice;
            cout<<"1. To add car\n";
            cout<<"2. To add van\n";
            cin>>addchoice;
            if(addchoice==1){
                add_car();
                }else if(addchoice==2){
                add_van();
                }
                break;
            case 2:
            int removechoice;
            cout<<"1. To remove car\n";
            cout<<"2. To remove van\n";
            cin>>removechoice;
            if(removechoice==1){
                remove_car();
                }else if(removechoice==2){
                remove_van();
                }
                break;
            case 3:
            int updatechoice;
            cout<<"1. To update cars\n";
            cout<<"2. To  update vans\n";
            cin>>updatechoice;
            if(updatechoice==1){
                viewcar();
                cout<<"\nEnter Car number to be update : ";
             cin>>updateCar;
                admin.update_car(updateCar);
                }else if(updatechoice==2){
                viewvan();
                cout<<"\nEnter van number to be update: ";
                cin>>updatevan;
                admin.update_van(updatevan);
                }
                break;
                case 4:
                int displaychoice;
                cout<<"1. To view all cars rental report\n";
                cout<<"2. To view all vans rental report\n";
                cin>>displaychoice;
                if (displaychoice==1)
                {
                    displayallRentalReports();
                }
                else if(displaychoice==2){
                    displayallvanrentalreport();
                }
                break;
                case 5:
                int choicespecificreport;
                cout<<"1. To view specific report for car\n";
                cout<<"2. To view specific report for van\n";
                cin>>choicespecificreport;
                if(choicespecificreport==1){
                     cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionID;
                display_specific_Rental_Report(transactionID);
                }
                else {
                     cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionid;
                    display_specific_van_Rental_Report(transactionid);
                }
                break;
                case 6:
                admin.add_customer();
                break;
                case 7:
                admin.remove_customer();
                break;
                case 8:
                admin.update_customer_info();
                break;
                case 9:
                view_all_customer();
                break;
                case 10:
                int viewchoice;
                cout<<"1. To view cars\n";
                cout<<"2. To view vans\n";
                cin>>viewchoice;
                if(viewchoice==1){
                    viewcar();
                }
                else{
                    viewvan();
                }
                
                break;
                case 11:
                cout<<"Enter cnic to find customer: ";
                cin>>cn;
                admin.findCustomer(cn);
                break;
                case 12:
                int findchoice;
                cout<<"1. To find car\n";
                cout<<"2. To find van\n";
                cin>>findchoice;
                if(findchoice==1){
                cout<<"Enter plate number to find car: ";
                cin>>cr;
                admin.find_car(cr);
                }
                else{
                    cout<<"Enter plate number to find van: ";
                cin>>vr;
                admin.find_van(vr);
                } 
                break;
                case 13:
                main();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                // Clear input buffer
                cin.clear();
                break;
        }
        cout << "Do you want to perform another action? (yes/no): ";
        string performAnotherAction;
        cin >> performAnotherAction;
        if (performAnotherAction != "yes" && performAnotherAction != "YES") {
            exit(0); // Exit the loop if the user doesn't want to perform another action
        }
    }
    break;
}
else if (choice == "customer_manager" || choice == "CUSTOMER_MANAGER") {
    while (true) {
        if (!isAuthenticated) { // Check if the user is not authenticated
            authenticate.admin_authentication();
            system("cls");
            // cout << "customer manager entering\n";
            cusmanager.display_manager();
            isAuthenticated = true; // Set authentication state to true after successful authentication
        }
        int choice;
        cin >> choice;
        switch (choice) {
            case 0:
                exit(0);
                break;
            case 1:
            int managerviewchoice;
            cout<<"1. To view cars\n";
            cout<<"2. To view vans\n";
            cin>>managerviewchoice;
            if (managerviewchoice==1)
            {
                viewcar();
            }
            else{viewvan();}
                break;
            case 2:
            int managerrentchoice;
            cout<<"1. To view cars on rent\n";
            cout<<"2. To view vans on rent\n";
            cin>>managerrentchoice;
            if(managerrentchoice==1){
                    rental.viewRentedCars();
            }
            else{rental.viewRentedVan();}
                break;
            case 3:
                cout << "view all customer\n";
                view_all_customer();
                break;
            case 4:
            int managerreportchoice;
            cout<<"1. To view all rental reports for car\n";
            cout<<"2.  To view all rental reports for van\n";
            cin>>managerreportchoice;
            if(managerreportchoice==1)
            {
                     displayallRentalReports();
            }
            else{
                    displayallvanrentalreport();
            }
                break;
            case 5:
            
             int choicespecificreport;
                cout<<"1. To view specific report for car\n";
                cout<<"2. To view specific report for van\n";
                cin>>choicespecificreport;
                if(choicespecificreport==1){
                     cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionID;
                display_specific_Rental_Report(transactionID);
                }
                else {
                     cout<<"Enter the transaction id to find rental report: ";
                cin>>transactionid;
                    display_specific_van_Rental_Report(transactionid);
                }
                break;
            case 6:
            main();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                continue; // Continue the loop to ask for input again
        }
        cout << "Do you want to perform another action? (yes/no): ";
        string performAnotherAction;
        cin >> performAnotherAction;
        if (performAnotherAction != "yes" && performAnotherAction != "YES") {
            exit(0); // Exit the loop if the user doesn't want to perform another action
        }
        cout << "Please enter your choice: "; // Prompt for next action
    }
}
else {
    cout << "\nWrong input! Please enter either 'customer', 'admin', or 'customer_manager'. \n";
}
}
return 0;
}
         