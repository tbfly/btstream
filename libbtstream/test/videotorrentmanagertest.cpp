/*
 * Copyright (C) 2011-2013 Gabriel Mendonça
 *
 * This file is part of BTStream.
 * BTStream is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BTStream is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with BTStream.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * VideoTorrentManagerTest.cpp
 *
 *  Created on: 29/09/2011
 *      Author: gabriel
 */

#include <gtest/gtest.h>

#include "videotorrentmanager.h"
#include "exception.h"

#include "constants.h"

namespace btstream {

TEST(VideoTorrentManagerTest, AddTorrentInvalid) {
	VideoTorrentManager video_torrent_manager;

	ASSERT_THROW(video_torrent_manager.add_torrent("", 0, "."), Exception);
}

TEST(VideoTorrentManagerTest, AddTorrentValid) {
	VideoTorrentManager video_torrent_manager;

	boost::shared_ptr<VideoBuffer> video_buffer;
	ASSERT_NO_THROW(video_buffer =
			video_torrent_manager.add_torrent(TEST_TORRENT1, 0, "."));

	EXPECT_TRUE(video_buffer);
}

TEST(VideoTorrentManagerTest, AddTwoTorrents) {
	VideoTorrentManager video_torrent_manager;
	boost::shared_ptr<VideoBuffer> video_buffer;

	// Add first torrent.
	ASSERT_NO_THROW(video_buffer =
			video_torrent_manager.add_torrent(TEST_TORRENT1, 0, "."));

	EXPECT_TRUE(video_buffer);

	// Add second torrent.
	ASSERT_NO_THROW(video_buffer =
			video_torrent_manager.add_torrent(TEST_TORRENT2, 0, "."));

	EXPECT_TRUE(video_buffer);
}

} /* namespace btstream */
