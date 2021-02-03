.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B90_59F270
/* 59F270 80218B90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F274 80218B94 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F278 80218B98 0080882D */  daddu     $s1, $a0, $zero
/* 59F27C 80218B9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F280 80218BA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F284 80218BA4 8E30000C */  lw        $s0, 0xc($s1)
/* 59F288 80218BA8 8E050000 */  lw        $a1, ($s0)
/* 59F28C 80218BAC 0C0B1EAF */  jal       get_variable
/* 59F290 80218BB0 26100004 */   addiu    $s0, $s0, 4
/* 59F294 80218BB4 00021080 */  sll       $v0, $v0, 2
/* 59F298 80218BB8 8E050000 */  lw        $a1, ($s0)
/* 59F29C 80218BBC 3C068022 */  lui       $a2, %hi(D_80222E20_5A9500)
/* 59F2A0 80218BC0 00C23021 */  addu      $a2, $a2, $v0
/* 59F2A4 80218BC4 8CC62E20 */  lw        $a2, %lo(D_80222E20_5A9500)($a2)
/* 59F2A8 80218BC8 0C0B2026 */  jal       set_variable
/* 59F2AC 80218BCC 0220202D */   daddu    $a0, $s1, $zero
/* 59F2B0 80218BD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F2B4 80218BD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F2B8 80218BD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F2BC 80218BDC 24020002 */  addiu     $v0, $zero, 2
/* 59F2C0 80218BE0 03E00008 */  jr        $ra
/* 59F2C4 80218BE4 27BD0020 */   addiu    $sp, $sp, 0x20
