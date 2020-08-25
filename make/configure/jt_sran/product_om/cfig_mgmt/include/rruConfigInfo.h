/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:45 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:03 CST. */
/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */
#ifndef RRUCONFIGINFO_H
#define RRUCONFIGINFO_H
#include "sbs_type.h"

#define RRUCONFIGINFOTABLES_INDEX_POS 14

typedef struct{
	long			rruCfgMsgIndex;
	/*
	 * Column values 
	 */
	u_long			rruCfgMsgRruId;
	u_long			rruCfgMsgCpuUsage;       
	u_long			rruCfgMsgPeriod;
	char			rruCfgMsgTempVal[8];
	size_t			rruCfgMsgTempVal_len;
	char			rruCfgMsgVswrVal[8];
	size_t			rruCfgMsgVswrVal_len;
	u_long			rruCfgMsgVswrThres1;
	u_long			rruCfgMsgVswrThres2;
	char			rruCfgMsgpPowerVal[8];
	size_t			rruCfgMsgpPowerVal_len;
	long			rruCfgMsgUpThres;
	long			rruCfgMsgLowThres;
	u_long			rruCfgMsgAntMode;
	u_long			rruCfgMsgAntSetNo;
	u_long			rruCfgMsgAntState;
	char			rruCfgMsgUpPathState[8];
	size_t			rruCfgMsgUpPathState_len;
	char			rruCfgMsgDwPathState[8];
	size_t			rruCfgMsgDwPathState_len;
	u_long			rruCfgMsgState;
	u_long			rruCfgMsgClockState;
	long			rruCfgMsgRowStatus;

	UINT8           fin_flag_vswr_thres;
	UINT8			fin_flag_temp_thres;
	UINT8 			fin_flag_ant_cfg;
	UINT8			fin_flag_channel_state;	
}rruCfgMsgTable;

typedef struct  {
   
    long            rruDealyCfgIndex;
	
    u_long          rruDealyCfgRruId;
    u_long          rruDealyCfgFiberNo;
    u_long          rruDealyCfgTrxaRxm;
    u_long          rruDealyCfgTrxmRxa;
    u_long          rruDealyCfgTimeAdv;
    u_long          rruDealyCfgDlCalRru;
    u_long          rruDealyCfgUlCalRru;
    long            rruDealyCfgRowStatus;

	UINT8 			fin_flag;
}rruDealyCfgTable;

typedef struct{
    long            rruRingTestIndex;
	
    u_long          rruRingTestRruId;
    u_long          rruRingTestType;
    u_long          rruRingTestCheckPeriod;
    u_long          rruRingTestPortNo;
    long            rruRingTestRowStatus;

	UINT8 			fin_flag;
}rruRingTestTable;

typedef struct {
  
    long            rruOperateIndex;
   
    u_long          rruOperateResetType;
    u_long          rruOperateSwUpdate;
    long            rruOperateRowStatus;

	UINT8			fin_flag;

}rruOperateTable;


/*
 * function declarations 
 */
