#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <map>

using namespace std;
// This data structure should be a record in a input file
// For this example use airship.dat
struct AirShipFile {
	int Type;  // Airplane or Balloon
	string name;		// Name of the airship
	int passCount;		// passenger count
	int weightCargo;     // cargo weight
	int EngOrGas;		// engine or gas type
	int distance;		// range or altitude
};
enum EngineType { Jet, Propeller }; // for airplanes only
std::ostream& operator<<(std::ostream& out, const EngineType value) {
	static std::map<EngineType, std::string> strings;
	if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(Jet);
		INSERT_ELEMENT(Propeller);
#undef INSERT_ELEMENT
	}

	return out << strings[value];
}
enum GasType {Helium, Hydrogen };  // for proprellers only
std::ostream& operator<<(std::ostream& out, const GasType value) {
	static std::map<GasType, std::string> strings;
	if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(Helium);
		INSERT_ELEMENT(Hydrogen);
#undef INSERT_ELEMENT
	}

	return out << strings[value];
}
enum AirShipType { AIRPLANE, BALLOON };
class CAirship {
public:
	CAirship() { }
	virtual ~CAirship() {}
	
	virtual void SetData(AirShipFile &data) = 0;
	virtual void GetData() = 0;
	AirShipType GetAirShipType() { return m_AirShipType; }

protected:
	AirShipType m_AirShipType;

};

class CAIRPLANE : public virtual CAirship {
public:
	CAIRPLANE() : CAirship() {}
	void SetData(AirShipFile &data);
	void GetData();
	
private:
	EngineType m_EngineType;
	int m_MaxPassengerCount;
	string m_Name;
	int m_MaxCargoWeight;
	int m_MaxAltitude;
};
// Function: SetData
void CAIRPLANE::SetData(AirShipFile &data)
{
	// cast integer to enum
	m_EngineType = EngineType(data.EngOrGas);
	// airplane name
	m_Name = data.name;
	// passenger count
	m_MaxPassengerCount = data.passCount;
	//max cargo weight
	m_MaxCargoWeight = data.weightCargo;
	// cast integer to enum
	m_AirShipType = AirShipType(data.Type);
	// maximum altitude
	m_MaxAltitude = data.distance;

}
void CAIRPLANE::GetData()
{
	cout << setw(20) << m_Name << "\t" << setw(20) << m_EngineType << setw(20);
	cout << left << setw(20) << m_MaxAltitude << "\n";
}
class CBALLOON : public virtual CAirship {
public:
	CBALLOON() : CAirship() {}
	void SetData(AirShipFile &data);
	void GetData();
	
private:
	GasType m_GasType;
	EngineType m_EngineType;
	int m_MaxPassengerCount;
	string m_Name ;
	int m_MaxCargoWeight;
	int m_MaxAltitude;
};
void CBALLOON::SetData(AirShipFile &data)
{
	// cast integer to enum
	m_GasType = GasType(data.EngOrGas);
	// airplane name
	m_Name  = data.name;
	// passenger count
	m_MaxPassengerCount = data.passCount;
	//max cargo weight
	m_MaxCargoWeight = data.weightCargo;
	// cast integer to enum
	m_AirShipType = AirShipType(data.Type);
	// maximum altitude
	m_MaxAltitude = data.distance;
}
void CBALLOON::GetData()
{
	cout << setw(20) << m_Name << "\t" << setw(20)<< m_GasType << setw(20);
	cout << left << setw(20) << m_MaxAltitude << "\n";
}
// AIRPLANE = 0
// BALLOON = 1
int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << "Usage: PR <filename>\n";
		return 1;
	}
	ifstream Infile(argv[1]);
	if (!Infile) {
		cout << "Cannot open file\n";
		return 1;
	}
	char LineBuf[100];
	char d[] = ",";
	char* context = nullptr;
	CAirship * pAirShip[10];
	int i = 0;
	while (Infile.getline(LineBuf, 100)) {
		struct AirShipFile data;
		// read the first field Airship type
		// airplane or balloon
		data.Type = atoi(strtok_s(LineBuf, d, &context));

		switch (data.Type) {
		case AIRPLANE:
			// Create AIRPLANE Object
			pAirShip[i] = new CAIRPLANE();
			data.name = strtok_s(nullptr, d, &context);
			data.passCount = atoi(strtok_s(nullptr, d, &context));
			data.weightCargo = atoi(strtok_s(nullptr, d, &context));
			data.EngOrGas = atoi(strtok_s(nullptr, d, &context));
			data.distance = atoi(strtok_s(nullptr, d, &context));
			break;
		case BALLOON:
			// Create BALLOON Object
			pAirShip[i] = new CBALLOON();
			data.name = strtok_s(nullptr, d, &context);
			data.passCount = atoi(strtok_s(nullptr, d, &context));
			data.weightCargo = atoi(strtok_s(nullptr, d, &context));
			data.EngOrGas = atoi(strtok_s(nullptr, d, &context));
			data.distance = atoi(strtok_s(nullptr, d, &context));
			break;
		default:
			break;
		} // end switch
		  // call appropriate function
		pAirShip[i++]->SetData(data);
		memset(LineBuf, '\0', 100);
	}
	Infile.close();
	cout << "Listing of all Airplanes \n";
	cout << left << setw(20) << "\nName" << left<< setw(20)<<"\tEngine Type";
	cout << left<<setw(20)<<"\Maximum Range" << "\n\n";
	for (int i = 0; i < 10; i++) {
		if (pAirShip[i]->GetAirShipType() == AIRPLANE)
			
			pAirShip[i]->GetData();
	}
	cout << "\n\nListing of all Balloons \n";
	cout <<left << setw(20) << "\nName" << left << setw(20) << "\tGas Type" ;
	cout << left << setw(20) << "\Maximum Altitude" << "\n\n";
	for (int i = 0; i < 10; i++) {
		if (pAirShip[i]->GetAirShipType() == BALLOON)
			pAirShip[i]->GetData();
	}

for (int i = 0; i < 10; i++) {
		if (pAirShip[i]) {
			delete pAirShip[i];// Delete appropriate object
			}
	} // end for loop

	return 0;
}