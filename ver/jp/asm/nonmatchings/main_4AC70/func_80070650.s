.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070650
/* 4BA50 80070650 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BA54 80070654 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BA58 80070658 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BA5C 8007065C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BA60 80070660 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BA64 80070664 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BA68 80070668 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BA6C 8007066C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BA70 80070670 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BA74 80070674 0C016885 */  jal       func_8005A214
/* 4BA78 80070678 24040025 */   addiu    $a0, $zero, 0x25
/* 4BA7C 8007067C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BA80 80070680 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BA84 80070684 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BA88 80070688 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BA8C 8007068C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BA90 80070690 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BA94 80070694 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BA98 80070698 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BA9C 8007069C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BAA0 800706A0 3C018008 */  lui       $at, %hi(D_8007F558)
/* 4BAA4 800706A4 8C21F558 */  lw        $at, %lo(D_8007F558)($at)
/* 4BAA8 800706A8 00200008 */  jr        $at
/* 4BAAC 800706AC 00000000 */   nop
