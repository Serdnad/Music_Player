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


#ifndef TAGINFO_XIPH_H
#define TAGINFO_XIPH_H


#include "taginfo.h"

#include <flacfile.h>
#include <oggfile.h>
#include <vorbisfile.h>


using namespace TagLib;
using namespace TagInfo;


/** @file */


namespace TagInfo {
    
    // GENERAL XIPH
    //! Info implementation for vorbis tags.
    /*!
     * XiphInfo is a common implementation of Info for media files with xiph comment tags.
    */        
    class XiphInfo : public Info {
        protected :
            //! Constructor for XiphInfo
            //! \param filename is the path to the media file
            XiphInfo(const String &filename = "");
            //! Xiph comment
            Ogg::XiphComment * xiphcomment;
            
        public :
            virtual ~XiphInfo();
            
            virtual bool load(void);
            virtual bool save(void);
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
            
            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
    };
    
    // FILE TYPES
    
    //! Info implementation for flac files.
    /*!
     * FlacInfo is an implementation of Info for flac files.
    */    
    class FlacInfo : public XiphInfo {
        protected :
            //! Flac tag
            TagLib::FLAC::File * flac_file;
        
        public :
            //! Constructor for FlacInfo
            //! \param filename is the path to the media file
            FlacInfo(const String &filename = "");
            virtual ~FlacInfo();
            
            virtual bool load(void);
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
    };
    
    
    //! Info implementation for ogg files.
    /*!
     * OggInfo is an implementation of Info for ogg and oga files.
    */    
    class OggInfo : public XiphInfo {
        public :
            //! Constructor for OggInfo
            //! \param filename is the path to the media file
            OggInfo(const String &filename = "");
            virtual ~OggInfo();
    };
    
#ifdef TAGLIB_ONE_NINE
    //! Info implementation for opus files.
    /*!
     * OpusInfo is an implementation of Info for opus files.
    */    
    class OpusInfo : public XiphInfo {
        public :
            //! Constructor for OpusInfo
            //! \param filename is the path to the media file
            OpusInfo(const String &filename = "");
            virtual ~OpusInfo();
    };
#endif /* TAGLIB_ONE_NINE */
    
    //! Info implementation for speex files (spx).
    /*!
     * SpeexInfo is an implementation of Info for speex files.
    */    
    class SpeexInfo : public XiphInfo {
        public :
            //! Constructor for SpeexInfo
            //! \param filename is the path to the media file
            SpeexInfo(const String &filename = "");
            virtual ~SpeexInfo();
    };
}

#endif
