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
 * 	Matias De lellis <mati86dl@gmail.com>
 * 	Pavel Vasin <rat4vier@gmail.com>
 */


#ifndef TAGINFO_C_H
#define TAGINFO_C_H

/** @file */

/**
 * @mainpage
 *
 * This manual documents the <b><em>C bindings</em></b> for libtaginfo. Libtaginfo is a wrapper library for 
 * taglib and allows access to media tags in an abstract way.
 * 
 * The functions used to interface the library through C language is available from the taginfo_c.h header.
 *
 * Known tag formats are: 
 *  - Ape tags, 
 *  - Asf tags and 
 *  - Id3 tags (v1, v2.2, v2.3, v2.4),
 *  - Mod tags.
 *  - Mp4 tags, 
 *  - Xiphcomment/Vorbis tag, 
 * 
 * These tags are used with the following media files (extensions / mime):
 *  - aac  : audio/aac, audio/aacp, audio/mp4, audio/x-aac
 *  - aif  : audio/x-aiff
 *  - aiff : audio/x-aiff
 *  - ape  : application/x-ape
 *  - asf  : audio/x-ms-asf, video/x-ms-asf
 *  - flac : audio/flac, audio/x-flac+ogg, audio/x-flac
 *  - it   : audio/x-it
 *  - m4a  : audio/mp4a-latm, audio/x-m4a
 *  - m4b  : audio/m4b
 *  - m4p  : audio/x-m4p
 *  - mod  : audio/x-mod
 *  - mp3  : audio/mpeg, audio/x-mpegurl
 *  - mp4  : audio/mp4, video/mp4
 *  - mpc  : audio/mpc, audio/x-musepack
 *  - oga  : audio/x-vorbis+ogg, audio/ogg
 *  - ogg  : audio/x-vorbis+ogg, audio/ogg
 *  - s3m  : audio/x-s3m
 *  - spx  : audio/x-spx, audio/x-speex, audio/x-speex+ogg
 *  - tta  : audio/tta, audio/x-tta
 *  - wav  : audio/x-wav
 *  - wma  : audio/x-ms-wma
 *  - wmv  : video/x-ms-wmv, video/x-msvideo
 *  - wv   : application/x-wavpack, audio/wavpack, audio/x-wavpack
 *  - xm   : audio/x-xm
 *
 * There is an API for accessing the following media tags:
 *  - Album
 *  - Album artist
 *  - Artist
 *  - BPM
 *  - Comments;
 *  - Compilation/V.A. flag
 *  - Composer;
 *  - Copyright;
 *  - Encoder;
 *  - Genre
 *  - Homepage;
 *  - Images (embedded image files)
 *  - Lyrics
 *  - Original artist
 *  - Play count
 *  - Rating (1 - 5 stars, 0 not set) 
 *  - Title
 *  - Track count;
 *  - Track number;
 *  - User defined album labels;
 *  - User defined artist labels;
 *  - User defined track labels;
 *  - Volume count;
 *  - Volume number;
 *  - Year
 * 
 * However, some media tags are not supported by some tag formats. (E.g. mod tags are very limited)
 * 
 * There is an API for accessing the following audio properties:
 *  - Bitrate
 *  - Channel count
 *  - Lenght in seconds
 *  - Sample rate
 * 
 * 
 * Examples can be found in the <b>examples</b> directory in the source code package.
 * 
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BOOL
//! Boolean value as integer
#define BOOL int
#endif


//! \enum TagInfo_MediaFileType is an enumeration of media file types supported in libtaginfo
typedef enum {
    //! Unknown media file type
    TAG_INFO_FILE_TYPE_UNKNOWN, 
    //! Aac media file
    TAG_INFO_FILE_TYPE_AAC,
    //! Aiff media file
    TAG_INFO_FILE_TYPE_AIF,
    //! Ape media file
    TAG_INFO_FILE_TYPE_APE,
    //! Asf media file
    TAG_INFO_FILE_TYPE_ASF,
    //! Flac media file
    TAG_INFO_FILE_TYPE_FLAC,
    //! M4A media file
    TAG_INFO_FILE_TYPE_M4A,
    //! M4B media file
    TAG_INFO_FILE_TYPE_M4B,
    //! M4P media file
    TAG_INFO_FILE_TYPE_M4P,
    //! MP3 media file
    TAG_INFO_FILE_TYPE_MP3,
    //! MP4 media file
    TAG_INFO_FILE_TYPE_MP4,
    //! MPC media file
    TAG_INFO_FILE_TYPE_MPC,
    //! Oga media file
    TAG_INFO_FILE_TYPE_OGA,
    //! Ogg media file
    TAG_INFO_FILE_TYPE_OGG,
    //! Tta media file
    TAG_INFO_FILE_TYPE_TTA,
    //! Wave media file
    TAG_INFO_FILE_TYPE_WAV,
    //! Wma media file
    TAG_INFO_FILE_TYPE_WMA,
    //! WavPack media file
    TAG_INFO_FILE_TYPE_WV,
    //! Speex media file
    TAG_INFO_FILE_TYPE_SPEEX,
    //! Wmv media file
    TAG_INFO_FILE_TYPE_WMV,
    //! Mod media file
    TAG_INFO_FILE_TYPE_MOD,
    //! Impulse Tracker media file
    TAG_INFO_FILE_TYPE_IT,
    //! Xm media file
    TAG_INFO_FILE_TYPE_XM,
    //! S3m media file
    TAG_INFO_FILE_TYPE_S3M,
    //! Opus media file
    TAG_INFO_FILE_TYPE_OPUS
} TagInfo_MediaFileType;


//! \enum TagInfo_ImageFileType is an enumeration of image file types for embedded images
typedef enum {
        //! Unknown image file type
    TAG_INFO_IMAGE_FILE_TYPE_UNKNOWN,
        //! Jpg file type
    TAG_INFO_IMAGE_FILE_TYPE_JPEG,
        //! Png file type
    TAG_INFO_IMAGE_FILE_TYPE_PNG,
        //! Gif file type
    TAG_INFO_IMAGE_FILE_TYPE_GIF,
        //! Bitmap file type
    TAG_INFO_IMAGE_FILE_TYPE_BMP
} TagInfo_ImageFileType;


//! \enum TagInfo_ImageContentType enumeration for image content description
typedef enum {
    //! An image type not listed here
    TAG_INFO_IMAGE_CONTENT_OTHER,
    //! 32x32 PNG image that should be used as the file icon
    TAG_INFO_IMAGE_CONTENT_FILE_ICON,
    //! File icon of a different size or format
    TAG_INFO_IMAGE_CONTENT_OTHER_FILE_ICON,
    //! Front cover image of the album
    TAG_INFO_IMAGE_CONTENT_COVER_FRONT,
    //! Back cover image of the album
    TAG_INFO_IMAGE_CONTENT_COVER_BACK,
    //! Inside leaflet page of the album
    TAG_INFO_IMAGE_CONTENT_LEAFLET_PAGE,
    //! Image from the album itself
    TAG_INFO_IMAGE_CONTENT_MEDIA,
    //! Picture of the lead artist or soloist
    TAG_INFO_IMAGE_CONTENT_LEAD_ARTIST,
    //! Picture of the artist or performer
    TAG_INFO_IMAGE_CONTENT_ARTIST,
    //! Picture of the conductor
    TAG_INFO_IMAGE_CONTENT_CONDUCTOR,
    //! Picture of the band or orchestra
    TAG_INFO_IMAGE_CONTENT_BAND,
    //! Picture of the composer
    TAG_INFO_IMAGE_CONTENT_COMPOSER,
    //! Picture of the lyricist or text writer
    TAG_INFO_IMAGE_CONTENT_LYRICIST,
    //! Picture of the recording location or studio
    TAG_INFO_IMAGE_CONTENT_RECORDING_LOCATION,
    //! Picture of the artists during recording
    TAG_INFO_IMAGE_CONTENT_DURING_RECORDING,
    //! Picture of the artists during performance
    TAG_INFO_IMAGE_CONTENT_DURING_PERFORMANCE,
    //! Picture from a movie or video related to the track
    TAG_INFO_IMAGE_CONTENT_MOVIESCREENCAPTURE,
    //! Picture of a large, coloured fish.
    TAG_INFO_IMAGE_CONTENT_COLOURED_FISH,
    //! Illustration related to the track
    TAG_INFO_IMAGE_CONTENT_ILLUSTRATION,
    //! Logo of the band or performer
    TAG_INFO_IMAGE_CONTENT_ARTIST_LOGO,
    //! Logo of the publisher (record company)
    TAG_INFO_IMAGE_CONTENT_PUBLISHER_LOGO
} TagInfo_ImageContentType;


//! TagInfo_Info is an abstraction for accessing media file tags. 
//! The caller should destroy TagInfo_Info with taginfo_info_free() after usage. Internal data will then automatically be removed.
typedef struct { 
} TagInfo_Info;


//! TagInfo_Image contains image data and image information. 
//! The caller should destroy TagInfo_Image with taginfo_image_free() after usage. Internal data will then automatically be removed.
typedef struct {
} TagInfo_Image;


/*----------------------------------------------------------------------------------------*/
//Info FREE FUNCTION
void taginfo_info_free(TagInfo_Info *info);
/*----------------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------*/
// FACTORY CREATION
TagInfo_Info *taginfo_info_create(const char *filename);
TagInfo_Info *taginfo_info_create_with_file_type(const char *filename, TagInfo_MediaFileType format);
TagInfo_Info *taginfo_info_create_from_mime(const char *filename, const char *mime_type);
/*----------------------------------------------------------------------------------------*/


