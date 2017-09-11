/*
    Copyright (C) 2013  Aleix Pol Gonzalez <aleixpol@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <QQmlExtensionPlugin>
#include <qqml.h>
#include "hide-window-component.h"
#include "htmlhelper.h"

static QObject *htmlHelper_singleton_provider(QQmlEngine *, QJSEngine *)
{
    return new HtmlHelper();
}

class QmlPlugins : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

    public:
        virtual void initializeEngine(QQmlEngine */*engine*/, const char */*uri*/) {}
        virtual void registerTypes(const char *uri) {
            qmlRegisterType<HideWindowComponent>(uri, 0, 1, "HideWindowComponent");
            qmlRegisterSingletonType<HtmlHelper>(uri, 0, 1, "HtmlHelper", htmlHelper_singleton_provider);
        }

};

#include "qmlplugin.moc"
