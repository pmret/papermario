.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_97B670
/* 97B670 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97B674 80240044 AFB20018 */  sw        $s2, 0x18($sp)
/* 97B678 80240048 0080902D */  daddu     $s2, $a0, $zero
/* 97B67C 8024004C AFBF001C */  sw        $ra, 0x1c($sp)
/* 97B680 80240050 AFB10014 */  sw        $s1, 0x14($sp)
/* 97B684 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* 97B688 80240058 8E510148 */  lw        $s1, 0x148($s2)
/* 97B68C 8024005C 0C00EABB */  jal       get_npc_unsafe
/* 97B690 80240060 86240008 */   lh       $a0, 8($s1)
/* 97B694 80240064 0040802D */  daddu     $s0, $v0, $zero
/* 97B698 80240068 8E2300CC */  lw        $v1, 0xcc($s1)
/* 97B69C 8024006C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 97B6A0 80240070 8C630020 */  lw        $v1, 0x20($v1)
/* 97B6A4 80240074 AE030028 */  sw        $v1, 0x28($s0)
/* 97B6A8 80240078 96220076 */  lhu       $v0, 0x76($s1)
/* 97B6AC 8024007C A602008E */  sh        $v0, 0x8e($s0)
/* 97B6B0 80240080 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 97B6B4 80240084 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 97B6B8 80240088 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 97B6BC 8024008C 8C460028 */  lw        $a2, 0x28($v0)
/* 97B6C0 80240090 0C00A720 */  jal       atan2
/* 97B6C4 80240094 8C470030 */   lw       $a3, 0x30($v0)
/* 97B6C8 80240098 2402000D */  addiu     $v0, $zero, 0xd
/* 97B6CC 8024009C E600000C */  swc1      $f0, 0xc($s0)
/* 97B6D0 802400A0 AE420070 */  sw        $v0, 0x70($s2)
/* 97B6D4 802400A4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97B6D8 802400A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 97B6DC 802400AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 97B6E0 802400B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 97B6E4 802400B4 03E00008 */  jr        $ra
/* 97B6E8 802400B8 27BD0020 */   addiu    $sp, $sp, 0x20
