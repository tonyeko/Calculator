include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        Exception/BaseException.hpp \
        Exception/DivideByZeroException.hpp \
        Exception/DoubleNegationException.hpp \
        Exception/EmptyMemoryException.hpp \
        Exception/EmptyParenthesesException.hpp \
        Exception/InvalidExpressionException.hpp \
        Exception/NegativeSqrtException.hpp \
        Exception/NullPointerException.hpp \
        Exception/OperationFailedException.hpp \
        tst_exceptiontest.h

SOURCES += \
        main.cpp
