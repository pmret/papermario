.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DF0_59F4D0
/* 59F4D0 80218DF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F4D4 80218DF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F4D8 80218DF8 0080882D */  daddu     $s1, $a0, $zero
/* 59F4DC 80218DFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F4E0 80218E00 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F4E4 80218E04 8E30000C */  lw        $s0, 0xc($s1)
/* 59F4E8 80218E08 8E050000 */  lw        $a1, ($s0)
/* 59F4EC 80218E0C 0C0B1EAF */  jal       get_variable
/* 59F4F0 80218E10 26100004 */   addiu    $s0, $s0, 4
/* 59F4F4 80218E14 8E050000 */  lw        $a1, ($s0)
/* 59F4F8 80218E18 8C50000C */  lw        $s0, 0xc($v0)
/* 59F4FC 80218E1C 0C0B210B */  jal       evt_get_float_variable
/* 59F500 80218E20 0220202D */   daddu    $a0, $s1, $zero
/* 59F504 80218E24 E600002C */  swc1      $f0, 0x2c($s0)
/* 59F508 80218E28 E6000030 */  swc1      $f0, 0x30($s0)
/* 59F50C 80218E2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F510 80218E30 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F514 80218E34 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F518 80218E38 24020002 */  addiu     $v0, $zero, 2
/* 59F51C 80218E3C 03E00008 */  jr        $ra
/* 59F520 80218E40 27BD0020 */   addiu    $sp, $sp, 0x20
/* 59F524 80218E44 00000000 */  nop
/* 59F528 80218E48 00000000 */  nop
/* 59F52C 80218E4C 00000000 */  nop
