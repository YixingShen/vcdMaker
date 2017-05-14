/// @file VcdExceptionList.h
///
/// The file lists errors and warnings which might occur within vcdMaker
/// applications.
///
/// @par Full Description
/// vcdMaker errors and warnings.
///
/// @ingroup Exception
///
/// @par Copyright (c) 2017 vcdMaker team
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
/// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
/// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
/// IN THE SOFTWARE.

#pragma once

namespace EXCEPTION
{
    /// The list of warnings.
    namespace Warning
    {
        /// Synchronization time out of bounds.
        const uint32_t SYNCHRONIZATION_TIME_OUT_OF_BOUNDS = 1U;

        /// Timestamp out of bounds.
        const uint32_t TIMESTAMP_OUT_OF_BOUNDS = 2U;
    };

    /// The list of errors.
    namespace Error
    {
        /// Cannot open the file.
        const uint32_t CANNOT_OPEN_FILE = 1U;

        /// Conflicting signals names.
        const uint32_t CONFLICTING_SIGNAL_NAMES = 2U;

        /// Invalid time unit.
        const uint32_t INVALID_TIME_UNIT = 3U;

        /// Synchronization point out of bounds.
        const uint32_t SYNCHRONIZATION_POINT_OUT_OF_BOUNDS = 4U;

        /// Invalid log file format.
        const uint32_t INVALID_LOG_FILE_FORMAT = 5U;

        /// Invalid synchronization point value.
        const uint32_t INVALID_SYNCHRONIZATION_POINT_VALUE = 6U;

        /// Invalid number of the source parameters.
        const uint32_t INVALID_NUMBER_OF_SOURCE_PARAMS = 7U;

        /// Logic errors which shall never happen start from 9000.

        /// Invalid signal source.
        const uint32_t INVALID_SIGNAL_SOURCE = 9000U;

        /// Cannot find the source signal name.
        const uint32_t CANNOT_FIND_SOURCE_SIGNAL_NAME = 9001U;

        /// Too many signal sources.
        const uint32_t TOO_MANY_SIGNAL_SOURCES = 9002U;
    };
}