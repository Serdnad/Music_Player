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

#ifndef TAGINFO_MODTAG_H
#define TAGINFO_MODTAG_H

#include "taginfo.h"


using namespace TagLib;
using namespace TagInfo;

/** @file */



namespace TagInfo {

    //Implementations for different mod tags
    
    //! Info implementation for mod tags..
    /*!
     * ModTagInfo is an implementation of Info for Mod Tags.
     * It is used for .it, .mod, s3m and xm files
    */
    class ModTagInfo : public Info {
        protected :
            //! Constructor for ModTagInfo
            //! \param filename is the path to the media file
            ModTagInfo(const String &filename = "");
            //! TagLib::Mod::Tag of the media file
            Mod::Tag * taglib_tagMod;
            
        public :
            virtual ~ModTagInfo();
            
            virtual bool load(void);
            virtual bool save();
    };
    
    //! Info implementation for mod files.
    /*!
     * ModInfo is an implementation of Info for .mod files (%Mod Tracker).
     * The tagging possibilities of this format is very limited and quite some 
     * tag types are not supported.
    */
    class ModInfo : public ModTagInfo {
        public :
            //! Constructor for ModInfo
            //! \param filename is the path to the media file
            ModInfo(const String &filename = "");
            virtual ~ModInfo();
    };
    
    //! Info implementation for it files.
    /*!
     * ItInfo is an implementation of Info for .it files (Impulse Tracker).
     * The tagging possibilities of this format is very limited and quite some 
     * tag types are not supported.
    */
    class ItInfo : public ModTagInfo {
        public :
            //! Constructor for ItInfo
            //! \param filename is the path to the media file
            ItInfo(const String &filename = "");
            virtual ~ItInfo();
    };
    
    //! Info implementation for s3m files.
    /*!
     * S3mInfo is an implementation of Info for .s3m files.
     * The tagging possibilities of this format is very limited and quite some 
     * tag types are not supported.
    */
    class S3mInfo : public ModTagInfo {
        public :
            //! Constructor for S3mInfo
            //! \param filename is the path to the media file
            S3mInfo(const String &filename = "");
            virtual ~S3mInfo();
    };
    
    //! Info implementation for xm files.
    /*!
     * XmInfo is an implementation of Info for .xm files.
     * The tagging possibilities of this format is very limited and quite some 
     * tag types are not supported.
    */
    class XmInfo : public ModTagInfo {
        public :
            //! Constructor for XmInfo
            //! \param filename is the path to the media file
            XmInfo(const String &filename = "");
            virtual ~XmInfo();
    };
   
}

#endif
