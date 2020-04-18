/*
 * Copyright (C) 2013 ~ 2020 National University of Defense Technology(NUDT) & Tianjin Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    lixiang@kylinos.cn/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WEATHER_MANAGER_H
#define WEATHER_MANAGER_H

#include <QObject>

class QThread;
class CitySettingData;
class GeoIpWorker;
class WeatherWorker;

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);
    ~WeatherManager();

    void startTestNetwork();
    void postSystemInfoToServer();
    void startAutoLocationTask();

private:
    WeatherWorker *m_weatherWorker = nullptr;
    GeoIpWorker *m_geoipWorker = nullptr;

private slots:
    void setAutomaticCity(const QString& cityName);

signals:
    void requestAutoLocationData(const CitySettingData & info, bool success);
    void nofityNetworkStatus(const QString &status);
};

#endif // WEATHER_MANAGER_H