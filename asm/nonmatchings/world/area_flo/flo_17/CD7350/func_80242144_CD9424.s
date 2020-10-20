.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242144_CD9424
/* CD9424 80242144 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD9428 80242148 AFB20018 */  sw        $s2, 0x18($sp)
/* CD942C 8024214C 0080902D */  daddu     $s2, $a0, $zero
/* CD9430 80242150 AFBF001C */  sw        $ra, 0x1c($sp)
/* CD9434 80242154 AFB10014 */  sw        $s1, 0x14($sp)
/* CD9438 80242158 AFB00010 */  sw        $s0, 0x10($sp)
/* CD943C 8024215C 8E510148 */  lw        $s1, 0x148($s2)
/* CD9440 80242160 0C00EABB */  jal       get_npc_unsafe
/* CD9444 80242164 86240008 */   lh       $a0, 8($s1)
/* CD9448 80242168 0040802D */  daddu     $s0, $v0, $zero
/* CD944C 8024216C 8E2300CC */  lw        $v1, 0xcc($s1)
/* CD9450 80242170 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD9454 80242174 8C630020 */  lw        $v1, 0x20($v1)
/* CD9458 80242178 AE030028 */  sw        $v1, 0x28($s0)
/* CD945C 8024217C 96220076 */  lhu       $v0, 0x76($s1)
/* CD9460 80242180 A602008E */  sh        $v0, 0x8e($s0)
/* CD9464 80242184 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD9468 80242188 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD946C 8024218C C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD9470 80242190 8C460028 */  lw        $a2, 0x28($v0)
/* CD9474 80242194 0C00A720 */  jal       atan2
/* CD9478 80242198 8C470030 */   lw       $a3, 0x30($v0)
/* CD947C 8024219C 2402000D */  addiu     $v0, $zero, 0xd
/* CD9480 802421A0 E600000C */  swc1      $f0, 0xc($s0)
/* CD9484 802421A4 AE420070 */  sw        $v0, 0x70($s2)
/* CD9488 802421A8 8FBF001C */  lw        $ra, 0x1c($sp)
/* CD948C 802421AC 8FB20018 */  lw        $s2, 0x18($sp)
/* CD9490 802421B0 8FB10014 */  lw        $s1, 0x14($sp)
/* CD9494 802421B4 8FB00010 */  lw        $s0, 0x10($sp)
/* CD9498 802421B8 03E00008 */  jr        $ra
/* CD949C 802421BC 27BD0020 */   addiu    $sp, $sp, 0x20
