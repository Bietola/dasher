#ifndef __DASHER_MODULE_H__
#define __DASHER_MODULE_H__

#include "../Common/ModuleSettings.h"
#include "DasherComponent.h"

class CDasherModule : public Dasher::CDasherComponent {
 public:
  CDasherModule(Dasher::CEventHandler * pEventHandler, CSettingsStore * pSettingsStore, long long int iID, int iType, const char *szName);

  virtual long long int GetID();
  virtual int GetType();
  virtual const char *GetName();

  virtual bool GetSettings(SModuleSettings **pSettings, int *iCount) {
    return false;
  };

  // Basic Reference counting

  ///
  /// Add a reference to the module
  ///

  virtual void Ref();

  /// 
  /// Remove a reference to the module
  ///

  virtual void Unref();

 private:
  long long int m_iID;
  int m_iType;
  int m_iRefCount;
  const char *m_szName;
};

#endif