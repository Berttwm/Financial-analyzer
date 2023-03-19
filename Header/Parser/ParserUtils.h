#pragma once
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

enum class CommandType {
	metric,
	category,
	help,
};

/* Unordered_map holding the input to a command type */
const std::unordered_map<std::string, CommandType> InputStringToCommand = {
	{"--i", CommandType::metric},
	{"--c", CommandType::category},
	{"--help", CommandType::help},
};