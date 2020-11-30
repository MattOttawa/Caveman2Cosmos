#pragma once

#ifndef custom_array_h__
#define custom_array_h__

namespace seq
{
	template <class T>
	class array
	{
	public:
		array() { }

		~array()
		{
			if (m_array)
				delete[] m_array;
		}

		void init(size_t size, T value)
		{
			m_array = new T[size];
			for (uint32_t i = 0; i < size; i++)
			{
				m_array[i] = value;
			}
		}

		T& operator[](const uint32_t& index) const
		{
			FASSERT_BOUNDS(0, size(), index)
			return m_array[index];
		}

	protected:
		size_t size() const
		{
			return sizeof(m_array) / sizeof(T);
		}

		T* m_array;
	};
}

#endif
