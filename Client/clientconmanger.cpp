﻿#include "clientconmanger.h"
#include "clientconver.h"
#include ""
#include <QThread>

ClientConManger::ClientConManger(const QString & key,int maxCache,QObject *parent)
    : ClientConManger(key,maxCache,parent)
{
    th = new QThread;
    th->start();
    this->moveToThread(th);
}

ClientConManger::~ClientConManger()
{
    th->quit();
    th->wait();
    delete th;
}

Conversation * ClientConManger::newCConversation()
{
    auto con = new ClientConver(this);
    connect(con,&ClientConver::connectionClosed,this,&ClientConManger::newCache);
    return con;
}
