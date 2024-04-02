#include "ResponseApdu.h"

ResponseApdu(const std::vector<unsigned char>& respApdu) {
    if (respApdu.size() < 2) {
        return;
    }
    if (respApdu.size() > 2) {
        mData.resize(respApdu.size() - 2);
        std::copy(respApdu.begin(), respApdu.end() - 2, mData.begin());
    }
    mSw1 = 0x00FF & respApdu[respApdu.size() - 2];
    mSw2 = 0x00FF & respApdu[respApdu.size() - 1];
}
int getSW1() const {
    return mSw1;
}
int getSW2() const {
    return mSw2;
}
int getSW1SW2() const {
    return (mSw1 << 8) | mSw2;
}
const std::vector<unsigned char>& getData() const {
    return mData;
}
bool isStatus(int sw1sw2) const {
    return (getSW1SW2() == sw1sw2);
}