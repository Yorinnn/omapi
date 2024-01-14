#pragma once

#include <binder/IInterface.h>
#include <android/se/omapi/ISecureElementService.h>

namespace android {
namespace se {
namespace omapi {
class BnSecureElementService : public ::android::BnInterface<ISecureElementService> {
public:
  static constexpr uint32_t TRANSACTION_getReaders = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getReader = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isNfcEventAllowed = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnSecureElementService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSecureElementService

class ISecureElementServiceDelegator : public BnSecureElementService {
public:
  explicit ISecureElementServiceDelegator(::android::sp<ISecureElementService> &impl) : _aidl_delegate(impl) {}

  ::android::binder::Status getReaders(::std::vector<::android::String16>* _aidl_return) override {
    return _aidl_delegate->getReaders(_aidl_return);
  }
  ::android::binder::Status getReader(const ::android::String16& reader, ::android::sp<::android::se::omapi::ISecureElementReader>* _aidl_return) override {
    return _aidl_delegate->getReader(reader, _aidl_return);
  }
  ::android::binder::Status isNfcEventAllowed(const ::android::String16& reader, const ::std::vector<uint8_t>& aid, const ::std::vector<::android::String16>& packageNames, int32_t userId, ::std::vector<bool>* _aidl_return) override {
    return _aidl_delegate->isNfcEventAllowed(reader, aid, packageNames, userId, _aidl_return);
  }
private:
  ::android::sp<ISecureElementService> _aidl_delegate;
};  // class ISecureElementServiceDelegator
}  // namespace omapi
}  // namespace se
}  // namespace android
