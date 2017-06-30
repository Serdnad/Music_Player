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

#ifndef TAGINFO_APE_H
#define TAGINFO_APE_H


#include "taginfo.h"

using namespace TagLib;
using namespace TagInfo;

/** @file */


namespace TagInfo {
    
    // GENERAL APE

    //! Info implementation for APE tags
    /*!
     * ApeTagInfo is a common implementation of Info for media files with ape tags.
    */        
    class ApeTagInfo : public Info {
        protected:
            //! Constructor for ApeTagInfo
            //! \param filename is the path to the media file
            ApeTagInfo(const String &filename = "");
            //! Ape tag
            TagLib::APE::Tag * taglib_apetag;
            
        public:
            virtual ~ApeTagInfo();
            
            virtual bool load(void);
            virtual bool save(void);
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
            
            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
    };
    
    
    // FILE TYPES
    
    //! Info implementation for ape files
    /*!
     * ApeInfo Implementation of Info for ape files.
    */        
    class ApeInfo : public ApeTagInfo {
        public:
            //! Constructor for ApeInfo
            //! \param filename is the path to the media file
            ApeInfo(const String &filename = "");
            virtual ~ApeInfo();
    };
    
    
    //! Info implementation for mpc files
    /*!
     * MpcInfo is an implementation of Info for mpc files.
    */        
    class MpcInfo : public ApeTagInfo {
        public :
            //! Constructor for MpcInfo
            //! \param filename is the path to the media file
            MpcInfo(const String &filename = "");
            virtual ~MpcInfo();
    };
    
    
    //! Info implementation for wavpack files (wv)
    /*!
     * WavPackInfo is an implementation of Info for wv files.
    */        
    class WavPackInfo : public ApeTagInfo {
        public :
            //! Constructor for WavPackInfo
            //! \param filename is the path to the media file
            WavPackInfo(const String &filename = "");
            virtual ~WavPackInfo();
    };
}

#endif
