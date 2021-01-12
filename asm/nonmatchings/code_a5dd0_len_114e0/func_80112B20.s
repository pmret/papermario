.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112B20
/* A9220 80112B20 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A9224 80112B24 27A20028 */  addiu     $v0, $sp, 0x28
/* A9228 80112B28 AFBF0030 */  sw        $ra, 0x30($sp)
/* A922C 80112B2C C4800048 */  lwc1      $f0, 0x48($a0)
/* A9230 80112B30 C482004C */  lwc1      $f2, 0x4c($a0)
/* A9234 80112B34 C4840050 */  lwc1      $f4, 0x50($a0)
/* A9238 80112B38 27A40018 */  addiu     $a0, $sp, 0x18
/* A923C 80112B3C 27A5001C */  addiu     $a1, $sp, 0x1c
/* A9240 80112B40 27A60020 */  addiu     $a2, $sp, 0x20
/* A9244 80112B44 27A70024 */  addiu     $a3, $sp, 0x24
/* A9248 80112B48 E7A00018 */  swc1      $f0, 0x18($sp)
/* A924C 80112B4C E7A2001C */  swc1      $f2, 0x1c($sp)
/* A9250 80112B50 E7A40020 */  swc1      $f4, 0x20($sp)
/* A9254 80112B54 AFA20010 */  sw        $v0, 0x10($sp)
/* A9258 80112B58 27A2002C */  addiu     $v0, $sp, 0x2c
/* A925C 80112B5C 0C04497A */  jal       func_801125E8
/* A9260 80112B60 AFA20014 */   sw       $v0, 0x14($sp)
/* A9264 80112B64 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A9268 80112B68 24027FFF */  addiu     $v0, $zero, 0x7fff
/* A926C 80112B6C 4600018D */  trunc.w.s $f6, $f0
/* A9270 80112B70 44033000 */  mfc1      $v1, $f6
/* A9274 80112B74 00000000 */  nop
/* A9278 80112B78 50620001 */  beql      $v1, $v0, .L80112B80
/* A927C 80112B7C 0000182D */   daddu    $v1, $zero, $zero
.L80112B80:
/* A9280 80112B80 8FBF0030 */  lw        $ra, 0x30($sp)
/* A9284 80112B84 0060102D */  daddu     $v0, $v1, $zero
/* A9288 80112B88 03E00008 */  jr        $ra
/* A928C 80112B8C 27BD0038 */   addiu    $sp, $sp, 0x38