void            init_rruConfigInfo(void);
FindVarMethod   var_rruConfigInfo;
FindVarMethod   var_rruLogicMsgTable;
FindVarMethod   var_rruProductMsgTable;
FindVarMethod   var_rruCfgMsgTable;
FindVarMethod   var_rruLatestChannelSetTable;
FindVarMethod   var_rruAbilityMsgTable;
FindVarMethod   var_rruSoftHardMsgTable;
FindVarMethod   var_rruDelayMeasureTable;
FindVarMethod   var_rruDealyCfgTable;
FindVarMethod   var_rruRingTestTable;
FindVarMethod   var_rruOperateTable;
WriteMethod     write_rruLogicMsgRruId;
WriteMethod     write_rruLogicMsgNeId;
WriteMethod     write_rruLogicMsgBbuId;
WriteMethod     write_rruLogicMsgFpgaId;
WriteMethod     write_rruLogicMsgCpriPort;
WriteMethod     write_rruLogicMsgBbuIp;
WriteMethod     write_rruLogicMsgRruIp;
WriteMethod     write_rruLogicMsgRruMac;
WriteMethod     write_rruLogicMsgSubMask;
WriteMethod     write_rruLogicMsgRowStatus;
WriteMethod     write_rruProductMsgRruId;
WriteMethod     write_rruProductMsgManufactuere;
WriteMethod     write_rruProductMsgPublisher;
WriteMethod     write_rruProductMsgSerialNo;
WriteMethod     write_rruProductMsgManufactureDate;
WriteMethod     write_rruProductMsgLastServiceDate;
WriteMethod     write_rruProductMsgExtraInfo;
WriteMethod     write_rruProductMsgRowStatus;
WriteMethod     write_rruCfgMsgRruId;
WriteMethod     write_rruCfgMsgCpuUsage;
WriteMethod     write_rruCfgMsgPeriod;
WriteMethod     write_rruCfgMsgTempVal;
WriteMethod     write_rruCfgMsgVswrVal;
WriteMethod     write_rruCfgMsgVswrThres1;
WriteMethod     write_rruCfgMsgVswrThres2;
WriteMethod     write_rruCfgMsgpPowerVal;
WriteMethod     write_rruCfgMsgUpThres;
WriteMethod     write_rruCfgMsgLowThres;
WriteMethod     write_rruCfgMsgAntMode;
WriteMethod     write_rruCfgMsgAntSetNo;
WriteMethod     write_rruCfgMsgAntState;
WriteMethod     write_rruCfgMsgUpPathState;
WriteMethod     write_rruCfgMsgDwPathState;
WriteMethod     write_rruCfgMsgState;
WriteMethod     write_rruCfgMsgClockState;
WriteMethod     write_rruCfgMsgRowStatus;
WriteMethod     write_rruLatestChannelSetRruId;
WriteMethod     write_rruLatestChannelSetReason;
WriteMethod     write_rruLatestChannelSetAlarmCode;
WriteMethod     write_rruLatestChannelSetRowStatus;
WriteMethod     write_rruAbilityMsgRruId;
WriteMethod     write_rruAbilityMsgTdCarrierNum;
WriteMethod     write_rruAbilityMsgLteCarrierNum;
WriteMethod     write_rruAbilityMsgAntNum;
WriteMethod     write_rruAbilityMsgMaxPower;
WriteMethod     write_rruAbilityMsgMasterOrSlave;
WriteMethod     write_rruAbilityMsgMaxDwTimeDelay;
WriteMethod     write_rruAbilityMsgMaxUpTimeDelay;
WriteMethod     write_rruAbilityMsgSupportMode;
WriteMethod     write_rruAbilityMsgAntClbrtFlag;
WriteMethod     write_rruAbilityMsgMainSendEmePath;
WriteMethod     write_rruAbilityMsgSlaveSendEmePath;
WriteMethod     write_rruAbilityMsgMainRecvEmePath;
WriteMethod     write_rruAbilityMsgSlaveRecvEmePath;
WriteMethod     write_rruAbilityMsgRowStatus;
WriteMethod     write_rruSoftHardMsgRruId;
WriteMethod     write_rruSoftHardMsgHwType;
WriteMethod     write_rruSoftHardMsgHwVersion;
WriteMethod     write_rruSoftHardMsgSwVer;
WriteMethod     write_rruSoftHardMsgFwVer;
WriteMethod     write_rruSoftHardMsgRowStatus;
WriteMethod     write_rruDelayMeasureRruId;
WriteMethod     write_rruDelayMeasureFiberNo;
WriteMethod     write_rruDelayMeasureTOffset;
WriteMethod     write_rruDelayMeasureTbDelayDl;
WriteMethod     write_rruDelayMeasureTbDelayUl;
WriteMethod     write_rruDelayMeasureT2a;
WriteMethod     write_rruDelayMeasureT3a;
WriteMethod     write_rruDelayMeasureRowStatus;
WriteMethod     write_rruDealyCfgRruId;
WriteMethod     write_rruDealyCfgFiberNo;
WriteMethod     write_rruDealyCfgTrxaRxm;
WriteMethod     write_rruDealyCfgTrxmRxa;
WriteMethod     write_rruDealyCfgTimeAdv;
WriteMethod     write_rruDealyCfgDlCalRru;
WriteMethod     write_rruDealyCfgUlCalRru;
WriteMethod     write_rruDealyCfgRowStatus;
WriteMethod     write_rruRingTestRruId;
WriteMethod     write_rruRingTestType;
WriteMethod     write_rruRingTestCheckPeriod;
WriteMethod     write_rruRingTestPortNo;
WriteMethod     write_rruRingTestRowStatus;
WriteMethod     write_rruOperateResetType;
WriteMethod     write_rruOperateSwUpdate;
WriteMethod     write_rruOperateRowStatus;

#endif                          /* RRUCONFIGINFO_H */
