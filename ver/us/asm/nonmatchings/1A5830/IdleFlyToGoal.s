.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8029DA18
.double 180.0

.section .text

glabel IdleFlyToGoal
/* 1AA498 8027BBB8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 1AA49C 8027BBBC AFB20020 */  sw        $s2, 0x20($sp)
/* 1AA4A0 8027BBC0 0080902D */  daddu     $s2, $a0, $zero
/* 1AA4A4 8027BBC4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AA4A8 8027BBC8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1AA4AC 8027BBCC AFB00018 */  sw        $s0, 0x18($sp)
/* 1AA4B0 8027BBD0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1AA4B4 8027BBD4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 1AA4B8 8027BBD8 10A0004F */  beqz      $a1, .L8027BD18
/* 1AA4BC 8027BBDC 8E51000C */   lw       $s1, 0xc($s2)
/* 1AA4C0 8027BBE0 8E250000 */  lw        $a1, ($s1)
/* 1AA4C4 8027BBE4 0C0B1EAF */  jal       evt_get_variable
/* 1AA4C8 8027BBE8 26310004 */   addiu    $s1, $s1, 4
/* 1AA4CC 8027BBEC 0040202D */  daddu     $a0, $v0, $zero
/* 1AA4D0 8027BBF0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AA4D4 8027BBF4 14820002 */  bne       $a0, $v0, .L8027BC00
/* 1AA4D8 8027BBF8 00000000 */   nop
/* 1AA4DC 8027BBFC 8E440148 */  lw        $a0, 0x148($s2)
.L8027BC00:
/* 1AA4E0 8027BC00 0C09A75B */  jal       get_actor
/* 1AA4E4 8027BC04 00000000 */   nop
/* 1AA4E8 8027BC08 0040802D */  daddu     $s0, $v0, $zero
/* 1AA4EC 8027BC0C AE500074 */  sw        $s0, 0x74($s2)
/* 1AA4F0 8027BC10 8E250000 */  lw        $a1, ($s1)
/* 1AA4F4 8027BC14 26310004 */  addiu     $s1, $s1, 4
/* 1AA4F8 8027BC18 0C0B1EAF */  jal       evt_get_variable
/* 1AA4FC 8027BC1C 0240202D */   daddu    $a0, $s2, $zero
/* 1AA500 8027BC20 A6020120 */  sh        $v0, 0x120($s0)
/* 1AA504 8027BC24 8E250000 */  lw        $a1, ($s1)
/* 1AA508 8027BC28 26310004 */  addiu     $s1, $s1, 4
/* 1AA50C 8027BC2C 0C0B1EAF */  jal       evt_get_variable
/* 1AA510 8027BC30 0240202D */   daddu    $a0, $s2, $zero
/* 1AA514 8027BC34 A6020122 */  sh        $v0, 0x122($s0)
/* 1AA518 8027BC38 8E250000 */  lw        $a1, ($s1)
/* 1AA51C 8027BC3C 0C0B1EAF */  jal       evt_get_variable
/* 1AA520 8027BC40 0240202D */   daddu    $a0, $s2, $zero
/* 1AA524 8027BC44 AE42007C */  sw        $v0, 0x7c($s2)
/* 1AA528 8027BC48 C60000D4 */  lwc1      $f0, 0xd4($s0)
/* 1AA52C 8027BC4C C6060144 */  lwc1      $f6, 0x144($s0)
/* 1AA530 8027BC50 46003081 */  sub.s     $f2, $f6, $f0
/* 1AA534 8027BC54 46021202 */  mul.s     $f8, $f2, $f2
/* 1AA538 8027BC58 00000000 */  nop
/* 1AA53C 8027BC5C C6040148 */  lwc1      $f4, 0x148($s0)
/* 1AA540 8027BC60 C60000D8 */  lwc1      $f0, 0xd8($s0)
/* 1AA544 8027BC64 46002081 */  sub.s     $f2, $f4, $f0
/* 1AA548 8027BC68 46021282 */  mul.s     $f10, $f2, $f2
/* 1AA54C 8027BC6C 00000000 */  nop
/* 1AA550 8027BC70 C60000DC */  lwc1      $f0, 0xdc($s0)
/* 1AA554 8027BC74 C602014C */  lwc1      $f2, 0x14c($s0)
/* 1AA558 8027BC78 46001001 */  sub.s     $f0, $f2, $f0
/* 1AA55C 8027BC7C 46000002 */  mul.s     $f0, $f0, $f0
/* 1AA560 8027BC80 00000000 */  nop
/* 1AA564 8027BC84 E60600C8 */  swc1      $f6, 0xc8($s0)
/* 1AA568 8027BC88 E60600E0 */  swc1      $f6, 0xe0($s0)
/* 1AA56C 8027BC8C 460A4200 */  add.s     $f8, $f8, $f10
/* 1AA570 8027BC90 E60400CC */  swc1      $f4, 0xcc($s0)
/* 1AA574 8027BC94 E60400E4 */  swc1      $f4, 0xe4($s0)
/* 1AA578 8027BC98 46004300 */  add.s     $f12, $f8, $f0
/* 1AA57C 8027BC9C E60200D0 */  swc1      $f2, 0xd0($s0)
/* 1AA580 8027BCA0 E60200E8 */  swc1      $f2, 0xe8($s0)
/* 1AA584 8027BCA4 46006084 */  sqrt.s    $f2, $f12
/* 1AA588 8027BCA8 46021032 */  c.eq.s    $f2, $f2
/* 1AA58C 8027BCAC 00000000 */  nop
/* 1AA590 8027BCB0 45010004 */  bc1t      .L8027BCC4
/* 1AA594 8027BCB4 261100C8 */   addiu    $s1, $s0, 0xc8
/* 1AA598 8027BCB8 0C0187BC */  jal       sqrtf
/* 1AA59C 8027BCBC 00000000 */   nop
/* 1AA5A0 8027BCC0 46000086 */  mov.s     $f2, $f0
.L8027BCC4:
/* 1AA5A4 8027BCC4 86020120 */  lh        $v0, 0x120($s0)
/* 1AA5A8 8027BCC8 14400007 */  bnez      $v0, .L8027BCE8
/* 1AA5AC 8027BCCC E6020114 */   swc1     $f2, 0x114($s0)
/* 1AA5B0 8027BCD0 C6000108 */  lwc1      $f0, 0x108($s0)
/* 1AA5B4 8027BCD4 46001003 */  div.s     $f0, $f2, $f0
/* 1AA5B8 8027BCD8 4600038D */  trunc.w.s $f14, $f0
/* 1AA5BC 8027BCDC 44027000 */  mfc1      $v0, $f14
/* 1AA5C0 8027BCE0 0809EF3F */  j         .L8027BCFC
/* 1AA5C4 8027BCE4 A6020120 */   sh       $v0, 0x120($s0)
.L8027BCE8:
/* 1AA5C8 8027BCE8 44820000 */  mtc1      $v0, $f0
/* 1AA5CC 8027BCEC 00000000 */  nop
/* 1AA5D0 8027BCF0 46800020 */  cvt.s.w   $f0, $f0
/* 1AA5D4 8027BCF4 46001003 */  div.s     $f0, $f2, $f0
/* 1AA5D8 8027BCF8 E6000108 */  swc1      $f0, 0x108($s0)
.L8027BCFC:
/* 1AA5DC 8027BCFC 86220058 */  lh        $v0, 0x58($s1)
/* 1AA5E0 8027BD00 54400003 */  bnel      $v0, $zero, .L8027BD10
/* 1AA5E4 8027BD04 AE200050 */   sw       $zero, 0x50($s1)
/* 1AA5E8 8027BD08 0809EFC6 */  j         .L8027BF18
/* 1AA5EC 8027BD0C 24020002 */   addiu    $v0, $zero, 2
.L8027BD10:
/* 1AA5F0 8027BD10 AE200048 */  sw        $zero, 0x48($s1)
/* 1AA5F4 8027BD14 AE200044 */  sw        $zero, 0x44($s1)
.L8027BD18:
/* 1AA5F8 8027BD18 8E500074 */  lw        $s0, 0x74($s2)
/* 1AA5FC 8027BD1C 86020120 */  lh        $v0, 0x120($s0)
/* 1AA600 8027BD20 C6000118 */  lwc1      $f0, 0x118($s0)
/* 1AA604 8027BD24 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA608 8027BD28 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA60C 8027BD2C 8E0500E0 */  lw        $a1, 0xe0($s0)
/* 1AA610 8027BD30 8E0600D4 */  lw        $a2, 0xd4($s0)
/* 1AA614 8027BD34 4600038D */  trunc.w.s $f14, $f0
/* 1AA618 8027BD38 44077000 */  mfc1      $a3, $f14
/* 1AA61C 8027BD3C 0C09EC37 */  jal       update_lerp_battle
/* 1AA620 8027BD40 00000000 */   nop
/* 1AA624 8027BD44 C6020118 */  lwc1      $f2, 0x118($s0)
/* 1AA628 8027BD48 86020120 */  lh        $v0, 0x120($s0)
/* 1AA62C 8027BD4C E60000C8 */  swc1      $f0, 0xc8($s0)
/* 1AA630 8027BD50 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA634 8027BD54 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA638 8027BD58 8E0500E4 */  lw        $a1, 0xe4($s0)
/* 1AA63C 8027BD5C 8E0600D8 */  lw        $a2, 0xd8($s0)
/* 1AA640 8027BD60 4600138D */  trunc.w.s $f14, $f2
/* 1AA644 8027BD64 44077000 */  mfc1      $a3, $f14
/* 1AA648 8027BD68 0C09EC37 */  jal       update_lerp_battle
/* 1AA64C 8027BD6C 00000000 */   nop
/* 1AA650 8027BD70 C6020118 */  lwc1      $f2, 0x118($s0)
/* 1AA654 8027BD74 86020120 */  lh        $v0, 0x120($s0)
/* 1AA658 8027BD78 E60000CC */  swc1      $f0, 0xcc($s0)
/* 1AA65C 8027BD7C AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA660 8027BD80 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA664 8027BD84 8E0500E8 */  lw        $a1, 0xe8($s0)
/* 1AA668 8027BD88 8E0600DC */  lw        $a2, 0xdc($s0)
/* 1AA66C 8027BD8C 4600138D */  trunc.w.s $f14, $f2
/* 1AA670 8027BD90 44077000 */  mfc1      $a3, $f14
/* 1AA674 8027BD94 0C09EC37 */  jal       update_lerp_battle
/* 1AA678 8027BD98 00000000 */   nop
/* 1AA67C 8027BD9C C6020118 */  lwc1      $f2, 0x118($s0)
/* 1AA680 8027BDA0 3C013F80 */  lui       $at, 0x3f80
/* 1AA684 8027BDA4 4481B000 */  mtc1      $at, $f22
/* 1AA688 8027BDA8 86020120 */  lh        $v0, 0x120($s0)
/* 1AA68C 8027BDAC 46161080 */  add.s     $f2, $f2, $f22
/* 1AA690 8027BDB0 E60000D0 */  swc1      $f0, 0xd0($s0)
/* 1AA694 8027BDB4 44820000 */  mtc1      $v0, $f0
/* 1AA698 8027BDB8 00000000 */  nop
/* 1AA69C 8027BDBC 46800020 */  cvt.s.w   $f0, $f0
/* 1AA6A0 8027BDC0 4602003C */  c.lt.s    $f0, $f2
/* 1AA6A4 8027BDC4 00000000 */  nop
/* 1AA6A8 8027BDC8 45000009 */  bc1f      .L8027BDF0
/* 1AA6AC 8027BDCC E6020118 */   swc1     $f2, 0x118($s0)
/* 1AA6B0 8027BDD0 C60000D4 */  lwc1      $f0, 0xd4($s0)
/* 1AA6B4 8027BDD4 C60200D8 */  lwc1      $f2, 0xd8($s0)
/* 1AA6B8 8027BDD8 C60400DC */  lwc1      $f4, 0xdc($s0)
/* 1AA6BC 8027BDDC 24020002 */  addiu     $v0, $zero, 2
/* 1AA6C0 8027BDE0 E6000144 */  swc1      $f0, 0x144($s0)
/* 1AA6C4 8027BDE4 E6020148 */  swc1      $f2, 0x148($s0)
/* 1AA6C8 8027BDE8 0809EFC6 */  j         .L8027BF18
/* 1AA6CC 8027BDEC E604014C */   swc1     $f4, 0x14c($s0)
.L8027BDF0:
/* 1AA6D0 8027BDF0 C60200D4 */  lwc1      $f2, 0xd4($s0)
/* 1AA6D4 8027BDF4 C60000C8 */  lwc1      $f0, 0xc8($s0)
/* 1AA6D8 8027BDF8 46001081 */  sub.s     $f2, $f2, $f0
/* 1AA6DC 8027BDFC 46021102 */  mul.s     $f4, $f2, $f2
/* 1AA6E0 8027BE00 00000000 */  nop
/* 1AA6E4 8027BE04 C60000CC */  lwc1      $f0, 0xcc($s0)
/* 1AA6E8 8027BE08 C60200D8 */  lwc1      $f2, 0xd8($s0)
/* 1AA6EC 8027BE0C 46001081 */  sub.s     $f2, $f2, $f0
/* 1AA6F0 8027BE10 46021182 */  mul.s     $f6, $f2, $f2
/* 1AA6F4 8027BE14 00000000 */  nop
/* 1AA6F8 8027BE18 C60000D0 */  lwc1      $f0, 0xd0($s0)
/* 1AA6FC 8027BE1C C60200DC */  lwc1      $f2, 0xdc($s0)
/* 1AA700 8027BE20 46001001 */  sub.s     $f0, $f2, $f0
/* 1AA704 8027BE24 46000002 */  mul.s     $f0, $f0, $f0
/* 1AA708 8027BE28 00000000 */  nop
/* 1AA70C 8027BE2C 46062100 */  add.s     $f4, $f4, $f6
/* 1AA710 8027BE30 46002300 */  add.s     $f12, $f4, $f0
/* 1AA714 8027BE34 46006004 */  sqrt.s    $f0, $f12
/* 1AA718 8027BE38 46000032 */  c.eq.s    $f0, $f0
/* 1AA71C 8027BE3C 00000000 */  nop
/* 1AA720 8027BE40 45010003 */  bc1t      .L8027BE50
/* 1AA724 8027BE44 00000000 */   nop
/* 1AA728 8027BE48 0C0187BC */  jal       sqrtf
/* 1AA72C 8027BE4C 00000000 */   nop
.L8027BE50:
/* 1AA730 8027BE50 4480A000 */  mtc1      $zero, $f20
/* 1AA734 8027BE54 46000086 */  mov.s     $f2, $f0
/* 1AA738 8027BE58 46141032 */  c.eq.s    $f2, $f20
/* 1AA73C 8027BE5C 00000000 */  nop
/* 1AA740 8027BE60 45030001 */  bc1tl     .L8027BE68
/* 1AA744 8027BE64 4600B086 */   mov.s    $f2, $f22
.L8027BE68:
/* 1AA748 8027BE68 C6000114 */  lwc1      $f0, 0x114($s0)
/* 1AA74C 8027BE6C 46140032 */  c.eq.s    $f0, $f20
/* 1AA750 8027BE70 00000000 */  nop
/* 1AA754 8027BE74 45030001 */  bc1tl     .L8027BE7C
/* 1AA758 8027BE78 E6160114 */   swc1     $f22, 0x114($s0)
.L8027BE7C:
/* 1AA75C 8027BE7C C6000114 */  lwc1      $f0, 0x114($s0)
/* 1AA760 8027BE80 3C013FF0 */  lui       $at, 0x3ff0
/* 1AA764 8027BE84 44816800 */  mtc1      $at, $f13
/* 1AA768 8027BE88 44806000 */  mtc1      $zero, $f12
/* 1AA76C 8027BE8C 46001003 */  div.s     $f0, $f2, $f0
/* 1AA770 8027BE90 46000021 */  cvt.d.s   $f0, $f0
/* 1AA774 8027BE94 46206301 */  sub.d     $f12, $f12, $f0
/* 1AA778 8027BE98 3C01802A */  lui       $at, %hi(D_8029DA18)
/* 1AA77C 8027BE9C D420DA18 */  ldc1      $f0, %lo(D_8029DA18)($at)
/* 1AA780 8027BEA0 46206302 */  mul.d     $f12, $f12, $f0
/* 1AA784 8027BEA4 00000000 */  nop
/* 1AA788 8027BEA8 0C00A8BB */  jal       sin_deg
/* 1AA78C 8027BEAC 46206320 */   cvt.s.d  $f12, $f12
/* 1AA790 8027BEB0 86030122 */  lh        $v1, 0x122($s0)
/* 1AA794 8027BEB4 14600002 */  bnez      $v1, .L8027BEC0
/* 1AA798 8027BEB8 46000186 */   mov.s    $f6, $f0
/* 1AA79C 8027BEBC 4600A186 */  mov.s     $f6, $f20
.L8027BEC0:
/* 1AA7A0 8027BEC0 04610007 */  bgez      $v1, .L8027BEE0
/* 1AA7A4 8027BEC4 00031023 */   negu     $v0, $v1
/* 1AA7A8 8027BEC8 44821000 */  mtc1      $v0, $f2
/* 1AA7AC 8027BECC 00000000 */  nop
/* 1AA7B0 8027BED0 468010A0 */  cvt.s.w   $f2, $f2
/* 1AA7B4 8027BED4 46003007 */  neg.s     $f0, $f6
/* 1AA7B8 8027BED8 46020182 */  mul.s     $f6, $f0, $f2
/* 1AA7BC 8027BEDC 00000000 */  nop
.L8027BEE0:
/* 1AA7C0 8027BEE0 18600006 */  blez      $v1, .L8027BEFC
/* 1AA7C4 8027BEE4 0000102D */   daddu    $v0, $zero, $zero
/* 1AA7C8 8027BEE8 44830000 */  mtc1      $v1, $f0
/* 1AA7CC 8027BEEC 00000000 */  nop
/* 1AA7D0 8027BEF0 46800020 */  cvt.s.w   $f0, $f0
/* 1AA7D4 8027BEF4 46003182 */  mul.s     $f6, $f6, $f0
/* 1AA7D8 8027BEF8 00000000 */  nop
.L8027BEFC:
/* 1AA7DC 8027BEFC C60000C8 */  lwc1      $f0, 0xc8($s0)
/* 1AA7E0 8027BF00 C60200CC */  lwc1      $f2, 0xcc($s0)
/* 1AA7E4 8027BF04 C60400D0 */  lwc1      $f4, 0xd0($s0)
/* 1AA7E8 8027BF08 46061080 */  add.s     $f2, $f2, $f6
/* 1AA7EC 8027BF0C E6000144 */  swc1      $f0, 0x144($s0)
/* 1AA7F0 8027BF10 E604014C */  swc1      $f4, 0x14c($s0)
/* 1AA7F4 8027BF14 E6020148 */  swc1      $f2, 0x148($s0)
.L8027BF18:
/* 1AA7F8 8027BF18 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AA7FC 8027BF1C 8FB20020 */  lw        $s2, 0x20($sp)
/* 1AA800 8027BF20 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1AA804 8027BF24 8FB00018 */  lw        $s0, 0x18($sp)
/* 1AA808 8027BF28 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1AA80C 8027BF2C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1AA810 8027BF30 03E00008 */  jr        $ra
/* 1AA814 8027BF34 27BD0038 */   addiu    $sp, $sp, 0x38
