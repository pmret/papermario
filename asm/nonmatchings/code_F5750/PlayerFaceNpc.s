.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayerFaceNpc
/* F64B4 802D1B04 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F64B8 802D1B08 AFB20018 */  sw        $s2, 0x18($sp)
/* F64BC 802D1B0C 0080902D */  daddu     $s2, $a0, $zero
/* F64C0 802D1B10 AFB60028 */  sw        $s6, 0x28($sp)
/* F64C4 802D1B14 3C168011 */  lui       $s6, 0x8011
/* F64C8 802D1B18 26D6EFC8 */  addiu     $s6, $s6, -0x1038
/* F64CC 802D1B1C AFB50024 */  sw        $s5, 0x24($sp)
/* F64D0 802D1B20 26550074 */  addiu     $s5, $s2, 0x74
/* F64D4 802D1B24 AFB10014 */  sw        $s1, 0x14($sp)
/* F64D8 802D1B28 26510078 */  addiu     $s1, $s2, 0x78
/* F64DC 802D1B2C AFB40020 */  sw        $s4, 0x20($sp)
/* F64E0 802D1B30 AFBF002C */  sw        $ra, 0x2c($sp)
/* F64E4 802D1B34 AFB3001C */  sw        $s3, 0x1c($sp)
/* F64E8 802D1B38 AFB00010 */  sw        $s0, 0x10($sp)
/* F64EC 802D1B3C 8E53000C */  lw        $s3, 0xc($s2)
/* F64F0 802D1B40 10A00043 */  beqz      $a1, .L802D1C50
/* F64F4 802D1B44 2654007C */   addiu    $s4, $s2, 0x7c
/* F64F8 802D1B48 8E650000 */  lw        $a1, ($s3)
/* F64FC 802D1B4C 0C0B1EAF */  jal       get_variable
/* F6500 802D1B50 26730004 */   addiu    $s3, $s3, 4
/* F6504 802D1B54 0040202D */  daddu     $a0, $v0, $zero
/* F6508 802D1B58 2402FFFF */  addiu     $v0, $zero, -1
/* F650C 802D1B5C 14820006 */  bne       $a0, $v0, .L802D1B78
/* F6510 802D1B60 3C02EFE8 */   lui      $v0, 0xefe8
/* F6514 802D1B64 8E44014C */  lw        $a0, 0x14c($s2)
/* F6518 802D1B68 0C00EAD2 */  jal       get_npc_safe
/* F651C 802D1B6C 00000000 */   nop      
/* F6520 802D1B70 080B46E7 */  j         .L802D1B9C
/* F6524 802D1B74 0040202D */   daddu    $a0, $v0, $zero
.L802D1B78:
/* F6528 802D1B78 34422080 */  ori       $v0, $v0, 0x2080
/* F652C 802D1B7C 0082102A */  slt       $v0, $a0, $v0
/* F6530 802D1B80 14400006 */  bnez      $v0, .L802D1B9C
/* F6534 802D1B84 00000000 */   nop      
/* F6538 802D1B88 0C00EAD2 */  jal       get_npc_safe
/* F653C 802D1B8C 00000000 */   nop      
/* F6540 802D1B90 0040202D */  daddu     $a0, $v0, $zero
/* F6544 802D1B94 1080005A */  beqz      $a0, .L802D1D00
/* F6548 802D1B98 24020002 */   addiu    $v0, $zero, 2
.L802D1B9C:
/* F654C 802D1B9C 3C10802E */  lui       $s0, 0x802e
/* F6550 802D1BA0 26109D20 */  addiu     $s0, $s0, -0x62e0
/* F6554 802D1BA4 8E020000 */  lw        $v0, ($s0)
/* F6558 802D1BA8 C6C00080 */  lwc1      $f0, 0x80($s6)
/* F655C 802D1BAC E440000C */  swc1      $f0, 0xc($v0)
/* F6560 802D1BB0 E6A00000 */  swc1      $f0, ($s5)
/* F6564 802D1BB4 C6CC0028 */  lwc1      $f12, 0x28($s6)
/* F6568 802D1BB8 C6CE0030 */  lwc1      $f14, 0x30($s6)
/* F656C 802D1BBC 8C860038 */  lw        $a2, 0x38($a0)
/* F6570 802D1BC0 0C00A720 */  jal       atan2
/* F6574 802D1BC4 8C870040 */   lw       $a3, 0x40($a0)
/* F6578 802D1BC8 C6A20000 */  lwc1      $f2, ($s5)
/* F657C 802D1BCC 46020001 */  sub.s     $f0, $f0, $f2
/* F6580 802D1BD0 E6200000 */  swc1      $f0, ($s1)
/* F6584 802D1BD4 8E650000 */  lw        $a1, ($s3)
/* F6588 802D1BD8 0C0B1EAF */  jal       get_variable
/* F658C 802D1BDC 0240202D */   daddu    $a0, $s2, $zero
/* F6590 802D1BE0 AE820000 */  sw        $v0, ($s4)
/* F6594 802D1BE4 8E020000 */  lw        $v0, ($s0)
/* F6598 802D1BE8 3C01C334 */  lui       $at, 0xc334
/* F659C 802D1BEC 44810000 */  mtc1      $at, $f0
/* F65A0 802D1BF0 A440008E */  sh        $zero, 0x8e($v0)
/* F65A4 802D1BF4 C6220000 */  lwc1      $f2, ($s1)
/* F65A8 802D1BF8 4600103C */  c.lt.s    $f2, $f0
/* F65AC 802D1BFC 00000000 */  nop       
/* F65B0 802D1C00 45000007 */  bc1f      .L802D1C20
/* F65B4 802D1C04 00000000 */   nop      
/* F65B8 802D1C08 3C0143B4 */  lui       $at, 0x43b4
/* F65BC 802D1C0C 44810000 */  mtc1      $at, $f0
/* F65C0 802D1C10 00000000 */  nop       
/* F65C4 802D1C14 46001000 */  add.s     $f0, $f2, $f0
/* F65C8 802D1C18 E6200000 */  swc1      $f0, ($s1)
/* F65CC 802D1C1C C6220000 */  lwc1      $f2, ($s1)
.L802D1C20:
/* F65D0 802D1C20 3C014334 */  lui       $at, 0x4334
/* F65D4 802D1C24 44810000 */  mtc1      $at, $f0
/* F65D8 802D1C28 00000000 */  nop       
/* F65DC 802D1C2C 4602003C */  c.lt.s    $f0, $f2
/* F65E0 802D1C30 00000000 */  nop       
/* F65E4 802D1C34 45000006 */  bc1f      .L802D1C50
/* F65E8 802D1C38 00000000 */   nop      
/* F65EC 802D1C3C 3C0143B4 */  lui       $at, 0x43b4
/* F65F0 802D1C40 44810000 */  mtc1      $at, $f0
/* F65F4 802D1C44 00000000 */  nop       
/* F65F8 802D1C48 46001001 */  sub.s     $f0, $f2, $f0
/* F65FC 802D1C4C E6200000 */  swc1      $f0, ($s1)
.L802D1C50:
/* F6600 802D1C50 8E820000 */  lw        $v0, ($s4)
/* F6604 802D1C54 1C40000E */  bgtz      $v0, .L802D1C90
/* F6608 802D1C58 00000000 */   nop      
/* F660C 802D1C5C 3C10802E */  lui       $s0, 0x802e
/* F6610 802D1C60 26109D20 */  addiu     $s0, $s0, -0x62e0
/* F6614 802D1C64 8E020000 */  lw        $v0, ($s0)
/* F6618 802D1C68 C6200000 */  lwc1      $f0, ($s1)
/* F661C 802D1C6C C44C000C */  lwc1      $f12, 0xc($v0)
/* F6620 802D1C70 46006300 */  add.s     $f12, $f12, $f0
/* F6624 802D1C74 0C00A6C9 */  jal       clamp_angle
/* F6628 802D1C78 E44C000C */   swc1     $f12, 0xc($v0)
/* F662C 802D1C7C 8E030000 */  lw        $v1, ($s0)
/* F6630 802D1C80 24020002 */  addiu     $v0, $zero, 2
/* F6634 802D1C84 E460000C */  swc1      $f0, 0xc($v1)
/* F6638 802D1C88 080B4740 */  j         .L802D1D00
/* F663C 802D1C8C E6C00080 */   swc1     $f0, 0x80($s6)
.L802D1C90:
/* F6640 802D1C90 3C10802E */  lui       $s0, 0x802e
/* F6644 802D1C94 26109D20 */  addiu     $s0, $s0, -0x62e0
/* F6648 802D1C98 8E030000 */  lw        $v1, ($s0)
/* F664C 802D1C9C 9462008E */  lhu       $v0, 0x8e($v1)
/* F6650 802D1CA0 24420001 */  addiu     $v0, $v0, 1
/* F6654 802D1CA4 A462008E */  sh        $v0, 0x8e($v1)
/* F6658 802D1CA8 00021400 */  sll       $v0, $v0, 0x10
/* F665C 802D1CAC 00021403 */  sra       $v0, $v0, 0x10
/* F6660 802D1CB0 C6200000 */  lwc1      $f0, ($s1)
/* F6664 802D1CB4 44821000 */  mtc1      $v0, $f2
/* F6668 802D1CB8 00000000 */  nop       
/* F666C 802D1CBC 468010A0 */  cvt.s.w   $f2, $f2
/* F6670 802D1CC0 46020002 */  mul.s     $f0, $f0, $f2
/* F6674 802D1CC4 00000000 */  nop       
/* F6678 802D1CC8 C6AC0000 */  lwc1      $f12, ($s5)
/* F667C 802D1CCC C6820000 */  lwc1      $f2, ($s4)
/* F6680 802D1CD0 468010A0 */  cvt.s.w   $f2, $f2
/* F6684 802D1CD4 46020003 */  div.s     $f0, $f0, $f2
/* F6688 802D1CD8 46006300 */  add.s     $f12, $f12, $f0
/* F668C 802D1CDC 0C00A6C9 */  jal       clamp_angle
/* F6690 802D1CE0 E46C000C */   swc1     $f12, 0xc($v1)
/* F6694 802D1CE4 8E020000 */  lw        $v0, ($s0)
/* F6698 802D1CE8 E440000C */  swc1      $f0, 0xc($v0)
/* F669C 802D1CEC E6C00080 */  swc1      $f0, 0x80($s6)
/* F66A0 802D1CF0 8442008E */  lh        $v0, 0x8e($v0)
/* F66A4 802D1CF4 8E830000 */  lw        $v1, ($s4)
/* F66A8 802D1CF8 0043102A */  slt       $v0, $v0, $v1
/* F66AC 802D1CFC 38420001 */  xori      $v0, $v0, 1
.L802D1D00:
/* F66B0 802D1D00 8FBF002C */  lw        $ra, 0x2c($sp)
/* F66B4 802D1D04 8FB60028 */  lw        $s6, 0x28($sp)
/* F66B8 802D1D08 8FB50024 */  lw        $s5, 0x24($sp)
/* F66BC 802D1D0C 8FB40020 */  lw        $s4, 0x20($sp)
/* F66C0 802D1D10 8FB3001C */  lw        $s3, 0x1c($sp)
/* F66C4 802D1D14 8FB20018 */  lw        $s2, 0x18($sp)
/* F66C8 802D1D18 8FB10014 */  lw        $s1, 0x14($sp)
/* F66CC 802D1D1C 8FB00010 */  lw        $s0, 0x10($sp)
/* F66D0 802D1D20 03E00008 */  jr        $ra
/* F66D4 802D1D24 27BD0030 */   addiu    $sp, $sp, 0x30
