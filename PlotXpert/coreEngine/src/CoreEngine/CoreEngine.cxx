#include <CoreEngine.hxx>

CoreEngine* CoreEngine::instance = nullptr;
std::mutex CoreEngine::mutex;


CoreEngine::CoreEngine()
	: operationRegistrant(OperationRegistrant::getInstance()),
	contextPool(),
	operationCache(),
	resultCache()
{}

CoreEngine* CoreEngine::getInstance()
{
	if (instance == nullptr)	// Avoid acquiring the lock every time the GetInstance() method is called. 
	{
		std::lock_guard<std::mutex> lock(mutex);	// When a thread passes the first null check, it acquires a lock on a mutex. This ensures that only one thread can enter the following block of code at a time, preventing concurrent instantiation of the singleton.

		if (instance == nullptr)
		{
			instance = new CoreEngine();
		}
	}

	return instance;
}



OperationResult CoreEngine::execute(IOperationContext* context) {
	// Check if the result is cached
	std::string cacheKey = generateCacheKey(context); // This is a hypothetical function to generate a unique key for caching
	if (resultCache.hasItem(cacheKey)) {
		return resultCache.getItem(cacheKey);
	}

	// If not cached, fetch the operation from the registrant
	OperationType type = context.getOperationType();
	IOperation* operation = operationRegistrant.getOperation(type);

	// Execute the operation
	OperationResult result;
	if (auto unaryOperation = dynamic_cast<IUnaryOperation*>(operation)) {
		result = unaryOperation->execute(context.getData()[0]);
	}
	else if (auto binaryOperation = dynamic_cast<IBinaryOperation*>(operation)) {
		result = binaryOperation->execute(context.getData()[0], context.getData()[1]);
	}
	// ... Handle other operation types as needed

	// Cache the result and return
	resultCache.putItem(cacheKey, result);
	return result;
}

IOperationContext* CoreEngine::getContext(OperationType type) {
	IOperationContext* context = contextPool.getItem();
	context->setOperationType(type); // Assuming a setter for operation type, you might adjust based on design
	return context;
}

void CoreEngine::releaseContext(IOperationContext* context) {
	contextPool.returnItem(context);
}

// Hypothetical function to generate a unique key for caching
std::string CoreEngine::generateCacheKey(const IOperationContext& context) {
	// Convert operation type and data to a string representation
	// This is a basic example; a more sophisticated key generation might be needed
	return std::to_string(static_cast<int>(context.getOperationType())) + "_" + context.getDataStringRepresentation();
}
