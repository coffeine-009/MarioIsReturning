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
/** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section()
{
    this -> name = L"";
}

/** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring Name Section name
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *
 * Copy constructor
 *  --- --- --- --- --- --- --- --- --- *
 * @param const Section & Orig
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: Section( const Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;
}

/** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- *
 *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section :: ~Section()
{
    //- Free memory -//
    this -> name.clear();
    this -> subSection.clear();
    this -> objects.clear();
}


//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *
 * GetName
 *  --- --- --- --- --- --- --- --- --- *
 * @return wstring Name of section
*///*** *** *** *** *** *** *** *** *** *
wstring Configuration :: Ini :: Section :: GetName()
{
    return this -> name;
}

/** *** *** *** *** *** *** *** *** *** *
 * GetSubSection
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring SubSection
 * @return Section Sub section name
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section Configuration :: Ini :: Section :: GetSubSection( wstring SubSection )
{
    return this -> subSection[ SubSection ];
}


//- SECTION :: SET -//
/** *** *** *** *** *** *** *** *** *** *
 * SetName
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring Name
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: SetName( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *
 * SetSubSection
 *  --- --- --- --- --- --- --- --- --- *
 * @param map < wstring, Section > SubSections
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: SetSubSections( map < wstring, Section > SubSections )
{
    this -> subSection = SubSections;
}


//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *
 * AddSubSection
 *  --- --- --- --- --- --- --- --- --- *
 * @param Section * SubSection
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: AddSubSection( Section SubSection )
{
    this -> subSection.insert(
        pair < wstring, Section >(
            SubSection.GetName(), 
            SubSection
        )
    );
}

/** *** *** *** *** *** *** *** *** *** *
 * AddObject
 *  --- --- --- --- --- --- --- --- --- *
 * @param Object * Object
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Section :: AddObject( Object Object )
{
    this -> objects.insert(
        pair < wstring, Configuration :: Ini :: Object >(
            Object.GetName(), 
            Object
        )
    );
}


//- SECTION :: OPERATORS -//
/** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- *
 * @param const Section * Orig
 * @return Section *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator = ( const Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- *
 * @param Section * Orig
 * @return Section *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator = ( Section & Orig )
{
    this -> name        = Orig.name;
    this -> subSection  = Orig.subSection;
    this -> objects     = Orig.objects;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator ==
 *  --- --- --- --- --- --- --- --- --- *
 * @param const Section & Orig
 * @return & Section
*///*** *** *** *** *** *** *** *** *** *
bool Configuration :: Ini :: Section :: operator == ( const Section & Orig )
{
    return this -> name == Orig.name;
//        && this -> objects == Orig.objects
//        && this -> subSection == Orig.subSection;
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator ()
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring SectionName
 * @return & Section
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Section & Configuration :: Ini :: Section :: operator () ( wstring SectionName )
{
    return this -> subSection[ SectionName ];
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator []
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring ObjectName
 * @return & Object
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object & Configuration :: Ini :: Section :: operator [] ( wstring ObjectName )
{
    return this -> objects[ ObjectName ];
}
