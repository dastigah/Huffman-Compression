#ifndef __HUFFMANCOMMON_H__
#define __HUFFMANCOMMON_H__

#include <memory>
#include <string>
#include <iostream>
#include <map>


struct Node{
    int value;
    char letter;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(double _value, char _letter ) : value(_value), letter(_letter) {}

    bool isLeaf(){return (!left && !right);}
};


void printHisto(const std::map<char,int> & histogram){
	for (auto it = histogram.begin();it != histogram.end();it++){
		std::cout << it->first << ":" << it->second << std::endl;
	}
}

#endif
