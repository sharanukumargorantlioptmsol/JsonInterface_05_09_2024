#include "jsonparser.h"

ElectricalData JsonParser::getElectricalData(const QString &filePath) {
    QJsonObject jsonObject = loadJson(filePath);

    ElectricalData data;
    QJsonObject electrical = jsonObject["Electrical"].toObject();

    data.voltageV1LowerLimit = electrical["Voltage_V1_Lower_Limit"].toInt();
    data.voltageV1UpperLimit = electrical["Voltage_V1_Upper_Limit"].toInt();
    data.voltageV2LowerLimit = electrical["Voltage_V2_Lower_Limit"].toInt();
    data.voltageV2UpperLimit = electrical["Voltage_V2_Upper_Limit"].toInt();
    data.voltageV3LowerLimit = electrical["Voltage_V3_Lower_Limit"].toInt();
    data.voltageV3UpperLimit = electrical["Voltage_V3_Upper_Limit"].toInt();
    data.averageCurrentMax = electrical["Average_Current_Max"].toInt();
    data.maxTotalPowerLimitAtInfra = electrical["Max_Total_Power_Limit_at_Infra"].toInt();
    data.powerFactorLessThanOrEqualTo = electrical["Power_Factor_Less_Than_Or_Equal_To"].toDouble();
    data.frequencyLowerLimit = electrical["Frequency_Lower_Limit"].toInt();
    data.frequencyUpperLimit = electrical["Frequency_Upper_Limit"].toInt();
    return data;
}

SystemData JsonParser::getSystemData(const QString &filePath)
{
    QJsonObject jsonObject =loadJsonSystemData(filePath);
    SystemData sysdata;
    QJsonObject system = jsonObject["System"].toObject();

    sysdata.SlotCount=system["Slot_Count"].toInt();
    sysdata.MaxChargerCurrent=system["Max_Charger_Current"].toString();
    sysdata.MaxChargerVoltage=system["Max_Charger_Voltage"].toString();
    sysdata.BatteryTemperatureSessionChargeCutOff=system["Battery_Temperature_Session_Charge_Cut_Off"].toInt();
    sysdata.BatteryTemperatureStartChargeCutOff=system["Battery_Temperature_Start_Charge_Cut_Off"].toInt();

    sysdata.DeltaSOCRestrictedForMultipleBatterySwapPick=system["Delta_SOC%_Restricted_For_Multiple_Battery_Swap/Pick"].toInt();
    sysdata.MaxSOCAvailableForPickSwap=system["Max_SOC%_Available_For_Pick/Swap"].toInt();
    sysdata.DNSIP=system["DNS/IP"].toString();
    sysdata.PORT=system["PORT"].toInt();
    sysdata.WIFI_SSID=system["WIFI_SSID"].toString();
    sysdata.WIFIACCESSPOINTNAME=system["WIFI_ACCESS-POINT_NAME"].toString();
    sysdata.WIFIACCESSPOINTPASSWORD=system["WIFI_ACCESS-POINT_PASSWORD"].toString();

    sysdata.SYSTEMMODE=system["SYSTEM_MODE"].toString();

    sysdata.HeartBeatPacketEverySeconds=system["HeartBeatPacketEverySeconds"].toInt();

    sysdata.SystemHealthPacketEverySeconds=system["SystemHealthPacketEverySeconds"].toInt();

    sysdata.BatteryHealthPacketEverySeconds=system["Battery-Health_Packet_Every_Seconds"].toInt();

    sysdata.SwapSessionPacketEverySeconds=system["Swap_Session-Packet_Every_Seconds"].toInt();

    //sysdata.AlertEventPacketImmediate=system["Alert_Event_Packet_Immediate"].toString();

    sysdata.Reserved15=system["Reserved_1-5"].toString();

    return sysdata;



}

QJsonObject JsonParser::loadJson(const QString &filePath) {     //electricaldata
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open file.");
        return {};
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning("JSON parse error: %s", qPrintable(parseError.errorString()));
        return {};
    }

    return document.object();
}

