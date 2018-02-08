#include <string>

#include "Plugin.h"
#include "uap.bif.h"

namespace plugin { namespace VR_UAP { Plugin plugin; } }

using namespace plugin::VR_UAP;

UserAgent Plugin::parse(const std::string& ua) const
{
  return parser->parse(ua);
}

void Plugin::InitPostScript()
{
        std::string regex_path; 
        regex_path.assign((const char*) BifConst::UAP::uap_core_regex_path->Bytes(), BifConst::UAP::uap_core_regex_path->Len());
        parser = std::make_shared<UserAgentParser>(regex_path);
}
       
plugin::Configuration Plugin::Configure()
{
  // Plugin configuration
  plugin::Configuration config;
  config.name = "VR::UAP";
  config.description = "User Agent Parser - Bro implementation based on uap-core";
  config.version.major = 0;
  config.version.minor = 1;
  return config;
}
