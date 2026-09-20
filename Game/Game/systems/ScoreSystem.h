#pragma once

struct MatchResult;

class ScoreSystem
{
public:
	void Process(const MatchResult& result);
	int GetScore() const { return m_Score; };

private:
	int m_Score = 0;
};

