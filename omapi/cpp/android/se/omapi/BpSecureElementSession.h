#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/se/omapi/ISecureElementSession.h>

namespace android {
namespace se {
namespace omapi {
class BpSecureElementSession : public ::android::BpInterface<ISecureElementSession> {
public:
  explicit BpSecureElementSession(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSecureElementSession() = default;
  ::android::binder::Status getAtr(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status close() override;
  ::android::binder::Status closeChannels() override;
  ::android::binder::Status isClosed(bool* _aidl_return) override;
  ::android::binder::Status openBasicChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) override;
  ::android::binder::Status openLogicalChannel(const ::std::vector<uint8_t>& aid, int8_t p2, const ::android::sp<::android::se::omapi::ISecureElementListener>& listener, ::android::sp<::android::se::omapi::ISecureElementChannel>* _aidl_return) override;
};  // class BpSecureElementSession
}  // namespace omapi
}  // namespace se
}  // namespace android
