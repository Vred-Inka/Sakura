#pragma once
class ScoreSystem
{
public:
	void AddVirusDestroyed();
	void AddPillDestroyed();

	int GetScore() const { return m_Score; };

private:
	int m_Score = 0;
};

