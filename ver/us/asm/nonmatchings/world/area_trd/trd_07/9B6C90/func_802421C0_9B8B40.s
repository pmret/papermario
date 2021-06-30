.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421C0_9B8B40
/* 9B8B40 802421C0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 9B8B44 802421C4 AFB20030 */  sw        $s2, 0x30($sp)
/* 9B8B48 802421C8 0080902D */  daddu     $s2, $a0, $zero
/* 9B8B4C 802421CC AFBF0034 */  sw        $ra, 0x34($sp)
/* 9B8B50 802421D0 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9B8B54 802421D4 AFB00028 */  sw        $s0, 0x28($sp)
/* 9B8B58 802421D8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9B8B5C 802421DC 8E510148 */  lw        $s1, 0x148($s2)
/* 9B8B60 802421E0 0C00EABB */  jal       get_npc_unsafe
/* 9B8B64 802421E4 86240008 */   lh       $a0, 8($s1)
/* 9B8B68 802421E8 0040802D */  daddu     $s0, $v0, $zero
/* 9B8B6C 802421EC C604001C */  lwc1      $f4, 0x1c($s0)
/* 9B8B70 802421F0 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9B8B74 802421F4 0200202D */  daddu     $a0, $s0, $zero
/* 9B8B78 802421F8 46002100 */  add.s     $f4, $f4, $f0
/* 9B8B7C 802421FC C602003C */  lwc1      $f2, 0x3c($s0)
/* 9B8B80 80242200 8E050018 */  lw        $a1, 0x18($s0)
/* 9B8B84 80242204 46041080 */  add.s     $f2, $f2, $f4
/* 9B8B88 80242208 8E06000C */  lw        $a2, 0xc($s0)
/* 9B8B8C 8024220C C6200078 */  lwc1      $f0, 0x78($s1)
/* 9B8B90 80242210 46800020 */  cvt.s.w   $f0, $f0
/* 9B8B94 80242214 E602003C */  swc1      $f2, 0x3c($s0)
/* 9B8B98 80242218 3C014059 */  lui       $at, 0x4059
/* 9B8B9C 8024221C 44811800 */  mtc1      $at, $f3
/* 9B8BA0 80242220 44801000 */  mtc1      $zero, $f2
/* 9B8BA4 80242224 46000021 */  cvt.d.s   $f0, $f0
/* 9B8BA8 80242228 E604001C */  swc1      $f4, 0x1c($s0)
/* 9B8BAC 8024222C 46220003 */  div.d     $f0, $f0, $f2
/* 9B8BB0 80242230 0C00EA95 */  jal       npc_move_heading
/* 9B8BB4 80242234 46200520 */   cvt.s.d  $f20, $f0
/* 9B8BB8 80242238 27A50018 */  addiu     $a1, $sp, 0x18
/* 9B8BBC 8024223C 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9B8BC0 80242240 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9B8BC4 80242244 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9B8BC8 80242248 C6040040 */  lwc1      $f4, 0x40($s0)
/* 9B8BCC 8024224C 3C01447A */  lui       $at, 0x447a
/* 9B8BD0 80242250 44813000 */  mtc1      $at, $f6
/* 9B8BD4 80242254 27A20024 */  addiu     $v0, $sp, 0x24
/* 9B8BD8 80242258 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9B8BDC 8024225C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9B8BE0 80242260 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9B8BE4 80242264 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9B8BE8 80242268 AFA20010 */  sw        $v0, 0x10($sp)
/* 9B8BEC 8024226C 8E040080 */  lw        $a0, 0x80($s0)
/* 9B8BF0 80242270 0C0372DF */  jal       npc_raycast_down_sides
/* 9B8BF4 80242274 27A70020 */   addiu    $a3, $sp, 0x20
/* 9B8BF8 80242278 10400003 */  beqz      $v0, .L80242288
/* 9B8BFC 8024227C 4600A086 */   mov.s    $f2, $f20
/* 9B8C00 80242280 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9B8C04 80242284 46140080 */  add.s     $f2, $f0, $f20
.L80242288:
/* 9B8C08 80242288 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9B8C0C 8024228C 4602003C */  c.lt.s    $f0, $f2
/* 9B8C10 80242290 00000000 */  nop
/* 9B8C14 80242294 45010009 */  bc1t      .L802422BC
/* 9B8C18 80242298 2402000A */   addiu    $v0, $zero, 0xa
/* 9B8C1C 8024229C A602008E */  sh        $v0, 0x8e($s0)
/* 9B8C20 802422A0 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B8C24 802422A4 8C42002C */  lw        $v0, 0x2c($v0)
/* 9B8C28 802422A8 AE020028 */  sw        $v0, 0x28($s0)
/* 9B8C2C 802422AC 9622008E */  lhu       $v0, 0x8e($s1)
/* 9B8C30 802422B0 A60200A8 */  sh        $v0, 0xa8($s0)
/* 9B8C34 802422B4 2402000F */  addiu     $v0, $zero, 0xf
/* 9B8C38 802422B8 AE420070 */  sw        $v0, 0x70($s2)
.L802422BC:
/* 9B8C3C 802422BC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9B8C40 802422C0 8FB20030 */  lw        $s2, 0x30($sp)
/* 9B8C44 802422C4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9B8C48 802422C8 8FB00028 */  lw        $s0, 0x28($sp)
/* 9B8C4C 802422CC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9B8C50 802422D0 03E00008 */  jr        $ra
/* 9B8C54 802422D4 27BD0040 */   addiu    $sp, $sp, 0x40
