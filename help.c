#include "shell.h"

/**
 * _cdHelp - printf help for cd command
 */
void _changedirectoryHelp(void)
{
_write("cd: cd [-L|[-P [-e]] [-@]] [dir]\n    Change the shell working dir");
_write("ectory.\n\n    Change the current directory to DIR.  The default DIR");
_write(" is the value of the\n    HOME shell variable.\n    The variable CDP");
_write("ATH defines the search path for the directory containing\n    DIR.  ");
_write("Alternative directory names in CDPATH are separated by a ");
_write("colon (:).\n    A null directory name is the same as the current dir");
_write("ectory.  If DIR begins\n    with a slash (/), then CDPATH is not use");
_write("d.\n\n    If the directory is not found, and the shell option `cdabl");
_write("e_vars' is set,\n    the word is assumed to be  a variable name.  If");
_write(" that variable has a value,\n    its value is used for DIR.\n\n    O");
_write("ptions:\n        -L      force symbolic links to be followed: resolv");
_write("e symbolic links in\n        DIR after processing instances of `..'");
_write("\n        -P      u	_putsse the physical directory structure without foll");
_write("owing symbolic\n        links: resolve symbolic links in DIR before");
_write(" processing instances\n        of `..'\n        -e      if the -P o");
_write("ption is supplied, and the current working directory\n        canno");
_write("t be determined successfully, exit with a non-zero status\n        ");
_write("-@  on systems that support it, present a file with extended attrib");
_write("utes\n            as a directory containing the file attributes\n\n");
_write("    The default is to follow symbolic links, as if `-L' were specif");
_write("ied.\n");
_write("    `..' is processed by removing the immediately previous pathname");
_write(" component\n    back to a slash or the beginning of DIR.\n\n");
_write("    Exit Status:\n");
_write("    Returns 0 if the directory is changed, and if $PWD is set succe");
_write("ssfully when\n    -P is used; non-zero otherwise.\n");
}

/**
 * _envHelp - print help for env command
 */
void _envHelp(void)
{
_write("env: env\n");
_write("    prints the current environment.\n\n");
_write("    Has no options\n");
}

/**
 * _exitHelp - print help for exit command
 */
void _exitHelp(void)
{
_write("exit: exit [n]\n");
_write("    Exit the shell.\n\n");
_write("    Exits the shell with a status of N.  ");
_write("    If N is omitted, the exit status\n");
_write("    is that of the last command executed.\n");
}

/**
 * _helpHelp - print help for help command
 */
void _helpHelp(void)
{
_write("help: help [-dms] [pattern ...]\n");
_write("    Display information about builtin commands.\n\n");
_write("    Displays brief summaries of builtin commands.  If PATTERN is\n");
_write("    specified, gives detailed help on all commands ");
_write("    matching PATTERN,\n");
_write("    otherwise the list of help topics is printed.\n\n");
_write("    Options:\n");
_write("      -d        output short description for each topic\n");
_write("      -m        display usage in pseudo-manpage format\n");
_write("      -s        output only a short usage synopsis for each topic m");
_write("atching\n        PATTERN\n\n");
_write("    Arguments:\n");
_write("      PATTERN   Pattern specifying a help topic\n\n");
_write("    Exit Status:\n");
_write("    Returns success unless PATTERN is not found or an invalid ");
_write("    option is given.\n");
}

/**
 * _defaultHelp - print help when any command found
 *
 * @prmCommand: command name
 */
void _defaultHelp(char *ptrCmd)
{
_write("bash: help: Aucune rubrique d'aide ne correspond à \"");
_write(ptrCmd);
_write("\". Essayez \"help help\", \"man -k ");
_write(ptrCmd);
_write("\" ou \"info ");
_write(ptrCmd);
_write("\".\n");
}
