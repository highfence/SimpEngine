#include "stdafx.h"
#include "EngineConfig.h"
#include "ConfigParamParser.h"

namespace SimpEngine
{
	EngineConfig::EngineConfig()
	{
	}

	EngineConfig::~EngineConfig()
	{
	}

	SimpResult EngineConfig::LoadConfig(CommandParams& params)
	{
		m_ParamParser = std::make_unique<ConfigParamParser>();

		ParseCommandParams(params);

		LoadConfig();

		return SimpResult::None;
	}

	void EngineConfig::ParseCommandParams(CommandParams & params)
	{
		for (auto& param : params)
		{
			m_ParamParser->ParseParam(this, param);
		}
	}

	void EngineConfig::LoadConfig()
	{
		std::wstring configPath;

		if (m_ConfigPath.empty())
			configPath = GetDefaultConfigPath();
		else
			configPath = m_ConfigPath;

		// Todo : 여기서부터 작업합시다.
		std::wstring buffer;


	}

	std::wstring EngineConfig::GetDefaultConfigPath()
	{
		return TEXT("../Config.json");
	}
}
