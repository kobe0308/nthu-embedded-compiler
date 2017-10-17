#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/ADT/Statistic.h"

using namespace llvm;

namespace {
	struct KYPass: public ModulePass{
		static char ID; //Pass ID.
		KYPass() : ModulePass(ID) {}

		int originModuleSize;
		
		virtual bool runOnModule(Module &M) {
		
			return false;
		}

	};
};

char KYPass::ID = 0;

static RegisterPass<KYPass> GS("KYPass","Simple demo");
