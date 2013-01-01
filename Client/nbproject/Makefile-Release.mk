#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/world/CGrid.o \
	${OBJECTDIR}/UI/UICastBar.o \
	${OBJECTDIR}/objects/CPos.o \
	${OBJECTDIR}/CGlobals.o \
	${OBJECTDIR}/_ext/2098112761/GGlobals.o \
	${OBJECTDIR}/world/CWorld.o \
	${OBJECTDIR}/UI/UIMainFrame.o \
	${OBJECTDIR}/CPlayerObjHandle.o \
	${OBJECTDIR}/CDatabase.o \
	${OBJECTDIR}/UI/UIBaseFrame.o \
	${OBJECTDIR}/CFunctions.o \
	${OBJECTDIR}/objects/CCreature.o \
	${OBJECTDIR}/mainClient.o \
	${OBJECTDIR}/objects/CObj.o \
	${OBJECTDIR}/_ext/2098112761/GFunctions.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/world/CGrid.o: world/CGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/world
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/world/CGrid.o world/CGrid.cpp

${OBJECTDIR}/UI/UICastBar.o: UI/UICastBar.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UICastBar.o UI/UICastBar.cpp

${OBJECTDIR}/objects/CPos.o: objects/CPos.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CPos.o objects/CPos.cpp

${OBJECTDIR}/CGlobals.o: CGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CGlobals.o CGlobals.cpp

${OBJECTDIR}/_ext/2098112761/GGlobals.o: ../GShare/GGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GGlobals.o ../GShare/GGlobals.cpp

${OBJECTDIR}/world/CWorld.o: world/CWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/world
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/world/CWorld.o world/CWorld.cpp

${OBJECTDIR}/UI/UIMainFrame.o: UI/UIMainFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIMainFrame.o UI/UIMainFrame.cpp

${OBJECTDIR}/CPlayerObjHandle.o: CPlayerObjHandle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CPlayerObjHandle.o CPlayerObjHandle.cpp

${OBJECTDIR}/CDatabase.o: CDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CDatabase.o CDatabase.cpp

${OBJECTDIR}/UI/UIBaseFrame.o: UI/UIBaseFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIBaseFrame.o UI/UIBaseFrame.cpp

${OBJECTDIR}/CFunctions.o: CFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CFunctions.o CFunctions.cpp

${OBJECTDIR}/objects/CCreature.o: objects/CCreature.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CCreature.o objects/CCreature.cpp

${OBJECTDIR}/mainClient.o: mainClient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mainClient.o mainClient.cpp

${OBJECTDIR}/objects/CObj.o: objects/CObj.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CObj.o objects/CObj.cpp

${OBJECTDIR}/_ext/2098112761/GFunctions.o: ../GShare/GFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GFunctions.o ../GShare/GFunctions.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
