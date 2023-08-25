#if !defined(VALIDATION_RESULT)
#define VALIDATION_RESULT

template <typename T>
struct ValidationResult {
    bool success;
    T value;
};

#endif
