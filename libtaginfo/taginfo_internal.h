/*
 * Copyright (C) 2008-2013 J.Rios <anonbeat@gmail.com>
 * Copyright (C) 2013 Jörn Magens
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This Program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file LICENSE.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth 
 * Floor, Boston, MA  02110-1301  USA
 * https://www.gnu.org/licenses/lgpl-2.1.txt
 *
 * Author:
 * 	Jörn Magens <shuerhaaken@googlemail.com>
 * 
 */

#ifndef TAGINFO_INTERNAL_H
#define TAGINFO_INTERNAL_H


#include "taginfo.h"

#include <tag.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define BUFFERSIZE 512
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


using namespace TagLib;

/** @file */


namespace TagInfo {
    
    //! \enum ChangedFlags Internal change flags for implementations
    enum ChangedFlags {
        //! Nothing changed
        CHANGED_DATA_NONE          = 0,
        //! Artist tag changed
        CHANGED_ARTIST_TAG         = (1 << 0),
        //! Album tag changed
        CHANGED_ALBUM_TAG          = (1 << 1),
        //! Title tag changed
        CHANGED_TITLE_TAG          = (1 << 2),
        //! Genre tag changed
        CHANGED_GENRE_TAG          = (1 << 3),
        //! Comment tag changed
        CHANGED_COMMENT_TAG        = (1 << 4),
        //! Track number tag changed
        CHANGED_TRACK_NUMBER        = (1 << 5),
        //! Track count tag changed
        CHANGED_TRACK_COUNT        = (1 << 6),
        //! Year tag changed
        CHANGED_YEAR_TAG           = (1 << 7),
        //! Album artist tag changed
        CHANGED_DATA_ALBUMARTIST   = (1 << 8),
        //! Volume number tag changed
        CHANGED_DATA_VOL_NUM       = (1 << 9),
        //! Volume count tag changed
        CHANGED_DATA_VOL_CNT       = (1 << 10),
        //! Images tag changed
        CHANGED_DATA_IMAGES        = (1 << 11),
        //! Lyrics tag changed
        CHANGED_DATA_LYRICS        = (1 << 12),
        //! Rating tag changed
        CHANGED_DATA_RATING        = (1 << 13),
        //! Play count changed
        CHANGED_DATA_PLAYCOUNT     = (1 << 14),
        //! Composer tag changed
        CHANGED_COMPOSER_TAG       = (1 << 15),
        //! Track labels changed
        CHANGED_TRACK_LABELS       = (1 << 16),
        //! Artist labels changed
        CHANGED_ARTIST_LABELS      = (1 << 17),
        //! Album labels changed
        CHANGED_ALBUM_LABELS       = (1 << 18),
        //! Is compilation tag changed
        CHANGED_IS_COMPILATION_TAG = (1 << 19),
        //! Homepage tag changed
        CHANGED_HOMEPAGE_TAG       = (1 << 20),
        //! Encoder tag changed
        CHANGED_ENCODER_TAG        = (1 << 21),
        //! Copyright tag changed
        CHANGED_COPYRIGHT_TAG      = (1 << 22),
        //! License tag changed
        CHANGED_LICENSE_TAG        = (1 << 23),
        //! Original artist tag changed
        CHANGED_ORIGINALARTIST_TAG = (1 << 24),
        //! Beats per minute tag changed
        CHANGED_BPM_TAG            = (1 << 25)
    };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
inline StringList split(const String str, const String &separator) {
    return StringList::split(str, separator);
}


inline int popularity_to_rating(const int popularity) {
    if(popularity <= 0)
        return 0;
    if(popularity < 64)
        return 1;
    if(popularity < 128)
        return 2;
    if(popularity < 192)
        return 3;
    if(popularity < 255)
        return 4;
    return 5;
}

inline int rating_to_popularity(const int rating) {
    int Ratings[] = { 0, 0, 1, 64, 128, 192, 255 };
    return Ratings[rating + 1];
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif
