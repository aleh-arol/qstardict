/*****************************************************************************
 * settingsdialog.h - QStarDict, a dictionary application for learning       *
 *                    languages                                              *
 * Copyright (C) 2026 Aleh Arol                                              *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *****************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "ui_settingsdialog.h"

#include "openai.h"

class SettingsDialog: public QDialog, private Ui::SettingsDialog
{
    Q_OBJECT

    public:
        SettingsDialog(OpenAI *plugin, QWidget *parent = nullptr);

        void accept();

    private:
        OpenAI *m_plugin;
};

#endif // SETTINGSDIALOG_H
