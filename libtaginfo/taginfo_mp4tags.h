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


#ifndef TAGINFO_MP4_H
#define TAGINFO_MP4_H

#include "taginfo.h"



using namespace TagLib;
using namespace TagInfo;

/** @file */


namespace TagInfo {
    
    //! Info implementation for mp4 tags.
    /*!
     * Mp4Info is an implementation of Info for mp4, m4a, m4b, m4p and aac files.
    */    
    class Mp4Info : public Info {
        protected :
            //! Mp4 tag
            TagLib::MP4::Tag * mp4_tag;
            
        public :
            //! Constructor for Mp4Info
            //! \param filename is the path to the media file
            Mp4Info(const String &filename = "");
            virtual ~Mp4Info();
            
            virtual bool load(void);
            virtual bool save(void);
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
            
            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
    };
}

#endif
