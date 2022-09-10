#pragma once
#include "util.h"
#include "constants.h"

enum class Action
{
	NO_ACTION = 1000,
	UNEXPECTED_ERROR = 1001,
	INSTALL_INTEGRATIONS = 1002,
	REMOVE_INTEGRATIONS = 1003,
	NOTHING_TO_INSTALL = 1004,
};


template<typename OStream>
OStream& operator<<(OStream& os, const Action& action)
{
	switch (action) {
	case Action::NO_ACTION:
		return os << "NO ACTION";
	case Action::UNEXPECTED_ERROR:
		return os << "UNEXPECTED ERROR";
	case Action::INSTALL_INTEGRATIONS:
		return os << "INSTALL INTEGRATIONS";
	case Action::REMOVE_INTEGRATIONS:
		return os << "REMOVE INTEGRATIONS";
	case Action::NOTHING_TO_INSTALL:
		return os << "NOTHING TO INSTALL";
	default:
		return os << "Not defined, add definition for type in 'IntegrationWizard.h'";
	}
}

namespace IntegrationWizard
{

constexpr auto ALL_PLATFORMS = -1;
extern vector<wstring> alteredPlatforms;

enum class Architecture { x32, x64 };

struct PlatformInstallation
{
	path path;
	Architecture architecture = Architecture::x32;
	string process;
	wstring name;
};

struct PlatformRegistry
{
	Architecture architecture;
	string process;
	string key;
	string value;
};

map<int, PlatformInstallation> getInstalledPlatforms();
void alterPlatform(Action action, int platformID, map<int, PlatformInstallation> platforms);

}
