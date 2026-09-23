#include "DestroyAnimation.h"

void DestroyAnimation::Start()
{
    m_Time = 0.0f;
}

void DestroyAnimation::Update(float dt)
{
    m_Time += dt;
}

bool DestroyAnimation::IsFinished() const
{
    return m_Time >= m_Duration;
}

float DestroyAnimation::GetTime() const
{
    return m_Time;
}
