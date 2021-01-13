.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218CF4_5132C4
/* 5132C4 80218CF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5132C8 80218CF8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 5132CC 80218CFC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 5132D0 80218D00 2406FFFF */  addiu     $a2, $zero, -1
/* 5132D4 80218D04 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5132D8 80218D08 806200AE */  lb        $v0, 0xae($v1)
/* 5132DC 80218D0C 10460007 */  beq       $v0, $a2, .L80218D2C
/* 5132E0 80218D10 8C85000C */   lw       $a1, 0xc($a0)
/* 5132E4 80218D14 806200AF */  lb        $v0, 0xaf($v1)
/* 5132E8 80218D18 10460004 */  beq       $v0, $a2, .L80218D2C
/* 5132EC 80218D1C 00000000 */   nop
/* 5132F0 80218D20 806200B0 */  lb        $v0, 0xb0($v1)
/* 5132F4 80218D24 14460004 */  bne       $v0, $a2, .L80218D38
/* 5132F8 80218D28 00000000 */   nop
.L80218D2C:
/* 5132FC 80218D2C 8CA50000 */  lw        $a1, ($a1)
/* 513300 80218D30 0808634F */  j         .L80218D3C
/* 513304 80218D34 0000302D */   daddu    $a2, $zero, $zero
.L80218D38:
/* 513308 80218D38 8CA50000 */  lw        $a1, ($a1)
.L80218D3C:
/* 51330C 80218D3C 0C0B2026 */  jal       set_variable
/* 513310 80218D40 00000000 */   nop
/* 513314 80218D44 8FBF0010 */  lw        $ra, 0x10($sp)
/* 513318 80218D48 24020002 */  addiu     $v0, $zero, 2
/* 51331C 80218D4C 03E00008 */  jr        $ra
/* 513320 80218D50 27BD0018 */   addiu    $sp, $sp, 0x18
