#define BTL_STAGE_DEFAULT -1

enum StageNames {
    BTL_KMR_PART_1_STAGE_00         = 0x00,
    BTL_KMR_PART_1_STAGE_01         = 0x01,
    BTL_KMR_PART_1_STAGE_02         = 0x02,
    BTL_KMR_PART_1_STAGE_03         = 0x03,
    BTL_KMR_PART_1_STAGE_04         = 0x04,
    BTL_KMR_PART_2_STAGE_00         = 0x00,
    BTL_KMR_PART_2_STAGE_01         = 0x01,
    BTL_KMR_PART_2_STAGE_02         = 0x02,
    BTL_KMR_PART_2_STAGE_03         = 0x03,
    BTL_KMR_PART_2_STAGE_04         = 0x04,
    BTL_KMR_PART_3_STAGE_00         = 0x00,
    BTL_KMR_PART_3_STAGE_01         = 0x01,
    BTL_KMR_PART_3_STAGE_02         = 0x02,
    BTL_KMR_PART_3_STAGE_03         = 0x03,
    BTL_KMR_PART_3_STAGE_04         = 0x04,
    BTL_KMR_PART_3_STAGE_05         = 0x05,
    BTL_KMR_PART_3_STAGE_06         = 0x06,
    BTL_KMR_PART_3_STAGE_07         = 0x07,
    BTL_KMR_PART_3_STAGE_08         = 0x08,
    BTL_KMR_PART_3_STAGE_09         = 0x09,
    BTL_MAC_STAGE_00                = 0x00,
    BTL_MAC_STAGE_01                = 0x01,
    BTL_HOS_STAGE_00                = 0x00,
    BTL_HOS_STAGE_01                = 0x01,
    BTL_HOS_STAGE_02                = 0x02,
    BTL_NOK_STAGE_00                = 0x00,
    BTL_NOK_STAGE_01                = 0x01,
    BTL_NOK_STAGE_02                = 0x02,
    BTL_NOK_STAGE_03                = 0x03,
    BTL_TRD_PART_1_STAGE_00         = 0x00,
    BTL_TRD_PART_1_STAGE_01         = 0x01,
    BTL_TRD_PART_1_STAGE_02         = 0x02,
    BTL_TRD_PART_1_STAGE_03         = 0x03,
    BTL_TRD_PART_1_STAGE_04         = 0x04,
    BTL_TRD_PART_1_STAGE_05         = 0x05,
    BTL_TRD_PART_1_STAGE_06         = 0x06,
    BTL_TRD_PART_1_STAGE_07         = 0x07,
    BTL_TRD_PART_1_STAGE_08         = 0x08,
    BTL_TRD_PART_1_STAGE_09         = 0x09,
    BTL_TRD_PART_1_STAGE_0A         = 0x0A,
    BTL_TRD_PART_1_STAGE_0B         = 0x0B,
    BTL_TRD_PART_1_STAGE_0C         = 0x0C,
    BTL_TRD_PART_1_STAGE_0D         = 0x0D,
    BTL_TRD_PART_2_STAGE_00         = 0x00,
    BTL_TRD_PART_2_STAGE_01         = 0x01,
    BTL_TRD_PART_2_STAGE_02         = 0x02,
    BTL_TRD_PART_2_STAGE_03         = 0x03,
    BTL_TRD_PART_2_STAGE_04         = 0x04,
    BTL_TRD_PART_2_STAGE_05         = 0x05,
    BTL_TRD_PART_2_STAGE_06         = 0x06,
    BTL_TRD_PART_2_STAGE_07         = 0x07,
    BTL_TRD_PART_2_STAGE_08         = 0x08,
    BTL_TRD_PART_2_STAGE_09         = 0x09,
    BTL_TRD_PART_2_STAGE_0A         = 0x0A,
    BTL_TRD_PART_2_STAGE_0B         = 0x0B,
    BTL_TRD_PART_3_STAGE_00         = 0x00,
    BTL_IWA_STAGE_00                = 0x00,
    BTL_IWA_STAGE_01                = 0x01,
    BTL_IWA_STAGE_02                = 0x02,
    BTL_SBK_STAGE_00                = 0x00,
    BTL_ISK_PART_1_STAGE_00         = 0x00,
    BTL_ISK_PART_1_STAGE_01         = 0x01,
    BTL_ISK_PART_1_STAGE_02         = 0x02,
    BTL_ISK_PART_1_STAGE_03         = 0x03,
    BTL_ISK_PART_1_STAGE_04         = 0x04,
    BTL_ISK_PART_1_STAGE_05         = 0x05,
    BTL_ISK_PART_1_STAGE_06         = 0x06,
    BTL_ISK_PART_1_STAGE_07         = 0x07,
    BTL_ISK_PART_1_STAGE_08         = 0x08,
    BTL_ISK_PART_1_STAGE_09         = 0x09,
    BTL_ISK_PART_1_STAGE_0A         = 0x0A,
    BTL_ISK_PART_1_STAGE_0B         = 0x0B,
    BTL_ISK_PART_1_STAGE_0C         = 0x0C,
    BTL_ISK_PART_2_STAGE_00         = 0x00,
    BTL_ISK_PART_2_STAGE_01         = 0x01,
    BTL_ISK_PART_2_STAGE_02         = 0x02,
    BTL_ISK_PART_2_STAGE_03         = 0x03,
    BTL_ISK_PART_2_STAGE_04         = 0x04,
    BTL_ISK_PART_2_STAGE_05         = 0x05,
    BTL_ISK_PART_2_STAGE_06         = 0x06,
    BTL_ISK_PART_2_STAGE_07         = 0x07,
    BTL_ISK_PART_2_STAGE_08         = 0x08,
    BTL_ISK_PART_2_STAGE_09         = 0x09,
    BTL_ISK_PART_2_STAGE_0A         = 0x0A,
    BTL_ISK_PART_2_STAGE_0B         = 0x0B,
    BTL_MIM_STAGE_00                = 0x00,
    BTL_ARN_STAGE_00                = 0x00,
    BTL_ARN_STAGE_01                = 0x01,
    BTL_ARN_STAGE_02                = 0x02,
    BTL_ARN_STAGE_03                = 0x03,
    BTL_ARN_STAGE_04                = 0x04,
    BTL_ARN_STAGE_05                = 0x05,
    BTL_DGB_STAGE_00                = 0x00,
    BTL_DGB_STAGE_01                = 0x01,
    BTL_DGB_STAGE_02                = 0x02,
    BTL_DGB_STAGE_03                = 0x03,
    BTL_DGB_STAGE_04                = 0x04,
    BTL_OMO_STAGE_00                = 0x00,
    BTL_OMO_STAGE_01                = 0x01,
    BTL_OMO_STAGE_02                = 0x02,
    BTL_OMO_STAGE_03                = 0x03,
    BTL_OMO_STAGE_04                = 0x04,
    BTL_OMO_STAGE_05                = 0x05,
    BTL_OMO_STAGE_06                = 0x06,
    BTL_OMO_STAGE_07                = 0x07,
    BTL_OMO_STAGE_08                = 0x08,
    BTL_OMO2_STAGE_00               = 0x00,
    BTL_OMO3_STAGE_00               = 0x00,
    BTL_OMO3_STAGE_01               = 0x01,
    BTL_OMO3_STAGE_02               = 0x02,
    BTL_OMO3_STAGE_03               = 0x03,
    BTL_OMO3_STAGE_04               = 0x04,
    BTL_OMO3_STAGE_05               = 0x05,
    BTL_OMO3_STAGE_06               = 0x06,
    BTL_OMO3_STAGE_07               = 0x07,
    BTL_OMO3_STAGE_08               = 0x08,
    BTL_KGR_STAGE_00                = 0x00,
    BTL_JAN_STAGE_00                = 0x00,
    BTL_JAN_STAGE_01                = 0x01,
    BTL_JAN_STAGE_02                = 0x02,
    BTL_JAN_STAGE_03                = 0x03,
    BTL_JAN_STAGE_04                = 0x04,
    BTL_JAN_STAGE_05                = 0x05,
    BTL_JAN_STAGE_06                = 0x06,
    BTL_JAN_STAGE_07                = 0x07,
    BTL_JAN2_STAGE_00               = 0x00,
    BTL_JAN2_STAGE_01               = 0x01,
    BTL_JAN2_STAGE_02               = 0x02,
    BTL_JAN2_STAGE_03               = 0x03,
    BTL_JAN2_STAGE_04               = 0x04,
    BTL_JAN2_STAGE_05               = 0x05,
    BTL_JAN2_STAGE_06               = 0x06,
    BTL_JAN2_STAGE_07               = 0x07,
    BTL_KZN_STAGE_00                = 0x00,
    BTL_KZN_STAGE_01                = 0x01,
    BTL_KZN_STAGE_02                = 0x02,
    BTL_KZN_STAGE_03                = 0x03,
    BTL_KZN_STAGE_04                = 0x04,
    BTL_KZN_STAGE_05                = 0x05,
    BTL_KZN_STAGE_06                = 0x06,
    BTL_KZN2_STAGE_00               = 0x00,
    BTL_KZN2_STAGE_01               = 0x01,
    BTL_KZN2_STAGE_02               = 0x02,
    BTL_KZN2_STAGE_03               = 0x03,
    BTL_KZN2_STAGE_04               = 0x04,
    BTL_KZN2_STAGE_05               = 0x05,
    BTL_KZN2_STAGE_06               = 0x06,
    BTL_FLO_STAGE_00                = 0x00,
    BTL_FLO_STAGE_01                = 0x01,
    BTL_FLO_STAGE_02                = 0x02,
    BTL_FLO_STAGE_03                = 0x03,
    BTL_FLO_STAGE_04                = 0x04,
    BTL_FLO_STAGE_05                = 0x05,
    BTL_FLO_STAGE_06                = 0x06,
    BTL_FLO_STAGE_07                = 0x07,
    BTL_FLO_STAGE_08                = 0x08,
    BTL_FLO_STAGE_09                = 0x09,
    BTL_FLO2_STAGE_00               = 0x00,
    BTL_FLO2_STAGE_01               = 0x01,
    BTL_FLO2_STAGE_02               = 0x02,
    BTL_FLO2_STAGE_03               = 0x03,
    BTL_FLO2_STAGE_04               = 0x04,
    BTL_FLO2_STAGE_05               = 0x05,
    BTL_FLO2_STAGE_06               = 0x06,
    BTL_FLO2_STAGE_07               = 0x07,
    BTL_FLO2_STAGE_08               = 0x08,
    BTL_FLO2_STAGE_09               = 0x09,
    BTL_TIK_STAGE_00                = 0x00,
    BTL_TIK_STAGE_01                = 0x01,
    BTL_TIK_STAGE_02                = 0x02,
    BTL_TIK_STAGE_03                = 0x03,
    BTL_TIK_STAGE_04                = 0x04,
    BTL_TIK2_STAGE_00               = 0x00,
    BTL_TIK2_STAGE_01               = 0x01,
    BTL_TIK2_STAGE_02               = 0x02,
    BTL_TIK2_STAGE_03               = 0x03,
    BTL_TIK2_STAGE_04               = 0x04,
    BTL_TIK3_STAGE_00               = 0x00,
    BTL_TIK3_STAGE_01               = 0x01,
    BTL_TIK3_STAGE_02               = 0x02,
    BTL_TIK3_STAGE_03               = 0x03,
    BTL_TIK3_STAGE_04               = 0x04,
    BTL_SAM_STAGE_00                = 0x00,
    BTL_SAM_STAGE_01                = 0x01,
    BTL_SAM_STAGE_02                = 0x02,
    BTL_SAM_STAGE_03                = 0x03,
    BTL_SAM_STAGE_04                = 0x04,
    BTL_SAM_STAGE_05                = 0x05,
    BTL_SAM2_STAGE_00               = 0x00,
    BTL_SAM2_STAGE_01               = 0x01,
    BTL_SAM2_STAGE_02               = 0x02,
    BTL_SAM2_STAGE_03               = 0x03,
    BTL_SAM2_STAGE_04               = 0x04,
    BTL_SAM2_STAGE_05               = 0x05,
    BTL_PRA_STAGE_00                = 0x00,
    BTL_PRA_STAGE_01                = 0x01,
    BTL_PRA_STAGE_02                = 0x02,
    BTL_PRA_STAGE_03                = 0x03,
    BTL_PRA_STAGE_04                = 0x04,
    BTL_PRA_STAGE_05                = 0x05,
    BTL_PRA2_STAGE_00               = 0x00,
    BTL_PRA3_STAGE_00               = 0x00,
    BTL_PRA3_STAGE_01               = 0x01,
    BTL_PRA3_STAGE_02               = 0x02,
    BTL_PRA3_STAGE_03               = 0x03,
    BTL_PRA3_STAGE_04               = 0x04,
    BTL_PRA3_STAGE_05               = 0x05,
    BTL_KPA_STAGE_00                = 0x00,
    BTL_KPA_STAGE_01                = 0x01,
    BTL_KPA_STAGE_02                = 0x02,
    BTL_KPA_STAGE_03                = 0x03,
    BTL_KPA_STAGE_04                = 0x04,
    BTL_KPA_STAGE_05                = 0x05,
    BTL_KPA_STAGE_06                = 0x06,
    BTL_KPA_STAGE_07                = 0x07,
    BTL_KPA_STAGE_08                = 0x08,
    BTL_KPA_STAGE_09                = 0x09,
    BTL_KPA_STAGE_0A                = 0x0A,
    BTL_KPA_STAGE_0B                = 0x0B,
    BTL_KPA_STAGE_0C                = 0x0C,
    BTL_KPA_STAGE_0D                = 0x0D,
    BTL_KPA2_STAGE_00               = 0x00,
    BTL_KPA2_STAGE_01               = 0x01,
    BTL_KPA2_STAGE_02               = 0x02,
    BTL_KPA3_STAGE_00               = 0x00,
    BTL_KPA4_STAGE_00               = 0x00,
    BTL_KPA4_STAGE_01               = 0x01,
    BTL_KPA4_STAGE_02               = 0x02,
    BTL_KPA4_STAGE_03               = 0x03,
    BTL_KPA4_STAGE_04               = 0x04,
    BTL_KPA4_STAGE_05               = 0x05,
    BTL_KPA4_STAGE_06               = 0x06,
    BTL_KPA4_STAGE_07               = 0x07,
    BTL_KPA4_STAGE_08               = 0x08,
    BTL_KPA4_STAGE_09               = 0x09,
    BTL_KPA4_STAGE_0A               = 0x0A,
    BTL_KPA4_STAGE_0B               = 0x0B,
    BTL_KPA4_STAGE_0C               = 0x0C,
    BTL_KKJ_STAGE_00                = 0x00,
    BTL_DIG_STAGE_00                = 0x00,
    BTL_DIG_STAGE_01                = 0x01,
    BTL_DIG_STAGE_02                = 0x02,
    BTL_DIG_STAGE_03                = 0x03,
    BTL_DIG_STAGE_04                = 0x04,
};
