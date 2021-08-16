.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003A310
/* 34EF90 E003A310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 34EF94 E003A314 3C02E004 */  lui       $v0, %hi(func_E003A354)
/* 34EF98 E003A318 2442A354 */  addiu     $v0, $v0, %lo(func_E003A354)
/* 34EF9C E003A31C AFA2001C */  sw        $v0, 0x1c($sp)
/* 34EFA0 E003A320 24020028 */  addiu     $v0, $zero, 0x28
/* 34EFA4 E003A324 AFA40018 */  sw        $a0, 0x18($sp)
/* 34EFA8 E003A328 27A40010 */  addiu     $a0, $sp, 0x10
/* 34EFAC E003A32C AFBF0020 */  sw        $ra, 0x20($sp)
/* 34EFB0 E003A330 AFA00014 */  sw        $zero, 0x14($sp)
/* 34EFB4 E003A334 0C080120 */  jal       func_E0200480
/* 34EFB8 E003A338 AFA20010 */   sw       $v0, 0x10($sp)
/* 34EFBC E003A33C 8C430000 */  lw        $v1, ($v0)
/* 34EFC0 E003A340 34630002 */  ori       $v1, $v1, 2
/* 34EFC4 E003A344 AC430000 */  sw        $v1, ($v0)
/* 34EFC8 E003A348 8FBF0020 */  lw        $ra, 0x20($sp)
/* 34EFCC E003A34C 03E00008 */  jr        $ra
/* 34EFD0 E003A350 27BD0028 */   addiu    $sp, $sp, 0x28
