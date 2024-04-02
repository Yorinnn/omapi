#include <iostream>
#include <vector>

class ByteArrayConverter {
    private:
        ByteArrayConverter();
    public:
        static std::string byteArrayToPathString(const std::vector<unsigned char>& rawPath);
        static std::string byteArrayToHexString(const std::vector<unsigned char>& byteArray);
        static std::vector<unsigned char> hexStringToByteArray(const std::string& str);
        static std::vector<unsigned char> intToByteArray(int value);
        static int byteArrayToInt(const std::vector<unsigned char>& byteArray);
        static bool isHexChar(char c);
}