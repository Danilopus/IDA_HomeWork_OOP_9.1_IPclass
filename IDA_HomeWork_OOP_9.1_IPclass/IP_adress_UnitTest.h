#pragma once
#include <string>
#include "IP_adress.h"
#include "Net_mask.h"

//class Net_mask;
//class IP_adress;



class IP_adress_UnitTest
{
	static std::vector<std::string> test_names;
public:

	static std::string main_test()
	{
		std::cout << "\n\n*\n**\n*** SELF Tests module\n";
		std::string test_report = "\n\n*** Tests status. ";
		test_names.push_back(test_report);				
		
		IP_adress IP_example(192, 168, 100, 100);
		Net_mask Net_mask_example(255, 255, 255, 0);

		// Methods test list --------------------------------------------------------*/

		//1
		test_names.push_back("Object constructor test:\n");
		test_report += test_names[1];
		test_report += Collection_test_methods_1(IP_example, Net_mask_example) ? "Ok" : "failed";

		//2	
		test_names.push_back("Set_adress() test:\n");
		test_report += test_names[2];
		test_report += Collection_test_methods_2(IP_example, Net_mask_example) ? "Ok" : "failed";

		//3
		test_names.push_back("Get_adress() test:\n");
		test_report += test_names[3];
		test_report += Collection_test_methods_3(IP_example, Net_mask_example) ? "Ok" : "failed";

		//4
		test_names.push_back("Get_net_adress() test:\n");
		test_report += test_names[4];
		test_report += Collection_test_methods_4(IP_example, Net_mask_example) ? "Ok" : "failed";

		//5
		test_names.push_back("is_IP_adress_valid () test:\n");
		test_report += test_names[5];
		test_report += Collection_test_methods_5(IP_example, Net_mask_example) ? "Ok" : "failed";
		
		//6 					
		test_names.push_back("is_valid_net_mask() test:\n");
		test_report += test_names[6];
		test_report += Collection_test_methods_6(IP_example, Net_mask_example) ? "Ok" : "failed";

		//7					
		test_names.push_back("Get_Nodes_Quantity() test:\n");
		test_report += test_names[7];
		test_report += Collection_test_methods_7(IP_example, Net_mask_example) ? "Ok" : "failed";

		
		// Operators test list --------------------------------------------------------*/
		
		//8
		test_names.push_back("operator == test:\n");
		test_report += test_names[8];
		test_report += Collection_test_methods_8(IP_example, Net_mask_example) ? "Ok" : "failed";

		return test_report;
	}

	static bool Collection_test_methods_1(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[1] << "\n"
			<< "IP_adress IP_example(192, 168, 100, 100);\nIP_example.Show();\nNet_mask Net_mask_example(255, 255, 255, 0);\nNet_mask_example.Show();";

		IP_example.Show();
		Net_mask_example.Show();		
		
		//заготовка под условия, пока простой вариант
		{ return true; }
		return false;
	}
	static bool Collection_test_methods_2(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[1] << "\n"
			<< "IP_example.Set_adress(192, 168, 100, 100);\nIP_example.Show();\nNet_mask_example.Set_adress(255, 255, 225, 0);\nNet_mask_example.Show();";
		
		 IP_example.Set_adress(192, 168, 100, 100);
		 IP_example.Show();
		 Net_mask_example.Set_adress(255, 255, 225, 0);
		 Net_mask_example.Show();

		{ return true; }
		return false;
	}
	static bool Collection_test_methods_3(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[3] << "\n"
			<< "std::cout << IP_example.Get_adress();\nstd::cout << Net_mask_example.Get_adress();";

		std::cout << IP_example.Get_adress();
		std::cout << Net_mask_example.Get_adress();

		{ return true; }
		return false;
	}
	static bool Collection_test_methods_4(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[4] << "\n"
			<< "std::cout << IP_example.Get_adress();\nstd::cout << Net_mask_example.Get_adress();";

		std::cout << IP_example.Get_net_adress(Net_mask_example);

		{ return true; }
		return false;
	}		
	static bool Collection_test_methods_5(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[5] << "\n"
			<< "std::cout << IP_adress::is_IP_adress_valid(IP_example);";

		std::cout << IP_adress::is_IP_adress_valid(IP_example);

		{ return true; }
		return false;
	}
	static bool Collection_test_methods_6(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[6] << "\n"
			<< "IP_adress IP_example_2(192, 118, 11, 12);\nstd::cout << Net_mask_example.is_valid_net_mask(IP_example, IP_example_2);";
		IP_adress IP_example_2(192, 118, 11, 12);
		std::cout << Net_mask_example.is_valid_net_mask(IP_example, IP_example_2);

		if (Net_mask_example.is_valid_net_mask(IP_example, IP_example_2)) { return true; }
		return false;
	}
	static bool Collection_test_methods_7(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[6] << "\n"
			<< "std::cout << Net_mask_example.Get_Nodes_Quantity();\n";

		std::cout << Net_mask_example.Get_Nodes_Quantity();

		if (std::cout << Net_mask_example.Get_Nodes_Quantity()) { return true; }
		return false;
	}
	static bool Collection_test_methods_8(IP_adress& IP_example, Net_mask& Net_mask_example)
	{
		std::cout << "\n\n" << test_names[8] << "\n"
			<< "std::cout << (IP_example == IP_example);";

		std::cout << (IP_example == IP_example);


		if (IP_example == IP_example) { return true; }
		return false;
	}







	/*
		template <typename any>
		static any Summ(Collection<any> Collection_obj)
		{
			any Summ{};
			for (size_t i = 0; i < Collection_obj.size(); i++)
				Summ += Collection_obj[i];
			return Summ;
		}
	*/

};
