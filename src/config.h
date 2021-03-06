/*
obs-websocket
Copyright (C) 2016-2019	Stéphane Lepin <stephane.lepin@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#pragma once

#include <vector>

#include <QtCore/QString>
#include <QtCore/QSharedPointer>

#include <util/config-file.h>
#if __has_include(<obs-frontend-api.h>)
#include <obs-frontend-api.h>
#else
#include <obs-frontend-api/obs-frontend-api.h>
#endif


class Config : QObject
{
	Q_OBJECT
public:
	Config();
	~Config() override;

	void Load();
	void Save();
	void SetDefaults();
	config_t *GetConfigStore();

	bool DebugEnabled;
	bool AlertsEnabled;

	bool SettingsLoaded;

private:
	static void on_frontend_event(obs_frontend_event event, void *param);
};
