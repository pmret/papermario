.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E6184
/* 3E0AB4 E00E6184 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3E0AB8 E00E6188 AFB20018 */  sw        $s2, 0x18($sp)
/* 3E0ABC E00E618C 0080902D */  daddu     $s2, $a0, $zero
/* 3E0AC0 E00E6190 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3E0AC4 E00E6194 AFB7002C */  sw        $s7, 0x2c($sp)
/* 3E0AC8 E00E6198 AFB60028 */  sw        $s6, 0x28($sp)
/* 3E0ACC E00E619C AFB50024 */  sw        $s5, 0x24($sp)
/* 3E0AD0 E00E61A0 AFB40020 */  sw        $s4, 0x20($sp)
/* 3E0AD4 E00E61A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3E0AD8 E00E61A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 3E0ADC E00E61AC AFB00010 */  sw        $s0, 0x10($sp)
/* 3E0AE0 E00E61B0 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3E0AE4 E00E61B4 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3E0AE8 E00E61B8 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3E0AEC E00E61BC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3E0AF0 E00E61C0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3E0AF4 E00E61C4 8E430000 */  lw        $v1, ($s2)
/* 3E0AF8 E00E61C8 8E45000C */  lw        $a1, 0xc($s2)
/* 3E0AFC E00E61CC 30620010 */  andi      $v0, $v1, 0x10
/* 3E0B00 E00E61D0 8CB30000 */  lw        $s3, ($a1)
/* 3E0B04 E00E61D4 10400005 */  beqz      $v0, .LE00E61EC
/* 3E0B08 E00E61D8 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3E0B0C E00E61DC 00621024 */  and       $v0, $v1, $v0
/* 3E0B10 E00E61E0 AE420000 */  sw        $v0, ($s2)
/* 3E0B14 E00E61E4 24020010 */  addiu     $v0, $zero, 0x10
/* 3E0B18 E00E61E8 ACA20028 */  sw        $v0, 0x28($a1)
.LE00E61EC:
/* 3E0B1C E00E61EC 8CA30028 */  lw        $v1, 0x28($a1)
/* 3E0B20 E00E61F0 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3E0B24 E00E61F4 10400002 */  beqz      $v0, .LE00E6200
/* 3E0B28 E00E61F8 2462FFFF */   addiu    $v0, $v1, -1
/* 3E0B2C E00E61FC ACA20028 */  sw        $v0, 0x28($a1)
.LE00E6200:
/* 3E0B30 E00E6200 8CA2002C */  lw        $v0, 0x2c($a1)
/* 3E0B34 E00E6204 8CA40028 */  lw        $a0, 0x28($a1)
/* 3E0B38 E00E6208 24420001 */  addiu     $v0, $v0, 1
/* 3E0B3C E00E620C 04810005 */  bgez      $a0, .LE00E6224
/* 3E0B40 E00E6210 ACA2002C */   sw       $v0, 0x2c($a1)
/* 3E0B44 E00E6214 0C080128 */  jal       shim_remove_effect
/* 3E0B48 E00E6218 0240202D */   daddu    $a0, $s2, $zero
/* 3E0B4C E00E621C 08039925 */  j         .LE00E6494
/* 3E0B50 E00E6220 00000000 */   nop
.LE00E6224:
/* 3E0B54 E00E6224 0040A82D */  daddu     $s5, $v0, $zero
/* 3E0B58 E00E6228 28820010 */  slti      $v0, $a0, 0x10
/* 3E0B5C E00E622C 10400002 */  beqz      $v0, .LE00E6238
/* 3E0B60 E00E6230 00041100 */   sll      $v0, $a0, 4
/* 3E0B64 E00E6234 ACA20030 */  sw        $v0, 0x30($a1)
.LE00E6238:
/* 3E0B68 E00E6238 16600009 */  bnez      $s3, .LE00E6260
/* 3E0B6C E00E623C 24A50038 */   addiu    $a1, $a1, 0x38
/* 3E0B70 E00E6240 3C013DCC */  lui       $at, 0x3dcc
/* 3E0B74 E00E6244 3421CCCD */  ori       $at, $at, 0xcccd
/* 3E0B78 E00E6248 4481C000 */  mtc1      $at, $f24
/* 3E0B7C E00E624C 3C013E4C */  lui       $at, 0x3e4c
/* 3E0B80 E00E6250 3421CCCD */  ori       $at, $at, 0xcccd
/* 3E0B84 E00E6254 4481B000 */  mtc1      $at, $f22
/* 3E0B88 E00E6258 0803989D */  j         .LE00E6274
/* 3E0B8C E00E625C 00000000 */   nop
.LE00E6260:
/* 3E0B90 E00E6260 3C013E4C */  lui       $at, 0x3e4c
/* 3E0B94 E00E6264 3421CCCD */  ori       $at, $at, 0xcccd
/* 3E0B98 E00E6268 4481B000 */  mtc1      $at, $f22
/* 3E0B9C E00E626C 00000000 */  nop
/* 3E0BA0 E00E6270 4600B606 */  mov.s     $f24, $f22
.LE00E6274:
/* 3E0BA4 E00E6274 8E420008 */  lw        $v0, 8($s2)
/* 3E0BA8 E00E6278 24110001 */  addiu     $s1, $zero, 1
/* 3E0BAC E00E627C 0222102A */  slt       $v0, $s1, $v0
/* 3E0BB0 E00E6280 10400084 */  beqz      $v0, .LE00E6494
/* 3E0BB4 E00E6284 00131080 */   sll      $v0, $s3, 2
/* 3E0BB8 E00E6288 3C03E00E */  lui       $v1, %hi(D_E00E6890)
/* 3E0BBC E00E628C 24636890 */  addiu     $v1, $v1, %lo(D_E00E6890)
/* 3E0BC0 E00E6290 0043A021 */  addu      $s4, $v0, $v1
/* 3E0BC4 E00E6294 3C17E00E */  lui       $s7, %hi(D_E00E6898)
/* 3E0BC8 E00E6298 26F76898 */  addiu     $s7, $s7, %lo(D_E00E6898)
/* 3E0BCC E00E629C 3C16E00E */  lui       $s6, %hi(D_E00E6910)
/* 3E0BD0 E00E62A0 26D66910 */  addiu     $s6, $s6, %lo(D_E00E6910)
/* 3E0BD4 E00E62A4 24B00014 */  addiu     $s0, $a1, 0x14
/* 3E0BD8 E00E62A8 3C014180 */  lui       $at, 0x4180
/* 3E0BDC E00E62AC 4481E000 */  mtc1      $at, $f28
/* 3E0BE0 E00E62B0 3C01E00E */  lui       $at, %hi(D_E00E6990)
/* 3E0BE4 E00E62B4 D43A6990 */  ldc1      $f26, %lo(D_E00E6990)($at)
.LE00E62B8:
/* 3E0BE8 E00E62B8 8E02000C */  lw        $v0, 0xc($s0)
/* 3E0BEC E00E62BC 24420001 */  addiu     $v0, $v0, 1
/* 3E0BF0 E00E62C0 AE02000C */  sw        $v0, 0xc($s0)
/* 3E0BF4 E00E62C4 8E830000 */  lw        $v1, ($s4)
/* 3E0BF8 E00E62C8 0043102A */  slt       $v0, $v0, $v1
/* 3E0BFC E00E62CC 50400001 */  beql      $v0, $zero, .LE00E62D4
/* 3E0C00 E00E62D0 AE00000C */   sw       $zero, 0xc($s0)
.LE00E62D4:
/* 3E0C04 E00E62D4 8E02000C */  lw        $v0, 0xc($s0)
/* 3E0C08 E00E62D8 0442006A */  bltzl     $v0, .LE00E6484
/* 3E0C0C E00E62DC 26310001 */   addiu    $s1, $s1, 1
/* 3E0C10 E00E62E0 1440002A */  bnez      $v0, .LE00E638C
/* 3E0C14 E00E62E4 00000000 */   nop
/* 3E0C18 E00E62E8 3C0143B4 */  lui       $at, 0x43b4
/* 3E0C1C E00E62EC 44810000 */  mtc1      $at, $f0
/* 3E0C20 E00E62F0 4491A000 */  mtc1      $s1, $f20
/* 3E0C24 E00E62F4 00000000 */  nop
/* 3E0C28 E00E62F8 4680A520 */  cvt.s.w   $f20, $f20
/* 3E0C2C E00E62FC 4600A502 */  mul.s     $f20, $f20, $f0
/* 3E0C30 E00E6300 00000000 */  nop
/* 3E0C34 E00E6304 8E420008 */  lw        $v0, 8($s2)
/* 3E0C38 E00E6308 2442FFFF */  addiu     $v0, $v0, -1
/* 3E0C3C E00E630C 44820000 */  mtc1      $v0, $f0
/* 3E0C40 E00E6310 00000000 */  nop
/* 3E0C44 E00E6314 46800020 */  cvt.s.w   $f0, $f0
/* 3E0C48 E00E6318 4600A503 */  div.s     $f20, $f20, $f0
/* 3E0C4C E00E631C 0C080140 */  jal       shim_sin_deg
/* 3E0C50 E00E6320 4600A306 */   mov.s    $f12, $f20
/* 3E0C54 E00E6324 461C0002 */  mul.s     $f0, $f0, $f28
/* 3E0C58 E00E6328 00000000 */  nop
/* 3E0C5C E00E632C 4600A306 */  mov.s     $f12, $f20
/* 3E0C60 E00E6330 0C080144 */  jal       shim_cos_deg
/* 3E0C64 E00E6334 E600FFF0 */   swc1     $f0, -0x10($s0)
/* 3E0C68 E00E6338 461C0002 */  mul.s     $f0, $f0, $f28
/* 3E0C6C E00E633C 00000000 */  nop
/* 3E0C70 E00E6340 C606FFF0 */  lwc1      $f6, -0x10($s0)
/* 3E0C74 E00E6344 46183182 */  mul.s     $f6, $f6, $f24
/* 3E0C78 E00E6348 00000000 */  nop
/* 3E0C7C E00E634C E600FFF4 */  swc1      $f0, -0xc($s0)
/* 3E0C80 E00E6350 46000106 */  mov.s     $f4, $f0
/* 3E0C84 E00E6354 46182102 */  mul.s     $f4, $f4, $f24
/* 3E0C88 E00E6358 00000000 */  nop
/* 3E0C8C E00E635C 3C013F80 */  lui       $at, 0x3f80
/* 3E0C90 E00E6360 44811000 */  mtc1      $at, $f2
/* 3E0C94 E00E6364 3C014234 */  lui       $at, 0x4234
/* 3E0C98 E00E6368 44810000 */  mtc1      $at, $f0
/* 3E0C9C E00E636C 4600A507 */  neg.s     $f20, $f20
/* 3E0CA0 E00E6370 AE000004 */  sw        $zero, 4($s0)
/* 3E0CA4 E00E6374 AE000008 */  sw        $zero, 8($s0)
/* 3E0CA8 E00E6378 4600A501 */  sub.s     $f20, $f20, $f0
/* 3E0CAC E00E637C E6020020 */  swc1      $f2, 0x20($s0)
/* 3E0CB0 E00E6380 E606FFFC */  swc1      $f6, -4($s0)
/* 3E0CB4 E00E6384 E6140010 */  swc1      $f20, 0x10($s0)
/* 3E0CB8 E00E6388 E6040000 */  swc1      $f4, ($s0)
.LE00E638C:
/* 3E0CBC E00E638C 16600008 */  bnez      $s3, .LE00E63B0
/* 3E0CC0 E00E6390 00000000 */   nop
/* 3E0CC4 E00E6394 8E02000C */  lw        $v0, 0xc($s0)
/* 3E0CC8 E00E6398 3C03E00E */  lui       $v1, %hi(D_E00E68F8)
/* 3E0CCC E00E639C 00621821 */  addu      $v1, $v1, $v0
/* 3E0CD0 E00E63A0 906368F8 */  lbu       $v1, %lo(D_E00E68F8)($v1)
/* 3E0CD4 E00E63A4 00021080 */  sll       $v0, $v0, 2
/* 3E0CD8 E00E63A8 080398F2 */  j         .LE00E63C8
/* 3E0CDC E00E63AC 00571021 */   addu     $v0, $v0, $s7
.LE00E63B0:
/* 3E0CE0 E00E63B0 8E02000C */  lw        $v0, 0xc($s0)
/* 3E0CE4 E00E63B4 3C03E00E */  lui       $v1, %hi(D_E00E6970)
/* 3E0CE8 E00E63B8 00621821 */  addu      $v1, $v1, $v0
/* 3E0CEC E00E63BC 90636970 */  lbu       $v1, %lo(D_E00E6970)($v1)
/* 3E0CF0 E00E63C0 00021080 */  sll       $v0, $v0, 2
/* 3E0CF4 E00E63C4 00561021 */  addu      $v0, $v0, $s6
.LE00E63C8:
/* 3E0CF8 E00E63C8 AE03001C */  sw        $v1, 0x1c($s0)
/* 3E0CFC E00E63CC C4400000 */  lwc1      $f0, ($v0)
/* 3E0D00 E00E63D0 32A30001 */  andi      $v1, $s5, 1
/* 3E0D04 E00E63D4 32220001 */  andi      $v0, $s1, 1
/* 3E0D08 E00E63D8 14620009 */  bne       $v1, $v0, .LE00E6400
/* 3E0D0C E00E63DC E6000020 */   swc1     $f0, 0x20($s0)
/* 3E0D10 E00E63E0 C604FFF0 */  lwc1      $f4, -0x10($s0)
/* 3E0D14 E00E63E4 C600FFFC */  lwc1      $f0, -4($s0)
/* 3E0D18 E00E63E8 C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 3E0D1C E00E63EC 46002100 */  add.s     $f4, $f4, $f0
/* 3E0D20 E00E63F0 C6000000 */  lwc1      $f0, ($s0)
/* 3E0D24 E00E63F4 46001080 */  add.s     $f2, $f2, $f0
/* 3E0D28 E00E63F8 08039911 */  j         .LE00E6444
/* 3E0D2C E00E63FC E604FFF0 */   swc1     $f4, -0x10($s0)
.LE00E6400:
/* 3E0D30 E00E6400 C606FFFC */  lwc1      $f6, -4($s0)
/* 3E0D34 E00E6404 460031A1 */  cvt.d.s   $f6, $f6
/* 3E0D38 E00E6408 463A3182 */  mul.d     $f6, $f6, $f26
/* 3E0D3C E00E640C 00000000 */  nop
/* 3E0D40 E00E6410 C6040000 */  lwc1      $f4, ($s0)
/* 3E0D44 E00E6414 46002121 */  cvt.d.s   $f4, $f4
/* 3E0D48 E00E6418 463A2102 */  mul.d     $f4, $f4, $f26
/* 3E0D4C E00E641C 00000000 */  nop
/* 3E0D50 E00E6420 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 3E0D54 E00E6424 C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 3E0D58 E00E6428 46000021 */  cvt.d.s   $f0, $f0
/* 3E0D5C E00E642C 46260000 */  add.d     $f0, $f0, $f6
/* 3E0D60 E00E6430 460010A1 */  cvt.d.s   $f2, $f2
/* 3E0D64 E00E6434 46241080 */  add.d     $f2, $f2, $f4
/* 3E0D68 E00E6438 46200020 */  cvt.s.d   $f0, $f0
/* 3E0D6C E00E643C 462010A0 */  cvt.s.d   $f2, $f2
/* 3E0D70 E00E6440 E600FFF0 */  swc1      $f0, -0x10($s0)
.LE00E6444:
/* 3E0D74 E00E6444 E602FFF4 */  swc1      $f2, -0xc($s0)
/* 3E0D78 E00E6448 C6040004 */  lwc1      $f4, 4($s0)
/* 3E0D7C E00E644C C606FFFC */  lwc1      $f6, -4($s0)
/* 3E0D80 E00E6450 46062101 */  sub.s     $f4, $f4, $f6
/* 3E0D84 E00E6454 46162102 */  mul.s     $f4, $f4, $f22
/* 3E0D88 E00E6458 00000000 */  nop
/* 3E0D8C E00E645C C6000008 */  lwc1      $f0, 8($s0)
/* 3E0D90 E00E6460 C6020000 */  lwc1      $f2, ($s0)
/* 3E0D94 E00E6464 46020001 */  sub.s     $f0, $f0, $f2
/* 3E0D98 E00E6468 46160002 */  mul.s     $f0, $f0, $f22
/* 3E0D9C E00E646C 00000000 */  nop
/* 3E0DA0 E00E6470 46043180 */  add.s     $f6, $f6, $f4
/* 3E0DA4 E00E6474 46001080 */  add.s     $f2, $f2, $f0
/* 3E0DA8 E00E6478 E606FFFC */  swc1      $f6, -4($s0)
/* 3E0DAC E00E647C E6020000 */  swc1      $f2, ($s0)
/* 3E0DB0 E00E6480 26310001 */  addiu     $s1, $s1, 1
.LE00E6484:
/* 3E0DB4 E00E6484 8E420008 */  lw        $v0, 8($s2)
/* 3E0DB8 E00E6488 0222102A */  slt       $v0, $s1, $v0
/* 3E0DBC E00E648C 1440FF8A */  bnez      $v0, .LE00E62B8
/* 3E0DC0 E00E6490 26100038 */   addiu    $s0, $s0, 0x38
.LE00E6494:
/* 3E0DC4 E00E6494 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3E0DC8 E00E6498 8FB7002C */  lw        $s7, 0x2c($sp)
/* 3E0DCC E00E649C 8FB60028 */  lw        $s6, 0x28($sp)
/* 3E0DD0 E00E64A0 8FB50024 */  lw        $s5, 0x24($sp)
/* 3E0DD4 E00E64A4 8FB40020 */  lw        $s4, 0x20($sp)
/* 3E0DD8 E00E64A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3E0DDC E00E64AC 8FB20018 */  lw        $s2, 0x18($sp)
/* 3E0DE0 E00E64B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 3E0DE4 E00E64B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3E0DE8 E00E64B8 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 3E0DEC E00E64BC D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3E0DF0 E00E64C0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3E0DF4 E00E64C4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3E0DF8 E00E64C8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3E0DFC E00E64CC 03E00008 */  jr        $ra
/* 3E0E00 E00E64D0 27BD0060 */   addiu    $sp, $sp, 0x60
