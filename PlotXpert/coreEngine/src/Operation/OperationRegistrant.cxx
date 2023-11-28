#include <OperationRegistrant.hxx>

OperationRegistrant* OperationRegistrant::m_instance = nullptr;
std::mutex OperationRegistrant::m_mutex;


OperationRegistrant* OperationRegistrant::getInstance()
{
	if (m_instance == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_instance == nullptr)
		{
			m_instance = new OperationRegistrant();
		}
	}

	return m_instance;
}

void OperationRegistrant::registorOperation(std::unique_ptr<IOperation> operation)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	//TO DO: check if the operation is legal or not
	m_operations[operation->getType()] = std::move(operation);
}

IOperation* OperationRegistrant::getOperation(const OperationType& operType)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto it = m_operations.find(operType);
	if (it != m_operations.end())
	{
		return it->second.get();
	}

	return nullptr;
}