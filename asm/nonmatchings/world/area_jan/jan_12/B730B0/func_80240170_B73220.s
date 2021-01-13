.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240170_B73220
/* B73220 80240170 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B73224 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* B73228 80240178 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B7322C 8024017C 4485A000 */  mtc1      $a1, $f20
/* B73230 80240180 AFBF0014 */  sw        $ra, 0x14($sp)
/* B73234 80240184 0C019D28 */  jal       guMtxIdentF
/* B73238 80240188 0080802D */   daddu    $s0, $a0, $zero
/* B7323C 8024018C 3C018024 */  lui       $at, %hi(D_802433B0)
/* B73240 80240190 D42033B0 */  ldc1      $f0, %lo(D_802433B0)($at)
/* B73244 80240194 4600A521 */  cvt.d.s   $f20, $f20
/* B73248 80240198 4620A502 */  mul.d     $f20, $f20, $f0
/* B7324C 8024019C 00000000 */  nop
/* B73250 802401A0 3C013F80 */  lui       $at, 0x3f80
/* B73254 802401A4 44810000 */  mtc1      $at, $f0
/* B73258 802401A8 AE000018 */  sw        $zero, 0x18($s0)
/* B7325C 802401AC E6000014 */  swc1      $f0, 0x14($s0)
/* B73260 802401B0 4620A520 */  cvt.s.d   $f20, $f20
/* B73264 802401B4 E6140010 */  swc1      $f20, 0x10($s0)
/* B73268 802401B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7326C 802401BC 8FB00010 */  lw        $s0, 0x10($sp)
/* B73270 802401C0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B73274 802401C4 03E00008 */  jr        $ra
/* B73278 802401C8 27BD0020 */   addiu    $sp, $sp, 0x20
