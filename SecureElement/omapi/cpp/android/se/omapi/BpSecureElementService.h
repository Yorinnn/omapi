#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/se/omapi/ISecureElementService.h>

namespace android {
namespace se {
namespace omapi {
class BpSecureElementService : public ::android::BpInterface<ISecureElementService> {
public:
  explicit BpSecureElementService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSecureElementService() = default;
  ::android::binder::Status getReaders(::std::vector<::android::String16>* _aidl_return) override;
  ::android::binder::Status getReader(const ::android::String16& reader, ::android::sp<::android::se::omapi::ISecureElementReader>* _aidl_return) override;
  ::android::binder::Status isNfcEventAllowed(const ::android::String16& reader, const ::std::vector<uint8_t>& aid, const ::std::vector<::android::String16>& packageNames, int32_t userId, ::std::vector<bool>* _aidl_return) override;
};  // class BpSecureElementService
}  // namespace omapi
}  // namespace se
}  // namespace android
