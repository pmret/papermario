.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240170_B7A1C0
/* B7A1C0 80240170 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B7A1C4 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* B7A1C8 80240178 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B7A1CC 8024017C 4485A000 */  mtc1      $a1, $f20
/* B7A1D0 80240180 AFBF0014 */  sw        $ra, 0x14($sp)
/* B7A1D4 80240184 0C019D28 */  jal       guMtxIdentF
/* B7A1D8 80240188 0080802D */   daddu    $s0, $a0, $zero
/* B7A1DC 8024018C 3C018024 */  lui       $at, %hi(func_80243870_96CA30)
/* B7A1E0 80240190 D4203870 */  ldc1      $f0, %lo(func_80243870_96CA30)($at)
/* B7A1E4 80240194 4600A521 */  cvt.d.s   $f20, $f20
/* B7A1E8 80240198 4620A502 */  mul.d     $f20, $f20, $f0
/* B7A1EC 8024019C 00000000 */  nop
/* B7A1F0 802401A0 3C013F80 */  lui       $at, 0x3f80
/* B7A1F4 802401A4 44810000 */  mtc1      $at, $f0
/* B7A1F8 802401A8 AE000018 */  sw        $zero, 0x18($s0)
/* B7A1FC 802401AC E6000014 */  swc1      $f0, 0x14($s0)
/* B7A200 802401B0 4620A520 */  cvt.s.d   $f20, $f20
/* B7A204 802401B4 E6140010 */  swc1      $f20, 0x10($s0)
/* B7A208 802401B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B7A20C 802401BC 8FB00010 */  lw        $s0, 0x10($sp)
/* B7A210 802401C0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B7A214 802401C4 03E00008 */  jr        $ra
/* B7A218 802401C8 27BD0020 */   addiu    $sp, $sp, 0x20
