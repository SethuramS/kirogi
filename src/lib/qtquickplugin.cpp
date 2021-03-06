/*
 * Copyright 2019 Eike Hein <hein@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qtquickplugin.h"

#include "abstractvehicle.h"
#include "parametermodel.h"
#include "vehiclesupportplugin.h"
#include "vehiclesupportpluginmodel.h"

#include "positionsource/positionsource.h"

#include <QQmlEngine>

namespace Kirogi
{
void QtQuickPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("org.kde.kirogi"));

    qmlRegisterUncreatableType<AbstractVehicle>(uri, 0, 1, "AbstractVehicle", "AbstractVehicle cannot be created from QML.");

    qmlRegisterType<VehicleSupportPluginModel>(uri, 0, 1, "VehicleSupportPluginModel");
    qRegisterMetaType<ParameterModel *>("ParameterModel*");

    qmlRegisterSingletonType<PositionSource>(uri, 0, 1, "PositionSource", PositionSource::qmlSingletonRegister);
}
}
