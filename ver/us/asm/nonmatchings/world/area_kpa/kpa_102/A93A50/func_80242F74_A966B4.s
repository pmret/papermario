.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F74_A966B4
/* A966B4 80242F74 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A966B8 80242F78 AFB3003C */  sw        $s3, 0x3c($sp)
/* A966BC 80242F7C 0080982D */  daddu     $s3, $a0, $zero
/* A966C0 80242F80 AFBF0044 */  sw        $ra, 0x44($sp)
/* A966C4 80242F84 AFB40040 */  sw        $s4, 0x40($sp)
/* A966C8 80242F88 AFB20038 */  sw        $s2, 0x38($sp)
/* A966CC 80242F8C AFB10034 */  sw        $s1, 0x34($sp)
/* A966D0 80242F90 AFB00030 */  sw        $s0, 0x30($sp)
/* A966D4 80242F94 8E720148 */  lw        $s2, 0x148($s3)
/* A966D8 80242F98 00A0882D */  daddu     $s1, $a1, $zero
/* A966DC 80242F9C 86440008 */  lh        $a0, 8($s2)
/* A966E0 80242FA0 0C00EABB */  jal       get_npc_unsafe
/* A966E4 80242FA4 00C0A02D */   daddu    $s4, $a2, $zero
/* A966E8 80242FA8 0040802D */  daddu     $s0, $v0, $zero
/* A966EC 80242FAC 9602008E */  lhu       $v0, 0x8e($s0)
/* A966F0 80242FB0 2442FFFF */  addiu     $v0, $v0, -1
/* A966F4 80242FB4 A602008E */  sh        $v0, 0x8e($s0)
/* A966F8 80242FB8 00021400 */  sll       $v0, $v0, 0x10
/* A966FC 80242FBC 1C400032 */  bgtz      $v0, .L80243088
/* A96700 80242FC0 00000000 */   nop
/* A96704 80242FC4 0260202D */  daddu     $a0, $s3, $zero
/* A96708 80242FC8 8E250024 */  lw        $a1, 0x24($s1)
/* A9670C 80242FCC 8E260028 */  lw        $a2, 0x28($s1)
/* A96710 80242FD0 0C09074C */  jal       func_80241D30_A95470
/* A96714 80242FD4 0280382D */   daddu    $a3, $s4, $zero
/* A96718 80242FD8 0040882D */  daddu     $s1, $v0, $zero
/* A9671C 80242FDC 24020001 */  addiu     $v0, $zero, 1
/* A96720 80242FE0 1222001D */  beq       $s1, $v0, .L80243058
/* A96724 80242FE4 0200282D */   daddu    $a1, $s0, $zero
/* A96728 80242FE8 24040002 */  addiu     $a0, $zero, 2
/* A9672C 80242FEC 0000302D */  daddu     $a2, $zero, $zero
/* A96730 80242FF0 860300A8 */  lh        $v1, 0xa8($s0)
/* A96734 80242FF4 3C013F80 */  lui       $at, 0x3f80
/* A96738 80242FF8 44810000 */  mtc1      $at, $f0
/* A9673C 80242FFC 3C014000 */  lui       $at, 0x4000
/* A96740 80243000 44811000 */  mtc1      $at, $f2
/* A96744 80243004 3C01C1A0 */  lui       $at, 0xc1a0
/* A96748 80243008 44812000 */  mtc1      $at, $f4
/* A9674C 8024300C 2402000C */  addiu     $v0, $zero, 0xc
/* A96750 80243010 AFA2001C */  sw        $v0, 0x1c($sp)
/* A96754 80243014 44833000 */  mtc1      $v1, $f6
/* A96758 80243018 00000000 */  nop
/* A9675C 8024301C 468031A0 */  cvt.s.w   $f6, $f6
/* A96760 80243020 44073000 */  mfc1      $a3, $f6
/* A96764 80243024 27A20028 */  addiu     $v0, $sp, 0x28
/* A96768 80243028 AFA20020 */  sw        $v0, 0x20($sp)
/* A9676C 8024302C E7A00010 */  swc1      $f0, 0x10($sp)
/* A96770 80243030 E7A20014 */  swc1      $f2, 0x14($sp)
/* A96774 80243034 0C01BFA4 */  jal       fx_emote
/* A96778 80243038 E7A40018 */   swc1     $f4, 0x18($sp)
/* A9677C 8024303C 8E4200CC */  lw        $v0, 0xcc($s2)
/* A96780 80243040 8C430000 */  lw        $v1, ($v0)
/* A96784 80243044 2402000F */  addiu     $v0, $zero, 0xf
/* A96788 80243048 A602008E */  sh        $v0, 0x8e($s0)
/* A9678C 8024304C 24020032 */  addiu     $v0, $zero, 0x32
/* A96790 80243050 08090C21 */  j         .L80243084
/* A96794 80243054 AE030028 */   sw       $v1, 0x28($s0)
.L80243058:
/* A96798 80243058 0200202D */  daddu     $a0, $s0, $zero
/* A9679C 8024305C 240520D5 */  addiu     $a1, $zero, 0x20d5
/* A967A0 80243060 0C012530 */  jal       func_800494C0
/* A967A4 80243064 0000302D */   daddu    $a2, $zero, $zero
/* A967A8 80243068 86440008 */  lh        $a0, 8($s2)
/* A967AC 8024306C 0C00FB3A */  jal       get_enemy
/* A967B0 80243070 24840001 */   addiu    $a0, $a0, 1
/* A967B4 80243074 AC51006C */  sw        $s1, 0x6c($v0)
/* A967B8 80243078 24020014 */  addiu     $v0, $zero, 0x14
/* A967BC 8024307C A602008E */  sh        $v0, 0x8e($s0)
/* A967C0 80243080 24020018 */  addiu     $v0, $zero, 0x18
.L80243084:
/* A967C4 80243084 AE620070 */  sw        $v0, 0x70($s3)
.L80243088:
/* A967C8 80243088 8FBF0044 */  lw        $ra, 0x44($sp)
/* A967CC 8024308C 8FB40040 */  lw        $s4, 0x40($sp)
/* A967D0 80243090 8FB3003C */  lw        $s3, 0x3c($sp)
/* A967D4 80243094 8FB20038 */  lw        $s2, 0x38($sp)
/* A967D8 80243098 8FB10034 */  lw        $s1, 0x34($sp)
/* A967DC 8024309C 8FB00030 */  lw        $s0, 0x30($sp)
/* A967E0 802430A0 03E00008 */  jr        $ra
/* A967E4 802430A4 27BD0048 */   addiu    $sp, $sp, 0x48
