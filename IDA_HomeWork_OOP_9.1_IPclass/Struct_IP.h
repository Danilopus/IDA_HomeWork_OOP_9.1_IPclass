#pragma once
#include <iostream>

class Struct_IP
{
public:
	unsigned char octet_4;
	unsigned char octet_3;
	unsigned char octet_2;
	unsigned char octet_1;

	bool operator == (const Struct_IP& Struct_IP_obj) const
	{
		if (octet_4 == Struct_IP_obj.octet_4)
			if (octet_3 == Struct_IP_obj.octet_3)
				if (octet_2 == Struct_IP_obj.octet_2)
					if (octet_1 == Struct_IP_obj.octet_1)
						return true;
		return false;
	}

	friend std::ostream& operator << (std::ostream& out, Struct_IP& Struct_IP_obj)
	{
		std::cout << "(" << Struct_IP_obj.octet_1
			<< "." <<		Struct_IP_obj.octet_2
			<< "." <<		Struct_IP_obj.octet_3
			<< "." <<		Struct_IP_obj.octet_4
			<< " )";

		return out;
	}

};