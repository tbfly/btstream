/*
 * Copyright 2011 Gabriel Mendonça
 *
 * This file is part of BIVoD.
 * BIVoD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BIVoD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BIVoD.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * VideoTorrentManager.cpp
 *
 *  Created on: 06/09/2011
 *      Author: gabriel
 */

#include "VideoTorrentManager.h"

#include <boost/function.hpp>

#include "VideoTorrentPlugin.h"

namespace bivod {

VideoTorrentManager::VideoTorrentManager() {
	TorrentPluginFactory f(&create_video_plugin);
	m_session.add_extension(f);
}

} /* namespace bivod */
