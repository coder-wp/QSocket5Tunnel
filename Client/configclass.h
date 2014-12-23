﻿#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H
#include <QString>
#include "../common/datastruct.h"

class ConfigClass
{
public:
    ~ConfigClass();

    static ConfigClass & getClass();
    void saveSetting();

    QString serverUrl;
    QString key;
    int serverPort;
    int localPort;
    int MaxThread;
    int MaxCache;

private:
    void loadSetting();

    ConfigClass();
};

#endif // CONFIGCLASS_H
