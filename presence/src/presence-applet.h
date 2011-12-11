/***************************************************************************
 *   Copyright (C) 2011 by Francesco Nwokeka <francesco.nwokeka@gmail.com> *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef TELEPATHY_KDE_PRESENCE_APPLET_H
#define TELEPATHY_KDE_PRESENCE_APPLET_H

#include <Plasma/Applet>
#include <Plasma/DeclarativeWidget>

class GlobalPresenceWrapper;
class QAction;

class TelepathyPresenceApplet: public Plasma::Applet
{
    Q_OBJECT

    Q_PROPERTY(int height READ appletHeight)
    Q_PROPERTY(int width READ appletWidth)

public:
    TelepathyPresenceApplet(QObject *parent, const QVariantList &args);
    ~TelepathyPresenceApplet();

    int appletHeight() const;
    int appletWidth() const;

    QList<QAction*>contextualActions();
    void init();
    void paintInterface(QPainter *p, const QStyleOptionGraphicsItem *option, const QRect& contentsRect);

    /// TODO
//     /** overide of config signal */
//     void showConfigurationInterface();

private Q_SLOTS:
    void startAccountManager() const;
    void startContactList() const;

private:
    /// TODO
    void saveConfig();

    Plasma::DeclarativeWidget *m_declarative;
    QObject *m_qmlObject;
    GlobalPresenceWrapper *m_globalPresenceWrapper;
};

#endif  // TELEPATHY_KDE_PRESENCE_APPLET_H
