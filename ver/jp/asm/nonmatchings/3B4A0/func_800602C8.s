.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800602C8
/* 3B6C8 800602C8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3B6CC 800602CC AFB00040 */  sw        $s0, 0x40($sp)
/* 3B6D0 800602D0 27B00010 */  addiu     $s0, $sp, 0x10
/* 3B6D4 800602D4 A7A40028 */  sh        $a0, 0x28($sp)
/* 3B6D8 800602D8 0200202D */  daddu     $a0, $s0, $zero
/* 3B6DC 800602DC AFA50034 */  sw        $a1, 0x34($sp)
/* 3B6E0 800602E0 27A50038 */  addiu     $a1, $sp, 0x38
/* 3B6E4 800602E4 24060001 */  addiu     $a2, $zero, 1
/* 3B6E8 800602E8 AFBF0044 */  sw        $ra, 0x44($sp)
/* 3B6EC 800602EC 0C019554 */  jal       func_80065550
/* 3B6F0 800602F0 AFB0002C */   sw       $s0, 0x2c($sp)
/* 3B6F4 800602F4 3C04800E */  lui       $a0, %hi(D_800D91D4)
/* 3B6F8 800602F8 248491D4 */  addiu     $a0, $a0, %lo(D_800D91D4)
/* 3B6FC 800602FC 27A50028 */  addiu     $a1, $sp, 0x28
/* 3B700 80060300 0C0195FC */  jal       func_800657F0
/* 3B704 80060304 24060001 */   addiu    $a2, $zero, 1
/* 3B708 80060308 0200202D */  daddu     $a0, $s0, $zero
/* 3B70C 8006030C 0000282D */  daddu     $a1, $zero, $zero
/* 3B710 80060310 0C0195B0 */  jal       func_800656C0
/* 3B714 80060314 24060001 */   addiu    $a2, $zero, 1
/* 3B718 80060318 8FA20030 */  lw        $v0, 0x30($sp)
/* 3B71C 8006031C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 3B720 80060320 8FB00040 */  lw        $s0, 0x40($sp)
/* 3B724 80060324 03E00008 */  jr        $ra
/* 3B728 80060328 27BD0048 */   addiu    $sp, $sp, 0x48
