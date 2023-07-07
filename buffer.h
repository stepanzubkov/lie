// Buffer class that represents opened file
#include <vector>
#include <string>
#include <fstream>

#if !defined(BUFFER)
#define BUFFER

class Buffer {
    private:
        std::fstream file;
        std::vector<std::string> lines;
        std::size_t current_line;
    public:
        Buffer();
        Buffer(std::string filename);
        std::vector<std::string> get_lines() const;
        void set_lines(std::vector<std::string> lines);
        std::size_t get_current_line() const;
        void set_current_line(std::size_t current_line);
        int open_file(std::string filename);
        int write();
};

#endif
