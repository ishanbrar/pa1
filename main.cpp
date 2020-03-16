//
//  main.cpp
//  CS3377 Program
// Checks for the validity of a URL.
//
//  Created by Ishan Brar on 2/1/20.
//  Copyright © 2020 Ishan Brar. All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;
void displayVersion(std::string version)
{
    std::cout << "The current version is " << version << std::endl;
    
}
int main()
{
    //variables for length of the URL and location of first breakpoint
    int protocolnum;
    int length;
    std::string version = "1.2";
    displayVersion(version);
    
    //prompt URL from user
    cout<< "Enter a URL to check for validity: " << endl;
    std::string url;
    
    //Get URl from user
    getline(cin, url);
    length = url.length();
    
    // Breakpoints for each segment of the URl
    std::string delimiter1 = "://";
    std::string delimiter2 = ":";
    std::string delimiter3 = "/";
    std::string delimiter4 = "?";
    
    //Blank line for clarity
    cout<< " " << endl;
    
    //Segmentation of protocol
    std::string protocol = url.substr(0, url.find(delimiter1));
    protocolnum = url.find(delimiter1);
    
    // '3' is length of "://"
    std::string remainingurl = url.substr(protocolnum+3);
    //Print URL
    cout << url << endl;
    //Blank line for clarity
    cout<< " " << endl;
    
    //Segmentation of Domain
    std::string domain = remainingurl.substr(0, remainingurl.find(delimiter2));
    remainingurl = remainingurl.substr(remainingurl.find(delimiter2));
    
    //Segmentation of Port
    std::string port = remainingurl.substr(1, remainingurl.find(delimiter3) -1);
    remainingurl = remainingurl.substr(remainingurl.find(delimiter3));
    
    //Segmentation of Filepath
    std::string filepath = remainingurl.substr(0, remainingurl.find(delimiter4));
    remainingurl = remainingurl.substr(remainingurl.find(delimiter4));
    
    //Segmentation of Parameters
    std::string parameters = remainingurl.substr(1);

    //Check if protocol is valid
    bool goodprotocol = false;
    if(protocol == "http" || protocol == "https" || protocol == "ftp" || protocol == "ftps")
    {
        goodprotocol = true;
    }
    
    //Check if Domain is valid
    bool gooddomain = false;
    std::string enddomain = domain.substr(domain.length()-3);
    if(enddomain == "edu" || enddomain == "com" || enddomain == "net" || enddomain == "gov" || enddomain =="biz")
    {
        gooddomain = true;
    }
    
    //Check if Port is valid
    bool goodport = false;
    int x = std::stoi(port);
    if(x < 65536 && x > 0)
    {
        goodport = true;
    }
    
    //Check if Filepath is valid
    bool goodfilepath = false;
    std::string check = filepath.substr(filepath.length()-5);
    
    if(check.find("htm") != std::string::npos)
    {
        goodfilepath = true;
    }
    
    
    //Check if the entire URL is valid
    bool goodurl = false;
    if(goodfilepath && goodport && gooddomain && goodprotocol)
    {
        goodurl = true;
    }
    
    //If URL is valid, print each component
    if(goodurl == true)
    {
        cout<< "Protocol:   " << protocol<< endl;
        cout<< "Domain:     " << domain << endl;
        cout<< "Port:       " << port<< endl;
        cout<< "Filepath:   " << filepath <<endl;
        cout<< "Parameters: " << parameters <<endl;
    }
    
    //If URL is not valid, print error messages
    else{
        cout<< "Invalid URL with following erroneous components:" << endl;
        if(goodprotocol == false)
        {
            cout<< "Protocol:    " << protocol << " is not a valid protocol." <<endl;
        }
        if(gooddomain == false)
        {
            cout<< "Domain:    " << enddomain << " is an invalid domain name." <<endl;
        }
        if(goodport == false)
        {
            cout<< "Port:    " << "    port number must be between 1 and 65535." <<endl;
        }
        if(goodfilepath == false)
        {
            cout<< "Filepath:    " << filepath << " is an invalid filepath" <<endl;
        }
        
        
        
    }


}
