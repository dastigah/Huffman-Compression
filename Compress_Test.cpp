#include "Compress.H"
#include "HuffmanCommon.H"
#include "gtest/gtest.h"
#include <string>

class CompressTest : public ::testing::Test{
	protected:	
		std::string expectedContent;
		std::map<char,int> expectedHistogram;
		std::shared_ptr<Node> expectedHuffmanTree;

		CompressTest(){}

		virtual void SetUp(){
			expectedContent = "This is a test to see if huffman works";
			expectedHistogram = {
				{'T',1},
				{'h',2},
				{'i',3},
				{'s',5},
				{' ',8},
				{'a',2},
				{'t',3},
				{'e',3},
				{'o',2},
				{'f',3},
				{'u',1},
				{'m',1},
				{'n',1},
				{'w',1},
				{'r',1},
				{'k',1}
			};
			

		}

		virtual void TearDown(){}

};

TEST_F(CompressTest,generateHistogramTest){
	std::map<char,int> histogram = std::map<char,int>();
	int histogramSize = Compress::generateHistogram(expectedContent,histogram);


	EXPECT_EQ(histogramSize,expectedHistogram.size()) << "Size Check";
	
	for(auto it = expectedHistogram.begin();it != expectedHistogram.end();it++){
		EXPECT_EQ(it->second,histogram[it->first]) << std::string(1,it->first) + " : (expected,output)";
	}

	printHisto(histogram);
}

/*
TEST_F(CompressTest,generateHuffmanTreeTest){
	std::shared_ptr<Node> huffmanTree = Compress::generateHuffmanTree(expectedHistogram);
}
*/



