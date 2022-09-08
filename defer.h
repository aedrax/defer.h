#define DEFER_MERGE(a, b) a##b
#define DEFER_VARNAME(a) DEFER_MERGE(defer_scopevar_, a)
#define DEFER_FUNCNAME(a) DEFER_MERGE(defer_scopefunc_, a)
#define DEFER(BLOCK)                                                       \
  void DEFER_FUNCNAME(__LINE__)(__attribute__((unused)) int *a) { BLOCK; } \
  __attribute__((cleanup(DEFER_FUNCNAME(__LINE__)))) int DEFER_VARNAME(__LINE__)

// Usage:
/*
  void dosomething()
  {
    char* data = malloc(100);
    DEFER(free(data));
    
    dosomethingwith(data);
  }
*/