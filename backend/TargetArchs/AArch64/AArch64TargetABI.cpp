#include "AArch64TargetABI.hpp"

using namespace AArch64;

AArch64TargetABI::AArch64TargetABI(RegisterInfo *RI) {
  StackAlignment = 16;
  MaxStructSize = 128;

  // x0-x7
  for (int i = 32; i <= 39; i++)
    ArgumentRegisters.push_back(RI->GetRegister(i));

  // TODO: make maybe a new vector for callee saved GPR regs
  // so excluding special ones like sp, fp and lr
  // sp
  //CalleeSavedRegisters.push_back(RI->GetRegister(64));
  // fp
  //CalleeSavedRegisters.push_back(RI->GetRegister(61));
  // lr
  //CalleeSavedRegisters.push_back(RI->GetRegister(62));
  // x19-x28
  for (int i = 51; i <= 60; i++)
    CalleeSavedRegisters.push_back(RI->GetRegister(i));

  // w0-w7
  for (int i = 32; i <= 39; i++)
    CallerSavedRegisters.push_back(RI->GetRegister(i));
  // x9-x15
  for (int i = 41; i <= 47; i++)
    CallerSavedRegisters.push_back(RI->GetRegister(i));

  // x0-x7
  for (int i = 32; i <= 39; i++)
    ReturnRegisters.push_back(RI->GetRegister(i));
}
