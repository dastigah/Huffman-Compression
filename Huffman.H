#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <string>

namespace Huffman{

	std::string encode(std::file Name);
	std::string encode(std::string data);

	std::string decode(std::string fileName);
	std::string decode(std::string data);
}
#endif
