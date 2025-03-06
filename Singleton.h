#pragma once
// ������ ����
// �̱��� ����? : ���α׷� ������ ��ü 1��, ���� ��𼭵� ���� ����
//				���� �� �������� ����...

template<typename T>
class Singleton
{
protected:
	Singleton() {};
	~Singleton() {};

	Singleton(const Singleton&) = delete;					// ���� ������ ����
	Singleton& operator = (const Singleton& a) = delete;	// ���� ������ �����ε� ���� 
	
public:
	static T* GetIns()
	{
		if (instance == nullptr)
		{
			instance = new T();
		}
		return instance;
	}

private:
	static T* instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;