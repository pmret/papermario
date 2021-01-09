.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002C3D0
/* 340250 E002C3D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 340254 E002C3D4 3C02E003 */  lui       $v0, %hi(func_E002C414)
/* 340258 E002C3D8 2442C414 */  addiu     $v0, $v0, %lo(func_E002C414)
/* 34025C E002C3DC AFA2001C */  sw        $v0, 0x1c($sp)
/* 340260 E002C3E0 2402002D */  addiu     $v0, $zero, 0x2d
/* 340264 E002C3E4 AFA40018 */  sw        $a0, 0x18($sp)
/* 340268 E002C3E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 34026C E002C3EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 340270 E002C3F0 AFA00014 */  sw        $zero, 0x14($sp)
/* 340274 E002C3F4 0C080120 */  jal       func_E0200480
/* 340278 E002C3F8 AFA20010 */   sw       $v0, 0x10($sp)
/* 34027C E002C3FC 8C430000 */  lw        $v1, ($v0)
/* 340280 E002C400 34630002 */  ori       $v1, $v1, 2
/* 340284 E002C404 AC430000 */  sw        $v1, ($v0)
/* 340288 E002C408 8FBF0020 */  lw        $ra, 0x20($sp)
/* 34028C E002C40C 03E00008 */  jr        $ra
/* 340290 E002C410 27BD0028 */   addiu    $sp, $sp, 0x28
