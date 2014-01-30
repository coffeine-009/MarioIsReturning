/// *** Application *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-11-27 18:11:50
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Main file for module
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <cstring>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "Reader.h"
#include "Object.h"
#include "Section.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
Configuration :: Ini :: Reader :: Reader()
{
    
}

Configuration :: Ini :: Reader :: Reader( string FileName ) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> fileName = FileName;
    this -> sectionName = L"";
    this -> subSectionName = L"";
}

Configuration :: Ini :: Reader :: Reader(
    string FileName,
    wstring SectionName
) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> sectionName = SectionName;
    this -> subSectionName = L"";
}

Configuration :: Ini :: Reader :: Reader(
    string FileName, 
    wstring SectionName, 
    wstring SubSectionName
) : ReaderInterface( FileName )
{
    //- Initialization -//
    this -> sectionName = SectionName;
    this -> subSectionName = SubSectionName;
}

Configuration :: Ini :: Reader :: Reader( const Reader& Orig )
{

}

Configuration :: Ini :: Reader :: ~Reader()
{

}

void Configuration :: Ini :: Reader :: Read()
{
    //- Read data from file -//
    std :: wifstream file( this -> fileName.c_str(), std :: ios :: binary );

    while( !file.eof() )
    {
        //- Temp buffer for lines -//
        wchar_t line[128];

        //- Read line -//
        file.getline( line, 128 );

        this -> Parse( line );
    }
    Configuration::Ini::Section s = this->data(L"development");
     wstring d = s.GetName();
    wstring t = this->data(L"test").GetName();
    file.close();
}

Configuration :: Object Configuration :: Ini :: Reader :: GetObject()
{
    return Configuration :: Object();
}

/**
 * Parce
 *  --- --- ---
 * Inner method for parce Ini file
 *
 * @param wstring Line
 * @return void
*/
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
            }
        }

        return;
    }

    //- Purse objects -//
    {
        vector < wstring > pair_object_value;
        boost :: split( pair_object_value, boost :: is_any_of( L"=" ) );

        if( pair_object_value.size() == 2 )
        {
            vector < wstring > objects;
            boost :: split( objects, boost :: is_any_of( L"." ) );

            Configuration :: Ini :: Object object;
            Configuration :: Ini :: Object * current_ref;
            for( unsigned int i = 0, len = objects.size(); i < len; i++ )
            {
                
            }

            this -> currentSection -> AddSubObject();
        }
    }
}
