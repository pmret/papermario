.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801413F8
/* 0D7AF8 801413F8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0D7AFC 801413FC 240200EF */  addiu $v0, $zero, 0xef
/* 0D7B00 80141400 24040003 */  addiu $a0, $zero, 3
/* 0D7B04 80141404 0000282D */  daddu $a1, $zero, $zero
/* 0D7B08 80141408 00A0302D */  daddu $a2, $a1, $zero
/* 0D7B0C 8014140C 2407013F */  addiu $a3, $zero, 0x13f
/* 0D7B10 80141410 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0D7B14 80141414 0C00B8C5 */  jal   set_cam_viewport
/* 0D7B18 80141418 AFA20010 */   sw    $v0, 0x10($sp)
/* 0D7B1C 8014141C 3C02800B */  lui   $v0, 0x800b
/* 0D7B20 80141420 24421D80 */  addiu $v0, $v0, 0x1d80
/* 0D7B24 80141424 3C014320 */  lui   $at, 0x4320
/* 0D7B28 80141428 44810000 */  mtc1  $at, $f0
/* 0D7B2C 8014142C 3C01C2F0 */  lui   $at, 0xc2f0
/* 0D7B30 80141430 44811000 */  mtc1  $at, $f2
/* 0D7B34 80141434 3C013F80 */  lui   $at, 0x3f80
/* 0D7B38 80141438 44812000 */  mtc1  $at, $f4
/* 0D7B3C 8014143C 94441008 */  lhu   $a0, 0x1008($v0)
/* 0D7B40 80141440 24030002 */  addiu $v1, $zero, 2
/* 0D7B44 80141444 A443100C */  sh    $v1, 0x100c($v0)
/* 0D7B48 80141448 24030001 */  addiu $v1, $zero, 1
/* 0D7B4C 8014144C A443100E */  sh    $v1, 0x100e($v0)
/* 0D7B50 80141450 24033CBF */  addiu $v1, $zero, 0x3cbf
/* 0D7B54 80141454 A4431028 */  sh    $v1, 0x1028($v0)
/* 0D7B58 80141458 24030010 */  addiu $v1, $zero, 0x10
/* 0D7B5C 8014145C A443101A */  sh    $v1, 0x101a($v0)
/* 0D7B60 80141460 24034000 */  addiu $v1, $zero, 0x4000
/* 0D7B64 80141464 A4401024 */  sh    $zero, 0x1024($v0)
/* 0D7B68 80141468 A4401026 */  sh    $zero, 0x1026($v0)
/* 0D7B6C 8014146C A440102A */  sh    $zero, 0x102a($v0)
/* 0D7B70 80141470 AC401064 */  sw    $zero, 0x1064($v0)
/* 0D7B74 80141474 A443101C */  sh    $v1, 0x101c($v0)
/* 0D7B78 80141478 A4401034 */  sh    $zero, 0x1034($v0)
/* 0D7B7C 8014147C A4401036 */  sh    $zero, 0x1036($v0)
/* 0D7B80 80141480 A4401038 */  sh    $zero, 0x1038($v0)
/* 0D7B84 80141484 3084FFF9 */  andi  $a0, $a0, 0xfff9
/* 0D7B88 80141488 E440105C */  swc1  $f0, 0x105c($v0)
/* 0D7B8C 8014148C E4421060 */  swc1  $f2, 0x1060($v0)
/* 0D7B90 80141490 E4441020 */  swc1  $f4, 0x1020($v0)
/* 0D7B94 80141494 A4441008 */  sh    $a0, 0x1008($v0)
/* 0D7B98 80141498 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0D7B9C 8014149C 03E00008 */  jr    $ra
/* 0D7BA0 801414A0 27BD0020 */   addiu $sp, $sp, 0x20

