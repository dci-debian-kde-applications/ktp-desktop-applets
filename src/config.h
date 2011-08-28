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

#ifndef CONFIG_H
#define CONFIG_H

#include "ui_config.h"

#include <KDialog>
#include <TelepathyQt4/AccountManager>

namespace Ui {
    class Config;
}

class AccountsModel;
class AccountsFilterModel;
class GroupsModel;

class Config : public KDialog
{
    Q_OBJECT

public:
    Config(QWidget *parent = 0);
    ~Config();

    /** retrieve accountPtr by given unique identifier */
    Tp::AccountPtr accountFromUniqueId(const QString &id) const;

//     /** retrieve contactPtr from given id */
//     Tp::ContactPtr contactFromUniqueId(const Tp::AccountPtr &account, const QString &id) const;

signals:
    /** emitted when accountManager is ready so that the plasmoid can retrieve Account and Contact pointers */
    void loadConfig();

    void setNewContact(const Tp::ContactPtr &newContact, const Tp::AccountPtr &relatedAccount);

protected slots:
    void slotButtonClicked(int button);

private slots:
    void activateOkButton();
    void enableGroupsView(bool enable);                     /** enable/disable groups view */
    void enableOfflineContacts(bool enable);                /** enable/disable offline contacts */
    void onAccountManagerReady(Tp::PendingOperation* op);

private:
    void setupContactsList();                               /** prepare the contacts to be show in the list */

    AccountsModel *m_model;
    AccountsFilterModel *m_modelFilter;
    GroupsModel *m_groupsModel;
    Tp::AccountManagerPtr m_accountManager;

    Ui::Config ui;
};


#endif  // CONFIG_H
