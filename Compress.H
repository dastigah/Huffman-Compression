#ifndef __COMPRESS_H__
#define __COMPRESS_H__

#include "HuffmanCommon.H"

#include <map>
#include <memory>
#include <string>


namespace Compress{ 

	int generateHistogram(const std::string &, std::map<char,int> &);

	std::shared_ptr<Node> generateHuffmanTree(const std::map<char,int> &);
	
	void generateBitMap(const std::shared_ptr<Node> &, std::map<char,std::string> &);

	std::string serializeTree(const std::shared_ptr<Node> &);

}


#endif

