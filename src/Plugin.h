
#ifndef BRO_PLUGIN_VR_UAP
#define BRO_PLUGIN_VR_UAP

#include <plugin/Plugin.h>
#include <memory>

#include "UaParser.h"

namespace plugin {
namespace VR_UAP {

class Plugin : public ::plugin::Plugin
{
public:
        UserAgent parse(const std::string& ua) const;
protected:
	// Overridden from plugin::Plugin.
	plugin::Configuration Configure() override;
        // Parser initialization
        void InitPostScript() override;
private:
       std::shared_ptr<UserAgentParser> parser; 
};

extern Plugin plugin;

}
}

#endif
