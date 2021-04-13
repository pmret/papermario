.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070B90
/* 4BF90 80070B90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BF94 80070B94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BF98 80070B98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BF9C 80070B9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BFA0 80070BA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BFA4 80070BA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BFA8 80070BA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BFAC 80070BAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BFB0 80070BB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BFB4 80070BB4 0C016885 */  jal       func_8005A214
/* 4BFB8 80070BB8 24040033 */   addiu    $a0, $zero, 0x33
/* 4BFBC 80070BBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BFC0 80070BC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BFC4 80070BC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BFC8 80070BC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BFCC 80070BCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BFD0 80070BD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BFD4 80070BD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BFD8 80070BD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BFDC 80070BDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BFE0 80070BE0 3C018008 */  lui       $at, %hi(D_8007F6A8)
/* 4BFE4 80070BE4 8C21F6A8 */  lw        $at, %lo(D_8007F6A8)($at)
/* 4BFE8 80070BE8 00200008 */  jr        $at
/* 4BFEC 80070BEC 00000000 */   nop
