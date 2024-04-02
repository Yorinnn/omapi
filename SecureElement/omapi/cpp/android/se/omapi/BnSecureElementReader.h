#pragma once

#include <binder/IInterface.h>
#include <android/se/omapi/ISecureElementReader.h>

namespace android {
namespace se {
namespace omapi {
class BnSecureElementReader : public ::android::BnInterface<ISecureElementReader> {
public:
  static constexpr uint32_t TRANSACTION_isSecureElementPresent = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_openSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_closeSessions = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_reset = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnSecureElementReader();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSecureElementReader

class ISecureElementReaderDelegator : public BnSecureElementReader {
public:
  explicit ISecureElementReaderDelegator(::android::sp<ISecureElementReader> &impl) : _aidl_delegate(impl) {}

  ::android::binder::Status isSecureElementPresent(bool* _aidl_return) override {
    return _aidl_delegate->isSecureElementPresent(_aidl_return);
  }
  ::android::binder::Status openSession(::android::sp<::android::se::omapi::ISecureElementSession>* _aidl_return) override {
    return _aidl_delegate->openSession(_aidl_return);
  }
  ::android::binder::Status closeSessions() override {
    return _aidl_delegate->closeSessions();
  }
  ::android::binder::Status reset(bool* _aidl_return) override {
    return _aidl_delegate->reset(_aidl_return);
  }
private:
  ::android::sp<ISecureElementReader> _aidl_delegate;
};  // class ISecureElementReaderDelegator
}  // namespace omapi
}  // namespace se
}  // namespace android
