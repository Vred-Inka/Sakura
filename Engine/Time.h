#pragma once
class Time
{
public:
	static float Update();
	static float TotalTime();
	static float GetDeltaTime();

private:
	static float s_DeltaTime;
};

