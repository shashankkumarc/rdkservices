/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
*
* Copyright 2019 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#pragma once

#include <plugins/plugins.h>

/**
 * DO NOT USE THIS.
 *
 * Instead, use:
 * - ThunderInterfaces
 * - IShell notifications:
 *      PluginHost::IShell::Register
 *      PluginHost::IPlugin::INotification
 * - PluginHost::IShell::Job
 * - Preconditions
 */

namespace Utils
{
    struct SecurityToken
    {
        static void getSecurityToken(std::string& token);
        static bool isThunderSecurityConfigured();

    private:
        static std::string m_sToken;
        static bool m_sThunderSecurityChecked;
    };

    // Thunder Plugin Communication
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> getThunderControllerClient(std::string callsign="");

    void activatePlugin(const char* callSign);

    bool isPluginActivated(const char* callSign);
} // namespace Utils
