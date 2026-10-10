/*****************************************************************************
 * openai.h - QStarDict, a dictionary application for learning languages    *
 * Copyright (C) 2026 Aleh Arol                                             *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *****************************************************************************/

#ifndef OPENAI_H
#define OPENAI_H

#include "../dictplugin.h"

#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

class OpenAI: public QObject, public QStarDict::DictPlugin
{
    Q_OBJECT
    Q_INTERFACES(QStarDict::DictPlugin)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qstardict.DictPlugin/1.0" FILE "openai.json")
#endif

    public:
        struct Settings
        {
            QString apiUrl;
            QString targetLanguage;
            QString instructions;
            bool phrasesOnly;
        };

        OpenAI(QObject *parent = nullptr);

        QString name() const
        { return "openai"; }
        QString version() const
        { return "0.1"; }
        QString description() const
        { return tr("Translates phrases through an OpenAI-compatible API."); }
        QStringList authors() const
        { return QStringList("Aleh Arol <aleh.arol@gmail.com>"); }
        Features features() const
        { return Features(SettingsDialog); }

        QStringList availableDicts() const;
        QStringList loadedDicts() const;
        void setLoadedDicts(const QStringList &dicts);
        DictInfo dictInfo(const QString &dict);

        bool isTranslatable(const QString &dict, const QString &word);
        Translation translate(const QString &dict, const QString &word);

        int execSettingsDialog(QWidget *parent);
        bool enableAvailableDictsAfterSettings() const
        { return true; }
        QStringList configuredDefaultDicts() const;

        Settings settings() const;
        bool saveSettings(const Settings &settings, QString *error);

    private:
        enum class RequestStatus
        {
            Success,
            Unavailable,
            Error
        };

        struct RequestResult
        {
            RequestStatus status;
            QByteArray body;
            QString error;
        };

        static QString dictionaryName();
        static Settings defaultSettings();
        static bool isPhrase(const QString &text);

        void loadSettings();
        QUrl endpoint(const QString &path) const;
        RequestResult send(const QNetworkRequest &request, const QByteArray *body = nullptr) const;
        RequestStatus requestModel(QString *model, QString *error) const;
        RequestStatus requestTranslation(const QString &model, const QString &text,
                                         QString *translation, QString *error) const;
        QJsonObject requestBody(const QString &model, const QString &text) const;
        bool parseTranslation(const QByteArray &response, QString *translation, QString *error) const;
        Translation errorTranslation(const QString &word, const QString &error) const;

        Settings m_settings;
        QString m_model;
        bool m_configured;
        bool m_loaded;
};

#endif // OPENAI_H
