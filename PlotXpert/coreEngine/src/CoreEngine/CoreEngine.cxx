#include <CoreEngine.hxx>

CoreEngine* CoreEngine::m_instance = nullptr;
std::mutex CoreEngine::m_mutex;


CoreEngine::CoreEngine()
	: m_operationRegistrant(OperationRegistrant::getInstance()),
	m_resultCache(10)
{}

CoreEngine* CoreEngine::getInstance()
{
	if (m_instance == nullptr)	// Avoid acquiring the lock every time the GetInstance() method is called. 
	{
		std::lock_guard<std::mutex> lock(m_mutex);	// When a thread passes the first null check, it acquires a lock on a mutex. This ensures that only one thread can enter the following block of code at a time, preventing concurrent instantiation of the singleton.

		if (m_instance == nullptr)
		{
			m_instance = new CoreEngine();
		}
	}

	return m_instance;
}

// Hypothetical function to generate a unique key for caching
std::string CoreEngine::generateCacheKey(const IOperationContext& context) {

	return "";
}

OperationResult CoreEngine::execute(IOperationContext* context) {
	// Check if the result is cached
	std::string cacheKey = generateCacheKey(*context); // This is a hypothetical function to generate a unique key for caching
	if (m_resultCache.contains(cacheKey)) 
	{
		return *(m_resultCache.get(cacheKey));
	}

	// If not cached, fetch the operation from the registrant
	OperationType type = context->getOperationType();
	IOperation* operation = m_operationRegistrant->getOperation(type);
	if (operation == nullptr)
	{
		//TO DO: register operation or find it somewhere..
	}

	// Execute the operation
	std::shared_ptr<OperationResult> result;
	if (auto unaryOperation = dynamic_cast<IUnaryOperation*>(operation)) {
		result.reset(unaryOperation->execute(context->getData()));
	}
	else if (auto binaryOperation = dynamic_cast<IBinaryOperation*>(operation)) {
		result.reset(binaryOperation->execute(context->getData()));
	}
	// ... Handle other operation types as needed

	// Cache the result and return
	m_resultCache.put(cacheKey, result);
	return *result;
}

