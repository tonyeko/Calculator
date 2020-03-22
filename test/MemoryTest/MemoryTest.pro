include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../Exception/DoubleNegationException.hpp \
        ../../Exception/EmptyMemoryException.hpp \
        ../../Exception/EmptyParenthesesException.hpp \
        ../../Exception/InvalidExpressionException.hpp \
        ../../Exception/NegativeSqrtException.hpp \
        ../../Exception/NullPointerException.hpp \
        ../../Exception/OperationFailedException.hpp \
        Exception/BaseException.hpp \
        Exception/DivideByZeroException.hpp \
        Exception/DoubleNegationException.hpp \
        Exception/EmptyMemoryException.hpp \
        Exception/EmptyParenthesesException.hpp \
        Exception/InvalidExpressionException.hpp \
        Exception/NegativeSqrtException.hpp \
        Exception/NullPointerException.hpp \
        Exception/OperationFailedException.hpp \
        Expression/Binary/AddExpression.hpp \
        Expression/Binary/BinaryExpression.hpp \
        Expression/Binary/DivisionExpression.hpp \
        Expression/Binary/MultiplicationExpression.hpp \
        Expression/Binary/SubtractExpression.hpp \
        Expression/Expression.hpp \
        Expression/Memory.hpp \
        Expression/TerminalExpression.hpp \
        Expression/Unary/NegativeExpression.hpp \
        Expression/Unary/PercentExpression.hpp \
        Expression/Unary/SqrtExpression.hpp \
        Expression/Unary/SquareExpression.hpp \
        Expression/Unary/Trigonometry/CosExpression.hpp \
        Expression/Unary/Trigonometry/SinExpression.hpp \
        Expression/Unary/Trigonometry/TanExpression.hpp \
        Expression/Unary/Trigonometry/TrigonometryExpression.hpp \
        Expression/Unary/UnaryExpression.hpp \
        tst_memorytest.h

SOURCES += \
        main.cpp
