#include <iostream>
#include <string>
#include <vector>

class Util {
    public:
        static const int END = -1;
        static std::vector<unsigned char> mergeBytes(const std::vector<unsigned char>& array1, const std::vector<unsigned char>& array2);
        static std::vector<unsigned char> getMid(const std::vector<unsigned char>& array, int start, int length);
        static std::vector<unsigned char> appendResponse(const std::vector<unsigned char>& r1, const std::vector<unsigned char>& r2, int length);
        static std::string createMessage(const std::string& commandName, int sw);
        static std::string createMessage(const std::string& commandName, const std::string& message);
        static std::string getPackageNameFromCallingUid(Context& context, int uid);
        static unsigned char setChannelToClassByte(unsigned char cla, int channelNumber);
        static unsigned char clearChannelNumber(unsigned char cla);
        static int parseChannelNumber(unsigned char cla);
}