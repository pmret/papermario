.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024EDEC
/* 17D6CC 8024EDEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D6D0 8024EDF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 17D6D4 8024EDF4 0000882D */  daddu     $s1, $zero, $zero
/* 17D6D8 8024EDF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D6DC 8024EDFC 3C10802A */  lui       $s0, 0x802a
/* 17D6E0 8024EE00 2610F2C0 */  addiu     $s0, $s0, -0xd40
/* 17D6E4 8024EE04 AFBF0018 */  sw        $ra, 0x18($sp)
.L8024EE08:
/* 17D6E8 8024EE08 8E040018 */  lw        $a0, 0x18($s0)
/* 17D6EC 8024EE0C 50800005 */  beql      $a0, $zero, .L8024EE24
/* 17D6F0 8024EE10 A6000010 */   sh       $zero, 0x10($s0)
/* 17D6F4 8024EE14 0C00AB4B */  jal       heap_free
/* 17D6F8 8024EE18 00000000 */   nop      
/* 17D6FC 8024EE1C AE000018 */  sw        $zero, 0x18($s0)
/* 17D700 8024EE20 A6000010 */  sh        $zero, 0x10($s0)
.L8024EE24:
/* 17D704 8024EE24 26310001 */  addiu     $s1, $s1, 1
/* 17D708 8024EE28 2A220020 */  slti      $v0, $s1, 0x20
/* 17D70C 8024EE2C 1440FFF6 */  bnez      $v0, .L8024EE08
/* 17D710 8024EE30 2610001C */   addiu    $s0, $s0, 0x1c
/* 17D714 8024EE34 8FBF0018 */  lw        $ra, 0x18($sp)
/* 17D718 8024EE38 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D71C 8024EE3C 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D720 8024EE40 03E00008 */  jr        $ra
/* 17D724 8024EE44 27BD0020 */   addiu    $sp, $sp, 0x20
