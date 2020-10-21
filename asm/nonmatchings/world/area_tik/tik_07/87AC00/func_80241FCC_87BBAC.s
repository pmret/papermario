.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FCC_87BBAC
/* 87BBAC 80241FCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87BBB0 80241FD0 AFB20018 */  sw        $s2, 0x18($sp)
/* 87BBB4 80241FD4 0080902D */  daddu     $s2, $a0, $zero
/* 87BBB8 80241FD8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 87BBBC 80241FDC AFB10014 */  sw        $s1, 0x14($sp)
/* 87BBC0 80241FE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 87BBC4 80241FE4 8E510148 */  lw        $s1, 0x148($s2)
/* 87BBC8 80241FE8 0C00EABB */  jal       get_npc_unsafe
/* 87BBCC 80241FEC 86240008 */   lh       $a0, 8($s1)
/* 87BBD0 80241FF0 0040802D */  daddu     $s0, $v0, $zero
/* 87BBD4 80241FF4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 87BBD8 80241FF8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 87BBDC 80241FFC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 87BBE0 80242000 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 87BBE4 80242004 A600008E */  sh        $zero, 0x8e($s0)
/* 87BBE8 80242008 8C460028 */  lw        $a2, 0x28($v0)
/* 87BBEC 8024200C 0C00A720 */  jal       atan2
/* 87BBF0 80242010 8C470030 */   lw       $a3, 0x30($v0)
/* 87BBF4 80242014 E600000C */  swc1      $f0, 0xc($s0)
/* 87BBF8 80242018 8E2200CC */  lw        $v0, 0xcc($s1)
/* 87BBFC 8024201C 8C420020 */  lw        $v0, 0x20($v0)
/* 87BC00 80242020 AE020028 */  sw        $v0, 0x28($s0)
/* 87BC04 80242024 2402000B */  addiu     $v0, $zero, 0xb
/* 87BC08 80242028 AE420070 */  sw        $v0, 0x70($s2)
/* 87BC0C 8024202C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 87BC10 80242030 8FB20018 */  lw        $s2, 0x18($sp)
/* 87BC14 80242034 8FB10014 */  lw        $s1, 0x14($sp)
/* 87BC18 80242038 8FB00010 */  lw        $s0, 0x10($sp)
/* 87BC1C 8024203C 03E00008 */  jr        $ra
/* 87BC20 80242040 27BD0020 */   addiu    $sp, $sp, 0x20
