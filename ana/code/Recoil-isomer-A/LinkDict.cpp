// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME LinkDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "tree.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Energy__Dictionary();
   static void Energy__TClassManip(TClass*);
   static void *new_Energy_(void *p = 0);
   static void *newArray_Energy_(Long_t size, void *p);
   static void delete_Energy_(void *p);
   static void deleteArray_Energy_(void *p);
   static void destruct_Energy_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Energy_*)
   {
      ::Energy_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Energy_));
      static ::ROOT::TGenericClassInfo 
         instance("Energy_", "tree.h", 10,
                  typeid(::Energy_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Energy__Dictionary, isa_proxy, 4,
                  sizeof(::Energy_) );
      instance.SetNew(&new_Energy_);
      instance.SetNewArray(&newArray_Energy_);
      instance.SetDelete(&delete_Energy_);
      instance.SetDeleteArray(&deleteArray_Energy_);
      instance.SetDestructor(&destruct_Energy_);

      ::ROOT::AddClassAlternate("Energy_","Data");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Energy_*)
   {
      return GenerateInitInstanceLocal((::Energy_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Energy_*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Energy__Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Energy_*)0x0)->GetClass();
      Energy__TClassManip(theClass);
   return theClass;
   }

   static void Energy__TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Imp_Dictionary();
   static void Imp_TClassManip(TClass*);
   static void *new_Imp(void *p = 0);
   static void *newArray_Imp(Long_t size, void *p);
   static void delete_Imp(void *p);
   static void deleteArray_Imp(void *p);
   static void destruct_Imp(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Imp*)
   {
      ::Imp *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Imp));
      static ::ROOT::TGenericClassInfo 
         instance("Imp", "tree.h", 21,
                  typeid(::Imp), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Imp_Dictionary, isa_proxy, 0,
                  sizeof(::Imp) );
      instance.SetNew(&new_Imp);
      instance.SetNewArray(&newArray_Imp);
      instance.SetDelete(&delete_Imp);
      instance.SetDeleteArray(&deleteArray_Imp);
      instance.SetDestructor(&destruct_Imp);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Imp*)
   {
      return GenerateInitInstanceLocal((::Imp*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Imp*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Imp_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Imp*)0x0)->GetClass();
      Imp_TClassManip(theClass);
   return theClass;
   }

   static void Imp_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Decay_Dictionary();
   static void Decay_TClassManip(TClass*);
   static void *new_Decay(void *p = 0);
   static void *newArray_Decay(Long_t size, void *p);
   static void delete_Decay(void *p);
   static void deleteArray_Decay(void *p);
   static void destruct_Decay(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Decay*)
   {
      ::Decay *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Decay));
      static ::ROOT::TGenericClassInfo 
         instance("Decay", "tree.h", 39,
                  typeid(::Decay), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Decay_Dictionary, isa_proxy, 0,
                  sizeof(::Decay) );
      instance.SetNew(&new_Decay);
      instance.SetNewArray(&newArray_Decay);
      instance.SetDelete(&delete_Decay);
      instance.SetDeleteArray(&deleteArray_Decay);
      instance.SetDestructor(&destruct_Decay);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Decay*)
   {
      return GenerateInitInstanceLocal((::Decay*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Decay*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Decay_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Decay*)0x0)->GetClass();
      Decay_TClassManip(theClass);
   return theClass;
   }

   static void Decay_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Energy_(void *p) {
      return  p ? new(p) ::Energy_ : new ::Energy_;
   }
   static void *newArray_Energy_(Long_t nElements, void *p) {
      return p ? new(p) ::Energy_[nElements] : new ::Energy_[nElements];
   }
   // Wrapper around operator delete
   static void delete_Energy_(void *p) {
      delete ((::Energy_*)p);
   }
   static void deleteArray_Energy_(void *p) {
      delete [] ((::Energy_*)p);
   }
   static void destruct_Energy_(void *p) {
      typedef ::Energy_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Energy_

namespace ROOT {
   // Wrappers around operator new
   static void *new_Imp(void *p) {
      return  p ? new(p) ::Imp : new ::Imp;
   }
   static void *newArray_Imp(Long_t nElements, void *p) {
      return p ? new(p) ::Imp[nElements] : new ::Imp[nElements];
   }
   // Wrapper around operator delete
   static void delete_Imp(void *p) {
      delete ((::Imp*)p);
   }
   static void deleteArray_Imp(void *p) {
      delete [] ((::Imp*)p);
   }
   static void destruct_Imp(void *p) {
      typedef ::Imp current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Imp

namespace ROOT {
   // Wrappers around operator new
   static void *new_Decay(void *p) {
      return  p ? new(p) ::Decay : new ::Decay;
   }
   static void *newArray_Decay(Long_t nElements, void *p) {
      return p ? new(p) ::Decay[nElements] : new ::Decay[nElements];
   }
   // Wrapper around operator delete
   static void delete_Decay(void *p) {
      delete ((::Decay*)p);
   }
   static void deleteArray_Decay(void *p) {
      delete [] ((::Decay*)p);
   }
   static void destruct_Decay(void *p) {
      typedef ::Decay current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Decay

namespace ROOT {
   static TClass *vectorlEEnergy_gR_Dictionary();
   static void vectorlEEnergy_gR_TClassManip(TClass*);
   static void *new_vectorlEEnergy_gR(void *p = 0);
   static void *newArray_vectorlEEnergy_gR(Long_t size, void *p);
   static void delete_vectorlEEnergy_gR(void *p);
   static void deleteArray_vectorlEEnergy_gR(void *p);
   static void destruct_vectorlEEnergy_gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Energy_>*)
   {
      vector<Energy_> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Energy_>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Energy_>", -2, "vector", 210,
                  typeid(vector<Energy_>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEEnergy_gR_Dictionary, isa_proxy, 4,
                  sizeof(vector<Energy_>) );
      instance.SetNew(&new_vectorlEEnergy_gR);
      instance.SetNewArray(&newArray_vectorlEEnergy_gR);
      instance.SetDelete(&delete_vectorlEEnergy_gR);
      instance.SetDeleteArray(&deleteArray_vectorlEEnergy_gR);
      instance.SetDestructor(&destruct_vectorlEEnergy_gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Energy_> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Energy_>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEEnergy_gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Energy_>*)0x0)->GetClass();
      vectorlEEnergy_gR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEEnergy_gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEEnergy_gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Energy_> : new vector<Energy_>;
   }
   static void *newArray_vectorlEEnergy_gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Energy_>[nElements] : new vector<Energy_>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEEnergy_gR(void *p) {
      delete ((vector<Energy_>*)p);
   }
   static void deleteArray_vectorlEEnergy_gR(void *p) {
      delete [] ((vector<Energy_>*)p);
   }
   static void destruct_vectorlEEnergy_gR(void *p) {
      typedef vector<Energy_> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Energy_>

namespace {
  void TriggerDictionaryInitialization_LinkDict_Impl() {
    static const char* headers[] = {
"tree.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root-v6.16/include/root",
"/home/huangh/58Ni+96Ru/Recoil-isomer-A/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "LinkDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
struct __attribute__((annotate("$clingAutoload$tree.h")))  Energy_;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
struct __attribute__((annotate("$clingAutoload$tree.h")))  Imp;
struct __attribute__((annotate("$clingAutoload$tree.h")))  Decay;
typedef struct Energy_ Energy __attribute__((annotate("$clingAutoload$tree.h"))) ;
typedef Energy Data __attribute__((annotate("$clingAutoload$tree.h"))) ;
typedef struct Imp Imp __attribute__((annotate("$clingAutoload$tree.h"))) ;
typedef struct Decay Decay __attribute__((annotate("$clingAutoload$tree.h"))) ;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "LinkDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "tree.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Data", payloadCode, "@",
"Decay", payloadCode, "@",
"Energy_", payloadCode, "@",
"Imp", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("LinkDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_LinkDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_LinkDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_LinkDict() {
  TriggerDictionaryInitialization_LinkDict_Impl();
}
