.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_99CD80
/* 99CD80 802403F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 99CD84 802403F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 99CD88 802403F8 0080902D */  daddu     $s2, $a0, $zero
/* 99CD8C 802403FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 99CD90 80240400 AFB10014 */  sw        $s1, 0x14($sp)
/* 99CD94 80240404 AFB00010 */  sw        $s0, 0x10($sp)
/* 99CD98 80240408 8E510148 */  lw        $s1, 0x148($s2)
/* 99CD9C 8024040C 0C00EABB */  jal       get_npc_unsafe
/* 99CDA0 80240410 86240008 */   lh       $a0, 8($s1)
/* 99CDA4 80240414 0040802D */  daddu     $s0, $v0, $zero
/* 99CDA8 80240418 8E2300CC */  lw        $v1, 0xcc($s1)
/* 99CDAC 8024041C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 99CDB0 80240420 8C630020 */  lw        $v1, 0x20($v1)
/* 99CDB4 80240424 AE030028 */  sw        $v1, 0x28($s0)
/* 99CDB8 80240428 96220076 */  lhu       $v0, 0x76($s1)
/* 99CDBC 8024042C A602008E */  sh        $v0, 0x8e($s0)
/* 99CDC0 80240430 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 99CDC4 80240434 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 99CDC8 80240438 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 99CDCC 8024043C 8C460028 */  lw        $a2, 0x28($v0)
/* 99CDD0 80240440 0C00A720 */  jal       atan2
/* 99CDD4 80240444 8C470030 */   lw       $a3, 0x30($v0)
/* 99CDD8 80240448 2402000D */  addiu     $v0, $zero, 0xd
/* 99CDDC 8024044C E600000C */  swc1      $f0, 0xc($s0)
/* 99CDE0 80240450 AE420070 */  sw        $v0, 0x70($s2)
/* 99CDE4 80240454 8FBF001C */  lw        $ra, 0x1c($sp)
/* 99CDE8 80240458 8FB20018 */  lw        $s2, 0x18($sp)
/* 99CDEC 8024045C 8FB10014 */  lw        $s1, 0x14($sp)
/* 99CDF0 80240460 8FB00010 */  lw        $s0, 0x10($sp)
/* 99CDF4 80240464 03E00008 */  jr        $ra
/* 99CDF8 80240468 27BD0020 */   addiu    $sp, $sp, 0x20
