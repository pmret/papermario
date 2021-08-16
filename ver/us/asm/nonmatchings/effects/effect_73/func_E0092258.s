.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0092258
/* 391F88 E0092258 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 391F8C E009225C 3C02E009 */  lui       $v0, %hi(func_E00922A0)
/* 391F90 E0092260 244222A0 */  addiu     $v0, $v0, %lo(func_E00922A0)
/* 391F94 E0092264 AFA2001C */  sw        $v0, 0x1c($sp)
/* 391F98 E0092268 2402000A */  addiu     $v0, $zero, 0xa
/* 391F9C E009226C AFA20014 */  sw        $v0, 0x14($sp)
/* 391FA0 E0092270 2402002D */  addiu     $v0, $zero, 0x2d
/* 391FA4 E0092274 AFA40018 */  sw        $a0, 0x18($sp)
/* 391FA8 E0092278 27A40010 */  addiu     $a0, $sp, 0x10
/* 391FAC E009227C AFBF0020 */  sw        $ra, 0x20($sp)
/* 391FB0 E0092280 0C080120 */  jal       func_E0200480
/* 391FB4 E0092284 AFA20010 */   sw       $v0, 0x10($sp)
/* 391FB8 E0092288 8C430000 */  lw        $v1, ($v0)
/* 391FBC E009228C 34630002 */  ori       $v1, $v1, 2
/* 391FC0 E0092290 AC430000 */  sw        $v1, ($v0)
/* 391FC4 E0092294 8FBF0020 */  lw        $ra, 0x20($sp)
/* 391FC8 E0092298 03E00008 */  jr        $ra
/* 391FCC E009229C 27BD0028 */   addiu    $sp, $sp, 0x28
