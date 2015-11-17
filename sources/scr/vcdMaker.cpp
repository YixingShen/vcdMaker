/*!
  @file vcdMaker.cpp

  The main module of the vcdMaker application.

  @par Full Description
  This is the vcdMaker executor.

  @if REVISION_HISTORY_INCLUDED
  @par Edit History
  @li [0]    wojciech.rynczuk@wp.pl    13-JAN-2015    Initial file revision.
  @endif

  @ingroup Main

  @par Copyright (c) MMXV Wojciech Rynczuk

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.

*/

/*!
    @defgroup Main Main

    @brief The main file of the vcdMaker.

    @par Full Description
    This is the main file of the vcdMaker.

*/

// SYSTEM INCLUDES
#include "stdafx.h"  // Precompiled header for the Windows platform
// Create the empty stdafx.h file for other platforms.
#include <iostream>  // std::cout
#include <fstream>   // std::ifstream
#include <string>    // std::getline

// C PROJECT INCLUDES
// (none)

// C++ PROJECT INCLUDES
#include "VCDTracer.h"     // VCDTracer
#include "SignalFactory.h" // SignalFactory
#include "CliParserImpl.h" // CliParser

// FORWARD REFERENCES
// (none)

/*!
  The vcdMaker main function.

  @par Full Description
  The vcdMaker main function.

  @param argc Number of arguments.
  @param argv The table of arguments.
  @return The execution status.
*/
int main(int argc, char *argv[])
{
    // Parse input parameters
    CLI::CliParserImpl CLI(argv, argv + argc);
    if (false == CLI.Validate())
    {
        return -1;
    }

    // Get parameters' values
    char *log_file = CLI.GetParamValue("-f");
    char *vcd_file = CLI.GetParamValue("-o");
    char *tbase = CLI.GetParamValue("-t");

    // Validate the time base.
    TRACER::VCDTracer::TimeUnit::_TimeUnit tunit = TRACER::VCDTracer::TimeUnit::invalid;
    if (0 == strcmp(tbase, "s"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::s;
    }
    if (0 == strcmp(tbase, "ms"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::ms;
    }
    if (0 == strcmp(tbase, "us"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::us;
    }
    if (0 == strcmp(tbase, "ns"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::ns;
    }
    if (0 == strcmp(tbase, "ps"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::ps;
    }
    if (0 == strcmp(tbase, "fs"))
    {
        tunit = TRACER::VCDTracer::TimeUnit::fs;
    }
    if (TRACER::VCDTracer::TimeUnit::invalid == tunit)
    {
        std::cout << "Invalid time base." << std::endl;
        return -1;
    }

    // Open the log file
    std::ifstream file(log_file);
    if (!file)
    {
        std::cout << "File " << log_file << " does not exist." << std::endl;
        return -1;
    }
    std::string line;

    // Create VCD tracer
    TRACER::VCDTracer  VcdTrace(vcd_file, tunit);

    // Create the signal factory
    CONSTRUCTION::SignalFactory signalFactory;

    // A signal
    SIGNAL::Signal *pSignal = NULL;

    // Process the log file
    while (std::getline(file, line))
    {
        pSignal = signalFactory.Create(line);
        if (pSignal != NULL)
        {
            VcdTrace.Log(pSignal);
        }
        else
        {
            std::cout << "Invalid log line: " << line << std::endl;
        }
    }

    // Create the VCD file
    VcdTrace.Dump();
    return 0;
}

