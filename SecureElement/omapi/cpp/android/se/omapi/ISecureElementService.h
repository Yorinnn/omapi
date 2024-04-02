#pragma once

#include <android/se/omapi/ISecureElementReader.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace se {
namespace omapi {
class ISecureElementService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SecureElementService)
  virtual ::android::binder::Status getReaders(::std::vector<::android::String16>* _aidl_return) = 0;
  virtual ::android::binder::Status getReader(const ::android::String16& reader, ::android::sp<::android::se::omapi::ISecureElementReader>* _aidl_return) = 0;
  virtual ::android::binder::Status isNfcEventAllowed(const ::android::String16& reader, const ::std::vector<uint8_t>& aid, const ::std::vector<::android::String16>& packageNames, int32_t userId, ::std::vector<bool>* _aidl_return) = 0;
};  // class ISecureElementService

class ISecureElementServiceDefault : public ISecureElementService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getReaders(::std::vector<::android::String16>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getReader(const ::android::String16& /*reader*/, ::android::sp<::android::se::omapi::ISecureElementReader>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isNfcEventAllowed(const ::android::String16& /*reader*/, const ::std::vector<uint8_t>& /*aid*/, const ::std::vector<::android::String16>& /*packageNames*/, int32_t /*userId*/, ::std::vector<bool>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISecureElementServiceDefault
}  // namespace omapi
}  // namespace se
}  // namespace android
