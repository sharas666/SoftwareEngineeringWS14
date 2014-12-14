#ifndef Command_HPP
#define Command_HPP

struct Command
{
	Command(std::string const& cmd):
		m_command{cmd}
	{}


	std::string m_command;
};

#endif //COMMAND_HPP