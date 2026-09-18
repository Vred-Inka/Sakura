#include "ScoreSystem.h"

void ScoreSystem::AddVirusDestroyed()
{
	m_Score += 100;
}

void ScoreSystem::AddPillDestroyed()
{
	m_Score += 10;
}
