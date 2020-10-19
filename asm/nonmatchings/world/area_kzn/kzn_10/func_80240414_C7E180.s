.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240414_C7E594
/* C7E594 80240414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7E598 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* C7E59C 8024041C 0080802D */  daddu     $s0, $a0, $zero
/* C7E5A0 80240420 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C7E5A4 80240424 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C7E5A8 80240428 AFBF0014 */  sw        $ra, 0x14($sp)
/* C7E5AC 8024042C C4400028 */  lwc1      $f0, 0x28($v0)
/* C7E5B0 80240430 C6020084 */  lwc1      $f2, 0x84($s0)
/* C7E5B4 80240434 468010A0 */  cvt.s.w   $f2, $f2
/* C7E5B8 80240438 46001081 */  sub.s     $f2, $f2, $f0
/* C7E5BC 8024043C 46021082 */  mul.s     $f2, $f2, $f2
/* C7E5C0 80240440 00000000 */  nop       
/* C7E5C4 80240444 C440002C */  lwc1      $f0, 0x2c($v0)
/* C7E5C8 80240448 C604008C */  lwc1      $f4, 0x8c($s0)
/* C7E5CC 8024044C 46802120 */  cvt.s.w   $f4, $f4
/* C7E5D0 80240450 46002101 */  sub.s     $f4, $f4, $f0
/* C7E5D4 80240454 46042102 */  mul.s     $f4, $f4, $f4
/* C7E5D8 80240458 00000000 */  nop       
/* C7E5DC 8024045C C4460030 */  lwc1      $f6, 0x30($v0)
/* C7E5E0 80240460 44800000 */  mtc1      $zero, $f0
/* C7E5E4 80240464 00000000 */  nop       
/* C7E5E8 80240468 46060001 */  sub.s     $f0, $f0, $f6
/* C7E5EC 8024046C 46000002 */  mul.s     $f0, $f0, $f0
/* C7E5F0 80240470 00000000 */  nop       
/* C7E5F4 80240474 46041080 */  add.s     $f2, $f2, $f4
/* C7E5F8 80240478 46001300 */  add.s     $f12, $f2, $f0
/* C7E5FC 8024047C 46006004 */  sqrt.s    $f0, $f12
/* C7E600 80240480 46000032 */  c.eq.s    $f0, $f0
/* C7E604 80240484 00000000 */  nop       
/* C7E608 80240488 45010003 */  bc1t      .L80240498
/* C7E60C 8024048C 00000000 */   nop      
/* C7E610 80240490 0C0187BC */  jal       sqrtf
/* C7E614 80240494 00000000 */   nop      
.L80240498:
/* C7E618 80240498 4600020D */  trunc.w.s $f8, $f0
/* C7E61C 8024049C E6080094 */  swc1      $f8, 0x94($s0)
/* C7E620 802404A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* C7E624 802404A4 8FB00010 */  lw        $s0, 0x10($sp)
/* C7E628 802404A8 24020002 */  addiu     $v0, $zero, 2
/* C7E62C 802404AC 03E00008 */  jr        $ra
/* C7E630 802404B0 27BD0018 */   addiu    $sp, $sp, 0x18
