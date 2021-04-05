#include "vector.h"

const std::string VectorException::iteratorInvalid{ "The element you're trying to access doesn't exist!" };
const std::string VectorException::wrongIterator{ "The iterator does not iterate over this vector!" };
const std::string VectorException::invalidComparison{ "The comparison criteria is invalid!" };