#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace se {
namespace omapi {
class ISecureElementChannel : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SecureElementChannel)
  virtual ::android::binder::Status close() = 0;
  virtual ::android::binder::Status isClosed(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isBasicChannel(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getSelectResponse(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status transmit(const ::std::vector<uint8_t>& command, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status selectNext(bool* _aidl_return) = 0;
};  // class ISecureElementChannel

class ISecureElementChannelDefault : public ISecureElementChannel {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status close() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isClosed(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isBasicChannel(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSelectResponse(::std::vector<uint8_t>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status transmit(const ::std::vector<uint8_t>& /*command*/, ::std::vector<uint8_t>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status selectNext(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISecureElementChannelDefault
}  // namespace omapi
}  // namespace se
}  // namespace android
