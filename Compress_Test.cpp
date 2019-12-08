#include "Compress.H"
#include "gtest/gtest.h"

class CompressTest : public ::testing::Test{
	protected:
		

		Compress(){}
		void Setup(){
			std::string content = "This is a test to see if huffman works";
			std::map<char,int> histogran = {
				{'T',1}
			};

		}
}



