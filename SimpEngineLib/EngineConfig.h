#pragma once

namespace SimpEngine
{
	class ConfigParamParser;

	class EngineConfig
	{
		friend class ConfigParamParser;

	public:
		EngineConfig();
		~EngineConfig();

		using CommandParams = std::vector<std::wstring>;
		SimpResult LoadConfig(CommandParams& params);

	private :

		std::wstring m_ConfigPath;
		std::wstring m_LogPath;

		void ParseCommandParams(CommandParams& params);
		void LoadConfig();

		std::wstring GetDefaultConfigPath();

		std::unique_ptr<ConfigParamParser> m_ParamParser;
	};
}
