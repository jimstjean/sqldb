# Microsoft Developer Studio Generated NMAKE File, Based on V2Template32.dsp
!IF "$(CFG)" == ""
CFG=V2Template32 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to V2Template32 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "V2Template32 - Win32 Release" && "$(CFG)" != "V2Template32 - Win32 Debug" && "$(CFG)" != "V2Template32 - Win32 Run_Only" && "$(CFG)" != "V2Template32 - Win32 Release_Small" && "$(CFG)" != "V2Template32 - Win32 Run_Only_Small" && "$(CFG)" != "V2Template32 - Win32 Vitalize" && "$(CFG)" != "V2Template32 - Win32 Vitalize_Small"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "V2Template32.mak" CFG="V2Template32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "V2Template32 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Run_Only" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Release_Small" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Run_Only_Small" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Vitalize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "V2Template32 - Win32 Vitalize_Small" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "V2Template32 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.cox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.cox"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "EDITOR" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.cox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.cox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.cox" "$(OUTDIR)\V2Template32.bsc" ".\V2Template32"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\attach.sbr"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\auth.sbr"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\btree.sbr"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\build.sbr"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\date.sbr"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\delete.sbr"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\Edittime.sbr"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\expr.sbr"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\func.sbr"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\General.sbr"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\hash.sbr"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\insert.sbr"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\legacy.sbr"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\Main.sbr"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\opcodes.sbr"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_mac.sbr"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_unix.sbr"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\os_win.sbr"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\pager.sbr"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\parse.sbr"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\pragma.sbr"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\printf.sbr"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\random.sbr"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\RunOnly.sbr"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\Runtime.sbr"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\select.sbr"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\shell.sbr"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\sqlite.sbr"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\table.sbr"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\tokenize.sbr"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\trigger.sbr"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\update.sbr"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\utf.sbr"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\util.sbr"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vacuum.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbe.sbr"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeapi.sbr"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbeaux.sbr"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\vdbemem.sbr"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(INTDIR)\where.sbr"
	-@erase "$(OUTDIR)\V2Template32.bsc"
	-@erase "$(OUTDIR)\V2Template32.cox"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.ilk"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase "$(OUTDIR)\V2Template32.pdb"
	-@erase ".\Debug\Extobj.res"
	-@erase "V2Template32"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "_DEBUG" /d "EDITOR" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Edittime.sbr" \
	"$(INTDIR)\General.sbr" \
	"$(INTDIR)\Main.sbr" \
	"$(INTDIR)\RunOnly.sbr" \
	"$(INTDIR)\Runtime.sbr" \
	"$(INTDIR)\sqlite.sbr" \
	"$(INTDIR)\btree.sbr" \
	"$(INTDIR)\where.sbr" \
	"$(INTDIR)\attach.sbr" \
	"$(INTDIR)\auth.sbr" \
	"$(INTDIR)\build.sbr" \
	"$(INTDIR)\date.sbr" \
	"$(INTDIR)\delete.sbr" \
	"$(INTDIR)\expr.sbr" \
	"$(INTDIR)\func.sbr" \
	"$(INTDIR)\hash.sbr" \
	"$(INTDIR)\insert.sbr" \
	"$(INTDIR)\legacy.sbr" \
	"$(INTDIR)\opcodes.sbr" \
	"$(INTDIR)\os_mac.sbr" \
	"$(INTDIR)\os_unix.sbr" \
	"$(INTDIR)\os_win.sbr" \
	"$(INTDIR)\pager.sbr" \
	"$(INTDIR)\parse.sbr" \
	"$(INTDIR)\pragma.sbr" \
	"$(INTDIR)\printf.sbr" \
	"$(INTDIR)\random.sbr" \
	"$(INTDIR)\select.sbr" \
	"$(INTDIR)\shell.sbr" \
	"$(INTDIR)\table.sbr" \
	"$(INTDIR)\tokenize.sbr" \
	"$(INTDIR)\trigger.sbr" \
	"$(INTDIR)\update.sbr" \
	"$(INTDIR)\utf.sbr" \
	"$(INTDIR)\util.sbr" \
	"$(INTDIR)\vacuum.sbr" \
	"$(INTDIR)\vdbe.sbr" \
	"$(INTDIR)\vdbeapi.sbr" \
	"$(INTDIR)\vdbeaux.sbr" \
	"$(INTDIR)\vdbemem.sbr"

"$(OUTDIR)\V2Template32.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\lib\cncs32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\V2Template32.pdb" /debug /machine:I386 /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.cox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Debug\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.cox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

InputDir=.\Debug
WkspDir=.
WkspName=V2Template32
InputPath=.\Debug\V2Template32.cox
SOURCE="$(InputPath)"

".\V2Template32" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	$(WkspDir)\$(InputDir)\transfer.bat
<< 
	

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"

OUTDIR=.\Run_Only
INTDIR=.\Run_Only
# Begin Custom Macros
OutDir=.\Run_Only
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.cox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.cox"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /D "RUN_ONLY" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /D "RUN_ONLY" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "RUN_ONLY" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.cox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.cox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"

