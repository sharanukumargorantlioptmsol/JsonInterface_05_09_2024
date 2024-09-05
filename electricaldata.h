#ifndef ELECTRICALDATA_H
#define ELECTRICALDATA_H


struct ElectricalData {
    int voltageV1LowerLimit;
    int voltageV1UpperLimit;
    int voltageV2LowerLimit;
    int voltageV2UpperLimit;
    int voltageV3LowerLimit;
    int voltageV3UpperLimit;
    int averageCurrentMax;
    int maxTotalPowerLimitAtInfra;
    double powerFactorLessThanOrEqualTo;
    int frequencyLowerLimit;
    int frequencyUpperLimit;
};

#endif // ELECTRICALDATA_H
