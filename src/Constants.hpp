/*
    Constants.hpp
    =============
        Constants define.
*/

#pragma once

#include <string>
#include <unordered_map>
#include "Constants.h"
#include "TokenType.hpp"

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::unordered_map;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string __Constants::__DESCRIPTION_STR = R"(
========================================================================================================================

CMM
===

    CMM (C Minus Minus) Language Compiler And __VM.

========================================================================================================================

Usage)";


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Keyword Map
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const unordered_map<string, __TokenType> __Constants::__KEYWORD_MAP
{
    {"void",   __TokenType::__Void},
    {"int",    __TokenType::__Int},
    {"if",     __TokenType::__If},
    {"else",   __TokenType::__Else},
    {"while",  __TokenType::__While},
    {"return", __TokenType::__Return},
};


}  // End namespace CMM
