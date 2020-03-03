#ifndef EX3_DATASTREAM_H
#define EX3_DATASTREAM_H

#include <stdint.h>
#include <vector>
#include <string>
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
			uint32_t pos = 0;
			int bitPos = 0;
			int bitBuf = 0;
			int tempByte = 0;
		public:
			//DataStream();
			//DataStream(DataStream* ds);
			DataStream(vector<uint8_t> data);
			//DataStream(uint8_t* data, size_t dataLength);
			~DataStream();

			uint8_t readUInt8();
			uint16_t readUInt16();
			uint32_t readUInt32();
			uint64_t readUInt64();
			int8_t readInt8();
			int16_t readInt16();
			int32_t readInt32();
			int64_t readInt64();

			unsigned int readUBits(int nBits);
			int readBits(int nBits);
			void fillBitBuf();
			
			void skipHeader(); // TODO This is just for testing. Remove
			/*
			float readFloat();
			double readDouble();
			*/

			string readString();
			string readString(long length);
			
			float readFIXED();
			float readFIXED8();

			float readFLOAT16();
			/*
			float readFLOAT();
			double readDOUBLE();
			uint32_t readEncodedU32();
			
			string readString();
			string readString(long len);
			*/

			long available();
			vector<uint8_t> readBytes(long len);

			int64_t read();
			int readNoBitReset();

			void alignByte();
	};
};

#endif //EX3_DATASTREAM_H