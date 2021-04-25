#include "Repository.h"
#include <string>
const std::string RepoException::drugExists{ "Drug already exists!" };
const std::string RepoException::drugDoesntExist{ "Drug doesn't exist!" };
const std::string RepoException::fileFail{ "File doesn't exist!" };
const std::string RepoException::probabilityException{ "Exception thrown because you are unlucky!" };