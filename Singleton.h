#pragma once
// 디자인 패턴
// 싱글톤 패턴? : 프로그램 내에서 객체 1개, 언제 어디서든 접근 가능
//				조금 더 안정적인 구조...

template<typename T>
class Singleton
{
protected:
	Singleton() {};
	~Singleton() {};

	Singleton(const Singleton&) = delete;					// 복사 생성자 삭제
	Singleton& operator = (const Singleton& a) = delete;	// 대입 연산자 오버로드 삭제 
	
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