.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_DF6A20
/* DF6A20 80240020 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* DF6A24 80240024 AFB00088 */  sw        $s0, 0x88($sp)
/* DF6A28 80240028 00A0802D */  daddu     $s0, $a1, $zero
/* DF6A2C 8024002C AFBF00A0 */  sw        $ra, 0xa0($sp)
/* DF6A30 80240030 AFB5009C */  sw        $s5, 0x9c($sp)
/* DF6A34 80240034 AFB40098 */  sw        $s4, 0x98($sp)
/* DF6A38 80240038 AFB30094 */  sw        $s3, 0x94($sp)
/* DF6A3C 8024003C AFB20090 */  sw        $s2, 0x90($sp)
/* DF6A40 80240040 AFB1008C */  sw        $s1, 0x8c($sp)
/* DF6A44 80240044 F7BA00C0 */  sdc1      $f26, 0xc0($sp)
/* DF6A48 80240048 F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* DF6A4C 8024004C F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* DF6A50 80240050 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* DF6A54 80240054 C6160010 */  lwc1      $f22, 0x10($s0)
/* DF6A58 80240058 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF6A5C 8024005C 4480D000 */  mtc1      $zero, $f26
/* DF6A60 80240060 3C01437F */  lui       $at, 0x437f
/* DF6A64 80240064 4481A000 */  mtc1      $at, $f20
/* DF6A68 80240068 8C82001C */  lw        $v0, 0x1c($a0)
/* DF6A6C 8024006C 4405D000 */  mfc1      $a1, $f26
/* DF6A70 80240070 4406A000 */  mfc1      $a2, $f20
/* DF6A74 80240074 C6180014 */  lwc1      $f24, 0x14($s0)
/* DF6A78 80240078 4680C620 */  cvt.s.w   $f24, $f24
/* DF6A7C 8024007C AFA20010 */  sw        $v0, 0x10($sp)
/* DF6A80 80240080 8E070018 */  lw        $a3, 0x18($s0)
/* DF6A84 80240084 0C00A8ED */  jal       update_lerp
/* DF6A88 80240088 0000202D */   daddu    $a0, $zero, $zero
/* DF6A8C 8024008C 4600A03C */  c.lt.s    $f20, $f0
/* DF6A90 80240090 00000000 */  nop
/* DF6A94 80240094 45000002 */  bc1f      .L802400A0
/* DF6A98 80240098 27B10038 */   addiu    $s1, $sp, 0x38
/* DF6A9C 8024009C 4600A006 */  mov.s     $f0, $f20
.L802400A0:
/* DF6AA0 802400A0 4600010D */  trunc.w.s $f4, $f0
/* DF6AA4 802400A4 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6AA8 802400A8 0000202D */  daddu     $a0, $zero, $zero
/* DF6AAC 802400AC 24050007 */  addiu     $a1, $zero, 7
/* DF6AB0 802400B0 240600FF */  addiu     $a2, $zero, 0xff
/* DF6AB4 802400B4 00C0382D */  daddu     $a3, $a2, $zero
/* DF6AB8 802400B8 00C0A82D */  daddu     $s5, $a2, $zero
/* DF6ABC 802400BC AFB50010 */  sw        $s5, 0x10($sp)
/* DF6AC0 802400C0 0C04EAA7 */  jal       func_8013AA9C
/* DF6AC4 802400C4 AFA00018 */   sw       $zero, 0x18($sp)
/* DF6AC8 802400C8 AFB10010 */  sw        $s1, 0x10($sp)
/* DF6ACC 802400CC 8E040004 */  lw        $a0, 4($s0)
/* DF6AD0 802400D0 8E050008 */  lw        $a1, 8($s0)
/* DF6AD4 802400D4 8E060000 */  lw        $a2, ($s0)
/* DF6AD8 802400D8 8E07000C */  lw        $a3, 0xc($s0)
/* DF6ADC 802400DC 0C04BA38 */  jal       msg_get_glyph
/* DF6AE0 802400E0 3C140001 */   lui      $s4, 1
/* DF6AE4 802400E4 93A20042 */  lbu       $v0, 0x42($sp)
/* DF6AE8 802400E8 3C013FE0 */  lui       $at, 0x3fe0
/* DF6AEC 802400EC 4481A800 */  mtc1      $at, $f21
/* DF6AF0 802400F0 4480A000 */  mtc1      $zero, $f20
/* DF6AF4 802400F4 44820000 */  mtc1      $v0, $f0
/* DF6AF8 802400F8 00000000 */  nop
/* DF6AFC 802400FC 46800021 */  cvt.d.w   $f0, $f0
/* DF6B00 80240100 46340002 */  mul.d     $f0, $f0, $f20
/* DF6B04 80240104 00000000 */  nop
/* DF6B08 80240108 36941630 */  ori       $s4, $s4, 0x1630
/* DF6B0C 8024010C 4600B0A1 */  cvt.d.s   $f2, $f22
/* DF6B10 80240110 27B00048 */  addiu     $s0, $sp, 0x48
/* DF6B14 80240114 4600C607 */  neg.s     $f24, $f24
/* DF6B18 80240118 46201080 */  add.d     $f2, $f2, $f0
/* DF6B1C 8024011C 4406C000 */  mfc1      $a2, $f24
/* DF6B20 80240120 4407D000 */  mfc1      $a3, $f26
/* DF6B24 80240124 462010A0 */  cvt.s.d   $f2, $f2
/* DF6B28 80240128 44051000 */  mfc1      $a1, $f2
/* DF6B2C 8024012C 0C019E40 */  jal       guTranslateF
/* DF6B30 80240130 0200202D */   daddu    $a0, $s0, $zero
/* DF6B34 80240134 0200202D */  daddu     $a0, $s0, $zero
/* DF6B38 80240138 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* DF6B3C 8024013C 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* DF6B40 80240140 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* DF6B44 80240144 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* DF6B48 80240148 96450000 */  lhu       $a1, ($s2)
/* DF6B4C 8024014C 8E620000 */  lw        $v0, ($s3)
/* DF6B50 80240150 00052980 */  sll       $a1, $a1, 6
/* DF6B54 80240154 00B42821 */  addu      $a1, $a1, $s4
/* DF6B58 80240158 0C019D40 */  jal       guMtxF2L
/* DF6B5C 8024015C 00452821 */   addu     $a1, $v0, $a1
/* DF6B60 80240160 3C03DA38 */  lui       $v1, 0xda38
/* DF6B64 80240164 34630002 */  ori       $v1, $v1, 2
/* DF6B68 80240168 0000202D */  daddu     $a0, $zero, $zero
/* DF6B6C 8024016C 27A50020 */  addiu     $a1, $sp, 0x20
/* DF6B70 80240170 3C060005 */  lui       $a2, 5
/* DF6B74 80240174 34C60040 */  ori       $a2, $a2, 0x40
/* DF6B78 80240178 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* DF6B7C 8024017C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* DF6B80 80240180 0200382D */  daddu     $a3, $s0, $zero
/* DF6B84 80240184 8E220000 */  lw        $v0, ($s1)
/* DF6B88 80240188 96480000 */  lhu       $t0, ($s2)
/* DF6B8C 8024018C 0040482D */  daddu     $t1, $v0, $zero
/* DF6B90 80240190 24420008 */  addiu     $v0, $v0, 8
/* DF6B94 80240194 AE220000 */  sw        $v0, ($s1)
/* DF6B98 80240198 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF6B9C 8024019C 00021180 */  sll       $v0, $v0, 6
/* DF6BA0 802401A0 00541021 */  addu      $v0, $v0, $s4
/* DF6BA4 802401A4 AD230000 */  sw        $v1, ($t1)
/* DF6BA8 802401A8 8E630000 */  lw        $v1, ($s3)
/* DF6BAC 802401AC 25080001 */  addiu     $t0, $t0, 1
/* DF6BB0 802401B0 00621821 */  addu      $v1, $v1, $v0
/* DF6BB4 802401B4 3C028000 */  lui       $v0, 0x8000
/* DF6BB8 802401B8 00621821 */  addu      $v1, $v1, $v0
/* DF6BBC 802401BC AD230004 */  sw        $v1, 4($t1)
/* DF6BC0 802401C0 93A20042 */  lbu       $v0, 0x42($sp)
/* DF6BC4 802401C4 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF6BC8 802401C8 93A90040 */  lbu       $t1, 0x40($sp)
/* DF6BCC 802401CC 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF6BD0 802401D0 44820000 */  mtc1      $v0, $f0
/* DF6BD4 802401D4 00000000 */  nop
/* DF6BD8 802401D8 46800021 */  cvt.d.w   $f0, $f0
/* DF6BDC 802401DC 8FA20038 */  lw        $v0, 0x38($sp)
/* DF6BE0 802401E0 46340002 */  mul.d     $f0, $f0, $f20
/* DF6BE4 802401E4 00000000 */  nop
/* DF6BE8 802401E8 A6480000 */  sh        $t0, ($s2)
/* DF6BEC 802401EC A7A0002E */  sh        $zero, 0x2e($sp)
/* DF6BF0 802401F0 A3B50030 */  sb        $s5, 0x30($sp)
/* DF6BF4 802401F4 AFA30024 */  sw        $v1, 0x24($sp)
/* DF6BF8 802401F8 A7A90028 */  sh        $t1, 0x28($sp)
/* DF6BFC 802401FC A7AA002A */  sh        $t2, 0x2a($sp)
/* DF6C00 80240200 AFA20020 */  sw        $v0, 0x20($sp)
/* DF6C04 80240204 46200007 */  neg.d     $f0, $f0
/* DF6C08 80240208 4620010D */  trunc.w.d $f4, $f0
/* DF6C0C 8024020C 44022000 */  mfc1      $v0, $f4
/* DF6C10 80240210 0C04EBDC */  jal       func_8013AF70
/* DF6C14 80240214 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF6C18 80240218 3C04D838 */  lui       $a0, 0xd838
/* DF6C1C 8024021C 8E220000 */  lw        $v0, ($s1)
/* DF6C20 80240220 34840002 */  ori       $a0, $a0, 2
/* DF6C24 80240224 0040182D */  daddu     $v1, $v0, $zero
/* DF6C28 80240228 24420008 */  addiu     $v0, $v0, 8
/* DF6C2C 8024022C AE220000 */  sw        $v0, ($s1)
/* DF6C30 80240230 24020040 */  addiu     $v0, $zero, 0x40
/* DF6C34 80240234 AC640000 */  sw        $a0, ($v1)
/* DF6C38 80240238 AC620004 */  sw        $v0, 4($v1)
/* DF6C3C 8024023C 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* DF6C40 80240240 8FB5009C */  lw        $s5, 0x9c($sp)
/* DF6C44 80240244 8FB40098 */  lw        $s4, 0x98($sp)
/* DF6C48 80240248 8FB30094 */  lw        $s3, 0x94($sp)
/* DF6C4C 8024024C 8FB20090 */  lw        $s2, 0x90($sp)
/* DF6C50 80240250 8FB1008C */  lw        $s1, 0x8c($sp)
/* DF6C54 80240254 8FB00088 */  lw        $s0, 0x88($sp)
/* DF6C58 80240258 D7BA00C0 */  ldc1      $f26, 0xc0($sp)
/* DF6C5C 8024025C D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* DF6C60 80240260 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* DF6C64 80240264 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* DF6C68 80240268 03E00008 */  jr        $ra
/* DF6C6C 8024026C 27BD00C8 */   addiu    $sp, $sp, 0xc8