BOOL  taginfo_info_is_valid(TagInfo_Info *info);
/*----------------------------------------------------------------------------------------*/
// LOAD / SAVE
BOOL  taginfo_info_load(TagInfo_Info *info);
BOOL  taginfo_info_save(TagInfo_Info *info);
/*----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------*/
// STRING MANAGEMENT
void  taginfo_info_enable_string_management(BOOL management);
void  taginfo_info_free_strings();
/*----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------*/
// TAG ACCESS
char *taginfo_info_get_album(const TagInfo_Info *info);
void  taginfo_info_set_album(TagInfo_Info *info, const char *album);

char *taginfo_info_get_albumartist(const TagInfo_Info *info);
void  taginfo_info_set_albumartist(TagInfo_Info *info, const char *albumartist);

char *taginfo_info_get_artist(const TagInfo_Info *info);
void  taginfo_info_set_artist(TagInfo_Info *info, const char *artist);

int  taginfo_info_get_beats_per_minute(const TagInfo_Info *info);
void taginfo_info_set_beats_per_minute(TagInfo_Info *info, int new_bpm);

char *taginfo_info_get_comment(const TagInfo_Info *info);
void  taginfo_info_set_comment(TagInfo_Info *info, const char *comment);

char *taginfo_info_get_composer(const TagInfo_Info *info);
void  taginfo_info_set_composer(TagInfo_Info *info, const char *composer);

