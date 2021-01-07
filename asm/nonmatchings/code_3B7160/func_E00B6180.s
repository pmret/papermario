.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B6180
/* 3B72E0 E00B6180 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B72E4 E00B6184 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B72E8 E00B6188 8C830000 */  lw        $v1, ($a0)
/* 3B72EC E00B618C 8C85000C */  lw        $a1, 0xc($a0)
/* 3B72F0 E00B6190 30620010 */  andi      $v0, $v1, 0x10
/* 3B72F4 E00B6194 10400005 */  beqz      $v0, .LE00B61AC
/* 3B72F8 E00B6198 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B72FC E00B619C 00621024 */  and       $v0, $v1, $v0
/* 3B7300 E00B61A0 AC820000 */  sw        $v0, ($a0)
/* 3B7304 E00B61A4 24020010 */  addiu     $v0, $zero, 0x10
/* 3B7308 E00B61A8 ACA20010 */  sw        $v0, 0x10($a1)
.LE00B61AC:
/* 3B730C E00B61AC 8CA30010 */  lw        $v1, 0x10($a1)
/* 3B7310 E00B61B0 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B7314 E00B61B4 10400002 */  beqz      $v0, .LE00B61C0
/* 3B7318 E00B61B8 2462FFFF */   addiu    $v0, $v1, -1
/* 3B731C E00B61BC ACA20010 */  sw        $v0, 0x10($a1)
.LE00B61C0:
/* 3B7320 E00B61C0 8CA20014 */  lw        $v0, 0x14($a1)
/* 3B7324 E00B61C4 8CA30010 */  lw        $v1, 0x10($a1)
/* 3B7328 E00B61C8 24460001 */  addiu     $a2, $v0, 1
/* 3B732C E00B61CC 04610005 */  bgez      $v1, .LE00B61E4
/* 3B7330 E00B61D0 ACA60014 */   sw       $a2, 0x14($a1)
/* 3B7334 E00B61D4 0C080128 */  jal       func_E02004A0
/* 3B7338 E00B61D8 00000000 */   nop      
/* 3B733C E00B61DC 0802D8A4 */  j         .LE00B6290
/* 3B7340 E00B61E0 00000000 */   nop      
.LE00B61E4:
/* 3B7344 E00B61E4 28620010 */  slti      $v0, $v1, 0x10
/* 3B7348 E00B61E8 10400002 */  beqz      $v0, .LE00B61F4
/* 3B734C E00B61EC 00031100 */   sll      $v0, $v1, 4
/* 3B7350 E00B61F0 ACA20024 */  sw        $v0, 0x24($a1)
.LE00B61F4:
/* 3B7354 E00B61F4 28C20010 */  slti      $v0, $a2, 0x10
/* 3B7358 E00B61F8 10400003 */  beqz      $v0, .LE00B6208
/* 3B735C E00B61FC 00061100 */   sll      $v0, $a2, 4
/* 3B7360 E00B6200 2442000F */  addiu     $v0, $v0, 0xf
/* 3B7364 E00B6204 ACA20024 */  sw        $v0, 0x24($a1)
.LE00B6208:
/* 3B7368 E00B6208 0000202D */  daddu     $a0, $zero, $zero
/* 3B736C E00B620C 00A0182D */  daddu     $v1, $a1, $zero
/* 3B7370 E00B6210 3C01E00B */  lui       $at, %hi(D_E00B6758)
/* 3B7374 E00B6214 D42A6758 */  ldc1      $f10, %lo(D_E00B6758)($at)
/* 3B7378 E00B6218 3C0140A0 */  lui       $at, 0x40a0
/* 3B737C E00B621C 44816000 */  mtc1      $at, $f12
/* 3B7380 E00B6220 3C014014 */  lui       $at, 0x4014
/* 3B7384 E00B6224 44814800 */  mtc1      $at, $f9
/* 3B7388 E00B6228 44804000 */  mtc1      $zero, $f8
/* 3B738C E00B622C 3C01E00B */  lui       $at, %hi(D_E00B6760)
/* 3B7390 E00B6230 D4266760 */  ldc1      $f6, %lo(D_E00B6760)($at)
.LE00B6234:
/* 3B7394 E00B6234 C464005C */  lwc1      $f4, 0x5c($v1)
/* 3B7398 E00B6238 46002086 */  mov.s     $f2, $f4
/* 3B739C E00B623C 460010A1 */  cvt.d.s   $f2, $f2
/* 3B73A0 E00B6240 462A1080 */  add.d     $f2, $f2, $f10
/* 3B73A4 E00B6244 C460002C */  lwc1      $f0, 0x2c($v1)
/* 3B73A8 E00B6248 46040000 */  add.s     $f0, $f0, $f4
/* 3B73AC E00B624C 462010A0 */  cvt.s.d   $f2, $f2
/* 3B73B0 E00B6250 E460002C */  swc1      $f0, 0x2c($v1)
/* 3B73B4 E00B6254 4602603C */  c.lt.s    $f12, $f2
/* 3B73B8 E00B6258 00000000 */  nop       
/* 3B73BC E00B625C 45000008 */  bc1f      .LE00B6280
/* 3B73C0 E00B6260 E462005C */   swc1     $f2, 0x5c($v1)
/* 3B73C4 E00B6264 460010A1 */  cvt.d.s   $f2, $f2
/* 3B73C8 E00B6268 46224001 */  sub.d     $f0, $f8, $f2
/* 3B73CC E00B626C 46260002 */  mul.d     $f0, $f0, $f6
/* 3B73D0 E00B6270 00000000 */  nop       
/* 3B73D4 E00B6274 46201080 */  add.d     $f2, $f2, $f0
/* 3B73D8 E00B6278 462010A0 */  cvt.s.d   $f2, $f2
/* 3B73DC E00B627C E462005C */  swc1      $f2, 0x5c($v1)
.LE00B6280:
/* 3B73E0 E00B6280 24840001 */  addiu     $a0, $a0, 1
/* 3B73E4 E00B6284 2882000C */  slti      $v0, $a0, 0xc
/* 3B73E8 E00B6288 1440FFEA */  bnez      $v0, .LE00B6234
/* 3B73EC E00B628C 24630004 */   addiu    $v1, $v1, 4
.LE00B6290:
/* 3B73F0 E00B6290 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B73F4 E00B6294 03E00008 */  jr        $ra
/* 3B73F8 E00B6298 27BD0018 */   addiu    $sp, $sp, 0x18
