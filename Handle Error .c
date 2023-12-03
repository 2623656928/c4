#include <stdio.h>
#include <stdlib.h>

// 错误类型的枚举
typedef enum {
    LEXICAL_ERROR,
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    CODEGEN_ERROR
} ErrorType;

// 错误信息结构
typedef struct {
    ErrorType type;
    char* message;
    int line;
    int column;
} ErrorMessage;

// 报告错误的函数
void reportError(ErrorMessage error) {
    const char* errorTypeStrings[] = {
        "Lexical Error",
        "Syntax Error",
        "Semantic Error",
        "Code Generation Error"
    };

    fprintf(stderr, "%s at line %d, column %d: %s\n", errorTypeStrings[error.type], error.line, error.column, error.message);

    // 在实际应用中，你可能会选择在这里终止编译过程或采取其他适当的措施
    exit(EXIT_FAILURE);
}

// 词法分析阶段的错误处理
void lexError(int line, int column, char* message) {
    ErrorMessage error = { LEXICAL_ERROR, message, line, column };
    reportError(error);
}

// 语法分析阶段的错误处理
void parseError(int line, int column, char* message) {
    ErrorMessage error = { SYNTAX_ERROR, message, line, column };
    reportError(error);
}

// 语义分析阶段的错误处理
void semanticError(int line, int column, char* message) {
    ErrorMessage error = { SEMANTIC_ERROR, message, line, column };
    reportError(error);
}

// 代码生成阶段的错误处理
void codegenError(int line, int column, char* message) {
    ErrorMessage error = { CODEGEN_ERROR, message, line, column };
    reportError(error);
}

int main() {
    // 在编译器的不同阶段调用错误处理函数
    lexError(10, 5, "Invalid token");
    parseError(15, 8, "Syntax error");
    semanticError(20, 12, "Undeclared variable");
    codegenError(25, 15, "Failed to generate code");

    return 0;
}