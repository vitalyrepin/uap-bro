module UAP;

export {

function fillVersion(s: string): string
        {
          if (|s| > 0)
             return s;
          else
             return "0";
        }


function AgentRecToVersionString(agent: AgentRec): string
        {
         return string_cat(fillVersion(agent$major), ".", fillVersion(agent$minor), ".", fillVersion(agent$patch));
        }

function AgentRecToString(agent: AgentRec): string
        {
         return string_cat(agent$family, " ", AgentRecToVersionString(agent));   
        }

function UserAgentRecToString(ua: UserAgentRec): string
        {
         return string_cat(AgentRecToString(ua$browser), "/", AgentRecToString(ua$os));   
        }
}
