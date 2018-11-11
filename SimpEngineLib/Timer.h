#pragma once

namespace SimpEngine
{
	// �ʿ��� ��ɸ� ������ Ÿ�̸�.
	// �ʱ�ȭ �ÿ� InitTimer�� �����ְ�,
	// Tick�� �������� ProcessTime��,
	// ��Ÿ Ÿ���� �ʿ��Ҷ� ���� GetElapsedTime�� �����ָ� �ȴ�.
	//
	class Timer
	{
	public:

		Timer();
		virtual ~Timer();

		void InitTimer();
		void ProcessTime();

		inline float GetElapsedTime() const
		{
			return m_ElapsedTime;
		}

	private:

		bool m_UseQPF;
		float m_ElapsedTime;
		LONGLONG m_QPFTicksPerSec;
		LONGLONG m_LastElapsedTime;
	};
}
