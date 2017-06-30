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
 * 	Matias De lellis <mati86dl@gmail.com>
 * 	Pavel Vasin <rat4vier@gmail.com>
 */


#ifndef TAGINFO_H
#define TAGINFO_H

#include <stdio.h>
#include <string.h>

#include <tag.h>
#include <apetag.h>
#include <asftag.h>
#include <fileref.h>
#include <id3v2tag.h>
#include <flacfile.h>
#include <modtag.h>
#include <mp4tag.h>
#include <xiphcomment.h>

#include "taginfo_image.h"


using namespace TagLib;
using namespace std;

/** @file */


 /*!
  * 
  * The \namespace TagInfo contains classes for abstract access to media file tags.
  */
namespace TagInfo {
    
    //! TagLib::List<TagInfo::Image *> .
    //! ImageList holds pointers to Images. Automatic memory management can be enabled
    //! with the setAutoDelete(bool auto_delete) function.
    typedef TagLib::List<Image *> ImageList;
    
    //! \enum MediaFileType describes the media file type
    /*! Enumerator for the type of the media file. */
    enum MediaFileType {
        //! Unknown media file type
        FILE_TYPE_UNKNOWN, 
        //! Aac media file
        FILE_TYPE_AAC,
        //! Aiff media file
        FILE_TYPE_AIF,
        //! Ape media file
        FILE_TYPE_APE,
        //! Asf media file
        FILE_TYPE_ASF,
        //! Flac media file
        FILE_TYPE_FLAC,
        //! M4A media file
        FILE_TYPE_M4A,
        //! M4B media file
        FILE_TYPE_M4B,
        //! M4P media file
        FILE_TYPE_M4P,
        //! MP3 media file
        FILE_TYPE_MP3,
        //! MP4 media file
        FILE_TYPE_MP4,
        //! MPC media file
        FILE_TYPE_MPC,
        //! Oga media file
        FILE_TYPE_OGA,
        //! Ogg media file
        FILE_TYPE_OGG,
        //! Tta media file
        FILE_TYPE_TTA,
        //! Wave media file
        FILE_TYPE_WAV,
        //! Wma media file
        FILE_TYPE_WMA,
        //! WavPack media file
        FILE_TYPE_WV,
        //! Speex media file
        FILE_TYPE_SPEEX,
        //! Wmv media file
        FILE_TYPE_WMV,
        //! Mod media file
        FILE_TYPE_MOD,
        //! Impulse Tracker media file
        FILE_TYPE_IT,
        //! Xm media file
        FILE_TYPE_XM,
        //! S3m media file
        FILE_TYPE_S3M,
        //! Opus media file
        FILE_TYPE_OPUS
    };
    
    
    
    //! A simple, generic interface to common audio meta data fields and media properties
    /*!
    * Info is an abstract base class for media tag reading/writing  
    */
    class Info {
        public:
            virtual ~Info();
            
            // CREATION METHODS
            static Info * create(const String &filename);
            static Info * create_with_file_type(const String &file, MediaFileType format);
            static Info * create_from_mime(const String &filename, const String &mime_type);
            
            //General stuff
            
            //! \return name of media file
            String get_file_name(void);
            
            //! Information if the media file could be recognized and appears to be valid
            //! \return true if valid 
            bool is_valid();
            
            
            //Tag access functions
            
            String get_album_artist(void) const;
            void   set_album_artist(const String new_artist);
            
            String get_album(void) const;
            void   set_album(const String new_album);
            
            String get_artist(void) const;
            void   set_artist(const String new_artist);
            
            int    get_beats_per_minute() const;
            void   set_beats_per_minute(const int new_bpm);
            
            String get_comments(void) const;
            void   set_comments(const String new_comments);
            
            String get_composer(void) const;
            void   set_composer(const String new_composer);
            
            String get_copyright(void) const;
            void   set_copyright(const String new_copyright);
            
            String get_encoder(void) const;
            void   set_encoder(const String new_encoder);
            
            String get_genre(void) const;
            void   set_genre(const String new_genre);
            
            bool   get_has_image() const;
            
            String get_homepage(void) const;
            void   set_homepage(const String new_homepage);
            
            bool   get_is_compilation() const;
            void   set_is_compilation(bool compilation);
            
            String get_original_artist(void) const;
            void   set_original_artist(const String new_artist);
            
            int    get_playcount() const;
            void   set_playcount(int new_playcount);
            
            int    get_rating() const;
            void   set_rating(const int new_rating);
            
            String get_title(void) const;
            void   set_title(const String new_title);
            
