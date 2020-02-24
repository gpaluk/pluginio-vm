#ifndef EX3_DATASTREAM_H
#define EX3_DATASTREAM_H

#include <stdint.h>
#include <vector>
//#include <string>
/*
#include <glob.h>
*/

using namespace std;

namespace EX3
{
	class DataStream
	{
		private:
			vector<uint8_t> data;
			long index = 0;
			int bitIndex = 0;
			int tempByte = 0;
		public:
			//DataStream();
			//DataStream(DataStream* ds);
			DataStream(vector<uint8_t> data);
			//DataStream(uint8_t* data, size_t dataLength);
			~DataStream();


			uint8_t readUI8();
			uint16_t readUI16();

			uint64_t readUB(unsigned nBits);
			int64_t readSB(unsigned nBits);
			

			/*
			uint32_t readUI32();
			uint64_t readUI64();
			int8_t readSI8();
			int16_t readSI16();
			int32_t readSI32();
			float readFIXED();
			float readFIXED8();
			float readFLOAT16();
			float readFLOAT();
			double readDOUBLE();
			uint32_t readEncodedU32();
			
			string readString();
			string readString(long len);
			*/


			uint8_t read();
			int readNoBitReset();

			void alignByte();
	};
};

#endif //EX3_DATASTREAM_H