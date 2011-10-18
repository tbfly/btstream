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
 * VideoBufferTest.cpp
 *
 *  Created on: 29/09/2011
 *      Author: gabriel
 */

#include "VideoBuffer.h"

#include <gtest/gtest.h>

#include "Exception.h"

namespace bivod {

TEST(VideoBufferTest, CreateWithNegativeSize) {
	ASSERT_THROW(VideoBuffer videoBuffer(-1), Exception);
}

TEST(VideoBufferTest, AddPieceInvalidIndex) {
	int buffer_length = 1;
	VideoBuffer videoBuffer(buffer_length);

	int size = 1;
	boost::shared_array<char> data(new char[size]);

	ASSERT_NO_THROW(videoBuffer.add_piece(0, data, size));
	EXPECT_THROW(videoBuffer.add_piece(-1, data, size), Exception);
	EXPECT_THROW(videoBuffer.add_piece(buffer_length, data, size), Exception);
}

TEST(VideoBufferTest, AddPieceNoData) {
	VideoBuffer videoBuffer(1);

	int index = 0;
	int size = 1;
	boost::shared_array<char> data;

	EXPECT_THROW(videoBuffer.add_piece(index, data, size), Exception);
}

TEST(VideoBufferTest, AddPieceInvalidSize) {
	VideoBuffer videoBuffer(1);

	int index = 0;
	boost::shared_array<char> data(new char[1]);

	EXPECT_THROW(videoBuffer.add_piece(index, data, 0), Exception);
	EXPECT_THROW(videoBuffer.add_piece(index, data, -1), Exception);
}

TEST(VideoBufferTest, AddPieceOne) {
	VideoBuffer videoBuffer(1);

	int index = 0;
	int size = 1;
	boost::shared_array<char> data(new char[size]);
	data[0] = 7;

	videoBuffer.add_piece(index, data, size);

	boost::shared_ptr<Piece> piece = videoBuffer.get_next_piece();

	ASSERT_NE((Piece*) 0, piece.get());
	EXPECT_EQ(index, piece->index);
	ASSERT_NE((char*) 0, piece->data.get());
	EXPECT_EQ(data[0], piece->data[0]);
	EXPECT_EQ(size, piece->size);
}

TEST(VideoBufferTest, AddPieceTwo) {
	VideoBuffer videoBuffer(2);

	int index2 = 1;
	int size2 = 2;
	boost::shared_array<char> data2(new char[size2]);
	data2[0] = 3;
	data2[1] = 5;

	videoBuffer.add_piece(index2, data2, size2);

	int index1 = 0;
	int size1 = 1;
	boost::shared_array<char> data1(new char[size1]);
	data1[0] = 7;

	videoBuffer.add_piece(index1, data1, size1);

	boost::shared_ptr<Piece> piece1 = videoBuffer.get_next_piece();
	boost::shared_ptr<Piece> piece2 = videoBuffer.get_next_piece();

	ASSERT_NE((Piece*) 0, piece1.get());
	EXPECT_EQ(index1, piece1->index);
	ASSERT_NE((char*) 0, piece1->data.get());
	EXPECT_EQ(data1[0], piece1->data[0]);
	EXPECT_EQ(size1, piece1->size);

	ASSERT_NE((Piece*) 0, piece2.get());
	EXPECT_EQ(index2, piece2->index);
	ASSERT_NE((char*) 0, piece2->data.get());
	EXPECT_EQ(data2[0], piece2->data[0]);
	EXPECT_EQ(data2[1], piece2->data[1]);
	EXPECT_EQ(size2, piece2->size);
}

} /* namespace bivod */
