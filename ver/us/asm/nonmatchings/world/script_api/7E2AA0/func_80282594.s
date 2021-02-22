.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282594
/* 7E3414 80282594 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E3418 80282598 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E341C 8028259C 8C82000C */  lw        $v0, 0xc($a0)
/* 7E3420 802825A0 0C0B210B */  jal       get_float_variable
/* 7E3424 802825A4 8C450000 */   lw       $a1, ($v0)
/* 7E3428 802825A8 46000086 */  mov.s     $f2, $f0
/* 7E342C 802825AC 3C02800B */  lui       $v0, %hi(gCameras)
/* 7E3430 802825B0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 7E3434 802825B4 44800000 */  mtc1      $zero, $f0
/* 7E3438 802825B8 00000000 */  nop
/* 7E343C 802825BC 4602003E */  c.le.s    $f0, $f2
/* 7E3440 802825C0 00000000 */  nop
/* 7E3444 802825C4 45000006 */  bc1f      .L802825E0
/* 7E3448 802825C8 0040182D */   daddu    $v1, $v0, $zero
/* 7E344C 802825CC C4400490 */  lwc1      $f0, 0x490($v0)
/* 7E3450 802825D0 E4420490 */  swc1      $f2, 0x490($v0)
/* 7E3454 802825D4 3C018028 */  lui       $at, 0x8028
/* 7E3458 802825D8 080A097B */  j         .L802825EC
/* 7E345C 802825DC E4206540 */   swc1     $f0, 0x6540($at)
.L802825E0:
/* 7E3460 802825E0 3C018028 */  lui       $at, 0x8028
/* 7E3464 802825E4 C4206540 */  lwc1      $f0, 0x6540($at)
/* 7E3468 802825E8 E4600490 */  swc1      $f0, 0x490($v1)
.L802825EC:
/* 7E346C 802825EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E3470 802825F0 24020002 */  addiu     $v0, $zero, 2
/* 7E3474 802825F4 03E00008 */  jr        $ra
/* 7E3478 802825F8 27BD0018 */   addiu    $sp, $sp, 0x18
