#include <vector>
#include <stdexcept>

class CommandApduValidator {
private:
    static const int CMD_APDU_LENGTH_CASE1 = 4;
    static const int CMD_APDU_LENGTH_CASE2 = 5;
    static const int CMD_APDU_LENGTH_CASE2_EXTENDED = 7;
    static const int CMD_APDU_LENGTH_CASE3_WITHOUT_DATA = 5;
    static const int CMD_APDU_LENGTH_CASE3_WITHOUT_DATA_EXTENDED = 7;
    static const int CMD_APDU_LENGTH_CASE4_WITHOUT_DATA = 6;
    static const int CMD_APDU_LENGTH_CASE4_WITHOUT_DATA_EXTENDED = 9;

    static const int MAX_EXPECTED_DATA_LENGTH = 65536;

    static const int OFFSET_CLA = 0;
    static const int OFFSET_INS = 1;
    static const int OFFSET_P3 = 4;
    static const int OFFSET_DATA = 5;
    static const int OFFSET_DATA_EXTENDED = 7;

    CommandApduValidator() {}

public:
    static void execute(const std::vector<unsigned char>& apdu);

private:
    static void checkCla(unsigned char cla);
    static void checkIns(unsigned char ins);
    static void checkLe(int le);
};