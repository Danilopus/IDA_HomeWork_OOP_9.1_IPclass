#pragma once
//#include "Struct_IP.h"
#include "IP_adress.h"
#include "Service functions.h"


class Net_mask
{
	Struct_IP _Struct_IP_net_mask;

public:
	Net_mask(Struct_IP Struct_IP_net_mask) : _Struct_IP_net_mask(Struct_IP_net_mask) {}
	Net_mask(char o4, char o3, char o2, char o1)
	{
		_Struct_IP_net_mask.octet_1 = o1;
		_Struct_IP_net_mask.octet_2 = o2;
		_Struct_IP_net_mask.octet_3 = o3;
		_Struct_IP_net_mask.octet_4 = o4;
	}

	
	// Show // Info --------------------------------------------------------
	void Show() { std::cout << *this; }
	//static std::string OpenInterface_Class_Info();
	//static std::vector<int>& OpenInterface_Operation_Info();

	//bool is_valid_net_mask(const IP_adress& IP_adress_obj) // Error(active)	E1086	the object has type qualifiers that are not compatible with the member function "IP_adress::Get_adress"
	//*
	bool is_valid_net_mask(IP_adress& IP_adress_obj_sample, IP_adress& IP_adress_obj_test)
	{
		Struct_IP adress_of_net_sample = *this & IP_adress_obj_sample;
		Struct_IP adress_of_net_test = *this & IP_adress_obj_test;

		if (adress_of_net_test == adress_of_net_sample) return true;
		return false;
	}//*/

	size_t Get_Nodes_Quantity()
	{
			Struct_IP inverted_Net_mask;
		inverted_Net_mask.octet_1 = ~_Struct_IP_net_mask.octet_1;
		inverted_Net_mask.octet_2 = ~_Struct_IP_net_mask.octet_2;
		inverted_Net_mask.octet_3 = ~_Struct_IP_net_mask.octet_3;
		inverted_Net_mask.octet_4 = ~_Struct_IP_net_mask.octet_4;

		size_t _NUMBER_OF_HOSTS_ = -2 + inverted_Net_mask.octet_1 + pow(2, 8) * inverted_Net_mask.octet_2 + pow(2, 16) * inverted_Net_mask.octet_3 + pow(2, 24) * inverted_Net_mask.octet_4;
		
		return _NUMBER_OF_HOSTS_;
	}

	// Setters // Getters --------------------------------------------------
	void Set_adress(Struct_IP Struct_IP_net_mask) { _Struct_IP_net_mask = Struct_IP_net_mask; }
	void Set_adress(char o4, char o3, char o2, char o1)	{
		_Struct_IP_net_mask.octet_1 = o1;
		_Struct_IP_net_mask.octet_2 = o2;
		_Struct_IP_net_mask.octet_3 = o3;
		_Struct_IP_net_mask.octet_4 = o4;
	}

	Struct_IP& Get_adress() { return _Struct_IP_net_mask; }

	//Overload operators ---------------------------------------------------
	//Struct_IP operator & (const IP_adress& IP_adress_obj) // Error(active)	E1086	the object has type qualifiers that are not compatible with the member function "IP_adress::Get_adress"
	Struct_IP operator & (IP_adress& IP_adress_obj)
	{
		Struct_IP tmp_obj;
		tmp_obj.octet_1 = _Struct_IP_net_mask.octet_1 & IP_adress_obj.Get_adress().octet_1;
		tmp_obj.octet_2 = _Struct_IP_net_mask.octet_2 & IP_adress_obj.Get_adress().octet_2;
		tmp_obj.octet_3 = _Struct_IP_net_mask.octet_3 & IP_adress_obj.Get_adress().octet_3;
		tmp_obj.octet_4 = _Struct_IP_net_mask.octet_4 & IP_adress_obj.Get_adress().octet_4;

		return tmp_obj;
	}
	friend std::istream& operator >> (std::istream& in, Net_mask& Net_mask_obj)
	{
		Struct_IP new_adress;

		// как вернуть консоль на предыдущую строку?
		std::cout << "\nEnter new Net mask: ( ";
		new_adress.octet_4 = Get_Int_Positive(0, 255, "range in [0..255] ");
		std::cout << ". ";
		new_adress.octet_3 = Get_Int_Positive(0, 255, "range in [0..255] ");
		std::cout << ". ";
		new_adress.octet_2 = Get_Int_Positive(0, 255, "range in [0..255] ");
		std::cout << ". ";
		new_adress.octet_1 = Get_Int_Positive(0, 255, "range in [0..255] ");
		std::cout << " )";

		Net_mask_obj.Set_adress(new_adress);
	}
	friend std::ostream& operator << (std::ostream& out, Net_mask& Net_mask_obj)
	{
		std::cout << "(" << Net_mask_obj._Struct_IP_net_mask.octet_1
			<< "." << Net_mask_obj._Struct_IP_net_mask.octet_2
			<< "." << Net_mask_obj._Struct_IP_net_mask.octet_3
			<< "." << Net_mask_obj._Struct_IP_net_mask.octet_4
			<< " )";

		return out;
	}

};
