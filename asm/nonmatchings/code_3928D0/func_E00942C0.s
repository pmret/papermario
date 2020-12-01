.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00942C0
/* 392B90 E00942C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 392B94 E00942C4 3C02E009 */  lui       $v0, %hi(D_E00942FC)
/* 392B98 E00942C8 244242FC */  addiu     $v0, $v0, %lo(D_E00942FC)
/* 392B9C E00942CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 392BA0 E00942D0 2402000A */  addiu     $v0, $zero, 0xa
/* 392BA4 E00942D4 AFA20014 */  sw        $v0, 0x14($sp)
/* 392BA8 E00942D8 24020022 */  addiu     $v0, $zero, 0x22
/* 392BAC E00942DC AFA40018 */  sw        $a0, 0x18($sp)
/* 392BB0 E00942E0 27A40010 */  addiu     $a0, $sp, 0x10
/* 392BB4 E00942E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 392BB8 E00942E8 0C080120 */  jal       func_E0200480
/* 392BBC E00942EC AFA20010 */   sw       $v0, 0x10($sp)
/* 392BC0 E00942F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 392BC4 E00942F4 03E00008 */  jr        $ra
/* 392BC8 E00942F8 27BD0028 */   addiu    $sp, $sp, 0x28