char *taginfo_info_get_copyright(const TagInfo_Info *info);
void  taginfo_info_set_copyright(TagInfo_Info *info, const char *copyright);

char *taginfo_info_get_encoder(const TagInfo_Info *info);
void  taginfo_info_set_encoder(TagInfo_Info *info, const char *encoder);

char *taginfo_info_get_genre(const TagInfo_Info *info);
void  taginfo_info_set_genre(TagInfo_Info *info, const char *genre);

BOOL taginfo_info_get_has_image(const TagInfo_Info *info);

char *taginfo_info_get_homepage(const TagInfo_Info *info);
void  taginfo_info_set_homepage(TagInfo_Info *info, const char *homepage);

BOOL taginfo_info_get_is_compilation(const TagInfo_Info *info);
void taginfo_info_set_is_compilation(TagInfo_Info *info, BOOL is_compilation);

char *taginfo_info_get_original_artist(const TagInfo_Info *info);
void  taginfo_info_set_original_artist(TagInfo_Info *info, const char *artist);

int  taginfo_info_get_playcount(const TagInfo_Info *info);
void taginfo_info_set_playcount(TagInfo_Info *info, int count);

// rating 1 - 5; 0 -> not set
int  taginfo_info_get_rating(const TagInfo_Info *info);
void taginfo_info_set_rating(TagInfo_Info *info, int rating);

