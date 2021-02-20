#include "AArch64InstructionDefinitions.hpp"

using namespace AArch64;

AArch64InstructionDefinitions::IRToTargetInstrMap
    AArch64InstructionDefinitions::Instructions = [] {
      IRToTargetInstrMap ret;

      ret[ADD_rrr] = {ADD_rrr, 32, "add\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[ADD_rri] = {ADD_rri, 32, "add\t$1, $2, #$3", {GPR, GPR, UIMM12}};
      ret[SUB_rrr] = {SUB_rrr, 32, "sub\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[SUB_rri] = {SUB_rri, 32, "sub\t$1, $2, #$3", {GPR, GPR, UIMM12}};
      ret[SUBS] = {SUBS, 32, "subs\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[SDIV_rrr] = {SDIV_rrr, 32, "sdiv\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[SDIV_rri] = {SDIV_rri, 32, "sdiv\t$1, $2, #$3", {GPR, GPR, UIMM12}};
      ret[MUL_rrr] = {MUL_rri, 32, "mul\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[MUL_rri] = {MUL_rrr, 32, "mul\t$1, $2, #$3", {GPR, GPR, UIMM12}};
      ret[CMP_rr] = {CMP_rr, 32, "cmp\t$1, $2", {GPR, GPR}};
      ret[CMP_ri] = {CMP_ri, 32, "cmp\t$1, #$2", {GPR, UIMM12}};
      ret[CSET] = {CSET, 32, "cset\t$1, $2, $3", {GPR, GPR, GPR}};
      ret[LDR] = {LDR,
                  32,
                  "ldr\t$1, [$2, #$3]",
                  {GPR, GPR, SIMM12},
                  TargetInstruction::LOAD};
      ret[STR] = {STR,
                  32,
                  "str\t$1, [$2, #$3]",
                  {GPR, GPR, SIMM12},
                  TargetInstruction::STORE};
      ret[BLE] = {BLE, 32, "b.le\t$1", {SIMM21_LSB0}};
      ret[BEQ] = {BEQ, 32, "b.eq\t$1", {SIMM21_LSB0}};
      ret[B] = {B, 32, "b\t$1", {SIMM21_LSB0}};
      ret[RET] = {RET, 32, "ret", {}, TargetInstruction::RETURN};

      return ret;
    }();

TargetInstruction *
AArch64InstructionDefinitions::GetTargetInstr(unsigned Opcode) {
  if (0 == Instructions.count(Opcode))
    return nullptr;

  return &Instructions[Opcode];
}
