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
    // to read from json and print
    ElectricalData getElectricalData(const QString &filePath);
    SystemData getSystemData(const QString &filePath);
    // to write json data to a file
    static QJsonObject systemDataToJsonObject(const SystemData &data);
    static SystemData jsonObjectToSystemData(const QJsonObject &jsonObject);
    static void writeSystemDataToFile(const SystemData &data, const QString &filePath);


private:
    QJsonObject loadJson(const QString &filePath);
    QJsonObject loadJsonSystemData(const QString &filePath);
};

#endif // JSONPARSER_H
