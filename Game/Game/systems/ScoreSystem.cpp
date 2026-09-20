#include "ScoreSystem.h"

#include "MatchResult.h"

void ScoreSystem::Process(const MatchResult& result)
{
	m_Score += result.m_VirusCount * 100;
	m_Score += result.m_PillCount * 10;
}
