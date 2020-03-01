  
#include <iostream>
#include "core/SwfParser.h"

using namespace std;

int main(int argc, char** argv)
{
    EX3::SwfParser p;
	p.readFromFile("./data/test.swf");

    return 0;
}