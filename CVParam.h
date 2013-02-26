#ifndef CVPARAM_H
#define CVPARAM_H

#include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>

#include "ImzMLCV.h"
#include "OBOTerm.h"

namespace ImzML {

	class CVParam
	{
		protected:
			boost::shared_ptr<ImzML::OBOTerm> term;
			std::string value;

			boost::shared_ptr<ImzML::OBOTerm> units;

		public:
			// Copy constructor
			CVParam(const CVParam& cvParam);

			CVParam(boost::shared_ptr<ImzML::OBOTerm> term, std::string value);
			CVParam(boost::shared_ptr<ImzML::OBOTerm> term, std::string value, boost::shared_ptr<ImzML::OBOTerm> units);

			CVParam(std::string accession, std::string name, std::string value);
			CVParam(std::string accession, std::string name, std::string value, std::string unitAccession, std::string unitName);

			~CVParam();

			std::string getAccession() { return term->getID(); }
			std::string getName() { return term->getName(); }
			boost::shared_ptr<ImzML::OBOTerm> getTerm();

			std::string getValue() { return value; }

			std::string getUnitAccession() { return units->getID(); }
			std::string getUnitName() { return units->getName(); }

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::CVParam& obj);
			friend std::ostream& operator<<(std::ostream& os, const ImzML::CVParam* obj);

			friend bool operator==(const CVParam &cvParam1, const CVParam &cvParam2);
			friend bool operator!=(const CVParam &cvParam1, const CVParam &cvParam2);

			void operator=(const CVParam &cvParam);
	};

	inline std::ostream& operator<<(std::ostream& os, const ImzML::CVParam& obj) {
		os << "<cvParam cvRef=\"" << obj.term->getNamespace() << "\" accession=\"" << obj.term->getID() << "\" name=\"" << obj.term->getName() << "\" value=\"" << obj.value << "\"";

		if(obj.units != NULL) {
			os << " unitCvRef=\"" << obj.units->getNamespace() << "\" unitAccession=\"" << obj.units->getID() << "\" unitName=\"" << obj.units->getName() << "\"";
		}

		os << " />";

		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ImzML::CVParam* obj) {
		return os << *obj;
	}

} /* namespace ImzML */


#endif // CVPARAM_H