            int    get_track_count() const;
            void   set_track_count(const int new_track_count);
            
            int    get_track_number() const;
            void   set_track_number(const int new_track_number);
            
            int    get_volume_count() const;
            void   set_volume_count(const int count);
            
            int    get_volume_number() const;
            void   set_volume_number(const int number);
            
            int    get_year() const;
            void   set_year(const int new_year);
            
            //Audio properties
            int    get_length_seconds() const;
            int    get_bitrate() const;
            int    get_channels() const;
            int    get_samplerate() const;
            
            
            //Labels
            StringList get_track_labels_list() const;
            void       set_track_labels_list(const StringList &new_track_labels_list);
            
            StringList get_artist_labels_list() const;
            void       set_artist_labels_list(const StringList &new_artist_labels_list);
            
            StringList get_album_labels_list() const;
            void       set_album_labels_list(const StringList &new_album_labels_list);
            
            
            
            /*!
             * Loads tags and properties from the Info object of a file.
             * String returns are coming as TagLib::String.
             */
            virtual bool load(void);
            
            /*!
             * Saves the tags of the Info object to the media file.
             */
            virtual bool save(void);
            
            
            virtual ImageList get_images() const;
            virtual void      set_images(const ImageList images);

            virtual String    get_lyrics(void) const;
            virtual void      set_lyrics(const String &lyrics);
            
            
        protected :
            //! Constructor to be called from derrived classes
            Info(const String &filename = "");

            //! \a TagLib::FileRef of the media file
            TagLib::FileRef * taglib_fileref;
            
            //! \a TagLib::File of the media file
            TagLib::File *    taglib_file;
            
            //! \a TagLib::Tag of the media file
            TagLib::Tag *     taglib_tag;

            //! The path of the media file
            String file_name;
            
            //Tags

            //! Title of the Info object 
            String title;
            //! Genre of the Info object 
            String genre;
            //! Artist of the Info object 
            String artist;
            //! Album artist of the Info object 
            String album_artist;
            //! Album of the Info object
            String album;
            //! Composer of the Info object
            String composer;
            //! Comments of the Info object
            String comments;
            //! Homepage of the Info object
            String homepage;
            //! Encoder of the Info object
            String encoder;
            //! Copyright of the Info object
            String copyright;
            //! Original artist of the Info object
            String original_artist;
            //! Track number of the Info object
            int    track_number;
            //! Track count of the Info object
            int    track_count;
            //! Year of the Info object
            int    year;
            //! Whether the media file is part of a compilation
            bool   is_compilation;
            //! Speed in beats per minute
            int beats_per_minute;
            //! Volume number of the Info object
            int    volume_number;
            //! Volume count of the Info object
            int    volume_count;
            
            
            //Audioproperties
            //! Lenght in seconds
            int    length_seconds;
            //! Bitrate
            int    bitrate;
            //! Sample rate
            int    samplerate;
            //! Channel count
            int    channels;
            
            //Extras
            //! Play count
            int    playcount;
            //! Rating (1 - 5 stars, 0 not set) 
            int    rating;
            
            //! User defined track labels
            StringList track_labels;
            //! User defined track labels as string with "|" as delimiter
            String     track_labels_string;
            //! User defined artist labels
            StringList artist_labels;
            //! User defined artist labels as string with "|" as delimiter
            String     artist_labels_string;
            //! User defined album labels
            StringList album_labels;
            //! User defined album labels as string with "|" as delimiter
            String     album_labels_string;
            
            //! The setters for the tags on the info object will set these ChangedFlags flags
            ulong changedflag;
            
            //! Whether there is image data available
            bool has_image;
            
            //! Whether the info object is valid
            bool valid;
            
            //! Load the abstact basic tags from TagLib::Tag
            //! This will only do something if \param tag is not NULL
            void   load_base_tags(TagLib::Tag * tag);
            
            //! Save the abstact basic tags to TagLib::Tag
            //! This will only do something if \param tag is not NULL
            void   save_base_tags(TagLib::Tag * tag);
    };

    //! A simple, value based wrapper round Info
    
    /* ! InfoRef exists to provide a minimal, generic and value-based wrapper around
     * a Info.  It is lightweight and suitable for pass-by-value use.  
     * This hides the TagInfo::Info memory management.
     */
    class InfoRef {
        public:
            InfoRef(const String &filename);
            InfoRef(const String &filename, MediaFileType format);
            InfoRef(const String &filename, const String &mime);
            ~InfoRef();
            
            Info * info() const;
            bool is_valid() const;
            bool load() const;
            bool save();
            
        private:
            Info * i;
    };
    
}
#endif
