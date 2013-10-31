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
	${OBJECTDIR}/Grafic/GraficUtils/RandomVec3Texture.o \
	${OBJECTDIR}/UI/UICastBar.o \
	${OBJECTDIR}/Grafic/GraficEffectPlayer.o \
	${OBJECTDIR}/Powers/CPower.o \
	${OBJECTDIR}/Grafic/ParticalSystems/ParticalEngine.o \
	${OBJECTDIR}/Grafic/GraficEffectDataBlockState.o \
	${OBJECTDIR}/Grafic/Camera.o \
	${OBJECTDIR}/Grafic/ParticalSystems/ParticalUpShader.o \
	${OBJECTDIR}/Grafic/Shaders/BillboardShader.o \
	${OBJECTDIR}/Grafic/GraficEffectDataBlock.o \
	${OBJECTDIR}/objects/CPos.o \
	${OBJECTDIR}/Grafic/screenControler.o \
	${OBJECTDIR}/Grafic/Shader.o \
	${OBJECTDIR}/Grafic/Shaders/UIPrimShader.o \
	${OBJECTDIR}/GLutil.o \
	${OBJECTDIR}/UI/UIAbilityBox.o \
	${OBJECTDIR}/CGlobals.o \
	${OBJECTDIR}/_ext/2098112761/GGlobals.o \
	${OBJECTDIR}/Grafic/CGraficObject.o \
	${OBJECTDIR}/objects/Buffs/CBuff.o \
	${OBJECTDIR}/Grafic/Grafic.o \
	${OBJECTDIR}/CPlayerObjHandle.o \
	${OBJECTDIR}/world/CWorld.o \
	${OBJECTDIR}/UI/UIMainFrame.o \
	${OBJECTDIR}/UI/TransformStack.o \
	${OBJECTDIR}/CDatabase.o \
	${OBJECTDIR}/Grafic/ShaderProgram.o \
	${OBJECTDIR}/UI/UIBaseFrame.o \
	${OBJECTDIR}/CFunctions.o \
	${OBJECTDIR}/Grafic/ParticalSystems/ParticalSystem.o \
	${OBJECTDIR}/UI/UIPrimitiveBox.o \
	${OBJECTDIR}/Grafic/GraficEffectType.o \
	${OBJECTDIR}/mainClient.o \
	${OBJECTDIR}/objects/CObj.o \
	${OBJECTDIR}/objects/CCreature.o \
	${OBJECTDIR}/UI/UIUnitBox.o \
	${OBJECTDIR}/Grafic/Model.o \
	${OBJECTDIR}/_ext/2098112761/GFunctions.o \
	${OBJECTDIR}/UI/UISocket.o \
	${OBJECTDIR}/Grafic/Shaders/UIShader.o \
	${OBJECTDIR}/Grafic/Shaders/ObjectShader.o


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

${OBJECTDIR}/Grafic/GraficUtils/RandomVec3Texture.o: Grafic/GraficUtils/RandomVec3Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/GraficUtils
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/GraficUtils/RandomVec3Texture.o Grafic/GraficUtils/RandomVec3Texture.cpp

${OBJECTDIR}/UI/UICastBar.o: UI/UICastBar.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UICastBar.o UI/UICastBar.cpp

${OBJECTDIR}/Grafic/GraficEffectPlayer.o: Grafic/GraficEffectPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/GraficEffectPlayer.o Grafic/GraficEffectPlayer.cpp

${OBJECTDIR}/Powers/CPower.o: Powers/CPower.cpp 
	${MKDIR} -p ${OBJECTDIR}/Powers
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Powers/CPower.o Powers/CPower.cpp

${OBJECTDIR}/Grafic/ParticalSystems/ParticalEngine.o: Grafic/ParticalSystems/ParticalEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/ParticalSystems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/ParticalSystems/ParticalEngine.o Grafic/ParticalSystems/ParticalEngine.cpp

${OBJECTDIR}/Grafic/GraficEffectDataBlockState.o: Grafic/GraficEffectDataBlockState.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/GraficEffectDataBlockState.o Grafic/GraficEffectDataBlockState.cpp

${OBJECTDIR}/Grafic/Camera.o: Grafic/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Camera.o Grafic/Camera.cpp

${OBJECTDIR}/Grafic/ParticalSystems/ParticalUpShader.o: Grafic/ParticalSystems/ParticalUpShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/ParticalSystems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/ParticalSystems/ParticalUpShader.o Grafic/ParticalSystems/ParticalUpShader.cpp

${OBJECTDIR}/Grafic/Shaders/BillboardShader.o: Grafic/Shaders/BillboardShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/Shaders
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Shaders/BillboardShader.o Grafic/Shaders/BillboardShader.cpp

