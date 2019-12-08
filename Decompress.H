#ifndef __DECOMPRESS_H__
#define __DECOMPRESS_H__

#include <string>


namespace Decompress{
	std::shared_ptr<Node> deserializeTree(const std::string &);

}

#endif
