.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071790
/* 4CB90 80071790 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CB94 80071794 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CB98 80071798 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CB9C 8007179C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CBA0 800717A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CBA4 800717A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CBA8 800717A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CBAC 800717AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CBB0 800717B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CBB4 800717B4 0C016885 */  jal       func_8005A214
/* 4CBB8 800717B8 24040053 */   addiu    $a0, $zero, 0x53
/* 4CBBC 800717BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CBC0 800717C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CBC4 800717C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CBC8 800717C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CBCC 800717CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CBD0 800717D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CBD4 800717D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CBD8 800717D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CBDC 800717DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CBE0 800717E0 3C018008 */  lui       $at, %hi(D_8007F9A8)
/* 4CBE4 800717E4 8C21F9A8 */  lw        $at, %lo(D_8007F9A8)($at)
/* 4CBE8 800717E8 00200008 */  jr        $at
/* 4CBEC 800717EC 00000000 */   nop
