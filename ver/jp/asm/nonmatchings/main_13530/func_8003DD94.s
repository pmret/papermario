.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DD94
/* 19194 8003DD94 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19198 8003DD98 AFB00010 */  sw        $s0, 0x10($sp)
/* 1919C 8003DD9C 0080802D */  daddu     $s0, $a0, $zero
/* 191A0 8003DDA0 3C048007 */  lui       $a0, %hi(D_80077C08)
/* 191A4 8003DDA4 24847C08 */  addiu     $a0, $a0, %lo(D_80077C08)
/* 191A8 8003DDA8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 191AC 8003DDAC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 191B0 8003DDB0 94820000 */  lhu       $v0, ($a0)
/* 191B4 8003DDB4 24430001 */  addiu     $v1, $v0, 1
/* 191B8 8003DDB8 00021400 */  sll       $v0, $v0, 0x10
/* 191BC 8003DDBC 00021403 */  sra       $v0, $v0, 0x10
/* 191C0 8003DDC0 28420004 */  slti      $v0, $v0, 4
/* 191C4 8003DDC4 1440002D */  bnez      $v0, .L8003DE7C
/* 191C8 8003DDC8 A4830000 */   sh       $v1, ($a0)
/* 191CC 8003DDCC C60C000C */  lwc1      $f12, 0xc($s0)
/* 191D0 8003DDD0 A4800000 */  sh        $zero, ($a0)
/* 191D4 8003DDD4 0C00A6B9 */  jal       func_80029AE4
/* 191D8 8003DDD8 46006307 */   neg.s    $f12, $f12
/* 191DC 8003DDDC 3C0140C9 */  lui       $at, 0x40c9
/* 191E0 8003DDE0 34210FD0 */  ori       $at, $at, 0xfd0
/* 191E4 8003DDE4 44811000 */  mtc1      $at, $f2
/* 191E8 8003DDE8 00000000 */  nop
/* 191EC 8003DDEC 46020502 */  mul.s     $f20, $f0, $f2
/* 191F0 8003DDF0 00000000 */  nop
/* 191F4 8003DDF4 3C0143B4 */  lui       $at, 0x43b4
/* 191F8 8003DDF8 44810000 */  mtc1      $at, $f0
/* 191FC 8003DDFC 00000000 */  nop
/* 19200 8003DE00 4600A503 */  div.s     $f20, $f20, $f0
/* 19204 8003DE04 0C00A84B */  jal       func_8002A12C
/* 19208 8003DE08 4600A306 */   mov.s    $f12, $f20
/* 1920C 8003DE0C 4600A306 */  mov.s     $f12, $f20
/* 19210 8003DE10 0C00A864 */  jal       func_8002A190
/* 19214 8003DE14 46000506 */   mov.s    $f20, $f0
/* 19218 8003DE18 860200A6 */  lh        $v0, 0xa6($s0)
/* 1921C 8003DE1C 44821000 */  mtc1      $v0, $f2
/* 19220 8003DE20 00000000 */  nop
/* 19224 8003DE24 468010A0 */  cvt.s.w   $f2, $f2
/* 19228 8003DE28 46141502 */  mul.s     $f20, $f2, $f20
/* 1922C 8003DE2C 00000000 */  nop
/* 19230 8003DE30 46001082 */  mul.s     $f2, $f2, $f0
/* 19234 8003DE34 00000000 */  nop
/* 19238 8003DE38 3C013E4C */  lui       $at, 0x3e4c
/* 1923C 8003DE3C 3421CCCD */  ori       $at, $at, 0xcccd
/* 19240 8003DE40 44810000 */  mtc1      $at, $f0
/* 19244 8003DE44 00000000 */  nop
/* 19248 8003DE48 4600A502 */  mul.s     $f20, $f20, $f0
/* 1924C 8003DE4C 00000000 */  nop
/* 19250 8003DE50 46001082 */  mul.s     $f2, $f2, $f0
/* 19254 8003DE54 00000000 */  nop
/* 19258 8003DE58 C6000038 */  lwc1      $f0, 0x38($s0)
/* 1925C 8003DE5C 46140000 */  add.s     $f0, $f0, $f20
/* 19260 8003DE60 44050000 */  mfc1      $a1, $f0
/* 19264 8003DE64 C6000040 */  lwc1      $f0, 0x40($s0)
/* 19268 8003DE68 46020000 */  add.s     $f0, $f0, $f2
/* 1926C 8003DE6C 3C064220 */  lui       $a2, 0x4220
/* 19270 8003DE70 44070000 */  mfc1      $a3, $f0
/* 19274 8003DE74 0C01C23C */  jal       func_800708F0
/* 19278 8003DE78 24040001 */   addiu    $a0, $zero, 1
.L8003DE7C:
/* 1927C 8003DE7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19280 8003DE80 8FB00010 */  lw        $s0, 0x10($sp)
/* 19284 8003DE84 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 19288 8003DE88 03E00008 */  jr        $ra
/* 1928C 8003DE8C 27BD0020 */   addiu    $sp, $sp, 0x20
