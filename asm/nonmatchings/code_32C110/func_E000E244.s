.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000E244
/* 32C354 E000E244 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32C358 E000E248 3C02E001 */  lui       $v0, 0xe001
/* 32C35C E000E24C 2442E288 */  addiu     $v0, $v0, -0x1d78
/* 32C360 E000E250 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32C364 E000E254 24020028 */  addiu     $v0, $zero, 0x28
/* 32C368 E000E258 AFA40018 */  sw        $a0, 0x18($sp)
/* 32C36C E000E25C 27A40010 */  addiu     $a0, $sp, 0x10
/* 32C370 E000E260 AFBF0020 */  sw        $ra, 0x20($sp)
/* 32C374 E000E264 AFA00014 */  sw        $zero, 0x14($sp)
/* 32C378 E000E268 0C080120 */  jal       func_E0200480
/* 32C37C E000E26C AFA20010 */   sw       $v0, 0x10($sp)
/* 32C380 E000E270 8C430000 */  lw        $v1, ($v0)
/* 32C384 E000E274 34630002 */  ori       $v1, $v1, 2
/* 32C388 E000E278 AC430000 */  sw        $v1, ($v0)
/* 32C38C E000E27C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32C390 E000E280 03E00008 */  jr        $ra
/* 32C394 E000E284 27BD0028 */   addiu    $sp, $sp, 0x28
