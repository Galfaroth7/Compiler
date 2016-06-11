#include "Loop.h"

Loop::Loop(std::string it, std::unique_ptr<Expression> list, std::unique_ptr<Statement> bl) :
	iterator(std::move(it)), collection(std::move(list)), block(std::move(bl)) {}


Loop::~Loop()
{
}


void Loop::execute(VariablesMap& map)
{
	{
		std::vector<std::string> tempVector;
		if (map.containsVariable(iterator))
		{
			//throw exception
		}
		auto result = collection->evaluate(map);
		for (auto& elem : result)
		{
			tempVector.push_back(elem);
			map.storeVariable(iterator, tempVector);
			block->execute(map);
			map.eraseVariable(iterator);
			tempVector.pop_back();
		}
	}
}