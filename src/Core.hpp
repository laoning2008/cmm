/*
    Core.hpp
    ========
        Class Core implementation.
*/

#pragma once

#include <string>
#include <iostream>
#include "popl.hpp"
#include "Core.h"
#include "LexicalAnalyzer.h"
#include "SyntaxAnalyzer.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"
#include "IO.h"
#include "VM.h"
#include "Constants.h"

using namespace popl;

namespace CMM
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::cout;
using std::endl;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Core::Core(int argc, char **argv):
    __ARGC(argc),
    __ARGV(argv) {}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::main()
{
    __main();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Input Arguments
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__inputArguments()
{
    OptionParser op(__Constants::__DESCRIPTION_STR);
    auto help_option = op.add<Switch>("h", "help", "show this help message and exit");
    auto input_option = op.add<Value<std::string>>("i", "i", "Input CMM File Path", "", &__cmmFilePath);
    auto output_option = op.add<Value<std::string>>("o", "o", "Output ASM File Path", "a.out", &__outputFilePath);
    auto run_option  = op.add<Value<std::string>>("r", "r", "Input ASM File Path (For Running)", "", &__asmFilePath);
    op.parse(__ARGC, __ARGV);
    
    if (help_option->is_set())
    {
        cout << op << endl;
        exit(1);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generate Code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__generateCode() const
{
    if (!__cmmFilePath.empty())
    {
        auto tokenList   = __LexicalAnalyzer(__cmmFilePath).__lexicalAnalysis();
        auto root        = __SyntaxAnalyzer(tokenList).__syntaxAnalysis();
        auto symbolTable = __SemanticAnalyzer(root).__semanticAnalysis();
        auto codeList    = __CodeGenerator(root, symbolTable).__generateCode();

        __IO::__outputInstruction(__outputFilePath, codeList);

        delete root;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Exec Code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__execCode() const
{
    if (!__asmFilePath.empty())
    {
        auto codeList = __IO::__parseInstructionFile(__asmFilePath);

        __VM(codeList).__run();
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Core::__main()
{
    __inputArguments();
    __generateCode();
    __execCode();
}


}  // End namespace CMM
