#pragma once

#include <map>
#include <vector>
#include <mutex>
#include "IOperationContext.hxx"
#include "IOperation.hxx"
#include "OperationType.hxx"
#include "OperationResult.hxx"
#include "OperationRegistrant.hxx"
#include "Pool.hxx"
#include "Cache.hxx"


class CoreEngine {
public:
	static CoreEngine* getInstance();
	~CoreEngine() = default;

	// Methods
	OperationResult execute(IOperationContext* context);
	IOperationContext* getContext(OperationType type);
	void releaseContext(IOperationContext* context);

private:
	std::string generateCacheKey(const IOperationContext* context);

	// Constructors
	CoreEngine() = default;

	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;

	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	// Data members
	static CoreEngine* instance;
	static std::mutex mutex;

	OperationRegistrant operationRegistrant;
	Pool<IOperationContext> contextPool;
	Cache<OperationType, IOperation*> operationCache;
	Cache<std::string, OperationResult> resultCache;
};
