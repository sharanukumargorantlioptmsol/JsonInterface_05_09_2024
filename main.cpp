#include <QCoreApplication>
#include <QDebug>
#include "jsonparser.h"
#include "electricaldata.h"
#include "systemdata.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    JsonParser parser;
    ElectricalData data = parser.getElectricalData("C:/Users/Admin/Desktop/Work@Optm_Files/jsonfileparsing.json");
    SystemData sysdata = parser.getSystemData("C:/Users/Admin/Desktop/Work@Optm_Files/jsonfileparsing.json");

    qDebug()<<" Example: Printing the parsed data Electrical: "<<Qt::endl;
    qDebug() << "Voltage V1 Lower Limit:" << data.voltageV1LowerLimit;
    qDebug() << "Voltage V1 Upper Limit:" << data.voltageV1UpperLimit;
    qDebug() << "Voltage_V2_Lower_Limit:" << data.voltageV2LowerLimit;
    qDebug() << "Voltage_V2_Upper_Limit:" << data.voltageV2UpperLimit;
    qDebug() << "Voltage_V3_Lower_Limit:" << data.voltageV3LowerLimit;
    qDebug() << "Voltage_V3_Upper_Limit:" << data.voltageV3UpperLimit;
    qDebug() << "Average_Current_Max:" << data.averageCurrentMax;
    qDebug() << "Max_Total_Power_Limit_at_Infrat:" << data.maxTotalPowerLimitAtInfra;
    qDebug() << "Power_Factor_Less_Than_Or_Equal_To:" << data.powerFactorLessThanOrEqualTo;
    qDebug() << "Frequency_Lower_Limit:" << data.frequencyLowerLimit;
    qDebug() << "Frequency_Upper_Limit:" << data.frequencyUpperLimit;

    qDebug()<<" Example: Printing the parsed data System: "<<Qt::endl;
    qDebug() << "SlotCount:" << sysdata.SlotCount;
    qDebug() << "MaxChargerCurrent:" << sysdata.MaxChargerCurrent;
    qDebug() << "MaxChargerVoltage:" << sysdata.MaxChargerVoltage;
    qDebug() << "BatteryTemperatureSessionChargeCutOff:" << sysdata.BatteryTemperatureSessionChargeCutOff;
    qDebug() << "BatteryTemperatureStartChargeCutOff:" << sysdata.BatteryTemperatureStartChargeCutOff;
    qDebug() << "DeltaSOCRestrictedForMultipleBatterySwapPick:" << sysdata.DeltaSOCRestrictedForMultipleBatterySwapPick;
    qDebug() << "MaxSOCAvailableForPickSwap:" << sysdata.MaxSOCAvailableForPickSwap;
    qDebug() << "maxTotalPowerLimitAtInfra:" << sysdata.maxTotalPowerLimitAtInfra;
    qDebug() << "DNSIP:" << sysdata.DNSIP;
    qDebug() << "PORT:" << sysdata.PORT;
    qDebug() << "WIFI_SSID:" << sysdata.WIFI_SSID;
    qDebug() << "WIFIACCESSPOINTNAME:" << sysdata.WIFIACCESSPOINTNAME;
    qDebug() << "WIFIACCESSPOINTPASSWORD:" << sysdata.WIFIACCESSPOINTPASSWORD;
    qDebug() << "HeartBeatPacketEverySeconds:" << sysdata.HeartBeatPacketEverySeconds;
    qDebug() << "SystemHealthPacketEverySeconds:" << sysdata.SystemHealthPacketEverySeconds;
    qDebug() << "BatteryHealthPacketEverySeconds:" << sysdata.BatteryHealthPacketEverySeconds;
    qDebug() << "SwapSessionPacketEverySeconds:" << sysdata.SwapSessionPacketEverySeconds;
   // qDebug() << "AlertEventPacketImmediate:" << sysdata.AlertEventPacketImmediate;
    qDebug() << "Reserved15:" << sysdata.Reserved15;

    //write json data to file
    // Create and populate SystemData struct
    //SystemData data;

    sysdata.SlotCount = 100;
    sysdata.MaxChargerCurrent = "[10-19]";
    sysdata.MaxChargerVoltage = "[10-19]";
    sysdata.BatteryTemperatureSessionChargeCutOff = 45;
    sysdata.BatteryTemperatureStartChargeCutOff = 50;
    sysdata.DeltaSOCRestrictedForMultipleBatterySwapPick = 5;
    sysdata.MaxSOCAvailableForPickSwap = 80;
    sysdata.DNSIP = "192.168.1.1";
    sysdata.PORT = 8080;
    sysdata.WIFI_SSID = "MyWifi";
    sysdata.WIFIACCESSPOINTNAME = "MyAccessPoint";
    sysdata.WIFIACCESSPOINTPASSWORD = "password123";
    sysdata.SYSTEMMODE = "Normal";
    sysdata.HeartBeatPacketEverySeconds = 30;
    sysdata.SystemHealthPacketEverySeconds = 60;
    sysdata.BatteryHealthPacketEverySeconds = 120;
    sysdata.SwapSessionPacketEverySeconds = 180;
   // sysdata.SwapSessionPacketEverySeconds = "Yes";
    sysdata.Reserved15 = "Reserved";

    QString filePath = "C:/Users/Admin/Desktop/Work@Optm_Files/jsonfileparsing_output.json";  // Ensure this path is valid and writable
    JsonParser::writeSystemDataToFile(sysdata, filePath);

    return a.exec();
}

