#include "Compress.H"
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
				{'T',1}
			};
		}

		virtual void TearDown(){}

};

TEST_F(CompressTest,generateHistogramTest){
	std::map<char,int> histogram = std::map<char,int>();
	Compress::generateHistogram(expectedContent,histogram);


	EXPECT_EQ(histogram.size(),expectedHistogram.size()) << "Size Check";
	
	for(auto it = expectedHistogram.begin();it != expectedHistogram.end();it++){
		EXPECT_EQ(it->second,histogram[it->first]) << std::string(1,it->first) + " : (expected,output)";
	}
}

/*
TEST_F(CompressTest,generateHuffmanTreeTest){
	std::shared_ptr<Node> huffmanTree = Compress::generateHuffmanTree(expectedHistogram);
}
*/