QJsonObject JsonParser::loadJsonSystemData(const QString &filePath) {         //Systemdata
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open file.");
        return {};
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning("JSON parse error: %s", qPrintable(parseError.errorString()));
        return {};
    }

    return document.object();
}
QJsonObject JsonParser::systemDataToJsonObject(const SystemData &data)
{
        QJsonObject jsonObject;
        jsonObject["Slot_Count"] = data.SlotCount;
        jsonObject["Max_Charger_Current"] = data.MaxChargerCurrent;
        jsonObject["Max_Charger_Voltage"] = data.MaxChargerVoltage;
        jsonObject["Battery_Temperature_Session_Charge_Cut_Off"] = data.BatteryTemperatureSessionChargeCutOff;
        jsonObject["Battery_Temperature_Start_Charge_Cut_Off"] = data.BatteryTemperatureStartChargeCutOff;
        jsonObject["Delta_SOC%_Restricted_For_Multiple_Battery_Swap/Pick"] = data.DeltaSOCRestrictedForMultipleBatterySwapPick;
        jsonObject["Max_SOC%_Available_For_Pick/Swap"] = data.MaxSOCAvailableForPickSwap;
        jsonObject["DNS/IP"] = data.DNSIP;
        jsonObject["PORT"] = data.PORT;
        jsonObject["WIFI_SSID"] = data.WIFI_SSID;
        jsonObject["WIFI_ACCESS-POINT_NAME"] = data.WIFIACCESSPOINTNAME;
        jsonObject["WIFI_ACCESS-POINT_PASSWORD"] = data.WIFIACCESSPOINTPASSWORD;
        jsonObject["SYSTEM_MODE"] = data.SYSTEMMODE;
        jsonObject["Heart-Beat_Packet_Every_Seconds"] = data.HeartBeatPacketEverySeconds;
        jsonObject["System-Health_Packet_Every_Seconds"] = data.SystemHealthPacketEverySeconds;
        jsonObject["Battery-Health_Packet_Every_Seconds"] = data.BatteryHealthPacketEverySeconds;
        jsonObject["Swap_Session-Packet_Every_Seconds"] = data.SwapSessionPacketEverySeconds;
      //  jsonObject["Alert_Event_Packet_Immediate"] = data.AlertEventPacketImmediate;
        jsonObject["Reserved_1-5"] = data.Reserved15;
        return jsonObject;
}
SystemData JsonParser::jsonObjectToSystemData(const QJsonObject &jsonObject)
{
    SystemData data;
    data.SlotCount = jsonObject["Slot_Count"].toInt();
    data.MaxChargerCurrent = jsonObject["Max_Charger_Current"].toString();
    data.MaxChargerVoltage = jsonObject["Max_Charger_Voltage"].toString();
    data.BatteryTemperatureSessionChargeCutOff = jsonObject["Battery_Temperature_Session_Charge_Cut_Off"].toInt();
    data.BatteryTemperatureStartChargeCutOff = jsonObject["Battery_Temperature_Start_Charge_Cut_Off"].toInt();
    data.DeltaSOCRestrictedForMultipleBatterySwapPick = jsonObject["Delta_SOC%_Restricted_For_Multiple_Battery_Swap/Pick"].toInt();
    data.MaxSOCAvailableForPickSwap = jsonObject["Max_SOC%_Available_For_Pick/Swap"].toInt();
    data.DNSIP = jsonObject["DNS/IP"].toString();
    data.PORT = jsonObject["PORT"].toInt();
    data.WIFI_SSID = jsonObject["WIFI_SSID"].toString();
    data.WIFIACCESSPOINTNAME = jsonObject["WIFI_ACCESS-POINT_NAME"].toString();
    data.WIFIACCESSPOINTPASSWORD = jsonObject["WIFI_ACCESS-POINT_PASSWORD"].toString();
    data.SYSTEMMODE = jsonObject["SYSTEM_MODE"].toString();
    data.HeartBeatPacketEverySeconds = jsonObject["Heart-Beat_Packet_Every_Seconds"].toInt();
    data.SystemHealthPacketEverySeconds = jsonObject["System-Health_Packet_Every_Seconds"].toInt();
    data.BatteryHealthPacketEverySeconds = jsonObject["Battery-Health_Packet_Every_Seconds"].toInt();
    data.SwapSessionPacketEverySeconds = jsonObject["Swap_Session-Packet_Every_Seconds"].toInt();
   // data.AlertEventPacketImmediate = jsonObject["Alert_Event_Packet_Immediate"].toString();
    data.Reserved15 = jsonObject["Reserved_1-5"].toString();
    return data;

}

void JsonParser::writeSystemDataToFile(const SystemData &data, const QString &filePath)
{
    qDebug()<<"Hi";
    QJsonObject jsonObject = systemDataToJsonObject(data);
    QJsonDocument jsonDoc(jsonObject);
    QFile jsonFile(filePath);

    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open the file.");
        return;
    }

    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
}



