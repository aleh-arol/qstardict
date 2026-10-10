/*****************************************************************************
 * settingsdialog.cpp - QStarDict, a dictionary application for learning     *
 *                      languages                                            *
 * Copyright (C) 2026 Aleh Arol                                              *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *****************************************************************************/

#include "settingsdialog.h"

#include <QMessageBox>

SettingsDialog::SettingsDialog(OpenAI *plugin, QWidget *parent)
    : QDialog(parent),
      m_plugin(plugin)
{
    setupUi(this);

    OpenAI::Settings settings = m_plugin->settings();
    apiUrlEdit->setText(settings.apiUrl);
    targetLanguageEdit->setText(settings.targetLanguage);
    phrasesOnlyBox->setChecked(settings.phrasesOnly);
    instructionsEdit->setPlainText(settings.instructions);
}

void SettingsDialog::accept()
{
    OpenAI::Settings settings;
    settings.apiUrl = apiUrlEdit->text().trimmed();
    settings.targetLanguage = targetLanguageEdit->text().trimmed();
    settings.phrasesOnly = phrasesOnlyBox->isChecked();
    settings.instructions = instructionsEdit->toPlainText().trimmed();

    QString error;
    if (! m_plugin->saveSettings(settings, &error))
    {
        QMessageBox::warning(this, tr("OpenAI plugin settings"),
                             tr("The API health check failed:\n%1").arg(error));
        return;
    }
    QDialog::accept();
}
