#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>

class ApduFilter {
private:
    std::vector<unsigned char> mApdu;
    std::vector<unsigned char> mMask;

public:
    static const int LENGTH = 8;

    ApduFilter() {}

    ApduFilter(const std::vector<unsigned char>& apdu, const std::vector<unsigned char>& mask) {
        if (apdu.size() != 4) {
            throw std::invalid_argument("apdu length must be 4 bytes");
        }
        if (mask.size() != 4) {
            throw std::invalid_argument("mask length must be 4 bytes");
        }
        mApdu = apdu;
        mMask = mask;
    }

    ApduFilter(const std::vector<unsigned char>& apduAndMask) {
        if (apduAndMask.size() != 8) {
            throw std::invalid_argument("filter length must be 8 bytes");
        }
        mApdu = std::vector<unsigned char>(apduAndMask.begin(), apduAndMask.begin() + 4);
        mMask = std::vector<unsigned char>(apduAndMask.begin() + 4, apduAndMask.end());
    }

    ApduFilter clone() const {
        ApduFilter apduFilter;
        apduFilter.setApdu(mApdu);
        apduFilter.setMask(mMask);
        return apduFilter;
    }

    const std::vector<unsigned char>& getApdu() const {
        return mApdu;
    }

    void setApdu(const std::vector<unsigned char>& apdu) {
        if (apdu.size() != 4) {
            throw std::invalid_argument("apdu length must be 4 bytes");
        }
        mApdu = apdu;
    }

    const std::vector<unsigned char>& getMask() const {
        return mMask;
    }

    void setMask(const std::vector<unsigned char>& mask) {
        if (mask.size() != 4) {
            throw std::invalid_argument("mask length must be 4 bytes");
        }
        mMask = mask;
    }

    std::vector<unsigned char> toBytes() const {
        std::vector<unsigned char> bytes;
        bytes.reserve(8);
        bytes.insert(bytes.end(), mApdu.begin(), mApdu.end());
        bytes.insert(bytes.end(), mMask.begin(), mMask.end());
        return bytes;
    }

    int getLength() const {
        return LENGTH;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "APDU Filter [apdu=";
        for (unsigned char byte : mApdu) {
            ss << std::hex << static_cast<int>(byte);
        }
        ss << ", mask=";
        for (unsigned char byte : mMask) {
            ss << std::hex << static_cast<int>(byte);
        }
        ss << "]";
        return ss.str();
    }
};