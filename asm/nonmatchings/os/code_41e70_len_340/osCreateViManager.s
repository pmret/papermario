.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osCreateViManager
/* 41E70 80066A70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 41E74 80066A74 AFB40028 */  sw        $s4, 0x28($sp)
/* 41E78 80066A78 3C148009 */  lui       $s4, 0x8009
/* 41E7C 80066A7C 26944680 */  addiu     $s4, $s4, 0x4680
/* 41E80 80066A80 AFBF002C */  sw        $ra, 0x2c($sp)
/* 41E84 80066A84 AFB30024 */  sw        $s3, 0x24($sp)
/* 41E88 80066A88 AFB20020 */  sw        $s2, 0x20($sp)
/* 41E8C 80066A8C AFB1001C */  sw        $s1, 0x1c($sp)
/* 41E90 80066A90 AFB00018 */  sw        $s0, 0x18($sp)
/* 41E94 80066A94 8E820000 */  lw        $v0, ($s4)
/* 41E98 80066A98 14400055 */  bnez      $v0, .L80066BF0
/* 41E9C 80066A9C 00808821 */   addu     $s1, $a0, $zero
/* 41EA0 80066AA0 0C019920 */  jal       osTimerServicesInit
/* 41EA4 80066AA4 2412FFFF */   addiu    $s2, $zero, -1
/* 41EA8 80066AA8 3C13800B */  lui       $s3, 0x800b
/* 41EAC 80066AAC 26730AD0 */  addiu     $s3, $s3, 0xad0
/* 41EB0 80066AB0 02602021 */  addu      $a0, $s3, $zero
/* 41EB4 80066AB4 3C05800B */  lui       $a1, 0x800b
/* 41EB8 80066AB8 24A50AE8 */  addiu     $a1, $a1, 0xae8
/* 41EBC 80066ABC 3C018009 */  lui       $at, 0x8009
/* 41EC0 80066AC0 AC20469C */  sw        $zero, 0x469c($at)
/* 41EC4 80066AC4 0C019560 */  jal       osCreateMesgQueue
/* 41EC8 80066AC8 24060005 */   addiu    $a2, $zero, 5
/* 41ECC 80066ACC 24040007 */  addiu     $a0, $zero, 7
/* 41ED0 80066AD0 3C06800B */  lui       $a2, 0x800b
/* 41ED4 80066AD4 24C60B00 */  addiu     $a2, $a2, 0xb00
/* 41ED8 80066AD8 2402000D */  addiu     $v0, $zero, 0xd
/* 41EDC 80066ADC 3C10800B */  lui       $s0, 0x800b
/* 41EE0 80066AE0 26100B18 */  addiu     $s0, $s0, 0xb18
/* 41EE4 80066AE4 A4C20000 */  sh        $v0, ($a2)
/* 41EE8 80066AE8 2402000E */  addiu     $v0, $zero, 0xe
/* 41EEC 80066AEC 3C01800B */  lui       $at, 0x800b
/* 41EF0 80066AF0 A0200B02 */  sb        $zero, 0xb02($at)
/* 41EF4 80066AF4 3C01800B */  lui       $at, 0x800b
/* 41EF8 80066AF8 AC200B04 */  sw        $zero, 0xb04($at)
/* 41EFC 80066AFC A6020000 */  sh        $v0, ($s0)
/* 41F00 80066B00 3C01800B */  lui       $at, 0x800b
/* 41F04 80066B04 A0200B1A */  sb        $zero, 0xb1a($at)
/* 41F08 80066B08 3C01800B */  lui       $at, 0x800b
/* 41F0C 80066B0C AC200B1C */  sw        $zero, 0xb1c($at)
/* 41F10 80066B10 0C019654 */  jal       osSetEventMesg
/* 41F14 80066B14 02602821 */   addu     $a1, $s3, $zero
/* 41F18 80066B18 24040003 */  addiu     $a0, $zero, 3
/* 41F1C 80066B1C 02602821 */  addu      $a1, $s3, $zero
/* 41F20 80066B20 0C019654 */  jal       osSetEventMesg
/* 41F24 80066B24 02003021 */   addu     $a2, $s0, $zero
/* 41F28 80066B28 0C0197CC */  jal       osGetThreadPri
/* 41F2C 80066B2C 00002021 */   addu     $a0, $zero, $zero
/* 41F30 80066B30 00401821 */  addu      $v1, $v0, $zero
/* 41F34 80066B34 0071102A */  slt       $v0, $v1, $s1
/* 41F38 80066B38 10400005 */  beqz      $v0, .L80066B50
/* 41F3C 80066B3C 00000000 */   nop      
/* 41F40 80066B40 00609021 */  addu      $s2, $v1, $zero
/* 41F44 80066B44 00002021 */  addu      $a0, $zero, $zero
/* 41F48 80066B48 0C0197D4 */  jal       osSetThreadPri
/* 41F4C 80066B4C 02202821 */   addu     $a1, $s1, $zero
.L80066B50:
/* 41F50 80066B50 0C01ACD8 */  jal       __osDisableInt
/* 41F54 80066B54 00000000 */   nop      
/* 41F58 80066B58 3C10800B */  lui       $s0, 0x800b
/* 41F5C 80066B5C 2610F918 */  addiu     $s0, $s0, -0x6e8
/* 41F60 80066B60 02002021 */  addu      $a0, $s0, $zero
/* 41F64 80066B64 00002821 */  addu      $a1, $zero, $zero
/* 41F68 80066B68 3C068006 */  lui       $a2, %hi(viMgrMain)
/* 41F6C 80066B6C 24C66C10 */  addiu     $a2, $a2, %lo(viMgrMain)
/* 41F70 80066B70 24030001 */  addiu     $v1, $zero, 1
/* 41F74 80066B74 AE830000 */  sw        $v1, ($s4)
/* 41F78 80066B78 3C03800B */  lui       $v1, 0x800b
/* 41F7C 80066B7C 24630AD0 */  addiu     $v1, $v1, 0xad0
/* 41F80 80066B80 AFB10014 */  sw        $s1, 0x14($sp)
/* 41F84 80066B84 00408821 */  addu      $s1, $v0, $zero
/* 41F88 80066B88 02803821 */  addu      $a3, $s4, $zero
/* 41F8C 80066B8C 3C018009 */  lui       $at, 0x8009
/* 41F90 80066B90 AC304684 */  sw        $s0, 0x4684($at)
/* 41F94 80066B94 3C018009 */  lui       $at, 0x8009
/* 41F98 80066B98 AC334688 */  sw        $s3, 0x4688($at)
/* 41F9C 80066B9C 3C018009 */  lui       $at, 0x8009
/* 41FA0 80066BA0 AC33468C */  sw        $s3, 0x468c($at)
/* 41FA4 80066BA4 3C018009 */  lui       $at, 0x8009
/* 41FA8 80066BA8 AC204690 */  sw        $zero, 0x4690($at)
/* 41FAC 80066BAC 3C018009 */  lui       $at, 0x8009
/* 41FB0 80066BB0 AC204694 */  sw        $zero, 0x4694($at)
/* 41FB4 80066BB4 3C018009 */  lui       $at, 0x8009
/* 41FB8 80066BB8 AC204698 */  sw        $zero, 0x4698($at)
/* 41FBC 80066BBC 0C019798 */  jal       osCreateThread
/* 41FC0 80066BC0 AFA30010 */   sw       $v1, 0x10($sp)
/* 41FC4 80066BC4 0C01B2A4 */  jal       osViInit
/* 41FC8 80066BC8 00000000 */   nop      
/* 41FCC 80066BCC 0C019808 */  jal       osStartThread
/* 41FD0 80066BD0 02002021 */   addu     $a0, $s0, $zero
/* 41FD4 80066BD4 0C01ACF4 */  jal       __osRestoreInt
/* 41FD8 80066BD8 02202021 */   addu     $a0, $s1, $zero
/* 41FDC 80066BDC 2402FFFF */  addiu     $v0, $zero, -1
/* 41FE0 80066BE0 12420003 */  beq       $s2, $v0, .L80066BF0
/* 41FE4 80066BE4 00002021 */   addu     $a0, $zero, $zero
/* 41FE8 80066BE8 0C0197D4 */  jal       osSetThreadPri
/* 41FEC 80066BEC 02402821 */   addu     $a1, $s2, $zero
.L80066BF0:
/* 41FF0 80066BF0 8FBF002C */  lw        $ra, 0x2c($sp)
/* 41FF4 80066BF4 8FB40028 */  lw        $s4, 0x28($sp)
/* 41FF8 80066BF8 8FB30024 */  lw        $s3, 0x24($sp)
/* 41FFC 80066BFC 8FB20020 */  lw        $s2, 0x20($sp)
/* 42000 80066C00 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42004 80066C04 8FB00018 */  lw        $s0, 0x18($sp)
/* 42008 80066C08 03E00008 */  jr        $ra
/* 4200C 80066C0C 27BD0030 */   addiu    $sp, $sp, 0x30
