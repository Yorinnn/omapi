#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/se/omapi/ISecureElementChannel.h>

namespace android {
namespace se {
namespace omapi {
class BpSecureElementChannel : public ::android::BpInterface<ISecureElementChannel> {
public:
  explicit BpSecureElementChannel(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSecureElementChannel() = default;
  ::android::binder::Status close() override;
  ::android::binder::Status isClosed(bool* _aidl_return) override;
  ::android::binder::Status isBasicChannel(bool* _aidl_return) override;
  ::android::binder::Status getSelectResponse(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status transmit(const ::std::vector<uint8_t>& command, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status selectNext(bool* _aidl_return) override;
};  // class BpSecureElementChannel
}  // namespace omapi
}  // namespace se
}  // namespace android
