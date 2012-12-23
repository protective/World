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
	${OBJECTDIR}/SDatabase.o \
	${OBJECTDIR}/objects/Buffs/SBuffBase.o \
	${OBJECTDIR}/Powers/SEffectTypeAddBuff.o \
	${OBJECTDIR}/Powers/SPowerSpellType.o \
	${OBJECTDIR}/Command/SC_ApplyTickSpellDamage.o \
	${OBJECTDIR}/Powers/SEffectType.o \
	${OBJECTDIR}/objects/Buffs/SBuffDot.o \
	${OBJECTDIR}/objects/SPos.o \
	${OBJECTDIR}/mainServer.o \
	${OBJECTDIR}/Command/SC_CastSTarget.o \
	${OBJECTDIR}/objects/Buffs/SBuff.o \
	${OBJECTDIR}/Powers/SPowerTypeLoader.o \
	${OBJECTDIR}/Client.o \
	${OBJECTDIR}/World/SWorld.o \
	${OBJECTDIR}/objects/SCreature.o \
	${OBJECTDIR}/Command/SCommand.o \
	${OBJECTDIR}/_ext/2098112761/GGlobals.o \
	${OBJECTDIR}/Command/SC_ApplyDamage.o \
	${OBJECTDIR}/Powers/SPower.o \
	${OBJECTDIR}/SFunctions.o \
	${OBJECTDIR}/objects/Buffs/SBuffStat.o \
	${OBJECTDIR}/Command/SC_KillUnit.o \
	${OBJECTDIR}/Powers/SPowerHandler.o \
	${OBJECTDIR}/SGlobals.o \
	${OBJECTDIR}/World/SGrid.o \
	${OBJECTDIR}/objects/SObj.o \
	${OBJECTDIR}/Powers/SPowerType.o \
	${OBJECTDIR}/_ext/2098112761/GFunctions.o \
	${OBJECTDIR}/Command/SC_BuffProces.o \
	${OBJECTDIR}/Powers/SEffectTypeDD.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/SDatabase.o: SDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/SDatabase.o SDatabase.cpp

${OBJECTDIR}/objects/Buffs/SBuffBase.o: objects/Buffs/SBuffBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects/Buffs
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Buffs/SBuffBase.o objects/Buffs/SBuffBase.cpp

${OBJECTDIR}/Powers/SEffectTypeAddBuff.o: Powers/SEffectTypeAddBuff.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SEffectTypeAddBuff.o Powers/SEffectTypeAddBuff.cpp

${OBJECTDIR}/Powers/SPowerSpellType.o: Powers/SPowerSpellType.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SPowerSpellType.o Powers/SPowerSpellType.cpp

${OBJECTDIR}/Command/SC_ApplyTickSpellDamage.o: Command/SC_ApplyTickSpellDamage.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SC_ApplyTickSpellDamage.o Command/SC_ApplyTickSpellDamage.cpp

${OBJECTDIR}/Powers/SEffectType.o: Powers/SEffectType.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SEffectType.o Powers/SEffectType.cpp

${OBJECTDIR}/objects/Buffs/SBuffDot.o: objects/Buffs/SBuffDot.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects/Buffs
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Buffs/SBuffDot.o objects/Buffs/SBuffDot.cpp

${OBJECTDIR}/objects/SPos.o: objects/SPos.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/SPos.o objects/SPos.cpp

${OBJECTDIR}/mainServer.o: mainServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mainServer.o mainServer.cpp

${OBJECTDIR}/Command/SC_CastSTarget.o: Command/SC_CastSTarget.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SC_CastSTarget.o Command/SC_CastSTarget.cpp

${OBJECTDIR}/objects/Buffs/SBuff.o: objects/Buffs/SBuff.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects/Buffs
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Buffs/SBuff.o objects/Buffs/SBuff.cpp

${OBJECTDIR}/Powers/SPowerTypeLoader.o: Powers/SPowerTypeLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SPowerTypeLoader.o Powers/SPowerTypeLoader.cpp

${OBJECTDIR}/Client.o: Client.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Client.o Client.cpp

${OBJECTDIR}/World/SWorld.o: World/SWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/World
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/World/SWorld.o World/SWorld.cpp

${OBJECTDIR}/objects/SCreature.o: objects/SCreature.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/SCreature.o objects/SCreature.cpp

${OBJECTDIR}/Command/SCommand.o: Command/SCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SCommand.o Command/SCommand.cpp

${OBJECTDIR}/_ext/2098112761/GGlobals.o: ../GShare/GGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GGlobals.o ../GShare/GGlobals.cpp

${OBJECTDIR}/Command/SC_ApplyDamage.o: Command/SC_ApplyDamage.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SC_ApplyDamage.o Command/SC_ApplyDamage.cpp

${OBJECTDIR}/Powers/SPower.o: Powers/SPower.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SPower.o Powers/SPower.cpp

${OBJECTDIR}/SFunctions.o: SFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/SFunctions.o SFunctions.cpp

${OBJECTDIR}/objects/Buffs/SBuffStat.o: objects/Buffs/SBuffStat.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects/Buffs
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Buffs/SBuffStat.o objects/Buffs/SBuffStat.cpp

${OBJECTDIR}/Command/SC_KillUnit.o: Command/SC_KillUnit.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SC_KillUnit.o Command/SC_KillUnit.cpp

${OBJECTDIR}/Powers/SPowerHandler.o: Powers/SPowerHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SPowerHandler.o Powers/SPowerHandler.cpp

${OBJECTDIR}/SGlobals.o: SGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/SGlobals.o SGlobals.cpp

${OBJECTDIR}/World/SGrid.o: World/SGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/World
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/World/SGrid.o World/SGrid.cpp

${OBJECTDIR}/objects/SObj.o: objects/SObj.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/SObj.o objects/SObj.cpp

${OBJECTDIR}/Powers/SPowerType.o: Powers/SPowerType.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SPowerType.o Powers/SPowerType.cpp

${OBJECTDIR}/_ext/2098112761/GFunctions.o: ../GShare/GFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GFunctions.o ../GShare/GFunctions.cpp

${OBJECTDIR}/Command/SC_BuffProces.o: Command/SC_BuffProces.cpp 
	${MKDIR} -p ${OBJECTDIR}/Command
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command/SC_BuffProces.o Command/SC_BuffProces.cpp

${OBJECTDIR}/Powers/SEffectTypeDD.o: Powers/SEffectTypeDD.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/SEffectTypeDD.o Powers/SEffectTypeDD.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
