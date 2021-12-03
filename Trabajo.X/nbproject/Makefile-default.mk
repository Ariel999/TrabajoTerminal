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
MKDIR=mkdir -p
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
SOURCEFILES_QUOTED_IF_SPACED=principal.c perifericos.c interrupciones.c procesamiento.c twiddleFactors.c config.c habilitarOscSec.s lcd.c pwm.c retardo.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/principal.o ${OBJECTDIR}/perifericos.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/procesamiento.o ${OBJECTDIR}/twiddleFactors.o ${OBJECTDIR}/config.o ${OBJECTDIR}/habilitarOscSec.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/retardo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/principal.o.d ${OBJECTDIR}/perifericos.o.d ${OBJECTDIR}/interrupciones.o.d ${OBJECTDIR}/procesamiento.o.d ${OBJECTDIR}/twiddleFactors.o.d ${OBJECTDIR}/config.o.d ${OBJECTDIR}/habilitarOscSec.o.d ${OBJECTDIR}/lcd.o.d ${OBJECTDIR}/pwm.o.d ${OBJECTDIR}/retardo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/principal.o ${OBJECTDIR}/perifericos.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/procesamiento.o ${OBJECTDIR}/twiddleFactors.o ${OBJECTDIR}/config.o ${OBJECTDIR}/habilitarOscSec.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/retardo.o

# Source Files
SOURCEFILES=principal.c perifericos.c interrupciones.c procesamiento.c twiddleFactors.c config.c habilitarOscSec.s lcd.c pwm.c retardo.s



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
${OBJECTDIR}/principal.o: principal.c  .generated_files/flags/default/fcd71c110a568591431dcc10626d4d1ac3e526e8 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/principal.o.d 
	@${RM} ${OBJECTDIR}/principal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  principal.c  -o ${OBJECTDIR}/principal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/principal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/perifericos.o: perifericos.c  .generated_files/flags/default/398aa98c695f7618ea86dc9f1e43149430cf1891 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/perifericos.o.d 
	@${RM} ${OBJECTDIR}/perifericos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  perifericos.c  -o ${OBJECTDIR}/perifericos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/perifericos.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupciones.o: interrupciones.c  .generated_files/flags/default/e17172d77af3648cc3a7b556532af84ba70f80 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupciones.c  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/procesamiento.o: procesamiento.c  .generated_files/flags/default/e1858b6a0b7361f9dd995adeda0f65a02ff37088 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/procesamiento.o.d 
	@${RM} ${OBJECTDIR}/procesamiento.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  procesamiento.c  -o ${OBJECTDIR}/procesamiento.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/procesamiento.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/twiddleFactors.o: twiddleFactors.c  .generated_files/flags/default/27b05d399111e1b3780f4cbfb341f84816c4585b .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twiddleFactors.o.d 
	@${RM} ${OBJECTDIR}/twiddleFactors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  twiddleFactors.c  -o ${OBJECTDIR}/twiddleFactors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/twiddleFactors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/f4fa6c5e22417133218ea7715c15a79497eed6ab .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  config.c  -o ${OBJECTDIR}/config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/f7b279bb04f8613615cf77edacf82c1186eca1dd .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pwm.o: pwm.c  .generated_files/flags/default/2bc0e98952786469229694ad9287920daec17f2 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwm.c  -o ${OBJECTDIR}/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/principal.o: principal.c  .generated_files/flags/default/7b7d0cb165588da115f7feeba82530d481990e06 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/principal.o.d 
	@${RM} ${OBJECTDIR}/principal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  principal.c  -o ${OBJECTDIR}/principal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/principal.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/perifericos.o: perifericos.c  .generated_files/flags/default/dcd3317c84dcd700b350aebf1e4d52ed1b268e6e .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/perifericos.o.d 
	@${RM} ${OBJECTDIR}/perifericos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  perifericos.c  -o ${OBJECTDIR}/perifericos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/perifericos.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupciones.o: interrupciones.c  .generated_files/flags/default/256d8ce18cb002f4910a2e35f4c3bf99f8e61671 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupciones.c  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupciones.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/procesamiento.o: procesamiento.c  .generated_files/flags/default/a3e1dbfb6d6eb3235d75c4321816a6a919596a70 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/procesamiento.o.d 
	@${RM} ${OBJECTDIR}/procesamiento.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  procesamiento.c  -o ${OBJECTDIR}/procesamiento.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/procesamiento.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/twiddleFactors.o: twiddleFactors.c  .generated_files/flags/default/70fd3d6ff79dfaecb91a5ee4eb3be8cf688a341a .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/twiddleFactors.o.d 
	@${RM} ${OBJECTDIR}/twiddleFactors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  twiddleFactors.c  -o ${OBJECTDIR}/twiddleFactors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/twiddleFactors.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/config.o: config.c  .generated_files/flags/default/4a71b24b907e4b662e440d42f6b8dc6ec6223a71 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config.o.d 
	@${RM} ${OBJECTDIR}/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  config.c  -o ${OBJECTDIR}/config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/8bc11f331294394e51b245b47e35e7481153a035 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pwm.o: pwm.c  .generated_files/flags/default/7cafc483cc77dc59f3e4193256951ec121454875 .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pwm.c  -o ${OBJECTDIR}/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pwm.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/habilitarOscSec.o: habilitarOscSec.s  .generated_files/flags/default/881f9c7aac74698375072ad2f4502374348f400e .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/habilitarOscSec.o.d 
	@${RM} ${OBJECTDIR}/habilitarOscSec.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  habilitarOscSec.s  -o ${OBJECTDIR}/habilitarOscSec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/habilitarOscSec.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/retardo.o: retardo.s  .generated_files/flags/default/738a144f66f18f689a2b84bb8663c10f256560cb .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardo.o.d 
	@${RM} ${OBJECTDIR}/retardo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardo.s  -o ${OBJECTDIR}/retardo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/retardo.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/habilitarOscSec.o: habilitarOscSec.s  .generated_files/flags/default/4fc61948d2b99dfaa32f324437ec07c5645754f .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/habilitarOscSec.o.d 
	@${RM} ${OBJECTDIR}/habilitarOscSec.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  habilitarOscSec.s  -o ${OBJECTDIR}/habilitarOscSec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/habilitarOscSec.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/retardo.o: retardo.s  .generated_files/flags/default/34bac88690a5bb50cb0a134736657cb6cbcfbb1c .generated_files/flags/default/483c49bb74f5a65b4ea000ea6dd3711cda2a277d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardo.o.d 
	@${RM} ${OBJECTDIR}/retardo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardo.s  -o ${OBJECTDIR}/retardo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/retardo.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:/Program Files/Microchip/xc16/v1.70/lib/libdsp-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Program\ Files/Microchip/xc16/v1.70/lib/libdsp-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:/Program Files/Microchip/xc16/v1.70/lib/libdsp-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Trabajo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