${OBJECTDIR}/Grafic/GraficEffectDataBlock.o: Grafic/GraficEffectDataBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/GraficEffectDataBlock.o Grafic/GraficEffectDataBlock.cpp

${OBJECTDIR}/objects/CPos.o: objects/CPos.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CPos.o objects/CPos.cpp

${OBJECTDIR}/Grafic/screenControler.o: Grafic/screenControler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/screenControler.o Grafic/screenControler.cpp

${OBJECTDIR}/Grafic/Shader.o: Grafic/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Shader.o Grafic/Shader.cpp

${OBJECTDIR}/Grafic/Shaders/UIPrimShader.o: Grafic/Shaders/UIPrimShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/Shaders
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Shaders/UIPrimShader.o Grafic/Shaders/UIPrimShader.cpp

${OBJECTDIR}/GLutil.o: GLutil.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GLutil.o GLutil.cpp

${OBJECTDIR}/UI/UIAbilityBox.o: UI/UIAbilityBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIAbilityBox.o UI/UIAbilityBox.cpp

${OBJECTDIR}/CGlobals.o: CGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CGlobals.o CGlobals.cpp

${OBJECTDIR}/_ext/2098112761/GGlobals.o: ../GShare/GGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GGlobals.o ../GShare/GGlobals.cpp

${OBJECTDIR}/Grafic/CGraficObject.o: Grafic/CGraficObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/CGraficObject.o Grafic/CGraficObject.cpp

${OBJECTDIR}/objects/Buffs/CBuff.o: objects/Buffs/CBuff.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects/Buffs
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Buffs/CBuff.o objects/Buffs/CBuff.cpp

${OBJECTDIR}/Grafic/Grafic.o: Grafic/Grafic.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Grafic.o Grafic/Grafic.cpp

${OBJECTDIR}/CPlayerObjHandle.o: CPlayerObjHandle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CPlayerObjHandle.o CPlayerObjHandle.cpp

${OBJECTDIR}/world/CWorld.o: world/CWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/world
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/world/CWorld.o world/CWorld.cpp

${OBJECTDIR}/UI/UIMainFrame.o: UI/UIMainFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIMainFrame.o UI/UIMainFrame.cpp

${OBJECTDIR}/UI/TransformStack.o: UI/TransformStack.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/TransformStack.o UI/TransformStack.cpp

${OBJECTDIR}/CDatabase.o: CDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CDatabase.o CDatabase.cpp

${OBJECTDIR}/Grafic/ShaderProgram.o: Grafic/ShaderProgram.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/ShaderProgram.o Grafic/ShaderProgram.cpp

${OBJECTDIR}/UI/UIBaseFrame.o: UI/UIBaseFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIBaseFrame.o UI/UIBaseFrame.cpp

${OBJECTDIR}/CFunctions.o: CFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/CFunctions.o CFunctions.cpp

${OBJECTDIR}/Grafic/ParticalSystems/ParticalSystem.o: Grafic/ParticalSystems/ParticalSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/ParticalSystems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/ParticalSystems/ParticalSystem.o Grafic/ParticalSystems/ParticalSystem.cpp

${OBJECTDIR}/UI/UIPrimitiveBox.o: UI/UIPrimitiveBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIPrimitiveBox.o UI/UIPrimitiveBox.cpp

${OBJECTDIR}/Grafic/GraficEffectType.o: Grafic/GraficEffectType.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/GraficEffectType.o Grafic/GraficEffectType.cpp

${OBJECTDIR}/mainClient.o: mainClient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mainClient.o mainClient.cpp

${OBJECTDIR}/objects/CObj.o: objects/CObj.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CObj.o objects/CObj.cpp

${OBJECTDIR}/objects/CCreature.o: objects/CCreature.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/CCreature.o objects/CCreature.cpp

${OBJECTDIR}/UI/UIUnitBox.o: UI/UIUnitBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UIUnitBox.o UI/UIUnitBox.cpp

${OBJECTDIR}/Grafic/Model.o: Grafic/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Model.o Grafic/Model.cpp

${OBJECTDIR}/_ext/2098112761/GFunctions.o: ../GShare/GFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2098112761
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2098112761/GFunctions.o ../GShare/GFunctions.cpp

${OBJECTDIR}/UI/UISocket.o: UI/UISocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/UI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UI/UISocket.o UI/UISocket.cpp

${OBJECTDIR}/Grafic/Shaders/UIShader.o: Grafic/Shaders/UIShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/Shaders
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Shaders/UIShader.o Grafic/Shaders/UIShader.cpp

${OBJECTDIR}/Grafic/Shaders/ObjectShader.o: Grafic/Shaders/ObjectShader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Grafic/Shaders
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Grafic/Shaders/ObjectShader.o Grafic/Shaders/ObjectShader.cpp

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
