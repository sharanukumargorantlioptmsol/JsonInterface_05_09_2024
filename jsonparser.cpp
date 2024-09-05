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

    sysdata.AlertEventPacketImmediate=system["Alert_Event_Packet_Immediate"].toString();

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
