.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802466C0_EA6FC0
.double -583.0

dlabel D_802466C8_EA6FC8
.double 165.0

.section .text

glabel func_80243054_EA3954
/* EA3954 80243054 3C018024 */  lui       $at, %hi(D_802466C0_EA6FC0)
/* EA3958 80243058 D42266C0 */  ldc1      $f2, %lo(D_802466C0_EA6FC0)($at)
/* EA395C 8024305C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA3960 80243060 AFB00010 */  sw        $s0, 0x10($sp)
/* EA3964 80243064 0080802D */  daddu     $s0, $a0, $zero
/* EA3968 80243068 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA396C 8024306C C6000084 */  lwc1      $f0, 0x84($s0)
/* EA3970 80243070 46800021 */  cvt.d.w   $f0, $f0
/* EA3974 80243074 46201081 */  sub.d     $f2, $f2, $f0
/* EA3978 80243078 462010A0 */  cvt.s.d   $f2, $f2
/* EA397C 8024307C 46021082 */  mul.s     $f2, $f2, $f2
/* EA3980 80243080 00000000 */  nop
/* EA3984 80243084 3C018024 */  lui       $at, %hi(D_802466C8_EA6FC8)
/* EA3988 80243088 D42066C8 */  ldc1      $f0, %lo(D_802466C8_EA6FC8)($at)
/* EA398C 8024308C C604008C */  lwc1      $f4, 0x8c($s0)
/* EA3990 80243090 46802121 */  cvt.d.w   $f4, $f4
/* EA3994 80243094 46240001 */  sub.d     $f0, $f0, $f4
/* EA3998 80243098 46200020 */  cvt.s.d   $f0, $f0
/* EA399C 8024309C 46000002 */  mul.s     $f0, $f0, $f0
/* EA39A0 802430A0 00000000 */  nop
/* EA39A4 802430A4 46001300 */  add.s     $f12, $f2, $f0
/* EA39A8 802430A8 46006004 */  sqrt.s    $f0, $f12
/* EA39AC 802430AC 46000032 */  c.eq.s    $f0, $f0
/* EA39B0 802430B0 00000000 */  nop
/* EA39B4 802430B4 45030004 */  bc1tl     .L802430C8
/* EA39B8 802430B8 46000007 */   neg.s    $f0, $f0
/* EA39BC 802430BC 0C019C10 */  jal       dead_sqrtf
/* EA39C0 802430C0 00000000 */   nop
/* EA39C4 802430C4 46000007 */  neg.s     $f0, $f0
.L802430C8:
/* EA39C8 802430C8 4600018D */  trunc.w.s $f6, $f0
/* EA39CC 802430CC E6060090 */  swc1      $f6, 0x90($s0)
/* EA39D0 802430D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA39D4 802430D4 8FB00010 */  lw        $s0, 0x10($sp)
/* EA39D8 802430D8 24020002 */  addiu     $v0, $zero, 2
/* EA39DC 802430DC 03E00008 */  jr        $ra
/* EA39E0 802430E0 27BD0018 */   addiu    $sp, $sp, 0x18
