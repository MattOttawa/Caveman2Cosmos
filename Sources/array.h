#pragma once

#ifndef custom_array_h__
#define custom_array_h__

namespace seq
{
	template <class T>
	class array
	{
	public:
		~array()
		{
			//if (m_array)
				delete[] m_array;
		}

		void init(const size_t size, const T value)
		{
			m_array = new T[size];
			foreach_(T& element, m_array)
			{
				element = value;
			}
		}

		T& operator[](const uint32_t& index) const
		{
			FASSERT_BOUNDS(0, size(), index)
			return m_array[index];
		}

		size_t size() const
		{
			return sizeof(m_array) / sizeof(T);
		}

		DECLARE_INDEX_ITERATORS_CONST(seq::array<T>, T, array_iterator, iterator, const_iterator, first, next)

		iterator begin() { return iterator(this); }
		iterator end() { return iterator(); }

		const_iterator begin() const { return iterator(this); }
		const_iterator end() const { return iterator(); }

		T* first(int* pIterIdx, bool bRev = false) const
		{
			*pIterIdx = 0;
			return next(pIterIdx);
		}

		T* next(int* pIterIdx, bool bRev = false) const
		{
			T* pObj = &m_array[*pIterIdx];
			*pIterIdx++;
			return pObj;
		}

	protected:
		T* m_array;
	};
}

#endif
