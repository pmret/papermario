.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AC124
/* 3AEF44 E00AC124 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AEF48 E00AC128 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AEF4C E00AC12C 8C85000C */  lw        $a1, 0xc($a0)
/* 3AEF50 E00AC130 8CA20014 */  lw        $v0, 0x14($a1)
/* 3AEF54 E00AC134 8CA60018 */  lw        $a2, 0x18($a1)
/* 3AEF58 E00AC138 2442FFFF */  addiu     $v0, $v0, -1
/* 3AEF5C E00AC13C ACA20014 */  sw        $v0, 0x14($a1)
/* 3AEF60 E00AC140 0040182D */  daddu     $v1, $v0, $zero
/* 3AEF64 E00AC144 24C20001 */  addiu     $v0, $a2, 1
/* 3AEF68 E00AC148 04610005 */  bgez      $v1, .LE00AC160
/* 3AEF6C E00AC14C ACA20018 */   sw       $v0, 0x18($a1)
/* 3AEF70 E00AC150 0C080128 */  jal       func_E02004A0
/* 3AEF74 E00AC154 00000000 */   nop      
/* 3AEF78 E00AC158 0802B09D */  j         .LE00AC274
/* 3AEF7C E00AC15C 00000000 */   nop      
.LE00AC160:
/* 3AEF80 E00AC160 8CA3001C */  lw        $v1, 0x1c($a1)
/* 3AEF84 E00AC164 24020001 */  addiu     $v0, $zero, 1
/* 3AEF88 E00AC168 14620019 */  bne       $v1, $v0, .LE00AC1D0
/* 3AEF8C E00AC16C 28C20021 */   slti     $v0, $a2, 0x21
/* 3AEF90 E00AC170 10400019 */  beqz      $v0, .LE00AC1D8
/* 3AEF94 E00AC174 00061040 */   sll      $v0, $a2, 1
/* 3AEF98 E00AC178 3C03E00B */  lui       $v1, %hi(D_E00AC83C)
/* 3AEF9C E00AC17C 2463C83C */  addiu     $v1, $v1, %lo(D_E00AC83C)
/* 3AEFA0 E00AC180 00431021 */  addu      $v0, $v0, $v1
/* 3AEFA4 E00AC184 90430000 */  lbu       $v1, ($v0)
/* 3AEFA8 E00AC188 ACA30024 */  sw        $v1, 0x24($a1)
/* 3AEFAC E00AC18C 90420001 */  lbu       $v0, 1($v0)
/* 3AEFB0 E00AC190 3C01E00B */  lui       $at, %hi(D_E00AC8D0)
/* 3AEFB4 E00AC194 D422C8D0 */  ldc1      $f2, %lo(D_E00AC8D0)($at)
/* 3AEFB8 E00AC198 44820000 */  mtc1      $v0, $f0
/* 3AEFBC E00AC19C 00000000 */  nop       
/* 3AEFC0 E00AC1A0 46800020 */  cvt.s.w   $f0, $f0
/* 3AEFC4 E00AC1A4 46000021 */  cvt.d.s   $f0, $f0
/* 3AEFC8 E00AC1A8 46220002 */  mul.d     $f0, $f0, $f2
/* 3AEFCC E00AC1AC 00000000 */  nop       
/* 3AEFD0 E00AC1B0 3C013F80 */  lui       $at, 0x3f80
/* 3AEFD4 E00AC1B4 44812000 */  mtc1      $at, $f4
/* 3AEFD8 E00AC1B8 46200020 */  cvt.s.d   $f0, $f0
/* 3AEFDC E00AC1BC 46002081 */  sub.s     $f2, $f4, $f0
/* 3AEFE0 E00AC1C0 46041080 */  add.s     $f2, $f2, $f4
/* 3AEFE4 E00AC1C4 E4A0002C */  swc1      $f0, 0x2c($a1)
/* 3AEFE8 E00AC1C8 0802B08F */  j         .LE00AC23C
/* 3AEFEC E00AC1CC E4A20028 */   swc1     $f2, 0x28($a1)
.LE00AC1D0:
/* 3AEFF0 E00AC1D0 14400005 */  bnez      $v0, .LE00AC1E8
/* 3AEFF4 E00AC1D4 00061040 */   sll      $v0, $a2, 1
.LE00AC1D8:
/* 3AEFF8 E00AC1D8 ACA00024 */  sw        $zero, 0x24($a1)
/* 3AEFFC E00AC1DC ACA00028 */  sw        $zero, 0x28($a1)
/* 3AF000 E00AC1E0 0802B08F */  j         .LE00AC23C
/* 3AF004 E00AC1E4 ACA0002C */   sw       $zero, 0x2c($a1)
.LE00AC1E8:
/* 3AF008 E00AC1E8 3C03E00B */  lui       $v1, %hi(D_E00AC7F8)
/* 3AF00C E00AC1EC 2463C7F8 */  addiu     $v1, $v1, %lo(D_E00AC7F8)
/* 3AF010 E00AC1F0 00431021 */  addu      $v0, $v0, $v1
/* 3AF014 E00AC1F4 90430000 */  lbu       $v1, ($v0)
/* 3AF018 E00AC1F8 ACA30024 */  sw        $v1, 0x24($a1)
/* 3AF01C E00AC1FC 90420001 */  lbu       $v0, 1($v0)
/* 3AF020 E00AC200 3C01E00B */  lui       $at, %hi(D_E00AC8D8)
/* 3AF024 E00AC204 D422C8D8 */  ldc1      $f2, %lo(D_E00AC8D8)($at)
/* 3AF028 E00AC208 44820000 */  mtc1      $v0, $f0
/* 3AF02C E00AC20C 00000000 */  nop       
/* 3AF030 E00AC210 46800020 */  cvt.s.w   $f0, $f0
/* 3AF034 E00AC214 46000021 */  cvt.d.s   $f0, $f0
/* 3AF038 E00AC218 46220002 */  mul.d     $f0, $f0, $f2
/* 3AF03C E00AC21C 00000000 */  nop       
/* 3AF040 E00AC220 3C013F80 */  lui       $at, 0x3f80
/* 3AF044 E00AC224 44812000 */  mtc1      $at, $f4
/* 3AF048 E00AC228 46200020 */  cvt.s.d   $f0, $f0
/* 3AF04C E00AC22C 46002081 */  sub.s     $f2, $f4, $f0
/* 3AF050 E00AC230 46041080 */  add.s     $f2, $f2, $f4
/* 3AF054 E00AC234 E4A00028 */  swc1      $f0, 0x28($a1)
/* 3AF058 E00AC238 E4A2002C */  swc1      $f2, 0x2c($a1)
.LE00AC23C:
/* 3AF05C E00AC23C ACA0003C */  sw        $zero, 0x3c($a1)
/* 3AF060 E00AC240 ACA00040 */  sw        $zero, 0x40($a1)
/* 3AF064 E00AC244 C4A60004 */  lwc1      $f6, 4($a1)
/* 3AF068 E00AC248 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 3AF06C E00AC24C C4A40008 */  lwc1      $f4, 8($a1)
/* 3AF070 E00AC250 46003180 */  add.s     $f6, $f6, $f0
/* 3AF074 E00AC254 C4A00038 */  lwc1      $f0, 0x38($a1)
/* 3AF078 E00AC258 C4A2000C */  lwc1      $f2, 0xc($a1)
/* 3AF07C E00AC25C 46002100 */  add.s     $f4, $f4, $f0
/* 3AF080 E00AC260 C4A00034 */  lwc1      $f0, 0x34($a1)
/* 3AF084 E00AC264 46001080 */  add.s     $f2, $f2, $f0
/* 3AF088 E00AC268 E4A60004 */  swc1      $f6, 4($a1)
/* 3AF08C E00AC26C E4A40008 */  swc1      $f4, 8($a1)
/* 3AF090 E00AC270 E4A2000C */  swc1      $f2, 0xc($a1)
.LE00AC274:
/* 3AF094 E00AC274 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AF098 E00AC278 03E00008 */  jr        $ra
/* 3AF09C E00AC27C 27BD0018 */   addiu    $sp, $sp, 0x18
