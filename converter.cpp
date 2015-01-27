#include "converter.hpp"

void converter::link(std::shared_ptr<converter> const& to_decorate)
{
	m_to_decorate = to_decorate;
}

double converter::get_min_value() const
{
	return m_min_value;
}