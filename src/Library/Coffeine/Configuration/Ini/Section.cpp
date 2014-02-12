/// *** Configuration :: Ini :: Section  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-12-12 10:03:00 :: 2014-01-20 21:48:32
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Section Ini
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include "Section.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section()
{
    this -> name = L"";
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom constructor
 *
 * @param wstring Name Section name
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Copy constructor
 *
 * @param const Section & Orig
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section( const Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Free memory and clean object
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: ~Section()
{
    //- Free memory -//
    this -> name.clear();
    this -> subSection.clear();
    this -> objects.clear();
}


//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetName
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for Name of Section
 *
 * @param void
 * @return wstring Name of section
*///*** *** *** *** *** *** *** *** *** *** *** *** *
wstring Configuration :: Ini :: Section :: GetName()
{
    return this -> name;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetObjects
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for Objects
 *
 * @param void
 * @return map < wstring, Configuration :: Object > &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
map < wstring, Configuration :: Object > & Configuration :: Ini :: Section :: GetObjects()
{
    return this -> objects;
}


//- SECTION :: SET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetName
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Setter for Name of section
 *
 * @param wstring Name
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: SetName( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetSubSection
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Setter for SubSections
 *
 * @param map < wstring, Section > SubSections
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: SetSubSections( map < wstring, Section > SubSections )
{
    this -> subSection = SubSections;
}


//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddSubSection
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add new sub section
 *
 * @param Section SubSection
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: AddSubSection( Section SubSection )
{
    this -> subSection.insert(
        pair < wstring, Section >(
            SubSection.GetName(), 
            SubSection
        )
    );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add new or update exist object to this section
 *
 * @param Object Object
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: AddObject( Configuration :: Object Object )
{
    if( this -> objects.find( Object.GetName() ) == this -> objects.end() )
    {
        //- Add bew object -//
        this -> objects.insert(
            pair < wstring, Configuration :: Object >(
                Object.GetName(), 
                Object
            )
        );
    }else
        {
            //- Update exist object -//
            this -> objects[ Object.GetName() ] += Object;
        }
}


//- SECTION :: OPERATORS -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param const Section & Orig
 * @return Section &
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator = ( const Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param Section & Orig
 * @return Section &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator = ( Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator ==
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param const Section & Orig
 * @return & Section
*///*** *** *** *** *** *** *** *** *** *** *** *** *
//bool Configuration :: Ini :: Section :: operator == ( const Section & Orig )
//{
//    return this -> name == Orig.name;// TODO: rewrite
////        && this -> objects == Orig.objects
////        && this -> subSection == Orig.subSection;
//}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator ()
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param wstring SectionName
 * @return & Section
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator () ( wstring SectionName )
{
    return this -> subSection[ SectionName ];
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator []
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param wstring ObjectName
 * @return & Object
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Ini :: Section :: operator [] ( wstring ObjectName )
{
    return this -> objects[ ObjectName ];
}
