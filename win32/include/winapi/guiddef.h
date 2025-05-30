/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido GUID_DEFINED
#Defina GUID_DEFINED
Tipo Estrutura _GUID {
  SemSinal Longo Data1;
  SemSinal Curto Data2;
  SemSinal Curto Data3;
  SemSinal Caractere Data4[8 ];
} GUID;
#FimSe

#SenãoDefinido UUID_DEFINED
#Defina UUID_DEFINED
Tipo GUID UUID;
#FimSe

#SenãoDefinido FAR
#Defina FAR
#FimSe

#SenãoDefinido DECLSPEC_SELECTANY
#Defina DECLSPEC_SELECTANY __declspec(selectany)
#FimSe

#SenãoDefinido EXTERN_C
#SeDefinido __cplusplus
#Defina EXTERN_C Externo "C"
#Senão
#Defina EXTERN_C Externo
#FimSe
#FimSe

#SeDefinido DEFINE_GUID
#Indefinido DEFINE_GUID
#FimSe

#SeDefinido INITGUID
#SeDefinido __cplusplus
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C Constante GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#Senão
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) Constante GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#FimSe
#Senão
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C Constante GUID name
#FimSe

#Defina DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#SenãoDefinido _GUIDDEF_H_
#Defina _GUIDDEF_H_

#SenãoDefinido __LPGUID_DEFINED__
#Defina __LPGUID_DEFINED__
Tipo GUID *LPGUID;
#FimSe

#SenãoDefinido __LPCGUID_DEFINED__
#Defina __LPCGUID_DEFINED__
Tipo Constante GUID *LPCGUID;
#FimSe

#SenãoDefinido __IID_DEFINED__
#Defina __IID_DEFINED__

Tipo GUID IID;
Tipo IID *LPIID;
#Defina IID_NULL GUID_NULL
#Defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
Tipo GUID CLSID;
Tipo CLSID *LPCLSID;
#Defina CLSID_NULL GUID_NULL
#Defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
Tipo GUID FMTID;
Tipo FMTID *LPFMTID;
#Defina FMTID_NULL GUID_NULL
#Defina IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#SeDefinido __midl_proxy
#Defina __MIDL_CONST
#Senão
#Defina __MIDL_CONST Constante
#FimSe

#SenãoDefinido _REFGUID_DEFINED
#Defina _REFGUID_DEFINED
#SeDefinido __cplusplus
#Defina REFGUID Constante GUID &
#Senão
#Defina REFGUID Constante GUID *__MIDL_CONST
#FimSe
#FimSe

#SenãoDefinido _REFIID_DEFINED
#Defina _REFIID_DEFINED
#SeDefinido __cplusplus
#Defina REFIID Constante IID &
#Senão
#Defina REFIID Constante IID *__MIDL_CONST
#FimSe
#FimSe

#SenãoDefinido _REFCLSID_DEFINED
#Defina _REFCLSID_DEFINED
#SeDefinido __cplusplus
#Defina REFCLSID Constante IID &
#Senão
#Defina REFCLSID Constante IID *__MIDL_CONST
#FimSe
#FimSe

#SenãoDefinido _REFFMTID_DEFINED
#Defina _REFFMTID_DEFINED
#SeDefinido __cplusplus
#Defina REFFMTID Constante IID &
#Senão
#Defina REFFMTID Constante IID *__MIDL_CONST
#FimSe
#FimSe
#FimSe

#SenãoDefinido _SYS_GUID_OPERATORS_
#Defina _SYS_GUID_OPERATORS_
#Inclua <string.h>

#SeDefinido __cplusplus
EmLinha Inteiro InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  Retorno (((SemSinal Longo *) &rguid1)[0]==((SemSinal Longo *) &rguid2)[0] && ((SemSinal Longo *) &rguid1)[1]==((SemSinal Longo *) &rguid2)[1] &&
    ((SemSinal Longo *) &rguid1)[2]==((SemSinal Longo *) &rguid2)[2] && ((SemSinal Longo *) &rguid1)[3]==((SemSinal Longo *) &rguid2)[3]);
}
EmLinha Inteiro IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { Retorno !memcmp(&rguid1,&rguid2,TamanhoDe(GUID)); }
#Senão
#Defina InlineIsEqualGUID(rguid1,rguid2) (((SemSinal Longo *) rguid1)[0]==((SemSinal Longo *) rguid2)[0] && ((SemSinal Longo *) rguid1)[1]==((SemSinal Longo *) rguid2)[1] && ((SemSinal Longo *) rguid1)[2]==((SemSinal Longo *) rguid2)[2] && ((SemSinal Longo *) rguid1)[3]==((SemSinal Longo *) rguid2)[3])
#Defina IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,TamanhoDe(GUID)))
#FimSe

#SeDefinido __INLINE_ISEQUAL_GUID
#Indefinido IsEqualGUID
#Defina IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#FimSe

#Defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#Defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#Se !Definido _SYS_GUID_OPERATOR_EQ_ && !Definido _NO_SYS_GUID_OPERATOR_EQ_
#Defina _SYS_GUID_OPERATOR_EQ_
#SeDefinido __cplusplus
EmLinha Inteiro operator==(REFGUID guidOne,REFGUID guidOther) { Retorno IsEqualGUID(guidOne,guidOther); }
EmLinha Inteiro operator!=(REFGUID guidOne,REFGUID guidOther) { Retorno !(guidOne==guidOther); }
#FimSe
#FimSe
#FimSe
#FimSe
