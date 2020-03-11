/**
 * @author      : CaféHaine (kilian.guillaume@gmail.com)
 * @file        : Shell
 * @created     : Sunday Mar 08, 2020 08:33:56 CET
 */

#ifndef SHELL_H
#define SHELL_H

#include "Arduino.h"
#include "LinkedPointerList.h"

class ShellCommand {
	public:
		ShellCommand(void (*func)(String *args), const __FlashStringHelper *name) {
			this->name = name;
			this->func = func;
		}

		void (*func)(String *args);
		const __FlashStringHelper *name;
};

class CShell {
	public:
		void begin(int baudrate);
		void handleEvent();
		void registerCommand(ShellCommand *com);

	private:
		void _help();
		void _clear_buffer();
		void _draw_prompt();
		void _run_command();

		String _buffer;
		LinkedPointerList<ShellCommand> _commands;
};

static CShell Shell;

#endif
