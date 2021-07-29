.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSetEventMesg
/* 40D50 80065950 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 40D54 80065954 AFB00010 */  sw        $s0, 0x10($sp)
/* 40D58 80065958 00808021 */  addu      $s0, $a0, $zero
/* 40D5C 8006595C AFB10014 */  sw        $s1, 0x14($sp)
/* 40D60 80065960 00A08821 */  addu      $s1, $a1, $zero
/* 40D64 80065964 AFB20018 */  sw        $s2, 0x18($sp)
/* 40D68 80065968 00C09021 */  addu      $s2, $a2, $zero
/* 40D6C 8006596C AFBF0020 */  sw        $ra, 0x20($sp)
/* 40D70 80065970 0C01ACD8 */  jal       osDisableInt
/* 40D74 80065974 AFB3001C */   sw       $s3, 0x1c($sp)
/* 40D78 80065978 001018C0 */  sll       $v1, $s0, 3
/* 40D7C 8006597C 3C04800E */  lui       $a0, %hi(D_800D9F80)
/* 40D80 80065980 24849F80 */  addiu     $a0, $a0, %lo(D_800D9F80)
/* 40D84 80065984 00641821 */  addu      $v1, $v1, $a0
/* 40D88 80065988 00409821 */  addu      $s3, $v0, $zero
/* 40D8C 8006598C 2402000E */  addiu     $v0, $zero, 0xe
/* 40D90 80065990 AC710000 */  sw        $s1, ($v1)
/* 40D94 80065994 16020010 */  bne       $s0, $v0, .L800659D8
/* 40D98 80065998 AC720004 */   sw       $s2, 4($v1)
/* 40D9C 8006599C 3C028009 */  lui       $v0, %hi(D_800958FC)
/* 40DA0 800659A0 8C4258FC */  lw        $v0, %lo(D_800958FC)($v0)
/* 40DA4 800659A4 1040000A */  beqz      $v0, .L800659D0
/* 40DA8 800659A8 24020001 */   addiu    $v0, $zero, 1
/* 40DAC 800659AC 3C028009 */  lui       $v0, %hi(__osPreNMI)
/* 40DB0 800659B0 8C424630 */  lw        $v0, %lo(__osPreNMI)($v0)
/* 40DB4 800659B4 14400006 */  bnez      $v0, .L800659D0
/* 40DB8 800659B8 24020001 */   addiu    $v0, $zero, 1
/* 40DBC 800659BC 02202021 */  addu      $a0, $s1, $zero
/* 40DC0 800659C0 02402821 */  addu      $a1, $s2, $zero
/* 40DC4 800659C4 0C019608 */  jal       osSendMesg
/* 40DC8 800659C8 00003021 */   addu     $a2, $zero, $zero
/* 40DCC 800659CC 24020001 */  addiu     $v0, $zero, 1
.L800659D0:
/* 40DD0 800659D0 3C018009 */  lui       $at, %hi(__osPreNMI)
/* 40DD4 800659D4 AC224630 */  sw        $v0, %lo(__osPreNMI)($at)
.L800659D8:
/* 40DD8 800659D8 0C01ACF4 */  jal       osRestoreInt
/* 40DDC 800659DC 02602021 */   addu     $a0, $s3, $zero
/* 40DE0 800659E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 40DE4 800659E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 40DE8 800659E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 40DEC 800659EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 40DF0 800659F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 40DF4 800659F4 03E00008 */  jr        $ra
/* 40DF8 800659F8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 40DFC 800659FC 00000000 */  nop
