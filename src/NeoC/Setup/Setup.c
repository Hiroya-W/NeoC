#include "Setup.h"

static void _Setup() {
	E._Setup();

	CSI._Setup();
	SGR._Setup();

	String._Setup();
	System._Setup();
}

__S _S = {
	._Setup = _Setup,
};
