#pragma once

struct IIPCVector;

class ipc_vector
{
public:
	void init();
	void uninit();

	int operator[](int index) const;

	int size() const;

	void push_back(int value);

protected:
	IIPCVector* m_interface;
};