char *taginfo_info_get_title(const TagInfo_Info *info);
void  taginfo_info_set_title(TagInfo_Info *info, const char *title);

int  taginfo_info_get_track_count(const TagInfo_Info *info);
void taginfo_info_set_track_count(TagInfo_Info *info, int track_number);

int  taginfo_info_get_track_number(const TagInfo_Info *info);
void taginfo_info_set_track_number(TagInfo_Info *info, int track_number);

int  taginfo_info_get_volume_count(const TagInfo_Info *info);
void taginfo_info_set_volume_count(TagInfo_Info *info, int count);

int  taginfo_info_get_volume_number(const TagInfo_Info *info);
void taginfo_info_set_volume_number(TagInfo_Info *info, int number);

int  taginfo_info_get_year(const TagInfo_Info *info);
void taginfo_info_set_year(TagInfo_Info *info, int year);


// AUDIO PROPERTIES
int  taginfo_info_get_length(const TagInfo_Info *info);
int  taginfo_info_get_bitrate(const TagInfo_Info *info);
int  taginfo_info_get_samplerate(const TagInfo_Info *info);
int  taginfo_info_get_channels(const TagInfo_Info *info);

// USER LABELS
char ** taginfo_info_get_track_labels(const TagInfo_Info *info,
                                     int *data_length);
void    taginfo_info_set_track_labels(TagInfo_Info *info,
                                   const char* const* data, int data_length);

char ** taginfo_info_get_album_labels(const TagInfo_Info *info,
                                     int *data_length);
void    taginfo_info_set_album_labels(TagInfo_Info *info,
                                   const char* const* data, int data_length);

char ** taginfo_info_get_artist_labels(const TagInfo_Info *info,
                                      int *data_length);
void    taginfo_info_set_artist_labels(TagInfo_Info *info,
                                    const char* const* data,
                                    int data_length);

// LYRICS
char *                  taginfo_info_get_lyrics(const TagInfo_Info *info);
void                    taginfo_info_set_lyrics(TagInfo_Info *info,
                                                const char *lyrics);
/*----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/
// IMAGE Extraction
TagInfo_Image **        taginfo_info_get_images(const TagInfo_Info *info,
                                                int *image_count);
void                    taginfo_info_set_images(TagInfo_Info *info,
                                                TagInfo_Image ** images,
                                                const int image_count);
/*----------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------*/
// IMAGE API
TagInfo_Image *          taginfo_image_new();

void                     taginfo_image_free(TagInfo_Image * img);
void                     taginfo_image_array_free(TagInfo_Image ** img_arr);

char *                   taginfo_image_get_data(const TagInfo_Image * img, unsigned int * bin_data_length);
void                     taginfo_image_set_data(TagInfo_Image * img,
                                                char * bin_data, 
                                                unsigned int bin_data_length);

TagInfo_ImageContentType taginfo_image_get_content_type(const TagInfo_Image * img);
void                     taginfo_image_set_content_type(TagInfo_Image * img,
                                                      TagInfo_ImageContentType itype);

TagInfo_ImageFileType    taginfo_image_get_file_type(const TagInfo_Image * img);
void                     taginfo_image_set_file_type(TagInfo_Image * img,
                                                           TagInfo_ImageFileType image_f_type);

char *                   taginfo_image_get_description(const TagInfo_Image * img);
void                     taginfo_image_set_description(TagInfo_Image * img,
                                                       const char * new_description);
/*----------------------------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif
#endif
