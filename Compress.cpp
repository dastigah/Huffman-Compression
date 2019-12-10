
#include "Compress.H"


int Compress::generateHistogram(const std::string & content,std::map<char,int> & histogram){
	for (auto letter : content){
		histogram[letter]++;
	}
	return histogram.size();
}

std::shared_ptr<Node> Compress::generateHuffmanTree(const std::map<char,int> & histogram){
	//TODO
	return nullptr;
}


void Compress::generateBitMap(const std::shared_ptr<Node> & huffmanTree, std::map<char,std::string> & bitMap){
	//TODO
}

std::string Compress::serializeTree(const std::shared_ptr<Node> & huffmanTree){
	//TODO
	return "";
}
