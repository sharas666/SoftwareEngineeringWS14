#ifndef Command_HPP
#define Command_HPP

struct Command
{
	Command(std::string cmd, double value):
		m_command{cmd},
		m_value{value}
	{}


	std::string m_command;
	double m_value;
};

#endif //COMMAND_HPP