OUTDIR=.\Release_Small
INTDIR=.\Release_Small
# Begin Custom Macros
OutDir=.\Release_Small
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.cox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.cox"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /D "COMPILE_SMALL" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "EDITOR" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib msvcrt.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /nodefaultlib /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.cox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.cox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"

OUTDIR=.\Run_Only_Small
INTDIR=.\Run_Only_Small
# Begin Custom Macros
OutDir=.\Run_Only_Small
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.cox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.cox"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /D "RUN_ONLY" /D "COMPILE_SMALL" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /D "RUN_ONLY" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "RUN_ONLY" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib msvcrt.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /nodefaultlib /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.cox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.cox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"

OUTDIR=.\Vitalize
INTDIR=.\Vitalize
# Begin Custom Macros
OutDir=.\Vitalize
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.mox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase "$(OUTDIR)\V2Template32.mox"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /D "RUN_ONLY" /D "VITALIZE" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /D "RUN_ONLY" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "RUN_ONLY" /d "VITALIZE" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.mox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.mox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"

OUTDIR=.\Vitalize_Small
INTDIR=.\Vitalize_Small
# Begin Custom Macros
OutDir=.\Vitalize_Small
# End Custom Macros

ALL : "$(OUTDIR)\V2Template32.mox"


CLEAN :
	-@erase "$(INTDIR)\attach.obj"
	-@erase "$(INTDIR)\auth.obj"
	-@erase "$(INTDIR)\btree.obj"
	-@erase "$(INTDIR)\build.obj"
	-@erase "$(INTDIR)\date.obj"
	-@erase "$(INTDIR)\delete.obj"
	-@erase "$(INTDIR)\Edittime.obj"
	-@erase "$(INTDIR)\expr.obj"
	-@erase "$(INTDIR)\func.obj"
	-@erase "$(INTDIR)\General.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\insert.obj"
	-@erase "$(INTDIR)\legacy.obj"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\opcodes.obj"
	-@erase "$(INTDIR)\os_mac.obj"
	-@erase "$(INTDIR)\os_unix.obj"
	-@erase "$(INTDIR)\os_win.obj"
	-@erase "$(INTDIR)\pager.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\pragma.obj"
	-@erase "$(INTDIR)\printf.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\RunOnly.obj"
	-@erase "$(INTDIR)\Runtime.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\sqlite.obj"
	-@erase "$(INTDIR)\table.obj"
	-@erase "$(INTDIR)\tclsqlite.obj"
	-@erase "$(INTDIR)\tokenize.obj"
	-@erase "$(INTDIR)\trigger.obj"
	-@erase "$(INTDIR)\update.obj"
	-@erase "$(INTDIR)\utf.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vacuum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vdbe.obj"
	-@erase "$(INTDIR)\vdbeapi.obj"
	-@erase "$(INTDIR)\vdbeaux.obj"
	-@erase "$(INTDIR)\vdbemem.obj"
	-@erase "$(INTDIR)\where.obj"
	-@erase "$(OUTDIR)\V2Template32.exp"
	-@erase "$(OUTDIR)\V2Template32.lib"
	-@erase "$(OUTDIR)\V2Template32.mox"
	-@erase ".\Release\Extobj.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "STRICT" /D "RUN_ONLY" /D "COMPILE_SMALL" /D "VITALIZE" /Fp"$(INTDIR)\V2Template32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /D "RUN_ONLY" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Extobj.res" /d "NDEBUG" /d "RUN_ONLY" /d "VITALIZE" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\V2Template32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib msvcrt.lib ..\lib\cncs32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\V2Template32.pdb" /machine:I386 /nodefaultlib /def:".\Extobj32.def" /out:"$(OUTDIR)\V2Template32.mox" /implib:"$(OUTDIR)\V2Template32.lib" 
DEF_FILE= \
	".\Extobj32.def"
LINK32_OBJS= \
	"$(INTDIR)\Edittime.obj" \
	"$(INTDIR)\General.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\RunOnly.obj" \
	"$(INTDIR)\Runtime.obj" \
	".\Release\Extobj.res" \
	"$(INTDIR)\sqlite.obj" \
	"$(INTDIR)\btree.obj" \
	"$(INTDIR)\where.obj" \
	"$(INTDIR)\attach.obj" \
	"$(INTDIR)\auth.obj" \
	"$(INTDIR)\build.obj" \
	"$(INTDIR)\date.obj" \
	"$(INTDIR)\delete.obj" \
	"$(INTDIR)\expr.obj" \
	"$(INTDIR)\func.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\insert.obj" \
	"$(INTDIR)\legacy.obj" \
	"$(INTDIR)\opcodes.obj" \
	"$(INTDIR)\os_mac.obj" \
	"$(INTDIR)\os_unix.obj" \
	"$(INTDIR)\os_win.obj" \
	"$(INTDIR)\pager.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\pragma.obj" \
	"$(INTDIR)\printf.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\table.obj" \
	"$(INTDIR)\tclsqlite.obj" \
	"$(INTDIR)\tokenize.obj" \
	"$(INTDIR)\trigger.obj" \
	"$(INTDIR)\update.obj" \
	"$(INTDIR)\utf.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\vacuum.obj" \
	"$(INTDIR)\vdbe.obj" \
	"$(INTDIR)\vdbeapi.obj" \
	"$(INTDIR)\vdbeaux.obj" \
	"$(INTDIR)\vdbemem.obj"

