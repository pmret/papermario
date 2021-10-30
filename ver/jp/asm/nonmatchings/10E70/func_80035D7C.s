.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035D7C
/* 1117C 80035D7C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 11180 80035D80 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 11184 80035D84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 11188 80035D88 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1118C 80035D8C 804300AC */  lb        $v1, 0xac($v0)
/* 11190 80035D90 24020002 */  addiu     $v0, $zero, 2
/* 11194 80035D94 14620003 */  bne       $v1, $v0, .L80035DA4
/* 11198 80035D98 00000000 */   nop
/* 1119C 80035D9C 0C03A5B7 */  jal       func_800E96DC
/* 111A0 80035DA0 00000000 */   nop
.L80035DA4:
/* 111A4 80035DA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 111A8 80035DA8 03E00008 */  jr        $ra
/* 111AC 80035DAC 27BD0018 */   addiu    $sp, $sp, 0x18
