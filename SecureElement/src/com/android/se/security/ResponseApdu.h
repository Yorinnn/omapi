#include <vector>

class ResponseApdu {
private:
    int mSw1;
    int mSw2;
    std::vector<unsigned char> mData;

public:
    ResponseApdu(const std::vector<unsigned char>& respApdu);

    int getSW1() const;
    int getSW2() const;
    int getSW1SW2() const;
    const std::vector<unsigned char>& getData() const;
    bool isStatus(int sw1sw2) const;
};