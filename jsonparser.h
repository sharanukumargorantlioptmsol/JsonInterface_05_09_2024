#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonParseError>
#include <QString>
#include "electricaldata.h"
#include "systemdata.h"

class JsonParser {
public:
    ElectricalData getElectricalData(const QString &filePath);
    SystemData getSystemData(const QString &filePath);

private:
    QJsonObject loadJson(const QString &filePath);
    QJsonObject loadJsonSystemData(const QString &filePath);
};

#endif // JSONPARSER_H
