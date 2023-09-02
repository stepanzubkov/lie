// Integer range datastructure (ex. 0-10, 5-100)


class Range {
    private:
        int start;
        int stop;
    public:
        Range(int);
        Range(int, int);

        bool contains(int);
};
