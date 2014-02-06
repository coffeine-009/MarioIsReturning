/// *** Configuration :: Ini :: Reader  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50 :: 2014-02-05 17:26:07
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Reader.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: Reader()
{
    this -> currentSection = &this -> data;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom
 *
 * @param string FileName
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: Reader( string FileName ) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> sectionName = L"";
    this -> subSectionName = L"";

    this -> currentSection = &this -> data;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom
 *
 * @param string FileName
 * @param wstring SectionName
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: Reader(
    string FileName,
    wstring SectionName
) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> sectionName = SectionName;
    this -> subSectionName = L"";

    this -> currentSection = &this -> data;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom
 *
 * @param string FileName
 * @param wstring SectionName
 * @param wstring SubSectionName
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: Reader(
    string FileName, 
    wstring SectionName, 
    wstring SubSectionName
) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> sectionName = SectionName;
    this -> subSectionName = SubSectionName;

    this -> currentSection = &this -> data;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Copy constructor
 *
 * @param const Reader & Orig
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: Reader( const Reader & Orig )
{
    this -> currentSection = Orig.currentSection;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * 
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Reader :: ~Reader()
{
    //- Free memory -//
    this -> fileName.clear();
    this -> sectionName.clear();
    this -> subSectionName.clear();
    this -> currentSection = NULL;
}


//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Convert ini file's content to Object
 *
 * @param void
 * @return Object &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Ini :: Reader :: GetObject()
{
    this -> result.SetSubObject(
        this -> data.GetObjects()
    );

    if( !this -> subSectionName.empty() )
    {
        Configuration :: Object tmp;
            tmp.SetSubObject(
                this -> data( this -> subSectionName ).GetObjects()
            );
        result += tmp;
    }

    return this -> result;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Read
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Read ini file and parse
 *
 * @throw InvalidFormatException//TODO: rewrite
 *
 * @param void
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Reader :: Read()
{
    //- Read data from file -//
    std :: wifstream file( this -> fileName.c_str(), std :: ios :: binary );

    while( !file.eof() )
    {
        //- Temp buffer for lines -//
        wchar_t line[ 128 ];

        //- Read line -//
        file.getline( line, 128 );

        //- Parse read line -//
        this -> Parse( line );
    }
    
    file.close();
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Parce
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Inner method for parce line in Ini format
 *
 * @throw InvalidFormatException//TODO: rewrite
 *
 * @param wstring Line
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Reader :: Parse( wstring Line )
{
    if( Line.empty() )
    {
        return;
    }

    //- Parse -//
    {
        //- Remove comments -//
        int comment_begin = Line.find( L';', 0 );
        if( comment_begin != -1 )
        {
            Line.erase( 
                comment_begin, 
                Line.length() - comment_begin
            );
        }

        //- Remove spaces -//
        Line.erase(
            remove_if(
                Line.begin(), 
                Line.end(), 
                ::isspace
            ), 
            Line.end()
        );
    }

    //- Parse sections -//
    {
        int section_begin_pos = Line.find( L'[', 0 );
        int section_end_pos = Line.find( L']', 0 );

        if( section_begin_pos != -1 && section_end_pos != -1 )
        {
            Line.erase( section_end_pos, 1 );
            Line.erase( section_begin_pos, 1 );

            vector < wstring > sections;
            boost :: split( sections, Line, boost :: is_any_of( L":" ) );

            //- Create section -//
            if( this -> data.GetName().empty()  )
            {
                this -> data.SetName( sections[ 0 ] );
            }

            //- Create Subsections -//
            for( unsigned int i = 1; i < sections.size() && i < 2; i++ )
            {
                this -> data.AddSubSection( sections[ i ] );
                this -> currentSection = &this -> data( sections[ i ] );
            }

            return;
        }
    }

    //- Purse objects -//
    {
        vector < wstring > pair_object_value;
        boost :: split( pair_object_value, Line, boost :: is_any_of( L"=" ) );

        if( pair_object_value.size() == 2 )
        {
            this -> currentSection -> AddObject(
                this -> ParseObject( 
                    pair_object_value[ 0 ], 
                    pair_object_value[ 1 ] 
                )
            );
        }else
            {
                //- Parse Exception -//
                //TODO: throw InvalidFormatException
            }
    }
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * ParceObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Parse line in Ini format and create object
 *
 * @throws BadParamsException
 * @throws ParseException
 *
 * @param wstring Line
 * @param wstring Value
 * 
 * @return Object
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object Configuration :: Ini :: Reader :: ParseObject( wstring Line, wstring Value )
{
    //- Split string for items -//
    vector < wstring > items;
    boost :: split( items, Line, boost :: is_any_of( L"." ) );
    unsigned int count_items = items.size();

    //- Result -//
    Configuration :: Object result( items[ 0 ] );

    //- Forming result -//
    //- Bad params -//
    if( count_items < 2 )
    {
        //TODO: throw BadParamsException
    }

    //- Finish step of parsing -//
    if( count_items == 2 )
    {
        result.AddProperty( items[ 1 ], Value );
    }

    //- Recurse parse last part of String -//
    if( count_items > 2 )
    {
        //- Delete first item -//
        Line.erase(
            0, 
            Line.find_first_of( L'.', 0 ) + 1
        );

        result.AddSubObject( this -> ParseObject( Line, Value ) );
    }

    return result;
}
