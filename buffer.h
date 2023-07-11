// Buffer class that represents opened file
#include <vector>
#include <string>
#include <fstream>

#if !defined(BUFFER)
#define BUFFER

class Buffer {
    private:
        std::fstream file;
        std::vector<std::string>* lines;
        std::size_t current_line;
        std::size_t prev_current_line;
    public:
        bool changed;
        Buffer();
        Buffer(std::string filename);
        std::vector<std::string>* get_lines() const;
        std::size_t get_current_line() const;
        std::size_t get_prev_current_line() const;
        void set_current_line(std::size_t current_line);
        int open_file(std::string filename);
        int write();
};

#endif
