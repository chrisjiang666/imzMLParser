/*
 * 
 *  Copyright 2013 Alan Race
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *
 */
#include "Source.h"

namespace ImzML {

	const std::string Source::ionisationTypeID = "MS:1000008";
	const std::string Source::sourceAttributeID = "MS:1000482";
	const std::string Source::inletTypeID = "MS:1000007";
	const std::string Source::sampleStageID = "IMS:1000002";

	Source::Source(int order) {
		this->order = order;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Source& source) {
		for(int i = 0; i < source.indent; i++)
			os << source.indentString;
		os << "<source order=\"" << source.order << "\">" << std::endl;

		source.indent++;
		os << (MzMLContent)source;
		source.indent--;

		for(int i = 0; i < source.indent; i++)
			os << source.indentString;
		os << "</source>";

		return os;
	}

} /* namespace ImzML */
