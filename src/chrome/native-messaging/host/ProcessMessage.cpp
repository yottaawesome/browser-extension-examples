#include "ProcessMessage.hpp"
#include "json\json.h"
#include "Windows.h" //ExitWindowsEx

void ProcessMessage(char* jsonMsg)
{
	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(jsonMsg, root);
	if (!parsingSuccessful)
		return;

	std::string request = root.get("request", "").asString();
	if (request == "logoff_windows")
		ExitWindowsEx(EWX_LOGOFF, 0);
}

