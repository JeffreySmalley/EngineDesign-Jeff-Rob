class IScriptManager
{
	virtual bool VInit();
	virtual void VExecuteFile(const char* resource);
	virtual void VExecuteString(const char* str);
};