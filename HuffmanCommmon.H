#ifndef __HUFFMANCOMMON_H__
#define __HUFFMANCOMMON_H__

struct Node{
    int value;
    char letter;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(double _value, char _letter ) : value(_value), letter(_letter) {}

    bool isLeaf(){return (!left && !right);}
};

#endif
