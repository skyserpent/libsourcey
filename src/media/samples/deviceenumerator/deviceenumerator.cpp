#include "scy/media/devicemanager.h"
#include "scy/media/mediafactory.h"
#include "scy/util.h"

#include <string>
#include <vector>
#include <assert.h>
#include <conio.h>


using namespace std;
//using namespace Poco;
using namespace scy;
using namespace scy::av;


IDeviceManager* devices;


// Detect Memory Leaks
/*
#ifdef _DEBUG
#include "MemLeakDetect/MemLeakDetect.h"
CMemLeakDetect memLeakDetect;
#endif<RawPacket>
*/


int main(int argc, char** argv)
{
	scy::Logger::instance().add(new ConsoleChannel("debug", LTrace));

	devices = DeviceManagerFactory::create();
	devices->initialize();
	
	char o = 0;
	while (o != 'Q') 
	{	
		cout << 
			"COMMANDS:\n\n"
			"  P	Print Devices.\n"
			"  Q	Quit.\n\n";
		
		o = toupper(getch());
		
		// Print Devices
		if (o == 'P') {	
			reinterpret_cast<DeviceManager*>(devices)->print(cout);
		}
	}
	
	scy::Logger::destroy();
	return 0;
}