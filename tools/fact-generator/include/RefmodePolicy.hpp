#ifndef REFMODE_POLICY_HPP__
#define REFMODE_POLICY_HPP__

#include <string>
#include <llvm/IR/Type.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

/* Type aliases */
typedef std::string refmode_t;

class RefmodePolicy {
  public:
    RefmodePolicy();
    ~RefmodePolicy();

    refmode_t refmodeOf(llvm::GlobalValue::LinkageTypes LT) const;
    refmode_t refmodeOf(llvm::GlobalValue::VisibilityTypes Vis) const;
    refmode_t refmodeOf(llvm::GlobalVariable::ThreadLocalMode TLM) const;
    refmode_t refmodeOf(llvm::CallingConv::ID CC) const;
    refmode_t refmodeOf(const llvm::Type *type) const;
    refmode_t refmodeOf(const llvm::Value * Val, const llvm::Module *Mod = 0) const;

  private:
    /* Opaque Pointer Idiom */
    class Impl;
    Impl *impl;
};

#endif /* REFMODE_POLICY_HPP__ */