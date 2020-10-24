.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024192C_910FDC
/* 910FDC 8024192C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 910FE0 80241930 AFB10014 */  sw        $s1, 0x14($sp)
/* 910FE4 80241934 0080882D */  daddu     $s1, $a0, $zero
/* 910FE8 80241938 AFBF0018 */  sw        $ra, 0x18($sp)
/* 910FEC 8024193C AFB00010 */  sw        $s0, 0x10($sp)
/* 910FF0 80241940 8E220148 */  lw        $v0, 0x148($s1)
/* 910FF4 80241944 0C00EABB */  jal       get_npc_unsafe
/* 910FF8 80241948 84440008 */   lh       $a0, 8($v0)
/* 910FFC 8024194C 0040802D */  daddu     $s0, $v0, $zero
/* 911000 80241950 0200202D */  daddu     $a0, $s0, $zero
/* 911004 80241954 0000302D */  daddu     $a2, $zero, $zero
/* 911008 80241958 2403FFFD */  addiu     $v1, $zero, -3
/* 91100C 8024195C 8E020000 */  lw        $v0, ($s0)
/* 911010 80241960 24050321 */  addiu     $a1, $zero, 0x321
/* 911014 80241964 00431024 */  and       $v0, $v0, $v1
/* 911018 80241968 0C012530 */  jal       func_800494C0
/* 91101C 8024196C AE020000 */   sw       $v0, ($s0)
/* 911020 80241970 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 911024 80241974 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 911028 80241978 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91102C 8024197C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 911030 80241980 8C460028 */  lw        $a2, 0x28($v0)
/* 911034 80241984 0C00A720 */  jal       atan2
/* 911038 80241988 8C470030 */   lw       $a3, 0x30($v0)
/* 91103C 8024198C 3C02002F */  lui       $v0, 0x2f
/* 911040 80241990 34420010 */  ori       $v0, $v0, 0x10
/* 911044 80241994 AE020028 */  sw        $v0, 0x28($s0)
/* 911048 80241998 2402000A */  addiu     $v0, $zero, 0xa
/* 91104C 8024199C A602008E */  sh        $v0, 0x8e($s0)
/* 911050 802419A0 2402000D */  addiu     $v0, $zero, 0xd
/* 911054 802419A4 E600000C */  swc1      $f0, 0xc($s0)
/* 911058 802419A8 AE220070 */  sw        $v0, 0x70($s1)
/* 91105C 802419AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 911060 802419B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 911064 802419B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 911068 802419B8 03E00008 */  jr        $ra
/* 91106C 802419BC 27BD0020 */   addiu    $sp, $sp, 0x20
