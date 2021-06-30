.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024059C_D3AB6C
/* D3AB6C 8024059C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D3AB70 802405A0 AFB1002C */  sw        $s1, 0x2c($sp)
/* D3AB74 802405A4 AFB20030 */  sw        $s2, 0x30($sp)
/* D3AB78 802405A8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D3AB7C 802405AC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D3AB80 802405B0 AFBF0034 */  sw        $ra, 0x34($sp)
/* D3AB84 802405B4 AFB00028 */  sw        $s0, 0x28($sp)
/* D3AB88 802405B8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* D3AB8C 802405BC 10A00003 */  beqz      $a1, .L802405CC
/* D3AB90 802405C0 0080882D */   daddu    $s1, $a0, $zero
/* D3AB94 802405C4 2402000A */  addiu     $v0, $zero, 0xa
/* D3AB98 802405C8 AE220074 */  sw        $v0, 0x74($s1)
.L802405CC:
/* D3AB9C 802405CC 3C014387 */  lui       $at, 0x4387
/* D3ABA0 802405D0 44810000 */  mtc1      $at, $f0
/* D3ABA4 802405D4 00000000 */  nop
/* D3ABA8 802405D8 E6400080 */  swc1      $f0, 0x80($s2)
/* D3ABAC 802405DC 8E220074 */  lw        $v0, 0x74($s1)
/* D3ABB0 802405E0 24420004 */  addiu     $v0, $v0, 4
/* D3ABB4 802405E4 AE220074 */  sw        $v0, 0x74($s1)
/* D3ABB8 802405E8 C64C0080 */  lwc1      $f12, 0x80($s2)
/* D3ABBC 802405EC 0C00A8BB */  jal       sin_deg
/* D3ABC0 802405F0 3C106666 */   lui      $s0, 0x6666
/* D3ABC4 802405F4 8E230074 */  lw        $v1, 0x74($s1)
/* D3ABC8 802405F8 36106667 */  ori       $s0, $s0, 0x6667
/* D3ABCC 802405FC 00700018 */  mult      $v1, $s0
/* D3ABD0 80240600 C64C0080 */  lwc1      $f12, 0x80($s2)
/* D3ABD4 80240604 00031FC3 */  sra       $v1, $v1, 0x1f
/* D3ABD8 80240608 00004010 */  mfhi      $t0
/* D3ABDC 8024060C 00081083 */  sra       $v0, $t0, 2
/* D3ABE0 80240610 00431023 */  subu      $v0, $v0, $v1
/* D3ABE4 80240614 4482A000 */  mtc1      $v0, $f20
/* D3ABE8 80240618 00000000 */  nop
/* D3ABEC 8024061C 4680A520 */  cvt.s.w   $f20, $f20
/* D3ABF0 80240620 4600A502 */  mul.s     $f20, $f20, $f0
/* D3ABF4 80240624 0C00A8D4 */  jal       cos_deg
/* D3ABF8 80240628 00000000 */   nop
/* D3ABFC 8024062C 8E230074 */  lw        $v1, 0x74($s1)
/* D3AC00 80240630 00700018 */  mult      $v1, $s0
/* D3AC04 80240634 46000007 */  neg.s     $f0, $f0
/* D3AC08 80240638 00031FC3 */  sra       $v1, $v1, 0x1f
/* D3AC0C 8024063C 00004010 */  mfhi      $t0
/* D3AC10 80240640 00081083 */  sra       $v0, $t0, 2
/* D3AC14 80240644 00431023 */  subu      $v0, $v0, $v1
/* D3AC18 80240648 44824000 */  mtc1      $v0, $f8
/* D3AC1C 8024064C 00000000 */  nop
/* D3AC20 80240650 46804220 */  cvt.s.w   $f8, $f8
/* D3AC24 80240654 46004202 */  mul.s     $f8, $f8, $f0
/* D3AC28 80240658 00000000 */  nop
/* D3AC2C 8024065C 0000202D */  daddu     $a0, $zero, $zero
/* D3AC30 80240660 864200B0 */  lh        $v0, 0xb0($s2)
/* D3AC34 80240664 3C013F00 */  lui       $at, 0x3f00
/* D3AC38 80240668 44811000 */  mtc1      $at, $f2
/* D3AC3C 8024066C 44820000 */  mtc1      $v0, $f0
/* D3AC40 80240670 00000000 */  nop
/* D3AC44 80240674 46800020 */  cvt.s.w   $f0, $f0
/* D3AC48 80240678 46020002 */  mul.s     $f0, $f0, $f2
/* D3AC4C 8024067C 00000000 */  nop
/* D3AC50 80240680 27A50018 */  addiu     $a1, $sp, 0x18
/* D3AC54 80240684 27A6001C */  addiu     $a2, $sp, 0x1c
/* D3AC58 80240688 C6440028 */  lwc1      $f4, 0x28($s2)
/* D3AC5C 8024068C 27A70020 */  addiu     $a3, $sp, 0x20
/* D3AC60 80240690 46142100 */  add.s     $f4, $f4, $f20
/* D3AC64 80240694 C642002C */  lwc1      $f2, 0x2c($s2)
/* D3AC68 80240698 3C0143FA */  lui       $at, 0x43fa
/* D3AC6C 8024069C 44813000 */  mtc1      $at, $f6
/* D3AC70 802406A0 46001080 */  add.s     $f2, $f2, $f0
/* D3AC74 802406A4 C6400030 */  lwc1      $f0, 0x30($s2)
/* D3AC78 802406A8 27A20024 */  addiu     $v0, $sp, 0x24
/* D3AC7C 802406AC E7A60024 */  swc1      $f6, 0x24($sp)
/* D3AC80 802406B0 46080000 */  add.s     $f0, $f0, $f8
/* D3AC84 802406B4 E7A40018 */  swc1      $f4, 0x18($sp)
/* D3AC88 802406B8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* D3AC8C 802406BC E7A00020 */  swc1      $f0, 0x20($sp)
/* D3AC90 802406C0 0C0372DF */  jal       npc_raycast_down_sides
/* D3AC94 802406C4 AFA20010 */   sw       $v0, 0x10($sp)
/* D3AC98 802406C8 10400011 */  beqz      $v0, .L80240710
/* D3AC9C 802406CC 24020002 */   addiu    $v0, $zero, 2
/* D3ACA0 802406D0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* D3ACA4 802406D4 3C0142C8 */  lui       $at, 0x42c8
/* D3ACA8 802406D8 44810000 */  mtc1      $at, $f0
/* D3ACAC 802406DC 00000000 */  nop
/* D3ACB0 802406E0 4600103C */  c.lt.s    $f2, $f0
/* D3ACB4 802406E4 00000000 */  nop
/* D3ACB8 802406E8 45000008 */  bc1f      .L8024070C
/* D3ACBC 802406EC 0000102D */   daddu    $v0, $zero, $zero
/* D3ACC0 802406F0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* D3ACC4 802406F4 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* D3ACC8 802406F8 C7A40020 */  lwc1      $f4, 0x20($sp)
/* D3ACCC 802406FC E6400028 */  swc1      $f0, 0x28($s2)
/* D3ACD0 80240700 E642002C */  swc1      $f2, 0x2c($s2)
/* D3ACD4 80240704 080901C4 */  j         .L80240710
/* D3ACD8 80240708 E6440030 */   swc1     $f4, 0x30($s2)
.L8024070C:
/* D3ACDC 8024070C 24020002 */  addiu     $v0, $zero, 2
.L80240710:
/* D3ACE0 80240710 8FBF0034 */  lw        $ra, 0x34($sp)
/* D3ACE4 80240714 8FB20030 */  lw        $s2, 0x30($sp)
/* D3ACE8 80240718 8FB1002C */  lw        $s1, 0x2c($sp)
/* D3ACEC 8024071C 8FB00028 */  lw        $s0, 0x28($sp)
/* D3ACF0 80240720 D7B40038 */  ldc1      $f20, 0x38($sp)
/* D3ACF4 80240724 03E00008 */  jr        $ra
/* D3ACF8 80240728 27BD0040 */   addiu    $sp, $sp, 0x40
