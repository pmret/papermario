.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BA0_4E32E0
/* 4E32E0 80218BA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4E32E4 80218BA4 3C028022 */  lui       $v0, %hi(D_80224DB0)
/* 4E32E8 80218BA8 24424DB0 */  addiu     $v0, $v0, %lo(D_80224DB0)
/* 4E32EC 80218BAC 24040001 */  addiu     $a0, $zero, 1
/* 4E32F0 80218BB0 3C013E99 */  lui       $at, 0x3e99
/* 4E32F4 80218BB4 3421999A */  ori       $at, $at, 0x999a
/* 4E32F8 80218BB8 44810000 */  mtc1      $at, $f0
/* 4E32FC 80218BBC 3C064290 */  lui       $a2, 0x4290
/* 4E3300 80218BC0 3C07C312 */  lui       $a3, 0xc312
/* 4E3304 80218BC4 0000282D */  daddu     $a1, $zero, $zero
/* 4E3308 80218BC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E330C 80218BCC AFA20014 */  sw        $v0, 0x14($sp)
/* 4E3310 80218BD0 0C01C124 */  jal       func_80070490
/* 4E3314 80218BD4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4E3318 80218BD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E331C 80218BDC 24020002 */  addiu     $v0, $zero, 2
/* 4E3320 80218BE0 03E00008 */  jr        $ra
/* 4E3324 80218BE4 27BD0020 */   addiu    $sp, $sp, 0x20
