.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BC1D8
/* 3BA208 E00BC1D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3BA20C E00BC1DC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 3BA210 E00BC1E0 46006506 */  mov.s     $f20, $f12
/* 3BA214 E00BC1E4 4600A08D */  trunc.w.s $f2, $f20
/* 3BA218 E00BC1E8 44041000 */  mfc1      $a0, $f2
/* 3BA21C E00BC1EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BA220 E00BC1F0 0C080138 */  jal       shim_rand_int
/* 3BA224 E00BC1F4 00000000 */   nop
/* 3BA228 E00BC1F8 3C013FE0 */  lui       $at, 0x3fe0
/* 3BA22C E00BC1FC 44810800 */  mtc1      $at, $f1
/* 3BA230 E00BC200 44800000 */  mtc1      $zero, $f0
/* 3BA234 E00BC204 4600A521 */  cvt.d.s   $f20, $f20
/* 3BA238 E00BC208 4620A502 */  mul.d     $f20, $f20, $f0
/* 3BA23C E00BC20C 00000000 */  nop
/* 3BA240 E00BC210 44820000 */  mtc1      $v0, $f0
/* 3BA244 E00BC214 00000000 */  nop
/* 3BA248 E00BC218 46800020 */  cvt.s.w   $f0, $f0
/* 3BA24C E00BC21C 46000021 */  cvt.d.s   $f0, $f0
/* 3BA250 E00BC220 46340001 */  sub.d     $f0, $f0, $f20
/* 3BA254 E00BC224 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BA258 E00BC228 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 3BA25C E00BC22C 46200020 */  cvt.s.d   $f0, $f0
/* 3BA260 E00BC230 03E00008 */  jr        $ra
/* 3BA264 E00BC234 27BD0020 */   addiu    $sp, $sp, 0x20
