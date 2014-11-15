#ifndef MARKETSTATS_H
#define MARKETSTATS_H

#include "clientmodel.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"

#include <QWidget>
#include <QObject>
#include <QtNetwork/QtNetwork>
#include <qcustomplot.h>


extern QString bitcoing;
extern QString dollarg;

namespace Ui {
class MarketStats;
}
class ClientModel;


class MarketStats : public QWidget
{
    Q_OBJECT

public:
    MarketStats(QWidget *parent = 0);
    ~MarketStats();
    
    void setModel(ClientModel *model);

private:
    void getRequest( const QString &url );

signals:
    void networkError( QNetworkReply::NetworkError err );

public slots:
    void parseNetworkResponse(QNetworkReply *finished );
    void randomChuckNorrisJoke();
    void bittrex();
    void poloniex();
    void bter();
    void mintpal();
    void egaldo();

private:
    QNetworkAccessManager m_nam;
    Ui::MarketStats *ui;
    ClientModel *model;

};

#endif // MarketStats.H
