#include "BuildStatement.h"

BuildStatement::BuildStatement(std::unique_ptr<Expression> target, std::unique_ptr<Expression> dependencies, std::unique_ptr<Expression> buildCommand)
	: target(std::move(target)), dependencies(std::move(dependencies)), buildCommand(std::move(buildCommand)),  isBuilt(false) {}




void BuildStatement::execute(VariablesMap& map)
{
	
	std::string targetString = getTarget(map);
	std::string consoleCommand;

	auto dependenciesResult = dependencies->evaluate(map);
	if (!dependenciesResult.empty())
	{
		for (auto& dep : dependenciesResult)
		{
			if (map.buildExists(dep))
			{
				auto depBuild = map.getBuildStatement(dep);
				if (!depBuild->getBuilt())
					depBuild->execute(map);
			}
			else
			{
				std::string targ = getTarget(map);
				std::shared_ptr<BuildStatement> thisPtr = std::make_shared<BuildStatement>(std::move(target), std::move(dependencies), std::move(buildCommand));
				map.storeBuildStatement(targ, std::move(thisPtr));
				return;
			}

		}
	}
		auto commandVector = buildCommand->evaluate(map);
		for (auto& identifier : commandVector)
		{
			consoleCommand += identifier;
			consoleCommand += std::string(" ");
		}
		consoleCommand += std::string(" -o ") + targetString;

		const char* consoleCommandChar = consoleCommand.c_str();

		system(consoleCommandChar);
		std::string targ = getTarget(map);
		std::shared_ptr<BuildStatement> thisPtr = std::make_shared<BuildStatement>(std::move(target), std::move(dependencies), std::move(buildCommand));
		thisPtr->isBuilt = true;
		map.storeBuildStatement(targ, std::move(thisPtr));
}


