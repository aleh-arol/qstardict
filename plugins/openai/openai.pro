#############################################################################
# openai.pro - QStarDict, a dictionary application for learning languages  #
# Copyright (C) 2026 Aleh Arol                                              #
#############################################################################

TARGET = openai
include(../plugin.pri)

HEADERS += \
    openai.h \
    settingsdialog.h
SOURCES += \
    openai.cpp \
    settingsdialog.cpp
FORMS += \
    settingsdialog.ui

OTHER_FILES += \
    openai.json
