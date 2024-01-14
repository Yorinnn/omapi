#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/se/omapi/ISecureElementReader.h>

namespace android {
namespace se {
namespace omapi {
class BpSecureElementReader : public ::android::BpInterface<ISecureElementReader> {
public:
  explicit BpSecureElementReader(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSecureElementReader() = default;
  ::android::binder::Status isSecureElementPresent(bool* _aidl_return) override;
  ::android::binder::Status openSession(::android::sp<::android::se::omapi::ISecureElementSession>* _aidl_return) override;
  ::android::binder::Status closeSessions() override;
  ::android::binder::Status reset(bool* _aidl_return) override;
};  // class BpSecureElementReader
}  // namespace omapi
}  // namespace se
}  // namespace android
