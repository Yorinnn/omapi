#pragma once

#include <android/se/omapi/ISecureElementChannel.h>
#include <android/se/omapi/ISecureElementListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace se {
namespace omapi {
class ISecureElementSession : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SecureElementSession)
  virtual ::android::binder::Status getAtr(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status close() = 0;
  virtual ::android::binder::Status closeChannels() = 0;
  virtual ::android::binder::Status isClosed(bool* _aidl_return) = 0;
  virtual ::android::binder::Status openBasicChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) = 0;
  virtual ::android::binder::Status openLogicalChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) = 0;
};  // class ISecureElementSession

class ISecureElementSessionDefault : public ISecureElementSession {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getAtr(::std::vector<uint8_t>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status close() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeChannels() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isClosed(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openBasicChannel(const ::std::vector<uint8_t>& /*aid*/, int8_t /*p2*/, const ::android::sp<::android::se::omapi::ISecureElementListener>& /*listener*/, ::android::sp<::android::se::omapi::ISecureElementChannel>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openLogicalChannel(const ::std::vector<uint8_t>& /*aid*/, int8_t /*p2*/, const ::android::sp<::android::se::omapi::ISecureElementListener>& /*listener*/, ::android::sp<::android::se::omapi::ISecureElementChannel>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISecureElementSessionDefault
}  // namespace omapi
}  // namespace se
}  // namespace android
