  
#include <iostream>
#include "SwfParser.h"

using namespace std;

int main(int argc, char** argv)
{
    //cout << "Hello, world" << endl;

/**
    ifstream inputFile ("src/_test.swf", ios::binary);
    assert(inputFile);
    inputFile.unsetf(ios::skipws);

    istream_iterator<uint8_t> b(inputFile), e;
    const vector<uint8_t> data(b, e);

    //readFromRawData(data);

    EX3::DataStream *stream = new EX3::DataStream(data);
    uint8_t sig1 = stream->readUI8();
    uint8_t sig2 = stream->readUI8();

    cout << sig1 << endl;
    cout << sig2 << endl;
**/
    EX3::SwfParser p;
	p.readFromFile("src/_test.swf");

    return 0;
}