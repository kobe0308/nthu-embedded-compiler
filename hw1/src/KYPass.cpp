#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Analysis/MemoryDependenceAnalysis.h"

using namespace llvm;

namespace {
  struct KYPass: public ModulePass{
		static char ID; //Pass ID.
		KYPass() : ModulePass(ID) {}

		int originModuleSize;
		
		bool IsLoadOrStore(Instruction *I)
		{
		    if(isa<LoadInst>(I)) return true;
			else if(isa<StoreInst>(I)) return true;
			else return false;
		}


		virtual bool runOnModule(Module &M) {
			errs() << "start runOnModule";
			
			MemoryDependenceAnalysis *MDA = &getAnalysis<MemoryDependenceAnalysis>();

					for (Module:: iterator F = M.begin(); F!= M.end(); F++) {
				for (Function::iterator BB = (*F).begin(); BB != (*F).end(); BB++) {
					for (BasicBlock::iterator itrIns = (*BB).begin(); itrIns != (*BB).end(); itrIns++) {
						if(Instruction *ins = dyn_cast<Instruction>(itrIns)) {
							
							errs() << "----------------\n";
							
							if(IsLoadOrStore(ins)) {
								errs() << "is load or store!!!\n";

							}

							
							errs() << "ins: " <<  (*ins) << "\n";
							errs() << "# of operands: " << (*ins).getNumOperands() << "\n";
							
							for (int idx = 0; idx < (*ins).getNumOperands(); idx++)  {
								Value *val = (*ins).getOperand(idx);
								errs() << "operand " << idx << "\n";
								errs() << "val: " << (*val) << "\n";
								//errs() << "reg: " << (*ins).getOperand(idx).getReg() << "\n";
								//errs() << "imm: " << (*ins).getOperand(idx).getImm() << "\n";
							}

							//errs() << "\n \n got opcode ";
							//errs() << (*ins).getOpcode();
							//if((*ins).getName() == "") {
							//	for(User::op_iterator OI = (*ins).op_begin(), e = (*ins).op_end();OI!=e;++OI){
							//		Value *v = *OI;
							//		errs() << *v << "\n";
//
	//							}
			//				}
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
