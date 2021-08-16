.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AA3C0
/* 3AACE0 E00AA3C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3AACE4 E00AA3C4 3C02E00B */  lui       $v0, %hi(func_E00AA404)
/* 3AACE8 E00AA3C8 2442A404 */  addiu     $v0, $v0, %lo(func_E00AA404)
/* 3AACEC E00AA3CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3AACF0 E00AA3D0 2402002D */  addiu     $v0, $zero, 0x2d
/* 3AACF4 E00AA3D4 AFA40018 */  sw        $a0, 0x18($sp)
/* 3AACF8 E00AA3D8 27A40010 */  addiu     $a0, $sp, 0x10
/* 3AACFC E00AA3DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 3AAD00 E00AA3E0 AFA00014 */  sw        $zero, 0x14($sp)
/* 3AAD04 E00AA3E4 0C080120 */  jal       func_E0200480
/* 3AAD08 E00AA3E8 AFA20010 */   sw       $v0, 0x10($sp)
/* 3AAD0C E00AA3EC 8C430000 */  lw        $v1, ($v0)
/* 3AAD10 E00AA3F0 34630002 */  ori       $v1, $v1, 2
/* 3AAD14 E00AA3F4 AC430000 */  sw        $v1, ($v0)
/* 3AAD18 E00AA3F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3AAD1C E00AA3FC 03E00008 */  jr        $ra
/* 3AAD20 E00AA400 27BD0028 */   addiu    $sp, $sp, 0x28
