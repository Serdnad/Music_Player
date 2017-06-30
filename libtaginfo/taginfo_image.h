/*
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
 */


#ifndef TAGINFO_IMAGE_H
#define TAGINFO_IMAGE_H

#include "taginfo.h"

using namespace TagLib;


/** @file */


namespace TagInfo {
    
    //! Wrapper for image data and related information
    /*!
    * This class holds image data and information on loads and writes
    * Internal memory is freed automatically.
    */
    class Image {
        public:
            //! \enum ImageFileType The enumeration type for the image encoding
            /*!
            * Binary formats of embedded images (jpeg, png, ...)
            */
            enum FileType {
                //! Unknown image file type
                TYPE_UNKNOWN,
                //! Jpg file type
                TYPE_JPEG,
                //! Png file type
                TYPE_PNG,
                //! Gif file type
                TYPE_GIF,
                //! Bitmap file type
                TYPE_BMP
            };
            
            
            //! \enum ContentType The enumeration type for the image content
            /*!
            * Enumerated classification of image content
            */
            enum ContentType { 
                //! An image type not listed here
                CONTENT_OTHER, 
                //! 32x32 PNG image that should be used as the file icon
                CONTENT_FILE_ICON,
                //! File icon of a different size or format
                CONTENT_OTHER_FILE_ICON,
                //! Front cover image of the album
                CONTENT_COVER_FRONT,
                //! Back cover image of the album
                CONTENT_COVER_BACK,
                //! Inside leaflet page of the album
                CONTENT_LEAFLET_PAGE,
                //! Image from the album itself
                CONTENT_MEDIA,
                //! Picture of the lead artist or soloist
                CONTENT_LEAD_ARTIST,
                //! Picture of the artist or performer
                CONTENT_ARTIST,
                //! Picture of the conductor
                CONTENT_CONDUCTOR,
                //! Picture of the band or orchestra
                CONTENT_BAND,
                //! Picture of the composer
                CONTENT_COMPOSER,
                //! Picture of the lyricist or text writer
                CONTENT_LYRICIST,
                //! Picture of the recording location or studio
                CONTENT_RECORDING_LOCATION,
                //! Picture of the artists during recording
                CONTENT_DURING_RECORDING,
                //! Picture of the artists during performance
                CONTENT_DURING_PERFORMANCE,
                //! Picture from a movie or video related to the track
                CONTENT_MOVIESCREENCAPTURE,
                //! Picture of a large, coloured fish.
                CONTENT_COLOURED_FISH,
                //! Illustration related to the track
                CONTENT_ILLUSTRATION,
                //! Logo of the band or performer
                CONTENT_ARTIST_LOGO,
                //! Logo of the publisher (record company)
                CONTENT_PUBLISHER_LOGO
            };
            
            //! Image constructor.
            /*!
              Sets up an Image object
            */
            Image();
            
            //! Image destructor.
            /*!
              Removes Image object and frees all internal data
            */
            ~Image();
            
            //! Get image binary data
            //! \return ByteVector with binary data
            const ByteVector get_data() const;
            
            //! Get image binary data
            //! \param image_data_length is the return location for the length of the binary data array
            //! \return Byte array with binary data
            char * get_data(uint &image_data_length) const;
            
            //! Set image binary data
            //! \param image_data The Byte array with binary image data
            //! \param image_data_length is the length of the binary image data array
            void set_data(const char * image_data, const uint image_data_length);
            
            //! Set image binary data
            //! \param image_data ByteVector with binary image data
            void set_data(const ByteVector &image_data);
            
            Image::ContentType get_content_type(void) const;
            void set_content_type(const Image::ContentType it);
            
            Image::FileType get_file_type(void) const;
            void set_file_type(const Image::FileType ft);
            
            const String get_description(void) const;
            void set_description(const String &description);
            
        private:
            //! \a bytes The image binary data
            ByteVector      bytes;
            //! \a image_type is the ImageType enum, giving information 
            //! on the content of the picture 
            ContentType     image_type;
            
            //! \a image_file_type is the ImageFileType enum, giving 
            //! information on the file type of the embedded picture
            FileType        image_file_type;
            
            //! The \a description gives extra information on the image
            //! (Not supported by all media tags). NULL if not set
            String          description;
    };
}

#endif
