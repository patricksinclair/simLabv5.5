// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME simLabDict

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
#include "TLab.h"
#include "TSim.h"
#include "TTheory.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TTheory(void *p = 0);
   static void *newArray_TTheory(Long_t size, void *p);
   static void delete_TTheory(void *p);
   static void deleteArray_TTheory(void *p);
   static void destruct_TTheory(void *p);
   static void streamer_TTheory(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTheory*)
   {
      ::TTheory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTheory >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTheory", ::TTheory::Class_Version(), "TTheory.h", 7,
                  typeid(::TTheory), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTheory::Dictionary, isa_proxy, 16,
                  sizeof(::TTheory) );
      instance.SetNew(&new_TTheory);
      instance.SetNewArray(&newArray_TTheory);
      instance.SetDelete(&delete_TTheory);
      instance.SetDeleteArray(&deleteArray_TTheory);
      instance.SetDestructor(&destruct_TTheory);
      instance.SetStreamerFunc(&streamer_TTheory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTheory*)
   {
      return GenerateInitInstanceLocal((::TTheory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TTheory*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TSim(void *p = 0);
   static void *newArray_TSim(Long_t size, void *p);
   static void delete_TSim(void *p);
   static void deleteArray_TSim(void *p);
   static void destruct_TSim(void *p);
   static void streamer_TSim(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSim*)
   {
      ::TSim *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TSim >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TSim", ::TSim::Class_Version(), "TSim.h", 8,
                  typeid(::TSim), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TSim::Dictionary, isa_proxy, 16,
                  sizeof(::TSim) );
      instance.SetNew(&new_TSim);
      instance.SetNewArray(&newArray_TSim);
      instance.SetDelete(&delete_TSim);
      instance.SetDeleteArray(&deleteArray_TSim);
      instance.SetDestructor(&destruct_TSim);
      instance.SetStreamerFunc(&streamer_TSim);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSim*)
   {
      return GenerateInitInstanceLocal((::TSim*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TSim*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TLab(void *p = 0);
   static void *newArray_TLab(Long_t size, void *p);
   static void delete_TLab(void *p);
   static void deleteArray_TLab(void *p);
   static void destruct_TLab(void *p);
   static void streamer_TLab(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TLab*)
   {
      ::TLab *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TLab >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TLab", ::TLab::Class_Version(), "TLab.h", 10,
                  typeid(::TLab), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TLab::Dictionary, isa_proxy, 16,
                  sizeof(::TLab) );
      instance.SetNew(&new_TLab);
      instance.SetNewArray(&newArray_TLab);
      instance.SetDelete(&delete_TLab);
      instance.SetDeleteArray(&deleteArray_TLab);
      instance.SetDestructor(&destruct_TLab);
      instance.SetStreamerFunc(&streamer_TLab);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TLab*)
   {
      return GenerateInitInstanceLocal((::TLab*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TLab*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TTheory::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTheory::Class_Name()
{
   return "TTheory";
}

//______________________________________________________________________________
const char *TTheory::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTheory*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTheory::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTheory*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTheory::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTheory*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTheory::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTheory*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TSim::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TSim::Class_Name()
{
   return "TSim";
}

//______________________________________________________________________________
const char *TSim::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSim*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TSim::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TSim*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TSim::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSim*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TSim::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TSim*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TLab::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TLab::Class_Name()
{
   return "TLab";
}

//______________________________________________________________________________
const char *TLab::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TLab*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TLab::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TLab*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TLab::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TLab*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TLab::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TLab*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TTheory::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTheory.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, TTheory::IsA());
   } else {
      R__c = R__b.WriteVersion(TTheory::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTheory(void *p) {
      return  p ? new(p) ::TTheory : new ::TTheory;
   }
   static void *newArray_TTheory(Long_t nElements, void *p) {
      return p ? new(p) ::TTheory[nElements] : new ::TTheory[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTheory(void *p) {
      delete ((::TTheory*)p);
   }
   static void deleteArray_TTheory(void *p) {
      delete [] ((::TTheory*)p);
   }
   static void destruct_TTheory(void *p) {
      typedef ::TTheory current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTheory(TBuffer &buf, void *obj) {
      ((::TTheory*)obj)->::TTheory::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTheory

//______________________________________________________________________________
void TSim::Streamer(TBuffer &R__b)
{
   // Stream an object of class TSim.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      rootFile.Streamer(R__b);
      R__b >> theFile;
      R__b >> theTree;
      R__b >> nHits;
      R__b >> nParticles;
      R__b.ReadStaticArray((Long64_t*)eventNumber);
      R__b.ReadStaticArray((char*)detector);
      R__b.ReadStaticArray((int*)detectorUnitID);
      R__b.ReadStaticArray((float*)energy);
      R__b.ReadStaticArray((float*)x);
      R__b.ReadStaticArray((float*)y);
      R__b.ReadStaticArray((float*)z);
      R__b.ReadStaticArray((float*)minTime);
      R__b.ReadStaticArray((float*)maxTime);
      R__b.ReadStaticArray((int*)nOriginalTracks);
      R__b.ReadStaticArray((int*)originalParticleNumber);
      R__b.ReadStaticArray((int*)nTracks);
      R__b.ReadStaticArray((int*)particleNumber);
      R__b >> nHitsC;
      R__b >> nHitsW;
      R__b >> eventType;
      R__b.ReadStaticArray((float*)iC);
      R__b.ReadStaticArray((float*)iW);
      R__b >> i1P1;
      R__b >> i1P2;
      R__b >> sinogramR;
      R__b >> sinogramPhi;
      R__b >> meanHitAngle;
      R__b >> energy1P1;
      R__b >> energy1P2;
      R__b >> i2P1;
      R__b >> i2P2;
      R__b >> energy2P1;
      R__b >> energy2P2;
      R__b >> thetaP1E;
      R__b >> thetaP2E;
      R__b >> thetaP1V;
      R__b >> thetaP2V;
      R__b >> thetaP1VTrue;
      R__b >> thetaP2VTrue;
      R__b >> phiP1;
      R__b >> phiP2;
      R__b >> dPhi;
      p3P1Lab.Streamer(R__b);
      p3P2Lab.Streamer(R__b);
      LOR.Streamer(R__b);
      LORXY.Streamer(R__b);
      v3P1Lab.Streamer(R__b);
      v3P2Lab.Streamer(R__b);
      midpointXY.Streamer(R__b);
      midpoint.Streamer(R__b);
      v3ScP1Lab.Streamer(R__b);
      v3ScP2Lab.Streamer(R__b);
      v3P1Event.Streamer(R__b);
      v3P2Event.Streamer(R__b);
      R__b >> b_nHits;
      R__b >> b_nParticles;
      R__b >> b_eventNumber;
      R__b >> b_detector;
      R__b >> b_detectorUnitID;
      R__b >> b_energy;
      R__b >> b_x;
      R__b >> b_y;
      R__b >> b_z;
      R__b >> b_nOriginalTracks;
      R__b >> b_originalParticleNumber;
      R__b >> b_nTracks;
      R__b >> b_nHitsC;
      R__b >> b_nHitsW;
      R__b >> b_eventType;
      R__b >> b_iC;
      R__b >> b_iW;
      R__b >> b_i1P1;
      R__b >> b_i1P2;
      R__b >> b_sinogramR;
      R__b >> b_sinogramPhi;
      R__b >> b_meanHitAngle;
      R__b >> b_energy1P1;
      R__b >> b_energy1P2;
      R__b >> b_i2P1;
      R__b >> b_i2P2;
      R__b >> b_energy2P1;
      R__b >> b_energy2P2;
      R__b >> b_thetaP1E;
      R__b >> b_thetaP2E;
      R__b >> b_thetaP1V;
      R__b >> b_thetaP2V;
      R__b >> b_thetaP1VTrue;
      R__b >> b_thetaP2VTrue;
      R__b >> b_phiP1;
      R__b >> b_phiP2;
      R__b >> b_dPhi;
      R__b.ReadStaticArray((float*)asymm90);
      R__b.ReadStaticArray((float*)asyer90);
      R__b.ReadStaticArray((float*)asymmCr90);
      R__b.ReadStaticArray((float*)asyerCr90);
      R__b.CheckByteCount(R__s, R__c, TSim::IsA());
   } else {
      R__c = R__b.WriteVersion(TSim::IsA(), kTRUE);
      TObject::Streamer(R__b);
      rootFile.Streamer(R__b);
      R__b << theFile;
      R__b << theTree;
      R__b << nHits;
      R__b << nParticles;
      R__b.WriteArray(eventNumber, 32);
      R__b.WriteArray(detector, 32);
      R__b.WriteArray(detectorUnitID, 32);
      R__b.WriteArray(energy, 32);
      R__b.WriteArray(x, 32);
      R__b.WriteArray(y, 32);
      R__b.WriteArray(z, 32);
      R__b.WriteArray(minTime, 32);
      R__b.WriteArray(maxTime, 32);
      R__b.WriteArray(nOriginalTracks, 32);
      R__b.WriteArray(originalParticleNumber, 32);
      R__b.WriteArray(nTracks, 32);
      R__b.WriteArray((int*)particleNumber, 512);
      R__b << nHitsC;
      R__b << nHitsW;
      R__b << eventType;
      R__b.WriteArray(iC, 32);
      R__b.WriteArray(iW, 32);
      R__b << i1P1;
      R__b << i1P2;
      R__b << sinogramR;
      R__b << sinogramPhi;
      R__b << meanHitAngle;
      R__b << energy1P1;
      R__b << energy1P2;
      R__b << i2P1;
      R__b << i2P2;
      R__b << energy2P1;
      R__b << energy2P2;
      R__b << thetaP1E;
      R__b << thetaP2E;
      R__b << thetaP1V;
      R__b << thetaP2V;
      R__b << thetaP1VTrue;
      R__b << thetaP2VTrue;
      R__b << phiP1;
      R__b << phiP2;
      R__b << dPhi;
      p3P1Lab.Streamer(R__b);
      p3P2Lab.Streamer(R__b);
      LOR.Streamer(R__b);
      LORXY.Streamer(R__b);
      v3P1Lab.Streamer(R__b);
      v3P2Lab.Streamer(R__b);
      midpointXY.Streamer(R__b);
      midpoint.Streamer(R__b);
      v3ScP1Lab.Streamer(R__b);
      v3ScP2Lab.Streamer(R__b);
      v3P1Event.Streamer(R__b);
      v3P2Event.Streamer(R__b);
      R__b << b_nHits;
      R__b << b_nParticles;
      R__b << b_eventNumber;
      R__b << b_detector;
      R__b << b_detectorUnitID;
      R__b << b_energy;
      R__b << b_x;
      R__b << b_y;
      R__b << b_z;
      R__b << b_nOriginalTracks;
      R__b << b_originalParticleNumber;
      R__b << b_nTracks;
      R__b << b_nHitsC;
      R__b << b_nHitsW;
      R__b << b_eventType;
      R__b << b_iC;
      R__b << b_iW;
      R__b << b_i1P1;
      R__b << b_i1P2;
      R__b << b_sinogramR;
      R__b << b_sinogramPhi;
      R__b << b_meanHitAngle;
      R__b << b_energy1P1;
      R__b << b_energy1P2;
      R__b << b_i2P1;
      R__b << b_i2P2;
      R__b << b_energy2P1;
      R__b << b_energy2P2;
      R__b << b_thetaP1E;
      R__b << b_thetaP2E;
      R__b << b_thetaP1V;
      R__b << b_thetaP2V;
      R__b << b_thetaP1VTrue;
      R__b << b_thetaP2VTrue;
      R__b << b_phiP1;
      R__b << b_phiP2;
      R__b << b_dPhi;
      R__b.WriteArray(asymm90, 32);
      R__b.WriteArray(asyer90, 32);
      R__b.WriteArray(asymmCr90, 32);
      R__b.WriteArray(asyerCr90, 32);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSim(void *p) {
      return  p ? new(p) ::TSim : new ::TSim;
   }
   static void *newArray_TSim(Long_t nElements, void *p) {
      return p ? new(p) ::TSim[nElements] : new ::TSim[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSim(void *p) {
      delete ((::TSim*)p);
   }
   static void deleteArray_TSim(void *p) {
      delete [] ((::TSim*)p);
   }
   static void destruct_TSim(void *p) {
      typedef ::TSim current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TSim(TBuffer &buf, void *obj) {
      ((::TSim*)obj)->::TSim::Streamer(buf);
   }
} // end of namespace ROOT for class ::TSim

//______________________________________________________________________________
void TLab::Streamer(TBuffer &R__b)
{
   // Stream an object of class TLab.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> runNumberInt;
      R__b >> inData;
      R__b >> rootFileRawData;
      R__b >> rawDataTree;
      R__b >> rootFileCalData;
      R__b >> calDataTree;
      textFileName.Streamer(R__b);
      rootFileRawName.Streamer(R__b);
      rootFileCalName.Streamer(R__b);
      R__b >> canvas1;
      R__b >> canvas2;
      int R__i;
      for (R__i = 0; R__i < 10; R__i++)
         R__b >> hQ[R__i];
      for (R__i = 0; R__i < 10; R__i++)
         R__b >> hT[R__i];
      R__b >> eventNumber;
      R__b.ReadStaticArray((float*)Q);
      R__b.ReadStaticArray((float*)T);
      R__b.ReadStaticArray((float*)pedQ);
      R__b.ReadStaticArray((float*)phoQ);
      for (R__i = 0; R__i < 10; R__i++)
         R__b >> hEA[R__i];
      for (R__i = 0; R__i < 10; R__i++)
         R__b >> hEB[R__i];
      R__b.ReadStaticArray((float*)QA);
      R__b.ReadStaticArray((float*)QB);
      R__b.ReadStaticArray((float*)EA);
      R__b.ReadStaticArray((float*)EB);
      R__b.ReadStaticArray((float*)TA);
      R__b.ReadStaticArray((float*)TB);
      R__b.ReadStaticArray((float*)tHA);
      R__b.ReadStaticArray((float*)tHB);
      R__b >> Asym;
      R__b >> AsymErr;
      R__b >> R000;
      R__b >> R090;
      R__b >> AR;
      R__b >> BR;
      R__b >> type;
      R__b >> simData;
      R__b >> npeaks;
      R__b.CheckByteCount(R__s, R__c, TLab::IsA());
   } else {
      R__c = R__b.WriteVersion(TLab::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << runNumberInt;
      R__b << inData;
      R__b << rootFileRawData;
      R__b << rawDataTree;
      R__b << rootFileCalData;
      R__b << calDataTree;
      textFileName.Streamer(R__b);
      rootFileRawName.Streamer(R__b);
      rootFileCalName.Streamer(R__b);
      R__b << canvas1;
      R__b << canvas2;
      int R__i;
      for (R__i = 0; R__i < 10; R__i++)
         R__b << (TObject*)hQ[R__i];
      for (R__i = 0; R__i < 10; R__i++)
         R__b << (TObject*)hT[R__i];
      R__b << eventNumber;
      R__b.WriteArray(Q, 10);
      R__b.WriteArray(T, 10);
      R__b.WriteArray(pedQ, 10);
      R__b.WriteArray(phoQ, 10);
      for (R__i = 0; R__i < 10; R__i++)
         R__b << (TObject*)hEA[R__i];
      for (R__i = 0; R__i < 10; R__i++)
         R__b << (TObject*)hEB[R__i];
      R__b.WriteArray(QA, 10);
      R__b.WriteArray(QB, 10);
      R__b.WriteArray(EA, 10);
      R__b.WriteArray(EB, 10);
      R__b.WriteArray(TA, 10);
      R__b.WriteArray(TB, 10);
      R__b.WriteArray(tHA, 10);
      R__b.WriteArray(tHB, 10);
      R__b << Asym;
      R__b << AsymErr;
      R__b << R000;
      R__b << R090;
      R__b << AR;
      R__b << BR;
      R__b << type;
      R__b << simData;
      R__b << npeaks;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TLab(void *p) {
      return  p ? new(p) ::TLab : new ::TLab;
   }
   static void *newArray_TLab(Long_t nElements, void *p) {
      return p ? new(p) ::TLab[nElements] : new ::TLab[nElements];
   }
   // Wrapper around operator delete
   static void delete_TLab(void *p) {
      delete ((::TLab*)p);
   }
   static void deleteArray_TLab(void *p) {
      delete [] ((::TLab*)p);
   }
   static void destruct_TLab(void *p) {
      typedef ::TLab current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TLab(TBuffer &buf, void *obj) {
      ((::TLab*)obj)->::TLab::Streamer(buf);
   }
} // end of namespace ROOT for class ::TLab

namespace {
  void TriggerDictionaryInitialization_simLabDict_Impl() {
    static const char* headers[] = {
"TLab.h",
"TSim.h",
"TTheory.h",
0
    };
    static const char* includePaths[] = {
"/home/psinclair/Programs/ROOT/root-6.08.04-build/include",
"/home/psinclair/Programs/ROOT/root-6.08.04-build/include",
"/home/psinclair/MastersProject/SimLab5.5/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "simLabDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TTheory.h")))  __attribute__((annotate("$clingAutoload$TLab.h")))  TTheory;
class __attribute__((annotate("$clingAutoload$TSim.h")))  __attribute__((annotate("$clingAutoload$TLab.h")))  TSim;
class __attribute__((annotate("$clingAutoload$TLab.h")))  TLab;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "simLabDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "TLab.h"
#include "TSim.h"
#include "TTheory.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TLab", payloadCode, "@",
"TSim", payloadCode, "@",
"TTheory", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("simLabDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_simLabDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_simLabDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_simLabDict() {
  TriggerDictionaryInitialization_simLabDict_Impl();
}
