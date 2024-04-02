#include "Util.h"
static std::vector<unsigned char> mergeBytes(const std::vector<unsigned char>& array1, const std::vector<unsigned char>& array2) {
    std::vector<unsigned char> data(array1.size() + array2.size());
    std::copy(array1.begin(), array1.end(), data.begin());
    std::copy(array2.begin(), array2.end(), data.begin() + array1.size());
    return data;
}
static std::vector<unsigned char> getMid(const std::vector<unsigned char>& array, int start, int length) {
    if (start < 0 || start + length > static_cast<int>(array.size())) {
        throw std::out_of_range("Index out of range");
    }
    std::vector<unsigned char> data(length);
    std::copy(array.begin() + start, array.begin() + start + length, data.begin());
    return data;
}
static std::vector<unsigned char> appendResponse(const std::vector<unsigned char>& r1, const std::vector<unsigned char>& r2, int length) {
    std::vector<unsigned char> rsp(r1.size() + length);
    std::copy(r1.begin(), r1.end(), rsp.begin());
    std::copy(r2.begin(), r2.begin() + length, rsp.begin() + r1.size());
    return rsp;
}
static std::string createMessage(const std::string& commandName, int sw) {
    std::stringstream message;
    if (!commandName.empty()) {
        message << commandName << " ";
    }
    message << "SW1/2 error: " << std::hex << std::setw(2) << std::setfill('0') << (sw | 0x10000);
    return message.str().substr(1);
}
static std::string createMessage(const std::string& commandName, const std::string& message) {
    if (commandName.empty()) {
        return message;
    }
    return commandName + " " + message;
}
static std::string getPackageNameFromCallingUid(Context& context, int uid) {
    PackageManager packageManager = context.getPackageManager();
    if (packageManager != nullptr) {
        std::vector<std::string> packageName = packageManager.getPackagesForUid(uid);
        if (!packageName.empty()) {
            return packageName[0];
        }
    }
    throw std::runtime_error("Caller PackageName can not be determined");
}
static unsigned char setChannelToClassByte(unsigned char cla, int channelNumber) {
    if (channelNumber < 4) {
        cla = (cla & 0xBC) | static_cast<unsigned char>(channelNumber);
    } else if (channelNumber < 20) {
        bool isSM = ((cla & 0x40) == 0x00) && ((cla & 0x0C) != 0);
        cla = (cla & 0xB0) | 0x40 | static_cast<unsigned char>(channelNumber - 4);
        if (isSM) {
            cla |= 0x20;
        }
    } else {
        throw std::invalid_argument("Channel number must be within [0..19]");
    }
    return cla;
}
static unsigned char clearChannelNumber(unsigned char cla) {
    bool isFirstInterindustryClassByteCoding = (cla & 0x40) == 0x00;
    if (isFirstInterindustryClassByteCoding) {
        return cla & 0xFC;
    } else {
        return cla & 0xF0;
    }
}
static int parseChannelNumber(unsigned char cla) {
    bool isFirstInterindustryClassByteCoding = (cla & 0x40) == 0x00;
    if (isFirstInterindustryClassByteCoding) {
        return cla & 0x03;
    } else {
        return (cla & 0x0F) + 4;
    }
}
