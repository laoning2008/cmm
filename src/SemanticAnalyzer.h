/*
    SemanticAnalyzer.h
    ==================
        Class __SemanticAnalyzer header.
*/

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include "AST.h"

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::unordered_map;
using std::pair;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class __SemanticAnalyzer
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class __SemanticAnalyzer
{
    // Friend
    friend class Core;


public:

    // Constructor
    __SemanticAnalyzer(__AST *root = nullptr);


private:

    // Attribute
    __AST *__root;


    // Semantic Analysis
    unordered_map<string, unordered_map<string, pair<int, int>>> __semanticAnalysis() const;
};


}  // End namespace CMM