"$(OUTDIR)\V2Template32.mox" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("V2Template32.dep")
!INCLUDE "V2Template32.dep"
!ELSE 
!MESSAGE Warning: cannot find "V2Template32.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "V2Template32 - Win32 Release" || "$(CFG)" == "V2Template32 - Win32 Debug" || "$(CFG)" == "V2Template32 - Win32 Run_Only" || "$(CFG)" == "V2Template32 - Win32 Release_Small" || "$(CFG)" == "V2Template32 - Win32 Run_Only_Small" || "$(CFG)" == "V2Template32 - Win32 Vitalize" || "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"
SOURCE=..\..\sqlite\attach.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\attach.obj"	"$(INTDIR)\attach.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\attach.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\auth.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\auth.obj"	"$(INTDIR)\auth.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\auth.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\btree.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\btree.obj"	"$(INTDIR)\btree.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\btree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\build.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\build.obj"	"$(INTDIR)\build.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\build.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\date.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\date.obj"	"$(INTDIR)\date.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\date.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\delete.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\delete.obj"	"$(INTDIR)\delete.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\delete.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Edittime.cpp

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\Edittime.obj"	"$(INTDIR)\Edittime.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\Edittime.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\sqlite\expr.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\expr.obj"	"$(INTDIR)\expr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\expr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Extobj.rc

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "EDITOR" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


".\Debug\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Debug/Extobj.res" /d "_DEBUG" /d "EDITOR" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "RUN_ONLY" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "EDITOR" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "RUN_ONLY" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "RUN_ONLY" /d "VITALIZE" $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


".\Release\Extobj.res" : $(SOURCE)
	$(RSC) /l 0x409 /fo".\Release/Extobj.res" /d "NDEBUG" /d "RUN_ONLY" /d "VITALIZE" $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\func.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\func.obj"	"$(INTDIR)\func.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\func.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\General.cpp

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\General.obj"	"$(INTDIR)\General.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\General.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\sqlite\hash.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\hash.obj"	"$(INTDIR)\hash.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\insert.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\insert.obj"	"$(INTDIR)\insert.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\insert.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\legacy.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\legacy.obj"	"$(INTDIR)\legacy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\legacy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\main.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Main.cpp

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\Main.obj"	"$(INTDIR)\Main.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\Main.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\sqlite\opcodes.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\opcodes.obj"	"$(INTDIR)\opcodes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\opcodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\os_mac.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\os_mac.obj"	"$(INTDIR)\os_mac.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\os_mac.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\os_unix.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\os_unix.obj"	"$(INTDIR)\os_unix.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\os_unix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\os_win.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\os_win.obj"	"$(INTDIR)\os_win.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\os_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\pager.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\pager.obj"	"$(INTDIR)\pager.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\pager.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\parse.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\parse.obj"	"$(INTDIR)\parse.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\pragma.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\pragma.obj"	"$(INTDIR)\pragma.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\pragma.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\printf.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\printf.obj"	"$(INTDIR)\printf.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\printf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\random.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\random.obj"	"$(INTDIR)\random.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\RunOnly.cpp

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\RunOnly.obj"	"$(INTDIR)\RunOnly.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\RunOnly.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\Runtime.cpp

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\Runtime.obj"	"$(INTDIR)\Runtime.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\Runtime.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\..\sqlite\select.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\select.obj"	"$(INTDIR)\select.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\shell.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\shell.obj"	"$(INTDIR)\shell.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\sqlite.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\sqlite.obj"	"$(INTDIR)\sqlite.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\sqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\table.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\table.obj"	"$(INTDIR)\table.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\table.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\tclsqlite.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"

!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\tclsqlite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\tokenize.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\tokenize.obj"	"$(INTDIR)\tokenize.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\tokenize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\trigger.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\trigger.obj"	"$(INTDIR)\trigger.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\trigger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\update.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\update.obj"	"$(INTDIR)\update.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\update.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\utf.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\utf.obj"	"$(INTDIR)\utf.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\utf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\util.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\util.obj"	"$(INTDIR)\util.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\vacuum.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\vacuum.obj"	"$(INTDIR)\vacuum.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\vacuum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\vdbe.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\vdbe.obj"	"$(INTDIR)\vdbe.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\vdbe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\vdbeapi.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\vdbeapi.obj"	"$(INTDIR)\vdbeapi.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\vdbeapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\vdbeaux.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\vdbeaux.obj"	"$(INTDIR)\vdbeaux.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\vdbeaux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\vdbemem.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\vdbemem.obj"	"$(INTDIR)\vdbemem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\vdbemem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\sqlite\where.c

!IF  "$(CFG)" == "V2Template32 - Win32 Release"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Debug"


"$(INTDIR)\where.obj"	"$(INTDIR)\where.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Release_Small"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Run_Only_Small"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "V2Template32 - Win32 Vitalize_Small"


"$(INTDIR)\where.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

