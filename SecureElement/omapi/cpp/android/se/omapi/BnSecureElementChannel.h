#pragma once

#include <binder/IInterface.h>
#include <android/se/omapi/ISecureElementChannel.h>

namespace android {
namespace se {
namespace omapi {
class BnSecureElementChannel : public ::android::BnInterface<ISecureElementChannel> {
public:
  static constexpr uint32_t TRANSACTION_close = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_isClosed = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isBasicChannel = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getSelectResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_transmit = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_selectNext = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnSecureElementChannel();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSecureElementChannel

class ISecureElementChannelDelegator : public BnSecureElementChannel {
public:
  explicit ISecureElementChannelDelegator(::android::sp<ISecureElementChannel> &impl) : _aidl_delegate(impl) {}

  ::android::binder::Status close() override {
    return _aidl_delegate->close();
  }
  ::android::binder::Status isClosed(bool* _aidl_return) override {
    return _aidl_delegate->isClosed(_aidl_return);
  }
  ::android::binder::Status isBasicChannel(bool* _aidl_return) override {
    return _aidl_delegate->isBasicChannel(_aidl_return);
  }
  ::android::binder::Status getSelectResponse(::std::vector<uint8_t>* _aidl_return) override {
    return _aidl_delegate->getSelectResponse(_aidl_return);
  }
  ::android::binder::Status transmit(const ::std::vector<uint8_t>& command, ::std::vector<uint8_t>* _aidl_return) override {
    return _aidl_delegate->transmit(command, _aidl_return);
  }
  ::android::binder::Status selectNext(bool* _aidl_return) override {
    return _aidl_delegate->selectNext(_aidl_return);
  }
private:
  ::android::sp<ISecureElementChannel> _aidl_delegate;
};  // class ISecureElementChannelDelegator
}  // namespace omapi
}  // namespace se
}  // namespace android
