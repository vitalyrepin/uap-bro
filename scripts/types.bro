module UAP;

export {
        type DeviceRec: record {
            model: string &log &optional;
            brand: string &log &optional;
            family: string &log &optional;
        };

	type AgentRec: record {
	    major: string &log &optional;
	    minor: string &log &optional;
	    patch: string &log &optional;
	    patch_minor: string &log &optional;
            family: string &log &optional;
	};

	type UserAgentRec: record {
	    device: DeviceRec &log &optional;
	    os: AgentRec &log &optional;
	    browser: AgentRec &log &optional;
	};
}
