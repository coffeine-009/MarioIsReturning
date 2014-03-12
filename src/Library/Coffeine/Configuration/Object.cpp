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
#include "Object.h"


/// *** Code    *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ///
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Default
 *
 * @param void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object :: Object()
{
    this -> name = L"";
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Custom constructor
 *
 * @param wstring Name Object name
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object :: Object( wstring Name )
{
    this -> name = Name;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Constructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Copy constructor
 *
 * @param const Object & Orig
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object :: Object( const Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Destructor
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Free memory and clean object
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object :: ~Object()
{
    //- Free memory -//
    this -> name.clear();
    this -> data.clear();
    this -> subObject.clear();
}

//- SECTION :: GET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetName
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for name
 *
 * @param void
 * @return wstring Object's name
*///*** *** *** *** *** *** *** *** *** *** *** *** *
wstring Configuration :: Object :: GetName()
{
    return this -> name;
}

//- Getters for properties -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetBoolean
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for boolean params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return bool Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
bool Configuration :: Object :: GetBoolean( wstring PropertyName )
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

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetDouble
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for double params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
double Configuration :: Object :: GetDouble( wstring PropertyName )
{
    return boost :: lexical_cast < double > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetFloat
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for float params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
float Configuration :: Object :: GetFloat( wstring PropertyName )
{
    return boost :: lexical_cast < float > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetInt
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for int params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
int Configuration :: Object :: GetInt( wstring PropertyName )
{
    return boost :: lexical_cast < int > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetLong
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for long params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return long Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
long Configuration :: Object :: GetLong( wstring PropertyName )
{
    return boost :: lexical_cast < long > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetUInt
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for unsigned int params
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return UINT Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
unsigned int Configuration :: Object :: GetUInt( wstring PropertyName )
{
    return boost :: lexical_cast < unsigned int > ( this -> data[ PropertyName ] );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * GetString
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Getter for string properties
 *
 * @throw boost :: bad_lexical_cast
 *
 * @param wstring PropertyName Property name for return
 * @return double Object's property
*///*** *** *** *** *** *** *** *** *** *** *** *** *
wstring Configuration :: Object :: GetString( wstring PropertyName )
{
    return this -> data[ PropertyName ];
}


//- SECTION :: SET -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * SetSubObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Setter for subObject
 *
 * @param map < wstring, Object > SubObject
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Object :: SetSubObject( map < wstring, Object > SubObject )
{
    subObject = SubObject;
}


//- SECTION :: MAIN -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddProperty
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add property
 *
 * @param wstring Name
 * @param wstring Value
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Object :: AddProperty( wstring Name, wstring Value )
{
    this -> data.insert( 
        pair < wstring, wstring > ( 
            Name, 
            Value 
        ) 
    );
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * AddSubObject
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * Add subObjects
 *
 * @param Object SubObject
 * @return void
*///*** *** *** *** *** *** *** *** *** *** *** *** *
void Configuration :: Object :: AddSubObject( Configuration :: Object SubObject )
{
    this -> subObject.insert( 
        pair < wstring, Configuration :: Object > ( 
            SubObject.GetName(), 
            SubObject 
        ) 
    );
}


//- SECTION :: OPERATORS -//
/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param const Object & Orig
 * @return Object &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Object :: operator = ( const Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator =
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param Object & Orig
 * @return Object &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Object :: operator = ( Object & Orig )
{
    this -> name        = Orig.name;
    this -> data        = Orig.data;
    this -> subObject   = Orig.subObject;

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator +=
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param Object & Orig
 * @return Object &
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Object :: operator += ( Object & Orig )
{
    //- Merge properties -//
    for( map < wstring, wstring > :: iterator i = Orig.data.begin(); i != Orig.data.end(); ++i )
    {
        this -> data[ i -> first ] = i -> second;
    }

    //- Merge sub objects -//
    for( map < wstring, Configuration :: Object > :: iterator i = Orig.subObject.begin(); i != Orig.subObject.end(); ++i )
    {
        if( this -> subObject.find( i -> first ) != this -> subObject.end() )
        {
            //- Recursive merge sub objects -//
            this -> subObject[ i -> first ] += i -> second;
        }else
            {
                //- Add new sub objects -//
                this -> subObject[ i -> first ] = i -> second;
            }
    }

    return * this;
}

/** *** *** *** *** *** *** *** *** *** *** *** *** *
 * Operator []
 *  --- --- --- --- --- --- --- --- --- --- --- --- *
 * @param wstring Key
 * @return Object
*///*** *** *** *** *** *** *** *** *** *** *** *** *
Configuration :: Object & Configuration :: Object :: operator [] ( wstring Key )
{
    return this -> subObject[ Key ];
}
