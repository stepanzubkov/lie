/*
    Command base class and derived classes.
    Each derived class represents one command.
    Copyright (C) 2023 Stepan Zubkov <stepanzubkov@florgon.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

class Save : public Command {
    private:
        Buffer* buffer;
    public:
        Save(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};

class Append : public Command {
    private:
        Buffer* buffer;
    public:
        Append(Buffer* buffer);
        void run(CommandArgs args);
        void help();
};
