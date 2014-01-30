/*
 * File:   Reader.cpp
 * Author: vitaliy
 *
 * Created on November 27, 2013, 6:11 PM
 */

#include <cstring>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "Reader.h"


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
            this -> data = Section( sections[ 0 ] );

            //- Create Subsections -//
            if( sections.size() == 2 )
            {
                this -> data.AddSubSection(
                    Section( sections[ 1 ] )
                );
            }
            
            std::wofstream f("/tmp/tmp.txt", std::ios::app);//TODO: del
            f << sections[0] << ":" << sections.size() << "\n";//TODO: del
            f.close();//TODO: del
        }
    }
}
