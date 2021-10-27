#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=principal.c perifericos.c interrupciones.c procesamiento.c twiddleFactors.c config.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/principal.o ${OBJECTDIR}/perifericos.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/procesamiento.o ${OBJECTDIR}/twiddleFactors.o ${OBJECTDIR}/config.o
POSSIBLE_DEPFILES=${OBJECTDIR}/principal.o.d ${OBJECTDIR}/perifericos.o.d ${OBJECTDIR}/interrupciones.o.d ${OBJECTDIR}/procesamiento.o.d ${OBJECTDIR}/twiddleFactors.o.d ${OBJECTDIR}/config.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/principal.o ${OBJECTDIR}/perifericos.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/procesamiento.o ${OBJECTDIR}/twiddleFactors.o ${OBJECTDIR}/config.o

# Source Files
SOURCEFILES=principal.c perifericos.c interrupciones.c procesamiento.c twiddleFactors.c config.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ64GP802
MP_LINKER_FILE_OPTION=,--script=p33FJ64GP802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/principal.o: principal.c  .generated_files/flags/default/e0d8ccb5c737cd4fdb503142c5fb45cca623ef96 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/principal.o.d 
	@${RM} ${OBJECTDIR}/principal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  principal.c  -o ${OBJECTDIR}/principal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/principal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/perifericos.o: perifericos.c  .generated_files/flags/default/4e6363c95ffebc60bf804204e5724c34a8ecb02b .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/perifericos.o.d 
	@${RM} ${OBJECTDIR}/perifericos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  perifericos.c  -o ${OBJECTDIR}/perifericos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/perifericos.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupciones.o: interrupciones.c  .generated_files/flags/default/d6c4851bed5042c1e7d65d839210ca54dcc0e26d .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupciones.c  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/procesamiento.o: procesamiento.c  .generated_files/flags/default/3cc1d55afcf2ee64d0c7236dbbd794f66533ef57 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/procesamiento.o.d 
	@${RM} ${OBJECTDIR}/procesamiento.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  procesamiento.c  -o ${OBJECTDIR}/procesamiento.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/procesamiento.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/twiddleFactors.o: twiddleFactors.c  .generated_files/flags/default/ca9bf98f11382ca663035c00a6136d467739ee69 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twiddleFactors.o.d 
	@${RM} ${OBJECTDIR}/twiddleFactors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  twiddleFactors.c  -o ${OBJECTDIR}/twiddleFactors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/twiddleFactors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/602253d1f7f90714cabe34abe06ef8af1d54711c .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  config.c  -o ${OBJECTDIR}/config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/principal.o: principal.c  .generated_files/flags/default/8002d7913406182d9d7577fefb23575d69dc36e1 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/principal.o.d 
	@${RM} ${OBJECTDIR}/principal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  principal.c  -o ${OBJECTDIR}/principal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/principal.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/perifericos.o: perifericos.c  .generated_files/flags/default/5952bcd5f0832bb5984af0b116b4f47d0bb0ada4 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/perifericos.o.d 
	@${RM} ${OBJECTDIR}/perifericos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  perifericos.c  -o ${OBJECTDIR}/perifericos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/perifericos.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupciones.o: interrupciones.c  .generated_files/flags/default/d4364cff93d54aa8abfe2846a4167056fdc442b2 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupciones.c  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/procesamiento.o: procesamiento.c  .generated_files/flags/default/8c126c26f32266ebc3f5b563851a151a7ccff44b .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/procesamiento.o.d 
	@${RM} ${OBJECTDIR}/procesamiento.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  procesamiento.c  -o ${OBJECTDIR}/procesamiento.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/procesamiento.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/twiddleFactors.o: twiddleFactors.c  .generated_files/flags/default/42d6bad58e2684578c8d6a0b67aea41443fa31d9 .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twiddleFactors.o.d 
	@${RM} ${OBJECTDIR}/twiddleFactors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  twiddleFactors.c  -o ${OBJECTDIR}/twiddleFactors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/twiddleFactors.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/fba1690393d22dbc00882e00a450fd941cd2aedd .generated_files/flags/default/a733305486dba52bf1b2f0129eacaac696315869
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  config.c  -o ${OBJECTDIR}/config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Program\ Files/Microchip/xc16/v1.70/lib/libdsp-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:\Program Files\Microchip\xc16\v1.70\lib\libdsp-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Program\ Files/Microchip/xc16/v1.70/lib/libdsp-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:\Program Files\Microchip\xc16\v1.70\lib\libdsp-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
