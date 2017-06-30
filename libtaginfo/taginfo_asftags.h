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


#ifndef TAGINFO_ASF_H
#define TAGINFO_ASF_H

#include "taginfo.h"

#include <asffile.h>


using namespace TagLib;
using namespace TagInfo;

/** @file */


namespace TagInfo {
    
    //! Info implementation for asf tags (wma, wmv and asf files).
    /*!
     * AsfInfo is an implementation of Info for wma, wmv and asf files.
    */        
    class AsfInfo : public Info {
        protected :
            //! Asf tag
            ASF::Tag * asf_tag;
        
        public :
            //! Constructor for AsfInfo
            //! \param filename is the path to the media file
            AsfInfo(const String &filename = "");
            virtual ~AsfInfo();
            
            virtual bool load(void);
            virtual bool save(void);
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
            
            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
    };
}

#endif
