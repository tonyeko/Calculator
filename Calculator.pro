QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:RC_ICONS += Calculator.ico

SOURCES += \
    Data.cpp \
    main.cpp \
    calculator.cpp

HEADERS += \
    Data.hpp \
    Exception/BaseException.hpp \
    Exception/DigitLimitException.hpp \
    Exception/DivideByZeroException.hpp \
    Exception/EmptyMemoryException.hpp \
    Exception/InvalidExpressionException.hpp \
    Exception/NegativeSqrtException.hpp \
    Exception/OperationFailedException.hpp \
    Expression/AddExpression.hpp \
    Expression/BinaryExpression.hpp \
    Expression/CosExpression.hpp \
    Expression/DivisionExpression.hpp \
    Expression/Expression.hpp \
    Expression/Memory.hpp \
    Expression/MultiplicationExpression.hpp \
    Expression/NegativeExpression.hpp \
    Expression/PercentExpression.hpp \
    Expression/SinExpression.hpp \
    Expression/SqrtExpression.hpp \
    Expression/SquareExpression.hpp \
    Expression/SubtractExpression.hpp \
    Expression/TanExpression.hpp \
    Expression/TerminalExpression.hpp \
    Expression/TrigonometryExpression.hpp \
    Expression/UnaryExpression.hpp \
    calculator.hpp

FORMS += \
    calculator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Calculator.ico



