#include <iostream>
#include "ConfigCreator.h"

int main(int argc, char** argv) {

	vidzhet::ConfigCreator file("config", Write);

	file.additem("item1", 19.35);
	file.additem("item str", "some str");

	auto header = file.addheader<std::string>("list");
	header.write("str1");
	header.write("str2");
	header.write("something");
	header.finalize();

	file.close();

	vidzhet::ConfigCreator outfile("config", Read);
	std::cout << outfile.read_static<double>("item1") << std::endl << outfile.read_string("item str") << std::endl;


	auto outheader = outfile.header<std::string>("list");
	std::cout << outheader.read() << std::endl << outheader.read() << std::endl;

	auto header2 = outfile.header<std::string>("list");
	while (header2.next()) {
		std::cout<< header2.read() << std::endl;
	}

	outfile.close();
	

	system("pause");
	return 0;
}