#pragma once

#include <android/se/omapi/ISecureElementSession.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace se {
namespace omapi {
class ISecureElementReader : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SecureElementReader)
  virtual ::android::binder::Status isSecureElementPresent(bool* _aidl_return) = 0;
  virtual ::android::binder::Status openSession(::android::sp<::android::se::omapi::ISecureElementSession>* _aidl_return) = 0;
  virtual ::android::binder::Status closeSessions() = 0;
  virtual ::android::binder::Status reset(bool* _aidl_return) = 0;
};  // class ISecureElementReader

class ISecureElementReaderDefault : public ISecureElementReader {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status isSecureElementPresent(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openSession(::android::sp<::android::se::omapi::ISecureElementSession>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeSessions() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reset(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISecureElementReaderDefault
}  // namespace omapi
}  // namespace se
}  // namespace android
