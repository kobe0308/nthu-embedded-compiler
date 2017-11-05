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
			errs() << "start runOnModule";
			
			for (Module:: iterator F = M.begin(); F!= M.end(); F++) {
				for (Function::iterator BB = (*F).begin(); BB != (*F).end(); BB++) {
					for (BasicBlock::iterator itrIns = (*BB).begin(); itrIns != (*BB).end(); itrIns++) {
						if(Instruction *ins = dyn_cast<Instruction>(itrIns)) {
							errs() << "\n \n got opcode ";
							errs() << (*ins).getOpcodeName();
						}							
					}
				}	
			
			
			}

			
				
			return false;
		}
  };
};

char KYPass::ID = 0;
static RegisterPass<KYPass> GS("KYPass","Simple demo");
