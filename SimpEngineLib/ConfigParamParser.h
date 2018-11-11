#pragma once

namespace SimpEngine
{

	class EngineConfig;
	enum class ConfigParamName : int
	{
		None = 0,
		ConfigFilePath = 1,
		LogFilePath = 2,

		ConfigParamCount
	};

	class ConfigParamParser
	{
	public:
		ConfigParamParser();
		~ConfigParamParser();

		void ParseParam(EngineConfig* config, std::wstring param);

	private :

		void RegistParsingFunctions();

		void ParseConfigFilePath(EngineConfig*, std::wstring&);
		void ParseLogFilePath(EngineConfig*, std::wstring&);

		using ParseConfigFunction = std::function<void(EngineConfig*, std::wstring&)>;
		using ParseFunctionList = std::unordered_map<ConfigParamName, ParseConfigFunction>;
		ParseFunctionList m_ParseFunctions;

		ConfigParamName GetConfigNameFromString(std::wstring paramString);
		std::wstring GetConfigNameToString(ConfigParamName configType);

	};
}
