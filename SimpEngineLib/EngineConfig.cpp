#include "stdafx.h"
#include "FileIOHelper.h"
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

	SimpResult EngineConfig::LoadAllConfig(CommandParams& params)
	{
		m_ParamParser = std::make_unique<ConfigParamParser>();

		ParseCommandParams(params);

		LoadBasicConfig();

		return SimpResult::None;
	}

	void EngineConfig::ParseCommandParams(CommandParams & params)
	{
		for (auto& param : params)
		{
			m_ParamParser->ParseParam(this, param);
		}
	}

	SimpResult EngineConfig::LoadBasicConfig()
	{
		std::wstring configFileBuffer = FileIOHelper::GetFileBuffer(m_ConfigPath);
		Json::Value root = Json::Value(configFileBuffer.data());

		// Todo : 여기서부터 작업합시다.
		
		return SimpResult::None;
	}

	std::wstring EngineConfig::GetDefaultConfigPath()
	{
		return TEXT("../Config.json");
	}
}
