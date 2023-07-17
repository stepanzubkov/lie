// Command base class and derived classes.
// Each derived class represents one command.
#include <map>
#include <string>
#include "../buffer.h"
#include "../parse.h"

class Command {
    public:
        virtual void run(CommandArgs) {}
        virtual void help() {}
};

class Quit : public Command {
    public:
        void run(CommandArgs _);
        void help();
};

class Help : public Command {
    private:
        std::map<std::string, Command*>& commands;
        std::map<std::string, std::string> commands_aliases;
    public:
        Help(std::map<std::string, Command*>& commands, std::map<std::string, std::string>& commands_aliases);
        void run(CommandArgs args);
        void help();
};
class Print : public Command {
    private:
        Buffer* buffer;
    public:
        Print(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};

class Open : public Command {
    private:
        Buffer* buffer;
    public:
        Open(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};

class GoTo : public Command {
    private:
        Buffer* buffer;
    public:
        GoTo(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};

class Change : public Command {
    private:
        Buffer* buffer;
    public:
        Change(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};
