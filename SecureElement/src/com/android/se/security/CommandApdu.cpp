#include "CommandApdu.h"

void CommandApduValidator::execute(const std::vector<unsigned char>& apdu) {
    if (apdu.size() < CMD_APDU_LENGTH_CASE1) {
        throw std::invalid_argument("Invalid length for command (" + std::to_string(apdu.size()) + ").");
    }
    checkCla(apdu[OFFSET_CLA]);
    checkIns(apdu[OFFSET_INS]);

    if (apdu.size() == CMD_APDU_LENGTH_CASE1) {
        return; // Case 1
    }

    if (apdu.size() == CMD_APDU_LENGTH_CASE2) {
        checkLe(apdu[OFFSET_P3]);
        return; // Case 2S
    }

    if (apdu[OFFSET_P3] != static_cast<unsigned char>(0x00)) {
        int lc = apdu[OFFSET_P3];
        if (apdu.size() == CMD_APDU_LENGTH_CASE3_WITHOUT_DATA + lc) {
            return; // Case 3S
        }
        if (apdu.size() == CMD_APDU_LENGTH_CASE4_WITHOUT_DATA + lc) {
            checkLe(apdu[apdu.size() - 1]);
            return; // Case 4S
        }
        throw std::invalid_argument("Unexpected value of Lc (" + std::to_string(lc) + ")");
    }

    if (apdu.size() == CMD_APDU_LENGTH_CASE2_EXTENDED) {
        checkLe((apdu[OFFSET_DATA] << 8) + apdu[OFFSET_DATA + 1]);
        return; // Case 2E
    }

    if (apdu.size() <= OFFSET_DATA_EXTENDED) {
        throw std::invalid_argument("Unexpected value of Lc or Le" + std::to_string(apdu.size()));
    }

    int lc = (apdu[OFFSET_DATA] << 8) + apdu[OFFSET_DATA + 1];
    if (lc == 0) {
        throw std::invalid_argument("Lc can't be 0");
    }

    if (apdu.size() == CMD_APDU_LENGTH_CASE3_WITHOUT_DATA_EXTENDED + lc) {
        return; // Case 3E
    }

    if (apdu.size() == CMD_APDU_LENGTH_CASE4_WITHOUT_DATA_EXTENDED + lc) {
        checkLe((apdu[apdu.size() - 2] << 8) + apdu[apdu.size() - 1]);
        return; // Case 4E
    }
    throw std::invalid_argument("Unexpected value of Lc (" + std::to_string(lc) + ")");
}

void CommandApduValidator::checkCla(unsigned char cla) {
    if (cla == static_cast<unsigned char>(0xFF)) {
        throw std::invalid_argument("Invalid value of CLA (" + std::to_string(static_cast<int>(cla)) + ")");
    }
}

void CommandApduValidator::checkIns(unsigned char ins) {
    if ((ins & 0x0F0) == 0x60 || ((ins & 0x0F0) == 0x90)) {
        throw std::invalid_argument("Invalid value of INS (" + std::to_string(static_cast<int>(ins)) + "). "
                                    + "0x6X and 0x9X are not valid values");
    }
}

void CommandApduValidator::checkLe(int le) {
    if (le < 0 || le > MAX_EXPECTED_DATA_LENGTH) {
        throw std::invalid_argument("Invalid value for le parameter (" + std::to_string(le) + ").");
    }
}
