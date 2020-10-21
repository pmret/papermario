.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B40_CE7240
/* CE7240 80240B40 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CE7244 80240B44 AFB20018 */  sw        $s2, 0x18($sp)
/* CE7248 80240B48 0080902D */  daddu     $s2, $a0, $zero
/* CE724C 80240B4C AFBF0028 */  sw        $ra, 0x28($sp)
/* CE7250 80240B50 AFB50024 */  sw        $s5, 0x24($sp)
/* CE7254 80240B54 AFB40020 */  sw        $s4, 0x20($sp)
/* CE7258 80240B58 AFB3001C */  sw        $s3, 0x1c($sp)
/* CE725C 80240B5C AFB10014 */  sw        $s1, 0x14($sp)
/* CE7260 80240B60 AFB00010 */  sw        $s0, 0x10($sp)
/* CE7264 80240B64 F7B80040 */  sdc1      $f24, 0x40($sp)
/* CE7268 80240B68 F7B60038 */  sdc1      $f22, 0x38($sp)
/* CE726C 80240B6C F7B40030 */  sdc1      $f20, 0x30($sp)
/* CE7270 80240B70 8E50000C */  lw        $s0, 0xc($s2)
/* CE7274 80240B74 8E140000 */  lw        $s4, ($s0)
/* CE7278 80240B78 26100004 */  addiu     $s0, $s0, 4
/* CE727C 80240B7C 0C0B1EAF */  jal       get_variable
/* CE7280 80240B80 0280282D */   daddu    $a1, $s4, $zero
/* CE7284 80240B84 0040982D */  daddu     $s3, $v0, $zero
/* CE7288 80240B88 8E150000 */  lw        $s5, ($s0)
/* CE728C 80240B8C 26100004 */  addiu     $s0, $s0, 4
/* CE7290 80240B90 8E050000 */  lw        $a1, ($s0)
/* CE7294 80240B94 26100004 */  addiu     $s0, $s0, 4
/* CE7298 80240B98 0C0B210B */  jal       get_float_variable
/* CE729C 80240B9C 0240202D */   daddu    $a0, $s2, $zero
/* CE72A0 80240BA0 8E050000 */  lw        $a1, ($s0)
/* CE72A4 80240BA4 26100004 */  addiu     $s0, $s0, 4
/* CE72A8 80240BA8 0240202D */  daddu     $a0, $s2, $zero
/* CE72AC 80240BAC 0C0B210B */  jal       get_float_variable
/* CE72B0 80240BB0 46000606 */   mov.s    $f24, $f0
/* CE72B4 80240BB4 8E050000 */  lw        $a1, ($s0)
/* CE72B8 80240BB8 26100004 */  addiu     $s0, $s0, 4
/* CE72BC 80240BBC 0240202D */  daddu     $a0, $s2, $zero
/* CE72C0 80240BC0 0C0B1EAF */  jal       get_variable
/* CE72C4 80240BC4 46000506 */   mov.s    $f20, $f0
/* CE72C8 80240BC8 8E050000 */  lw        $a1, ($s0)
/* CE72CC 80240BCC 26100004 */  addiu     $s0, $s0, 4
/* CE72D0 80240BD0 0240202D */  daddu     $a0, $s2, $zero
/* CE72D4 80240BD4 0C0B1EAF */  jal       get_variable
/* CE72D8 80240BD8 0040882D */   daddu    $s1, $v0, $zero
/* CE72DC 80240BDC 0240202D */  daddu     $a0, $s2, $zero
/* CE72E0 80240BE0 8E050000 */  lw        $a1, ($s0)
/* CE72E4 80240BE4 0C0B210B */  jal       get_float_variable
/* CE72E8 80240BE8 0040802D */   daddu    $s0, $v0, $zero
/* CE72EC 80240BEC 3C014334 */  lui       $at, 0x4334
/* CE72F0 80240BF0 44811000 */  mtc1      $at, $f2
/* CE72F4 80240BF4 3C014049 */  lui       $at, 0x4049
/* CE72F8 80240BF8 34210FD8 */  ori       $at, $at, 0xfd8
/* CE72FC 80240BFC 44812000 */  mtc1      $at, $f4
/* CE7300 80240C00 46020003 */  div.s     $f0, $f0, $f2
/* CE7304 80240C04 46040582 */  mul.s     $f22, $f0, $f4
/* CE7308 80240C08 00000000 */  nop       
/* CE730C 80240C0C 4618A501 */  sub.s     $f20, $f20, $f24
/* CE7310 80240C10 3C013F00 */  lui       $at, 0x3f00
/* CE7314 80240C14 44810000 */  mtc1      $at, $f0
/* CE7318 80240C18 00000000 */  nop       
/* CE731C 80240C1C 4600A502 */  mul.s     $f20, $f20, $f0
/* CE7320 80240C20 00000000 */  nop       
/* CE7324 80240C24 12000007 */  beqz      $s0, .L80240C44
/* CE7328 80240C28 0233102A */   slt      $v0, $s1, $s3
/* CE732C 80240C2C 10400005 */  beqz      $v0, .L80240C44
/* CE7330 80240C30 0240202D */   daddu    $a0, $s2, $zero
/* CE7334 80240C34 0220982D */  daddu     $s3, $s1, $zero
/* CE7338 80240C38 0280282D */  daddu     $a1, $s4, $zero
/* CE733C 80240C3C 0C0B2026 */  jal       set_variable
/* CE7340 80240C40 0220302D */   daddu    $a2, $s1, $zero
.L80240C44:
/* CE7344 80240C44 3C014049 */  lui       $at, 0x4049
/* CE7348 80240C48 34210FD8 */  ori       $at, $at, 0xfd8
/* CE734C 80240C4C 44810000 */  mtc1      $at, $f0
/* CE7350 80240C50 44936000 */  mtc1      $s3, $f12
/* CE7354 80240C54 00000000 */  nop       
/* CE7358 80240C58 46806320 */  cvt.s.w   $f12, $f12
/* CE735C 80240C5C 46006302 */  mul.s     $f12, $f12, $f0
/* CE7360 80240C60 00000000 */  nop       
/* CE7364 80240C64 44910000 */  mtc1      $s1, $f0
/* CE7368 80240C68 00000000 */  nop       
/* CE736C 80240C6C 46800020 */  cvt.s.w   $f0, $f0
/* CE7370 80240C70 46006303 */  div.s     $f12, $f12, $f0
/* CE7374 80240C74 0C00A874 */  jal       cos_rad
/* CE7378 80240C78 46166300 */   add.s    $f12, $f12, $f22
/* CE737C 80240C7C 4600A002 */  mul.s     $f0, $f20, $f0
/* CE7380 80240C80 00000000 */  nop       
/* CE7384 80240C84 4614C080 */  add.s     $f2, $f24, $f20
/* CE7388 80240C88 46001081 */  sub.s     $f2, $f2, $f0
/* CE738C 80240C8C 0240202D */  daddu     $a0, $s2, $zero
/* CE7390 80240C90 44061000 */  mfc1      $a2, $f2
/* CE7394 80240C94 0C0B2190 */  jal       set_float_variable
/* CE7398 80240C98 02A0282D */   daddu    $a1, $s5, $zero
/* CE739C 80240C9C 8FBF0028 */  lw        $ra, 0x28($sp)
/* CE73A0 80240CA0 8FB50024 */  lw        $s5, 0x24($sp)
/* CE73A4 80240CA4 8FB40020 */  lw        $s4, 0x20($sp)
/* CE73A8 80240CA8 8FB3001C */  lw        $s3, 0x1c($sp)
/* CE73AC 80240CAC 8FB20018 */  lw        $s2, 0x18($sp)
/* CE73B0 80240CB0 8FB10014 */  lw        $s1, 0x14($sp)
/* CE73B4 80240CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* CE73B8 80240CB8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* CE73BC 80240CBC D7B60038 */  ldc1      $f22, 0x38($sp)
/* CE73C0 80240CC0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* CE73C4 80240CC4 24020002 */  addiu     $v0, $zero, 2
/* CE73C8 80240CC8 03E00008 */  jr        $ra
/* CE73CC 80240CCC 27BD0048 */   addiu    $sp, $sp, 0x48
