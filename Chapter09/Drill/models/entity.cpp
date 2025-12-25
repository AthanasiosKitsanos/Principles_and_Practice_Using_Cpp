#include "pch.h"
#include "entity.h"

entity::entity(const std::string& lm, const std::string& n, const std::string& num, const std::string& m): last_name(lm), name(n), phone(num), email(m) {}
entity::~entity() {}