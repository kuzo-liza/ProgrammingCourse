QT += core
QT -= gui
TEMPLATE = subdirs

TARGET = Proekt
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += \
    timetable_work.c \
    timetable.c \
    main.c \
    first_task.c \
    matrix.c \
    matrix_maker.c \
    numbers.c \
    stroki.c \
    is_it_a_triangle.c \
    a_gap_of_time.c \
    what_type_of_triangle_is_it.c


HEADERS += \
    timetable.h \
    first_task.h \
    matrix.h \
    stroki.h


