/// *** Configuration :: Ini :: Object  *** *** *** *** *** *** *** *** *** ///

    /** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *
     *                                                                  *
     * @copyright (c), 2013 by Vitaliy Tsutsman
     *
     * @author Vitaliy Tsutsman
     *
     * @date 2013-12-12 10:25:00 :: 2013-12-29 13:11:45
     *
     * @address /Ukraine/Ivano-Frankivsk/Tychyny/7a (Softjourn)
     *
     * @description Object Ini
     *                                                                  *
    *///*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *

/// *** Dependencies    *** *** *** *** *** *** *** *** *** *** *** *** *** ///
#include <istream>
#include <fstream>
#include <cstring>
#include <wchar.h>
#include <map>
#include <clocale>

#include <boost/lexical_cast.hpp>

#include "Object.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- *
 * Default
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object :: Object()
{
    this -> name = L"";
}

/** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring Name Object name
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object :: Object( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *
 * Copy constructor
 *  --- --- --- --- --- --- --- --- --- *
 * @param const Object & Orig
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object :: Object( const Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;
}

/** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- *
 *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object :: ~Object()
{
    //- Free memory -//
    this -> name.clear();
    this -> data.clear();
    this -> subObject.clear();
}

//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *
 * GetName
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for name
 * @return wstring Object's name
*///*** *** *** *** *** *** *** *** *** *
wstring Configuration :: Ini :: Object :: GetName()
{
    return this -> name;
}

/** *** *** *** *** *** *** *** *** *** *
 * GetBoolean
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for boolean params
 * @param wstring PropertyName Property name for return
 * @return bool Object's property
*///*** *** *** *** *** *** *** *** *** *
bool Configuration :: Ini :: Object :: GetBoolean( wstring PropertyName )
{
    if( this -> data[ PropertyName ] == L"true" )
    {
        return true;
    }
    
    if( this -> data[ PropertyName ] == L"false" )
    {
        return false;
    }

    return boost :: lexical_cast < bool > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetDouble
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for double params
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *
double Configuration :: Ini :: Object :: GetDouble( wstring PropertyName )
{
    return boost :: lexical_cast < double > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetFloat
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for float params
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *
float Configuration :: Ini :: Object :: GetFloat( wstring PropertyName )
{
    return boost :: lexical_cast < float > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetInt
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for int params
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *
int Configuration :: Ini :: Object :: GetInt( wstring PropertyName )
{
    return boost :: lexical_cast < int > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetLong
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for long params
 * @param wstring PropertyName Property name for return
 * @return long Object's property
*///*** *** *** *** *** *** *** *** *** *
long Configuration :: Ini :: Object :: GetLong( wstring PropertyName )
{
    return boost :: lexical_cast < long > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetUInt
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for int params
 * @param wstring PropertyName Property name for return
 * @return UINT Object's property
*///*** *** *** *** *** *** *** *** *** *
unsigned int Configuration :: Ini :: Object :: GetUInt( wstring PropertyName )
{
    return boost :: lexical_cast < unsigned int > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *
 * GetString
 *  --- --- --- --- --- --- --- --- --- *
 * Getter for string properties
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *
wstring Configuration :: Ini :: Object :: GetString( wstring PropertyName )
{
    return this -> data[ PropertyName ];
}


//- SECTION :: SET -//
/** *** *** *** *** *** *** *** *** *** *
 * SetSubObject
 *  --- --- --- --- --- --- --- --- --- *
 * Setter for subObject
 * @param Object SubObject Sub object for this object
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Object :: SetSubObject( map < wstring, Object > SubObject )
{
    subObject = SubObject;
}


//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *
 * AddProperty
 *  --- --- --- --- --- --- --- --- --- *
 * Add property
 * @param wstring Name
 * @param Object SubObject Sub object for this object
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Object :: AddProperty( wstring Name, wstring Value )
{
    this -> data.insert( 
        pair < wstring, wstring > ( 
            Name, 
            Value 
        ) 
    );
}

/** *** *** *** *** *** *** *** *** *** *
 * AddSubObject
 *  --- --- --- --- --- --- --- --- --- *
 * Add subObjects
 * @param Object SubObject Sub object for this object
 * @return void
*///*** *** *** *** *** *** *** *** *** *
void Configuration :: Ini :: Object :: AddSubObject( wstring Name, Object SubObject )
{
    this -> subObject.insert( 
        pair < wstring, Object > ( 
            SubObject.GetName(), 
            SubObject 
        ) 
    );
}


//- SECTION :: OPERATORS -//
/** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- *
 * @param const Object * Orig
 * @return Object *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object & Configuration :: Ini :: Object :: operator = ( const Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- *
 * @param Object * Orig
 * @return Object *
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object & Configuration :: Ini :: Object :: operator = ( Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *
 * Operator []
 *  --- --- --- --- --- --- --- --- --- *
 * @param wstring Key
 * @return Object
*///*** *** *** *** *** *** *** *** *** *
Configuration :: Ini :: Object & Configuration :: Ini :: Object :: operator [] ( wstring Key )
{
    return this -> subObject[ Key ];
}
