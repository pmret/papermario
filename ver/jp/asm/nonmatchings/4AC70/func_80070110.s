.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070110
/* 4B510 80070110 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B514 80070114 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B518 80070118 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B51C 8007011C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B520 80070120 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B524 80070124 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B528 80070128 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B52C 8007012C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B530 80070130 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B534 80070134 0C016885 */  jal       func_8005A214
/* 4B538 80070138 24040017 */   addiu    $a0, $zero, 0x17
/* 4B53C 8007013C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B540 80070140 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B544 80070144 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B548 80070148 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B54C 8007014C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B550 80070150 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B554 80070154 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B558 80070158 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B55C 8007015C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B560 80070160 3C018008 */  lui       $at, %hi(D_8007F408)
/* 4B564 80070164 8C21F408 */  lw        $at, %lo(D_8007F408)($at)
/* 4B568 80070168 00200008 */  jr        $at
/* 4B56C 8007016C 00000000 */   nop
