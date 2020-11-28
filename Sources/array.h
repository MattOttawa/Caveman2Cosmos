#pragma once

#ifndef custom_array_h__
#define custom_array_h__

template <class T>
class array
{
public:
	array() { }

	explicit array(const array<T>& source)
		: m_array(source)
		{}

	explicit array(const size_t& size, const T value)
	{
		init(size, value);
	}

	~array()
	{
		delete[] m_array;
	}

	void init(const size_t& size, const T value)
	{
		m_array = new T[size];
		for (uint32_t i = 0; i < size; i++)
		{
			m_array[i] = value;
		}
	}

	void init(const size_t& size, const array<T>& source)
	{
		m_array = new T[size];
		for (uint32_t i = 0; i < size; i++)
		{
			m_array[i] = source[i];
		}
	}

	T& operator[](int index) const
	{
		FASSERT_BOUNDS(0, size(), static_cast<size_t>(index))
		return m_array[index];
	}

protected:
	size_t size() const
	{
		return sizeof(m_array) / sizeof(T);
	}

	T* m_array;
};

#endif
