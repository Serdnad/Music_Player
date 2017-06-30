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


#ifndef TAGINFO_ID3_H
#define TAGINFO_ID3_H


#include "taginfo.h"

#include <id3v2tag.h>


using namespace TagLib;
using namespace TagInfo;

/** @file */


namespace TagInfo {
    
    // GENERAL ID3
    //! Info implementation for id3 tags.
    /*!
     * Id3Info is an common implementation of Info for media files with id3 tags.
    */    
    class Id3Info : public Info {
        protected :
            //! Constructor for Id3Info
            //! \param filename is the path to the media file
            Id3Info(const String &filename = "");
            
            //! Id3 v2 tag
            ID3v2::Tag * taglib_tagId3v2;
            
        public :
            virtual ~Id3Info();
            
            virtual bool load(void);
            virtual bool save();
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);
            
            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
    };
    
    
    
    // FILE TYPES
    
    //! Info implementation for aiff files.
    /*!
     * AiffInfo is an implementation of Info for aif files.
    */        
    class AiffInfo : public Id3Info {
        public :
            //! Constructor for AiffInfo 
            //! \param filename is the path to the media file
            AiffInfo(const String &filename = "");
            virtual ~AiffInfo();
    };
    
    //! Info implementation for mp3 files.
    /*!
     * Mp3Info is an implementation of Info for mp3 files.
    */    
    class Mp3Info : public Id3Info {
        public :
            //! Constructor for Mp3Info
            //! \param filename is the path to the media file
            Mp3Info(const String &filename = "");
            virtual ~Mp3Info();
    };
    
    //! Info implementation for trueaudio files.
    /*!
     * TrueAudioInfo is an implementation of Info for tta files.
    */        
    class TrueAudioInfo : public Id3Info {
        public :
            //! Constructor for TrueAudioInfo
            //! \param filename is the path to the media file
            TrueAudioInfo(const String &filename = "");
            virtual ~TrueAudioInfo();
    };
    
    
    //! Info implementation for wav files.
    /*!
     * WaveInfo is an implementation of Info for wav files.
    */        
    class WaveInfo : public Id3Info {
        public :
            //! Constructor for WaveInfo
            //! \param filename is the path to the media file
            WaveInfo(const String &filename = "");
            virtual ~WaveInfo();
    };
}

#endif
