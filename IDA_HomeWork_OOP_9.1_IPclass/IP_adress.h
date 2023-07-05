#pragma once
#include <vector>
#include <iostream>
#include "Struct_IP.h"
#include "Net_mask.h"
#include "Service functions.h"

class  IP_adress
	{		
	Struct_IP _Struct_IP_adress;
	public:
		//1 Constructors // Initialisation // Destructors // Memory Clean -------
		IP_adress(const Struct_IP& Struct_IP_adress): _Struct_IP_adress(Struct_IP_adress) { }
		IP_adress(Struct_IP& Struct_IP_adress) : _Struct_IP_adress(Struct_IP_adress) { }
		IP_adress(char o4, char o3, char o2, char o1)
		{
			_Struct_IP_adress.octet_1 = o1;
			_Struct_IP_adress.octet_2 = o2;
			_Struct_IP_adress.octet_3 = o3;
			_Struct_IP_adress.octet_4 = o4;		
		}
		IP_adress() {  };

		//2 Setters // Getters --------------------------------------------------
		void Set_adress(Struct_IP Struct_IP_adress) { _Struct_IP_adress = Struct_IP_adress; }
		void Set_adress(char o4, char o3, char o2, char o1) 	{
				_Struct_IP_adress.octet_1 = o1;
				_Struct_IP_adress.octet_2 = o2;
				_Struct_IP_adress.octet_3 = o3;
				_Struct_IP_adress.octet_4 = o4;
		}
		

		Struct_IP& Get_adress() { return _Struct_IP_adress; }
		//Struct_IP& Get_adress() const { return _Struct_IP_adress; } // Error(active)	E0433	qualifiers dropped in binding reference of type "Struct_IP &" to initializer of type "const Struct_IP"
		Struct_IP& Get_net_adress(Net_mask& Net_mask_obj)
		{
			Struct_IP adress_of_net;
			adress_of_net.octet_1 = _Struct_IP_adress.octet_1 & Net_mask_obj.Get_adress().octet_1;
			adress_of_net.octet_2 = _Struct_IP_adress.octet_2 & Net_mask_obj.Get_adress().octet_2;
			adress_of_net.octet_3 = _Struct_IP_adress.octet_3 & Net_mask_obj.Get_adress().octet_3;
			adress_of_net.octet_4 = _Struct_IP_adress.octet_4 & Net_mask_obj.Get_adress().octet_4;

			return adress_of_net;
		}
		
		//3 Show // Info --------------------------------------------------------
		void Show() { std::cout << *this; }
		static std::string OpenInterface_Class_Info();
		static std::vector<int>& OpenInterface_Operation_Info();

		//4 Inner logic ---------------------------------------------------------
		static bool is_IP_adress_valid(const IP_adress& IP_adress_obj)
		// применяемый тип данных unsigned char гарантирует соответствие значений. Вроде так...
		{
			//if (IP_adress_obj._Struct_IP_adress.octet_1 == NULL) return false;
			//if (!IP_adress_obj._Struct_IP_adress.octet_1 && IP_adress_obj._Struct_IP_adress.octet_1 <255) return false;		
			//if (!IP_adress_obj._Struct_IP_adress.octet_2 && IP_adress_obj._Struct_IP_adress.octet_2 < 255) return false;
			return true;
		}
		//IP_adress* _Struct_IP_adress(const IP_adress& IP_adress_obj, const Net_mask& Net_mask_obj);						

		//5 Overload operators ---------------------------------------------------
		bool operator == (const IP_adress& IP_adress_obj)
		{
			if (_Struct_IP_adress.octet_4 == IP_adress_obj._Struct_IP_adress.octet_4)
				if (_Struct_IP_adress.octet_3 == IP_adress_obj._Struct_IP_adress.octet_3)
					if (_Struct_IP_adress.octet_2 == IP_adress_obj._Struct_IP_adress.octet_2)
						if (_Struct_IP_adress.octet_1 == IP_adress_obj._Struct_IP_adress.octet_1)
							return true;
			return false;



		}
		bool operator > (const IP_adress& IP_adress_obj)
		{
			if (*this == IP_adress_obj) return false;

			if (_Struct_IP_adress.octet_4 > IP_adress_obj._Struct_IP_adress.octet_4) return true;
			else if (_Struct_IP_adress.octet_4 < IP_adress_obj._Struct_IP_adress.octet_4) return false;

			if (_Struct_IP_adress.octet_3 > IP_adress_obj._Struct_IP_adress.octet_3) return true;
			else if (_Struct_IP_adress.octet_3 < IP_adress_obj._Struct_IP_adress.octet_3) return false;

			if (_Struct_IP_adress.octet_2 > IP_adress_obj._Struct_IP_adress.octet_2) return true;
			else if (_Struct_IP_adress.octet_2 < IP_adress_obj._Struct_IP_adress.octet_2) return false;

			if (_Struct_IP_adress.octet_1 > IP_adress_obj._Struct_IP_adress.octet_1) return true;
			else if (_Struct_IP_adress.octet_1 < IP_adress_obj._Struct_IP_adress.octet_1) return false;

			return false;
		}
		bool operator < (const IP_adress& IP_adress_obj)
		{
			return !(*this > IP_adress_obj);
		}

		friend std::istream& operator >> (std::istream& in, IP_adress& IP_adress_obj)
		{
			//Struct_IP new_adress(Get_Int_SA(), Get_Int_SA(), Get_Int_SA(), Get_Int_SA());
			Struct_IP new_adress;

			// как вернуть консоль на предыдущую строку?
			std::cout << "\Enter new IP adress: ( ";
			new_adress.octet_4 = Get_Int_Positive(0, 255, "range in [0..255] ");
			std::cout << ". ";
			new_adress.octet_3 = Get_Int_Positive(0, 255, "range in [0..255] ");
			std::cout << ". ";
			new_adress.octet_2 = Get_Int_Positive(0, 255, "range in [0..255] ");
			std::cout << ". ";
			new_adress.octet_1 = Get_Int_Positive(0, 255, "range in [0..255] ");
			std::cout << " )";


			IP_adress_obj.Set_adress(new_adress);

			return in;
		}
		friend std::ostream& operator << (std::ostream& out, IP_adress& IP_adress_obj)
		{			
			std::cout << "(" << IP_adress_obj._Struct_IP_adress.octet_1
				<< "." <<		IP_adress_obj._Struct_IP_adress.octet_2
				<< "." <<		IP_adress_obj._Struct_IP_adress.octet_3
				<< "." <<		IP_adress_obj._Struct_IP_adress.octet_4		
				<< " )";

			return out;
		}
};
