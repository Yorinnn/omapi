#include "ByteArrayConverter.h"
static std::string byteArrayToPathString(const std::vector<unsigned char>& rawPath) {
    if (rawPath.size() % 2 != 0) {
        throw std::invalid_argument("Invalid path");
    }
    std::ostringstream pathStream;
    for (size_t i = 0; i < rawPath.size(); i += 2) {
        if (rawPath[i] == 0x3F && rawPath[i + 1] == 0x00) {
            // MF should not be included in path
            continue;
        }
        pathStream << std::setw(2) << std::setfill('0') << std::hex
                   << static_cast<int>(rawPath[i]) << static_cast<int>(rawPath[i + 1]);
        if (i != rawPath.size() - 2) {
            pathStream << ":";
        }
    }
    return pathStream.str();
}
static std::string byteArrayToHexString(const std::vector<unsigned char>& byteArray) {
    std::ostringstream hexStream;
    for (const auto& byte : byteArray) {
        hexStream << std::setw(2) << std::setfill('0') << std::hex
                  << static_cast<int>(byte);
    }
    return hexStream.str();
}
static std::vector<unsigned char> hexStringToByteArray(const std::string& str) {
    if (str.length() % 2 != 0) {
        throw std::invalid_argument("Length must be multiple of 2");
    }
    std::vector<unsigned char> outputBytes;
    for (size_t i = 0; i < str.length(); i += 2) {
        int byte;
        std::istringstream(str.substr(i, 2)) >> std::hex >> byte;
        outputBytes.push_back(static_cast<unsigned char>(byte));
    }
    return outputBytes;
}
static std::vector<unsigned char> intToByteArray(int value) {
    std::vector<unsigned char> byteArray(4);
    byteArray[0] = static_cast<unsigned char>((value >> 24) & 0xFF);
    byteArray[1] = static_cast<unsigned char>((value >> 16) & 0xFF);
    byteArray[2] = static_cast<unsigned char>((value >> 8) & 0xFF);
    byteArray[3] = static_cast<unsigned char>(value & 0xFF);
    return byteArray;
}
static int byteArrayToInt(const std::vector<unsigned char>& byteArray) {
    if (byteArray.empty()) {
        return 0;
    }
    int value = 0;
    for (size_t i = 0; i < byteArray.size() && i < 4; ++i) {
        value |= static_cast<int>(byteArray[i]) << ((3 - i) * 8);
    }
    return value;
}
static bool isHexChar(char c) {
    c = std::toupper(static_cast<unsigned char>(c));
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
}