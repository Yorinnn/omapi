#pragma once

#include <binder/IInterface.h>
#include <android/se/omapi/ISecureElementSession.h>

namespace android {
namespace se {
namespace omapi {
class BnSecureElementSession : public ::android::BnInterface<ISecureElementSession> {
public:
  static constexpr uint32_t TRANSACTION_getAtr = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_close = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_closeChannels = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_isClosed = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_openBasicChannel = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_openLogicalChannel = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnSecureElementSession();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSecureElementSession

class ISecureElementSessionDelegator : public BnSecureElementSession {
public:
  explicit ISecureElementSessionDelegator(::android::sp<ISecureElementSession> &impl) : _aidl_delegate(impl) {}

  ::android::binder::Status getAtr(::std::vector<uint8_t>* _aidl_return) override {
    return _aidl_delegate->getAtr(_aidl_return);
  }
  ::android::binder::Status close() override {
    return _aidl_delegate->close();
  }
  ::android::binder::Status closeChannels() override {
    return _aidl_delegate->closeChannels();
  }
  ::android::binder::Status isClosed(bool* _aidl_return) override {
    return _aidl_delegate->isClosed(_aidl_return);
  }
  ::android::binder::Status openBasicChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) override {
    return _aidl_delegate->openBasicChannel(aid, p2, listener, _aidl_return);
  }
  ::android::binder::Status openLogicalChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) override {
    return _aidl_delegate->openLogicalChannel(aid, p2, listener, _aidl_return);
  }
private:
  ::android::sp<ISecureElementSession> _aidl_delegate;
};  // class ISecureElementSessionDelegator
}  // namespace omapi
}  // namespace se
}  // namespace android
