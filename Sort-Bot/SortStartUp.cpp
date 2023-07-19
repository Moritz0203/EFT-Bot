#include "SortStartUp.h"
#include "InitializeMovPrefix.h"
#include "PrefixProcessing.h"

void SortStartUp::StartUp() {
	PrefixProcessing prefixProcessing;

	InitializeMovPrefix::Initialize();
	prefixProcessing.CombinePrefixAndCase();

}
