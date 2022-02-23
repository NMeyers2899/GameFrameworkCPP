#pragma once
#include <exception>

template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void addItem(T item);
	void addItems(T item[], int size);
	bool removeItem(T item);
	bool removeItem(int index);
	void sortItems();

	T getItem(int index);
	int getLength();
	bool contains(T item);

	T operator[](int index);

private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArray = new T[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
		tempArray[i] = m_items[i];

	tempArray[m_length] = item;

	delete[] m_items;

	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int size)
{
	for (int i = 0; i < size; i++)
		addItem(items[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	if (!item || getLength() <= 0)
		return false;

	int j = 0;
	bool itemRemoved = false;
	T* tempArray = new T[getLength() - 1];

	for (int i = 0; i < getLength(); i++) {
		if (item != m_items[i] || itemRemoved) {
			tempArray[j] = m_items[i];
			j++;
		}
		else
			itemRemoved = true;
	}

	if (itemRemoved) {
		delete[] m_items;

		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(int index)
{
	if (getLength() <= 0)
		return false;

	int j = 0;
	bool itemRemoved = false;
	T* tempArray = new T[getLength() - 1];

	for (int i = 0; i < getLength(); i++) {
		if (i != index) {
			tempArray[j] = m_items[i];
			j++;
		}
		else
			itemRemoved = true;
	}

	if (itemRemoved) {
		delete[] m_items;

		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	int j = 0;
	T keyValue;
	// Goes through each index of the array.
	for (int i = 1; i < getLength(); i++) {
		keyValue = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > keyValue) {
			m_items[j + 1] = m_items[j];
			j--;
		}
		m_items[j + 1] = keyValue;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= getLength())
		return T();

	return m_items[index];
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline bool DynamicArray<T>::contains(T item) 
{
	return item;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= getLength())
		return T();

	throw std::exception("Index was outside the bounds of the array. Loser.");
}


