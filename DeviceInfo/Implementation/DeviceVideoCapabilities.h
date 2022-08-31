#pragma once

#include "../Module.h"
#include <interfaces/IDeviceInfo2.h>

namespace WPEFramework {
namespace Plugin {
    class DeviceVideoCapabilities : public Exchange::IDeviceVideoCapabilities {
    private:
        DeviceVideoCapabilities(const DeviceVideoCapabilities&) = delete;
        DeviceVideoCapabilities& operator=(const DeviceVideoCapabilities&) = delete;

    public:
        DeviceVideoCapabilities();

        BEGIN_INTERFACE_MAP(DeviceVideoCapabilities)
        INTERFACE_ENTRY(Exchange::IDeviceVideoCapabilities)
        END_INTERFACE_MAP

    private:
        // IDeviceVideoCapabilities interface
        uint32_t SupportedVideoDisplays(RPC::IStringIterator*& supportedVideoDisplays) const override;
        uint32_t HostEDID(string& edid) const override;
        uint32_t DefaultResolution(const string& videoDisplay, string& defaultResolution) const override;
        uint32_t SupportedResolutions(const string& videoDisplay, RPC::IStringIterator*& supportedResolutions) const override;
        uint32_t SupportedHdcp(const string& videoDisplay, Exchange::IDeviceVideoCapabilities::CopyProtection& supportedHDCPVersion) const override;
    };
}
}
