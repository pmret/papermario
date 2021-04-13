.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007238C
/* 3751DC E007238C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3751E0 E0072390 3C02E007 */  lui       $v0, %hi(func_E00723D4)
/* 3751E4 E0072394 244223D4 */  addiu     $v0, $v0, %lo(func_E00723D4)
/* 3751E8 E0072398 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3751EC E007239C 2402000A */  addiu     $v0, $zero, 0xa
/* 3751F0 E00723A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 3751F4 E00723A4 24020022 */  addiu     $v0, $zero, 0x22
/* 3751F8 E00723A8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3751FC E00723AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 375200 E00723B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 375204 E00723B4 0C080120 */  jal       func_E0200480
/* 375208 E00723B8 AFA20010 */   sw       $v0, 0x10($sp)
/* 37520C E00723BC 8C430000 */  lw        $v1, ($v0)
/* 375210 E00723C0 34630002 */  ori       $v1, $v1, 2
/* 375214 E00723C4 AC430000 */  sw        $v1, ($v0)
/* 375218 E00723C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37521C E00723CC 03E00008 */  jr        $ra
/* 375220 E00723D0 27BD0028 */   addiu    $sp, $sp, 0x28
