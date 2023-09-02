// Integer range datastructure (ex. 0-10, 5-100)


class Range {
    public:
        int start;
        int stop;

        Range(int);
        Range(int, int);

        bool contains(int);
};
