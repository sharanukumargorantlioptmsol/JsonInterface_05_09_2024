#ifndef SYSTEMDATA_H
#define SYSTEMDATA_H
#include<QString>


struct SystemData {
    int SlotCount;
    QString MaxChargerCurrent;
    QString MaxChargerVoltage;
    int BatteryTemperatureSessionChargeCutOff;
    int BatteryTemperatureStartChargeCutOff;
    int DeltaSOCRestrictedForMultipleBatterySwapPick;
    int MaxSOCAvailableForPickSwap;
    int maxTotalPowerLimitAtInfra;
    QString DNSIP;
    int PORT;
    QString WIFI_SSID;
    QString WIFIACCESSPOINTNAME;
    QString WIFIACCESSPOINTPASSWORD;
    QString SYSTEMMODE;
    int HeartBeatPacketEverySeconds;
    int SystemHealthPacketEverySeconds;
    int BatteryHealthPacketEverySeconds;
    int SwapSessionPacketEverySeconds;
    //QString SwapSessionPacketEverySeconds;
    QString Reserved15;

};




#endif // SYSTEMDATA_H
