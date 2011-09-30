/*
 * Copyright 2011 Gabriel Mendonça
 *
 * This file is part of BiVoD.
 * BiVoD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BiVoD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BiVoD.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * VideoPeerPlugin.cpp
 *
 *  Created on: 06/09/2011
 *      Author: gabriel
 */

#include "VideoPeerPlugin.h"

namespace bivod {

VideoPeerPlugin::VideoPeerPlugin(peer_connection* pc) :
	m_peer_connection(pc) {}

bool VideoPeerPlugin::on_unchoke() {
	return false;
}

} /* namespace bivod */
