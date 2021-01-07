.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004C20C
/* 35A12C E004C20C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 35A130 E004C210 AFBF0010 */  sw        $ra, 0x10($sp)
/* 35A134 E004C214 8C85000C */  lw        $a1, 0xc($a0)
/* 35A138 E004C218 8CA20018 */  lw        $v0, 0x18($a1)
/* 35A13C E004C21C 2442FFFF */  addiu     $v0, $v0, -1
/* 35A140 E004C220 ACA20018 */  sw        $v0, 0x18($a1)
/* 35A144 E004C224 8CA2001C */  lw        $v0, 0x1c($a1)
/* 35A148 E004C228 8CA60018 */  lw        $a2, 0x18($a1)
/* 35A14C E004C22C 24420001 */  addiu     $v0, $v0, 1
/* 35A150 E004C230 04C10005 */  bgez      $a2, .LE004C248
/* 35A154 E004C234 ACA2001C */   sw       $v0, 0x1c($a1)
/* 35A158 E004C238 0C080128 */  jal       func_E02004A0
/* 35A15C E004C23C 00000000 */   nop      
/* 35A160 E004C240 080130D6 */  j         .LE004C358
/* 35A164 E004C244 00000000 */   nop      
.LE004C248:
/* 35A168 E004C248 28C20006 */  slti      $v0, $a2, 6
/* 35A16C E004C24C 1440001E */  bnez      $v0, .LE004C2C8
/* 35A170 E004C250 28C2000A */   slti     $v0, $a2, 0xa
/* 35A174 E004C254 240200FF */  addiu     $v0, $zero, 0xff
/* 35A178 E004C258 8CA30014 */  lw        $v1, 0x14($a1)
/* 35A17C E004C25C 3C01E005 */  lui       $at, %hi(D_E004C6B0)
/* 35A180 E004C260 D424C6B0 */  ldc1      $f4, %lo(D_E004C6B0)($at)
/* 35A184 E004C264 00431023 */  subu      $v0, $v0, $v1
/* 35A188 E004C268 44823000 */  mtc1      $v0, $f6
/* 35A18C E004C26C 00000000 */  nop       
/* 35A190 E004C270 468031A1 */  cvt.d.w   $f6, $f6
/* 35A194 E004C274 46243182 */  mul.d     $f6, $f6, $f4
/* 35A198 E004C278 00000000 */  nop       
/* 35A19C E004C27C C4A20010 */  lwc1      $f2, 0x10($a1)
/* 35A1A0 E004C280 3C013F80 */  lui       $at, 0x3f80
/* 35A1A4 E004C284 44810000 */  mtc1      $at, $f0
/* 35A1A8 E004C288 00000000 */  nop       
/* 35A1AC E004C28C 46020001 */  sub.s     $f0, $f0, $f2
/* 35A1B0 E004C290 46000021 */  cvt.d.s   $f0, $f0
/* 35A1B4 E004C294 46240002 */  mul.d     $f0, $f0, $f4
/* 35A1B8 E004C298 00000000 */  nop       
/* 35A1BC E004C29C 44832000 */  mtc1      $v1, $f4
/* 35A1C0 E004C2A0 00000000 */  nop       
/* 35A1C4 E004C2A4 46802121 */  cvt.d.w   $f4, $f4
/* 35A1C8 E004C2A8 46262100 */  add.d     $f4, $f4, $f6
/* 35A1CC E004C2AC 460010A1 */  cvt.d.s   $f2, $f2
/* 35A1D0 E004C2B0 46201080 */  add.d     $f2, $f2, $f0
/* 35A1D4 E004C2B4 4620238D */  trunc.w.d $f14, $f4
/* 35A1D8 E004C2B8 E4AE0014 */  swc1      $f14, 0x14($a1)
/* 35A1DC E004C2BC 462010A0 */  cvt.s.d   $f2, $f2
/* 35A1E0 E004C2C0 E4A20010 */  swc1      $f2, 0x10($a1)
/* 35A1E4 E004C2C4 28C2000A */  slti      $v0, $a2, 0xa
.LE004C2C8:
/* 35A1E8 E004C2C8 10400005 */  beqz      $v0, .LE004C2E0
/* 35A1EC E004C2CC 00061040 */   sll      $v0, $a2, 1
/* 35A1F0 E004C2D0 00461021 */  addu      $v0, $v0, $a2
/* 35A1F4 E004C2D4 000210C0 */  sll       $v0, $v0, 3
/* 35A1F8 E004C2D8 00461021 */  addu      $v0, $v0, $a2
/* 35A1FC E004C2DC ACA20014 */  sw        $v0, 0x14($a1)
.LE004C2E0:
/* 35A200 E004C2E0 C4A60024 */  lwc1      $f6, 0x24($a1)
/* 35A204 E004C2E4 C4A4002C */  lwc1      $f4, 0x2c($a1)
/* 35A208 E004C2E8 46062101 */  sub.s     $f4, $f4, $f6
/* 35A20C E004C2EC 3C01E005 */  lui       $at, %hi(D_E004C6B8)
/* 35A210 E004C2F0 D428C6B8 */  ldc1      $f8, %lo(D_E004C6B8)($at)
/* 35A214 E004C2F4 46002121 */  cvt.d.s   $f4, $f4
/* 35A218 E004C2F8 46282102 */  mul.d     $f4, $f4, $f8
/* 35A21C E004C2FC 00000000 */  nop       
/* 35A220 E004C300 C4A20028 */  lwc1      $f2, 0x28($a1)
/* 35A224 E004C304 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 35A228 E004C308 46020001 */  sub.s     $f0, $f0, $f2
/* 35A22C E004C30C 46000021 */  cvt.d.s   $f0, $f0
/* 35A230 E004C310 46280002 */  mul.d     $f0, $f0, $f8
/* 35A234 E004C314 00000000 */  nop       
/* 35A238 E004C318 C4AA0004 */  lwc1      $f10, 4($a1)
/* 35A23C E004C31C 46003206 */  mov.s     $f8, $f6
/* 35A240 E004C320 46085280 */  add.s     $f10, $f10, $f8
/* 35A244 E004C324 C4AC0008 */  lwc1      $f12, 8($a1)
/* 35A248 E004C328 46001206 */  mov.s     $f8, $f2
/* 35A24C E004C32C 46086300 */  add.s     $f12, $f12, $f8
/* 35A250 E004C330 460031A1 */  cvt.d.s   $f6, $f6
/* 35A254 E004C334 46243180 */  add.d     $f6, $f6, $f4
/* 35A258 E004C338 460010A1 */  cvt.d.s   $f2, $f2
/* 35A25C E004C33C E4AA0004 */  swc1      $f10, 4($a1)
/* 35A260 E004C340 46201080 */  add.d     $f2, $f2, $f0
/* 35A264 E004C344 E4AC0008 */  swc1      $f12, 8($a1)
/* 35A268 E004C348 462031A0 */  cvt.s.d   $f6, $f6
/* 35A26C E004C34C 462010A0 */  cvt.s.d   $f2, $f2
/* 35A270 E004C350 E4A60024 */  swc1      $f6, 0x24($a1)
/* 35A274 E004C354 E4A20028 */  swc1      $f2, 0x28($a1)
.LE004C358:
/* 35A278 E004C358 8FBF0010 */  lw        $ra, 0x10($sp)
/* 35A27C E004C35C 03E00008 */  jr        $ra
/* 35A280 E004C360 27BD0018 */   addiu    $sp, $sp, 0x18
