.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00520F0
/* 35CB70 E00520F0 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 35CB74 E00520F4 AFBF0030 */  sw        $ra, 0x30($sp)
/* 35CB78 E00520F8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 35CB7C E00520FC AFB60028 */  sw        $s6, 0x28($sp)
/* 35CB80 E0052100 AFB50024 */  sw        $s5, 0x24($sp)
/* 35CB84 E0052104 AFB40020 */  sw        $s4, 0x20($sp)
/* 35CB88 E0052108 AFB3001C */  sw        $s3, 0x1c($sp)
/* 35CB8C E005210C AFB20018 */  sw        $s2, 0x18($sp)
/* 35CB90 E0052110 AFB10014 */  sw        $s1, 0x14($sp)
/* 35CB94 E0052114 AFB00010 */  sw        $s0, 0x10($sp)
/* 35CB98 E0052118 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 35CB9C E005211C F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 35CBA0 E0052120 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 35CBA4 E0052124 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 35CBA8 E0052128 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 35CBAC E005212C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 35CBB0 E0052130 8C90000C */  lw        $s0, 0xc($a0)
/* 35CBB4 E0052134 8E03001C */  lw        $v1, 0x1c($s0)
/* 35CBB8 E0052138 28620064 */  slti      $v0, $v1, 0x64
/* 35CBBC E005213C 10400003 */  beqz      $v0, .LE005214C
/* 35CBC0 E0052140 26130024 */   addiu    $s3, $s0, 0x24
/* 35CBC4 E0052144 2462FFFF */  addiu     $v0, $v1, -1
/* 35CBC8 E0052148 AE02001C */  sw        $v0, 0x1c($s0)
.LE005214C:
/* 35CBCC E005214C 3C030004 */  lui       $v1, 4
/* 35CBD0 E0052150 8E020020 */  lw        $v0, 0x20($s0)
/* 35CBD4 E0052154 3463F1A0 */  ori       $v1, $v1, 0xf1a0
/* 35CBD8 E0052158 24420001 */  addiu     $v0, $v0, 1
/* 35CBDC E005215C 0062182A */  slt       $v1, $v1, $v0
/* 35CBE0 E0052160 10600003 */  beqz      $v1, .LE0052170
/* 35CBE4 E0052164 AE020020 */   sw       $v0, 0x20($s0)
/* 35CBE8 E0052168 24020100 */  addiu     $v0, $zero, 0x100
/* 35CBEC E005216C AE020020 */  sw        $v0, 0x20($s0)
.LE0052170:
/* 35CBF0 E0052170 8E03001C */  lw        $v1, 0x1c($s0)
/* 35CBF4 E0052174 04610005 */  bgez      $v1, .LE005218C
/* 35CBF8 E0052178 0060B82D */   daddu    $s7, $v1, $zero
/* 35CBFC E005217C 0C080128 */  jal       func_E02004A0
/* 35CC00 E0052180 00000000 */   nop
/* 35CC04 E0052184 080148F6 */  j         .LE00523D8
/* 35CC08 E0052188 00000000 */   nop
.LE005218C:
/* 35CC0C E005218C C6020014 */  lwc1      $f2, 0x14($s0)
/* 35CC10 E0052190 C6140018 */  lwc1      $f20, 0x18($s0)
/* 35CC14 E0052194 46141081 */  sub.s     $f2, $f2, $f20
/* 35CC18 E0052198 3C013DCC */  lui       $at, 0x3dcc
/* 35CC1C E005219C 3421CCCD */  ori       $at, $at, 0xcccd
/* 35CC20 E00521A0 44810000 */  mtc1      $at, $f0
/* 35CC24 E00521A4 00000000 */  nop
/* 35CC28 E00521A8 46001082 */  mul.s     $f2, $f2, $f0
/* 35CC2C E00521AC 00000000 */  nop
/* 35CC30 E00521B0 8E160020 */  lw        $s6, 0x20($s0)
/* 35CC34 E00521B4 00161040 */  sll       $v0, $s6, 1
/* 35CC38 E00521B8 4602A500 */  add.s     $f20, $f20, $f2
/* 35CC3C E00521BC 00561021 */  addu      $v0, $v0, $s6
/* 35CC40 E00521C0 44826000 */  mtc1      $v0, $f12
/* 35CC44 E00521C4 00000000 */  nop
/* 35CC48 E00521C8 46806320 */  cvt.s.w   $f12, $f12
/* 35CC4C E00521CC 0C080140 */  jal       func_E0200500
/* 35CC50 E00521D0 E6140018 */   swc1     $f20, 0x18($s0)
/* 35CC54 E00521D4 4600A002 */  mul.s     $f0, $f20, $f0
/* 35CC58 E00521D8 00000000 */  nop
/* 35CC5C E00521DC 3C01E005 */  lui       $at, %hi(D_E0052A80)
/* 35CC60 E00521E0 D4222A80 */  ldc1      $f2, %lo(D_E0052A80)($at)
/* 35CC64 E00521E4 46000021 */  cvt.d.s   $f0, $f0
/* 35CC68 E00521E8 46220002 */  mul.d     $f0, $f0, $f2
/* 35CC6C E00521EC 00000000 */  nop
/* 35CC70 E00521F0 0000902D */  daddu     $s2, $zero, $zero
/* 35CC74 E00521F4 26110028 */  addiu     $s1, $s0, 0x28
/* 35CC78 E00521F8 0240A82D */  daddu     $s5, $s2, $zero
/* 35CC7C E00521FC 0240A02D */  daddu     $s4, $s2, $zero
/* 35CC80 E0052200 4600A521 */  cvt.d.s   $f20, $f20
/* 35CC84 E0052204 3C014000 */  lui       $at, 0x4000
/* 35CC88 E0052208 4481F800 */  mtc1      $at, $f31
/* 35CC8C E005220C 4480F000 */  mtc1      $zero, $f30
/* 35CC90 E0052210 4620A500 */  add.d     $f20, $f20, $f0
/* 35CC94 E0052214 3C013FF8 */  lui       $at, 0x3ff8
/* 35CC98 E0052218 4481E800 */  mtc1      $at, $f29
/* 35CC9C E005221C 4480E000 */  mtc1      $zero, $f28
/* 35CCA0 E0052220 46201686 */  mov.d     $f26, $f2
/* 35CCA4 E0052224 4620A620 */  cvt.s.d   $f24, $f20
.LE0052228:
/* 35CCA8 E0052228 3C0143B4 */  lui       $at, 0x43b4
/* 35CCAC E005222C 4481A000 */  mtc1      $at, $f20
/* 35CCB0 E0052230 4492B000 */  mtc1      $s2, $f22
/* 35CCB4 E0052234 00000000 */  nop
/* 35CCB8 E0052238 4680B5A0 */  cvt.s.w   $f22, $f22
/* 35CCBC E005223C 4614B502 */  mul.s     $f20, $f22, $f20
/* 35CCC0 E0052240 00000000 */  nop
/* 35CCC4 E0052244 3C0141A8 */  lui       $at, 0x41a8
/* 35CCC8 E0052248 44810000 */  mtc1      $at, $f0
/* 35CCCC E005224C 3C014188 */  lui       $at, 0x4188
/* 35CCD0 E0052250 44811000 */  mtc1      $at, $f2
/* 35CCD4 E0052254 4600A503 */  div.s     $f20, $f20, $f0
/* 35CCD8 E0052258 4602A500 */  add.s     $f20, $f20, $f2
/* 35CCDC E005225C 0C080140 */  jal       func_E0200500
/* 35CCE0 E0052260 4600A306 */   mov.s    $f12, $f20
/* 35CCE4 E0052264 4600C002 */  mul.s     $f0, $f24, $f0
/* 35CCE8 E0052268 00000000 */  nop
/* 35CCEC E005226C 4600A306 */  mov.s     $f12, $f20
/* 35CCF0 E0052270 0C080144 */  jal       func_E0200510
/* 35CCF4 E0052274 E6600000 */   swc1     $f0, ($s3)
/* 35CCF8 E0052278 4600C087 */  neg.s     $f2, $f24
/* 35CCFC E005227C 46001082 */  mul.s     $f2, $f2, $f0
/* 35CD00 E0052280 00000000 */  nop
/* 35CD04 E0052284 44946000 */  mtc1      $s4, $f12
/* 35CD08 E0052288 00000000 */  nop
/* 35CD0C E005228C 46806320 */  cvt.s.w   $f12, $f12
/* 35CD10 E0052290 0C080140 */  jal       func_E0200500
/* 35CD14 E0052294 E6220000 */   swc1     $f2, ($s1)
/* 35CD18 E0052298 46000021 */  cvt.d.s   $f0, $f0
/* 35CD1C E005229C 463A0002 */  mul.d     $f0, $f0, $f26
/* 35CD20 E00522A0 00000000 */  nop
/* 35CD24 E00522A4 463E0000 */  add.d     $f0, $f0, $f30
/* 35CD28 E00522A8 4496A000 */  mtc1      $s6, $f20
/* 35CD2C E00522AC 00000000 */  nop
/* 35CD30 E00522B0 4680A520 */  cvt.s.w   $f20, $f20
/* 35CD34 E00522B4 4600A521 */  cvt.d.s   $f20, $f20
/* 35CD38 E00522B8 4620A002 */  mul.d     $f0, $f20, $f0
/* 35CD3C E00522BC 00000000 */  nop
/* 35CD40 E00522C0 3C0140A0 */  lui       $at, 0x40a0
/* 35CD44 E00522C4 44811000 */  mtc1      $at, $f2
/* 35CD48 E00522C8 00000000 */  nop
/* 35CD4C E00522CC 4602B580 */  add.s     $f22, $f22, $f2
/* 35CD50 E00522D0 3C0141F0 */  lui       $at, 0x41f0
/* 35CD54 E00522D4 44811000 */  mtc1      $at, $f2
/* 35CD58 E00522D8 00000000 */  nop
/* 35CD5C E00522DC 4602B082 */  mul.s     $f2, $f22, $f2
/* 35CD60 E00522E0 00000000 */  nop
/* 35CD64 E00522E4 460010A1 */  cvt.d.s   $f2, $f2
/* 35CD68 E00522E8 46220000 */  add.d     $f0, $f0, $f2
/* 35CD6C E00522EC 0C080140 */  jal       func_E0200500
/* 35CD70 E00522F0 46200320 */   cvt.s.d  $f12, $f0
/* 35CD74 E00522F4 46000021 */  cvt.d.s   $f0, $f0
/* 35CD78 E00522F8 463C0002 */  mul.d     $f0, $f0, $f28
/* 35CD7C E00522FC 00000000 */  nop
/* 35CD80 E0052300 C6620000 */  lwc1      $f2, ($s3)
/* 35CD84 E0052304 460010A1 */  cvt.d.s   $f2, $f2
/* 35CD88 E0052308 46201080 */  add.d     $f2, $f2, $f0
/* 35CD8C E005230C 44956000 */  mtc1      $s5, $f12
/* 35CD90 E0052310 00000000 */  nop
/* 35CD94 E0052314 46806320 */  cvt.s.w   $f12, $f12
/* 35CD98 E0052318 462010A0 */  cvt.s.d   $f2, $f2
/* 35CD9C E005231C 0C080144 */  jal       func_E0200510
/* 35CDA0 E0052320 E6620000 */   swc1     $f2, ($s3)
/* 35CDA4 E0052324 46000021 */  cvt.d.s   $f0, $f0
/* 35CDA8 E0052328 463A0002 */  mul.d     $f0, $f0, $f26
/* 35CDAC E005232C 00000000 */  nop
/* 35CDB0 E0052330 463E0000 */  add.d     $f0, $f0, $f30
/* 35CDB4 E0052334 4620A502 */  mul.d     $f20, $f20, $f0
/* 35CDB8 E0052338 00000000 */  nop
/* 35CDBC E005233C 3C014248 */  lui       $at, 0x4248
/* 35CDC0 E0052340 44810000 */  mtc1      $at, $f0
/* 35CDC4 E0052344 00000000 */  nop
/* 35CDC8 E0052348 4600B582 */  mul.s     $f22, $f22, $f0
/* 35CDCC E005234C 00000000 */  nop
/* 35CDD0 E0052350 4600B5A1 */  cvt.d.s   $f22, $f22
/* 35CDD4 E0052354 4636A500 */  add.d     $f20, $f20, $f22
/* 35CDD8 E0052358 0C080144 */  jal       func_E0200510
/* 35CDDC E005235C 4620A320 */   cvt.s.d  $f12, $f20
/* 35CDE0 E0052360 46000021 */  cvt.d.s   $f0, $f0
/* 35CDE4 E0052364 463C0002 */  mul.d     $f0, $f0, $f28
/* 35CDE8 E0052368 00000000 */  nop
/* 35CDEC E005236C 26520001 */  addiu     $s2, $s2, 1
/* 35CDF0 E0052370 26940035 */  addiu     $s4, $s4, 0x35
/* 35CDF4 E0052374 C6220000 */  lwc1      $f2, ($s1)
/* 35CDF8 E0052378 26B50024 */  addiu     $s5, $s5, 0x24
/* 35CDFC E005237C 460010A1 */  cvt.d.s   $f2, $f2
/* 35CE00 E0052380 46201080 */  add.d     $f2, $f2, $f0
/* 35CE04 E0052384 26730008 */  addiu     $s3, $s3, 8
/* 35CE08 E0052388 2A420014 */  slti      $v0, $s2, 0x14
/* 35CE0C E005238C 462010A0 */  cvt.s.d   $f2, $f2
/* 35CE10 E0052390 E6220000 */  swc1      $f2, ($s1)
/* 35CE14 E0052394 1440FFA4 */  bnez      $v0, .LE0052228
/* 35CE18 E0052398 26310008 */   addiu    $s1, $s1, 8
/* 35CE1C E005239C 2AE20064 */  slti      $v0, $s7, 0x64
/* 35CE20 E00523A0 10400006 */  beqz      $v0, .LE00523BC
/* 35CE24 E00523A4 AE0000C4 */   sw       $zero, 0xc4($s0)
/* 35CE28 E00523A8 C60000C8 */  lwc1      $f0, 0xc8($s0)
/* 35CE2C E00523AC 3C013F80 */  lui       $at, 0x3f80
/* 35CE30 E00523B0 44811000 */  mtc1      $at, $f2
/* 35CE34 E00523B4 080148F5 */  j         .LE00523D4
/* 35CE38 E00523B8 46020000 */   add.s    $f0, $f0, $f2
.LE00523BC:
/* 35CE3C E00523BC 3C01E005 */  lui       $at, %hi(D_E0052A88)
/* 35CE40 E00523C0 D4222A88 */  ldc1      $f2, %lo(D_E0052A88)($at)
/* 35CE44 E00523C4 4600C021 */  cvt.d.s   $f0, $f24
/* 35CE48 E00523C8 46220002 */  mul.d     $f0, $f0, $f2
/* 35CE4C E00523CC 00000000 */  nop
/* 35CE50 E00523D0 46200020 */  cvt.s.d   $f0, $f0
.LE00523D4:
/* 35CE54 E00523D4 E60000C8 */  swc1      $f0, 0xc8($s0)
.LE00523D8:
/* 35CE58 E00523D8 8FBF0030 */  lw        $ra, 0x30($sp)
/* 35CE5C E00523DC 8FB7002C */  lw        $s7, 0x2c($sp)
/* 35CE60 E00523E0 8FB60028 */  lw        $s6, 0x28($sp)
/* 35CE64 E00523E4 8FB50024 */  lw        $s5, 0x24($sp)
/* 35CE68 E00523E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 35CE6C E00523EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 35CE70 E00523F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 35CE74 E00523F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 35CE78 E00523F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 35CE7C E00523FC D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 35CE80 E0052400 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 35CE84 E0052404 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 35CE88 E0052408 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 35CE8C E005240C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 35CE90 E0052410 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 35CE94 E0052414 03E00008 */  jr        $ra
/* 35CE98 E0052418 27BD0068 */   addiu    $sp, $sp, 0x68
