# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL     = flightControlSystem
TARGET      = sfun
MODULE_SRCS   = c4_flightControlSystem.c half_type.c
MODEL_SRC  = flightControlSystem_sfun.c
MODEL_REG = flightControlSystem_sfun_registry.c
MAKEFILE    = flightControlSystem_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2021a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "C:\Users\nithy\MATLAB\Projects\examples\parrotminidronecompetition1\work\slprj\_sfprj\flightcontrolsystem\_self\sfun\src" /I "C:\Users\nithy\MATLAB\Projects\examples\parrotminidronecompetition1" /I "C:\Users\nithy\MATLAB\Projects\examples\parrotminidronecompetition1\controller"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2021a\extern\include" \
    /I "C:\Program Files\MATLAB\R2021a\simulink\include" \
    /I "C:\Program Files\MATLAB\R2021a\simulink\include\sf_runtime" \
    /I "C:\Program Files\MATLAB\R2021a\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2021a\rtw\c\src" \
    /I "C:\Users\nithy\MATLAB\Projects\examples\parrotMinidroneCompetition1\work\slprj\_sfprj\flightControlSystem\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\include" /I "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocvcg\opencv\include"
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD  
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS)

USER_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS     = \
     "c_mexapi_version.obj" \
     "extractSurfCore.obj" \
     "surfCommon.obj" \
     "cgCommon.obj" \
     "mwsurf.obj" \
     "fastHessianDetectorCore.obj" \

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = flightControlSystem_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(DSP_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


c_mexapi_version.obj :  "C:\Program Files\MATLAB\R2021a\extern\version\c_mexapi_version.c"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\extern\version\c_mexapi_version.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\extern\version\c_mexapi_version.c"
extractSurfCore.obj :  "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\extractSurfCore.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\extractSurfCore.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\extractSurfCore.cpp"
surfCommon.obj :  "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\surfCommon.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\surfCommon.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\surfCommon.cpp"
cgCommon.obj :  "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\cgCommon.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\cgCommon.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\cgCommon.cpp"
mwsurf.obj :  "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\mwsurf.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\mwsurf.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\mwsurf.cpp"
fastHessianDetectorCore.obj :  "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\fastHessianDetectorCore.cpp"
	@echo ### Compiling "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\fastHessianDetectorCore.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021a\toolbox\vision\builtins\src\ocv\fastHessianDetectorCore.cpp"
