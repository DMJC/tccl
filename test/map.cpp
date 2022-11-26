#include <map>
#include <string>
#include <iostream>
#include "axis_box.h"
#include "../devices/warthog_stick.h"
//#include "../devices/warthog_throttle.h"
//#include "../devices/pendular_rudder.h"
//#include "cougar_stick.h"
//#include "../devices/tflight_rudder.h"
//#include "../devices/tflight_hotas.h"
//#include ""
//#include ""

using namespace std;
// Value-Defintions of the different String values
enum StringValue { evNotDefined,evWarthog_Stick,evWarthog_Throttle,evPendular_Rudder,evCougar_Stick,evCougarMFD1,evCougarMFD2,evStringValue7,evStringValue8,evStringValue9,evEnd };

// Map to associate the strings with the enum values
static std::map<std::string, StringValue> s_mapStringValues;

// User input
static char szInput[2048];

// Intialization
static void Initialize();

int main(int argc, char* argv[])
{


  // Init the string map
  Initialize();
  // Loop until the user stops the program
  while(1)
  {
    // Get the user's input
    cout << "Please enter a string (end to terminate): ";
    cout.flush();
    cin.getline(szInput, 2048);
    // Switch on the value
    switch(s_mapStringValues[szInput])
    {
      case evWarthog_Stick:{
        cout << "ThrustMaster HOTAS Warthog Stick." << endl;
	Axis_Box warthog_stick_ab = Axis_Box(warthog_stick_axes());
        break;}
      case evWarthog_Throttle:{
        cout << "ThrustMaster HOTAS Warthog Throttle." << endl;
        break;}
      case evPendular_Rudder:{
        cout << "ThrustMaster Pendular Rudder Pedals." << endl;
        break;}
      case evCougar_Stick:{
	cout << "ThrustMaster HOTAS Cougar." << endl;
        break;}
      case evCougarMFD1:{
        cout << "ThrustMaster Cougar MFD1" << endl;
        break;}
      case evCougarMFD2:{
        cout << "ThrustMaster Cougar MFD2" << endl;
        break;}
      case evStringValue7:{
        cout << "ThrustMaster" << endl;
        break;}
      case evStringValue8:{
        cout << "ThrustMaster" << endl;
        break;}
      case evStringValue9:{
        cout << "ThrustMaster" << endl;
        break;}
      case evEnd:
        cout << "Detected program end command. "
             << "Programm will be stopped." << endl;
        return(0);
      default:
        cout << "'" << szInput
  << "' is an invalid string. s_mapStringValues now contains "
             << s_mapStringValues.size()
             << " entries." << endl;
        break;
    }
  }

  return 0;
}

void Initialize()
{
  s_mapStringValues["4402"] = evWarthog_Stick;
  s_mapStringValues["4404"] = evWarthog_Throttle;
  s_mapStringValues["b68f"] = evPendular_Rudder;
  s_mapStringValues["0400"] = evCougar_Stick;
  s_mapStringValues["b351"] = evCougarMFD1;
  s_mapStringValues["b352"] = evCougarMFD2;
  s_mapStringValues["b10a"] = evStringValue7;
  s_mapStringValues["b678"] = evStringValue8;
  s_mapStringValues["b687"] = evStringValue9;
  s_mapStringValues[""] = evEnd;

  cout << "s_mapStringValues contains "
       << s_mapStringValues.size()
       << " entries." << endl;
}
