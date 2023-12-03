#include <stdio.h>
#include <stdlib.h>

// �������͵�ö��
typedef enum {
    LEXICAL_ERROR,
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    CODEGEN_ERROR
} ErrorType;

// ������Ϣ�ṹ
typedef struct {
    ErrorType type;
    char* message;
    int line;
    int column;
} ErrorMessage;

// �������ĺ���
void reportError(ErrorMessage error) {
    const char* errorTypeStrings[] = {
        "Lexical Error",
        "Syntax Error",
        "Semantic Error",
        "Code Generation Error"
    };

    fprintf(stderr, "%s at line %d, column %d: %s\n", errorTypeStrings[error.type], error.line, error.column, error.message);

    // ��ʵ��Ӧ���У�����ܻ�ѡ����������ֹ������̻��ȡ�����ʵ��Ĵ�ʩ
    exit(EXIT_FAILURE);
}

// �ʷ������׶εĴ�����
void lexError(int line, int column, char* message) {
    ErrorMessage error = { LEXICAL_ERROR, message, line, column };
    reportError(error);
}

// �﷨�����׶εĴ�����
void parseError(int line, int column, char* message) {
    ErrorMessage error = { SYNTAX_ERROR, message, line, column };
    reportError(error);
}

// ��������׶εĴ�����
void semanticError(int line, int column, char* message) {
    ErrorMessage error = { SEMANTIC_ERROR, message, line, column };
    reportError(error);
}

// �������ɽ׶εĴ�����
void codegenError(int line, int column, char* message) {
    ErrorMessage error = { CODEGEN_ERROR, message, line, column };
    reportError(error);
}

int main() {
    // �ڱ������Ĳ�ͬ�׶ε��ô�������
    lexError(10, 5, "Invalid token");
    parseError(15, 8, "Syntax error");
    semanticError(20, 12, "Undeclared variable");
    codegenError(25, 15, "Failed to generate code");

    return 0;
}