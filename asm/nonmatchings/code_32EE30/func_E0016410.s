.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0016410
/* 32F240 E0016410 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32F244 E0016414 3C02E001 */  lui       $v0, %hi(D_E0016454)
/* 32F248 E0016418 24426454 */  addiu     $v0, $v0, %lo(D_E0016454)
/* 32F24C E001641C AFA2001C */  sw        $v0, 0x1c($sp)
/* 32F250 E0016420 24020028 */  addiu     $v0, $zero, 0x28
/* 32F254 E0016424 AFA40018 */  sw        $a0, 0x18($sp)
/* 32F258 E0016428 27A40010 */  addiu     $a0, $sp, 0x10
/* 32F25C E001642C AFBF0020 */  sw        $ra, 0x20($sp)
/* 32F260 E0016430 AFA00014 */  sw        $zero, 0x14($sp)
/* 32F264 E0016434 0C080120 */  jal       func_E0200480
/* 32F268 E0016438 AFA20010 */   sw       $v0, 0x10($sp)
/* 32F26C E001643C 8C430000 */  lw        $v1, ($v0)
/* 32F270 E0016440 34630002 */  ori       $v1, $v1, 2
/* 32F274 E0016444 AC430000 */  sw        $v1, ($v0)
/* 32F278 E0016448 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32F27C E001644C 03E00008 */  jr        $ra
/* 32F280 E0016450 27BD0028 */   addiu    $sp, $sp, 0x28
