#ifndef REFMODE_ENGINE_HPP__
#define REFMODE_ENGINE_HPP__

#include <string>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>

namespace cclyzer {

    namespace refmode {
        /* Type aliases */
        typedef std::string refmode_t;
    }

    typedef refmode::refmode_t refmode_t;


    class RefmodeEngine {
      public:
        RefmodeEngine();
        ~RefmodeEngine();

        // Context modifying methods
        void enterContext(const llvm::Value *val);
        void exitContext();
        void enterModule(const llvm::Module *Mod, const std::string &path);
        void exitModule();

        // Compute refmode for obj, given some context state
        template<typename T>
        refmode_t refmode(const T& obj) const;

      private:
        /* Opaque Pointer Idiom */
        class Impl;
        mutable Impl *impl;
    };


    //-------------------------------------------------------------------
    // Explicit instantiation declarations
    //-------------------------------------------------------------------

    extern template refmode_t
    RefmodeEngine::refmode<llvm::Type>(const llvm::Type & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::Instruction>(const llvm::Instruction & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::Constant>(const llvm::Constant & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::BasicBlock>(const llvm::BasicBlock & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::Function>(const llvm::Function & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::InlineAsm>(const llvm::InlineAsm & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::GlobalValue>(const llvm::GlobalValue & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::Value>(const llvm::Value & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::GlobalValue::LinkageTypes>(
        const llvm::GlobalValue::LinkageTypes & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::GlobalValue::VisibilityTypes>(
        const llvm::GlobalValue::VisibilityTypes & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::GlobalVariable::ThreadLocalMode>(
        const llvm::GlobalVariable::ThreadLocalMode &) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::CallingConv::ID>(
        const llvm::CallingConv::ID & ) const;

    extern template refmode_t
    RefmodeEngine::refmode<llvm::AtomicOrdering>(
        const llvm::AtomicOrdering & ) const;

} // end of namespace cclyzer

#endif /* REFMODE_ENGINE_HPP__ */
