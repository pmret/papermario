.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80218000_4EF4A0
/* 4EF4A0 80218000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 4EF4A4 80218004 AFB40020 */  sw        $s4, 0x20($sp)
/* 4EF4A8 80218008 24140003 */  addiu     $s4, $zero, 3
/* 4EF4AC 8021800C AFB20018 */  sw        $s2, 0x18($sp)
/* 4EF4B0 80218010 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4EF4B4 80218014 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4EF4B8 80218018 AFB10014 */  sw        $s1, 0x14($sp)
/* 4EF4BC 8021801C AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF4C0 80218020 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 4EF4C4 80218024 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 4EF4C8 80218028 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 4EF4CC 8021802C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 4EF4D0 80218030 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 4EF4D4 80218034 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 4EF4D8 80218038 8C840148 */  lw        $a0, 0x148($a0)
/* 4EF4DC 8021803C 3C0140E0 */  lui       $at, 0x40e0
/* 4EF4E0 80218040 4481A000 */  mtc1      $at, $f20
/* 4EF4E4 80218044 3C013F19 */  lui       $at, 0x3f19
/* 4EF4E8 80218048 3421999A */  ori       $at, $at, 0x999a
/* 4EF4EC 8021804C 4481F000 */  mtc1      $at, $f30
/* 4EF4F0 80218050 3C014040 */  lui       $at, 0x4040
/* 4EF4F4 80218054 4481E000 */  mtc1      $at, $f28
/* 4EF4F8 80218058 0C09A75B */  jal       get_actor
/* 4EF4FC 8021805C 0000902D */   daddu    $s2, $zero, $zero
/* 4EF500 80218060 24040180 */  addiu     $a0, $zero, 0x180
/* 4EF504 80218064 0C00AB39 */  jal       heap_malloc
/* 4EF508 80218068 0040982D */   daddu    $s3, $v0, $zero
/* 4EF50C 8021806C 0040882D */  daddu     $s1, $v0, $zero
/* 4EF510 80218070 26300008 */  addiu     $s0, $s1, 8
/* 4EF514 80218074 C67A014C */  lwc1      $f26, 0x14c($s3)
/* 4EF518 80218078 C6620144 */  lwc1      $f2, 0x144($s3)
/* 4EF51C 8021807C 3C014028 */  lui       $at, 0x4028
/* 4EF520 80218080 44810800 */  mtc1      $at, $f1
/* 4EF524 80218084 44800000 */  mtc1      $zero, $f0
/* 4EF528 80218088 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF52C 8021808C 46201080 */  add.d     $f2, $f2, $f0
/* 4EF530 80218090 C6600148 */  lwc1      $f0, 0x148($s3)
/* 4EF534 80218094 3C014014 */  lui       $at, 0x4014
/* 4EF538 80218098 44812800 */  mtc1      $at, $f5
/* 4EF53C 8021809C 44802000 */  mtc1      $zero, $f4
/* 4EF540 802180A0 46000021 */  cvt.d.s   $f0, $f0
/* 4EF544 802180A4 46240000 */  add.d     $f0, $f0, $f4
/* 4EF548 802180A8 AE710078 */  sw        $s1, 0x78($s3)
/* 4EF54C 802180AC 46201620 */  cvt.s.d   $f24, $f2
/* 4EF550 802180B0 462005A0 */  cvt.s.d   $f22, $f0
.L802180B4:
/* 4EF554 802180B4 0260202D */  daddu     $a0, $s3, $zero
/* 4EF558 802180B8 02922821 */  addu      $a1, $s4, $s2
/* 4EF55C 802180BC E614001C */  swc1      $f20, 0x1c($s0)
/* 4EF560 802180C0 E6140024 */  swc1      $f20, 0x24($s0)
/* 4EF564 802180C4 E6140020 */  swc1      $f20, 0x20($s0)
/* 4EF568 802180C8 E6380000 */  swc1      $f24, ($s1)
/* 4EF56C 802180CC E616FFFC */  swc1      $f22, -4($s0)
/* 4EF570 802180D0 E61A0000 */  swc1      $f26, ($s0)
/* 4EF574 802180D4 AE000014 */  sw        $zero, 0x14($s0)
/* 4EF578 802180D8 E61E0018 */  swc1      $f30, 0x18($s0)
/* 4EF57C 802180DC E61C000C */  swc1      $f28, 0xc($s0)
/* 4EF580 802180E0 0C099117 */  jal       get_actor_part
/* 4EF584 802180E4 AE000010 */   sw       $zero, 0x10($s0)
/* 4EF588 802180E8 C6200000 */  lwc1      $f0, ($s1)
/* 4EF58C 802180EC 26520001 */  addiu     $s2, $s2, 1
/* 4EF590 802180F0 E440002C */  swc1      $f0, 0x2c($v0)
/* 4EF594 802180F4 C600FFFC */  lwc1      $f0, -4($s0)
/* 4EF598 802180F8 26310030 */  addiu     $s1, $s1, 0x30
/* 4EF59C 802180FC E4400030 */  swc1      $f0, 0x30($v0)
/* 4EF5A0 80218100 C6000000 */  lwc1      $f0, ($s0)
/* 4EF5A4 80218104 E4400034 */  swc1      $f0, 0x34($v0)
/* 4EF5A8 80218108 2A420008 */  slti      $v0, $s2, 8
/* 4EF5AC 8021810C 1440FFE9 */  bnez      $v0, .L802180B4
/* 4EF5B0 80218110 26100030 */   addiu    $s0, $s0, 0x30
/* 4EF5B4 80218114 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4EF5B8 80218118 8FB40020 */  lw        $s4, 0x20($sp)
/* 4EF5BC 8021811C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4EF5C0 80218120 8FB20018 */  lw        $s2, 0x18($sp)
/* 4EF5C4 80218124 8FB10014 */  lw        $s1, 0x14($sp)
/* 4EF5C8 80218128 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF5CC 8021812C D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 4EF5D0 80218130 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 4EF5D4 80218134 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 4EF5D8 80218138 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 4EF5DC 8021813C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 4EF5E0 80218140 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 4EF5E4 80218144 24020002 */  addiu     $v0, $zero, 2
/* 4EF5E8 80218148 03E00008 */  jr        $ra
/* 4EF5EC 8021814C 27BD0058 */   addiu    $sp, $sp, 0x58
/* 4EF5F0 80218150 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EF5F4 80218154 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4EF5F8 80218158 4485B000 */  mtc1      $a1, $f22
/* 4EF5FC 8021815C 3C0140C9 */  lui       $at, 0x40c9
/* 4EF600 80218160 34210FD0 */  ori       $at, $at, 0xfd0
/* 4EF604 80218164 44810000 */  mtc1      $at, $f0
/* 4EF608 80218168 44863000 */  mtc1      $a2, $f6
/* 4EF60C 8021816C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4EF610 80218170 46003502 */  mul.s     $f20, $f6, $f0
/* 4EF614 80218174 00000000 */  nop       
/* 4EF618 80218178 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF61C 8021817C 3C0143B4 */  lui       $at, 0x43b4
/* 4EF620 80218180 44810000 */  mtc1      $at, $f0
/* 4EF624 80218184 0080802D */  daddu     $s0, $a0, $zero
/* 4EF628 80218188 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4EF62C 8021818C 4600A503 */  div.s     $f20, $f20, $f0
/* 4EF630 80218190 0C00A85B */  jal       sin_rad
/* 4EF634 80218194 4600A306 */   mov.s    $f12, $f20
/* 4EF638 80218198 4600A306 */  mov.s     $f12, $f20
/* 4EF63C 8021819C 0C00A874 */  jal       cos_rad
/* 4EF640 802181A0 46000506 */   mov.s    $f20, $f0
/* 4EF644 802181A4 4600B087 */  neg.s     $f2, $f22
/* 4EF648 802181A8 46141082 */  mul.s     $f2, $f2, $f20
/* 4EF64C 802181AC 00000000 */  nop       
/* 4EF650 802181B0 4600B582 */  mul.s     $f22, $f22, $f0
/* 4EF654 802181B4 00000000 */  nop       
/* 4EF658 802181B8 C6040000 */  lwc1      $f4, ($s0)
/* 4EF65C 802181BC 46022100 */  add.s     $f4, $f4, $f2
/* 4EF660 802181C0 C6000004 */  lwc1      $f0, 4($s0)
/* 4EF664 802181C4 46160000 */  add.s     $f0, $f0, $f22
/* 4EF668 802181C8 E6040000 */  swc1      $f4, ($s0)
/* 4EF66C 802181CC E6000004 */  swc1      $f0, 4($s0)
/* 4EF670 802181D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4EF674 802181D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF678 802181D8 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4EF67C 802181DC D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4EF680 802181E0 03E00008 */  jr        $ra
/* 4EF684 802181E4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4EF688 802181E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EF68C 802181EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4EF690 802181F0 4485B000 */  mtc1      $a1, $f22
/* 4EF694 802181F4 3C0140C9 */  lui       $at, 0x40c9
/* 4EF698 802181F8 34210FD0 */  ori       $at, $at, 0xfd0
/* 4EF69C 802181FC 44810000 */  mtc1      $at, $f0
/* 4EF6A0 80218200 44861000 */  mtc1      $a2, $f2
/* 4EF6A4 80218204 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4EF6A8 80218208 46001502 */  mul.s     $f20, $f2, $f0
/* 4EF6AC 8021820C 00000000 */  nop       
/* 4EF6B0 80218210 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF6B4 80218214 3C0143B4 */  lui       $at, 0x43b4
/* 4EF6B8 80218218 44810000 */  mtc1      $at, $f0
/* 4EF6BC 8021821C 0080802D */  daddu     $s0, $a0, $zero
/* 4EF6C0 80218220 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4EF6C4 80218224 4600A503 */  div.s     $f20, $f20, $f0
/* 4EF6C8 80218228 0C00A85B */  jal       sin_rad
/* 4EF6CC 8021822C 4600A306 */   mov.s    $f12, $f20
/* 4EF6D0 80218230 0C00A874 */  jal       cos_rad
/* 4EF6D4 80218234 4600A306 */   mov.s    $f12, $f20
/* 4EF6D8 80218238 4600B582 */  mul.s     $f22, $f22, $f0
/* 4EF6DC 8021823C 00000000 */  nop       
/* 4EF6E0 80218240 E6160000 */  swc1      $f22, ($s0)
/* 4EF6E4 80218244 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4EF6E8 80218248 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF6EC 8021824C D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4EF6F0 80218250 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4EF6F4 80218254 03E00008 */  jr        $ra
/* 4EF6F8 80218258 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4EF6FC 8021825C 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 4EF700 80218260 AFB00020 */  sw        $s0, 0x20($sp)
/* 4EF704 80218264 0080802D */  daddu     $s0, $a0, $zero
/* 4EF708 80218268 AFBF003C */  sw        $ra, 0x3c($sp)
/* 4EF70C 8021826C AFB60038 */  sw        $s6, 0x38($sp)
/* 4EF710 80218270 AFB50034 */  sw        $s5, 0x34($sp)
/* 4EF714 80218274 AFB40030 */  sw        $s4, 0x30($sp)
/* 4EF718 80218278 AFB3002C */  sw        $s3, 0x2c($sp)
/* 4EF71C 8021827C AFB20028 */  sw        $s2, 0x28($sp)
/* 4EF720 80218280 AFB10024 */  sw        $s1, 0x24($sp)
/* 4EF724 80218284 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 4EF728 80218288 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 4EF72C 8021828C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 4EF730 80218290 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 4EF734 80218294 8E040148 */  lw        $a0, 0x148($s0)
/* 4EF738 80218298 0C09A75B */  jal       get_actor
/* 4EF73C 8021829C 8E12000C */   lw       $s2, 0xc($s0)
/* 4EF740 802182A0 0040882D */  daddu     $s1, $v0, $zero
/* 4EF744 802182A4 122000E3 */  beqz      $s1, .L80218634
/* 4EF748 802182A8 0000102D */   daddu    $v0, $zero, $zero
/* 4EF74C 802182AC 8E450000 */  lw        $a1, ($s2)
/* 4EF750 802182B0 0C0B1EAF */  jal       get_variable
/* 4EF754 802182B4 0200202D */   daddu    $a0, $s0, $zero
/* 4EF758 802182B8 0040A82D */  daddu     $s5, $v0, $zero
/* 4EF75C 802182BC 2402000A */  addiu     $v0, $zero, 0xa
/* 4EF760 802182C0 82230210 */  lb        $v1, 0x210($s1)
/* 4EF764 802182C4 8E320078 */  lw        $s2, 0x78($s1)
/* 4EF768 802182C8 1462000D */  bne       $v1, $v0, .L80218300
/* 4EF76C 802182CC 24160003 */   addiu    $s6, $zero, 3
/* 4EF770 802182D0 C6220144 */  lwc1      $f2, 0x144($s1)
/* 4EF774 802182D4 3C014018 */  lui       $at, 0x4018
/* 4EF778 802182D8 44810800 */  mtc1      $at, $f1
/* 4EF77C 802182DC 44800000 */  mtc1      $zero, $f0
/* 4EF780 802182E0 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF784 802182E4 46201080 */  add.d     $f2, $f2, $f0
/* 4EF788 802182E8 C6200148 */  lwc1      $f0, 0x148($s1)
/* 4EF78C 802182EC 3C014004 */  lui       $at, 0x4004
/* 4EF790 802182F0 44812800 */  mtc1      $at, $f5
/* 4EF794 802182F4 44802000 */  mtc1      $zero, $f4
/* 4EF798 802182F8 080860CB */  j         .L8021832C
/* 4EF79C 802182FC 46000021 */   cvt.d.s  $f0, $f0
.L80218300:
/* 4EF7A0 80218300 C6220144 */  lwc1      $f2, 0x144($s1)
/* 4EF7A4 80218304 3C014028 */  lui       $at, 0x4028
/* 4EF7A8 80218308 44810800 */  mtc1      $at, $f1
/* 4EF7AC 8021830C 44800000 */  mtc1      $zero, $f0
/* 4EF7B0 80218310 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF7B4 80218314 46201080 */  add.d     $f2, $f2, $f0
/* 4EF7B8 80218318 C6200148 */  lwc1      $f0, 0x148($s1)
/* 4EF7BC 8021831C 3C014014 */  lui       $at, 0x4014
/* 4EF7C0 80218320 44812800 */  mtc1      $at, $f5
/* 4EF7C4 80218324 44802000 */  mtc1      $zero, $f4
/* 4EF7C8 80218328 46000021 */  cvt.d.s   $f0, $f0
.L8021832C:
/* 4EF7CC 8021832C 46240000 */  add.d     $f0, $f0, $f4
/* 4EF7D0 80218330 46201520 */  cvt.s.d   $f20, $f2
/* 4EF7D4 80218334 462005A0 */  cvt.s.d   $f22, $f0
/* 4EF7D8 80218338 0000982D */  daddu     $s3, $zero, $zero
/* 4EF7DC 8021833C 2414000A */  addiu     $s4, $zero, 0xa
/* 4EF7E0 80218340 26500004 */  addiu     $s0, $s2, 4
/* 4EF7E4 80218344 3C014060 */  lui       $at, 0x4060
/* 4EF7E8 80218348 4481D000 */  mtc1      $at, $f26
/* 4EF7EC 8021834C 3C013F80 */  lui       $at, 0x3f80
/* 4EF7F0 80218350 4481C000 */  mtc1      $at, $f24
.L80218354:
/* 4EF7F4 80218354 82220210 */  lb        $v0, 0x210($s1)
/* 4EF7F8 80218358 14540005 */  bne       $v0, $s4, .L80218370
/* 4EF7FC 8021835C 00000000 */   nop      
/* 4EF800 80218360 E61A0020 */  swc1      $f26, 0x20($s0)
/* 4EF804 80218364 E61A0028 */  swc1      $f26, 0x28($s0)
/* 4EF808 80218368 080860E2 */  j         .L80218388
/* 4EF80C 8021836C E61A0024 */   swc1     $f26, 0x24($s0)
.L80218370:
/* 4EF810 80218370 3C0140E0 */  lui       $at, 0x40e0
/* 4EF814 80218374 44810000 */  mtc1      $at, $f0
/* 4EF818 80218378 00000000 */  nop       
/* 4EF81C 8021837C E6000020 */  swc1      $f0, 0x20($s0)
/* 4EF820 80218380 E6000028 */  swc1      $f0, 0x28($s0)
/* 4EF824 80218384 E6000024 */  swc1      $f0, 0x24($s0)
.L80218388:
/* 4EF828 80218388 C6020014 */  lwc1      $f2, 0x14($s0)
/* 4EF82C 8021838C C6000010 */  lwc1      $f0, 0x10($s0)
/* 4EF830 80218390 46001081 */  sub.s     $f2, $f2, $f0
/* 4EF834 80218394 46000007 */  neg.s     $f0, $f0
/* 4EF838 80218398 46000000 */  add.s     $f0, $f0, $f0
/* 4EF83C 8021839C 4600103C */  c.lt.s    $f2, $f0
/* 4EF840 802183A0 00000000 */  nop       
/* 4EF844 802183A4 4500000D */  bc1f      .L802183DC
/* 4EF848 802183A8 E6020014 */   swc1     $f2, 0x14($s0)
/* 4EF84C 802183AC E6000014 */  swc1      $f0, 0x14($s0)
/* 4EF850 802183B0 8E2200A8 */  lw        $v0, 0xa8($s1)
/* 4EF854 802183B4 10400009 */  beqz      $v0, .L802183DC
/* 4EF858 802183B8 00000000 */   nop      
/* 4EF85C 802183BC 16600007 */  bnez      $s3, .L802183DC
/* 4EF860 802183C0 24042063 */   addiu    $a0, $zero, 0x2063
/* 4EF864 802183C4 C620014C */  lwc1      $f0, 0x14c($s1)
/* 4EF868 802183C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 4EF86C 802183CC 8E260144 */  lw        $a2, 0x144($s1)
/* 4EF870 802183D0 8E270148 */  lw        $a3, 0x148($s1)
/* 4EF874 802183D4 0C052757 */  jal       play_sound_at_position
/* 4EF878 802183D8 0000282D */   daddu    $a1, $zero, $zero
.L802183DC:
/* 4EF87C 802183DC C6000000 */  lwc1      $f0, ($s0)
/* 4EF880 802183E0 C6020014 */  lwc1      $f2, 0x14($s0)
/* 4EF884 802183E4 46020000 */  add.s     $f0, $f0, $f2
/* 4EF888 802183E8 E6000000 */  swc1      $f0, ($s0)
/* 4EF88C 802183EC 82220210 */  lb        $v0, 0x210($s1)
/* 4EF890 802183F0 1454000D */  bne       $v0, $s4, .L80218428
/* 4EF894 802183F4 46000021 */   cvt.d.s  $f0, $f0
/* 4EF898 802183F8 3C014004 */  lui       $at, 0x4004
/* 4EF89C 802183FC 44811800 */  mtc1      $at, $f3
/* 4EF8A0 80218400 44801000 */  mtc1      $zero, $f2
/* 4EF8A4 80218404 00000000 */  nop       
/* 4EF8A8 80218408 4622003C */  c.lt.d    $f0, $f2
/* 4EF8AC 8021840C 00000000 */  nop       
/* 4EF8B0 80218410 45000012 */  bc1f      .L8021845C
/* 4EF8B4 80218414 4600A306 */   mov.s    $f12, $f20
/* 4EF8B8 80218418 3C014020 */  lui       $at, 0x4020
/* 4EF8BC 8021841C 44810000 */  mtc1      $at, $f0
/* 4EF8C0 80218420 08086115 */  j         .L80218454
/* 4EF8C4 80218424 AE000014 */   sw       $zero, 0x14($s0)
.L80218428:
/* 4EF8C8 80218428 3C014014 */  lui       $at, 0x4014
/* 4EF8CC 8021842C 44811800 */  mtc1      $at, $f3
/* 4EF8D0 80218430 44801000 */  mtc1      $zero, $f2
/* 4EF8D4 80218434 00000000 */  nop       
/* 4EF8D8 80218438 4622003C */  c.lt.d    $f0, $f2
/* 4EF8DC 8021843C 00000000 */  nop       
/* 4EF8E0 80218440 45000006 */  bc1f      .L8021845C
/* 4EF8E4 80218444 4600A306 */   mov.s    $f12, $f20
/* 4EF8E8 80218448 3C0140A0 */  lui       $at, 0x40a0
/* 4EF8EC 8021844C 44810000 */  mtc1      $at, $f0
/* 4EF8F0 80218450 AE000014 */  sw        $zero, 0x14($s0)
.L80218454:
/* 4EF8F4 80218454 E6000000 */  swc1      $f0, ($s0)
/* 4EF8F8 80218458 4600A306 */  mov.s     $f12, $f20
.L8021845C:
/* 4EF8FC 8021845C 8E460000 */  lw        $a2, ($s2)
/* 4EF900 80218460 8E070000 */  lw        $a3, ($s0)
/* 4EF904 80218464 0C00A7B5 */  jal       dist2D
/* 4EF908 80218468 4600B386 */   mov.s    $f14, $f22
/* 4EF90C 8021846C 4600A306 */  mov.s     $f12, $f20
/* 4EF910 80218470 4600B386 */  mov.s     $f14, $f22
/* 4EF914 80218474 8E460000 */  lw        $a2, ($s2)
/* 4EF918 80218478 8E070000 */  lw        $a3, ($s0)
/* 4EF91C 8021847C 0C00A720 */  jal       atan2
/* 4EF920 80218480 46000506 */   mov.s    $f20, $f0
/* 4EF924 80218484 C6020028 */  lwc1      $f2, 0x28($s0)
/* 4EF928 80218488 4614103E */  c.le.s    $f2, $f20
/* 4EF92C 8021848C 00000000 */  nop       
/* 4EF930 80218490 45000012 */  bc1f      .L802184DC
/* 4EF934 80218494 46000586 */   mov.s    $f22, $f0
/* 4EF938 80218498 4602A081 */  sub.s     $f2, $f20, $f2
/* 4EF93C 8021849C 4406B000 */  mfc1      $a2, $f22
/* 4EF940 802184A0 44051000 */  mfc1      $a1, $f2
/* 4EF944 802184A4 0C08607A */  jal       func_802181E8_4EF688
/* 4EF948 802184A8 27A40018 */   addiu    $a0, $sp, 0x18
/* 4EF94C 802184AC C7A00018 */  lwc1      $f0, 0x18($sp)
/* 4EF950 802184B0 3C013FE0 */  lui       $at, 0x3fe0
/* 4EF954 802184B4 44811800 */  mtc1      $at, $f3
/* 4EF958 802184B8 44801000 */  mtc1      $zero, $f2
/* 4EF95C 802184BC 46000021 */  cvt.d.s   $f0, $f0
/* 4EF960 802184C0 46220002 */  mul.d     $f0, $f0, $f2
/* 4EF964 802184C4 00000000 */  nop       
/* 4EF968 802184C8 C6020014 */  lwc1      $f2, 0x14($s0)
/* 4EF96C 802184CC 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF970 802184D0 46201080 */  add.d     $f2, $f2, $f0
/* 4EF974 802184D4 462010A0 */  cvt.s.d   $f2, $f2
/* 4EF978 802184D8 E6020014 */  swc1      $f2, 0x14($s0)
.L802184DC:
/* 4EF97C 802184DC C6000024 */  lwc1      $f0, 0x24($s0)
/* 4EF980 802184E0 4614003E */  c.le.s    $f0, $f20
/* 4EF984 802184E4 00000000 */  nop       
/* 4EF988 802184E8 4500000F */  bc1f      .L80218528
/* 4EF98C 802184EC 00000000 */   nop      
/* 4EF990 802184F0 C6000020 */  lwc1      $f0, 0x20($s0)
/* 4EF994 802184F4 4614003E */  c.le.s    $f0, $f20
/* 4EF998 802184F8 00000000 */  nop       
/* 4EF99C 802184FC 45000003 */  bc1f      .L8021850C
/* 4EF9A0 80218500 00000000 */   nop      
/* 4EF9A4 80218504 08086147 */  j         .L8021851C
/* 4EF9A8 80218508 4600A001 */   sub.s    $f0, $f20, $f0
.L8021850C:
/* 4EF9AC 8021850C C6000018 */  lwc1      $f0, 0x18($s0)
/* 4EF9B0 80218510 C602001C */  lwc1      $f2, 0x1c($s0)
/* 4EF9B4 80218514 46020000 */  add.s     $f0, $f0, $f2
/* 4EF9B8 80218518 E6000018 */  swc1      $f0, 0x18($s0)
.L8021851C:
/* 4EF9BC 8021851C 44050000 */  mfc1      $a1, $f0
/* 4EF9C0 80218520 0808615D */  j         .L80218574
/* 4EF9C4 80218524 00000000 */   nop      
.L80218528:
/* 4EF9C8 80218528 C602001C */  lwc1      $f2, 0x1c($s0)
/* 4EF9CC 8021852C 3C018022 */  lui       $at, %hi(D_802204E0)
/* 4EF9D0 80218530 D42004E0 */  ldc1      $f0, %lo(D_802204E0)($at)
/* 4EF9D4 80218534 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF9D8 80218538 46201082 */  mul.d     $f2, $f2, $f0
/* 4EF9DC 8021853C 00000000 */  nop       
/* 4EF9E0 80218540 C6000018 */  lwc1      $f0, 0x18($s0)
/* 4EF9E4 80218544 46000021 */  cvt.d.s   $f0, $f0
/* 4EF9E8 80218548 46220001 */  sub.d     $f0, $f0, $f2
/* 4EF9EC 8021854C 44802000 */  mtc1      $zero, $f4
/* 4EF9F0 80218550 44802800 */  mtc1      $zero, $f5
/* 4EF9F4 80218554 46200020 */  cvt.s.d   $f0, $f0
/* 4EF9F8 80218558 460000A1 */  cvt.d.s   $f2, $f0
/* 4EF9FC 8021855C 4624103C */  c.lt.d    $f2, $f4
/* 4EFA00 80218560 00000000 */  nop       
/* 4EFA04 80218564 45000002 */  bc1f      .L80218570
/* 4EFA08 80218568 E6000018 */   swc1     $f0, 0x18($s0)
/* 4EFA0C 8021856C AE000018 */  sw        $zero, 0x18($s0)
.L80218570:
/* 4EFA10 80218570 8E050018 */  lw        $a1, 0x18($s0)
.L80218574:
/* 4EFA14 80218574 4406B000 */  mfc1      $a2, $f22
/* 4EFA18 80218578 0C086054 */  jal       func_80218150_4EF5F0
/* 4EFA1C 8021857C 0240202D */   daddu    $a0, $s2, $zero
/* 4EFA20 80218580 C6000018 */  lwc1      $f0, 0x18($s0)
/* 4EFA24 80218584 3C014010 */  lui       $at, 0x4010
/* 4EFA28 80218588 44811800 */  mtc1      $at, $f3
/* 4EFA2C 8021858C 44801000 */  mtc1      $zero, $f2
/* 4EFA30 80218590 46000021 */  cvt.d.s   $f0, $f0
/* 4EFA34 80218594 4620103C */  c.lt.d    $f2, $f0
/* 4EFA38 80218598 00000000 */  nop       
/* 4EFA3C 8021859C 45000005 */  bc1f      .L802185B4
/* 4EFA40 802185A0 0220202D */   daddu    $a0, $s1, $zero
/* 4EFA44 802185A4 3C014080 */  lui       $at, 0x4080
/* 4EFA48 802185A8 44810000 */  mtc1      $at, $f0
/* 4EFA4C 802185AC 00000000 */  nop       
/* 4EFA50 802185B0 E6000018 */  swc1      $f0, 0x18($s0)
.L802185B4:
/* 4EFA54 802185B4 02D32821 */  addu      $a1, $s6, $s3
/* 4EFA58 802185B8 44950000 */  mtc1      $s5, $f0
/* 4EFA5C 802185BC 00000000 */  nop       
/* 4EFA60 802185C0 46800020 */  cvt.s.w   $f0, $f0
/* 4EFA64 802185C4 0C099117 */  jal       get_actor_part
/* 4EFA68 802185C8 E6000004 */   swc1     $f0, 4($s0)
/* 4EFA6C 802185CC C6400000 */  lwc1      $f0, ($s2)
/* 4EFA70 802185D0 0040182D */  daddu     $v1, $v0, $zero
/* 4EFA74 802185D4 E460002C */  swc1      $f0, 0x2c($v1)
/* 4EFA78 802185D8 C6000000 */  lwc1      $f0, ($s0)
/* 4EFA7C 802185DC E4600030 */  swc1      $f0, 0x30($v1)
/* 4EFA80 802185E0 C6000004 */  lwc1      $f0, 4($s0)
/* 4EFA84 802185E4 E4600034 */  swc1      $f0, 0x34($v1)
/* 4EFA88 802185E8 82220210 */  lb        $v0, 0x210($s1)
/* 4EFA8C 802185EC 54540007 */  bnel      $v0, $s4, .L8021860C
/* 4EFA90 802185F0 E478004C */   swc1     $f24, 0x4c($v1)
/* 4EFA94 802185F4 3C013F00 */  lui       $at, 0x3f00
/* 4EFA98 802185F8 44810000 */  mtc1      $at, $f0
/* 4EFA9C 802185FC E4780054 */  swc1      $f24, 0x54($v1)
/* 4EFAA0 80218600 E460004C */  swc1      $f0, 0x4c($v1)
/* 4EFAA4 80218604 08086185 */  j         .L80218614
/* 4EFAA8 80218608 E4600050 */   swc1     $f0, 0x50($v1)
.L8021860C:
/* 4EFAAC 8021860C E4780050 */  swc1      $f24, 0x50($v1)
/* 4EFAB0 80218610 E4780054 */  swc1      $f24, 0x54($v1)
.L80218614:
/* 4EFAB4 80218614 26730001 */  addiu     $s3, $s3, 1
/* 4EFAB8 80218618 C6160000 */  lwc1      $f22, ($s0)
/* 4EFABC 8021861C 26100030 */  addiu     $s0, $s0, 0x30
/* 4EFAC0 80218620 C6540000 */  lwc1      $f20, ($s2)
/* 4EFAC4 80218624 2A620008 */  slti      $v0, $s3, 8
/* 4EFAC8 80218628 1440FF4A */  bnez      $v0, .L80218354
/* 4EFACC 8021862C 26520030 */   addiu    $s2, $s2, 0x30
/* 4EFAD0 80218630 24020002 */  addiu     $v0, $zero, 2
.L80218634:
/* 4EFAD4 80218634 8FBF003C */  lw        $ra, 0x3c($sp)
/* 4EFAD8 80218638 8FB60038 */  lw        $s6, 0x38($sp)
/* 4EFADC 8021863C 8FB50034 */  lw        $s5, 0x34($sp)
/* 4EFAE0 80218640 8FB40030 */  lw        $s4, 0x30($sp)
/* 4EFAE4 80218644 8FB3002C */  lw        $s3, 0x2c($sp)
/* 4EFAE8 80218648 8FB20028 */  lw        $s2, 0x28($sp)
/* 4EFAEC 8021864C 8FB10024 */  lw        $s1, 0x24($sp)
/* 4EFAF0 80218650 8FB00020 */  lw        $s0, 0x20($sp)
/* 4EFAF4 80218654 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 4EFAF8 80218658 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 4EFAFC 8021865C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 4EFB00 80218660 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 4EFB04 80218664 03E00008 */  jr        $ra
/* 4EFB08 80218668 27BD0060 */   addiu    $sp, $sp, 0x60
/* 4EFB0C 8021866C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFB10 80218670 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFB14 80218674 8C82000C */  lw        $v0, 0xc($a0)
/* 4EFB18 80218678 0C0B1EAF */  jal       get_variable
/* 4EFB1C 8021867C 8C450004 */   lw       $a1, 4($v0)
/* 4EFB20 80218680 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFB24 80218684 24020002 */  addiu     $v0, $zero, 2
/* 4EFB28 80218688 03E00008 */  jr        $ra
/* 4EFB2C 8021868C 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFB30 80218690 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EFB34 80218694 AFB10014 */  sw        $s1, 0x14($sp)
/* 4EFB38 80218698 0080882D */  daddu     $s1, $a0, $zero
/* 4EFB3C 8021869C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4EFB40 802186A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4EFB44 802186A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 4EFB48 802186A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EFB4C 802186AC 8E30000C */  lw        $s0, 0xc($s1)
/* 4EFB50 802186B0 8E050000 */  lw        $a1, ($s0)
/* 4EFB54 802186B4 0C0B1EAF */  jal       get_variable
/* 4EFB58 802186B8 26100004 */   addiu    $s0, $s0, 4
/* 4EFB5C 802186BC 8E050000 */  lw        $a1, ($s0)
/* 4EFB60 802186C0 26100004 */  addiu     $s0, $s0, 4
/* 4EFB64 802186C4 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB68 802186C8 0C0B1EAF */  jal       get_variable
/* 4EFB6C 802186CC 0040982D */   daddu    $s3, $v0, $zero
/* 4EFB70 802186D0 8E050000 */  lw        $a1, ($s0)
/* 4EFB74 802186D4 26100004 */  addiu     $s0, $s0, 4
/* 4EFB78 802186D8 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB7C 802186DC 0C0B1EAF */  jal       get_variable
/* 4EFB80 802186E0 0040902D */   daddu    $s2, $v0, $zero
/* 4EFB84 802186E4 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB88 802186E8 8E050000 */  lw        $a1, ($s0)
/* 4EFB8C 802186EC 0C0B1EAF */  jal       get_variable
/* 4EFB90 802186F0 0040802D */   daddu    $s0, $v0, $zero
/* 4EFB94 802186F4 8E240148 */  lw        $a0, 0x148($s1)
/* 4EFB98 802186F8 0C09A75B */  jal       get_actor
/* 4EFB9C 802186FC 0040882D */   daddu    $s1, $v0, $zero
/* 4EFBA0 80218700 0040182D */  daddu     $v1, $v0, $zero
/* 4EFBA4 80218704 8C620008 */  lw        $v0, 8($v1)
/* 4EFBA8 80218708 90420024 */  lbu       $v0, 0x24($v0)
/* 4EFBAC 8021870C 8C640008 */  lw        $a0, 8($v1)
/* 4EFBB0 80218710 02629823 */  subu      $s3, $s3, $v0
/* 4EFBB4 80218714 A0730194 */  sb        $s3, 0x194($v1)
/* 4EFBB8 80218718 90820025 */  lbu       $v0, 0x25($a0)
/* 4EFBBC 8021871C 02429023 */  subu      $s2, $s2, $v0
/* 4EFBC0 80218720 A0720195 */  sb        $s2, 0x195($v1)
/* 4EFBC4 80218724 90820026 */  lbu       $v0, 0x26($a0)
/* 4EFBC8 80218728 02028023 */  subu      $s0, $s0, $v0
/* 4EFBCC 8021872C A0700196 */  sb        $s0, 0x196($v1)
/* 4EFBD0 80218730 90840027 */  lbu       $a0, 0x27($a0)
/* 4EFBD4 80218734 02248823 */  subu      $s1, $s1, $a0
/* 4EFBD8 80218738 A0710197 */  sb        $s1, 0x197($v1)
/* 4EFBDC 8021873C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4EFBE0 80218740 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4EFBE4 80218744 8FB20018 */  lw        $s2, 0x18($sp)
/* 4EFBE8 80218748 8FB10014 */  lw        $s1, 0x14($sp)
/* 4EFBEC 8021874C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EFBF0 80218750 24020002 */  addiu     $v0, $zero, 2
/* 4EFBF4 80218754 03E00008 */  jr        $ra
/* 4EFBF8 80218758 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4EFBFC 8021875C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFC00 80218760 AFB1002C */  sw        $s1, 0x2c($sp)
/* 4EFC04 80218764 0080882D */  daddu     $s1, $a0, $zero
/* 4EFC08 80218768 AFBF0034 */  sw        $ra, 0x34($sp)
/* 4EFC0C 8021876C AFB20030 */  sw        $s2, 0x30($sp)
/* 4EFC10 80218770 AFB00028 */  sw        $s0, 0x28($sp)
/* 4EFC14 80218774 8E30000C */  lw        $s0, 0xc($s1)
/* 4EFC18 80218778 8E050000 */  lw        $a1, ($s0)
/* 4EFC1C 8021877C 0C0B1EAF */  jal       get_variable
/* 4EFC20 80218780 26100004 */   addiu    $s0, $s0, 4
/* 4EFC24 80218784 8E050000 */  lw        $a1, ($s0)
/* 4EFC28 80218788 26100004 */  addiu     $s0, $s0, 4
/* 4EFC2C 8021878C 0220202D */  daddu     $a0, $s1, $zero
/* 4EFC30 80218790 0C0B1EAF */  jal       get_variable
/* 4EFC34 80218794 0040902D */   daddu    $s2, $v0, $zero
/* 4EFC38 80218798 0220202D */  daddu     $a0, $s1, $zero
/* 4EFC3C 8021879C 8E050000 */  lw        $a1, ($s0)
/* 4EFC40 802187A0 0C0B1EAF */  jal       get_variable
/* 4EFC44 802187A4 0040802D */   daddu    $s0, $v0, $zero
/* 4EFC48 802187A8 24040002 */  addiu     $a0, $zero, 2
/* 4EFC4C 802187AC 44923000 */  mtc1      $s2, $f6
/* 4EFC50 802187B0 00000000 */  nop       
/* 4EFC54 802187B4 468031A0 */  cvt.s.w   $f6, $f6
/* 4EFC58 802187B8 44900000 */  mtc1      $s0, $f0
/* 4EFC5C 802187BC 00000000 */  nop       
/* 4EFC60 802187C0 46800020 */  cvt.s.w   $f0, $f0
/* 4EFC64 802187C4 44053000 */  mfc1      $a1, $f6
/* 4EFC68 802187C8 44823000 */  mtc1      $v0, $f6
/* 4EFC6C 802187CC 00000000 */  nop       
/* 4EFC70 802187D0 468031A0 */  cvt.s.w   $f6, $f6
/* 4EFC74 802187D4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 4EFC78 802187D8 3C01BF00 */  lui       $at, 0xbf00
/* 4EFC7C 802187DC 44810000 */  mtc1      $at, $f0
/* 4EFC80 802187E0 3C01BF66 */  lui       $at, 0xbf66
/* 4EFC84 802187E4 34216666 */  ori       $at, $at, 0x6666
/* 4EFC88 802187E8 44811000 */  mtc1      $at, $f2
/* 4EFC8C 802187EC 3C013F00 */  lui       $at, 0x3f00
/* 4EFC90 802187F0 44812000 */  mtc1      $at, $f4
/* 4EFC94 802187F4 3C064316 */  lui       $a2, 0x4316
/* 4EFC98 802187F8 44073000 */  mfc1      $a3, $f6
/* 4EFC9C 802187FC 2403003C */  addiu     $v1, $zero, 0x3c
/* 4EFCA0 80218800 AFA30020 */  sw        $v1, 0x20($sp)
/* 4EFCA4 80218804 E7A00014 */  swc1      $f0, 0x14($sp)
/* 4EFCA8 80218808 E7A20018 */  swc1      $f2, 0x18($sp)
/* 4EFCAC 8021880C 0C01C544 */  jal       func_80071510
/* 4EFCB0 80218810 E7A4001C */   swc1     $f4, 0x1c($sp)
/* 4EFCB4 80218814 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCB8 80218818 AC600030 */  sw        $zero, 0x30($v1)
/* 4EFCBC 8021881C 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCC0 80218820 AC600038 */  sw        $zero, 0x38($v1)
/* 4EFCC4 80218824 8C43000C */  lw        $v1, 0xc($v0)
/* 4EFCC8 80218828 AC600034 */  sw        $zero, 0x34($v1)
/* 4EFCCC 8021882C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 4EFCD0 80218830 8FB20030 */  lw        $s2, 0x30($sp)
/* 4EFCD4 80218834 8FB1002C */  lw        $s1, 0x2c($sp)
/* 4EFCD8 80218838 8FB00028 */  lw        $s0, 0x28($sp)
/* 4EFCDC 8021883C 24020002 */  addiu     $v0, $zero, 2
/* 4EFCE0 80218840 03E00008 */  jr        $ra
/* 4EFCE4 80218844 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4EFCE8 80218848 00000000 */  nop       
/* 4EFCEC 8021884C 00000000 */  nop       
/* 4EFCF0 80218850 3C05C305 */  lui       $a1, 0xc305
/* 4EFCF4 80218854 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFCF8 80218858 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4EFCFC 8021885C 3C014290 */  lui       $at, 0x4290
/* 4EFD00 80218860 4481B000 */  mtc1      $at, $f22
/* 4EFD04 80218864 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4EFD08 80218868 3C01C30F */  lui       $at, 0xc30f
/* 4EFD0C 8021886C 4481C000 */  mtc1      $at, $f24
/* 4EFD10 80218870 24040001 */  addiu     $a0, $zero, 1
/* 4EFD14 80218874 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4EFD18 80218878 3C013E99 */  lui       $at, 0x3e99
/* 4EFD1C 8021887C 3421999A */  ori       $at, $at, 0x999a
/* 4EFD20 80218880 4481A000 */  mtc1      $at, $f20
/* 4EFD24 80218884 4406B000 */  mfc1      $a2, $f22
/* 4EFD28 80218888 4407C000 */  mfc1      $a3, $f24
/* 4EFD2C 8021888C 3C028022 */  lui       $v0, %hi(D_80220740)
/* 4EFD30 80218890 24420740 */  addiu     $v0, $v0, %lo(D_80220740)
/* 4EFD34 80218894 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFD38 80218898 AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFD3C 8021889C 0C01C124 */  jal       func_80070490
/* 4EFD40 802188A0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 4EFD44 802188A4 24040001 */  addiu     $a0, $zero, 1
/* 4EFD48 802188A8 3C054301 */  lui       $a1, 0x4301
/* 4EFD4C 802188AC 4406B000 */  mfc1      $a2, $f22
/* 4EFD50 802188B0 4407C000 */  mfc1      $a3, $f24
/* 4EFD54 802188B4 3C028022 */  lui       $v0, %hi(D_80220744)
/* 4EFD58 802188B8 24420744 */  addiu     $v0, $v0, %lo(D_80220744)
/* 4EFD5C 802188BC E7B40010 */  swc1      $f20, 0x10($sp)
/* 4EFD60 802188C0 0C01C124 */  jal       func_80070490
/* 4EFD64 802188C4 AFA20014 */   sw       $v0, 0x14($sp)
/* 4EFD68 802188C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFD6C 802188CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4EFD70 802188D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4EFD74 802188D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4EFD78 802188D8 24020002 */  addiu     $v0, $zero, 2
/* 4EFD7C 802188DC 03E00008 */  jr        $ra
/* 4EFD80 802188E0 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4EFD84 802188E4 3C048022 */  lui       $a0, %hi(D_80220740)
/* 4EFD88 802188E8 8C840740 */  lw        $a0, %lo(D_80220740)($a0)
/* 4EFD8C 802188EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFD90 802188F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFD94 802188F4 0C016914 */  jal       remove_effect
/* 4EFD98 802188F8 00000000 */   nop      
/* 4EFD9C 802188FC 3C048022 */  lui       $a0, %hi(D_80220744)
/* 4EFDA0 80218900 8C840744 */  lw        $a0, %lo(D_80220744)($a0)
/* 4EFDA4 80218904 0C016914 */  jal       remove_effect
/* 4EFDA8 80218908 00000000 */   nop      
/* 4EFDAC 8021890C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFDB0 80218910 24020002 */  addiu     $v0, $zero, 2
/* 4EFDB4 80218914 03E00008 */  jr        $ra
/* 4EFDB8 80218918 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFDBC 8021891C 00000000 */  nop       
/* 4EFDC0 80218920 3C05C2B4 */  lui       $a1, 0xc2b4
/* 4EFDC4 80218924 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFDC8 80218928 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4EFDCC 8021892C 3C014234 */  lui       $at, 0x4234
/* 4EFDD0 80218930 4481B000 */  mtc1      $at, $f22
/* 4EFDD4 80218934 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4EFDD8 80218938 3C01C312 */  lui       $at, 0xc312
/* 4EFDDC 8021893C 4481C000 */  mtc1      $at, $f24
/* 4EFDE0 80218940 24040001 */  addiu     $a0, $zero, 1
/* 4EFDE4 80218944 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4EFDE8 80218948 3C013E80 */  lui       $at, 0x3e80
/* 4EFDEC 8021894C 4481A000 */  mtc1      $at, $f20
/* 4EFDF0 80218950 4406B000 */  mfc1      $a2, $f22
/* 4EFDF4 80218954 4407C000 */  mfc1      $a3, $f24
/* 4EFDF8 80218958 3C028022 */  lui       $v0, %hi(D_80220750)
/* 4EFDFC 8021895C 24420750 */  addiu     $v0, $v0, %lo(D_80220750)
/* 4EFE00 80218960 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFE04 80218964 AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFE08 80218968 0C01C124 */  jal       func_80070490
/* 4EFE0C 8021896C E7B40010 */   swc1     $f20, 0x10($sp)
/* 4EFE10 80218970 24040001 */  addiu     $a0, $zero, 1
/* 4EFE14 80218974 3C0542A0 */  lui       $a1, 0x42a0
/* 4EFE18 80218978 4406B000 */  mfc1      $a2, $f22
/* 4EFE1C 8021897C 4407C000 */  mfc1      $a3, $f24
/* 4EFE20 80218980 3C028022 */  lui       $v0, %hi(D_80220754)
/* 4EFE24 80218984 24420754 */  addiu     $v0, $v0, %lo(D_80220754)
/* 4EFE28 80218988 E7B40010 */  swc1      $f20, 0x10($sp)
/* 4EFE2C 8021898C 0C01C124 */  jal       func_80070490
/* 4EFE30 80218990 AFA20014 */   sw       $v0, 0x14($sp)
/* 4EFE34 80218994 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFE38 80218998 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4EFE3C 8021899C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4EFE40 802189A0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4EFE44 802189A4 24020002 */  addiu     $v0, $zero, 2
/* 4EFE48 802189A8 03E00008 */  jr        $ra
/* 4EFE4C 802189AC 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4EFE50 802189B0 3C048022 */  lui       $a0, %hi(D_80220750)
/* 4EFE54 802189B4 8C840750 */  lw        $a0, %lo(D_80220750)($a0)
/* 4EFE58 802189B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFE5C 802189BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFE60 802189C0 0C016914 */  jal       remove_effect
/* 4EFE64 802189C4 00000000 */   nop      
/* 4EFE68 802189C8 3C048022 */  lui       $a0, %hi(D_80220754)
/* 4EFE6C 802189CC 8C840754 */  lw        $a0, %lo(D_80220754)($a0)
/* 4EFE70 802189D0 0C016914 */  jal       remove_effect
/* 4EFE74 802189D4 00000000 */   nop      
/* 4EFE78 802189D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFE7C 802189DC 24020002 */  addiu     $v0, $zero, 2
/* 4EFE80 802189E0 03E00008 */  jr        $ra
/* 4EFE84 802189E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFE88 802189E8 00000000 */  nop       
/* 4EFE8C 802189EC 00000000 */  nop       
/* 4EFE90 802189F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFE94 802189F4 3C028022 */  lui       $v0, %hi(D_80220760)
/* 4EFE98 802189F8 24420760 */  addiu     $v0, $v0, %lo(D_80220760)
/* 4EFE9C 802189FC 3C013E99 */  lui       $at, 0x3e99
/* 4EFEA0 80218A00 3421999A */  ori       $at, $at, 0x999a
/* 4EFEA4 80218A04 44810000 */  mtc1      $at, $f0
/* 4EFEA8 80218A08 3C05C2DC */  lui       $a1, 0xc2dc
/* 4EFEAC 80218A0C 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFEB0 80218A10 3C07C312 */  lui       $a3, 0xc312
/* 4EFEB4 80218A14 24040001 */  addiu     $a0, $zero, 1
/* 4EFEB8 80218A18 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFEBC 80218A1C AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFEC0 80218A20 0C01C124 */  jal       func_80070490
/* 4EFEC4 80218A24 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFEC8 80218A28 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFECC 80218A2C 24020002 */  addiu     $v0, $zero, 2
/* 4EFED0 80218A30 03E00008 */  jr        $ra
/* 4EFED4 80218A34 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4EFED8 80218A38 3C048022 */  lui       $a0, %hi(D_80220760)
/* 4EFEDC 80218A3C 8C840760 */  lw        $a0, %lo(D_80220760)($a0)
/* 4EFEE0 80218A40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFEE4 80218A44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFEE8 80218A48 0C016914 */  jal       remove_effect
/* 4EFEEC 80218A4C 00000000 */   nop      
/* 4EFEF0 80218A50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFEF4 80218A54 24020002 */  addiu     $v0, $zero, 2
/* 4EFEF8 80218A58 03E00008 */  jr        $ra
/* 4EFEFC 80218A5C 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFF00 80218A60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFF04 80218A64 3C028022 */  lui       $v0, %hi(D_80220770)
/* 4EFF08 80218A68 24420770 */  addiu     $v0, $v0, %lo(D_80220770)
/* 4EFF0C 80218A6C 3C013E99 */  lui       $at, 0x3e99
/* 4EFF10 80218A70 3421999A */  ori       $at, $at, 0x999a
/* 4EFF14 80218A74 44810000 */  mtc1      $at, $f0
/* 4EFF18 80218A78 3C05C2DC */  lui       $a1, 0xc2dc
/* 4EFF1C 80218A7C 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFF20 80218A80 3C07C312 */  lui       $a3, 0xc312
/* 4EFF24 80218A84 24040001 */  addiu     $a0, $zero, 1
/* 4EFF28 80218A88 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFF2C 80218A8C AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFF30 80218A90 0C01C124 */  jal       func_80070490
/* 4EFF34 80218A94 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFF38 80218A98 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFF3C 80218A9C 24020002 */  addiu     $v0, $zero, 2
/* 4EFF40 80218AA0 03E00008 */  jr        $ra
/* 4EFF44 80218AA4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4EFF48 80218AA8 3C048022 */  lui       $a0, %hi(D_80220770)
/* 4EFF4C 80218AAC 8C840770 */  lw        $a0, %lo(D_80220770)($a0)
/* 4EFF50 80218AB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFF54 80218AB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFF58 80218AB8 0C016914 */  jal       remove_effect
/* 4EFF5C 80218ABC 00000000 */   nop      
/* 4EFF60 80218AC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFF64 80218AC4 24020002 */  addiu     $v0, $zero, 2
/* 4EFF68 80218AC8 03E00008 */  jr        $ra
/* 4EFF6C 80218ACC 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFF70 80218AD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4EFF74 80218AD4 3C028022 */  lui       $v0, %hi(D_80220780)
/* 4EFF78 80218AD8 24420780 */  addiu     $v0, $v0, %lo(D_80220780)
/* 4EFF7C 80218ADC 3C013E99 */  lui       $at, 0x3e99
/* 4EFF80 80218AE0 3421999A */  ori       $at, $at, 0x999a
/* 4EFF84 80218AE4 44810000 */  mtc1      $at, $f0
/* 4EFF88 80218AE8 3C0542DC */  lui       $a1, 0x42dc
/* 4EFF8C 80218AEC 3C0642A0 */  lui       $a2, 0x42a0
/* 4EFF90 80218AF0 3C07C312 */  lui       $a3, 0xc312
/* 4EFF94 80218AF4 24040001 */  addiu     $a0, $zero, 1
/* 4EFF98 80218AF8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFF9C 80218AFC AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFFA0 80218B00 0C01C124 */  jal       func_80070490
/* 4EFFA4 80218B04 E7A00010 */   swc1     $f0, 0x10($sp)
/* 4EFFA8 80218B08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFFAC 80218B0C 24020002 */  addiu     $v0, $zero, 2
/* 4EFFB0 80218B10 03E00008 */  jr        $ra
/* 4EFFB4 80218B14 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4EFFB8 80218B18 3C048022 */  lui       $a0, %hi(D_80220780)
/* 4EFFBC 80218B1C 8C840780 */  lw        $a0, %lo(D_80220780)($a0)
/* 4EFFC0 80218B20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFFC4 80218B24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFFC8 80218B28 0C016914 */  jal       remove_effect
/* 4EFFCC 80218B2C 00000000 */   nop      
/* 4EFFD0 80218B30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFFD4 80218B34 24020002 */  addiu     $v0, $zero, 2
/* 4EFFD8 80218B38 03E00008 */  jr        $ra
/* 4EFFDC 80218B3C 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFFE0 80218B40 00000001 */  movf      $zero, $zero, $fcc0
/* 4EFFE4 80218B44 00690001 */  movt      $zero, $v1, $fcc2
/* 4EFFE8 80218B48 0000000C */  syscall   
/* 4EFFEC 80218B4C 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4EFFF0 80218B50 00000006 */  srlv      $zero, $zero, $zero
/* 4EFFF4 80218B54 00690007 */  srav      $zero, $t1, $v1
/* 4EFFF8 80218B58 00000009 */  jr        $zero
/* 4EFFFC 80218B5C 00690001 */   movt     $zero, $v1, $fcc2
/* 4F0000 80218B60 00000008 */  jr        $zero
/* 4F0004 80218B64 00690000 */   .byte    0x00, 0x69, 0x00, 0x00
/* 4F0008 80218B68 0000000B */  movn      $zero, $zero, $zero
/* 4F000C 80218B6C 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0010 80218B70 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0014 80218B74 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0018 80218B78 00000004 */  sllv      $zero, $zero, $zero
/* 4F001C 80218B7C 00690008 */  .byte     0x00, 0x69, 0x00, 0x08
/* 4F0020 80218B80 00000000 */  nop       
/* 4F0024 80218B84 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0028 80218B88 00690003 */  .byte     0x00, 0x69, 0x00, 0x03
/* 4F002C 80218B8C 00000009 */  jr        $zero
/* 4F0030 80218B90 00690003 */   .byte    0x00, 0x69, 0x00, 0x03
/* 4F0034 80218B94 00000008 */  jr        $zero
/* 4F0038 80218B98 00690000 */   .byte    0x00, 0x69, 0x00, 0x00
/* 4F003C 80218B9C 0000000C */  syscall   
/* 4F0040 80218BA0 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0044 80218BA4 00000006 */  srlv      $zero, $zero, $zero
/* 4F0048 80218BA8 00690007 */  srav      $zero, $t1, $v1
/* 4F004C 80218BAC 0000000B */  movn      $zero, $zero, $zero
/* 4F0050 80218BB0 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0054 80218BB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0058 80218BB8 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F005C 80218BBC 00000004 */  sllv      $zero, $zero, $zero
/* 4F0060 80218BC0 00690008 */  .byte     0x00, 0x69, 0x00, 0x08
/* 4F0064 80218BC4 00000000 */  nop       
/* 4F0068 80218BC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F006C 80218BCC 00690004 */  sllv      $zero, $t1, $v1
/* 4F0070 80218BD0 00000009 */  jr        $zero
/* 4F0074 80218BD4 00690004 */   sllv     $zero, $t1, $v1
/* 4F0078 80218BD8 00000008 */  jr        $zero
/* 4F007C 80218BDC 00690000 */   .byte    0x00, 0x69, 0x00, 0x00
/* 4F0080 80218BE0 0000000C */  syscall   
/* 4F0084 80218BE4 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0088 80218BE8 00000006 */  srlv      $zero, $zero, $zero
/* 4F008C 80218BEC 00690007 */  srav      $zero, $t1, $v1
/* 4F0090 80218BF0 0000000B */  movn      $zero, $zero, $zero
/* 4F0094 80218BF4 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F0098 80218BF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F009C 80218BFC 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F00A0 80218C00 00000004 */  sllv      $zero, $zero, $zero
/* 4F00A4 80218C04 00690008 */  .byte     0x00, 0x69, 0x00, 0x08
/* 4F00A8 80218C08 00000000 */  nop       
/* 4F00AC 80218C0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F00B0 80218C10 00690005 */  lsa       $zero, $v1, $t1, 1
/* 4F00B4 80218C14 00000009 */  jr        $zero
/* 4F00B8 80218C18 00690005 */   lsa      $zero, $v1, $t1, 1
/* 4F00BC 80218C1C 00000008 */  jr        $zero
/* 4F00C0 80218C20 00690000 */   .byte    0x00, 0x69, 0x00, 0x00
/* 4F00C4 80218C24 0000000C */  syscall   
/* 4F00C8 80218C28 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F00CC 80218C2C 00000006 */  srlv      $zero, $zero, $zero
/* 4F00D0 80218C30 00690007 */  srav      $zero, $t1, $v1
/* 4F00D4 80218C34 0000000B */  movn      $zero, $zero, $zero
/* 4F00D8 80218C38 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F00DC 80218C3C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F00E0 80218C40 00690000 */  .byte     0x00, 0x69, 0x00, 0x00
/* 4F00E4 80218C44 00000004 */  sllv      $zero, $zero, $zero
/* 4F00E8 80218C48 00690008 */  .byte     0x00, 0x69, 0x00, 0x08
/* 4F00EC 80218C4C 00000000 */  nop       
/* 4F00F0 80218C50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F00F4 80218C54 00690002 */  .byte     0x00, 0x69, 0x00, 0x02
/* 4F00F8 80218C58 00000000 */  nop       
/* 4F00FC 80218C5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0100 80218C60 00000003 */  sra       $zero, $zero, 0
/* 4F0104 80218C64 0000000C */  syscall   
/* 4F0108 80218C68 00000003 */  sra       $zero, $zero, 0
/* 4F010C 80218C6C 00000002 */  srl       $zero, $zero, 0
/* 4F0110 80218C70 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 4F0114 80218C74 00000004 */  sllv      $zero, $zero, $zero
/* 4F0118 80218C78 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 4F011C 80218C7C 00000007 */  srav      $zero, $zero, $zero
/* 4F0120 80218C80 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 4F0124 80218C84 00000000 */  nop       
/* 4F0128 80218C88 00000001 */  movf      $zero, $zero, $fcc0
/* 4F012C 80218C8C 00000000 */  nop       
/* 4F0130 80218C90 00000002 */  srl       $zero, $zero, 0
/* 4F0134 80218C94 00000000 */  nop       
/* 4F0138 80218C98 00000006 */  srlv      $zero, $zero, $zero
/* 4F013C 80218C9C 00000000 */  nop       
/* 4F0140 80218CA0 00000009 */  jr        $zero
/* 4F0144 80218CA4 00000000 */   nop      
/* 4F0148 80218CA8 00000007 */  srav      $zero, $zero, $zero
/* 4F014C 80218CAC 00000000 */  nop       
/* 4F0150 80218CB0 00000004 */  sllv      $zero, $zero, $zero
/* 4F0154 80218CB4 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 4F0158 80218CB8 00000003 */  sra       $zero, $zero, 0
/* 4F015C 80218CBC 00000000 */  nop       
/* 4F0160 80218CC0 0000000B */  movn      $zero, $zero, $zero
/* 4F0164 80218CC4 00000000 */  nop       
/* 4F0168 80218CC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F016C 80218CCC 00000000 */  nop       
/* 4F0170 80218CD0 0000000A */  movz      $zero, $zero, $zero
/* 4F0174 80218CD4 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 4F0178 80218CD8 00000008 */  jr        $zero
/* 4F017C 80218CDC 0000004B */   .byte    0x00, 0x00, 0x00, 0x4b
/* 4F0180 80218CE0 0000001F */  ddivu     $zero, $zero, $zero
/* 4F0184 80218CE4 00000000 */  nop       
/* 4F0188 80218CE8 00000020 */  add       $zero, $zero, $zero
/* 4F018C 80218CEC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F0190 80218CF0 00000025 */  or        $zero, $zero, $zero
/* 4F0194 80218CF4 00000000 */  nop       
/* 4F0198 80218CF8 00000022 */  neg       $zero, $zero
/* 4F019C 80218CFC 00000000 */  nop       
/* 4F01A0 80218D00 00000024 */  and       $zero, $zero, $zero
/* 4F01A4 80218D04 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F01A8 80218D08 00000023 */  negu      $zero, $zero
/* 4F01AC 80218D0C 00000000 */  nop       
/* 4F01B0 80218D10 00000021 */  addu      $zero, $zero, $zero
/* 4F01B4 80218D14 00000000 */  nop       
/* 4F01B8 80218D18 00000026 */  xor       $zero, $zero, $zero
/* 4F01BC 80218D1C 00000000 */  nop       
/* 4F01C0 80218D20 00000027 */  not       $zero, $zero
/* 4F01C4 80218D24 00000000 */  nop       
/* 4F01C8 80218D28 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4F01CC 80218D2C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F01D0 80218D30 00000000 */  nop       
/* 4F01D4 80218D34 00020000 */  sll       $zero, $v0, 0
/* 4F01D8 80218D38 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4F01DC 80218D3C 001800FF */  dsra32    $zero, $t8, 3
/* 4F01E0 80218D40 80218B40 */  lb        $at, -0x74c0($at)
/* 4F01E4 80218D44 80218C5C */  lb        $at, -0x73a4($at)
/* 4F01E8 80218D48 00000000 */  nop       
/* 4F01EC 80218D4C 00000000 */  nop       
/* 4F01F0 80218D50 00000000 */  nop       
/* 4F01F4 80218D54 00000000 */  nop       
/* 4F01F8 80218D58 00900001 */  movf      $zero, $a0, $fcc4
/* 4F01FC 80218D5C 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 4F0200 80218D60 F32800FF */  scd       $t0, 0xff($t9)
/* 4F0204 80218D64 80218B40 */  lb        $at, -0x74c0($at)
/* 4F0208 80218D68 80218C5C */  lb        $at, -0x73a4($at)
/* 4F020C 80218D6C 00000000 */  nop       
/* 4F0210 80218D70 00000000 */  nop       
/* 4F0214 80218D74 00F00000 */  .byte     0x00, 0xf0, 0x00, 0x00
/* 4F0218 80218D78 00000000 */  nop       
/* 4F021C 80218D7C 00124002 */  srl       $t0, $s2, 0
/* 4F0220 80218D80 03000000 */  .byte     0x03, 0x00, 0x00, 0x00
/* 4F0224 80218D84 000C00FF */  dsra32    $zero, $t4, 3
/* 4F0228 80218D88 80218C50 */  lb        $at, -0x73b0($at)
/* 4F022C 80218D8C 80218C5C */  lb        $at, -0x73a4($at)
/* 4F0230 80218D90 00000000 */  nop       
/* 4F0234 80218D94 00000000 */  nop       
/* 4F0238 80218D98 00000000 */  nop       
/* 4F023C 80218D9C 00000000 */  nop       
/* 4F0240 80218DA0 00124002 */  srl       $t0, $s2, 0
/* 4F0244 80218DA4 04000000 */  bltz      $zero, .L80218DA8
.L80218DA8:
/* 4F0248 80218DA8 000C00FF */   dsra32   $zero, $t4, 3
/* 4F024C 80218DAC 80218C50 */  lb        $at, -0x73b0($at)
/* 4F0250 80218DB0 80218C5C */  lb        $at, -0x73a4($at)
/* 4F0254 80218DB4 00000000 */  nop       
/* 4F0258 80218DB8 00000000 */  nop       
/* 4F025C 80218DBC 00000000 */  nop       
/* 4F0260 80218DC0 00000000 */  nop       
/* 4F0264 80218DC4 00124002 */  srl       $t0, $s2, 0
/* 4F0268 80218DC8 05000000 */  bltz      $t0, .L80218DCC
.L80218DCC:
/* 4F026C 80218DCC 000C00FF */   dsra32   $zero, $t4, 3
/* 4F0270 80218DD0 80218C50 */  lb        $at, -0x73b0($at)
/* 4F0274 80218DD4 80218C5C */  lb        $at, -0x73a4($at)
/* 4F0278 80218DD8 00000000 */  nop       
/* 4F027C 80218DDC 00000000 */  nop       
/* 4F0280 80218DE0 00000000 */  nop       
/* 4F0284 80218DE4 00000000 */  nop       
/* 4F0288 80218DE8 00124002 */  srl       $t0, $s2, 0
/* 4F028C 80218DEC 06000000 */  bltz      $s0, .L80218DF0
.L80218DF0:
/* 4F0290 80218DF0 000C00FF */   dsra32   $zero, $t4, 3
/* 4F0294 80218DF4 80218C50 */  lb        $at, -0x73b0($at)
/* 4F0298 80218DF8 80218C5C */  lb        $at, -0x73a4($at)
/* 4F029C 80218DFC 00000000 */  nop       
/* 4F02A0 80218E00 00000000 */  nop       
/* 4F02A4 80218E04 00000000 */  nop       
/* 4F02A8 80218E08 00000000 */  nop       
/* 4F02AC 80218E0C 00124002 */  srl       $t0, $s2, 0
/* 4F02B0 80218E10 07000000 */  bltz      $t8, .L80218E14
.L80218E14:
/* 4F02B4 80218E14 000C00FF */   dsra32   $zero, $t4, 3
/* 4F02B8 80218E18 80218C50 */  lb        $at, -0x73b0($at)
/* 4F02BC 80218E1C 80218C5C */  lb        $at, -0x73a4($at)
/* 4F02C0 80218E20 00000000 */  nop       
/* 4F02C4 80218E24 00000000 */  nop       
/* 4F02C8 80218E28 00000000 */  nop       
/* 4F02CC 80218E2C 00000000 */  nop       
/* 4F02D0 80218E30 00124002 */  srl       $t0, $s2, 0
/* 4F02D4 80218E34 08000000 */  j         .L80000000
/* 4F02D8 80218E38 000C00FF */   dsra32   $zero, $t4, 3
/* 4F02DC 80218E3C 80218C50 */  lb        $at, -0x73b0($at)
/* 4F02E0 80218E40 80218C5C */  lb        $at, -0x73a4($at)
/* 4F02E4 80218E44 00000000 */  nop       
/* 4F02E8 80218E48 00000000 */  nop       
/* 4F02EC 80218E4C 00000000 */  nop       
/* 4F02F0 80218E50 00000000 */  nop       
/* 4F02F4 80218E54 00124002 */  srl       $t0, $s2, 0
/* 4F02F8 80218E58 09000000 */  j         .L84000000
/* 4F02FC 80218E5C 000C00FF */   dsra32   $zero, $t4, 3
/* 4F0300 80218E60 80218C50 */  lb        $at, -0x73b0($at)
/* 4F0304 80218E64 80218C5C */  lb        $at, -0x73a4($at)
/* 4F0308 80218E68 00000000 */  nop       
/* 4F030C 80218E6C 00000000 */  nop       
/* 4F0310 80218E70 00000000 */  nop       
/* 4F0314 80218E74 00000000 */  nop       
/* 4F0318 80218E78 00124002 */  srl       $t0, $s2, 0
/* 4F031C 80218E7C 0A000000 */  j         .L88000000
/* 4F0320 80218E80 000C00FF */   dsra32   $zero, $t4, 3
/* 4F0324 80218E84 80218C50 */  lb        $at, -0x73b0($at)
/* 4F0328 80218E88 80218C5C */  lb        $at, -0x73a4($at)
/* 4F032C 80218E8C 00000000 */  nop       
/* 4F0330 80218E90 00000000 */  nop       
/* 4F0334 80218E94 00000000 */  nop       
/* 4F0338 80218E98 00000000 */  nop       
/* 4F033C 80218E9C 00000000 */  nop       
/* 4F0340 80218EA0 00A20E04 */  .byte     0x00, 0xa2, 0x0e, 0x04
/* 4F0344 80218EA4 000A0000 */  sll       $zero, $t2, 0
/* 4F0348 80218EA8 80218D34 */  lb        $at, -0x72cc($at)
/* 4F034C 80218EAC 80218EC4 */  lb        $at, -0x713c($at)
/* 4F0350 80218EB0 80218C88 */  lb        $at, -0x7378($at)
/* 4F0354 80218EB4 00000000 */  nop       
/* 4F0358 80218EB8 00005F00 */  sll       $t3, $zero, 0x1c
/* 4F035C 80218EBC 38280000 */  xori      $t0, $at, 0
/* 4F0360 80218EC0 F6140A14 */  sdc1      $f20, 0xa14($s0)
/* 4F0364 80218EC4 00000043 */  sra       $zero, $zero, 1
/* 4F0368 80218EC8 00000004 */  sllv      $zero, $zero, $zero
/* 4F036C 80218ECC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F0370 80218ED0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0374 80218ED4 00000008 */  jr        $zero
/* 4F0378 80218ED8 00000000 */   nop      
/* 4F037C 80218EDC 00000043 */  sra       $zero, $zero, 1
/* 4F0380 80218EE0 00000003 */  sra       $zero, $zero, 0
/* 4F0384 80218EE4 80278930 */  lb        $a3, -0x76d0($at)
/* 4F0388 80218EE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F038C 80218EEC 8021A7C4 */  lb        $at, -0x583c($at)
/* 4F0390 80218EF0 00000043 */  sra       $zero, $zero, 1
/* 4F0394 80218EF4 00000003 */  sra       $zero, $zero, 0
/* 4F0398 80218EF8 80278A94 */  lb        $a3, -0x756c($at)
/* 4F039C 80218EFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F03A0 80218F00 80219108 */  lb        $at, -0x6ef8($at)
/* 4F03A4 80218F04 00000043 */  sra       $zero, $zero, 1
/* 4F03A8 80218F08 00000003 */  sra       $zero, $zero, 0
/* 4F03AC 80218F0C 80278C20 */  lb        $a3, -0x73e0($at)
/* 4F03B0 80218F10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F03B4 80218F14 802197C4 */  lb        $at, -0x683c($at)
/* 4F03B8 80218F18 00000043 */  sra       $zero, $zero, 1
/* 4F03BC 80218F1C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F03C0 80218F20 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F03C4 80218F24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F03C8 80218F28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F03CC 80218F2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F03D0 80218F30 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F03D4 80218F34 00000043 */  sra       $zero, $zero, 1
/* 4F03D8 80218F38 00000006 */  srlv      $zero, $zero, $zero
/* 4F03DC 80218F3C 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F03E0 80218F40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F03E4 80218F44 00000002 */  srl       $zero, $zero, 0
/* 4F03E8 80218F48 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F03EC 80218F4C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F03F0 80218F50 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F03F4 80218F54 00000024 */  and       $zero, $zero, $zero
/* 4F03F8 80218F58 00000002 */  srl       $zero, $zero, 0
/* 4F03FC 80218F5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0400 80218F60 00000003 */  sra       $zero, $zero, 0
/* 4F0404 80218F64 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0408 80218F68 00000001 */  movf      $zero, $zero, $fcc0
/* 4F040C 80218F6C 00000008 */  jr        $zero
/* 4F0410 80218F70 00000043 */   sra      $zero, $zero, 1
/* 4F0414 80218F74 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0418 80218F78 8027D970 */  lb        $a3, -0x2690($at)
/* 4F041C 80218F7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0420 80218F80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0424 80218F84 00000010 */  mfhi      $zero
/* 4F0428 80218F88 00000010 */  mfhi      $zero
/* 4F042C 80218F8C 00000027 */  not       $zero, $zero
/* 4F0430 80218F90 00000002 */  srl       $zero, $zero, 0
/* 4F0434 80218F94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0438 80218F98 00000001 */  movf      $zero, $zero, $fcc0
/* 4F043C 80218F9C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0440 80218FA0 00000000 */  nop       
/* 4F0444 80218FA4 00000043 */  sra       $zero, $zero, 1
/* 4F0448 80218FA8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F044C 80218FAC 80218000 */  lb        $at, -0x8000($at)
/* 4F0450 80218FB0 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4F0454 80218FB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0458 80218FB8 8021972C */  lb        $at, -0x68d4($at)
/* 4F045C 80218FBC 00000002 */  srl       $zero, $zero, 0
/* 4F0460 80218FC0 00000000 */  nop       
/* 4F0464 80218FC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0468 80218FC8 00000000 */  nop       
/* 4F046C 80218FCC 00000043 */  sra       $zero, $zero, 1
/* 4F0470 80218FD0 00000003 */  sra       $zero, $zero, 0
/* 4F0474 80218FD4 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F0478 80218FD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F047C 80218FDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0480 80218FE0 00000010 */  mfhi      $zero
/* 4F0484 80218FE4 00000002 */  srl       $zero, $zero, 0
/* 4F0488 80218FE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F048C 80218FEC 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F0490 80218FF0 00000043 */  sra       $zero, $zero, 1
/* 4F0494 80218FF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0498 80218FF8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F049C 80218FFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F04A0 80219000 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F04A4 80219004 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F04A8 80219008 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F04AC 8021900C 00000043 */  sra       $zero, $zero, 1
/* 4F04B0 80219010 00000006 */  srlv      $zero, $zero, $zero
/* 4F04B4 80219014 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F04B8 80219018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F04BC 8021901C 00000002 */  srl       $zero, $zero, 0
/* 4F04C0 80219020 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F04C4 80219024 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F04C8 80219028 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F04CC 8021902C 00000043 */  sra       $zero, $zero, 1
/* 4F04D0 80219030 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F04D4 80219034 8027D380 */  lb        $a3, -0x2c80($at)
/* 4F04D8 80219038 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F04DC 8021903C 00000002 */  srl       $zero, $zero, 0
/* 4F04E0 80219040 00000000 */  nop       
/* 4F04E4 80219044 00000018 */  mult      $zero, $zero
/* 4F04E8 80219048 00000043 */  sra       $zero, $zero, 1
/* 4F04EC 8021904C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F04F0 80219050 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4F04F4 80219054 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F04F8 80219058 00000002 */  srl       $zero, $zero, 0
/* 4F04FC 8021905C 00000000 */  nop       
/* 4F0500 80219060 00000000 */  nop       
/* 4F0504 80219064 00000012 */  mflo      $zero
/* 4F0508 80219068 00000000 */  nop       
/* 4F050C 8021906C 00000043 */  sra       $zero, $zero, 1
/* 4F0510 80219070 00000002 */  srl       $zero, $zero, 0
/* 4F0514 80219074 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F0518 80219078 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F051C 8021907C 00000043 */  sra       $zero, $zero, 1
/* 4F0520 80219080 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0524 80219084 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F0528 80219088 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F052C 8021908C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0530 80219090 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0534 80219094 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0538 80219098 00000043 */  sra       $zero, $zero, 1
/* 4F053C 8021909C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0540 802190A0 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F0544 802190A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0548 802190A8 00000002 */  srl       $zero, $zero, 0
/* 4F054C 802190AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0550 802190B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0554 802190B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0558 802190B8 00000043 */  sra       $zero, $zero, 1
/* 4F055C 802190BC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0560 802190C0 8027D380 */  lb        $a3, -0x2c80($at)
/* 4F0564 802190C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0568 802190C8 00000002 */  srl       $zero, $zero, 0
/* 4F056C 802190CC FFFFFFF3 */  sd        $ra, -0xd($ra)
/* 4F0570 802190D0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F0574 802190D4 00000043 */  sra       $zero, $zero, 1
/* 4F0578 802190D8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F057C 802190DC 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4F0580 802190E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0584 802190E4 00000002 */  srl       $zero, $zero, 0
/* 4F0588 802190E8 00000000 */  nop       
/* 4F058C 802190EC FFFFFFF2 */  sd        $ra, -0xe($ra)
/* 4F0590 802190F0 00000013 */  mtlo      $zero
/* 4F0594 802190F4 00000000 */  nop       
/* 4F0598 802190F8 00000002 */  srl       $zero, $zero, 0
/* 4F059C 802190FC 00000000 */  nop       
/* 4F05A0 80219100 00000001 */  movf      $zero, $zero, $fcc0
/* 4F05A4 80219104 00000000 */  nop       
/* 4F05A8 80219108 00000003 */  sra       $zero, $zero, 0
/* 4F05AC 8021910C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F05B0 80219110 00000000 */  nop       
/* 4F05B4 80219114 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F05B8 80219118 00000001 */  movf      $zero, $zero, $fcc0
/* 4F05BC 8021911C 00000000 */  nop       
/* 4F05C0 80219120 00000046 */  rotrv     $zero, $zero, $zero
/* 4F05C4 80219124 00000001 */  movf      $zero, $zero, $fcc0
/* 4F05C8 80219128 80218FCC */  lb        $at, -0x7034($at)
/* 4F05CC 8021912C 00000043 */  sra       $zero, $zero, 1
/* 4F05D0 80219130 00000003 */  sra       $zero, $zero, 0
/* 4F05D4 80219134 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F05D8 80219138 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F05DC 8021913C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F05E0 80219140 00000011 */  mthi      $zero
/* 4F05E4 80219144 00000002 */  srl       $zero, $zero, 0
/* 4F05E8 80219148 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F05EC 8021914C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F05F0 80219150 00000007 */  srav      $zero, $zero, $zero
/* 4F05F4 80219154 00000000 */  nop       
/* 4F05F8 80219158 00000013 */  mtlo      $zero
/* 4F05FC 8021915C 00000000 */  nop       
/* 4F0600 80219160 00000008 */  jr        $zero
/* 4F0604 80219164 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0608 80219168 00000001 */  movf      $zero, $zero, $fcc0
/* 4F060C 8021916C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0610 80219170 00000000 */  nop       
/* 4F0614 80219174 00000043 */  sra       $zero, $zero, 1
/* 4F0618 80219178 00000004 */  sllv      $zero, $zero, $zero
/* 4F061C 8021917C 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F0620 80219180 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0624 80219184 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0628 80219188 80218C0C */  lb        $at, -0x73f4($at)
/* 4F062C 8021918C 00000043 */  sra       $zero, $zero, 1
/* 4F0630 80219190 00000003 */  sra       $zero, $zero, 0
/* 4F0634 80219194 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0638 80219198 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F063C 8021919C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F0640 802191A0 00000043 */  sra       $zero, $zero, 1
/* 4F0644 802191A4 00000002 */  srl       $zero, $zero, 0
/* 4F0648 802191A8 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F064C 802191AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0650 802191B0 00000043 */  sra       $zero, $zero, 1
/* 4F0654 802191B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0658 802191B8 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F065C 802191BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0660 802191C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0664 802191C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0668 802191C8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F066C 802191CC 00000027 */  not       $zero, $zero
/* 4F0670 802191D0 00000002 */  srl       $zero, $zero, 0
/* 4F0674 802191D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0678 802191D8 0000000A */  movz      $zero, $zero, $zero
/* 4F067C 802191DC 00000043 */  sra       $zero, $zero, 1
/* 4F0680 802191E0 00000003 */  sra       $zero, $zero, 0
/* 4F0684 802191E4 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0688 802191E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F068C 802191EC F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F0690 802191F0 00000043 */  sra       $zero, $zero, 1
/* 4F0694 802191F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0698 802191F8 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F069C 802191FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F06A0 80219200 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F06A4 80219204 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F06A8 80219208 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F06AC 8021920C 00000043 */  sra       $zero, $zero, 1
/* 4F06B0 80219210 00000004 */  sllv      $zero, $zero, $zero
/* 4F06B4 80219214 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F06B8 80219218 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F06BC 8021921C 0000000B */  movn      $zero, $zero, $zero
/* 4F06C0 80219220 00000001 */  movf      $zero, $zero, $fcc0
/* 4F06C4 80219224 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F06C8 80219228 00000001 */  movf      $zero, $zero, $fcc0
/* 4F06CC 8021922C 00000000 */  nop       
/* 4F06D0 80219230 00000046 */  rotrv     $zero, $zero, $zero
/* 4F06D4 80219234 00000001 */  movf      $zero, $zero, $fcc0
/* 4F06D8 80219238 80218FCC */  lb        $at, -0x7034($at)
/* 4F06DC 8021923C 00000043 */  sra       $zero, $zero, 1
/* 4F06E0 80219240 00000003 */  sra       $zero, $zero, 0
/* 4F06E4 80219244 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F06E8 80219248 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F06EC 8021924C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F06F0 80219250 00000011 */  mthi      $zero
/* 4F06F4 80219254 00000002 */  srl       $zero, $zero, 0
/* 4F06F8 80219258 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F06FC 8021925C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F0700 80219260 00000007 */  srav      $zero, $zero, $zero
/* 4F0704 80219264 00000000 */  nop       
/* 4F0708 80219268 00000013 */  mtlo      $zero
/* 4F070C 8021926C 00000000 */  nop       
/* 4F0710 80219270 00000008 */  jr        $zero
/* 4F0714 80219274 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0718 80219278 00000001 */  movf      $zero, $zero, $fcc0
/* 4F071C 8021927C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0720 80219280 00000000 */  nop       
/* 4F0724 80219284 00000043 */  sra       $zero, $zero, 1
/* 4F0728 80219288 00000003 */  sra       $zero, $zero, 0
/* 4F072C 8021928C 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0730 80219290 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0734 80219294 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F0738 80219298 00000043 */  sra       $zero, $zero, 1
/* 4F073C 8021929C 00000002 */  srl       $zero, $zero, 0
/* 4F0740 802192A0 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F0744 802192A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0748 802192A8 00000043 */  sra       $zero, $zero, 1
/* 4F074C 802192AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0750 802192B0 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F0754 802192B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0758 802192B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F075C 802192BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0760 802192C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0764 802192C4 00000043 */  sra       $zero, $zero, 1
/* 4F0768 802192C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F076C 802192CC 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F0770 802192D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0774 802192D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0778 802192D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F077C 802192DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0780 802192E0 00000043 */  sra       $zero, $zero, 1
/* 4F0784 802192E4 00000004 */  sllv      $zero, $zero, $zero
/* 4F0788 802192E8 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F078C 802192EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0790 802192F0 00000006 */  srlv      $zero, $zero, $zero
/* 4F0794 802192F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0798 802192F8 00000043 */  sra       $zero, $zero, 1
/* 4F079C 802192FC 00000003 */  sra       $zero, $zero, 0
/* 4F07A0 80219300 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F07A4 80219304 0000000A */  movz      $zero, $zero, $zero
/* 4F07A8 80219308 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F07AC 8021930C 00000027 */  not       $zero, $zero
/* 4F07B0 80219310 00000002 */  srl       $zero, $zero, 0
/* 4F07B4 80219314 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F07B8 80219318 00000001 */  movf      $zero, $zero, $fcc0
/* 4F07BC 8021931C 00000008 */  jr        $zero
/* 4F07C0 80219320 00000001 */   movf     $zero, $zero, $fcc0
/* 4F07C4 80219324 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F07C8 80219328 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F07CC 8021932C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F07D0 80219330 00000000 */  nop       
/* 4F07D4 80219334 00000046 */  rotrv     $zero, $zero, $zero
/* 4F07D8 80219338 00000001 */  movf      $zero, $zero, $fcc0
/* 4F07DC 8021933C 80218FCC */  lb        $at, -0x7034($at)
/* 4F07E0 80219340 00000043 */  sra       $zero, $zero, 1
/* 4F07E4 80219344 00000003 */  sra       $zero, $zero, 0
/* 4F07E8 80219348 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F07EC 8021934C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F07F0 80219350 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F07F4 80219354 00000011 */  mthi      $zero
/* 4F07F8 80219358 00000002 */  srl       $zero, $zero, 0
/* 4F07FC 8021935C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0800 80219360 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F0804 80219364 00000007 */  srav      $zero, $zero, $zero
/* 4F0808 80219368 00000000 */  nop       
/* 4F080C 8021936C 00000013 */  mtlo      $zero
/* 4F0810 80219370 00000000 */  nop       
/* 4F0814 80219374 00000008 */  jr        $zero
/* 4F0818 80219378 00000001 */   movf     $zero, $zero, $fcc0
/* 4F081C 8021937C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0820 80219380 00000006 */  srlv      $zero, $zero, $zero
/* 4F0824 80219384 00000000 */  nop       
/* 4F0828 80219388 00000043 */  sra       $zero, $zero, 1
/* 4F082C 8021938C 00000004 */  sllv      $zero, $zero, $zero
/* 4F0830 80219390 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F0834 80219394 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0838 80219398 00000001 */  movf      $zero, $zero, $fcc0
/* 4F083C 8021939C 80218BC8 */  lb        $at, -0x7438($at)
/* 4F0840 802193A0 00000043 */  sra       $zero, $zero, 1
/* 4F0844 802193A4 00000003 */  sra       $zero, $zero, 0
/* 4F0848 802193A8 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F084C 802193AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0850 802193B0 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F0854 802193B4 00000043 */  sra       $zero, $zero, 1
/* 4F0858 802193B8 00000002 */  srl       $zero, $zero, 0
/* 4F085C 802193BC 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F0860 802193C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0864 802193C4 00000043 */  sra       $zero, $zero, 1
/* 4F0868 802193C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F086C 802193CC 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F0870 802193D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0874 802193D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0878 802193D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F087C 802193DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0880 802193E0 00000043 */  sra       $zero, $zero, 1
/* 4F0884 802193E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0888 802193E8 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F088C 802193EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0890 802193F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0894 802193F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0898 802193F8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F089C 802193FC 00000043 */  sra       $zero, $zero, 1
/* 4F08A0 80219400 00000004 */  sllv      $zero, $zero, $zero
/* 4F08A4 80219404 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F08A8 80219408 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F08AC 8021940C 0000000F */  sync      
/* 4F08B0 80219410 00000001 */  movf      $zero, $zero, $fcc0
/* 4F08B4 80219414 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F08B8 80219418 00000001 */  movf      $zero, $zero, $fcc0
/* 4F08BC 8021941C 00000000 */  nop       
/* 4F08C0 80219420 00000046 */  rotrv     $zero, $zero, $zero
/* 4F08C4 80219424 00000001 */  movf      $zero, $zero, $fcc0
/* 4F08C8 80219428 80218FCC */  lb        $at, -0x7034($at)
/* 4F08CC 8021942C 00000043 */  sra       $zero, $zero, 1
/* 4F08D0 80219430 00000003 */  sra       $zero, $zero, 0
/* 4F08D4 80219434 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F08D8 80219438 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F08DC 8021943C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F08E0 80219440 00000011 */  mthi      $zero
/* 4F08E4 80219444 00000002 */  srl       $zero, $zero, 0
/* 4F08E8 80219448 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F08EC 8021944C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F08F0 80219450 00000007 */  srav      $zero, $zero, $zero
/* 4F08F4 80219454 00000000 */  nop       
/* 4F08F8 80219458 00000013 */  mtlo      $zero
/* 4F08FC 8021945C 00000000 */  nop       
/* 4F0900 80219460 00000008 */  jr        $zero
/* 4F0904 80219464 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0908 80219468 00000001 */  movf      $zero, $zero, $fcc0
/* 4F090C 8021946C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0910 80219470 00000000 */  nop       
/* 4F0914 80219474 00000043 */  sra       $zero, $zero, 1
/* 4F0918 80219478 00000004 */  sllv      $zero, $zero, $zero
/* 4F091C 8021947C 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F0920 80219480 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0924 80219484 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0928 80219488 80218C0C */  lb        $at, -0x73f4($at)
/* 4F092C 8021948C 00000043 */  sra       $zero, $zero, 1
/* 4F0930 80219490 00000003 */  sra       $zero, $zero, 0
/* 4F0934 80219494 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0938 80219498 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F093C 8021949C F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F0940 802194A0 00000043 */  sra       $zero, $zero, 1
/* 4F0944 802194A4 00000002 */  srl       $zero, $zero, 0
/* 4F0948 802194A8 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F094C 802194AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0950 802194B0 00000043 */  sra       $zero, $zero, 1
/* 4F0954 802194B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0958 802194B8 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F095C 802194BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0960 802194C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0964 802194C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0968 802194C8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F096C 802194CC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F0970 802194D0 00000002 */  srl       $zero, $zero, 0
/* 4F0974 802194D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0978 802194D8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F097C 802194DC 00000043 */  sra       $zero, $zero, 1
/* 4F0980 802194E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0984 802194E4 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F0988 802194E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F098C 802194EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0990 802194F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0994 802194F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0998 802194F8 00000043 */  sra       $zero, $zero, 1
/* 4F099C 802194FC 00000004 */  sllv      $zero, $zero, $zero
/* 4F09A0 80219500 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F09A4 80219504 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F09A8 80219508 0000000C */  syscall   
/* 4F09AC 8021950C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F09B0 80219510 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F09B4 80219514 00000001 */  movf      $zero, $zero, $fcc0
/* 4F09B8 80219518 00000000 */  nop       
/* 4F09BC 8021951C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F09C0 80219520 00000001 */  movf      $zero, $zero, $fcc0
/* 4F09C4 80219524 80218FCC */  lb        $at, -0x7034($at)
/* 4F09C8 80219528 00000043 */  sra       $zero, $zero, 1
/* 4F09CC 8021952C 00000003 */  sra       $zero, $zero, 0
/* 4F09D0 80219530 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F09D4 80219534 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F09D8 80219538 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F09DC 8021953C 00000011 */  mthi      $zero
/* 4F09E0 80219540 00000002 */  srl       $zero, $zero, 0
/* 4F09E4 80219544 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F09E8 80219548 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F09EC 8021954C 00000007 */  srav      $zero, $zero, $zero
/* 4F09F0 80219550 00000000 */  nop       
/* 4F09F4 80219554 00000013 */  mtlo      $zero
/* 4F09F8 80219558 00000000 */  nop       
/* 4F09FC 8021955C 00000008 */  jr        $zero
/* 4F0A00 80219560 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0A04 80219564 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0A08 80219568 00000006 */  srlv      $zero, $zero, $zero
/* 4F0A0C 8021956C 00000000 */  nop       
/* 4F0A10 80219570 00000043 */  sra       $zero, $zero, 1
/* 4F0A14 80219574 00000003 */  sra       $zero, $zero, 0
/* 4F0A18 80219578 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0A1C 8021957C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0A20 80219580 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F0A24 80219584 00000043 */  sra       $zero, $zero, 1
/* 4F0A28 80219588 00000002 */  srl       $zero, $zero, 0
/* 4F0A2C 8021958C 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F0A30 80219590 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0A34 80219594 00000043 */  sra       $zero, $zero, 1
/* 4F0A38 80219598 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0A3C 8021959C 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F0A40 802195A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0A44 802195A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0A48 802195A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0A4C 802195AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0A50 802195B0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F0A54 802195B4 00000002 */  srl       $zero, $zero, 0
/* 4F0A58 802195B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0A5C 802195BC 0000000A */  movz      $zero, $zero, $zero
/* 4F0A60 802195C0 00000043 */  sra       $zero, $zero, 1
/* 4F0A64 802195C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0A68 802195C8 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F0A6C 802195CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0A70 802195D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0A74 802195D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0A78 802195D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0A7C 802195DC 00000043 */  sra       $zero, $zero, 1
/* 4F0A80 802195E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F0A84 802195E4 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F0A88 802195E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0A8C 802195EC 00000009 */  jr        $zero
/* 4F0A90 802195F0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0A94 802195F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0A98 802195F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0A9C 802195FC 00000000 */  nop       
/* 4F0AA0 80219600 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0AA4 80219604 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0AA8 80219608 80218FCC */  lb        $at, -0x7034($at)
/* 4F0AAC 8021960C 00000043 */  sra       $zero, $zero, 1
/* 4F0AB0 80219610 00000003 */  sra       $zero, $zero, 0
/* 4F0AB4 80219614 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F0AB8 80219618 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0ABC 8021961C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0AC0 80219620 00000011 */  mthi      $zero
/* 4F0AC4 80219624 00000002 */  srl       $zero, $zero, 0
/* 4F0AC8 80219628 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0ACC 8021962C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F0AD0 80219630 00000007 */  srav      $zero, $zero, $zero
/* 4F0AD4 80219634 00000000 */  nop       
/* 4F0AD8 80219638 00000013 */  mtlo      $zero
/* 4F0ADC 8021963C 00000000 */  nop       
/* 4F0AE0 80219640 00000008 */  jr        $zero
/* 4F0AE4 80219644 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0AE8 80219648 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0AEC 8021964C 00000006 */  srlv      $zero, $zero, $zero
/* 4F0AF0 80219650 00000000 */  nop       
/* 4F0AF4 80219654 00000043 */  sra       $zero, $zero, 1
/* 4F0AF8 80219658 00000004 */  sllv      $zero, $zero, $zero
/* 4F0AFC 8021965C 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F0B00 80219660 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B04 80219664 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0B08 80219668 80218B84 */  lb        $at, -0x747c($at)
/* 4F0B0C 8021966C 00000043 */  sra       $zero, $zero, 1
/* 4F0B10 80219670 00000003 */  sra       $zero, $zero, 0
/* 4F0B14 80219674 8026B5D8 */  lb        $a2, -0x4a28($at)
/* 4F0B18 80219678 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B1C 8021967C F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F0B20 80219680 00000043 */  sra       $zero, $zero, 1
/* 4F0B24 80219684 00000002 */  srl       $zero, $zero, 0
/* 4F0B28 80219688 80269F2C */  lb        $a2, -0x60d4($at)
/* 4F0B2C 8021968C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B30 80219690 00000043 */  sra       $zero, $zero, 1
/* 4F0B34 80219694 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0B38 80219698 8026A8EC */  lb        $a2, -0x5714($at)
/* 4F0B3C 8021969C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B40 802196A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0B44 802196A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0B48 802196A8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0B4C 802196AC 00000043 */  sra       $zero, $zero, 1
/* 4F0B50 802196B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0B54 802196B4 8026A62C */  lb        $a2, -0x59d4($at)
/* 4F0B58 802196B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B5C 802196BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0B60 802196C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0B64 802196C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0B68 802196C8 00000043 */  sra       $zero, $zero, 1
/* 4F0B6C 802196CC 00000004 */  sllv      $zero, $zero, $zero
/* 4F0B70 802196D0 8027910C */  lb        $a3, -0x6ef4($at)
/* 4F0B74 802196D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0B78 802196D8 00000006 */  srlv      $zero, $zero, $zero
/* 4F0B7C 802196DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0B80 802196E0 00000043 */  sra       $zero, $zero, 1
/* 4F0B84 802196E4 00000003 */  sra       $zero, $zero, 0
/* 4F0B88 802196E8 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F0B8C 802196EC 0000000A */  movz      $zero, $zero, $zero
/* 4F0B90 802196F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0B94 802196F4 00000027 */  not       $zero, $zero
/* 4F0B98 802196F8 00000002 */  srl       $zero, $zero, 0
/* 4F0B9C 802196FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0BA0 80219700 0000000A */  movz      $zero, $zero, $zero
/* 4F0BA4 80219704 00000008 */  jr        $zero
/* 4F0BA8 80219708 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0BAC 8021970C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0BB0 80219710 00000004 */  sllv      $zero, $zero, $zero
/* 4F0BB4 80219714 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0BB8 80219718 00000000 */  nop       
/* 4F0BBC 8021971C 00000002 */  srl       $zero, $zero, 0
/* 4F0BC0 80219720 00000000 */  nop       
/* 4F0BC4 80219724 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0BC8 80219728 00000000 */  nop       
/* 4F0BCC 8021972C 00000003 */  sra       $zero, $zero, 0
/* 4F0BD0 80219730 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0BD4 80219734 00000000 */  nop       
/* 4F0BD8 80219738 00000008 */  jr        $zero
/* 4F0BDC 8021973C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0BE0 80219740 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0BE4 80219744 00000043 */  sra       $zero, $zero, 1
/* 4F0BE8 80219748 00000003 */  sra       $zero, $zero, 0
/* 4F0BEC 8021974C 8026DE5C */  lb        $a2, -0x21a4($at)
/* 4F0BF0 80219750 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F0BF4 80219754 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0BF8 80219758 0000000A */  movz      $zero, $zero, $zero
/* 4F0BFC 8021975C 00000002 */  srl       $zero, $zero, 0
/* 4F0C00 80219760 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0C04 80219764 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0C08 80219768 00000043 */  sra       $zero, $zero, 1
/* 4F0C0C 8021976C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0C10 80219770 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F0C14 80219774 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0C18 80219778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0C1C 8021977C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0C20 80219780 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0C24 80219784 00000043 */  sra       $zero, $zero, 1
/* 4F0C28 80219788 00000002 */  srl       $zero, $zero, 0
/* 4F0C2C 8021978C 8021825C */  lb        $at, -0x7da4($at)
/* 4F0C30 80219790 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0C34 80219794 00000004 */  sllv      $zero, $zero, $zero
/* 4F0C38 80219798 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0C3C 8021979C 00000000 */  nop       
/* 4F0C40 802197A0 00000013 */  mtlo      $zero
/* 4F0C44 802197A4 00000000 */  nop       
/* 4F0C48 802197A8 00000003 */  sra       $zero, $zero, 0
/* 4F0C4C 802197AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0C50 802197B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0C54 802197B4 00000002 */  srl       $zero, $zero, 0
/* 4F0C58 802197B8 00000000 */  nop       
/* 4F0C5C 802197BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0C60 802197C0 00000000 */  nop       
/* 4F0C64 802197C4 00000043 */  sra       $zero, $zero, 1
/* 4F0C68 802197C8 00000003 */  sra       $zero, $zero, 0
/* 4F0C6C 802197CC 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F0C70 802197D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0C74 802197D4 00000000 */  nop       
/* 4F0C78 802197D8 00000043 */  sra       $zero, $zero, 1
/* 4F0C7C 802197DC 00000003 */  sra       $zero, $zero, 0
/* 4F0C80 802197E0 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F0C84 802197E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0C88 802197E8 00000000 */  nop       
/* 4F0C8C 802197EC 00000043 */  sra       $zero, $zero, 1
/* 4F0C90 802197F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0C94 802197F4 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F0C98 802197F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0C9C 802197FC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F0CA0 80219800 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F0CA4 80219804 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F0CA8 80219808 00000043 */  sra       $zero, $zero, 1
/* 4F0CAC 8021980C 00000003 */  sra       $zero, $zero, 0
/* 4F0CB0 80219810 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 4F0CB4 80219814 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0CB8 80219818 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0CBC 8021981C 00000024 */  and       $zero, $zero, $zero
/* 4F0CC0 80219820 00000002 */  srl       $zero, $zero, 0
/* 4F0CC4 80219824 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F0CC8 80219828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0CCC 8021982C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F0CD0 80219830 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0CD4 80219834 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0CD8 80219838 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0CDC 8021983C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0CE0 80219840 00000009 */  jr        $zero
/* 4F0CE4 80219844 00000025 */   or       $zero, $zero, $zero
/* 4F0CE8 80219848 00000002 */  srl       $zero, $zero, 0
/* 4F0CEC 8021984C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0CF0 80219850 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0CF4 80219854 00000025 */  or        $zero, $zero, $zero
/* 4F0CF8 80219858 00000002 */  srl       $zero, $zero, 0
/* 4F0CFC 8021985C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0D00 80219860 00690006 */  srlv      $zero, $t1, $v1
/* 4F0D04 80219864 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0D08 80219868 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D0C 8021986C 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F0D10 80219870 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0D14 80219874 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D18 80219878 0000000A */  movz      $zero, $zero, $zero
/* 4F0D1C 8021987C 00000025 */  or        $zero, $zero, $zero
/* 4F0D20 80219880 00000002 */  srl       $zero, $zero, 0
/* 4F0D24 80219884 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0D28 80219888 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D2C 8021988C 00000025 */  or        $zero, $zero, $zero
/* 4F0D30 80219890 00000002 */  srl       $zero, $zero, 0
/* 4F0D34 80219894 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0D38 80219898 00690006 */  srlv      $zero, $t1, $v1
/* 4F0D3C 8021989C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0D40 802198A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D44 802198A4 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F0D48 802198A8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0D4C 802198AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D50 802198B0 00000038 */  dsll      $zero, $zero, 0
/* 4F0D54 802198B4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0D58 802198B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D5C 802198BC 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F0D60 802198C0 00000025 */  or        $zero, $zero, $zero
/* 4F0D64 802198C4 00000002 */  srl       $zero, $zero, 0
/* 4F0D68 802198C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0D6C 802198CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D70 802198D0 00000025 */  or        $zero, $zero, $zero
/* 4F0D74 802198D4 00000002 */  srl       $zero, $zero, 0
/* 4F0D78 802198D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0D7C 802198DC 00690006 */  srlv      $zero, $t1, $v1
/* 4F0D80 802198E0 00000025 */  or        $zero, $zero, $zero
/* 4F0D84 802198E4 00000002 */  srl       $zero, $zero, 0
/* 4F0D88 802198E8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0D8C 802198EC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F0D90 802198F0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0D94 802198F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0D98 802198F8 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F0D9C 802198FC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0DA0 80219900 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0DA4 80219904 00000024 */  and       $zero, $zero, $zero
/* 4F0DA8 80219908 00000025 */  or        $zero, $zero, $zero
/* 4F0DAC 8021990C 00000002 */  srl       $zero, $zero, 0
/* 4F0DB0 80219910 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0DB4 80219914 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0DB8 80219918 00000025 */  or        $zero, $zero, $zero
/* 4F0DBC 8021991C 00000002 */  srl       $zero, $zero, 0
/* 4F0DC0 80219920 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0DC4 80219924 00690006 */  srlv      $zero, $t1, $v1
/* 4F0DC8 80219928 00000025 */  or        $zero, $zero, $zero
/* 4F0DCC 8021992C 00000002 */  srl       $zero, $zero, 0
/* 4F0DD0 80219930 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0DD4 80219934 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F0DD8 80219938 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0DDC 8021993C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0DE0 80219940 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F0DE4 80219944 00000008 */  jr        $zero
/* 4F0DE8 80219948 00000001 */   movf     $zero, $zero, $fcc0
/* 4F0DEC 8021994C 0000000A */  movz      $zero, $zero, $zero
/* 4F0DF0 80219950 00000043 */  sra       $zero, $zero, 1
/* 4F0DF4 80219954 00000004 */  sllv      $zero, $zero, $zero
/* 4F0DF8 80219958 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F0DFC 8021995C 00000200 */  sll       $zero, $zero, 8
/* 4F0E00 80219960 0000000C */  syscall   
/* 4F0E04 80219964 00000002 */  srl       $zero, $zero, 0
/* 4F0E08 80219968 00000025 */  or        $zero, $zero, $zero
/* 4F0E0C 8021996C 00000002 */  srl       $zero, $zero, 0
/* 4F0E10 80219970 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0E14 80219974 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E18 80219978 00000025 */  or        $zero, $zero, $zero
/* 4F0E1C 8021997C 00000002 */  srl       $zero, $zero, 0
/* 4F0E20 80219980 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0E24 80219984 00690006 */  srlv      $zero, $t1, $v1
/* 4F0E28 80219988 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0E2C 8021998C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E30 80219990 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F0E34 80219994 00000002 */  srl       $zero, $zero, 0
/* 4F0E38 80219998 00000000 */  nop       
/* 4F0E3C 8021999C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0E40 802199A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E44 802199A4 0000000B */  movn      $zero, $zero, $zero
/* 4F0E48 802199A8 00000025 */  or        $zero, $zero, $zero
/* 4F0E4C 802199AC 00000002 */  srl       $zero, $zero, 0
/* 4F0E50 802199B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0E54 802199B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E58 802199B8 00000025 */  or        $zero, $zero, $zero
/* 4F0E5C 802199BC 00000002 */  srl       $zero, $zero, 0
/* 4F0E60 802199C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0E64 802199C4 00690006 */  srlv      $zero, $t1, $v1
/* 4F0E68 802199C8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0E6C 802199CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E70 802199D0 8021A200 */  lb        $at, -0x5e00($at)
/* 4F0E74 802199D4 00000043 */  sra       $zero, $zero, 1
/* 4F0E78 802199D8 00000003 */  sra       $zero, $zero, 0
/* 4F0E7C 802199DC 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F0E80 802199E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0E84 802199E4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F0E88 802199E8 00000043 */  sra       $zero, $zero, 1
/* 4F0E8C 802199EC 00000003 */  sra       $zero, $zero, 0
/* 4F0E90 802199F0 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F0E94 802199F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0E98 802199F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0E9C 802199FC 00000002 */  srl       $zero, $zero, 0
/* 4F0EA0 80219A00 00000000 */  nop       
/* 4F0EA4 80219A04 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F0EA8 80219A08 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0EAC 80219A0C 0000002F */  dsubu     $zero, $zero, $zero
/* 4F0EB0 80219A10 00000025 */  or        $zero, $zero, $zero
/* 4F0EB4 80219A14 00000002 */  srl       $zero, $zero, 0
/* 4F0EB8 80219A18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0EBC 80219A1C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0EC0 80219A20 00000025 */  or        $zero, $zero, $zero
/* 4F0EC4 80219A24 00000002 */  srl       $zero, $zero, 0
/* 4F0EC8 80219A28 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0ECC 80219A2C 00690006 */  srlv      $zero, $t1, $v1
/* 4F0ED0 80219A30 00000046 */  rotrv     $zero, $zero, $zero
/* 4F0ED4 80219A34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0ED8 80219A38 8029A6FC */  lb        $t1, -0x5904($at)
/* 4F0EDC 80219A3C 00000025 */  or        $zero, $zero, $zero
/* 4F0EE0 80219A40 00000002 */  srl       $zero, $zero, 0
/* 4F0EE4 80219A44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0EE8 80219A48 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0EEC 80219A4C 00000025 */  or        $zero, $zero, $zero
/* 4F0EF0 80219A50 00000002 */  srl       $zero, $zero, 0
/* 4F0EF4 80219A54 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0EF8 80219A58 00690006 */  srlv      $zero, $t1, $v1
/* 4F0EFC 80219A5C 00000043 */  sra       $zero, $zero, 1
/* 4F0F00 80219A60 00000002 */  srl       $zero, $zero, 0
/* 4F0F04 80219A64 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F0F08 80219A68 00000002 */  srl       $zero, $zero, 0
/* 4F0F0C 80219A6C 00000043 */  sra       $zero, $zero, 1
/* 4F0F10 80219A70 00000004 */  sllv      $zero, $zero, $zero
/* 4F0F14 80219A74 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F0F18 80219A78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0F1C 80219A7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0F20 80219A80 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0F24 80219A84 00000043 */  sra       $zero, $zero, 1
/* 4F0F28 80219A88 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0F2C 80219A8C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F0F30 80219A90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0F34 80219A94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0F38 80219A98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0F3C 80219A9C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0F40 80219AA0 00000024 */  and       $zero, $zero, $zero
/* 4F0F44 80219AA4 00000002 */  srl       $zero, $zero, 0
/* 4F0F48 80219AA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0F4C 80219AAC 00000000 */  nop       
/* 4F0F50 80219AB0 00000043 */  sra       $zero, $zero, 1
/* 4F0F54 80219AB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0F58 80219AB8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F0F5C 80219ABC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0F60 80219AC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F0F64 80219AC4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F0F68 80219AC8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F0F6C 80219ACC 00000043 */  sra       $zero, $zero, 1
/* 4F0F70 80219AD0 00000003 */  sra       $zero, $zero, 0
/* 4F0F74 80219AD4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F0F78 80219AD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0F7C 80219ADC F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F0F80 80219AE0 00000043 */  sra       $zero, $zero, 1
/* 4F0F84 80219AE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0F88 80219AE8 8026A748 */  lb        $a2, -0x58b8($at)
/* 4F0F8C 80219AEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0F90 80219AF0 0000001E */  ddiv      $zero, $zero, $zero
/* 4F0F94 80219AF4 00000000 */  nop       
/* 4F0F98 80219AF8 00000000 */  nop       
/* 4F0F9C 80219AFC 00000043 */  sra       $zero, $zero, 1
/* 4F0FA0 80219B00 00000006 */  srlv      $zero, $zero, $zero
/* 4F0FA4 80219B04 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F0FA8 80219B08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0FAC 80219B0C 0000000F */  sync      
/* 4F0FB0 80219B10 00000000 */  nop       
/* 4F0FB4 80219B14 00000001 */  movf      $zero, $zero, $fcc0
/* 4F0FB8 80219B18 00000000 */  nop       
/* 4F0FBC 80219B1C 00000043 */  sra       $zero, $zero, 1
/* 4F0FC0 80219B20 00000003 */  sra       $zero, $zero, 0
/* 4F0FC4 80219B24 8025385C */  lb        $a1, 0x385c($at)
/* 4F0FC8 80219B28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0FCC 80219B2C 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F0FD0 80219B30 00000043 */  sra       $zero, $zero, 1
/* 4F0FD4 80219B34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F0FD8 80219B38 8026A748 */  lb        $a2, -0x58b8($at)
/* 4F0FDC 80219B3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0FE0 80219B40 0000000F */  sync      
/* 4F0FE4 80219B44 00000000 */  nop       
/* 4F0FE8 80219B48 00000000 */  nop       
/* 4F0FEC 80219B4C 00000043 */  sra       $zero, $zero, 1
/* 4F0FF0 80219B50 00000006 */  srlv      $zero, $zero, $zero
/* 4F0FF4 80219B54 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F0FF8 80219B58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F0FFC 80219B5C 00000008 */  jr        $zero
/* 4F1000 80219B60 00000000 */   nop      
/* 4F1004 80219B64 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1008 80219B68 00000000 */  nop       
/* 4F100C 80219B6C 00000043 */  sra       $zero, $zero, 1
/* 4F1010 80219B70 00000003 */  sra       $zero, $zero, 0
/* 4F1014 80219B74 8025385C */  lb        $a1, 0x385c($at)
/* 4F1018 80219B78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F101C 80219B7C 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F1020 80219B80 00000043 */  sra       $zero, $zero, 1
/* 4F1024 80219B84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1028 80219B88 8026A748 */  lb        $a2, -0x58b8($at)
/* 4F102C 80219B8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1030 80219B90 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1034 80219B94 00000000 */  nop       
/* 4F1038 80219B98 00000000 */  nop       
/* 4F103C 80219B9C 00000043 */  sra       $zero, $zero, 1
/* 4F1040 80219BA0 00000006 */  srlv      $zero, $zero, $zero
/* 4F1044 80219BA4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1048 80219BA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F104C 80219BAC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1050 80219BB0 00000000 */  nop       
/* 4F1054 80219BB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1058 80219BB8 00000000 */  nop       
/* 4F105C 80219BBC 00000043 */  sra       $zero, $zero, 1
/* 4F1060 80219BC0 00000003 */  sra       $zero, $zero, 0
/* 4F1064 80219BC4 8025385C */  lb        $a1, 0x385c($at)
/* 4F1068 80219BC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F106C 80219BCC 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F1070 80219BD0 00000043 */  sra       $zero, $zero, 1
/* 4F1074 80219BD4 00000006 */  srlv      $zero, $zero, $zero
/* 4F1078 80219BD8 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F107C 80219BDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1080 80219BE0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1084 80219BE4 00000000 */  nop       
/* 4F1088 80219BE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F108C 80219BEC 00000000 */  nop       
/* 4F1090 80219BF0 00000043 */  sra       $zero, $zero, 1
/* 4F1094 80219BF4 00000003 */  sra       $zero, $zero, 0
/* 4F1098 80219BF8 8025385C */  lb        $a1, 0x385c($at)
/* 4F109C 80219BFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F10A0 80219C00 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F10A4 80219C04 00000025 */  or        $zero, $zero, $zero
/* 4F10A8 80219C08 00000002 */  srl       $zero, $zero, 0
/* 4F10AC 80219C0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F10B0 80219C10 00000001 */  movf      $zero, $zero, $fcc0
/* 4F10B4 80219C14 00000025 */  or        $zero, $zero, $zero
/* 4F10B8 80219C18 00000002 */  srl       $zero, $zero, 0
/* 4F10BC 80219C1C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F10C0 80219C20 00690005 */  lsa       $zero, $v1, $t1, 1
/* 4F10C4 80219C24 00000046 */  rotrv     $zero, $zero, $zero
/* 4F10C8 80219C28 00000001 */  movf      $zero, $zero, $fcc0
/* 4F10CC 80219C2C 8021B41C */  lb        $at, -0x4be4($at)
/* 4F10D0 80219C30 00000043 */  sra       $zero, $zero, 1
/* 4F10D4 80219C34 00000003 */  sra       $zero, $zero, 0
/* 4F10D8 80219C38 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F10DC 80219C3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F10E0 80219C40 F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 4F10E4 80219C44 00000043 */  sra       $zero, $zero, 1
/* 4F10E8 80219C48 00000006 */  srlv      $zero, $zero, $zero
/* 4F10EC 80219C4C 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F10F0 80219C50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F10F4 80219C54 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F10F8 80219C58 00000000 */  nop       
/* 4F10FC 80219C5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1100 80219C60 00000000 */  nop       
/* 4F1104 80219C64 00000043 */  sra       $zero, $zero, 1
/* 4F1108 80219C68 00000003 */  sra       $zero, $zero, 0
/* 4F110C 80219C6C 8025385C */  lb        $a1, 0x385c($at)
/* 4F1110 80219C70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1114 80219C74 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F1118 80219C78 00000056 */  drotrv    $zero, $zero, $zero
/* 4F111C 80219C7C 00000000 */  nop       
/* 4F1120 80219C80 00000043 */  sra       $zero, $zero, 1
/* 4F1124 80219C84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1128 80219C88 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F112C 80219C8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1130 80219C90 00000000 */  nop       
/* 4F1134 80219C94 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1138 80219C98 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F113C 80219C9C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1140 80219CA0 00000000 */  nop       
/* 4F1144 80219CA4 00000043 */  sra       $zero, $zero, 1
/* 4F1148 80219CA8 00000002 */  srl       $zero, $zero, 0
/* 4F114C 80219CAC 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F1150 80219CB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1154 80219CB4 00000043 */  sra       $zero, $zero, 1
/* 4F1158 80219CB8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F115C 80219CBC 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F1160 80219CC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1164 80219CC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1168 80219CC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F116C 80219CCC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1170 80219CD0 00000043 */  sra       $zero, $zero, 1
/* 4F1174 80219CD4 00000006 */  srlv      $zero, $zero, $zero
/* 4F1178 80219CD8 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F117C 80219CDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1180 80219CE0 00000002 */  srl       $zero, $zero, 0
/* 4F1184 80219CE4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1188 80219CE8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F118C 80219CEC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1190 80219CF0 00000043 */  sra       $zero, $zero, 1
/* 4F1194 80219CF4 00000004 */  sllv      $zero, $zero, $zero
/* 4F1198 80219CF8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F119C 80219CFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F11A0 80219D00 00000008 */  jr        $zero
/* 4F11A4 80219D04 00000000 */   nop      
/* 4F11A8 80219D08 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F11AC 80219D0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F11B0 80219D10 0000003A */  dsrl      $zero, $zero, 0
/* 4F11B4 80219D14 00000043 */  sra       $zero, $zero, 1
/* 4F11B8 80219D18 00000003 */  sra       $zero, $zero, 0
/* 4F11BC 80219D1C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F11C0 80219D20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F11C4 80219D24 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F11C8 80219D28 00000011 */  mthi      $zero
/* 4F11CC 80219D2C 00000002 */  srl       $zero, $zero, 0
/* 4F11D0 80219D30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F11D4 80219D34 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F11D8 80219D38 00000043 */  sra       $zero, $zero, 1
/* 4F11DC 80219D3C 00000002 */  srl       $zero, $zero, 0
/* 4F11E0 80219D40 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F11E4 80219D44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F11E8 80219D48 00000043 */  sra       $zero, $zero, 1
/* 4F11EC 80219D4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F11F0 80219D50 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F11F4 80219D54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F11F8 80219D58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F11FC 80219D5C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1200 80219D60 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F1204 80219D64 00000010 */  mfhi      $zero
/* 4F1208 80219D68 00000002 */  srl       $zero, $zero, 0
/* 4F120C 80219D6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1210 80219D70 00080000 */  sll       $zero, $t0, 0
/* 4F1214 80219D74 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F1218 80219D78 00000002 */  srl       $zero, $zero, 0
/* 4F121C 80219D7C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1220 80219D80 0000000A */  movz      $zero, $zero, $zero
/* 4F1224 80219D84 00000027 */  not       $zero, $zero
/* 4F1228 80219D88 00000002 */  srl       $zero, $zero, 0
/* 4F122C 80219D8C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1230 80219D90 00000004 */  sllv      $zero, $zero, $zero
/* 4F1234 80219D94 00000012 */  mflo      $zero
/* 4F1238 80219D98 00000000 */  nop       
/* 4F123C 80219D9C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F1240 80219DA0 00000002 */  srl       $zero, $zero, 0
/* 4F1244 80219DA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1248 80219DA8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F124C 80219DAC 00000027 */  not       $zero, $zero
/* 4F1250 80219DB0 00000002 */  srl       $zero, $zero, 0
/* 4F1254 80219DB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1258 80219DB8 0000000B */  movn      $zero, $zero, $zero
/* 4F125C 80219DBC 00000013 */  mtlo      $zero
/* 4F1260 80219DC0 00000000 */  nop       
/* 4F1264 80219DC4 00000043 */  sra       $zero, $zero, 1
/* 4F1268 80219DC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F126C 80219DCC 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4F1270 80219DD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1274 80219DD4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1278 80219DD8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F127C 80219DDC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F1280 80219DE0 00000013 */  mtlo      $zero
/* 4F1284 80219DE4 00000000 */  nop       
/* 4F1288 80219DE8 00000025 */  or        $zero, $zero, $zero
/* 4F128C 80219DEC 00000002 */  srl       $zero, $zero, 0
/* 4F1290 80219DF0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1294 80219DF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1298 80219DF8 00000025 */  or        $zero, $zero, $zero
/* 4F129C 80219DFC 00000002 */  srl       $zero, $zero, 0
/* 4F12A0 80219E00 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F12A4 80219E04 00690006 */  srlv      $zero, $t1, $v1
/* 4F12A8 80219E08 00000046 */  rotrv     $zero, $zero, $zero
/* 4F12AC 80219E0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F12B0 80219E10 8029C37C */  lb        $t1, -0x3c84($at)
/* 4F12B4 80219E14 00000043 */  sra       $zero, $zero, 1
/* 4F12B8 80219E18 00000003 */  sra       $zero, $zero, 0
/* 4F12BC 80219E1C 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F12C0 80219E20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F12C4 80219E24 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F12C8 80219E28 00000043 */  sra       $zero, $zero, 1
/* 4F12CC 80219E2C 00000003 */  sra       $zero, $zero, 0
/* 4F12D0 80219E30 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F12D4 80219E34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F12D8 80219E38 00000001 */  movf      $zero, $zero, $fcc0
/* 4F12DC 80219E3C 00000002 */  srl       $zero, $zero, 0
/* 4F12E0 80219E40 00000000 */  nop       
/* 4F12E4 80219E44 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F12E8 80219E48 00000001 */  movf      $zero, $zero, $fcc0
/* 4F12EC 80219E4C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F12F0 80219E50 00000025 */  or        $zero, $zero, $zero
/* 4F12F4 80219E54 00000002 */  srl       $zero, $zero, 0
/* 4F12F8 80219E58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F12FC 80219E5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1300 80219E60 00000025 */  or        $zero, $zero, $zero
/* 4F1304 80219E64 00000002 */  srl       $zero, $zero, 0
/* 4F1308 80219E68 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F130C 80219E6C 00690006 */  srlv      $zero, $t1, $v1
/* 4F1310 80219E70 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1314 80219E74 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1318 80219E78 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 4F131C 80219E7C 00000002 */  srl       $zero, $zero, 0
/* 4F1320 80219E80 00000000 */  nop       
/* 4F1324 80219E84 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F1328 80219E88 00000001 */  movf      $zero, $zero, $fcc0
/* 4F132C 80219E8C 0000001F */  ddivu     $zero, $zero, $zero
/* 4F1330 80219E90 00000025 */  or        $zero, $zero, $zero
/* 4F1334 80219E94 00000002 */  srl       $zero, $zero, 0
/* 4F1338 80219E98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F133C 80219E9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1340 80219EA0 00000025 */  or        $zero, $zero, $zero
/* 4F1344 80219EA4 00000002 */  srl       $zero, $zero, 0
/* 4F1348 80219EA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F134C 80219EAC 00690001 */  movt      $zero, $v1, $fcc2
/* 4F1350 80219EB0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1354 80219EB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1358 80219EB8 8029AC70 */  lb        $t1, -0x5390($at)
/* 4F135C 80219EBC 00000043 */  sra       $zero, $zero, 1
/* 4F1360 80219EC0 00000004 */  sllv      $zero, $zero, $zero
/* 4F1364 80219EC4 8026B2D0 */  lb        $a2, -0x4d30($at)
/* 4F1368 80219EC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F136C 80219ECC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1370 80219ED0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F1374 80219ED4 0000001D */  dmultu    $zero, $zero
/* 4F1378 80219ED8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F137C 80219EDC 00000017 */  dsrav     $zero, $zero, $zero
/* 4F1380 80219EE0 0000001D */  dmultu    $zero, $zero
/* 4F1384 80219EE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1388 80219EE8 00000019 */  multu     $zero, $zero
/* 4F138C 80219EEC 00000025 */  or        $zero, $zero, $zero
/* 4F1390 80219EF0 00000002 */  srl       $zero, $zero, 0
/* 4F1394 80219EF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1398 80219EF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F139C 80219EFC 00000025 */  or        $zero, $zero, $zero
/* 4F13A0 80219F00 00000002 */  srl       $zero, $zero, 0
/* 4F13A4 80219F04 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F13A8 80219F08 00690001 */  movt      $zero, $v1, $fcc2
/* 4F13AC 80219F0C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F13B0 80219F10 00000001 */  movf      $zero, $zero, $fcc0
/* 4F13B4 80219F14 8029AC70 */  lb        $t1, -0x5390($at)
/* 4F13B8 80219F18 00000020 */  add       $zero, $zero, $zero
/* 4F13BC 80219F1C 00000000 */  nop       
/* 4F13C0 80219F20 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F13C4 80219F24 00000001 */  movf      $zero, $zero, $fcc0
/* 4F13C8 80219F28 00000026 */  xor       $zero, $zero, $zero
/* 4F13CC 80219F2C 00000025 */  or        $zero, $zero, $zero
/* 4F13D0 80219F30 00000002 */  srl       $zero, $zero, 0
/* 4F13D4 80219F34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F13D8 80219F38 00000001 */  movf      $zero, $zero, $fcc0
/* 4F13DC 80219F3C 00000025 */  or        $zero, $zero, $zero
/* 4F13E0 80219F40 00000002 */  srl       $zero, $zero, 0
/* 4F13E4 80219F44 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F13E8 80219F48 00690006 */  srlv      $zero, $t1, $v1
/* 4F13EC 80219F4C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F13F0 80219F50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F13F4 80219F54 8029A6FC */  lb        $t1, -0x5904($at)
/* 4F13F8 80219F58 00000043 */  sra       $zero, $zero, 1
/* 4F13FC 80219F5C 00000004 */  sllv      $zero, $zero, $zero
/* 4F1400 80219F60 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F1404 80219F64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1408 80219F68 00000008 */  jr        $zero
/* 4F140C 80219F6C 00000000 */   nop      
/* 4F1410 80219F70 00000008 */  jr        $zero
/* 4F1414 80219F74 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1418 80219F78 0000000A */  movz      $zero, $zero, $zero
/* 4F141C 80219F7C 00000043 */  sra       $zero, $zero, 1
/* 4F1420 80219F80 00000004 */  sllv      $zero, $zero, $zero
/* 4F1424 80219F84 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F1428 80219F88 00000200 */  sll       $zero, $zero, 8
/* 4F142C 80219F8C 0000000C */  syscall   
/* 4F1430 80219F90 00000002 */  srl       $zero, $zero, 0
/* 4F1434 80219F94 00000025 */  or        $zero, $zero, $zero
/* 4F1438 80219F98 00000002 */  srl       $zero, $zero, 0
/* 4F143C 80219F9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1440 80219FA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1444 80219FA4 00000025 */  or        $zero, $zero, $zero
/* 4F1448 80219FA8 00000002 */  srl       $zero, $zero, 0
/* 4F144C 80219FAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1450 80219FB0 00690006 */  srlv      $zero, $t1, $v1
/* 4F1454 80219FB4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1458 80219FB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F145C 80219FBC 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F1460 80219FC0 00000002 */  srl       $zero, $zero, 0
/* 4F1464 80219FC4 00000000 */  nop       
/* 4F1468 80219FC8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F146C 80219FCC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1470 80219FD0 00000020 */  add       $zero, $zero, $zero
/* 4F1474 80219FD4 00000025 */  or        $zero, $zero, $zero
/* 4F1478 80219FD8 00000002 */  srl       $zero, $zero, 0
/* 4F147C 80219FDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1480 80219FE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1484 80219FE4 00000025 */  or        $zero, $zero, $zero
/* 4F1488 80219FE8 00000002 */  srl       $zero, $zero, 0
/* 4F148C 80219FEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1490 80219FF0 00690006 */  srlv      $zero, $t1, $v1
/* 4F1494 80219FF4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1498 80219FF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F149C 80219FFC 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F14A0 8021A000 00000008 */  jr        $zero
/* 4F14A4 8021A004 00000001 */   movf     $zero, $zero, $fcc0
/* 4F14A8 8021A008 0000000A */  movz      $zero, $zero, $zero
/* 4F14AC 8021A00C 00000043 */  sra       $zero, $zero, 1
/* 4F14B0 8021A010 00000004 */  sllv      $zero, $zero, $zero
/* 4F14B4 8021A014 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F14B8 8021A018 00000200 */  sll       $zero, $zero, 8
/* 4F14BC 8021A01C 0000000C */  syscall   
/* 4F14C0 8021A020 00000002 */  srl       $zero, $zero, 0
/* 4F14C4 8021A024 00000025 */  or        $zero, $zero, $zero
/* 4F14C8 8021A028 00000002 */  srl       $zero, $zero, 0
/* 4F14CC 8021A02C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F14D0 8021A030 00000001 */  movf      $zero, $zero, $fcc0
/* 4F14D4 8021A034 00000025 */  or        $zero, $zero, $zero
/* 4F14D8 8021A038 00000002 */  srl       $zero, $zero, 0
/* 4F14DC 8021A03C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F14E0 8021A040 00690006 */  srlv      $zero, $t1, $v1
/* 4F14E4 8021A044 00000046 */  rotrv     $zero, $zero, $zero
/* 4F14E8 8021A048 00000001 */  movf      $zero, $zero, $fcc0
/* 4F14EC 8021A04C 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F14F0 8021A050 00000002 */  srl       $zero, $zero, 0
/* 4F14F4 8021A054 00000000 */  nop       
/* 4F14F8 8021A058 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F14FC 8021A05C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1500 8021A060 00000021 */  addu      $zero, $zero, $zero
/* 4F1504 8021A064 00000025 */  or        $zero, $zero, $zero
/* 4F1508 8021A068 00000002 */  srl       $zero, $zero, 0
/* 4F150C 8021A06C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1510 8021A070 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1514 8021A074 00000025 */  or        $zero, $zero, $zero
/* 4F1518 8021A078 00000002 */  srl       $zero, $zero, 0
/* 4F151C 8021A07C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1520 8021A080 00690006 */  srlv      $zero, $t1, $v1
/* 4F1524 8021A084 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1528 8021A088 00000001 */  movf      $zero, $zero, $fcc0
/* 4F152C 8021A08C 8021A200 */  lb        $at, -0x5e00($at)
/* 4F1530 8021A090 00000043 */  sra       $zero, $zero, 1
/* 4F1534 8021A094 00000004 */  sllv      $zero, $zero, $zero
/* 4F1538 8021A098 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F153C 8021A09C 00000200 */  sll       $zero, $zero, 8
/* 4F1540 8021A0A0 0000000C */  syscall   
/* 4F1544 8021A0A4 00000002 */  srl       $zero, $zero, 0
/* 4F1548 8021A0A8 00000025 */  or        $zero, $zero, $zero
/* 4F154C 8021A0AC 00000002 */  srl       $zero, $zero, 0
/* 4F1550 8021A0B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1554 8021A0B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1558 8021A0B8 00000025 */  or        $zero, $zero, $zero
/* 4F155C 8021A0BC 00000002 */  srl       $zero, $zero, 0
/* 4F1560 8021A0C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1564 8021A0C4 00690006 */  srlv      $zero, $t1, $v1
/* 4F1568 8021A0C8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F156C 8021A0CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1570 8021A0D0 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F1574 8021A0D4 00000002 */  srl       $zero, $zero, 0
/* 4F1578 8021A0D8 00000000 */  nop       
/* 4F157C 8021A0DC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F1580 8021A0E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1584 8021A0E4 00000031 */  tgeu      $zero, $zero
/* 4F1588 8021A0E8 00000025 */  or        $zero, $zero, $zero
/* 4F158C 8021A0EC 00000002 */  srl       $zero, $zero, 0
/* 4F1590 8021A0F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1594 8021A0F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1598 8021A0F8 00000025 */  or        $zero, $zero, $zero
/* 4F159C 8021A0FC 00000002 */  srl       $zero, $zero, 0
/* 4F15A0 8021A100 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F15A4 8021A104 00690001 */  movt      $zero, $v1, $fcc2
/* 4F15A8 8021A108 00000046 */  rotrv     $zero, $zero, $zero
/* 4F15AC 8021A10C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F15B0 8021A110 8029BFA0 */  lb        $t1, -0x4060($at)
/* 4F15B4 8021A114 0000001C */  dmult     $zero, $zero
/* 4F15B8 8021A118 00000000 */  nop       
/* 4F15BC 8021A11C 00000023 */  negu      $zero, $zero
/* 4F15C0 8021A120 00000000 */  nop       
/* 4F15C4 8021A124 00000043 */  sra       $zero, $zero, 1
/* 4F15C8 8021A128 00000003 */  sra       $zero, $zero, 0
/* 4F15CC 8021A12C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F15D0 8021A130 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F15D4 8021A134 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F15D8 8021A138 00000010 */  mfhi      $zero
/* 4F15DC 8021A13C 00000002 */  srl       $zero, $zero, 0
/* 4F15E0 8021A140 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F15E4 8021A144 00151000 */  sll       $v0, $s5, 0
/* 4F15E8 8021A148 00000043 */  sra       $zero, $zero, 1
/* 4F15EC 8021A14C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F15F0 8021A150 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F15F4 8021A154 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F15F8 8021A158 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F15FC 8021A15C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1600 8021A160 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1604 8021A164 0000000B */  movn      $zero, $zero, $zero
/* 4F1608 8021A168 00000002 */  srl       $zero, $zero, 0
/* 4F160C 8021A16C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1610 8021A170 00000000 */  nop       
/* 4F1614 8021A174 00000043 */  sra       $zero, $zero, 1
/* 4F1618 8021A178 00000003 */  sra       $zero, $zero, 0
/* 4F161C 8021A17C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1620 8021A180 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1624 8021A184 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F1628 8021A188 00000043 */  sra       $zero, $zero, 1
/* 4F162C 8021A18C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1630 8021A190 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1634 8021A194 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1638 8021A198 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F163C 8021A19C 00000000 */  nop       
/* 4F1640 8021A1A0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1644 8021A1A4 00000043 */  sra       $zero, $zero, 1
/* 4F1648 8021A1A8 00000003 */  sra       $zero, $zero, 0
/* 4F164C 8021A1AC 80279BEC */  lb        $a3, -0x6414($at)
/* 4F1650 8021A1B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1654 8021A1B4 0000000B */  movn      $zero, $zero, $zero
/* 4F1658 8021A1B8 00000013 */  mtlo      $zero
/* 4F165C 8021A1BC 00000000 */  nop       
/* 4F1660 8021A1C0 00000013 */  mtlo      $zero
/* 4F1664 8021A1C4 00000000 */  nop       
/* 4F1668 8021A1C8 00000043 */  sra       $zero, $zero, 1
/* 4F166C 8021A1CC 00000003 */  sra       $zero, $zero, 0
/* 4F1670 8021A1D0 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F1674 8021A1D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1678 8021A1D8 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F167C 8021A1DC 00000043 */  sra       $zero, $zero, 1
/* 4F1680 8021A1E0 00000003 */  sra       $zero, $zero, 0
/* 4F1684 8021A1E4 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F1688 8021A1E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F168C 8021A1EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1690 8021A1F0 00000002 */  srl       $zero, $zero, 0
/* 4F1694 8021A1F4 00000000 */  nop       
/* 4F1698 8021A1F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F169C 8021A1FC 00000000 */  nop       
/* 4F16A0 8021A200 00000043 */  sra       $zero, $zero, 1
/* 4F16A4 8021A204 00000003 */  sra       $zero, $zero, 0
/* 4F16A8 8021A208 8026DE5C */  lb        $a2, -0x21a4($at)
/* 4F16AC 8021A20C 00000200 */  sll       $zero, $zero, 8
/* 4F16B0 8021A210 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F16B4 8021A214 0000000A */  movz      $zero, $zero, $zero
/* 4F16B8 8021A218 00000002 */  srl       $zero, $zero, 0
/* 4F16BC 8021A21C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F16C0 8021A220 00000000 */  nop       
/* 4F16C4 8021A224 00000004 */  sllv      $zero, $zero, $zero
/* 4F16C8 8021A228 00000001 */  movf      $zero, $zero, $fcc0
/* 4F16CC 8021A22C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F16D0 8021A230 00000013 */  mtlo      $zero
/* 4F16D4 8021A234 00000000 */  nop       
/* 4F16D8 8021A238 00000043 */  sra       $zero, $zero, 1
/* 4F16DC 8021A23C 00000004 */  sllv      $zero, $zero, $zero
/* 4F16E0 8021A240 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F16E4 8021A244 00000200 */  sll       $zero, $zero, 8
/* 4F16E8 8021A248 00000008 */  jr        $zero
/* 4F16EC 8021A24C FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F16F0 8021A250 0000000A */  movz      $zero, $zero, $zero
/* 4F16F4 8021A254 00000002 */  srl       $zero, $zero, 0
/* 4F16F8 8021A258 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F16FC 8021A25C 00000000 */  nop       
/* 4F1700 8021A260 00000004 */  sllv      $zero, $zero, $zero
/* 4F1704 8021A264 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1708 8021A268 00000001 */  movf      $zero, $zero, $fcc0
/* 4F170C 8021A26C 00000013 */  mtlo      $zero
/* 4F1710 8021A270 00000000 */  nop       
/* 4F1714 8021A274 00000003 */  sra       $zero, $zero, 0
/* 4F1718 8021A278 00000001 */  movf      $zero, $zero, $fcc0
/* 4F171C 8021A27C 00000000 */  nop       
/* 4F1720 8021A280 00000043 */  sra       $zero, $zero, 1
/* 4F1724 8021A284 00000004 */  sllv      $zero, $zero, $zero
/* 4F1728 8021A288 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F172C 8021A28C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1730 8021A290 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1734 8021A294 00690006 */  srlv      $zero, $t1, $v1
/* 4F1738 8021A298 00000043 */  sra       $zero, $zero, 1
/* 4F173C 8021A29C 00000003 */  sra       $zero, $zero, 0
/* 4F1740 8021A2A0 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F1744 8021A2A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1748 8021A2A8 00000200 */  sll       $zero, $zero, 8
/* 4F174C 8021A2AC 00000043 */  sra       $zero, $zero, 1
/* 4F1750 8021A2B0 00000002 */  srl       $zero, $zero, 0
/* 4F1754 8021A2B4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F1758 8021A2B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F175C 8021A2BC 00000043 */  sra       $zero, $zero, 1
/* 4F1760 8021A2C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1764 8021A2C4 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F1768 8021A2C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F176C 8021A2CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1770 8021A2D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1774 8021A2D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1778 8021A2D8 00000043 */  sra       $zero, $zero, 1
/* 4F177C 8021A2DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1780 8021A2E0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1784 8021A2E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1788 8021A2E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F178C 8021A2EC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F1790 8021A2F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1794 8021A2F4 00000043 */  sra       $zero, $zero, 1
/* 4F1798 8021A2F8 00000003 */  sra       $zero, $zero, 0
/* 4F179C 8021A2FC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F17A0 8021A300 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F17A4 8021A304 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F17A8 8021A308 00000043 */  sra       $zero, $zero, 1
/* 4F17AC 8021A30C 00000003 */  sra       $zero, $zero, 0
/* 4F17B0 8021A310 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F17B4 8021A314 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F17B8 8021A318 F24A9680 */  scd       $t2, -0x6980($s2)
/* 4F17BC 8021A31C 00000043 */  sra       $zero, $zero, 1
/* 4F17C0 8021A320 00000006 */  srlv      $zero, $zero, $zero
/* 4F17C4 8021A324 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F17C8 8021A328 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F17CC 8021A32C 00000000 */  nop       
/* 4F17D0 8021A330 00000000 */  nop       
/* 4F17D4 8021A334 00000001 */  movf      $zero, $zero, $fcc0
/* 4F17D8 8021A338 00000000 */  nop       
/* 4F17DC 8021A33C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F17E0 8021A340 00000000 */  nop       
/* 4F17E4 8021A344 00000043 */  sra       $zero, $zero, 1
/* 4F17E8 8021A348 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F17EC 8021A34C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F17F0 8021A350 00000001 */  movf      $zero, $zero, $fcc0
/* 4F17F4 8021A354 00000000 */  nop       
/* 4F17F8 8021A358 00000002 */  srl       $zero, $zero, 0
/* 4F17FC 8021A35C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F1800 8021A360 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1804 8021A364 00000000 */  nop       
/* 4F1808 8021A368 00000008 */  jr        $zero
/* 4F180C 8021A36C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1810 8021A370 00000002 */  srl       $zero, $zero, 0
/* 4F1814 8021A374 00000043 */  sra       $zero, $zero, 1
/* 4F1818 8021A378 00000008 */  jr        $zero
/* 4F181C 8021A37C 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F1820 8021A380 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1824 8021A384 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1828 8021A388 08000000 */  j         .L80000000
/* 4F182C 8021A38C 00000000 */   nop      
/* 4F1830 8021A390 00000000 */  nop       
/* 4F1834 8021A394 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1838 8021A398 00000020 */  add       $zero, $zero, $zero
/* 4F183C 8021A39C 00000043 */  sra       $zero, $zero, 1
/* 4F1840 8021A3A0 00000003 */  sra       $zero, $zero, 0
/* 4F1844 8021A3A4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1848 8021A3A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F184C 8021A3AC F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F1850 8021A3B0 00000043 */  sra       $zero, $zero, 1
/* 4F1854 8021A3B4 00000003 */  sra       $zero, $zero, 0
/* 4F1858 8021A3B8 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F185C 8021A3BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1860 8021A3C0 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F1864 8021A3C4 00000043 */  sra       $zero, $zero, 1
/* 4F1868 8021A3C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F186C 8021A3CC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F1870 8021A3D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1874 8021A3D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1878 8021A3D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F187C 8021A3DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1880 8021A3E0 00000043 */  sra       $zero, $zero, 1
/* 4F1884 8021A3E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1888 8021A3E8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F188C 8021A3EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1890 8021A3F0 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F1894 8021A3F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1898 8021A3F8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F189C 8021A3FC 00000043 */  sra       $zero, $zero, 1
/* 4F18A0 8021A400 00000006 */  srlv      $zero, $zero, $zero
/* 4F18A4 8021A404 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F18A8 8021A408 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F18AC 8021A40C 00000000 */  nop       
/* 4F18B0 8021A410 00000000 */  nop       
/* 4F18B4 8021A414 00000001 */  movf      $zero, $zero, $fcc0
/* 4F18B8 8021A418 00000000 */  nop       
/* 4F18BC 8021A41C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F18C0 8021A420 00000000 */  nop       
/* 4F18C4 8021A424 00000043 */  sra       $zero, $zero, 1
/* 4F18C8 8021A428 00000003 */  sra       $zero, $zero, 0
/* 4F18CC 8021A42C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F18D0 8021A430 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F18D4 8021A434 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F18D8 8021A438 00000011 */  mthi      $zero
/* 4F18DC 8021A43C 00000002 */  srl       $zero, $zero, 0
/* 4F18E0 8021A440 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F18E4 8021A444 00080000 */  sll       $zero, $t0, 0
/* 4F18E8 8021A448 00000043 */  sra       $zero, $zero, 1
/* 4F18EC 8021A44C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F18F0 8021A450 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F18F4 8021A454 00000001 */  movf      $zero, $zero, $fcc0
/* 4F18F8 8021A458 00000000 */  nop       
/* 4F18FC 8021A45C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1900 8021A460 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1904 8021A464 00000013 */  mtlo      $zero
/* 4F1908 8021A468 00000000 */  nop       
/* 4F190C 8021A46C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1910 8021A470 00000000 */  nop       
/* 4F1914 8021A474 00000024 */  and       $zero, $zero, $zero
/* 4F1918 8021A478 00000002 */  srl       $zero, $zero, 0
/* 4F191C 8021A47C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1920 8021A480 00000000 */  nop       
/* 4F1924 8021A484 00000043 */  sra       $zero, $zero, 1
/* 4F1928 8021A488 00000003 */  sra       $zero, $zero, 0
/* 4F192C 8021A48C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1930 8021A490 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1934 8021A494 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F1938 8021A498 00000043 */  sra       $zero, $zero, 1
/* 4F193C 8021A49C 00000003 */  sra       $zero, $zero, 0
/* 4F1940 8021A4A0 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F1944 8021A4A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1948 8021A4A8 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F194C 8021A4AC 00000043 */  sra       $zero, $zero, 1
/* 4F1950 8021A4B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1954 8021A4B4 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1958 8021A4B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F195C 8021A4BC 00000082 */  srl       $zero, $zero, 2
/* 4F1960 8021A4C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1964 8021A4C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1968 8021A4C8 00000043 */  sra       $zero, $zero, 1
/* 4F196C 8021A4CC 00000006 */  srlv      $zero, $zero, $zero
/* 4F1970 8021A4D0 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1974 8021A4D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1978 8021A4D8 0000000A */  movz      $zero, $zero, $zero
/* 4F197C 8021A4DC 00000000 */  nop       
/* 4F1980 8021A4E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1984 8021A4E4 00000000 */  nop       
/* 4F1988 8021A4E8 00000056 */  drotrv    $zero, $zero, $zero
/* 4F198C 8021A4EC 00000000 */  nop       
/* 4F1990 8021A4F0 00000043 */  sra       $zero, $zero, 1
/* 4F1994 8021A4F4 00000003 */  sra       $zero, $zero, 0
/* 4F1998 8021A4F8 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F199C 8021A4FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F19A0 8021A500 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F19A4 8021A504 00000011 */  mthi      $zero
/* 4F19A8 8021A508 00000002 */  srl       $zero, $zero, 0
/* 4F19AC 8021A50C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F19B0 8021A510 00080000 */  sll       $zero, $t0, 0
/* 4F19B4 8021A514 00000043 */  sra       $zero, $zero, 1
/* 4F19B8 8021A518 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F19BC 8021A51C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F19C0 8021A520 00000001 */  movf      $zero, $zero, $fcc0
/* 4F19C4 8021A524 00000000 */  nop       
/* 4F19C8 8021A528 00000001 */  movf      $zero, $zero, $fcc0
/* 4F19CC 8021A52C F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F19D0 8021A530 00000013 */  mtlo      $zero
/* 4F19D4 8021A534 00000000 */  nop       
/* 4F19D8 8021A538 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F19DC 8021A53C 00000000 */  nop       
/* 4F19E0 8021A540 00000043 */  sra       $zero, $zero, 1
/* 4F19E4 8021A544 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F19E8 8021A548 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F19EC 8021A54C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F19F0 8021A550 00000000 */  nop       
/* 4F19F4 8021A554 00000000 */  nop       
/* 4F19F8 8021A558 00000000 */  nop       
/* 4F19FC 8021A55C 00000008 */  jr        $zero
/* 4F1A00 8021A560 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1A04 8021A564 0000000F */  sync      
/* 4F1A08 8021A568 00000004 */  sllv      $zero, $zero, $zero
/* 4F1A0C 8021A56C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1A10 8021A570 0000000A */  movz      $zero, $zero, $zero
/* 4F1A14 8021A574 00000003 */  sra       $zero, $zero, 0
/* 4F1A18 8021A578 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1A1C 8021A57C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1A20 8021A580 00000043 */  sra       $zero, $zero, 1
/* 4F1A24 8021A584 00000004 */  sllv      $zero, $zero, $zero
/* 4F1A28 8021A588 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F1A2C 8021A58C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1A30 8021A590 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1A34 8021A594 00690006 */  srlv      $zero, $t1, $v1
/* 4F1A38 8021A598 00000043 */  sra       $zero, $zero, 1
/* 4F1A3C 8021A59C 00000003 */  sra       $zero, $zero, 0
/* 4F1A40 8021A5A0 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1A44 8021A5A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1A48 8021A5A8 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F1A4C 8021A5AC 00000043 */  sra       $zero, $zero, 1
/* 4F1A50 8021A5B0 00000003 */  sra       $zero, $zero, 0
/* 4F1A54 8021A5B4 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F1A58 8021A5B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1A5C 8021A5BC F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F1A60 8021A5C0 00000043 */  sra       $zero, $zero, 1
/* 4F1A64 8021A5C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1A68 8021A5C8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F1A6C 8021A5CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1A70 8021A5D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1A74 8021A5D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1A78 8021A5D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1A7C 8021A5DC 00000043 */  sra       $zero, $zero, 1
/* 4F1A80 8021A5E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1A84 8021A5E4 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1A88 8021A5E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1A8C 8021A5EC 00000087 */  .byte     0x00, 0x00, 0x00, 0x87
/* 4F1A90 8021A5F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1A94 8021A5F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1A98 8021A5F8 00000043 */  sra       $zero, $zero, 1
/* 4F1A9C 8021A5FC 00000006 */  srlv      $zero, $zero, $zero
/* 4F1AA0 8021A600 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1AA4 8021A604 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1AA8 8021A608 00000000 */  nop       
/* 4F1AAC 8021A60C 00000000 */  nop       
/* 4F1AB0 8021A610 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1AB4 8021A614 00000000 */  nop       
/* 4F1AB8 8021A618 00000056 */  drotrv    $zero, $zero, $zero
/* 4F1ABC 8021A61C 00000000 */  nop       
/* 4F1AC0 8021A620 00000043 */  sra       $zero, $zero, 1
/* 4F1AC4 8021A624 00000003 */  sra       $zero, $zero, 0
/* 4F1AC8 8021A628 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F1ACC 8021A62C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1AD0 8021A630 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1AD4 8021A634 00000011 */  mthi      $zero
/* 4F1AD8 8021A638 00000002 */  srl       $zero, $zero, 0
/* 4F1ADC 8021A63C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1AE0 8021A640 00080000 */  sll       $zero, $t0, 0
/* 4F1AE4 8021A644 00000043 */  sra       $zero, $zero, 1
/* 4F1AE8 8021A648 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1AEC 8021A64C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F1AF0 8021A650 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1AF4 8021A654 00000000 */  nop       
/* 4F1AF8 8021A658 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1AFC 8021A65C F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1B00 8021A660 00000013 */  mtlo      $zero
/* 4F1B04 8021A664 00000000 */  nop       
/* 4F1B08 8021A668 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1B0C 8021A66C 00000000 */  nop       
/* 4F1B10 8021A670 00000024 */  and       $zero, $zero, $zero
/* 4F1B14 8021A674 00000002 */  srl       $zero, $zero, 0
/* 4F1B18 8021A678 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1B1C 8021A67C 00000000 */  nop       
/* 4F1B20 8021A680 00000043 */  sra       $zero, $zero, 1
/* 4F1B24 8021A684 00000003 */  sra       $zero, $zero, 0
/* 4F1B28 8021A688 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1B2C 8021A68C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1B30 8021A690 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F1B34 8021A694 00000043 */  sra       $zero, $zero, 1
/* 4F1B38 8021A698 00000003 */  sra       $zero, $zero, 0
/* 4F1B3C 8021A69C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F1B40 8021A6A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1B44 8021A6A4 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F1B48 8021A6A8 00000043 */  sra       $zero, $zero, 1
/* 4F1B4C 8021A6AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1B50 8021A6B0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1B54 8021A6B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1B58 8021A6B8 00000069 */  .byte     0x00, 0x00, 0x00, 0x69
/* 4F1B5C 8021A6BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1B60 8021A6C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1B64 8021A6C4 00000043 */  sra       $zero, $zero, 1
/* 4F1B68 8021A6C8 00000006 */  srlv      $zero, $zero, $zero
/* 4F1B6C 8021A6CC 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1B70 8021A6D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1B74 8021A6D4 0000000A */  movz      $zero, $zero, $zero
/* 4F1B78 8021A6D8 00000000 */  nop       
/* 4F1B7C 8021A6DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1B80 8021A6E0 00000000 */  nop       
/* 4F1B84 8021A6E4 00000056 */  drotrv    $zero, $zero, $zero
/* 4F1B88 8021A6E8 00000000 */  nop       
/* 4F1B8C 8021A6EC 00000043 */  sra       $zero, $zero, 1
/* 4F1B90 8021A6F0 00000003 */  sra       $zero, $zero, 0
/* 4F1B94 8021A6F4 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F1B98 8021A6F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1B9C 8021A6FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1BA0 8021A700 00000011 */  mthi      $zero
/* 4F1BA4 8021A704 00000002 */  srl       $zero, $zero, 0
/* 4F1BA8 8021A708 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1BAC 8021A70C 00080000 */  sll       $zero, $t0, 0
/* 4F1BB0 8021A710 00000043 */  sra       $zero, $zero, 1
/* 4F1BB4 8021A714 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1BB8 8021A718 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F1BBC 8021A71C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1BC0 8021A720 00000000 */  nop       
/* 4F1BC4 8021A724 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1BC8 8021A728 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1BCC 8021A72C 00000013 */  mtlo      $zero
/* 4F1BD0 8021A730 00000000 */  nop       
/* 4F1BD4 8021A734 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1BD8 8021A738 00000000 */  nop       
/* 4F1BDC 8021A73C 00000043 */  sra       $zero, $zero, 1
/* 4F1BE0 8021A740 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1BE4 8021A744 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F1BE8 8021A748 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1BEC 8021A74C 00000000 */  nop       
/* 4F1BF0 8021A750 00000000 */  nop       
/* 4F1BF4 8021A754 00000000 */  nop       
/* 4F1BF8 8021A758 00000008 */  jr        $zero
/* 4F1BFC 8021A75C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1C00 8021A760 0000000F */  sync      
/* 4F1C04 8021A764 00000003 */  sra       $zero, $zero, 0
/* 4F1C08 8021A768 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1C0C 8021A76C 0000000A */  movz      $zero, $zero, $zero
/* 4F1C10 8021A770 00000025 */  or        $zero, $zero, $zero
/* 4F1C14 8021A774 00000002 */  srl       $zero, $zero, 0
/* 4F1C18 8021A778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1C1C 8021A77C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1C20 8021A780 00000025 */  or        $zero, $zero, $zero
/* 4F1C24 8021A784 00000002 */  srl       $zero, $zero, 0
/* 4F1C28 8021A788 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1C2C 8021A78C 00690001 */  movt      $zero, $v1, $fcc2
/* 4F1C30 8021A790 00000046 */  rotrv     $zero, $zero, $zero
/* 4F1C34 8021A794 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1C38 8021A798 8021B41C */  lb        $at, -0x4be4($at)
/* 4F1C3C 8021A79C 00000043 */  sra       $zero, $zero, 1
/* 4F1C40 8021A7A0 00000004 */  sllv      $zero, $zero, $zero
/* 4F1C44 8021A7A4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F1C48 8021A7A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1C4C 8021A7AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1C50 8021A7B0 00680001 */  movf      $zero, $v1, $fcc2
/* 4F1C54 8021A7B4 00000002 */  srl       $zero, $zero, 0
/* 4F1C58 8021A7B8 00000000 */  nop       
/* 4F1C5C 8021A7BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1C60 8021A7C0 00000000 */  nop       
/* 4F1C64 8021A7C4 00000043 */  sra       $zero, $zero, 1
/* 4F1C68 8021A7C8 00000004 */  sllv      $zero, $zero, $zero
/* 4F1C6C 8021A7CC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F1C70 8021A7D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1C74 8021A7D4 00000008 */  jr        $zero
/* 4F1C78 8021A7D8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1C7C 8021A7DC 00000043 */  sra       $zero, $zero, 1
/* 4F1C80 8021A7E0 00000003 */  sra       $zero, $zero, 0
/* 4F1C84 8021A7E4 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F1C88 8021A7E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1C8C 8021A7EC 00000000 */  nop       
/* 4F1C90 8021A7F0 00000043 */  sra       $zero, $zero, 1
/* 4F1C94 8021A7F4 00000003 */  sra       $zero, $zero, 0
/* 4F1C98 8021A7F8 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F1C9C 8021A7FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1CA0 8021A800 00000000 */  nop       
/* 4F1CA4 8021A804 00000043 */  sra       $zero, $zero, 1
/* 4F1CA8 8021A808 00000003 */  sra       $zero, $zero, 0
/* 4F1CAC 8021A80C 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F1CB0 8021A810 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1CB4 8021A814 00000000 */  nop       
/* 4F1CB8 8021A818 00000043 */  sra       $zero, $zero, 1
/* 4F1CBC 8021A81C 00000002 */  srl       $zero, $zero, 0
/* 4F1CC0 8021A820 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F1CC4 8021A824 0000003F */  dsra32    $zero, $zero, 0
/* 4F1CC8 8021A828 00000043 */  sra       $zero, $zero, 1
/* 4F1CCC 8021A82C 00000002 */  srl       $zero, $zero, 0
/* 4F1CD0 8021A830 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F1CD4 8021A834 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1CD8 8021A838 00000043 */  sra       $zero, $zero, 1
/* 4F1CDC 8021A83C 00000004 */  sllv      $zero, $zero, $zero
/* 4F1CE0 8021A840 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4F1CE4 8021A844 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F1CE8 8021A848 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1CEC 8021A84C 00000000 */  nop       
/* 4F1CF0 8021A850 00000043 */  sra       $zero, $zero, 1
/* 4F1CF4 8021A854 00000003 */  sra       $zero, $zero, 0
/* 4F1CF8 8021A858 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1CFC 8021A85C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1D00 8021A860 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1D04 8021A864 00000043 */  sra       $zero, $zero, 1
/* 4F1D08 8021A868 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1D0C 8021A86C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F1D10 8021A870 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1D14 8021A874 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1D18 8021A878 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1D1C 8021A87C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1D20 8021A880 00000024 */  and       $zero, $zero, $zero
/* 4F1D24 8021A884 00000002 */  srl       $zero, $zero, 0
/* 4F1D28 8021A888 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1D2C 8021A88C 00000000 */  nop       
/* 4F1D30 8021A890 00000027 */  not       $zero, $zero
/* 4F1D34 8021A894 00000002 */  srl       $zero, $zero, 0
/* 4F1D38 8021A898 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1D3C 8021A89C 0000002D */  daddu     $zero, $zero, $zero
/* 4F1D40 8021A8A0 00000043 */  sra       $zero, $zero, 1
/* 4F1D44 8021A8A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1D48 8021A8A8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1D4C 8021A8AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1D50 8021A8B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1D54 8021A8B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1D58 8021A8B8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1D5C 8021A8BC 00000043 */  sra       $zero, $zero, 1
/* 4F1D60 8021A8C0 00000006 */  srlv      $zero, $zero, $zero
/* 4F1D64 8021A8C4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1D68 8021A8C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1D6C 8021A8CC 0000000F */  sync      
/* 4F1D70 8021A8D0 00000000 */  nop       
/* 4F1D74 8021A8D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1D78 8021A8D8 00000000 */  nop       
/* 4F1D7C 8021A8DC 00000043 */  sra       $zero, $zero, 1
/* 4F1D80 8021A8E0 00000003 */  sra       $zero, $zero, 0
/* 4F1D84 8021A8E4 8025385C */  lb        $a1, 0x385c($at)
/* 4F1D88 8021A8E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1D8C 8021A8EC 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F1D90 8021A8F0 00000056 */  drotrv    $zero, $zero, $zero
/* 4F1D94 8021A8F4 00000000 */  nop       
/* 4F1D98 8021A8F8 00000043 */  sra       $zero, $zero, 1
/* 4F1D9C 8021A8FC 00000003 */  sra       $zero, $zero, 0
/* 4F1DA0 8021A900 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F1DA4 8021A904 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1DA8 8021A908 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1DAC 8021A90C 00000011 */  mthi      $zero
/* 4F1DB0 8021A910 00000002 */  srl       $zero, $zero, 0
/* 4F1DB4 8021A914 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1DB8 8021A918 00080000 */  sll       $zero, $t0, 0
/* 4F1DBC 8021A91C 00000043 */  sra       $zero, $zero, 1
/* 4F1DC0 8021A920 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1DC4 8021A924 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F1DC8 8021A928 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1DCC 8021A92C 00000000 */  nop       
/* 4F1DD0 8021A930 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1DD4 8021A934 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1DD8 8021A938 00000013 */  mtlo      $zero
/* 4F1DDC 8021A93C 00000000 */  nop       
/* 4F1DE0 8021A940 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1DE4 8021A944 00000000 */  nop       
/* 4F1DE8 8021A948 00000043 */  sra       $zero, $zero, 1
/* 4F1DEC 8021A94C 00000004 */  sllv      $zero, $zero, $zero
/* 4F1DF0 8021A950 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F1DF4 8021A954 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1DF8 8021A958 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1DFC 8021A95C 00690005 */  lsa       $zero, $v1, $t1, 1
/* 4F1E00 8021A960 00000008 */  jr        $zero
/* 4F1E04 8021A964 00000001 */   movf     $zero, $zero, $fcc0
/* 4F1E08 8021A968 0000000F */  sync      
/* 4F1E0C 8021A96C 00000043 */  sra       $zero, $zero, 1
/* 4F1E10 8021A970 00000003 */  sra       $zero, $zero, 0
/* 4F1E14 8021A974 8025385C */  lb        $a1, 0x385c($at)
/* 4F1E18 8021A978 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1E1C 8021A97C 0000010F */  sync      4
/* 4F1E20 8021A980 00000043 */  sra       $zero, $zero, 1
/* 4F1E24 8021A984 00000007 */  srav      $zero, $zero, $zero
/* 4F1E28 8021A988 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F1E2C 8021A98C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1E30 8021A990 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1E34 8021A994 00000000 */  nop       
/* 4F1E38 8021A998 00000000 */  nop       
/* 4F1E3C 8021A99C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1E40 8021A9A0 00000010 */  mfhi      $zero
/* 4F1E44 8021A9A4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F1E48 8021A9A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1E4C 8021A9AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1E50 8021A9B0 0000001D */  dmultu    $zero, $zero
/* 4F1E54 8021A9B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1E58 8021A9B8 00000006 */  srlv      $zero, $zero, $zero
/* 4F1E5C 8021A9BC 0000001D */  dmultu    $zero, $zero
/* 4F1E60 8021A9C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1E64 8021A9C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1E68 8021A9C8 00000024 */  and       $zero, $zero, $zero
/* 4F1E6C 8021A9CC 00000002 */  srl       $zero, $zero, 0
/* 4F1E70 8021A9D0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F1E74 8021A9D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1E78 8021A9D8 00000043 */  sra       $zero, $zero, 1
/* 4F1E7C 8021A9DC 00000002 */  srl       $zero, $zero, 0
/* 4F1E80 8021A9E0 802D6150 */  lb        $t5, 0x6150($at)
/* 4F1E84 8021A9E4 0000010F */  sync      4
/* 4F1E88 8021A9E8 00000043 */  sra       $zero, $zero, 1
/* 4F1E8C 8021A9EC 00000004 */  sllv      $zero, $zero, $zero
/* 4F1E90 8021A9F0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F1E94 8021A9F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1E98 8021A9F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1E9C 8021A9FC 00690001 */  movt      $zero, $v1, $fcc2
/* 4F1EA0 8021AA00 00000043 */  sra       $zero, $zero, 1
/* 4F1EA4 8021AA04 00000002 */  srl       $zero, $zero, 0
/* 4F1EA8 8021AA08 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F1EAC 8021AA0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1EB0 8021AA10 00000043 */  sra       $zero, $zero, 1
/* 4F1EB4 8021AA14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1EB8 8021AA18 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F1EBC 8021AA1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1EC0 8021AA20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1EC4 8021AA24 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1EC8 8021AA28 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1ECC 8021AA2C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F1ED0 8021AA30 00000002 */  srl       $zero, $zero, 0
/* 4F1ED4 8021AA34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1ED8 8021AA38 00000014 */  dsllv     $zero, $zero, $zero
/* 4F1EDC 8021AA3C 00000024 */  and       $zero, $zero, $zero
/* 4F1EE0 8021AA40 00000002 */  srl       $zero, $zero, 0
/* 4F1EE4 8021AA44 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1EE8 8021AA48 00000000 */  nop       
/* 4F1EEC 8021AA4C 00000043 */  sra       $zero, $zero, 1
/* 4F1EF0 8021AA50 00000003 */  sra       $zero, $zero, 0
/* 4F1EF4 8021AA54 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1EF8 8021AA58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1EFC 8021AA5C F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F1F00 8021AA60 00000043 */  sra       $zero, $zero, 1
/* 4F1F04 8021AA64 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1F08 8021AA68 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1F0C 8021AA6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1F10 8021AA70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1F14 8021AA74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1F18 8021AA78 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1F1C 8021AA7C 00000043 */  sra       $zero, $zero, 1
/* 4F1F20 8021AA80 00000006 */  srlv      $zero, $zero, $zero
/* 4F1F24 8021AA84 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F1F28 8021AA88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1F2C 8021AA8C 0000000A */  movz      $zero, $zero, $zero
/* 4F1F30 8021AA90 00000000 */  nop       
/* 4F1F34 8021AA94 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1F38 8021AA98 00000000 */  nop       
/* 4F1F3C 8021AA9C 00000043 */  sra       $zero, $zero, 1
/* 4F1F40 8021AAA0 00000003 */  sra       $zero, $zero, 0
/* 4F1F44 8021AAA4 8025385C */  lb        $a1, 0x385c($at)
/* 4F1F48 8021AAA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1F4C 8021AAAC 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F1F50 8021AAB0 00000056 */  drotrv    $zero, $zero, $zero
/* 4F1F54 8021AAB4 00000000 */  nop       
/* 4F1F58 8021AAB8 00000043 */  sra       $zero, $zero, 1
/* 4F1F5C 8021AABC 00000003 */  sra       $zero, $zero, 0
/* 4F1F60 8021AAC0 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F1F64 8021AAC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1F68 8021AAC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1F6C 8021AACC 00000011 */  mthi      $zero
/* 4F1F70 8021AAD0 00000002 */  srl       $zero, $zero, 0
/* 4F1F74 8021AAD4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1F78 8021AAD8 00080000 */  sll       $zero, $t0, 0
/* 4F1F7C 8021AADC 00000043 */  sra       $zero, $zero, 1
/* 4F1F80 8021AAE0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1F84 8021AAE4 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F1F88 8021AAE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1F8C 8021AAEC 00000000 */  nop       
/* 4F1F90 8021AAF0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F1F94 8021AAF4 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F1F98 8021AAF8 00000013 */  mtlo      $zero
/* 4F1F9C 8021AAFC 00000000 */  nop       
/* 4F1FA0 8021AB00 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F1FA4 8021AB04 00000000 */  nop       
/* 4F1FA8 8021AB08 00000043 */  sra       $zero, $zero, 1
/* 4F1FAC 8021AB0C 00000003 */  sra       $zero, $zero, 0
/* 4F1FB0 8021AB10 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F1FB4 8021AB14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1FB8 8021AB18 F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F1FBC 8021AB1C 00000043 */  sra       $zero, $zero, 1
/* 4F1FC0 8021AB20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1FC4 8021AB24 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F1FC8 8021AB28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1FCC 8021AB2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1FD0 8021AB30 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F1FD4 8021AB34 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F1FD8 8021AB38 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F1FDC 8021AB3C 00000002 */  srl       $zero, $zero, 0
/* 4F1FE0 8021AB40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1FE4 8021AB44 00000019 */  multu     $zero, $zero
/* 4F1FE8 8021AB48 00000043 */  sra       $zero, $zero, 1
/* 4F1FEC 8021AB4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F1FF0 8021AB50 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F1FF4 8021AB54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F1FF8 8021AB58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F1FFC 8021AB5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2000 8021AB60 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2004 8021AB64 00000043 */  sra       $zero, $zero, 1
/* 4F2008 8021AB68 00000006 */  srlv      $zero, $zero, $zero
/* 4F200C 8021AB6C 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2010 8021AB70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2014 8021AB74 00000006 */  srlv      $zero, $zero, $zero
/* 4F2018 8021AB78 00000000 */  nop       
/* 4F201C 8021AB7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2020 8021AB80 00000000 */  nop       
/* 4F2024 8021AB84 00000043 */  sra       $zero, $zero, 1
/* 4F2028 8021AB88 00000003 */  sra       $zero, $zero, 0
/* 4F202C 8021AB8C 8025385C */  lb        $a1, 0x385c($at)
/* 4F2030 8021AB90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2034 8021AB94 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2038 8021AB98 00000056 */  drotrv    $zero, $zero, $zero
/* 4F203C 8021AB9C 00000000 */  nop       
/* 4F2040 8021ABA0 00000043 */  sra       $zero, $zero, 1
/* 4F2044 8021ABA4 00000003 */  sra       $zero, $zero, 0
/* 4F2048 8021ABA8 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F204C 8021ABAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2050 8021ABB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2054 8021ABB4 00000011 */  mthi      $zero
/* 4F2058 8021ABB8 00000002 */  srl       $zero, $zero, 0
/* 4F205C 8021ABBC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2060 8021ABC0 00080000 */  sll       $zero, $t0, 0
/* 4F2064 8021ABC4 00000043 */  sra       $zero, $zero, 1
/* 4F2068 8021ABC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F206C 8021ABCC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2070 8021ABD0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2074 8021ABD4 00000000 */  nop       
/* 4F2078 8021ABD8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F207C 8021ABDC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2080 8021ABE0 00000013 */  mtlo      $zero
/* 4F2084 8021ABE4 00000000 */  nop       
/* 4F2088 8021ABE8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F208C 8021ABEC 00000000 */  nop       
/* 4F2090 8021ABF0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F2094 8021ABF4 00000002 */  srl       $zero, $zero, 0
/* 4F2098 8021ABF8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F209C 8021ABFC 0000000F */  sync      
/* 4F20A0 8021AC00 00000043 */  sra       $zero, $zero, 1
/* 4F20A4 8021AC04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F20A8 8021AC08 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F20AC 8021AC0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F20B0 8021AC10 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F20B4 8021AC14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F20B8 8021AC18 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F20BC 8021AC1C 00000043 */  sra       $zero, $zero, 1
/* 4F20C0 8021AC20 00000006 */  srlv      $zero, $zero, $zero
/* 4F20C4 8021AC24 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F20C8 8021AC28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F20CC 8021AC2C 00000004 */  sllv      $zero, $zero, $zero
/* 4F20D0 8021AC30 00000000 */  nop       
/* 4F20D4 8021AC34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F20D8 8021AC38 00000000 */  nop       
/* 4F20DC 8021AC3C 00000043 */  sra       $zero, $zero, 1
/* 4F20E0 8021AC40 00000003 */  sra       $zero, $zero, 0
/* 4F20E4 8021AC44 8025385C */  lb        $a1, 0x385c($at)
/* 4F20E8 8021AC48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F20EC 8021AC4C 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F20F0 8021AC50 00000056 */  drotrv    $zero, $zero, $zero
/* 4F20F4 8021AC54 00000000 */  nop       
/* 4F20F8 8021AC58 00000043 */  sra       $zero, $zero, 1
/* 4F20FC 8021AC5C 00000003 */  sra       $zero, $zero, 0
/* 4F2100 8021AC60 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2104 8021AC64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2108 8021AC68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F210C 8021AC6C 00000011 */  mthi      $zero
/* 4F2110 8021AC70 00000002 */  srl       $zero, $zero, 0
/* 4F2114 8021AC74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2118 8021AC78 00080000 */  sll       $zero, $t0, 0
/* 4F211C 8021AC7C 00000043 */  sra       $zero, $zero, 1
/* 4F2120 8021AC80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2124 8021AC84 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2128 8021AC88 00000001 */  movf      $zero, $zero, $fcc0
/* 4F212C 8021AC8C 00000000 */  nop       
/* 4F2130 8021AC90 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2134 8021AC94 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2138 8021AC98 00000013 */  mtlo      $zero
/* 4F213C 8021AC9C 00000000 */  nop       
/* 4F2140 8021ACA0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2144 8021ACA4 00000000 */  nop       
/* 4F2148 8021ACA8 00000043 */  sra       $zero, $zero, 1
/* 4F214C 8021ACAC 00000004 */  sllv      $zero, $zero, $zero
/* 4F2150 8021ACB0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F2154 8021ACB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2158 8021ACB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F215C 8021ACBC 00690004 */  sllv      $zero, $t1, $v1
/* 4F2160 8021ACC0 00000008 */  jr        $zero
/* 4F2164 8021ACC4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F2168 8021ACC8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F216C 8021ACCC 0000000A */  movz      $zero, $zero, $zero
/* 4F2170 8021ACD0 00000002 */  srl       $zero, $zero, 0
/* 4F2174 8021ACD4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F2178 8021ACD8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F217C 8021ACDC 00000043 */  sra       $zero, $zero, 1
/* 4F2180 8021ACE0 00000007 */  srav      $zero, $zero, $zero
/* 4F2184 8021ACE4 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F2188 8021ACE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F218C 8021ACEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2190 8021ACF0 80000000 */  lb        $zero, ($zero)
/* 4F2194 8021ACF4 00000000 */  nop       
/* 4F2198 8021ACF8 00000000 */  nop       
/* 4F219C 8021ACFC 00000000 */  nop       
/* 4F21A0 8021AD00 00000013 */  mtlo      $zero
/* 4F21A4 8021AD04 00000000 */  nop       
/* 4F21A8 8021AD08 00000043 */  sra       $zero, $zero, 1
/* 4F21AC 8021AD0C 00000002 */  srl       $zero, $zero, 0
/* 4F21B0 8021AD10 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F21B4 8021AD14 00000002 */  srl       $zero, $zero, 0
/* 4F21B8 8021AD18 00000043 */  sra       $zero, $zero, 1
/* 4F21BC 8021AD1C 00000002 */  srl       $zero, $zero, 0
/* 4F21C0 8021AD20 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F21C4 8021AD24 00000014 */  dsllv     $zero, $zero, $zero
/* 4F21C8 8021AD28 00000043 */  sra       $zero, $zero, 1
/* 4F21CC 8021AD2C 00000003 */  sra       $zero, $zero, 0
/* 4F21D0 8021AD30 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F21D4 8021AD34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F21D8 8021AD38 000000B4 */  teq       $zero, $zero, 2
/* 4F21DC 8021AD3C 00000043 */  sra       $zero, $zero, 1
/* 4F21E0 8021AD40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F21E4 8021AD44 8026EE88 */  lb        $a2, -0x1178($at)
/* 4F21E8 8021AD48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F21EC 8021AD4C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F21F0 8021AD50 00000000 */  nop       
/* 4F21F4 8021AD54 00000002 */  srl       $zero, $zero, 0
/* 4F21F8 8021AD58 00000025 */  or        $zero, $zero, $zero
/* 4F21FC 8021AD5C 00000002 */  srl       $zero, $zero, 0
/* 4F2200 8021AD60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2204 8021AD64 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2208 8021AD68 00000025 */  or        $zero, $zero, $zero
/* 4F220C 8021AD6C 00000002 */  srl       $zero, $zero, 0
/* 4F2210 8021AD70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2214 8021AD74 00690001 */  movt      $zero, $v1, $fcc2
/* 4F2218 8021AD78 00000046 */  rotrv     $zero, $zero, $zero
/* 4F221C 8021AD7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2220 8021AD80 8021B41C */  lb        $at, -0x4be4($at)
/* 4F2224 8021AD84 00000043 */  sra       $zero, $zero, 1
/* 4F2228 8021AD88 00000004 */  sllv      $zero, $zero, $zero
/* 4F222C 8021AD8C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F2230 8021AD90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2234 8021AD94 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2238 8021AD98 00690001 */  movt      $zero, $v1, $fcc2
/* 4F223C 8021AD9C 00000043 */  sra       $zero, $zero, 1
/* 4F2240 8021ADA0 00000002 */  srl       $zero, $zero, 0
/* 4F2244 8021ADA4 8026D664 */  lb        $a2, -0x299c($at)
/* 4F2248 8021ADA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F224C 8021ADAC 00000043 */  sra       $zero, $zero, 1
/* 4F2250 8021ADB0 00000004 */  sllv      $zero, $zero, $zero
/* 4F2254 8021ADB4 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4F2258 8021ADB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F225C 8021ADBC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2260 8021ADC0 00000000 */  nop       
/* 4F2264 8021ADC4 00000043 */  sra       $zero, $zero, 1
/* 4F2268 8021ADC8 00000003 */  sra       $zero, $zero, 0
/* 4F226C 8021ADCC 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F2270 8021ADD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2274 8021ADD4 00000000 */  nop       
/* 4F2278 8021ADD8 00000043 */  sra       $zero, $zero, 1
/* 4F227C 8021ADDC 00000004 */  sllv      $zero, $zero, $zero
/* 4F2280 8021ADE0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F2284 8021ADE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2288 8021ADE8 00000008 */  jr        $zero
/* 4F228C 8021ADEC 00000000 */   nop      
/* 4F2290 8021ADF0 00000043 */  sra       $zero, $zero, 1
/* 4F2294 8021ADF4 00000003 */  sra       $zero, $zero, 0
/* 4F2298 8021ADF8 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F229C 8021ADFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F22A0 8021AE00 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F22A4 8021AE04 00000002 */  srl       $zero, $zero, 0
/* 4F22A8 8021AE08 00000000 */  nop       
/* 4F22AC 8021AE0C 00000020 */  add       $zero, $zero, $zero
/* 4F22B0 8021AE10 00000000 */  nop       
/* 4F22B4 8021AE14 00000023 */  negu      $zero, $zero
/* 4F22B8 8021AE18 00000000 */  nop       
/* 4F22BC 8021AE1C 00000043 */  sra       $zero, $zero, 1
/* 4F22C0 8021AE20 00000004 */  sllv      $zero, $zero, $zero
/* 4F22C4 8021AE24 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F22C8 8021AE28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F22CC 8021AE2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F22D0 8021AE30 00690001 */  movt      $zero, $v1, $fcc2
/* 4F22D4 8021AE34 00000043 */  sra       $zero, $zero, 1
/* 4F22D8 8021AE38 00000002 */  srl       $zero, $zero, 0
/* 4F22DC 8021AE3C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F22E0 8021AE40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F22E4 8021AE44 00000043 */  sra       $zero, $zero, 1
/* 4F22E8 8021AE48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F22EC 8021AE4C 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F22F0 8021AE50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F22F4 8021AE54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F22F8 8021AE58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F22FC 8021AE5C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2300 8021AE60 00000043 */  sra       $zero, $zero, 1
/* 4F2304 8021AE64 00000003 */  sra       $zero, $zero, 0
/* 4F2308 8021AE68 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F230C 8021AE6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2310 8021AE70 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F2314 8021AE74 00000010 */  mfhi      $zero
/* 4F2318 8021AE78 00000002 */  srl       $zero, $zero, 0
/* 4F231C 8021AE7C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F2320 8021AE80 00080000 */  sll       $zero, $t0, 0
/* 4F2324 8021AE84 00000027 */  not       $zero, $zero
/* 4F2328 8021AE88 00000002 */  srl       $zero, $zero, 0
/* 4F232C 8021AE8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2330 8021AE90 00000004 */  sllv      $zero, $zero, $zero
/* 4F2334 8021AE94 00000012 */  mflo      $zero
/* 4F2338 8021AE98 00000000 */  nop       
/* 4F233C 8021AE9C 00000027 */  not       $zero, $zero
/* 4F2340 8021AEA0 00000002 */  srl       $zero, $zero, 0
/* 4F2344 8021AEA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2348 8021AEA8 0000000A */  movz      $zero, $zero, $zero
/* 4F234C 8021AEAC 00000013 */  mtlo      $zero
/* 4F2350 8021AEB0 00000000 */  nop       
/* 4F2354 8021AEB4 00000024 */  and       $zero, $zero, $zero
/* 4F2358 8021AEB8 00000002 */  srl       $zero, $zero, 0
/* 4F235C 8021AEBC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2360 8021AEC0 0000001B */  divu      $zero, $zero, $zero
/* 4F2364 8021AEC4 00000043 */  sra       $zero, $zero, 1
/* 4F2368 8021AEC8 00000003 */  sra       $zero, $zero, 0
/* 4F236C 8021AECC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F2370 8021AED0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2374 8021AED4 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F2378 8021AED8 00000043 */  sra       $zero, $zero, 1
/* 4F237C 8021AEDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2380 8021AEE0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2384 8021AEE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2388 8021AEE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F238C 8021AEEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2390 8021AEF0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2394 8021AEF4 00000043 */  sra       $zero, $zero, 1
/* 4F2398 8021AEF8 00000006 */  srlv      $zero, $zero, $zero
/* 4F239C 8021AEFC 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F23A0 8021AF00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F23A4 8021AF04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F23A8 8021AF08 00000000 */  nop       
/* 4F23AC 8021AF0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F23B0 8021AF10 00000000 */  nop       
/* 4F23B4 8021AF14 00000008 */  jr        $zero
/* 4F23B8 8021AF18 00000001 */   movf     $zero, $zero, $fcc0
/* 4F23BC 8021AF1C 00000002 */  srl       $zero, $zero, 0
/* 4F23C0 8021AF20 00000043 */  sra       $zero, $zero, 1
/* 4F23C4 8021AF24 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F23C8 8021AF28 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F23CC 8021AF2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F23D0 8021AF30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F23D4 8021AF34 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F23D8 8021AF38 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F23DC 8021AF3C 00000043 */  sra       $zero, $zero, 1
/* 4F23E0 8021AF40 00000006 */  srlv      $zero, $zero, $zero
/* 4F23E4 8021AF44 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F23E8 8021AF48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F23EC 8021AF4C 00000002 */  srl       $zero, $zero, 0
/* 4F23F0 8021AF50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F23F4 8021AF54 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F23F8 8021AF58 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F23FC 8021AF5C 00000043 */  sra       $zero, $zero, 1
/* 4F2400 8021AF60 00000008 */  jr        $zero
/* 4F2404 8021AF64 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F2408 8021AF68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F240C 8021AF6C FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F2410 8021AF70 00000000 */  nop       
/* 4F2414 8021AF74 00000000 */  nop       
/* 4F2418 8021AF78 00000000 */  nop       
/* 4F241C 8021AF7C 00000003 */  sra       $zero, $zero, 0
/* 4F2420 8021AF80 00000020 */  add       $zero, $zero, $zero
/* 4F2424 8021AF84 00000014 */  dsllv     $zero, $zero, $zero
/* 4F2428 8021AF88 00000001 */  movf      $zero, $zero, $fcc0
/* 4F242C 8021AF8C FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F2430 8021AF90 0000001C */  dmult     $zero, $zero
/* 4F2434 8021AF94 00000000 */  nop       
/* 4F2438 8021AF98 00000043 */  sra       $zero, $zero, 1
/* 4F243C 8021AF9C 00000002 */  srl       $zero, $zero, 0
/* 4F2440 8021AFA0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F2444 8021AFA4 00000002 */  srl       $zero, $zero, 0
/* 4F2448 8021AFA8 00000043 */  sra       $zero, $zero, 1
/* 4F244C 8021AFAC 00000002 */  srl       $zero, $zero, 0
/* 4F2450 8021AFB0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F2454 8021AFB4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F2458 8021AFB8 00000043 */  sra       $zero, $zero, 1
/* 4F245C 8021AFBC 00000004 */  sllv      $zero, $zero, $zero
/* 4F2460 8021AFC0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F2464 8021AFC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2468 8021AFC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F246C 8021AFCC 00690004 */  sllv      $zero, $t1, $v1
/* 4F2470 8021AFD0 00000043 */  sra       $zero, $zero, 1
/* 4F2474 8021AFD4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2478 8021AFD8 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F247C 8021AFDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2480 8021AFE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2484 8021AFE4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2488 8021AFE8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F248C 8021AFEC 00000027 */  not       $zero, $zero
/* 4F2490 8021AFF0 00000002 */  srl       $zero, $zero, 0
/* 4F2494 8021AFF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2498 8021AFF8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F249C 8021AFFC 00000024 */  and       $zero, $zero, $zero
/* 4F24A0 8021B000 00000002 */  srl       $zero, $zero, 0
/* 4F24A4 8021B004 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F24A8 8021B008 00000000 */  nop       
/* 4F24AC 8021B00C 00000043 */  sra       $zero, $zero, 1
/* 4F24B0 8021B010 00000003 */  sra       $zero, $zero, 0
/* 4F24B4 8021B014 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F24B8 8021B018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F24BC 8021B01C F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F24C0 8021B020 00000043 */  sra       $zero, $zero, 1
/* 4F24C4 8021B024 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F24C8 8021B028 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F24CC 8021B02C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F24D0 8021B030 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F24D4 8021B034 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F24D8 8021B038 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F24DC 8021B03C 00000043 */  sra       $zero, $zero, 1
/* 4F24E0 8021B040 00000006 */  srlv      $zero, $zero, $zero
/* 4F24E4 8021B044 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F24E8 8021B048 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F24EC 8021B04C 0000000A */  movz      $zero, $zero, $zero
/* 4F24F0 8021B050 00000000 */  nop       
/* 4F24F4 8021B054 00000001 */  movf      $zero, $zero, $fcc0
/* 4F24F8 8021B058 00000000 */  nop       
/* 4F24FC 8021B05C 00000043 */  sra       $zero, $zero, 1
/* 4F2500 8021B060 00000003 */  sra       $zero, $zero, 0
/* 4F2504 8021B064 8025385C */  lb        $a1, 0x385c($at)
/* 4F2508 8021B068 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F250C 8021B06C 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2510 8021B070 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2514 8021B074 00000000 */  nop       
/* 4F2518 8021B078 00000043 */  sra       $zero, $zero, 1
/* 4F251C 8021B07C 00000003 */  sra       $zero, $zero, 0
/* 4F2520 8021B080 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2524 8021B084 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2528 8021B088 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F252C 8021B08C 00000011 */  mthi      $zero
/* 4F2530 8021B090 00000002 */  srl       $zero, $zero, 0
/* 4F2534 8021B094 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2538 8021B098 00080000 */  sll       $zero, $t0, 0
/* 4F253C 8021B09C 00000043 */  sra       $zero, $zero, 1
/* 4F2540 8021B0A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2544 8021B0A4 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2548 8021B0A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F254C 8021B0AC 00000000 */  nop       
/* 4F2550 8021B0B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2554 8021B0B4 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2558 8021B0B8 00000013 */  mtlo      $zero
/* 4F255C 8021B0BC 00000000 */  nop       
/* 4F2560 8021B0C0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2564 8021B0C4 00000000 */  nop       
/* 4F2568 8021B0C8 00000027 */  not       $zero, $zero
/* 4F256C 8021B0CC 00000002 */  srl       $zero, $zero, 0
/* 4F2570 8021B0D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2574 8021B0D4 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2578 8021B0D8 00000043 */  sra       $zero, $zero, 1
/* 4F257C 8021B0DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2580 8021B0E0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2584 8021B0E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2588 8021B0E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F258C 8021B0EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2590 8021B0F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2594 8021B0F4 00000043 */  sra       $zero, $zero, 1
/* 4F2598 8021B0F8 00000006 */  srlv      $zero, $zero, $zero
/* 4F259C 8021B0FC 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F25A0 8021B100 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F25A4 8021B104 00000008 */  jr        $zero
/* 4F25A8 8021B108 00000000 */   nop      
/* 4F25AC 8021B10C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F25B0 8021B110 00000000 */  nop       
/* 4F25B4 8021B114 00000043 */  sra       $zero, $zero, 1
/* 4F25B8 8021B118 00000003 */  sra       $zero, $zero, 0
/* 4F25BC 8021B11C 8025385C */  lb        $a1, 0x385c($at)
/* 4F25C0 8021B120 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F25C4 8021B124 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F25C8 8021B128 00000056 */  drotrv    $zero, $zero, $zero
/* 4F25CC 8021B12C 00000000 */  nop       
/* 4F25D0 8021B130 00000043 */  sra       $zero, $zero, 1
/* 4F25D4 8021B134 00000003 */  sra       $zero, $zero, 0
/* 4F25D8 8021B138 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F25DC 8021B13C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F25E0 8021B140 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F25E4 8021B144 00000011 */  mthi      $zero
/* 4F25E8 8021B148 00000002 */  srl       $zero, $zero, 0
/* 4F25EC 8021B14C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F25F0 8021B150 00080000 */  sll       $zero, $t0, 0
/* 4F25F4 8021B154 00000043 */  sra       $zero, $zero, 1
/* 4F25F8 8021B158 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F25FC 8021B15C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2600 8021B160 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2604 8021B164 00000000 */  nop       
/* 4F2608 8021B168 00000001 */  movf      $zero, $zero, $fcc0
/* 4F260C 8021B16C F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2610 8021B170 00000013 */  mtlo      $zero
/* 4F2614 8021B174 00000000 */  nop       
/* 4F2618 8021B178 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F261C 8021B17C 00000000 */  nop       
/* 4F2620 8021B180 00000027 */  not       $zero, $zero
/* 4F2624 8021B184 00000002 */  srl       $zero, $zero, 0
/* 4F2628 8021B188 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F262C 8021B18C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F2630 8021B190 00000043 */  sra       $zero, $zero, 1
/* 4F2634 8021B194 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2638 8021B198 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F263C 8021B19C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2640 8021B1A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2644 8021B1A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2648 8021B1A8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F264C 8021B1AC 00000043 */  sra       $zero, $zero, 1
/* 4F2650 8021B1B0 00000006 */  srlv      $zero, $zero, $zero
/* 4F2654 8021B1B4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2658 8021B1B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F265C 8021B1BC 00000006 */  srlv      $zero, $zero, $zero
/* 4F2660 8021B1C0 00000000 */  nop       
/* 4F2664 8021B1C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2668 8021B1C8 00000000 */  nop       
/* 4F266C 8021B1CC 00000043 */  sra       $zero, $zero, 1
/* 4F2670 8021B1D0 00000003 */  sra       $zero, $zero, 0
/* 4F2674 8021B1D4 8025385C */  lb        $a1, 0x385c($at)
/* 4F2678 8021B1D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F267C 8021B1DC 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2680 8021B1E0 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2684 8021B1E4 00000000 */  nop       
/* 4F2688 8021B1E8 00000043 */  sra       $zero, $zero, 1
/* 4F268C 8021B1EC 00000003 */  sra       $zero, $zero, 0
/* 4F2690 8021B1F0 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2694 8021B1F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2698 8021B1F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F269C 8021B1FC 00000011 */  mthi      $zero
/* 4F26A0 8021B200 00000002 */  srl       $zero, $zero, 0
/* 4F26A4 8021B204 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F26A8 8021B208 00080000 */  sll       $zero, $t0, 0
/* 4F26AC 8021B20C 00000043 */  sra       $zero, $zero, 1
/* 4F26B0 8021B210 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F26B4 8021B214 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F26B8 8021B218 00000001 */  movf      $zero, $zero, $fcc0
/* 4F26BC 8021B21C 00000000 */  nop       
/* 4F26C0 8021B220 00000001 */  movf      $zero, $zero, $fcc0
/* 4F26C4 8021B224 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F26C8 8021B228 00000013 */  mtlo      $zero
/* 4F26CC 8021B22C 00000000 */  nop       
/* 4F26D0 8021B230 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F26D4 8021B234 00000000 */  nop       
/* 4F26D8 8021B238 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F26DC 8021B23C 00000002 */  srl       $zero, $zero, 0
/* 4F26E0 8021B240 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F26E4 8021B244 0000000A */  movz      $zero, $zero, $zero
/* 4F26E8 8021B248 00000043 */  sra       $zero, $zero, 1
/* 4F26EC 8021B24C 00000006 */  srlv      $zero, $zero, $zero
/* 4F26F0 8021B250 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F26F4 8021B254 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F26F8 8021B258 00000004 */  sllv      $zero, $zero, $zero
/* 4F26FC 8021B25C 00000000 */  nop       
/* 4F2700 8021B260 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2704 8021B264 00000000 */  nop       
/* 4F2708 8021B268 00000043 */  sra       $zero, $zero, 1
/* 4F270C 8021B26C 00000003 */  sra       $zero, $zero, 0
/* 4F2710 8021B270 8025385C */  lb        $a1, 0x385c($at)
/* 4F2714 8021B274 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2718 8021B278 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F271C 8021B27C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2720 8021B280 00000000 */  nop       
/* 4F2724 8021B284 00000043 */  sra       $zero, $zero, 1
/* 4F2728 8021B288 00000003 */  sra       $zero, $zero, 0
/* 4F272C 8021B28C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2730 8021B290 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2734 8021B294 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2738 8021B298 00000011 */  mthi      $zero
/* 4F273C 8021B29C 00000002 */  srl       $zero, $zero, 0
/* 4F2740 8021B2A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2744 8021B2A4 00080000 */  sll       $zero, $t0, 0
/* 4F2748 8021B2A8 00000043 */  sra       $zero, $zero, 1
/* 4F274C 8021B2AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2750 8021B2B0 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2754 8021B2B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2758 8021B2B8 00000000 */  nop       
/* 4F275C 8021B2BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2760 8021B2C0 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2764 8021B2C4 00000013 */  mtlo      $zero
/* 4F2768 8021B2C8 00000000 */  nop       
/* 4F276C 8021B2CC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2770 8021B2D0 00000000 */  nop       
/* 4F2774 8021B2D4 00000043 */  sra       $zero, $zero, 1
/* 4F2778 8021B2D8 00000004 */  sllv      $zero, $zero, $zero
/* 4F277C 8021B2DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F2780 8021B2E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2784 8021B2E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2788 8021B2E8 00690001 */  movt      $zero, $v1, $fcc2
/* 4F278C 8021B2EC 00000008 */  jr        $zero
/* 4F2790 8021B2F0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F2794 8021B2F4 00000008 */  jr        $zero
/* 4F2798 8021B2F8 00000043 */   sra      $zero, $zero, 1
/* 4F279C 8021B2FC 00000002 */  srl       $zero, $zero, 0
/* 4F27A0 8021B300 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F27A4 8021B304 00000002 */  srl       $zero, $zero, 0
/* 4F27A8 8021B308 0000000A */  movz      $zero, $zero, $zero
/* 4F27AC 8021B30C 00000002 */  srl       $zero, $zero, 0
/* 4F27B0 8021B310 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F27B4 8021B314 0000000A */  movz      $zero, $zero, $zero
/* 4F27B8 8021B318 00000043 */  sra       $zero, $zero, 1
/* 4F27BC 8021B31C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F27C0 8021B320 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F27C4 8021B324 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F27C8 8021B328 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F27CC 8021B32C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F27D0 8021B330 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F27D4 8021B334 00000043 */  sra       $zero, $zero, 1
/* 4F27D8 8021B338 00000006 */  srlv      $zero, $zero, $zero
/* 4F27DC 8021B33C 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F27E0 8021B340 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F27E4 8021B344 00000002 */  srl       $zero, $zero, 0
/* 4F27E8 8021B348 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F27EC 8021B34C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F27F0 8021B350 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F27F4 8021B354 00000002 */  srl       $zero, $zero, 0
/* 4F27F8 8021B358 00000000 */  nop       
/* 4F27FC 8021B35C 00000013 */  mtlo      $zero
/* 4F2800 8021B360 00000000 */  nop       
/* 4F2804 8021B364 00000043 */  sra       $zero, $zero, 1
/* 4F2808 8021B368 00000001 */  movf      $zero, $zero, $fcc0
/* 4F280C 8021B36C 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4F2810 8021B370 00000025 */  or        $zero, $zero, $zero
/* 4F2814 8021B374 00000002 */  srl       $zero, $zero, 0
/* 4F2818 8021B378 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F281C 8021B37C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2820 8021B380 00000025 */  or        $zero, $zero, $zero
/* 4F2824 8021B384 00000002 */  srl       $zero, $zero, 0
/* 4F2828 8021B388 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F282C 8021B38C 00690001 */  movt      $zero, $v1, $fcc2
/* 4F2830 8021B390 00000046 */  rotrv     $zero, $zero, $zero
/* 4F2834 8021B394 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2838 8021B398 8021B41C */  lb        $at, -0x4be4($at)
/* 4F283C 8021B39C 00000043 */  sra       $zero, $zero, 1
/* 4F2840 8021B3A0 00000004 */  sllv      $zero, $zero, $zero
/* 4F2844 8021B3A4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F2848 8021B3A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F284C 8021B3AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2850 8021B3B0 00690001 */  movt      $zero, $v1, $fcc2
/* 4F2854 8021B3B4 00000023 */  negu      $zero, $zero
/* 4F2858 8021B3B8 00000000 */  nop       
/* 4F285C 8021B3BC 00000043 */  sra       $zero, $zero, 1
/* 4F2860 8021B3C0 00000004 */  sllv      $zero, $zero, $zero
/* 4F2864 8021B3C4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F2868 8021B3C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F286C 8021B3CC 00000008 */  jr        $zero
/* 4F2870 8021B3D0 00000000 */   nop      
/* 4F2874 8021B3D4 00000043 */  sra       $zero, $zero, 1
/* 4F2878 8021B3D8 00000002 */  srl       $zero, $zero, 0
/* 4F287C 8021B3DC 8026D664 */  lb        $a2, -0x299c($at)
/* 4F2880 8021B3E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2884 8021B3E4 00000043 */  sra       $zero, $zero, 1
/* 4F2888 8021B3E8 00000003 */  sra       $zero, $zero, 0
/* 4F288C 8021B3EC 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F2890 8021B3F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2894 8021B3F4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F2898 8021B3F8 00000043 */  sra       $zero, $zero, 1
/* 4F289C 8021B3FC 00000003 */  sra       $zero, $zero, 0
/* 4F28A0 8021B400 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F28A4 8021B404 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F28A8 8021B408 00000001 */  movf      $zero, $zero, $fcc0
/* 4F28AC 8021B40C 00000002 */  srl       $zero, $zero, 0
/* 4F28B0 8021B410 00000000 */  nop       
/* 4F28B4 8021B414 00000001 */  movf      $zero, $zero, $fcc0
/* 4F28B8 8021B418 00000000 */  nop       
/* 4F28BC 8021B41C 00000043 */  sra       $zero, $zero, 1
/* 4F28C0 8021B420 00000004 */  sllv      $zero, $zero, $zero
/* 4F28C4 8021B424 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F28C8 8021B428 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F28CC 8021B42C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F28D0 8021B430 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F28D4 8021B434 00000043 */  sra       $zero, $zero, 1
/* 4F28D8 8021B438 00000004 */  sllv      $zero, $zero, $zero
/* 4F28DC 8021B43C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F28E0 8021B440 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F28E4 8021B444 00000001 */  movf      $zero, $zero, $fcc0
/* 4F28E8 8021B448 00690004 */  sllv      $zero, $t1, $v1
/* 4F28EC 8021B44C 00000043 */  sra       $zero, $zero, 1
/* 4F28F0 8021B450 00000003 */  sra       $zero, $zero, 0
/* 4F28F4 8021B454 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F28F8 8021B458 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F28FC 8021B45C F24A8A80 */  scd       $t2, -0x7580($s2)
/* 4F2900 8021B460 00000043 */  sra       $zero, $zero, 1
/* 4F2904 8021B464 00000003 */  sra       $zero, $zero, 0
/* 4F2908 8021B468 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F290C 8021B46C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2910 8021B470 F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F2914 8021B474 00000043 */  sra       $zero, $zero, 1
/* 4F2918 8021B478 00000002 */  srl       $zero, $zero, 0
/* 4F291C 8021B47C 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F2920 8021B480 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2924 8021B484 00000043 */  sra       $zero, $zero, 1
/* 4F2928 8021B488 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F292C 8021B48C 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F2930 8021B490 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2934 8021B494 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2938 8021B498 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F293C 8021B49C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2940 8021B4A0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F2944 8021B4A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2948 8021B4A8 8021B50C */  lb        $at, -0x4af4($at)
/* 4F294C 8021B4AC 00000043 */  sra       $zero, $zero, 1
/* 4F2950 8021B4B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2954 8021B4B4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F2958 8021B4B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F295C 8021B4BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2960 8021B4C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2964 8021B4C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2968 8021B4C8 00000043 */  sra       $zero, $zero, 1
/* 4F296C 8021B4CC 00000006 */  srlv      $zero, $zero, $zero
/* 4F2970 8021B4D0 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F2974 8021B4D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2978 8021B4D8 00000002 */  srl       $zero, $zero, 0
/* 4F297C 8021B4DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2980 8021B4E0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2984 8021B4E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2988 8021B4E8 00000043 */  sra       $zero, $zero, 1
/* 4F298C 8021B4EC 00000003 */  sra       $zero, $zero, 0
/* 4F2990 8021B4F0 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F2994 8021B4F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2998 8021B4F8 00000000 */  nop       
/* 4F299C 8021B4FC 00000002 */  srl       $zero, $zero, 0
/* 4F29A0 8021B500 00000000 */  nop       
/* 4F29A4 8021B504 00000001 */  movf      $zero, $zero, $fcc0
/* 4F29A8 8021B508 00000000 */  nop       
/* 4F29AC 8021B50C 00000043 */  sra       $zero, $zero, 1
/* 4F29B0 8021B510 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F29B4 8021B514 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F29B8 8021B518 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F29BC 8021B51C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F29C0 8021B520 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F29C4 8021B524 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F29C8 8021B528 0000000C */  syscall   
/* 4F29CC 8021B52C 00000002 */  srl       $zero, $zero, 0
/* 4F29D0 8021B530 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F29D4 8021B534 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F29D8 8021B538 00000043 */  sra       $zero, $zero, 1
/* 4F29DC 8021B53C 00000003 */  sra       $zero, $zero, 0
/* 4F29E0 8021B540 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F29E4 8021B544 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F29E8 8021B548 000000B4 */  teq       $zero, $zero, 2
/* 4F29EC 8021B54C 00000012 */  mflo      $zero
/* 4F29F0 8021B550 00000000 */  nop       
/* 4F29F4 8021B554 00000043 */  sra       $zero, $zero, 1
/* 4F29F8 8021B558 00000003 */  sra       $zero, $zero, 0
/* 4F29FC 8021B55C 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F2A00 8021B560 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2A04 8021B564 00000000 */  nop       
/* 4F2A08 8021B568 00000013 */  mtlo      $zero
/* 4F2A0C 8021B56C 00000000 */  nop       
/* 4F2A10 8021B570 00000003 */  sra       $zero, $zero, 0
/* 4F2A14 8021B574 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2A18 8021B578 00000000 */  nop       
/* 4F2A1C 8021B57C 00000043 */  sra       $zero, $zero, 1
/* 4F2A20 8021B580 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2A24 8021B584 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F2A28 8021B588 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2A2C 8021B58C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2A30 8021B590 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2A34 8021B594 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F2A38 8021B598 0000000A */  movz      $zero, $zero, $zero
/* 4F2A3C 8021B59C 00000002 */  srl       $zero, $zero, 0
/* 4F2A40 8021B5A0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2A44 8021B5A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2A48 8021B5A8 00000004 */  sllv      $zero, $zero, $zero
/* 4F2A4C 8021B5AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2A50 8021B5B0 0000000A */  movz      $zero, $zero, $zero
/* 4F2A54 8021B5B4 00000013 */  mtlo      $zero
/* 4F2A58 8021B5B8 00000000 */  nop       
/* 4F2A5C 8021B5BC 0000000C */  syscall   
/* 4F2A60 8021B5C0 00000002 */  srl       $zero, $zero, 0
/* 4F2A64 8021B5C4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2A68 8021B5C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2A6C 8021B5CC 00000024 */  and       $zero, $zero, $zero
/* 4F2A70 8021B5D0 00000002 */  srl       $zero, $zero, 0
/* 4F2A74 8021B5D4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2A78 8021B5D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2A7C 8021B5DC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F2A80 8021B5E0 00000002 */  srl       $zero, $zero, 0
/* 4F2A84 8021B5E4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2A88 8021B5E8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2A8C 8021B5EC 0000000C */  syscall   
/* 4F2A90 8021B5F0 00000002 */  srl       $zero, $zero, 0
/* 4F2A94 8021B5F4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2A98 8021B5F8 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2A9C 8021B5FC 00000043 */  sra       $zero, $zero, 1
/* 4F2AA0 8021B600 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2AA4 8021B604 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2AA8 8021B608 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2AAC 8021B60C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2AB0 8021B610 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2AB4 8021B614 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2AB8 8021B618 00000043 */  sra       $zero, $zero, 1
/* 4F2ABC 8021B61C 00000006 */  srlv      $zero, $zero, $zero
/* 4F2AC0 8021B620 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2AC4 8021B624 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2AC8 8021B628 00000006 */  srlv      $zero, $zero, $zero
/* 4F2ACC 8021B62C 00000000 */  nop       
/* 4F2AD0 8021B630 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2AD4 8021B634 00000000 */  nop       
/* 4F2AD8 8021B638 00000043 */  sra       $zero, $zero, 1
/* 4F2ADC 8021B63C 00000003 */  sra       $zero, $zero, 0
/* 4F2AE0 8021B640 8025385C */  lb        $a1, 0x385c($at)
/* 4F2AE4 8021B644 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2AE8 8021B648 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2AEC 8021B64C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2AF0 8021B650 00000000 */  nop       
/* 4F2AF4 8021B654 00000043 */  sra       $zero, $zero, 1
/* 4F2AF8 8021B658 00000003 */  sra       $zero, $zero, 0
/* 4F2AFC 8021B65C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2B00 8021B660 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2B04 8021B664 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2B08 8021B668 00000011 */  mthi      $zero
/* 4F2B0C 8021B66C 00000002 */  srl       $zero, $zero, 0
/* 4F2B10 8021B670 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2B14 8021B674 00080000 */  sll       $zero, $t0, 0
/* 4F2B18 8021B678 00000043 */  sra       $zero, $zero, 1
/* 4F2B1C 8021B67C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2B20 8021B680 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2B24 8021B684 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2B28 8021B688 00000000 */  nop       
/* 4F2B2C 8021B68C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2B30 8021B690 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2B34 8021B694 00000013 */  mtlo      $zero
/* 4F2B38 8021B698 00000000 */  nop       
/* 4F2B3C 8021B69C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2B40 8021B6A0 00000000 */  nop       
/* 4F2B44 8021B6A4 00000012 */  mflo      $zero
/* 4F2B48 8021B6A8 00000000 */  nop       
/* 4F2B4C 8021B6AC 00000024 */  and       $zero, $zero, $zero
/* 4F2B50 8021B6B0 00000002 */  srl       $zero, $zero, 0
/* 4F2B54 8021B6B4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2B58 8021B6B8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2B5C 8021B6BC 00000027 */  not       $zero, $zero
/* 4F2B60 8021B6C0 00000002 */  srl       $zero, $zero, 0
/* 4F2B64 8021B6C4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2B68 8021B6C8 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2B6C 8021B6CC 00000043 */  sra       $zero, $zero, 1
/* 4F2B70 8021B6D0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2B74 8021B6D4 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2B78 8021B6D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2B7C 8021B6DC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2B80 8021B6E0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2B84 8021B6E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2B88 8021B6E8 00000043 */  sra       $zero, $zero, 1
/* 4F2B8C 8021B6EC 00000006 */  srlv      $zero, $zero, $zero
/* 4F2B90 8021B6F0 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2B94 8021B6F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2B98 8021B6F8 00000006 */  srlv      $zero, $zero, $zero
/* 4F2B9C 8021B6FC 00000000 */  nop       
/* 4F2BA0 8021B700 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2BA4 8021B704 00000000 */  nop       
/* 4F2BA8 8021B708 00000043 */  sra       $zero, $zero, 1
/* 4F2BAC 8021B70C 00000003 */  sra       $zero, $zero, 0
/* 4F2BB0 8021B710 8025385C */  lb        $a1, 0x385c($at)
/* 4F2BB4 8021B714 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2BB8 8021B718 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2BBC 8021B71C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2BC0 8021B720 00000000 */  nop       
/* 4F2BC4 8021B724 00000043 */  sra       $zero, $zero, 1
/* 4F2BC8 8021B728 00000003 */  sra       $zero, $zero, 0
/* 4F2BCC 8021B72C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2BD0 8021B730 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2BD4 8021B734 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2BD8 8021B738 00000011 */  mthi      $zero
/* 4F2BDC 8021B73C 00000002 */  srl       $zero, $zero, 0
/* 4F2BE0 8021B740 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2BE4 8021B744 00080000 */  sll       $zero, $t0, 0
/* 4F2BE8 8021B748 00000043 */  sra       $zero, $zero, 1
/* 4F2BEC 8021B74C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2BF0 8021B750 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2BF4 8021B754 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2BF8 8021B758 00000000 */  nop       
/* 4F2BFC 8021B75C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2C00 8021B760 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2C04 8021B764 00000013 */  mtlo      $zero
/* 4F2C08 8021B768 00000000 */  nop       
/* 4F2C0C 8021B76C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2C10 8021B770 00000000 */  nop       
/* 4F2C14 8021B774 00000013 */  mtlo      $zero
/* 4F2C18 8021B778 00000000 */  nop       
/* 4F2C1C 8021B77C 00000012 */  mflo      $zero
/* 4F2C20 8021B780 00000000 */  nop       
/* 4F2C24 8021B784 00000024 */  and       $zero, $zero, $zero
/* 4F2C28 8021B788 00000002 */  srl       $zero, $zero, 0
/* 4F2C2C 8021B78C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2C30 8021B790 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2C34 8021B794 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F2C38 8021B798 00000002 */  srl       $zero, $zero, 0
/* 4F2C3C 8021B79C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2C40 8021B7A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2C44 8021B7A4 0000000C */  syscall   
/* 4F2C48 8021B7A8 00000002 */  srl       $zero, $zero, 0
/* 4F2C4C 8021B7AC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F2C50 8021B7B0 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2C54 8021B7B4 00000043 */  sra       $zero, $zero, 1
/* 4F2C58 8021B7B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2C5C 8021B7BC 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2C60 8021B7C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2C64 8021B7C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2C68 8021B7C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2C6C 8021B7CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2C70 8021B7D0 00000043 */  sra       $zero, $zero, 1
/* 4F2C74 8021B7D4 00000006 */  srlv      $zero, $zero, $zero
/* 4F2C78 8021B7D8 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2C7C 8021B7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2C80 8021B7E0 00000006 */  srlv      $zero, $zero, $zero
/* 4F2C84 8021B7E4 00000000 */  nop       
/* 4F2C88 8021B7E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2C8C 8021B7EC 00000000 */  nop       
/* 4F2C90 8021B7F0 00000043 */  sra       $zero, $zero, 1
/* 4F2C94 8021B7F4 00000003 */  sra       $zero, $zero, 0
/* 4F2C98 8021B7F8 8025385C */  lb        $a1, 0x385c($at)
/* 4F2C9C 8021B7FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2CA0 8021B800 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2CA4 8021B804 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2CA8 8021B808 00000000 */  nop       
/* 4F2CAC 8021B80C 00000043 */  sra       $zero, $zero, 1
/* 4F2CB0 8021B810 00000003 */  sra       $zero, $zero, 0
/* 4F2CB4 8021B814 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2CB8 8021B818 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2CBC 8021B81C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2CC0 8021B820 00000011 */  mthi      $zero
/* 4F2CC4 8021B824 00000002 */  srl       $zero, $zero, 0
/* 4F2CC8 8021B828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2CCC 8021B82C 00080000 */  sll       $zero, $t0, 0
/* 4F2CD0 8021B830 00000043 */  sra       $zero, $zero, 1
/* 4F2CD4 8021B834 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2CD8 8021B838 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2CDC 8021B83C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2CE0 8021B840 00000000 */  nop       
/* 4F2CE4 8021B844 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2CE8 8021B848 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2CEC 8021B84C 00000013 */  mtlo      $zero
/* 4F2CF0 8021B850 00000000 */  nop       
/* 4F2CF4 8021B854 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2CF8 8021B858 00000000 */  nop       
/* 4F2CFC 8021B85C 00000012 */  mflo      $zero
/* 4F2D00 8021B860 00000000 */  nop       
/* 4F2D04 8021B864 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F2D08 8021B868 00000002 */  srl       $zero, $zero, 0
/* 4F2D0C 8021B86C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2D10 8021B870 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2D14 8021B874 00000043 */  sra       $zero, $zero, 1
/* 4F2D18 8021B878 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2D1C 8021B87C 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F2D20 8021B880 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2D24 8021B884 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F2D28 8021B888 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F2D2C 8021B88C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F2D30 8021B890 00000043 */  sra       $zero, $zero, 1
/* 4F2D34 8021B894 00000006 */  srlv      $zero, $zero, $zero
/* 4F2D38 8021B898 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F2D3C 8021B89C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2D40 8021B8A0 00000006 */  srlv      $zero, $zero, $zero
/* 4F2D44 8021B8A4 00000000 */  nop       
/* 4F2D48 8021B8A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2D4C 8021B8AC 00000000 */  nop       
/* 4F2D50 8021B8B0 00000043 */  sra       $zero, $zero, 1
/* 4F2D54 8021B8B4 00000003 */  sra       $zero, $zero, 0
/* 4F2D58 8021B8B8 8025385C */  lb        $a1, 0x385c($at)
/* 4F2D5C 8021B8BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2D60 8021B8C0 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F2D64 8021B8C4 00000056 */  drotrv    $zero, $zero, $zero
/* 4F2D68 8021B8C8 00000000 */  nop       
/* 4F2D6C 8021B8CC 00000043 */  sra       $zero, $zero, 1
/* 4F2D70 8021B8D0 00000003 */  sra       $zero, $zero, 0
/* 4F2D74 8021B8D4 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F2D78 8021B8D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F2D7C 8021B8DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2D80 8021B8E0 00000011 */  mthi      $zero
/* 4F2D84 8021B8E4 00000002 */  srl       $zero, $zero, 0
/* 4F2D88 8021B8E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F2D8C 8021B8EC 00080000 */  sll       $zero, $t0, 0
/* 4F2D90 8021B8F0 00000043 */  sra       $zero, $zero, 1
/* 4F2D94 8021B8F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2D98 8021B8F8 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F2D9C 8021B8FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2DA0 8021B900 00000000 */  nop       
/* 4F2DA4 8021B904 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2DA8 8021B908 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F2DAC 8021B90C 00000013 */  mtlo      $zero
/* 4F2DB0 8021B910 00000000 */  nop       
/* 4F2DB4 8021B914 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F2DB8 8021B918 00000000 */  nop       
/* 4F2DBC 8021B91C 00000013 */  mtlo      $zero
/* 4F2DC0 8021B920 00000000 */  nop       
/* 4F2DC4 8021B924 00000013 */  mtlo      $zero
/* 4F2DC8 8021B928 00000000 */  nop       
/* 4F2DCC 8021B92C 00000004 */  sllv      $zero, $zero, $zero
/* 4F2DD0 8021B930 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2DD4 8021B934 00000000 */  nop       
/* 4F2DD8 8021B938 00000003 */  sra       $zero, $zero, 0
/* 4F2DDC 8021B93C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2DE0 8021B940 0000000A */  movz      $zero, $zero, $zero
/* 4F2DE4 8021B944 00000002 */  srl       $zero, $zero, 0
/* 4F2DE8 8021B948 00000000 */  nop       
/* 4F2DEC 8021B94C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2DF0 8021B950 00000000 */  nop       
/* 4F2DF4 8021B954 00000000 */  nop       
/* 4F2DF8 8021B958 00000000 */  nop       
/* 4F2DFC 8021B95C 00000000 */  nop       
/* 4F2E00 8021B960 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2E04 8021B964 00680001 */  movf      $zero, $v1, $fcc2
/* 4F2E08 8021B968 0000000C */  syscall   
/* 4F2E0C 8021B96C 00680000 */  .byte     0x00, 0x68, 0x00, 0x00
/* 4F2E10 8021B970 00000006 */  srlv      $zero, $zero, $zero
/* 4F2E14 8021B974 0068000C */  syscall   0x1a000
/* 4F2E18 8021B978 00000009 */  jr        $zero
/* 4F2E1C 8021B97C 00680001 */   movf     $zero, $v1, $fcc2
/* 4F2E20 8021B980 00000008 */  jr        $zero
/* 4F2E24 8021B984 00680000 */   .byte    0x00, 0x68, 0x00, 0x00
/* 4F2E28 8021B988 0000000B */  movn      $zero, $zero, $zero
/* 4F2E2C 8021B98C 00680000 */  .byte     0x00, 0x68, 0x00, 0x00
/* 4F2E30 8021B990 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2E34 8021B994 00680000 */  .byte     0x00, 0x68, 0x00, 0x00
/* 4F2E38 8021B998 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2E3C 8021B99C 00680000 */  .byte     0x00, 0x68, 0x00, 0x00
/* 4F2E40 8021B9A0 00000004 */  sllv      $zero, $zero, $zero
/* 4F2E44 8021B9A4 0068000A */  movz      $zero, $v1, $t0
/* 4F2E48 8021B9A8 00000000 */  nop       
/* 4F2E4C 8021B9AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2E50 8021B9B0 0068000A */  movz      $zero, $v1, $t0
/* 4F2E54 8021B9B4 0000000C */  syscall   
/* 4F2E58 8021B9B8 00680007 */  srav      $zero, $t0, $v1
/* 4F2E5C 8021B9BC 00000006 */  srlv      $zero, $zero, $zero
/* 4F2E60 8021B9C0 0068000D */  break     0x68
/* 4F2E64 8021B9C4 00000009 */   jr       $zero
/* 4F2E68 8021B9C8 0068000A */   movz     $zero, $v1, $t0
/* 4F2E6C 8021B9CC 00000008 */  jr        $zero
/* 4F2E70 8021B9D0 00680007 */   srav     $zero, $t0, $v1
/* 4F2E74 8021B9D4 0000000B */  movn      $zero, $zero, $zero
/* 4F2E78 8021B9D8 0068000A */  movz      $zero, $v1, $t0
/* 4F2E7C 8021B9DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2E80 8021B9E0 0068000A */  movz      $zero, $v1, $t0
/* 4F2E84 8021B9E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2E88 8021B9E8 0068000A */  movz      $zero, $v1, $t0
/* 4F2E8C 8021B9EC 00000004 */  sllv      $zero, $zero, $zero
/* 4F2E90 8021B9F0 0068000A */  movz      $zero, $v1, $t0
/* 4F2E94 8021B9F4 00000000 */  nop       
/* 4F2E98 8021B9F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2E9C 8021B9FC 00330006 */  srlv      $zero, $s3, $at
/* 4F2EA0 8021BA00 00000000 */  nop       
/* 4F2EA4 8021BA04 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2EA8 8021BA08 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F2EAC 8021BA0C 00000000 */  nop       
/* 4F2EB0 8021BA10 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2EB4 8021BA14 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F2EB8 8021BA18 00000000 */  nop       
/* 4F2EBC 8021BA1C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2EC0 8021BA20 00000000 */  nop       
/* 4F2EC4 8021BA24 00000000 */  nop       
/* 4F2EC8 8021BA28 00000001 */  movf      $zero, $zero, $fcc0
/* 4F2ECC 8021BA2C 00000000 */  nop       
/* 4F2ED0 8021BA30 00000002 */  srl       $zero, $zero, 0
/* 4F2ED4 8021BA34 00000000 */  nop       
/* 4F2ED8 8021BA38 00000006 */  srlv      $zero, $zero, $zero
/* 4F2EDC 8021BA3C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F2EE0 8021BA40 00000009 */  jr        $zero
/* 4F2EE4 8021BA44 00000000 */   nop      
/* 4F2EE8 8021BA48 00000007 */  srav      $zero, $zero, $zero
/* 4F2EEC 8021BA4C 00000000 */  nop       
/* 4F2EF0 8021BA50 00000004 */  sllv      $zero, $zero, $zero
/* 4F2EF4 8021BA54 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2EF8 8021BA58 00000003 */  sra       $zero, $zero, 0
/* 4F2EFC 8021BA5C 00000000 */  nop       
/* 4F2F00 8021BA60 0000000B */  movn      $zero, $zero, $zero
/* 4F2F04 8021BA64 00000000 */  nop       
/* 4F2F08 8021BA68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F2F0C 8021BA6C 0000001E */  ddiv      $zero, $zero, $zero
/* 4F2F10 8021BA70 0000000A */  movz      $zero, $zero, $zero
/* 4F2F14 8021BA74 0000003C */  dsll32    $zero, $zero, 0
/* 4F2F18 8021BA78 00000008 */  jr        $zero
/* 4F2F1C 8021BA7C 00000028 */   .byte    0x00, 0x00, 0x00, 0x28
/* 4F2F20 8021BA80 0000001F */  ddivu     $zero, $zero, $zero
/* 4F2F24 8021BA84 00000000 */  nop       
/* 4F2F28 8021BA88 00000020 */  add       $zero, $zero, $zero
/* 4F2F2C 8021BA8C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F2F30 8021BA90 00000025 */  or        $zero, $zero, $zero
/* 4F2F34 8021BA94 00000000 */  nop       
/* 4F2F38 8021BA98 00000022 */  neg       $zero, $zero
/* 4F2F3C 8021BA9C 00000000 */  nop       
/* 4F2F40 8021BAA0 00000024 */  and       $zero, $zero, $zero
/* 4F2F44 8021BAA4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F2F48 8021BAA8 00000023 */  negu      $zero, $zero
/* 4F2F4C 8021BAAC 00000000 */  nop       
/* 4F2F50 8021BAB0 00000021 */  addu      $zero, $zero, $zero
/* 4F2F54 8021BAB4 00000000 */  nop       
/* 4F2F58 8021BAB8 00000026 */  xor       $zero, $zero, $zero
/* 4F2F5C 8021BABC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F2F60 8021BAC0 00000027 */  not       $zero, $zero
/* 4F2F64 8021BAC4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F2F68 8021BAC8 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4F2F6C 8021BACC FFFFFFFE */  sd        $ra, -2($ra)
/* 4F2F70 8021BAD0 00000000 */  nop       
/* 4F2F74 8021BAD4 00020000 */  sll       $zero, $v0, 0
/* 4F2F78 8021BAD8 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4F2F7C 8021BADC 002800FF */  .byte     0x00, 0x28, 0x00, 0xff
/* 4F2F80 8021BAE0 8021B960 */  lb        $at, -0x46a0($at)
/* 4F2F84 8021BAE4 8021BA1C */  lb        $at, -0x45e4($at)
/* 4F2F88 8021BAE8 00000000 */  nop       
/* 4F2F8C 8021BAEC 00000000 */  nop       
/* 4F2F90 8021BAF0 00000000 */  nop       
/* 4F2F94 8021BAF4 00000000 */  nop       
/* 4F2F98 8021BAF8 00800001 */  movf      $zero, $a0, $fcc0
/* 4F2F9C 8021BAFC 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 4F2FA0 8021BB00 002700FF */  .byte     0x00, 0x27, 0x00, 0xff
/* 4F2FA4 8021BB04 8021B960 */  lb        $at, -0x46a0($at)
/* 4F2FA8 8021BB08 8021BA1C */  lb        $at, -0x45e4($at)
/* 4F2FAC 8021BB0C 00000000 */  nop       
/* 4F2FB0 8021BB10 00000000 */  nop       
/* 4F2FB4 8021BB14 FBF10000 */  bbit132   $ra, 0x11, .L8021BB18
.L8021BB18:
/* 4F2FB8 8021BB18 00000000 */   nop      
/* 4F2FBC 8021BB1C 40120000 */  mfc0      $s2, $0
/* 4F2FC0 8021BB20 03000000 */  .byte     0x03, 0x00, 0x00, 0x00
/* 4F2FC4 8021BB24 000000FF */  dsra32    $zero, $zero, 3
/* 4F2FC8 8021BB28 8021B9F8 */  lb        $at, -0x4608($at)
/* 4F2FCC 8021BB2C 00000000 */  nop       
/* 4F2FD0 8021BB30 00000000 */  nop       
/* 4F2FD4 8021BB34 00000000 */  nop       
/* 4F2FD8 8021BB38 00000000 */  nop       
/* 4F2FDC 8021BB3C 00000000 */  nop       
/* 4F2FE0 8021BB40 40120000 */  mfc0      $s2, $0
/* 4F2FE4 8021BB44 04000000 */  bltz      $zero, .L8021BB48
.L8021BB48:
/* 4F2FE8 8021BB48 000000FF */   dsra32   $zero, $zero, 3
/* 4F2FEC 8021BB4C 8021B9F8 */  lb        $at, -0x4608($at)
/* 4F2FF0 8021BB50 00000000 */  nop       
/* 4F2FF4 8021BB54 00000000 */  nop       
/* 4F2FF8 8021BB58 00000000 */  nop       
/* 4F2FFC 8021BB5C 00000000 */  nop       
/* 4F3000 8021BB60 00000000 */  nop       
/* 4F3004 8021BB64 40120000 */  mfc0      $s2, $0
/* 4F3008 8021BB68 05000000 */  bltz      $t0, .L8021BB6C
.L8021BB6C:
/* 4F300C 8021BB6C 000000FF */   dsra32   $zero, $zero, 3
/* 4F3010 8021BB70 8021B9F8 */  lb        $at, -0x4608($at)
/* 4F3014 8021BB74 00000000 */  nop       
/* 4F3018 8021BB78 00000000 */  nop       
/* 4F301C 8021BB7C 00000000 */  nop       
/* 4F3020 8021BB80 00000000 */  nop       
/* 4F3024 8021BB84 00000000 */  nop       
/* 4F3028 8021BB88 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4F302C 8021BB8C 06000000 */  bltz      $s0, .L8021BB90
.L8021BB90:
/* 4F3030 8021BB90 000000FF */   dsra32   $zero, $zero, 3
/* 4F3034 8021BB94 8021BA04 */  lb        $at, -0x45fc($at)
/* 4F3038 8021BB98 00000000 */  nop       
/* 4F303C 8021BB9C 00000000 */  nop       
/* 4F3040 8021BBA0 00000000 */  nop       
/* 4F3044 8021BBA4 00000000 */  nop       
/* 4F3048 8021BBA8 00000000 */  nop       
/* 4F304C 8021BBAC 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4F3050 8021BBB0 07000000 */  bltz      $t8, .L8021BBB4
.L8021BBB4:
/* 4F3054 8021BBB4 000000FF */   dsra32   $zero, $zero, 3
/* 4F3058 8021BBB8 8021BA04 */  lb        $at, -0x45fc($at)
/* 4F305C 8021BBBC 00000000 */  nop       
/* 4F3060 8021BBC0 00000000 */  nop       
/* 4F3064 8021BBC4 00000000 */  nop       
/* 4F3068 8021BBC8 00000000 */  nop       
/* 4F306C 8021BBCC 00000000 */  nop       
/* 4F3070 8021BBD0 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4F3074 8021BBD4 08000000 */  j         .L80000000
/* 4F3078 8021BBD8 000000FF */   dsra32   $zero, $zero, 3
/* 4F307C 8021BBDC 8021BA10 */  lb        $at, -0x45f0($at)
/* 4F3080 8021BBE0 00000000 */  nop       
/* 4F3084 8021BBE4 00000000 */  nop       
/* 4F3088 8021BBE8 00000000 */  nop       
/* 4F308C 8021BBEC 00000000 */  nop       
/* 4F3090 8021BBF0 00000000 */  nop       
/* 4F3094 8021BBF4 00000000 */  nop       
/* 4F3098 8021BBF8 00A1371E */  .byte     0x00, 0xa1, 0x37, 0x1e
/* 4F309C 8021BBFC 00080000 */  sll       $zero, $t0, 0
/* 4F30A0 8021BC00 8021BAD4 */  lb        $at, -0x452c($at)
/* 4F30A4 8021BC04 8021BC1C */  lb        $at, -0x43e4($at)
/* 4F30A8 8021BC08 8021BA28 */  lb        $at, -0x45d8($at)
/* 4F30AC 8021BC0C 00000000 */  nop       
/* 4F30B0 8021BC10 00044600 */  sll       $t0, $a0, 0x18
/* 4F30B4 8021BC14 382D0000 */  xori      $t5, $at, 0
/* 4F30B8 8021BC18 F6230A23 */  sdc1      $f3, 0xa23($s1)
/* 4F30BC 8021BC1C 00000043 */  sra       $zero, $zero, 1
/* 4F30C0 8021BC20 00000003 */  sra       $zero, $zero, 0
/* 4F30C4 8021BC24 80278930 */  lb        $a3, -0x76d0($at)
/* 4F30C8 8021BC28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F30CC 8021BC2C 8021CCD4 */  lb        $at, -0x332c($at)
/* 4F30D0 8021BC30 00000043 */  sra       $zero, $zero, 1
/* 4F30D4 8021BC34 00000003 */  sra       $zero, $zero, 0
/* 4F30D8 8021BC38 80278A94 */  lb        $a3, -0x756c($at)
/* 4F30DC 8021BC3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F30E0 8021BC40 8021BE28 */  lb        $at, -0x41d8($at)
/* 4F30E4 8021BC44 00000043 */  sra       $zero, $zero, 1
/* 4F30E8 8021BC48 00000003 */  sra       $zero, $zero, 0
/* 4F30EC 8021BC4C 80278C20 */  lb        $a3, -0x73e0($at)
/* 4F30F0 8021BC50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F30F4 8021BC54 8021BFD0 */  lb        $at, -0x4030($at)
/* 4F30F8 8021BC58 00000043 */  sra       $zero, $zero, 1
/* 4F30FC 8021BC5C 00000003 */  sra       $zero, $zero, 0
/* 4F3100 8021BC60 80278C94 */  lb        $a3, -0x736c($at)
/* 4F3104 8021BC64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3108 8021BC68 8021F9C4 */  lb        $at, -0x63c($at)
/* 4F310C 8021BC6C 00000043 */  sra       $zero, $zero, 1
/* 4F3110 8021BC70 00000002 */  srl       $zero, $zero, 0
/* 4F3114 8021BC74 8026D664 */  lb        $a2, -0x299c($at)
/* 4F3118 8021BC78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F311C 8021BC7C 00000043 */  sra       $zero, $zero, 1
/* 4F3120 8021BC80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3124 8021BC84 8026A1EC */  lb        $a2, -0x5e14($at)
/* 4F3128 8021BC88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F312C 8021BC8C 00000061 */  .byte     0x00, 0x00, 0x00, 0x61
/* 4F3130 8021BC90 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3134 8021BC94 0000000F */  sync      
/* 4F3138 8021BC98 00000043 */  sra       $zero, $zero, 1
/* 4F313C 8021BC9C 00000006 */  srlv      $zero, $zero, $zero
/* 4F3140 8021BCA0 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F3144 8021BCA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3148 8021BCA8 00000003 */  sra       $zero, $zero, 0
/* 4F314C 8021BCAC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3150 8021BCB0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3154 8021BCB4 00000003 */  sra       $zero, $zero, 0
/* 4F3158 8021BCB8 00000043 */  sra       $zero, $zero, 1
/* 4F315C 8021BCBC 00000006 */  srlv      $zero, $zero, $zero
/* 4F3160 8021BCC0 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F3164 8021BCC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3168 8021BCC8 00000004 */  sllv      $zero, $zero, $zero
/* 4F316C 8021BCCC 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 4F3170 8021BCD0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3174 8021BCD4 FFFFFFF9 */  sd        $ra, -7($ra)
/* 4F3178 8021BCD8 00000043 */  sra       $zero, $zero, 1
/* 4F317C 8021BCDC 00000006 */  srlv      $zero, $zero, $zero
/* 4F3180 8021BCE0 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F3184 8021BCE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3188 8021BCE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F318C 8021BCEC 0000003C */  dsll32    $zero, $zero, 0
/* 4F3190 8021BCF0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3194 8021BCF4 FFFFFFF9 */  sd        $ra, -7($ra)
/* 4F3198 8021BCF8 00000043 */  sra       $zero, $zero, 1
/* 4F319C 8021BCFC 00000004 */  sllv      $zero, $zero, $zero
/* 4F31A0 8021BD00 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F31A4 8021BD04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F31A8 8021BD08 00000008 */  jr        $zero
/* 4F31AC 8021BD0C 00000000 */   nop      
/* 4F31B0 8021BD10 00000043 */  sra       $zero, $zero, 1
/* 4F31B4 8021BD14 00000004 */  sllv      $zero, $zero, $zero
/* 4F31B8 8021BD18 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F31BC 8021BD1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F31C0 8021BD20 00000000 */  nop       
/* 4F31C4 8021BD24 00000000 */  nop       
/* 4F31C8 8021BD28 00000043 */  sra       $zero, $zero, 1
/* 4F31CC 8021BD2C 00000004 */  sllv      $zero, $zero, $zero
/* 4F31D0 8021BD30 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F31D4 8021BD34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F31D8 8021BD38 00000001 */  movf      $zero, $zero, $fcc0
/* 4F31DC 8021BD3C 00000000 */  nop       
/* 4F31E0 8021BD40 00000043 */  sra       $zero, $zero, 1
/* 4F31E4 8021BD44 00000004 */  sllv      $zero, $zero, $zero
/* 4F31E8 8021BD48 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F31EC 8021BD4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F31F0 8021BD50 00000003 */  sra       $zero, $zero, 0
/* 4F31F4 8021BD54 00000000 */  nop       
/* 4F31F8 8021BD58 00000043 */  sra       $zero, $zero, 1
/* 4F31FC 8021BD5C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3200 8021BD60 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F3204 8021BD64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3208 8021BD68 00000004 */  sllv      $zero, $zero, $zero
/* 4F320C 8021BD6C 00000000 */  nop       
/* 4F3210 8021BD70 00000043 */  sra       $zero, $zero, 1
/* 4F3214 8021BD74 00000004 */  sllv      $zero, $zero, $zero
/* 4F3218 8021BD78 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F321C 8021BD7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3220 8021BD80 00000002 */  srl       $zero, $zero, 0
/* 4F3224 8021BD84 00000003 */  sra       $zero, $zero, 0
/* 4F3228 8021BD88 00000043 */  sra       $zero, $zero, 1
/* 4F322C 8021BD8C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3230 8021BD90 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F3234 8021BD94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3238 8021BD98 00000006 */  srlv      $zero, $zero, $zero
/* 4F323C 8021BD9C 00000000 */  nop       
/* 4F3240 8021BDA0 00000043 */  sra       $zero, $zero, 1
/* 4F3244 8021BDA4 00000004 */  sllv      $zero, $zero, $zero
/* 4F3248 8021BDA8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F324C 8021BDAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3250 8021BDB0 00000007 */  srav      $zero, $zero, $zero
/* 4F3254 8021BDB4 00000000 */  nop       
/* 4F3258 8021BDB8 00000043 */  sra       $zero, $zero, 1
/* 4F325C 8021BDBC 00000004 */  sllv      $zero, $zero, $zero
/* 4F3260 8021BDC0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F3264 8021BDC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3268 8021BDC8 0000000A */  movz      $zero, $zero, $zero
/* 4F326C 8021BDCC 00000000 */  nop       
/* 4F3270 8021BDD0 00000043 */  sra       $zero, $zero, 1
/* 4F3274 8021BDD4 00000004 */  sllv      $zero, $zero, $zero
/* 4F3278 8021BDD8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F327C 8021BDDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3280 8021BDE0 0000000B */  movn      $zero, $zero, $zero
/* 4F3284 8021BDE4 00000000 */  nop       
/* 4F3288 8021BDE8 00000043 */  sra       $zero, $zero, 1
/* 4F328C 8021BDEC 00000004 */  sllv      $zero, $zero, $zero
/* 4F3290 8021BDF0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F3294 8021BDF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3298 8021BDF8 0000000C */  syscall   
/* 4F329C 8021BDFC 00000000 */  nop       
/* 4F32A0 8021BE00 00000043 */  sra       $zero, $zero, 1
/* 4F32A4 8021BE04 00000004 */  sllv      $zero, $zero, $zero
/* 4F32A8 8021BE08 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F32AC 8021BE0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F32B0 8021BE10 0000000D */  break     
/* 4F32B4 8021BE14 00000000 */   nop      
/* 4F32B8 8021BE18 00000002 */  srl       $zero, $zero, 0
/* 4F32BC 8021BE1C 00000000 */  nop       
/* 4F32C0 8021BE20 00000001 */  movf      $zero, $zero, $fcc0
/* 4F32C4 8021BE24 00000000 */  nop       
/* 4F32C8 8021BE28 00000003 */  sra       $zero, $zero, 0
/* 4F32CC 8021BE2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F32D0 8021BE30 00000000 */  nop       
/* 4F32D4 8021BE34 00000043 */  sra       $zero, $zero, 1
/* 4F32D8 8021BE38 00000004 */  sllv      $zero, $zero, $zero
/* 4F32DC 8021BE3C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F32E0 8021BE40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F32E4 8021BE44 00000008 */  jr        $zero
/* 4F32E8 8021BE48 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F32EC 8021BE4C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F32F0 8021BE50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F32F4 8021BE54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F32F8 8021BE58 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F32FC 8021BE5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3300 8021BE60 00000000 */  nop       
/* 4F3304 8021BE64 00000043 */  sra       $zero, $zero, 1
/* 4F3308 8021BE68 00000003 */  sra       $zero, $zero, 0
/* 4F330C 8021BE6C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F3310 8021BE70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3314 8021BE74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3318 8021BE78 00000010 */  mfhi      $zero
/* 4F331C 8021BE7C 00000002 */  srl       $zero, $zero, 0
/* 4F3320 8021BE80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3324 8021BE84 00040000 */  sll       $zero, $a0, 0
/* 4F3328 8021BE88 00000043 */  sra       $zero, $zero, 1
/* 4F332C 8021BE8C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3330 8021BE90 8027D380 */  lb        $a3, -0x2c80($at)
/* 4F3334 8021BE94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3338 8021BE98 00000002 */  srl       $zero, $zero, 0
/* 4F333C 8021BE9C FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4F3340 8021BEA0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3344 8021BEA4 00000043 */  sra       $zero, $zero, 1
/* 4F3348 8021BEA8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F334C 8021BEAC 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4F3350 8021BEB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3354 8021BEB4 00000002 */  srl       $zero, $zero, 0
/* 4F3358 8021BEB8 00000002 */  srl       $zero, $zero, 0
/* 4F335C 8021BEBC FFFFFFF8 */  sd        $ra, -8($ra)
/* 4F3360 8021BEC0 00000043 */  sra       $zero, $zero, 1
/* 4F3364 8021BEC4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3368 8021BEC8 80218690 */  lb        $at, -0x7970($at)
/* 4F336C 8021BECC FFFFFFE7 */  sd        $ra, -0x19($ra)
/* 4F3370 8021BED0 0000000F */  sync      
/* 4F3374 8021BED4 00000000 */  nop       
/* 4F3378 8021BED8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F337C 8021BEDC 00000012 */  mflo      $zero
/* 4F3380 8021BEE0 00000000 */  nop       
/* 4F3384 8021BEE4 00000043 */  sra       $zero, $zero, 1
/* 4F3388 8021BEE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F338C 8021BEEC 8027D380 */  lb        $a3, -0x2c80($at)
/* 4F3390 8021BEF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3394 8021BEF4 00000002 */  srl       $zero, $zero, 0
/* 4F3398 8021BEF8 00000000 */  nop       
/* 4F339C 8021BEFC 00000027 */  not       $zero, $zero
/* 4F33A0 8021BF00 00000043 */  sra       $zero, $zero, 1
/* 4F33A4 8021BF04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F33A8 8021BF08 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4F33AC 8021BF0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F33B0 8021BF10 00000002 */  srl       $zero, $zero, 0
/* 4F33B4 8021BF14 FFFFFFFB */  sd        $ra, -5($ra)
/* 4F33B8 8021BF18 FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 4F33BC 8021BF1C 00000043 */  sra       $zero, $zero, 1
/* 4F33C0 8021BF20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F33C4 8021BF24 80218690 */  lb        $at, -0x7970($at)
/* 4F33C8 8021BF28 FFFFFFEF */  sd        $ra, -0x11($ra)
/* 4F33CC 8021BF2C 00000017 */  dsrav     $zero, $zero, $zero
/* 4F33D0 8021BF30 0000000B */  movn      $zero, $zero, $zero
/* 4F33D4 8021BF34 00000020 */  add       $zero, $zero, $zero
/* 4F33D8 8021BF38 00000013 */  mtlo      $zero
/* 4F33DC 8021BF3C 00000000 */  nop       
/* 4F33E0 8021BF40 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F33E4 8021BF44 00000001 */  movf      $zero, $zero, $fcc0
/* 4F33E8 8021BF48 00000001 */  movf      $zero, $zero, $fcc0
/* 4F33EC 8021BF4C 00000043 */  sra       $zero, $zero, 1
/* 4F33F0 8021BF50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F33F4 8021BF54 8027D380 */  lb        $a3, -0x2c80($at)
/* 4F33F8 8021BF58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F33FC 8021BF5C 00000002 */  srl       $zero, $zero, 0
/* 4F3400 8021BF60 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4F3404 8021BF64 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3408 8021BF68 00000043 */  sra       $zero, $zero, 1
/* 4F340C 8021BF6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3410 8021BF70 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4F3414 8021BF74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3418 8021BF78 00000002 */  srl       $zero, $zero, 0
/* 4F341C 8021BF7C 00000002 */  srl       $zero, $zero, 0
/* 4F3420 8021BF80 FFFFFFF8 */  sd        $ra, -8($ra)
/* 4F3424 8021BF84 00000043 */  sra       $zero, $zero, 1
/* 4F3428 8021BF88 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F342C 8021BF8C 80218690 */  lb        $at, -0x7970($at)
/* 4F3430 8021BF90 FFFFFFE7 */  sd        $ra, -0x19($ra)
/* 4F3434 8021BF94 0000000F */  sync      
/* 4F3438 8021BF98 00000000 */  nop       
/* 4F343C 8021BF9C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F3440 8021BFA0 00000023 */  negu      $zero, $zero
/* 4F3444 8021BFA4 00000000 */  nop       
/* 4F3448 8021BFA8 00000008 */  jr        $zero
/* 4F344C 8021BFAC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3450 8021BFB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3454 8021BFB4 00000004 */  sllv      $zero, $zero, $zero
/* 4F3458 8021BFB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F345C 8021BFBC 00000000 */  nop       
/* 4F3460 8021BFC0 00000002 */  srl       $zero, $zero, 0
/* 4F3464 8021BFC4 00000000 */  nop       
/* 4F3468 8021BFC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F346C 8021BFCC 00000000 */  nop       
/* 4F3470 8021BFD0 00000043 */  sra       $zero, $zero, 1
/* 4F3474 8021BFD4 00000003 */  sra       $zero, $zero, 0
/* 4F3478 8021BFD8 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F347C 8021BFDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3480 8021BFE0 00000000 */  nop       
/* 4F3484 8021BFE4 00000043 */  sra       $zero, $zero, 1
/* 4F3488 8021BFE8 00000003 */  sra       $zero, $zero, 0
/* 4F348C 8021BFEC 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F3490 8021BFF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3494 8021BFF4 00000000 */  nop       
/* 4F3498 8021BFF8 00000043 */  sra       $zero, $zero, 1
/* 4F349C 8021BFFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F34A0 8021C000 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F34A4 8021C004 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F34A8 8021C008 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F34AC 8021C00C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F34B0 8021C010 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F34B4 8021C014 00000043 */  sra       $zero, $zero, 1
/* 4F34B8 8021C018 00000002 */  srl       $zero, $zero, 0
/* 4F34BC 8021C01C 80269E54 */  lb        $a2, -0x61ac($at)
/* 4F34C0 8021C020 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 4F34C4 8021C024 00000043 */  sra       $zero, $zero, 1
/* 4F34C8 8021C028 00000003 */  sra       $zero, $zero, 0
/* 4F34CC 8021C02C 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 4F34D0 8021C030 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F34D4 8021C034 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F34D8 8021C038 00000014 */  dsllv     $zero, $zero, $zero
/* 4F34DC 8021C03C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F34E0 8021C040 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F34E4 8021C044 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F34E8 8021C048 00000001 */  movf      $zero, $zero, $fcc0
/* 4F34EC 8021C04C 00000009 */  jr        $zero
/* 4F34F0 8021C050 00000025 */   or       $zero, $zero, $zero
/* 4F34F4 8021C054 00000002 */  srl       $zero, $zero, 0
/* 4F34F8 8021C058 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F34FC 8021C05C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3500 8021C060 00000025 */  or        $zero, $zero, $zero
/* 4F3504 8021C064 00000002 */  srl       $zero, $zero, 0
/* 4F3508 8021C068 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F350C 8021C06C 00680006 */  srlv      $zero, $t0, $v1
/* 4F3510 8021C070 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3514 8021C074 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3518 8021C078 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F351C 8021C07C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3520 8021C080 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3524 8021C084 0000000A */  movz      $zero, $zero, $zero
/* 4F3528 8021C088 00000025 */  or        $zero, $zero, $zero
/* 4F352C 8021C08C 00000002 */  srl       $zero, $zero, 0
/* 4F3530 8021C090 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3534 8021C094 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3538 8021C098 00000025 */  or        $zero, $zero, $zero
/* 4F353C 8021C09C 00000002 */  srl       $zero, $zero, 0
/* 4F3540 8021C0A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3544 8021C0A4 00680006 */  srlv      $zero, $t0, $v1
/* 4F3548 8021C0A8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F354C 8021C0AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3550 8021C0B0 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F3554 8021C0B4 00000043 */  sra       $zero, $zero, 1
/* 4F3558 8021C0B8 00000004 */  sllv      $zero, $zero, $zero
/* 4F355C 8021C0BC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F3560 8021C0C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3564 8021C0C4 0000000D */  break     
/* 4F3568 8021C0C8 FE363C82 */   sd       $s6, 0x3c82($s1)
/* 4F356C 8021C0CC 0000000B */  movn      $zero, $zero, $zero
/* 4F3570 8021C0D0 00000002 */  srl       $zero, $zero, 0
/* 4F3574 8021C0D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3578 8021C0D8 00000000 */  nop       
/* 4F357C 8021C0DC 00000043 */  sra       $zero, $zero, 1
/* 4F3580 8021C0E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F3584 8021C0E4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F3588 8021C0E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F358C 8021C0EC 0000000D */  break     
/* 4F3590 8021C0F0 00000000 */   nop      
/* 4F3594 8021C0F4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3598 8021C0F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F359C 8021C0FC 8021C974 */  lb        $at, -0x368c($at)
/* 4F35A0 8021C100 00000013 */  mtlo      $zero
/* 4F35A4 8021C104 00000000 */  nop       
/* 4F35A8 8021C108 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F35AC 8021C10C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F35B0 8021C110 00000038 */  dsll      $zero, $zero, 0
/* 4F35B4 8021C114 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F35B8 8021C118 00000001 */  movf      $zero, $zero, $fcc0
/* 4F35BC 8021C11C 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F35C0 8021C120 00000024 */  and       $zero, $zero, $zero
/* 4F35C4 8021C124 00000002 */  srl       $zero, $zero, 0
/* 4F35C8 8021C128 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F35CC 8021C12C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F35D0 8021C130 00000024 */  and       $zero, $zero, $zero
/* 4F35D4 8021C134 00000002 */  srl       $zero, $zero, 0
/* 4F35D8 8021C138 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F35DC 8021C13C 00680012 */  .byte     0x00, 0x68, 0x00, 0x12
/* 4F35E0 8021C140 00000024 */  and       $zero, $zero, $zero
/* 4F35E4 8021C144 00000002 */  srl       $zero, $zero, 0
/* 4F35E8 8021C148 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F35EC 8021C14C 00680013 */  .byte     0x00, 0x68, 0x00, 0x13
/* 4F35F0 8021C150 00000046 */  rotrv     $zero, $zero, $zero
/* 4F35F4 8021C154 00000001 */  movf      $zero, $zero, $fcc0
/* 4F35F8 8021C158 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F35FC 8021C15C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3600 8021C160 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3604 8021C164 00000024 */  and       $zero, $zero, $zero
/* 4F3608 8021C168 00000024 */  and       $zero, $zero, $zero
/* 4F360C 8021C16C 00000002 */  srl       $zero, $zero, 0
/* 4F3610 8021C170 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3614 8021C174 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3618 8021C178 00000024 */  and       $zero, $zero, $zero
/* 4F361C 8021C17C 00000002 */  srl       $zero, $zero, 0
/* 4F3620 8021C180 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3624 8021C184 00680012 */  .byte     0x00, 0x68, 0x00, 0x12
/* 4F3628 8021C188 00000024 */  and       $zero, $zero, $zero
/* 4F362C 8021C18C 00000002 */  srl       $zero, $zero, 0
/* 4F3630 8021C190 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3634 8021C194 00680013 */  .byte     0x00, 0x68, 0x00, 0x13
/* 4F3638 8021C198 00000046 */  rotrv     $zero, $zero, $zero
/* 4F363C 8021C19C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3640 8021C1A0 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F3644 8021C1A4 00000008 */  jr        $zero
/* 4F3648 8021C1A8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F364C 8021C1AC 0000000A */  movz      $zero, $zero, $zero
/* 4F3650 8021C1B0 00000025 */  or        $zero, $zero, $zero
/* 4F3654 8021C1B4 00000002 */  srl       $zero, $zero, 0
/* 4F3658 8021C1B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F365C 8021C1BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3660 8021C1C0 00000025 */  or        $zero, $zero, $zero
/* 4F3664 8021C1C4 00000002 */  srl       $zero, $zero, 0
/* 4F3668 8021C1C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F366C 8021C1CC 00680013 */  .byte     0x00, 0x68, 0x00, 0x13
/* 4F3670 8021C1D0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3674 8021C1D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3678 8021C1D8 8021FA54 */  lb        $at, -0x5ac($at)
/* 4F367C 8021C1DC 00000002 */  srl       $zero, $zero, 0
/* 4F3680 8021C1E0 00000000 */  nop       
/* 4F3684 8021C1E4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3688 8021C1E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F368C 8021C1EC 0000000B */  movn      $zero, $zero, $zero
/* 4F3690 8021C1F0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3694 8021C1F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3698 8021C1F8 8021C748 */  lb        $at, -0x38b8($at)
/* 4F369C 8021C1FC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F36A0 8021C200 00000001 */  movf      $zero, $zero, $fcc0
/* 4F36A4 8021C204 0000002F */  dsubu     $zero, $zero, $zero
/* 4F36A8 8021C208 00000025 */  or        $zero, $zero, $zero
/* 4F36AC 8021C20C 00000002 */  srl       $zero, $zero, 0
/* 4F36B0 8021C210 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F36B4 8021C214 00000001 */  movf      $zero, $zero, $fcc0
/* 4F36B8 8021C218 00000025 */  or        $zero, $zero, $zero
/* 4F36BC 8021C21C 00000002 */  srl       $zero, $zero, 0
/* 4F36C0 8021C220 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F36C4 8021C224 0068000E */  .byte     0x00, 0x68, 0x00, 0x0e
/* 4F36C8 8021C228 00000046 */  rotrv     $zero, $zero, $zero
/* 4F36CC 8021C22C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F36D0 8021C230 8029A6FC */  lb        $t1, -0x5904($at)
/* 4F36D4 8021C234 00000025 */  or        $zero, $zero, $zero
/* 4F36D8 8021C238 00000002 */  srl       $zero, $zero, 0
/* 4F36DC 8021C23C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F36E0 8021C240 00000001 */  movf      $zero, $zero, $fcc0
/* 4F36E4 8021C244 00000025 */  or        $zero, $zero, $zero
/* 4F36E8 8021C248 00000002 */  srl       $zero, $zero, 0
/* 4F36EC 8021C24C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F36F0 8021C250 00680006 */  srlv      $zero, $t0, $v1
/* 4F36F4 8021C254 00000046 */  rotrv     $zero, $zero, $zero
/* 4F36F8 8021C258 00000001 */  movf      $zero, $zero, $fcc0
/* 4F36FC 8021C25C 8029BD70 */  lb        $t1, -0x4290($at)
/* 4F3700 8021C260 00000043 */  sra       $zero, $zero, 1
/* 4F3704 8021C264 00000006 */  srlv      $zero, $zero, $zero
/* 4F3708 8021C268 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F370C 8021C26C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3710 8021C270 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3714 8021C274 00000000 */  nop       
/* 4F3718 8021C278 00000001 */  movf      $zero, $zero, $fcc0
/* 4F371C 8021C27C 00000000 */  nop       
/* 4F3720 8021C280 00000025 */  or        $zero, $zero, $zero
/* 4F3724 8021C284 00000002 */  srl       $zero, $zero, 0
/* 4F3728 8021C288 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F372C 8021C28C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3730 8021C290 00000025 */  or        $zero, $zero, $zero
/* 4F3734 8021C294 00000002 */  srl       $zero, $zero, 0
/* 4F3738 8021C298 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F373C 8021C29C 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F3740 8021C2A0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3744 8021C2A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3748 8021C2A8 8029BEB8 */  lb        $t1, -0x4148($at)
/* 4F374C 8021C2AC 00000043 */  sra       $zero, $zero, 1
/* 4F3750 8021C2B0 00000003 */  sra       $zero, $zero, 0
/* 4F3754 8021C2B4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F3758 8021C2B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F375C 8021C2BC F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 4F3760 8021C2C0 00000043 */  sra       $zero, $zero, 1
/* 4F3764 8021C2C4 00000006 */  srlv      $zero, $zero, $zero
/* 4F3768 8021C2C8 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F376C 8021C2CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3770 8021C2D0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3774 8021C2D4 00000000 */  nop       
/* 4F3778 8021C2D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F377C 8021C2DC 00000000 */  nop       
/* 4F3780 8021C2E0 0000001D */  dmultu    $zero, $zero
/* 4F3784 8021C2E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3788 8021C2E8 00000017 */  dsrav     $zero, $zero, $zero
/* 4F378C 8021C2EC 0000001D */  dmultu    $zero, $zero
/* 4F3790 8021C2F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3794 8021C2F4 00000019 */  multu     $zero, $zero
/* 4F3798 8021C2F8 0000001D */  dmultu    $zero, $zero
/* 4F379C 8021C2FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F37A0 8021C300 0000001F */  ddivu     $zero, $zero, $zero
/* 4F37A4 8021C304 00000025 */  or        $zero, $zero, $zero
/* 4F37A8 8021C308 00000002 */  srl       $zero, $zero, 0
/* 4F37AC 8021C30C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F37B0 8021C310 00000001 */  movf      $zero, $zero, $fcc0
/* 4F37B4 8021C314 00000043 */  sra       $zero, $zero, 1
/* 4F37B8 8021C318 00000004 */  sllv      $zero, $zero, $zero
/* 4F37BC 8021C31C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F37C0 8021C320 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F37C4 8021C324 00000008 */  jr        $zero
/* 4F37C8 8021C328 FE363C81 */   sd       $s6, 0x3c81($s1)
/* 4F37CC 8021C32C 0000000A */  movz      $zero, $zero, $zero
/* 4F37D0 8021C330 00000002 */  srl       $zero, $zero, 0
/* 4F37D4 8021C334 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F37D8 8021C338 00000001 */  movf      $zero, $zero, $fcc0
/* 4F37DC 8021C33C 00000043 */  sra       $zero, $zero, 1
/* 4F37E0 8021C340 00000004 */  sllv      $zero, $zero, $zero
/* 4F37E4 8021C344 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F37E8 8021C348 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F37EC 8021C34C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F37F0 8021C350 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F37F4 8021C354 0000000B */  movn      $zero, $zero, $zero
/* 4F37F8 8021C358 00000002 */  srl       $zero, $zero, 0
/* 4F37FC 8021C35C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3800 8021C360 00000000 */  nop       
/* 4F3804 8021C364 00000025 */  or        $zero, $zero, $zero
/* 4F3808 8021C368 00000002 */  srl       $zero, $zero, 0
/* 4F380C 8021C36C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3810 8021C370 0068000A */  movz      $zero, $v1, $t0
/* 4F3814 8021C374 00000012 */  mflo      $zero
/* 4F3818 8021C378 00000000 */  nop       
/* 4F381C 8021C37C 00000025 */  or        $zero, $zero, $zero
/* 4F3820 8021C380 00000002 */  srl       $zero, $zero, 0
/* 4F3824 8021C384 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3828 8021C388 00680001 */  movf      $zero, $v1, $fcc2
/* 4F382C 8021C38C 00000013 */  mtlo      $zero
/* 4F3830 8021C390 00000000 */  nop       
/* 4F3834 8021C394 00000012 */  mflo      $zero
/* 4F3838 8021C398 00000000 */  nop       
/* 4F383C 8021C39C 00000025 */  or        $zero, $zero, $zero
/* 4F3840 8021C3A0 00000002 */  srl       $zero, $zero, 0
/* 4F3844 8021C3A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3848 8021C3A8 00680001 */  movf      $zero, $v1, $fcc2
/* 4F384C 8021C3AC 00000013 */  mtlo      $zero
/* 4F3850 8021C3B0 00000000 */  nop       
/* 4F3854 8021C3B4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3858 8021C3B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F385C 8021C3BC 8029AC70 */  lb        $t1, -0x5390($at)
/* 4F3860 8021C3C0 00000020 */  add       $zero, $zero, $zero
/* 4F3864 8021C3C4 00000000 */  nop       
/* 4F3868 8021C3C8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F386C 8021C3CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3870 8021C3D0 0000001B */  divu      $zero, $zero, $zero
/* 4F3874 8021C3D4 00000043 */  sra       $zero, $zero, 1
/* 4F3878 8021C3D8 00000004 */  sllv      $zero, $zero, $zero
/* 4F387C 8021C3DC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F3880 8021C3E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3884 8021C3E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3888 8021C3E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F388C 8021C3EC 0000000A */  movz      $zero, $zero, $zero
/* 4F3890 8021C3F0 00000002 */  srl       $zero, $zero, 0
/* 4F3894 8021C3F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3898 8021C3F8 00000000 */  nop       
/* 4F389C 8021C3FC 00000010 */  mfhi      $zero
/* 4F38A0 8021C400 00000002 */  srl       $zero, $zero, 0
/* 4F38A4 8021C404 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 4F38A8 8021C408 00000080 */  sll       $zero, $zero, 2
/* 4F38AC 8021C40C 00000043 */  sra       $zero, $zero, 1
/* 4F38B0 8021C410 00000004 */  sllv      $zero, $zero, $zero
/* 4F38B4 8021C414 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F38B8 8021C418 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F38BC 8021C41C 0000000B */  movn      $zero, $zero, $zero
/* 4F38C0 8021C420 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F38C4 8021C424 0000000A */  movz      $zero, $zero, $zero
/* 4F38C8 8021C428 00000002 */  srl       $zero, $zero, 0
/* 4F38CC 8021C42C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F38D0 8021C430 00000000 */  nop       
/* 4F38D4 8021C434 00000043 */  sra       $zero, $zero, 1
/* 4F38D8 8021C438 00000004 */  sllv      $zero, $zero, $zero
/* 4F38DC 8021C43C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F38E0 8021C440 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F38E4 8021C444 0000000B */  movn      $zero, $zero, $zero
/* 4F38E8 8021C448 00000001 */  movf      $zero, $zero, $fcc0
/* 4F38EC 8021C44C 00000008 */  jr        $zero
/* 4F38F0 8021C450 00000001 */   movf     $zero, $zero, $fcc0
/* 4F38F4 8021C454 0000003C */  dsll32    $zero, $zero, 0
/* 4F38F8 8021C458 00000013 */  mtlo      $zero
/* 4F38FC 8021C45C 00000000 */  nop       
/* 4F3900 8021C460 00000013 */  mtlo      $zero
/* 4F3904 8021C464 00000000 */  nop       
/* 4F3908 8021C468 00000013 */  mtlo      $zero
/* 4F390C 8021C46C 00000000 */  nop       
/* 4F3910 8021C470 0000001D */  dmultu    $zero, $zero
/* 4F3914 8021C474 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3918 8021C478 00000026 */  xor       $zero, $zero, $zero
/* 4F391C 8021C47C 0000001D */  dmultu    $zero, $zero
/* 4F3920 8021C480 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3924 8021C484 00000020 */  add       $zero, $zero, $zero
/* 4F3928 8021C488 00000025 */  or        $zero, $zero, $zero
/* 4F392C 8021C48C 00000002 */  srl       $zero, $zero, 0
/* 4F3930 8021C490 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3934 8021C494 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3938 8021C498 00000025 */  or        $zero, $zero, $zero
/* 4F393C 8021C49C 00000002 */  srl       $zero, $zero, 0
/* 4F3940 8021C4A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3944 8021C4A4 00680006 */  srlv      $zero, $t0, $v1
/* 4F3948 8021C4A8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F394C 8021C4AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3950 8021C4B0 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F3954 8021C4B4 00000008 */  jr        $zero
/* 4F3958 8021C4B8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F395C 8021C4BC 0000000A */  movz      $zero, $zero, $zero
/* 4F3960 8021C4C0 00000025 */  or        $zero, $zero, $zero
/* 4F3964 8021C4C4 00000002 */  srl       $zero, $zero, 0
/* 4F3968 8021C4C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F396C 8021C4CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3970 8021C4D0 00000025 */  or        $zero, $zero, $zero
/* 4F3974 8021C4D4 00000002 */  srl       $zero, $zero, 0
/* 4F3978 8021C4D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F397C 8021C4DC 00680006 */  srlv      $zero, $t0, $v1
/* 4F3980 8021C4E0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3984 8021C4E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3988 8021C4E8 8021FA54 */  lb        $at, -0x5ac($at)
/* 4F398C 8021C4EC 00000002 */  srl       $zero, $zero, 0
/* 4F3990 8021C4F0 00000000 */  nop       
/* 4F3994 8021C4F4 00000020 */  add       $zero, $zero, $zero
/* 4F3998 8021C4F8 00000000 */  nop       
/* 4F399C 8021C4FC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F39A0 8021C500 00000001 */  movf      $zero, $zero, $fcc0
/* 4F39A4 8021C504 00000021 */  addu      $zero, $zero, $zero
/* 4F39A8 8021C508 00000046 */  rotrv     $zero, $zero, $zero
/* 4F39AC 8021C50C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F39B0 8021C510 8021C748 */  lb        $at, -0x38b8($at)
/* 4F39B4 8021C514 00000025 */  or        $zero, $zero, $zero
/* 4F39B8 8021C518 00000002 */  srl       $zero, $zero, 0
/* 4F39BC 8021C51C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F39C0 8021C520 00000001 */  movf      $zero, $zero, $fcc0
/* 4F39C4 8021C524 00000025 */  or        $zero, $zero, $zero
/* 4F39C8 8021C528 00000002 */  srl       $zero, $zero, 0
/* 4F39CC 8021C52C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F39D0 8021C530 00680006 */  srlv      $zero, $t0, $v1
/* 4F39D4 8021C534 00000046 */  rotrv     $zero, $zero, $zero
/* 4F39D8 8021C538 00000001 */  movf      $zero, $zero, $fcc0
/* 4F39DC 8021C53C 8021FA54 */  lb        $at, -0x5ac($at)
/* 4F39E0 8021C540 00000002 */  srl       $zero, $zero, 0
/* 4F39E4 8021C544 00000000 */  nop       
/* 4F39E8 8021C548 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F39EC 8021C54C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F39F0 8021C550 0000002A */  slt       $zero, $zero, $zero
/* 4F39F4 8021C554 00000043 */  sra       $zero, $zero, 1
/* 4F39F8 8021C558 00000004 */  sllv      $zero, $zero, $zero
/* 4F39FC 8021C55C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3A00 8021C560 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A04 8021C564 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3A08 8021C568 00680006 */  srlv      $zero, $t0, $v1
/* 4F3A0C 8021C56C 00000008 */  jr        $zero
/* 4F3A10 8021C570 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3A14 8021C574 00000014 */  dsllv     $zero, $zero, $zero
/* 4F3A18 8021C578 00000043 */  sra       $zero, $zero, 1
/* 4F3A1C 8021C57C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3A20 8021C580 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3A24 8021C584 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A28 8021C588 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3A2C 8021C58C 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F3A30 8021C590 00000043 */  sra       $zero, $zero, 1
/* 4F3A34 8021C594 00000002 */  srl       $zero, $zero, 0
/* 4F3A38 8021C598 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F3A3C 8021C59C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A40 8021C5A0 00000043 */  sra       $zero, $zero, 1
/* 4F3A44 8021C5A4 00000003 */  sra       $zero, $zero, 0
/* 4F3A48 8021C5A8 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F3A4C 8021C5AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A50 8021C5B0 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F3A54 8021C5B4 00000043 */  sra       $zero, $zero, 1
/* 4F3A58 8021C5B8 00000004 */  sllv      $zero, $zero, $zero
/* 4F3A5C 8021C5BC 80279E64 */  lb        $a3, -0x619c($at)
/* 4F3A60 8021C5C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A64 8021C5C4 00000000 */  nop       
/* 4F3A68 8021C5C8 00000000 */  nop       
/* 4F3A6C 8021C5CC 00000043 */  sra       $zero, $zero, 1
/* 4F3A70 8021C5D0 00000004 */  sllv      $zero, $zero, $zero
/* 4F3A74 8021C5D4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3A78 8021C5D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3A7C 8021C5DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3A80 8021C5E0 00680001 */  movf      $zero, $v1, $fcc2
/* 4F3A84 8021C5E4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3A88 8021C5E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3A8C 8021C5EC 0000002C */  dadd      $zero, $zero, $zero
/* 4F3A90 8021C5F0 00000043 */  sra       $zero, $zero, 1
/* 4F3A94 8021C5F4 00000004 */  sllv      $zero, $zero, $zero
/* 4F3A98 8021C5F8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3A9C 8021C5FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3AA0 8021C600 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3AA4 8021C604 00680006 */  srlv      $zero, $t0, $v1
/* 4F3AA8 8021C608 00000008 */  jr        $zero
/* 4F3AAC 8021C60C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3AB0 8021C610 00000014 */  dsllv     $zero, $zero, $zero
/* 4F3AB4 8021C614 00000043 */  sra       $zero, $zero, 1
/* 4F3AB8 8021C618 00000004 */  sllv      $zero, $zero, $zero
/* 4F3ABC 8021C61C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3AC0 8021C620 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3AC4 8021C624 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3AC8 8021C628 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F3ACC 8021C62C 00000043 */  sra       $zero, $zero, 1
/* 4F3AD0 8021C630 00000002 */  srl       $zero, $zero, 0
/* 4F3AD4 8021C634 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F3AD8 8021C638 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3ADC 8021C63C 00000043 */  sra       $zero, $zero, 1
/* 4F3AE0 8021C640 00000003 */  sra       $zero, $zero, 0
/* 4F3AE4 8021C644 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F3AE8 8021C648 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3AEC 8021C64C F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F3AF0 8021C650 00000043 */  sra       $zero, $zero, 1
/* 4F3AF4 8021C654 00000004 */  sllv      $zero, $zero, $zero
/* 4F3AF8 8021C658 80279E64 */  lb        $a3, -0x619c($at)
/* 4F3AFC 8021C65C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3B00 8021C660 00000000 */  nop       
/* 4F3B04 8021C664 00000000 */  nop       
/* 4F3B08 8021C668 00000043 */  sra       $zero, $zero, 1
/* 4F3B0C 8021C66C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3B10 8021C670 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3B14 8021C674 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3B18 8021C678 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B1C 8021C67C 00680001 */  movf      $zero, $v1, $fcc2
/* 4F3B20 8021C680 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3B24 8021C684 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B28 8021C688 00000035 */  .byte     0x00, 0x00, 0x00, 0x35
/* 4F3B2C 8021C68C 00000025 */  or        $zero, $zero, $zero
/* 4F3B30 8021C690 00000002 */  srl       $zero, $zero, 0
/* 4F3B34 8021C694 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3B38 8021C698 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B3C 8021C69C 00000025 */  or        $zero, $zero, $zero
/* 4F3B40 8021C6A0 00000002 */  srl       $zero, $zero, 0
/* 4F3B44 8021C6A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3B48 8021C6A8 00680001 */  movf      $zero, $v1, $fcc2
/* 4F3B4C 8021C6AC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3B50 8021C6B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B54 8021C6B4 8029BEB8 */  lb        $t1, -0x4148($at)
/* 4F3B58 8021C6B8 00000043 */  sra       $zero, $zero, 1
/* 4F3B5C 8021C6BC 00000002 */  srl       $zero, $zero, 0
/* 4F3B60 8021C6C0 8026D664 */  lb        $a2, -0x299c($at)
/* 4F3B64 8021C6C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3B68 8021C6C8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F3B6C 8021C6CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B70 8021C6D0 00000031 */  tgeu      $zero, $zero
/* 4F3B74 8021C6D4 00000025 */  or        $zero, $zero, $zero
/* 4F3B78 8021C6D8 00000002 */  srl       $zero, $zero, 0
/* 4F3B7C 8021C6DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3B80 8021C6E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B84 8021C6E4 00000025 */  or        $zero, $zero, $zero
/* 4F3B88 8021C6E8 00000002 */  srl       $zero, $zero, 0
/* 4F3B8C 8021C6EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3B90 8021C6F0 00680001 */  movf      $zero, $v1, $fcc2
/* 4F3B94 8021C6F4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F3B98 8021C6F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3B9C 8021C6FC 8029BFA0 */  lb        $t1, -0x4060($at)
/* 4F3BA0 8021C700 0000001C */  dmult     $zero, $zero
/* 4F3BA4 8021C704 00000000 */  nop       
/* 4F3BA8 8021C708 00000023 */  negu      $zero, $zero
/* 4F3BAC 8021C70C 00000000 */  nop       
/* 4F3BB0 8021C710 00000043 */  sra       $zero, $zero, 1
/* 4F3BB4 8021C714 00000003 */  sra       $zero, $zero, 0
/* 4F3BB8 8021C718 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F3BBC 8021C71C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3BC0 8021C720 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3BC4 8021C724 00000043 */  sra       $zero, $zero, 1
/* 4F3BC8 8021C728 00000003 */  sra       $zero, $zero, 0
/* 4F3BCC 8021C72C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F3BD0 8021C730 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3BD4 8021C734 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3BD8 8021C738 00000002 */  srl       $zero, $zero, 0
/* 4F3BDC 8021C73C 00000000 */  nop       
/* 4F3BE0 8021C740 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3BE4 8021C744 00000000 */  nop       
/* 4F3BE8 8021C748 00000043 */  sra       $zero, $zero, 1
/* 4F3BEC 8021C74C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3BF0 8021C750 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3BF4 8021C754 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3BF8 8021C758 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3BFC 8021C75C 00680006 */  srlv      $zero, $t0, $v1
/* 4F3C00 8021C760 00000043 */  sra       $zero, $zero, 1
/* 4F3C04 8021C764 00000003 */  sra       $zero, $zero, 0
/* 4F3C08 8021C768 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F3C0C 8021C76C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3C10 8021C770 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F3C14 8021C774 00000043 */  sra       $zero, $zero, 1
/* 4F3C18 8021C778 00000003 */  sra       $zero, $zero, 0
/* 4F3C1C 8021C77C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F3C20 8021C780 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3C24 8021C784 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F3C28 8021C788 00000043 */  sra       $zero, $zero, 1
/* 4F3C2C 8021C78C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3C30 8021C790 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F3C34 8021C794 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3C38 8021C798 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3C3C 8021C79C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3C40 8021C7A0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3C44 8021C7A4 00000027 */  not       $zero, $zero
/* 4F3C48 8021C7A8 00000002 */  srl       $zero, $zero, 0
/* 4F3C4C 8021C7AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3C50 8021C7B0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F3C54 8021C7B4 00000043 */  sra       $zero, $zero, 1
/* 4F3C58 8021C7B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3C5C 8021C7BC 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F3C60 8021C7C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3C64 8021C7C4 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F3C68 8021C7C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3C6C 8021C7CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3C70 8021C7D0 00000043 */  sra       $zero, $zero, 1
/* 4F3C74 8021C7D4 00000006 */  srlv      $zero, $zero, $zero
/* 4F3C78 8021C7D8 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F3C7C 8021C7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3C80 8021C7E0 00000000 */  nop       
/* 4F3C84 8021C7E4 00000000 */  nop       
/* 4F3C88 8021C7E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3C8C 8021C7EC 00000000 */  nop       
/* 4F3C90 8021C7F0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F3C94 8021C7F4 00000002 */  srl       $zero, $zero, 0
/* 4F3C98 8021C7F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3C9C 8021C7FC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F3CA0 8021C800 00000043 */  sra       $zero, $zero, 1
/* 4F3CA4 8021C804 00000003 */  sra       $zero, $zero, 0
/* 4F3CA8 8021C808 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F3CAC 8021C80C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3CB0 8021C810 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F3CB4 8021C814 00000043 */  sra       $zero, $zero, 1
/* 4F3CB8 8021C818 00000003 */  sra       $zero, $zero, 0
/* 4F3CBC 8021C81C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F3CC0 8021C820 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3CC4 8021C824 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F3CC8 8021C828 00000043 */  sra       $zero, $zero, 1
/* 4F3CCC 8021C82C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3CD0 8021C830 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F3CD4 8021C834 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3CD8 8021C838 00000082 */  srl       $zero, $zero, 2
/* 4F3CDC 8021C83C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3CE0 8021C840 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3CE4 8021C844 00000043 */  sra       $zero, $zero, 1
/* 4F3CE8 8021C848 00000006 */  srlv      $zero, $zero, $zero
/* 4F3CEC 8021C84C 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F3CF0 8021C850 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3CF4 8021C854 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3CF8 8021C858 00000000 */  nop       
/* 4F3CFC 8021C85C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3D00 8021C860 00000000 */  nop       
/* 4F3D04 8021C864 00000043 */  sra       $zero, $zero, 1
/* 4F3D08 8021C868 00000004 */  sllv      $zero, $zero, $zero
/* 4F3D0C 8021C86C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3D10 8021C870 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D14 8021C874 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3D18 8021C878 00680007 */  srav      $zero, $t0, $v1
/* 4F3D1C 8021C87C 00000008 */  jr        $zero
/* 4F3D20 8021C880 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3D24 8021C884 0000000F */  sync      
/* 4F3D28 8021C888 00000043 */  sra       $zero, $zero, 1
/* 4F3D2C 8021C88C 00000004 */  sllv      $zero, $zero, $zero
/* 4F3D30 8021C890 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3D34 8021C894 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D38 8021C898 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3D3C 8021C89C 00680008 */  .byte     0x00, 0x68, 0x00, 0x08
/* 4F3D40 8021C8A0 00000043 */  sra       $zero, $zero, 1
/* 4F3D44 8021C8A4 00000003 */  sra       $zero, $zero, 0
/* 4F3D48 8021C8A8 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F3D4C 8021C8AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D50 8021C8B0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3D54 8021C8B4 00000043 */  sra       $zero, $zero, 1
/* 4F3D58 8021C8B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3D5C 8021C8BC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F3D60 8021C8C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D64 8021C8C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3D68 8021C8C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3D6C 8021C8CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3D70 8021C8D0 00000043 */  sra       $zero, $zero, 1
/* 4F3D74 8021C8D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3D78 8021C8D8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F3D7C 8021C8DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D80 8021C8E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3D84 8021C8E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3D88 8021C8E8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3D8C 8021C8EC 00000043 */  sra       $zero, $zero, 1
/* 4F3D90 8021C8F0 00000006 */  srlv      $zero, $zero, $zero
/* 4F3D94 8021C8F4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F3D98 8021C8F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3D9C 8021C8FC 00000008 */  jr        $zero
/* 4F3DA0 8021C900 00000000 */   nop      
/* 4F3DA4 8021C904 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3DA8 8021C908 00000000 */  nop       
/* 4F3DAC 8021C90C 00000043 */  sra       $zero, $zero, 1
/* 4F3DB0 8021C910 00000002 */  srl       $zero, $zero, 0
/* 4F3DB4 8021C914 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F3DB8 8021C918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3DBC 8021C91C 00000043 */  sra       $zero, $zero, 1
/* 4F3DC0 8021C920 00000004 */  sllv      $zero, $zero, $zero
/* 4F3DC4 8021C924 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3DC8 8021C928 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3DCC 8021C92C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3DD0 8021C930 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F3DD4 8021C934 00000043 */  sra       $zero, $zero, 1
/* 4F3DD8 8021C938 00000004 */  sllv      $zero, $zero, $zero
/* 4F3DDC 8021C93C 80279E64 */  lb        $a3, -0x619c($at)
/* 4F3DE0 8021C940 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3DE4 8021C944 0000000A */  movz      $zero, $zero, $zero
/* 4F3DE8 8021C948 00000000 */  nop       
/* 4F3DEC 8021C94C 00000043 */  sra       $zero, $zero, 1
/* 4F3DF0 8021C950 00000004 */  sllv      $zero, $zero, $zero
/* 4F3DF4 8021C954 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3DF8 8021C958 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3DFC 8021C95C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3E00 8021C960 00680001 */  movf      $zero, $v1, $fcc2
/* 4F3E04 8021C964 00000002 */  srl       $zero, $zero, 0
/* 4F3E08 8021C968 00000000 */  nop       
/* 4F3E0C 8021C96C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3E10 8021C970 00000000 */  nop       
/* 4F3E14 8021C974 00000043 */  sra       $zero, $zero, 1
/* 4F3E18 8021C978 00000004 */  sllv      $zero, $zero, $zero
/* 4F3E1C 8021C97C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F3E20 8021C980 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3E24 8021C984 00000008 */  jr        $zero
/* 4F3E28 8021C988 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F3E2C 8021C98C 0000000A */  movz      $zero, $zero, $zero
/* 4F3E30 8021C990 00000002 */  srl       $zero, $zero, 0
/* 4F3E34 8021C994 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3E38 8021C998 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3E3C 8021C99C 00000002 */  srl       $zero, $zero, 0
/* 4F3E40 8021C9A0 00000000 */  nop       
/* 4F3E44 8021C9A4 00000013 */  mtlo      $zero
/* 4F3E48 8021C9A8 00000000 */  nop       
/* 4F3E4C 8021C9AC 00000043 */  sra       $zero, $zero, 1
/* 4F3E50 8021C9B0 00000002 */  srl       $zero, $zero, 0
/* 4F3E54 8021C9B4 8027D32C */  lb        $a3, -0x2cd4($at)
/* 4F3E58 8021C9B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3E5C 8021C9BC 00000043 */  sra       $zero, $zero, 1
/* 4F3E60 8021C9C0 00000003 */  sra       $zero, $zero, 0
/* 4F3E64 8021C9C4 8025385C */  lb        $a1, 0x385c($at)
/* 4F3E68 8021C9C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3E6C 8021C9CC 000020E3 */  .byte     0x00, 0x00, 0x20, 0xe3
/* 4F3E70 8021C9D0 00000043 */  sra       $zero, $zero, 1
/* 4F3E74 8021C9D4 00000004 */  sllv      $zero, $zero, $zero
/* 4F3E78 8021C9D8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3E7C 8021C9DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3E80 8021C9E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3E84 8021C9E4 00680006 */  srlv      $zero, $t0, $v1
/* 4F3E88 8021C9E8 00000043 */  sra       $zero, $zero, 1
/* 4F3E8C 8021C9EC 00000003 */  sra       $zero, $zero, 0
/* 4F3E90 8021C9F0 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F3E94 8021C9F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3E98 8021C9F8 F24A7E1A */  scd       $t2, 0x7e1a($s2)
/* 4F3E9C 8021C9FC 00000043 */  sra       $zero, $zero, 1
/* 4F3EA0 8021CA00 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3EA4 8021CA04 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F3EA8 8021CA08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3EAC 8021CA0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3EB0 8021CA10 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3EB4 8021CA14 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3EB8 8021CA18 00000027 */  not       $zero, $zero
/* 4F3EBC 8021CA1C 00000002 */  srl       $zero, $zero, 0
/* 4F3EC0 8021CA20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3EC4 8021CA24 0000000A */  movz      $zero, $zero, $zero
/* 4F3EC8 8021CA28 00000024 */  and       $zero, $zero, $zero
/* 4F3ECC 8021CA2C 00000002 */  srl       $zero, $zero, 0
/* 4F3ED0 8021CA30 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3ED4 8021CA34 00000000 */  nop       
/* 4F3ED8 8021CA38 00000027 */  not       $zero, $zero
/* 4F3EDC 8021CA3C 00000002 */  srl       $zero, $zero, 0
/* 4F3EE0 8021CA40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3EE4 8021CA44 00000018 */  mult      $zero, $zero
/* 4F3EE8 8021CA48 00000043 */  sra       $zero, $zero, 1
/* 4F3EEC 8021CA4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3EF0 8021CA50 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F3EF4 8021CA54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3EF8 8021CA58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F3EFC 8021CA5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F3F00 8021CA60 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F3F04 8021CA64 00000043 */  sra       $zero, $zero, 1
/* 4F3F08 8021CA68 00000006 */  srlv      $zero, $zero, $zero
/* 4F3F0C 8021CA6C 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F3F10 8021CA70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3F14 8021CA74 00000010 */  mfhi      $zero
/* 4F3F18 8021CA78 00000000 */  nop       
/* 4F3F1C 8021CA7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F20 8021CA80 00000000 */  nop       
/* 4F3F24 8021CA84 00000056 */  drotrv    $zero, $zero, $zero
/* 4F3F28 8021CA88 00000000 */  nop       
/* 4F3F2C 8021CA8C 00000043 */  sra       $zero, $zero, 1
/* 4F3F30 8021CA90 00000006 */  srlv      $zero, $zero, $zero
/* 4F3F34 8021CA94 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4F3F38 8021CA98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3F3C 8021CA9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F40 8021CAA0 F24A7EE7 */  scd       $t2, 0x7ee7($s2)
/* 4F3F44 8021CAA4 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F3F48 8021CAA8 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3F4C 8021CAAC 00000008 */  jr        $zero
/* 4F3F50 8021CAB0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3F54 8021CAB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F58 8021CAB8 00000043 */  sra       $zero, $zero, 1
/* 4F3F5C 8021CABC 00000006 */  srlv      $zero, $zero, $zero
/* 4F3F60 8021CAC0 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4F3F64 8021CAC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3F68 8021CAC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F6C 8021CACC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3F70 8021CAD0 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F3F74 8021CAD4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3F78 8021CAD8 00000008 */  jr        $zero
/* 4F3F7C 8021CADC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F3F80 8021CAE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F84 8021CAE4 00000043 */  sra       $zero, $zero, 1
/* 4F3F88 8021CAE8 00000006 */  srlv      $zero, $zero, $zero
/* 4F3F8C 8021CAEC 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4F3F90 8021CAF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3F94 8021CAF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3F98 8021CAF8 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3F9C 8021CAFC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3FA0 8021CB00 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F3FA4 8021CB04 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F3FA8 8021CB08 00000000 */  nop       
/* 4F3FAC 8021CB0C 00000043 */  sra       $zero, $zero, 1
/* 4F3FB0 8021CB10 00000002 */  srl       $zero, $zero, 0
/* 4F3FB4 8021CB14 80254218 */  lb        $a1, 0x4218($at)
/* 4F3FB8 8021CB18 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3FBC 8021CB1C 00000043 */  sra       $zero, $zero, 1
/* 4F3FC0 8021CB20 00000003 */  sra       $zero, $zero, 0
/* 4F3FC4 8021CB24 8025385C */  lb        $a1, 0x385c($at)
/* 4F3FC8 8021CB28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3FCC 8021CB2C 000020E4 */  .byte     0x00, 0x00, 0x20, 0xe4
/* 4F3FD0 8021CB30 00000043 */  sra       $zero, $zero, 1
/* 4F3FD4 8021CB34 00000004 */  sllv      $zero, $zero, $zero
/* 4F3FD8 8021CB38 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F3FDC 8021CB3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F3FE0 8021CB40 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3FE4 8021CB44 00680007 */  srav      $zero, $t0, $v1
/* 4F3FE8 8021CB48 00000043 */  sra       $zero, $zero, 1
/* 4F3FEC 8021CB4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F3FF0 8021CB50 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F3FF4 8021CB54 00000001 */  movf      $zero, $zero, $fcc0
/* 4F3FF8 8021CB58 00000000 */  nop       
/* 4F3FFC 8021CB5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4000 8021CB60 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F4004 8021CB64 00000043 */  sra       $zero, $zero, 1
/* 4F4008 8021CB68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F400C 8021CB6C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F4010 8021CB70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4014 8021CB74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4018 8021CB78 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F401C 8021CB7C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4020 8021CB80 00000027 */  not       $zero, $zero
/* 4F4024 8021CB84 00000002 */  srl       $zero, $zero, 0
/* 4F4028 8021CB88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F402C 8021CB8C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4030 8021CB90 00000043 */  sra       $zero, $zero, 1
/* 4F4034 8021CB94 0000000F */  sync      
/* 4F4038 8021CB98 802D829C */  lb        $t5, -0x7d64($at)
/* 4F403C 8021CB9C 0000002F */  dsubu     $zero, $zero, $zero
/* 4F4040 8021CBA0 00000000 */  nop       
/* 4F4044 8021CBA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4048 8021CBA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F404C 8021CBAC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4050 8021CBB0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4054 8021CBB4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4058 8021CBB8 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F405C 8021CBBC 00000000 */  nop       
/* 4F4060 8021CBC0 00000000 */  nop       
/* 4F4064 8021CBC4 00000000 */  nop       
/* 4F4068 8021CBC8 00000000 */  nop       
/* 4F406C 8021CBCC 00000000 */  nop       
/* 4F4070 8021CBD0 00000000 */  nop       
/* 4F4074 8021CBD4 00000043 */  sra       $zero, $zero, 1
/* 4F4078 8021CBD8 00000004 */  sllv      $zero, $zero, $zero
/* 4F407C 8021CBDC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4080 8021CBE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4084 8021CBE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4088 8021CBE8 0068000A */  movz      $zero, $v1, $t0
/* 4F408C 8021CBEC 00000043 */  sra       $zero, $zero, 1
/* 4F4090 8021CBF0 00000003 */  sra       $zero, $zero, 0
/* 4F4094 8021CBF4 8025385C */  lb        $a1, 0x385c($at)
/* 4F4098 8021CBF8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F409C 8021CBFC 000020E5 */  .byte     0x00, 0x00, 0x20, 0xe5
/* 4F40A0 8021CC00 00000008 */  jr        $zero
/* 4F40A4 8021CC04 00000001 */   movf     $zero, $zero, $fcc0
/* 4F40A8 8021CC08 0000001E */  ddiv      $zero, $zero, $zero
/* 4F40AC 8021CC0C 00000043 */  sra       $zero, $zero, 1
/* 4F40B0 8021CC10 00000002 */  srl       $zero, $zero, 0
/* 4F40B4 8021CC14 802D7AE4 */  lb        $t5, 0x7ae4($at)
/* 4F40B8 8021CC18 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 4F40BC 8021CC1C 00000043 */  sra       $zero, $zero, 1
/* 4F40C0 8021CC20 00000004 */  sllv      $zero, $zero, $zero
/* 4F40C4 8021CC24 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F40C8 8021CC28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F40CC 8021CC2C 00000008 */  jr        $zero
/* 4F40D0 8021CC30 00000001 */   movf     $zero, $zero, $fcc0
/* 4F40D4 8021CC34 00000043 */  sra       $zero, $zero, 1
/* 4F40D8 8021CC38 00000004 */  sllv      $zero, $zero, $zero
/* 4F40DC 8021CC3C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F40E0 8021CC40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F40E4 8021CC44 00000007 */  srav      $zero, $zero, $zero
/* 4F40E8 8021CC48 00000000 */  nop       
/* 4F40EC 8021CC4C 00000043 */  sra       $zero, $zero, 1
/* 4F40F0 8021CC50 00000004 */  sllv      $zero, $zero, $zero
/* 4F40F4 8021CC54 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F40F8 8021CC58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F40FC 8021CC5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4100 8021CC60 00000002 */  srl       $zero, $zero, 0
/* 4F4104 8021CC64 00000043 */  sra       $zero, $zero, 1
/* 4F4108 8021CC68 00000004 */  sllv      $zero, $zero, $zero
/* 4F410C 8021CC6C 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F4110 8021CC70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4114 8021CC74 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4118 8021CC78 8021B9AC */  lb        $at, -0x4654($at)
/* 4F411C 8021CC7C 00000043 */  sra       $zero, $zero, 1
/* 4F4120 8021CC80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4124 8021CC84 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F4128 8021CC88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F412C 8021CC8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4130 8021CC90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4134 8021CC94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4138 8021CC98 00000043 */  sra       $zero, $zero, 1
/* 4F413C 8021CC9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4140 8021CCA0 8026A1EC */  lb        $a2, -0x5e14($at)
/* 4F4144 8021CCA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4148 8021CCA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F414C 8021CCAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4150 8021CCB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4154 8021CCB4 00000043 */  sra       $zero, $zero, 1
/* 4F4158 8021CCB8 00000002 */  srl       $zero, $zero, 0
/* 4F415C 8021CCBC 8026D664 */  lb        $a2, -0x299c($at)
/* 4F4160 8021CCC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4164 8021CCC4 00000002 */  srl       $zero, $zero, 0
/* 4F4168 8021CCC8 00000000 */  nop       
/* 4F416C 8021CCCC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4170 8021CCD0 00000000 */  nop       
/* 4F4174 8021CCD4 00000043 */  sra       $zero, $zero, 1
/* 4F4178 8021CCD8 00000003 */  sra       $zero, $zero, 0
/* 4F417C 8021CCDC 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F4180 8021CCE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4184 8021CCE4 00000000 */  nop       
/* 4F4188 8021CCE8 00000043 */  sra       $zero, $zero, 1
/* 4F418C 8021CCEC 00000003 */  sra       $zero, $zero, 0
/* 4F4190 8021CCF0 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F4194 8021CCF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4198 8021CCF8 00000000 */  nop       
/* 4F419C 8021CCFC 00000003 */  sra       $zero, $zero, 0
/* 4F41A0 8021CD00 00000001 */  movf      $zero, $zero, $fcc0
/* 4F41A4 8021CD04 00000000 */  nop       
/* 4F41A8 8021CD08 00000043 */  sra       $zero, $zero, 1
/* 4F41AC 8021CD0C 00000004 */  sllv      $zero, $zero, $zero
/* 4F41B0 8021CD10 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F41B4 8021CD14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F41B8 8021CD18 00000008 */  jr        $zero
/* 4F41BC 8021CD1C FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F41C0 8021CD20 0000000A */  movz      $zero, $zero, $zero
/* 4F41C4 8021CD24 00000002 */  srl       $zero, $zero, 0
/* 4F41C8 8021CD28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F41CC 8021CD2C 00000000 */  nop       
/* 4F41D0 8021CD30 00000043 */  sra       $zero, $zero, 1
/* 4F41D4 8021CD34 00000003 */  sra       $zero, $zero, 0
/* 4F41D8 8021CD38 8026DE5C */  lb        $a2, -0x21a4($at)
/* 4F41DC 8021CD3C 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F41E0 8021CD40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F41E4 8021CD44 0000000A */  movz      $zero, $zero, $zero
/* 4F41E8 8021CD48 00000002 */  srl       $zero, $zero, 0
/* 4F41EC 8021CD4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F41F0 8021CD50 00000000 */  nop       
/* 4F41F4 8021CD54 00000043 */  sra       $zero, $zero, 1
/* 4F41F8 8021CD58 00000004 */  sllv      $zero, $zero, $zero
/* 4F41FC 8021CD5C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F4200 8021CD60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4204 8021CD64 0000000C */  syscall   
/* 4F4208 8021CD68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F420C 8021CD6C 0000000A */  movz      $zero, $zero, $zero
/* 4F4210 8021CD70 00000002 */  srl       $zero, $zero, 0
/* 4F4214 8021CD74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4218 8021CD78 00000000 */  nop       
/* 4F421C 8021CD7C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4220 8021CD80 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4224 8021CD84 8021E9C8 */  lb        $at, -0x1638($at)
/* 4F4228 8021CD88 00000043 */  sra       $zero, $zero, 1
/* 4F422C 8021CD8C 00000003 */  sra       $zero, $zero, 0
/* 4F4230 8021CD90 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F4234 8021CD94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4238 8021CD98 00000001 */  movf      $zero, $zero, $fcc0
/* 4F423C 8021CD9C 00000043 */  sra       $zero, $zero, 1
/* 4F4240 8021CDA0 00000003 */  sra       $zero, $zero, 0
/* 4F4244 8021CDA4 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F4248 8021CDA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F424C 8021CDAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4250 8021CDB0 00000002 */  srl       $zero, $zero, 0
/* 4F4254 8021CDB4 00000000 */  nop       
/* 4F4258 8021CDB8 00000012 */  mflo      $zero
/* 4F425C 8021CDBC 00000000 */  nop       
/* 4F4260 8021CDC0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4264 8021CDC4 00000002 */  srl       $zero, $zero, 0
/* 4F4268 8021CDC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F426C 8021CDCC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4270 8021CDD0 00000043 */  sra       $zero, $zero, 1
/* 4F4274 8021CDD4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4278 8021CDD8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F427C 8021CDDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4280 8021CDE0 0000000C */  syscall   
/* 4F4284 8021CDE4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4288 8021CDE8 00000013 */  mtlo      $zero
/* 4F428C 8021CDEC 00000000 */  nop       
/* 4F4290 8021CDF0 00000013 */  mtlo      $zero
/* 4F4294 8021CDF4 00000000 */  nop       
/* 4F4298 8021CDF8 00000043 */  sra       $zero, $zero, 1
/* 4F429C 8021CDFC 00000003 */  sra       $zero, $zero, 0
/* 4F42A0 8021CE00 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F42A4 8021CE04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F42A8 8021CE08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F42AC 8021CE0C 00000010 */  mfhi      $zero
/* 4F42B0 8021CE10 00000002 */  srl       $zero, $zero, 0
/* 4F42B4 8021CE14 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F42B8 8021CE18 00080000 */  sll       $zero, $t0, 0
/* 4F42BC 8021CE1C 00000043 */  sra       $zero, $zero, 1
/* 4F42C0 8021CE20 00000004 */  sllv      $zero, $zero, $zero
/* 4F42C4 8021CE24 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F42C8 8021CE28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F42CC 8021CE2C 00000000 */  nop       
/* 4F42D0 8021CE30 00000001 */  movf      $zero, $zero, $fcc0
/* 4F42D4 8021CE34 00000013 */  mtlo      $zero
/* 4F42D8 8021CE38 00000000 */  nop       
/* 4F42DC 8021CE3C 00000043 */  sra       $zero, $zero, 1
/* 4F42E0 8021CE40 00000004 */  sllv      $zero, $zero, $zero
/* 4F42E4 8021CE44 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F42E8 8021CE48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F42EC 8021CE4C 00000000 */  nop       
/* 4F42F0 8021CE50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F42F4 8021CE54 00000014 */  dsllv     $zero, $zero, $zero
/* 4F42F8 8021CE58 00000001 */  movf      $zero, $zero, $fcc0
/* 4F42FC 8021CE5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4300 8021CE60 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F4304 8021CE64 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4308 8021CE68 00000000 */  nop       
/* 4F430C 8021CE6C 00000043 */  sra       $zero, $zero, 1
/* 4F4310 8021CE70 00000004 */  sllv      $zero, $zero, $zero
/* 4F4314 8021CE74 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F4318 8021CE78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F431C 8021CE7C 00000002 */  srl       $zero, $zero, 0
/* 4F4320 8021CE80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4324 8021CE84 0000000A */  movz      $zero, $zero, $zero
/* 4F4328 8021CE88 00000002 */  srl       $zero, $zero, 0
/* 4F432C 8021CE8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4330 8021CE90 00000000 */  nop       
/* 4F4334 8021CE94 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4338 8021CE98 00000001 */  movf      $zero, $zero, $fcc0
/* 4F433C 8021CE9C 8021D81C */  lb        $at, -0x27e4($at)
/* 4F4340 8021CEA0 00000043 */  sra       $zero, $zero, 1
/* 4F4344 8021CEA4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4348 8021CEA8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F434C 8021CEAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4350 8021CEB0 00000000 */  nop       
/* 4F4354 8021CEB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4358 8021CEB8 00000012 */  mflo      $zero
/* 4F435C 8021CEBC 00000000 */  nop       
/* 4F4360 8021CEC0 00000043 */  sra       $zero, $zero, 1
/* 4F4364 8021CEC4 00000003 */  sra       $zero, $zero, 0
/* 4F4368 8021CEC8 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F436C 8021CECC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4370 8021CED0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4374 8021CED4 00000011 */  mthi      $zero
/* 4F4378 8021CED8 00000002 */  srl       $zero, $zero, 0
/* 4F437C 8021CEDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4380 8021CEE0 00080000 */  sll       $zero, $t0, 0
/* 4F4384 8021CEE4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4388 8021CEE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F438C 8021CEEC 8021D04C */  lb        $at, -0x2fb4($at)
/* 4F4390 8021CEF0 00000043 */  sra       $zero, $zero, 1
/* 4F4394 8021CEF4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4398 8021CEF8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F439C 8021CEFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F43A0 8021CF00 00000000 */  nop       
/* 4F43A4 8021CF04 00000001 */  movf      $zero, $zero, $fcc0
/* 4F43A8 8021CF08 00000012 */  mflo      $zero
/* 4F43AC 8021CF0C 00000000 */  nop       
/* 4F43B0 8021CF10 00000046 */  rotrv     $zero, $zero, $zero
/* 4F43B4 8021CF14 00000001 */  movf      $zero, $zero, $fcc0
/* 4F43B8 8021CF18 8021D81C */  lb        $at, -0x27e4($at)
/* 4F43BC 8021CF1C 00000043 */  sra       $zero, $zero, 1
/* 4F43C0 8021CF20 00000004 */  sllv      $zero, $zero, $zero
/* 4F43C4 8021CF24 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F43C8 8021CF28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F43CC 8021CF2C 00000000 */  nop       
/* 4F43D0 8021CF30 00000000 */  nop       
/* 4F43D4 8021CF34 00000013 */  mtlo      $zero
/* 4F43D8 8021CF38 00000000 */  nop       
/* 4F43DC 8021CF3C 00000013 */  mtlo      $zero
/* 4F43E0 8021CF40 00000000 */  nop       
/* 4F43E4 8021CF44 0000001C */  dmult     $zero, $zero
/* 4F43E8 8021CF48 00000000 */  nop       
/* 4F43EC 8021CF4C 00000043 */  sra       $zero, $zero, 1
/* 4F43F0 8021CF50 00000004 */  sllv      $zero, $zero, $zero
/* 4F43F4 8021CF54 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F43F8 8021CF58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F43FC 8021CF5C 00000000 */  nop       
/* 4F4400 8021CF60 00000000 */  nop       
/* 4F4404 8021CF64 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4408 8021CF68 00000001 */  movf      $zero, $zero, $fcc0
/* 4F440C 8021CF6C 8021D81C */  lb        $at, -0x27e4($at)
/* 4F4410 8021CF70 00000023 */  negu      $zero, $zero
/* 4F4414 8021CF74 00000000 */  nop       
/* 4F4418 8021CF78 00000043 */  sra       $zero, $zero, 1
/* 4F441C 8021CF7C 00000003 */  sra       $zero, $zero, 0
/* 4F4420 8021CF80 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F4424 8021CF84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4428 8021CF88 00000001 */  movf      $zero, $zero, $fcc0
/* 4F442C 8021CF8C 00000043 */  sra       $zero, $zero, 1
/* 4F4430 8021CF90 00000003 */  sra       $zero, $zero, 0
/* 4F4434 8021CF94 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F4438 8021CF98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F443C 8021CF9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4440 8021CFA0 00000002 */  srl       $zero, $zero, 0
/* 4F4444 8021CFA4 00000000 */  nop       
/* 4F4448 8021CFA8 00000012 */  mflo      $zero
/* 4F444C 8021CFAC 00000000 */  nop       
/* 4F4450 8021CFB0 00000043 */  sra       $zero, $zero, 1
/* 4F4454 8021CFB4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4458 8021CFB8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F445C 8021CFBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4460 8021CFC0 00000007 */  srav      $zero, $zero, $zero
/* 4F4464 8021CFC4 00000000 */  nop       
/* 4F4468 8021CFC8 00000043 */  sra       $zero, $zero, 1
/* 4F446C 8021CFCC 00000004 */  sllv      $zero, $zero, $zero
/* 4F4470 8021CFD0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F4474 8021CFD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4478 8021CFD8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F447C 8021CFDC 00000000 */  nop       
/* 4F4480 8021CFE0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4484 8021CFE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4488 8021CFE8 8021F80C */  lb        $at, -0x7f4($at)
/* 4F448C 8021CFEC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4490 8021CFF0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4494 8021CFF4 8021F5E8 */  lb        $at, -0xa18($at)
/* 4F4498 8021CFF8 00000004 */  sllv      $zero, $zero, $zero
/* 4F449C 8021CFFC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F44A0 8021D000 00000000 */  nop       
/* 4F44A4 8021D004 00000013 */  mtlo      $zero
/* 4F44A8 8021D008 00000000 */  nop       
/* 4F44AC 8021D00C 00000043 */  sra       $zero, $zero, 1
/* 4F44B0 8021D010 00000003 */  sra       $zero, $zero, 0
/* 4F44B4 8021D014 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F44B8 8021D018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F44BC 8021D01C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F44C0 8021D020 00000043 */  sra       $zero, $zero, 1
/* 4F44C4 8021D024 00000003 */  sra       $zero, $zero, 0
/* 4F44C8 8021D028 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F44CC 8021D02C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F44D0 8021D030 00000001 */  movf      $zero, $zero, $fcc0
/* 4F44D4 8021D034 00000002 */  srl       $zero, $zero, 0
/* 4F44D8 8021D038 00000000 */  nop       
/* 4F44DC 8021D03C 00000002 */  srl       $zero, $zero, 0
/* 4F44E0 8021D040 00000000 */  nop       
/* 4F44E4 8021D044 00000001 */  movf      $zero, $zero, $fcc0
/* 4F44E8 8021D048 00000000 */  nop       
/* 4F44EC 8021D04C 00000043 */  sra       $zero, $zero, 1
/* 4F44F0 8021D050 00000003 */  sra       $zero, $zero, 0
/* 4F44F4 8021D054 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F44F8 8021D058 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F44FC 8021D05C 00000000 */  nop       
/* 4F4500 8021D060 00000043 */  sra       $zero, $zero, 1
/* 4F4504 8021D064 00000004 */  sllv      $zero, $zero, $zero
/* 4F4508 8021D068 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F450C 8021D06C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4510 8021D070 00000002 */  srl       $zero, $zero, 0
/* 4F4514 8021D074 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4518 8021D078 00000014 */  dsllv     $zero, $zero, $zero
/* 4F451C 8021D07C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4520 8021D080 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4524 8021D084 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F4528 8021D088 00000001 */  movf      $zero, $zero, $fcc0
/* 4F452C 8021D08C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4530 8021D090 00000024 */  and       $zero, $zero, $zero
/* 4F4534 8021D094 00000002 */  srl       $zero, $zero, 0
/* 4F4538 8021D098 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F453C 8021D09C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4540 8021D0A0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F4544 8021D0A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4548 8021D0A8 00000002 */  srl       $zero, $zero, 0
/* 4F454C 8021D0AC 00000024 */  and       $zero, $zero, $zero
/* 4F4550 8021D0B0 00000002 */  srl       $zero, $zero, 0
/* 4F4554 8021D0B4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4558 8021D0B8 00000004 */  sllv      $zero, $zero, $zero
/* 4F455C 8021D0BC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F4560 8021D0C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4564 8021D0C4 00000003 */  sra       $zero, $zero, 0
/* 4F4568 8021D0C8 00000024 */  and       $zero, $zero, $zero
/* 4F456C 8021D0CC 00000002 */  srl       $zero, $zero, 0
/* 4F4570 8021D0D0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4574 8021D0D4 00000003 */  sra       $zero, $zero, 0
/* 4F4578 8021D0D8 0000001C */  dmult     $zero, $zero
/* 4F457C 8021D0DC 00000000 */  nop       
/* 4F4580 8021D0E0 00000002 */  srl       $zero, $zero, 0
/* 4F4584 8021D0E4 00000000 */  nop       
/* 4F4588 8021D0E8 00000023 */  negu      $zero, $zero
/* 4F458C 8021D0EC 00000000 */  nop       
/* 4F4590 8021D0F0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4594 8021D0F4 00000002 */  srl       $zero, $zero, 0
/* 4F4598 8021D0F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F459C 8021D0FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F45A0 8021D100 00000043 */  sra       $zero, $zero, 1
/* 4F45A4 8021D104 00000004 */  sllv      $zero, $zero, $zero
/* 4F45A8 8021D108 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F45AC 8021D10C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F45B0 8021D110 00000002 */  srl       $zero, $zero, 0
/* 4F45B4 8021D114 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F45B8 8021D118 00000043 */  sra       $zero, $zero, 1
/* 4F45BC 8021D11C 00000002 */  srl       $zero, $zero, 0
/* 4F45C0 8021D120 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F45C4 8021D124 0000000F */  sync      
/* 4F45C8 8021D128 00000043 */  sra       $zero, $zero, 1
/* 4F45CC 8021D12C 00000002 */  srl       $zero, $zero, 0
/* 4F45D0 8021D130 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F45D4 8021D134 00000140 */  pause     
/* 4F45D8 8021D138 00000043 */  sra       $zero, $zero, 1
/* 4F45DC 8021D13C 00000002 */  srl       $zero, $zero, 0
/* 4F45E0 8021D140 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4F45E4 8021D144 00000000 */  nop       
/* 4F45E8 8021D148 00000043 */  sra       $zero, $zero, 1
/* 4F45EC 8021D14C 00000003 */  sra       $zero, $zero, 0
/* 4F45F0 8021D150 8024EB84 */  lb        $a0, -0x147c($at)
/* 4F45F4 8021D154 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F45F8 8021D158 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F45FC 8021D15C 00000043 */  sra       $zero, $zero, 1
/* 4F4600 8021D160 00000004 */  sllv      $zero, $zero, $zero
/* 4F4604 8021D164 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4608 8021D168 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F460C 8021D16C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4610 8021D170 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F4614 8021D174 00000043 */  sra       $zero, $zero, 1
/* 4F4618 8021D178 00000006 */  srlv      $zero, $zero, $zero
/* 4F461C 8021D17C 8026AB74 */  lb        $a2, -0x548c($at)
/* 4F4620 8021D180 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4624 8021D184 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4628 8021D188 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F462C 8021D18C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4630 8021D190 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4634 8021D194 00000027 */  not       $zero, $zero
/* 4F4638 8021D198 00000002 */  srl       $zero, $zero, 0
/* 4F463C 8021D19C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4640 8021D1A0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4644 8021D1A4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4648 8021D1A8 00000002 */  srl       $zero, $zero, 0
/* 4F464C 8021D1AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4650 8021D1B0 00000003 */  sra       $zero, $zero, 0
/* 4F4654 8021D1B4 00000043 */  sra       $zero, $zero, 1
/* 4F4658 8021D1B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F465C 8021D1BC 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F4660 8021D1C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4664 8021D1C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4668 8021D1C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F466C 8021D1CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4670 8021D1D0 00000043 */  sra       $zero, $zero, 1
/* 4F4674 8021D1D4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4678 8021D1D8 80279E64 */  lb        $a3, -0x619c($at)
/* 4F467C 8021D1DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4680 8021D1E0 0000000A */  movz      $zero, $zero, $zero
/* 4F4684 8021D1E4 00000000 */  nop       
/* 4F4688 8021D1E8 00000043 */  sra       $zero, $zero, 1
/* 4F468C 8021D1EC 00000004 */  sllv      $zero, $zero, $zero
/* 4F4690 8021D1F0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4694 8021D1F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4698 8021D1F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F469C 8021D1FC 00680001 */  movf      $zero, $v1, $fcc2
/* 4F46A0 8021D200 00000008 */  jr        $zero
/* 4F46A4 8021D204 00000001 */   movf     $zero, $zero, $fcc0
/* 4F46A8 8021D208 0000000A */  movz      $zero, $zero, $zero
/* 4F46AC 8021D20C 00000043 */  sra       $zero, $zero, 1
/* 4F46B0 8021D210 00000004 */  sllv      $zero, $zero, $zero
/* 4F46B4 8021D214 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F46B8 8021D218 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F46BC 8021D21C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F46C0 8021D220 00680004 */  sllv      $zero, $t0, $v1
/* 4F46C4 8021D224 00000008 */  jr        $zero
/* 4F46C8 8021D228 00000001 */   movf     $zero, $zero, $fcc0
/* 4F46CC 8021D22C 00000007 */  srav      $zero, $zero, $zero
/* 4F46D0 8021D230 00000043 */  sra       $zero, $zero, 1
/* 4F46D4 8021D234 00000006 */  srlv      $zero, $zero, $zero
/* 4F46D8 8021D238 8026AB74 */  lb        $a2, -0x548c($at)
/* 4F46DC 8021D23C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F46E0 8021D240 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F46E4 8021D244 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F46E8 8021D248 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F46EC 8021D24C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F46F0 8021D250 00000027 */  not       $zero, $zero
/* 4F46F4 8021D254 00000002 */  srl       $zero, $zero, 0
/* 4F46F8 8021D258 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F46FC 8021D25C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4700 8021D260 00000027 */  not       $zero, $zero
/* 4F4704 8021D264 00000002 */  srl       $zero, $zero, 0
/* 4F4708 8021D268 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F470C 8021D26C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4710 8021D270 00000043 */  sra       $zero, $zero, 1
/* 4F4714 8021D274 00000004 */  sllv      $zero, $zero, $zero
/* 4F4718 8021D278 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F471C 8021D27C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4720 8021D280 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4724 8021D284 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F4728 8021D288 00000043 */  sra       $zero, $zero, 1
/* 4F472C 8021D28C 00000008 */  jr        $zero
/* 4F4730 8021D290 8027A4E4 */   lb       $a3, -0x5b1c($at)
/* 4F4734 8021D294 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4738 8021D298 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F473C 8021D29C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4740 8021D2A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4744 8021D2A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4748 8021D2A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F474C 8021D2AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4750 8021D2B0 00000008 */  jr        $zero
/* 4F4754 8021D2B4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4758 8021D2B8 00000008 */  jr        $zero
/* 4F475C 8021D2BC 00000043 */   sra      $zero, $zero, 1
/* 4F4760 8021D2C0 00000004 */  sllv      $zero, $zero, $zero
/* 4F4764 8021D2C4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4768 8021D2C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F476C 8021D2CC FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4770 8021D2D0 00330005 */  lsa       $zero, $at, $s3, 1
/* 4F4774 8021D2D4 00000043 */  sra       $zero, $zero, 1
/* 4F4778 8021D2D8 00000003 */  sra       $zero, $zero, 0
/* 4F477C 8021D2DC 8025385C */  lb        $a1, 0x385c($at)
/* 4F4780 8021D2E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4784 8021D2E4 000002F9 */  .byte     0x00, 0x00, 0x02, 0xf9
/* 4F4788 8021D2E8 00000043 */  sra       $zero, $zero, 1
/* 4F478C 8021D2EC 00000002 */  srl       $zero, $zero, 0
/* 4F4790 8021D2F0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4794 8021D2F4 00000002 */  srl       $zero, $zero, 0
/* 4F4798 8021D2F8 00000043 */  sra       $zero, $zero, 1
/* 4F479C 8021D2FC 00000007 */  srav      $zero, $zero, $zero
/* 4F47A0 8021D300 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F47A4 8021D304 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F47A8 8021D308 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F47AC 8021D30C 00000000 */  nop       
/* 4F47B0 8021D310 00000000 */  nop       
/* 4F47B4 8021D314 00000001 */  movf      $zero, $zero, $fcc0
/* 4F47B8 8021D318 00000010 */  mfhi      $zero
/* 4F47BC 8021D31C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F47C0 8021D320 00000001 */  movf      $zero, $zero, $fcc0
/* 4F47C4 8021D324 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F47C8 8021D328 0000001D */  dmultu    $zero, $zero
/* 4F47CC 8021D32C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F47D0 8021D330 00000006 */  srlv      $zero, $zero, $zero
/* 4F47D4 8021D334 0000001D */  dmultu    $zero, $zero
/* 4F47D8 8021D338 00000001 */  movf      $zero, $zero, $fcc0
/* 4F47DC 8021D33C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F47E0 8021D340 00000043 */  sra       $zero, $zero, 1
/* 4F47E4 8021D344 00000004 */  sllv      $zero, $zero, $zero
/* 4F47E8 8021D348 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F47EC 8021D34C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F47F0 8021D350 00000001 */  movf      $zero, $zero, $fcc0
/* 4F47F4 8021D354 00680005 */  lsa       $zero, $v1, $t0, 1
/* 4F47F8 8021D358 00000043 */  sra       $zero, $zero, 1
/* 4F47FC 8021D35C 00000004 */  sllv      $zero, $zero, $zero
/* 4F4800 8021D360 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F4804 8021D364 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4808 8021D368 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F480C 8021D36C F24AB280 */  scd       $t2, -0x4d80($s2)
/* 4F4810 8021D370 00000043 */  sra       $zero, $zero, 1
/* 4F4814 8021D374 00000004 */  sllv      $zero, $zero, $zero
/* 4F4818 8021D378 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F481C 8021D37C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4820 8021D380 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4824 8021D384 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F4828 8021D388 00000043 */  sra       $zero, $zero, 1
/* 4F482C 8021D38C 00000002 */  srl       $zero, $zero, 0
/* 4F4830 8021D390 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F4834 8021D394 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4838 8021D398 00000043 */  sra       $zero, $zero, 1
/* 4F483C 8021D39C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4840 8021D3A0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F4844 8021D3A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4848 8021D3A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F484C 8021D3AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4850 8021D3B0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4854 8021D3B4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4858 8021D3B8 00000002 */  srl       $zero, $zero, 0
/* 4F485C 8021D3BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4860 8021D3C0 00000032 */  tlt       $zero, $zero
/* 4F4864 8021D3C4 00000024 */  and       $zero, $zero, $zero
/* 4F4868 8021D3C8 00000002 */  srl       $zero, $zero, 0
/* 4F486C 8021D3CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4870 8021D3D0 FFFFFFFB */  sd        $ra, -5($ra)
/* 4F4874 8021D3D4 00000043 */  sra       $zero, $zero, 1
/* 4F4878 8021D3D8 00000009 */  jr        $zero
/* 4F487C 8021D3DC 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4F4880 8021D3E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4884 8021D3E4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4888 8021D3E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F488C 8021D3EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4890 8021D3F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4894 8021D3F4 00000000 */  nop       
/* 4F4898 8021D3F8 0000001E */  ddiv      $zero, $zero, $zero
/* 4F489C 8021D3FC 00000000 */  nop       
/* 4F48A0 8021D400 00000043 */  sra       $zero, $zero, 1
/* 4F48A4 8021D404 00000002 */  srl       $zero, $zero, 0
/* 4F48A8 8021D408 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F48AC 8021D40C 00000002 */  srl       $zero, $zero, 0
/* 4F48B0 8021D410 00000043 */  sra       $zero, $zero, 1
/* 4F48B4 8021D414 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F48B8 8021D418 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F48BC 8021D41C 00000000 */  nop       
/* 4F48C0 8021D420 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F48C4 8021D424 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F48C8 8021D428 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F48CC 8021D42C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F48D0 8021D430 00000002 */  srl       $zero, $zero, 0
/* 4F48D4 8021D434 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F48D8 8021D438 00000041 */  .byte     0x00, 0x00, 0x00, 0x41
/* 4F48DC 8021D43C 00000024 */  and       $zero, $zero, $zero
/* 4F48E0 8021D440 00000002 */  srl       $zero, $zero, 0
/* 4F48E4 8021D444 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F48E8 8021D448 FFFFFFFB */  sd        $ra, -5($ra)
/* 4F48EC 8021D44C 00000043 */  sra       $zero, $zero, 1
/* 4F48F0 8021D450 00000004 */  sllv      $zero, $zero, $zero
/* 4F48F4 8021D454 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F48F8 8021D458 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F48FC 8021D45C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4900 8021D460 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F4904 8021D464 00000043 */  sra       $zero, $zero, 1
/* 4F4908 8021D468 00000004 */  sllv      $zero, $zero, $zero
/* 4F490C 8021D46C 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F4910 8021D470 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4914 8021D474 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4918 8021D478 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F491C 8021D47C 00000043 */  sra       $zero, $zero, 1
/* 4F4920 8021D480 00000009 */  jr        $zero
/* 4F4924 8021D484 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4F4928 8021D488 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F492C 8021D48C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4930 8021D490 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4934 8021D494 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4938 8021D498 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F493C 8021D49C 00000000 */  nop       
/* 4F4940 8021D4A0 0000000F */  sync      
/* 4F4944 8021D4A4 00000000 */  nop       
/* 4F4948 8021D4A8 00000043 */  sra       $zero, $zero, 1
/* 4F494C 8021D4AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4950 8021D4B0 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F4954 8021D4B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4958 8021D4B8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F495C 8021D4BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4960 8021D4C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4964 8021D4C4 0000000A */  movz      $zero, $zero, $zero
/* 4F4968 8021D4C8 00000002 */  srl       $zero, $zero, 0
/* 4F496C 8021D4CC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F4970 8021D4D0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4974 8021D4D4 00000043 */  sra       $zero, $zero, 1
/* 4F4978 8021D4D8 00000007 */  srav      $zero, $zero, $zero
/* 4F497C 8021D4DC 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F4980 8021D4E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4984 8021D4E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4988 8021D4E8 80000000 */  lb        $zero, ($zero)
/* 4F498C 8021D4EC 00000000 */  nop       
/* 4F4990 8021D4F0 00000000 */  nop       
/* 4F4994 8021D4F4 00000000 */  nop       
/* 4F4998 8021D4F8 00000013 */  mtlo      $zero
/* 4F499C 8021D4FC 00000000 */  nop       
/* 4F49A0 8021D500 00000043 */  sra       $zero, $zero, 1
/* 4F49A4 8021D504 00000002 */  srl       $zero, $zero, 0
/* 4F49A8 8021D508 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F49AC 8021D50C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F49B0 8021D510 00000043 */  sra       $zero, $zero, 1
/* 4F49B4 8021D514 00000004 */  sllv      $zero, $zero, $zero
/* 4F49B8 8021D518 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F49BC 8021D51C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F49C0 8021D520 00000001 */  movf      $zero, $zero, $fcc0
/* 4F49C4 8021D524 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F49C8 8021D528 00000043 */  sra       $zero, $zero, 1
/* 4F49CC 8021D52C 00000004 */  sllv      $zero, $zero, $zero
/* 4F49D0 8021D530 80279E64 */  lb        $a3, -0x619c($at)
/* 4F49D4 8021D534 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F49D8 8021D538 0000000A */  movz      $zero, $zero, $zero
/* 4F49DC 8021D53C 00000000 */  nop       
/* 4F49E0 8021D540 00000043 */  sra       $zero, $zero, 1
/* 4F49E4 8021D544 00000004 */  sllv      $zero, $zero, $zero
/* 4F49E8 8021D548 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F49EC 8021D54C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F49F0 8021D550 00000001 */  movf      $zero, $zero, $fcc0
/* 4F49F4 8021D554 00680001 */  movf      $zero, $v1, $fcc2
/* 4F49F8 8021D558 00000002 */  srl       $zero, $zero, 0
/* 4F49FC 8021D55C 00000000 */  nop       
/* 4F4A00 8021D560 00000023 */  negu      $zero, $zero
/* 4F4A04 8021D564 00000000 */  nop       
/* 4F4A08 8021D568 00000043 */  sra       $zero, $zero, 1
/* 4F4A0C 8021D56C 00000004 */  sllv      $zero, $zero, $zero
/* 4F4A10 8021D570 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4A14 8021D574 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A18 8021D578 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4A1C 8021D57C 00680005 */  lsa       $zero, $v1, $t0, 1
/* 4F4A20 8021D580 00000043 */  sra       $zero, $zero, 1
/* 4F4A24 8021D584 00000004 */  sllv      $zero, $zero, $zero
/* 4F4A28 8021D588 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F4A2C 8021D58C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A30 8021D590 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4A34 8021D594 F24AB280 */  scd       $t2, -0x4d80($s2)
/* 4F4A38 8021D598 00000043 */  sra       $zero, $zero, 1
/* 4F4A3C 8021D59C 00000004 */  sllv      $zero, $zero, $zero
/* 4F4A40 8021D5A0 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F4A44 8021D5A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A48 8021D5A8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4A4C 8021D5AC F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F4A50 8021D5B0 00000043 */  sra       $zero, $zero, 1
/* 4F4A54 8021D5B4 00000002 */  srl       $zero, $zero, 0
/* 4F4A58 8021D5B8 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F4A5C 8021D5BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A60 8021D5C0 00000043 */  sra       $zero, $zero, 1
/* 4F4A64 8021D5C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4A68 8021D5C8 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F4A6C 8021D5CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A70 8021D5D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4A74 8021D5D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4A78 8021D5D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4A7C 8021D5DC 00000043 */  sra       $zero, $zero, 1
/* 4F4A80 8021D5E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F4A84 8021D5E4 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F4A88 8021D5E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4A8C 8021D5EC FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4A90 8021D5F0 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F4A94 8021D5F4 00000043 */  sra       $zero, $zero, 1
/* 4F4A98 8021D5F8 00000009 */  jr        $zero
/* 4F4A9C 8021D5FC 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4F4AA0 8021D600 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4AA4 8021D604 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4AA8 8021D608 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4AAC 8021D60C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4AB0 8021D610 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4AB4 8021D614 00000000 */  nop       
/* 4F4AB8 8021D618 0000001E */  ddiv      $zero, $zero, $zero
/* 4F4ABC 8021D61C 00000000 */  nop       
/* 4F4AC0 8021D620 00000008 */  jr        $zero
/* 4F4AC4 8021D624 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4AC8 8021D628 00000002 */  srl       $zero, $zero, 0
/* 4F4ACC 8021D62C 00000043 */  sra       $zero, $zero, 1
/* 4F4AD0 8021D630 00000008 */  jr        $zero
/* 4F4AD4 8021D634 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F4AD8 8021D638 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4ADC 8021D63C FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4F4AE0 8021D640 10000000 */  b         .L8021D644
.L8021D644:
/* 4F4AE4 8021D644 00000000 */   nop      
/* 4F4AE8 8021D648 00000000 */  nop       
/* 4F4AEC 8021D64C 00000003 */  sra       $zero, $zero, 0
/* 4F4AF0 8021D650 00000020 */  add       $zero, $zero, $zero
/* 4F4AF4 8021D654 00000043 */  sra       $zero, $zero, 1
/* 4F4AF8 8021D658 00000002 */  srl       $zero, $zero, 0
/* 4F4AFC 8021D65C 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4B00 8021D660 00000002 */  srl       $zero, $zero, 0
/* 4F4B04 8021D664 00000043 */  sra       $zero, $zero, 1
/* 4F4B08 8021D668 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4B0C 8021D66C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F4B10 8021D670 00000000 */  nop       
/* 4F4B14 8021D674 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4B18 8021D678 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4B1C 8021D67C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4B20 8021D680 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4B24 8021D684 00000002 */  srl       $zero, $zero, 0
/* 4F4B28 8021D688 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4B2C 8021D68C 00000037 */  .byte     0x00, 0x00, 0x00, 0x37
/* 4F4B30 8021D690 00000024 */  and       $zero, $zero, $zero
/* 4F4B34 8021D694 00000002 */  srl       $zero, $zero, 0
/* 4F4B38 8021D698 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4B3C 8021D69C 00000000 */  nop       
/* 4F4B40 8021D6A0 00000043 */  sra       $zero, $zero, 1
/* 4F4B44 8021D6A4 00000004 */  sllv      $zero, $zero, $zero
/* 4F4B48 8021D6A8 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F4B4C 8021D6AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4B50 8021D6B0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4B54 8021D6B4 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F4B58 8021D6B8 00000043 */  sra       $zero, $zero, 1
/* 4F4B5C 8021D6BC 00000004 */  sllv      $zero, $zero, $zero
/* 4F4B60 8021D6C0 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F4B64 8021D6C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4B68 8021D6C8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4B6C 8021D6CC F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F4B70 8021D6D0 00000043 */  sra       $zero, $zero, 1
/* 4F4B74 8021D6D4 00000009 */  jr        $zero
/* 4F4B78 8021D6D8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4F4B7C 8021D6DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4B80 8021D6E0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4B84 8021D6E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4B88 8021D6E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4B8C 8021D6EC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4B90 8021D6F0 00000000 */  nop       
/* 4F4B94 8021D6F4 00000019 */  multu     $zero, $zero
/* 4F4B98 8021D6F8 00000000 */  nop       
/* 4F4B9C 8021D6FC 00000043 */  sra       $zero, $zero, 1
/* 4F4BA0 8021D700 00000004 */  sllv      $zero, $zero, $zero
/* 4F4BA4 8021D704 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F4BA8 8021D708 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4BAC 8021D70C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4BB0 8021D710 F24A8A80 */  scd       $t2, -0x7580($s2)
/* 4F4BB4 8021D714 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4BB8 8021D718 00000002 */  srl       $zero, $zero, 0
/* 4F4BBC 8021D71C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4BC0 8021D720 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4BC4 8021D724 00000043 */  sra       $zero, $zero, 1
/* 4F4BC8 8021D728 00000009 */  jr        $zero
/* 4F4BCC 8021D72C 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4F4BD0 8021D730 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4BD4 8021D734 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4BD8 8021D738 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4BDC 8021D73C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4BE0 8021D740 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4BE4 8021D744 00000000 */  nop       
/* 4F4BE8 8021D748 00000015 */  dlsa      $zero, $zero, $zero, 1
/* 4F4BEC 8021D74C 00000000 */  nop       
/* 4F4BF0 8021D750 00000043 */  sra       $zero, $zero, 1
/* 4F4BF4 8021D754 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4BF8 8021D758 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F4BFC 8021D75C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4C00 8021D760 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4F4C04 8021D764 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4C08 8021D768 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4C0C 8021D76C 00000008 */  jr        $zero
/* 4F4C10 8021D770 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4C14 8021D774 00000013 */  mtlo      $zero
/* 4F4C18 8021D778 0000000A */  movz      $zero, $zero, $zero
/* 4F4C1C 8021D77C 00000002 */  srl       $zero, $zero, 0
/* 4F4C20 8021D780 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4F4C24 8021D784 0000000A */  movz      $zero, $zero, $zero
/* 4F4C28 8021D788 00000002 */  srl       $zero, $zero, 0
/* 4F4C2C 8021D78C 00000000 */  nop       
/* 4F4C30 8021D790 00000013 */  mtlo      $zero
/* 4F4C34 8021D794 00000000 */  nop       
/* 4F4C38 8021D798 00000043 */  sra       $zero, $zero, 1
/* 4F4C3C 8021D79C 00000002 */  srl       $zero, $zero, 0
/* 4F4C40 8021D7A0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4C44 8021D7A4 00000002 */  srl       $zero, $zero, 0
/* 4F4C48 8021D7A8 00000043 */  sra       $zero, $zero, 1
/* 4F4C4C 8021D7AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4C50 8021D7B0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4F4C54 8021D7B4 00000043 */  sra       $zero, $zero, 1
/* 4F4C58 8021D7B8 00000002 */  srl       $zero, $zero, 0
/* 4F4C5C 8021D7BC 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F4C60 8021D7C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4C64 8021D7C4 00000043 */  sra       $zero, $zero, 1
/* 4F4C68 8021D7C8 00000004 */  sllv      $zero, $zero, $zero
/* 4F4C6C 8021D7CC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4C70 8021D7D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4C74 8021D7D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4C78 8021D7D8 00680002 */  .byte     0x00, 0x68, 0x00, 0x02
/* 4F4C7C 8021D7DC 00000043 */  sra       $zero, $zero, 1
/* 4F4C80 8021D7E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F4C84 8021D7E4 80279E64 */  lb        $a3, -0x619c($at)
/* 4F4C88 8021D7E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4C8C 8021D7EC 0000000A */  movz      $zero, $zero, $zero
/* 4F4C90 8021D7F0 00000000 */  nop       
/* 4F4C94 8021D7F4 00000043 */  sra       $zero, $zero, 1
/* 4F4C98 8021D7F8 00000004 */  sllv      $zero, $zero, $zero
/* 4F4C9C 8021D7FC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4CA0 8021D800 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4CA4 8021D804 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4CA8 8021D808 00680001 */  movf      $zero, $v1, $fcc2
/* 4F4CAC 8021D80C 00000002 */  srl       $zero, $zero, 0
/* 4F4CB0 8021D810 00000000 */  nop       
/* 4F4CB4 8021D814 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4CB8 8021D818 00000000 */  nop       
/* 4F4CBC 8021D81C 00000043 */  sra       $zero, $zero, 1
/* 4F4CC0 8021D820 00000002 */  srl       $zero, $zero, 0
/* 4F4CC4 8021D824 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4CC8 8021D828 0000000F */  sync      
/* 4F4CCC 8021D82C 00000043 */  sra       $zero, $zero, 1
/* 4F4CD0 8021D830 00000002 */  srl       $zero, $zero, 0
/* 4F4CD4 8021D834 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F4CD8 8021D838 0000015E */  .byte     0x00, 0x00, 0x01, 0x5e
/* 4F4CDC 8021D83C 00000043 */  sra       $zero, $zero, 1
/* 4F4CE0 8021D840 00000002 */  srl       $zero, $zero, 0
/* 4F4CE4 8021D844 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4F4CE8 8021D848 00000000 */  nop       
/* 4F4CEC 8021D84C 00000043 */  sra       $zero, $zero, 1
/* 4F4CF0 8021D850 00000002 */  srl       $zero, $zero, 0
/* 4F4CF4 8021D854 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F4CF8 8021D858 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4CFC 8021D85C 00000043 */  sra       $zero, $zero, 1
/* 4F4D00 8021D860 00000002 */  srl       $zero, $zero, 0
/* 4F4D04 8021D864 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F4D08 8021D868 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F4D0C 8021D86C 00000043 */  sra       $zero, $zero, 1
/* 4F4D10 8021D870 00000003 */  sra       $zero, $zero, 0
/* 4F4D14 8021D874 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F4D18 8021D878 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4D1C 8021D87C 00000000 */  nop       
/* 4F4D20 8021D880 00000043 */  sra       $zero, $zero, 1
/* 4F4D24 8021D884 00000002 */  srl       $zero, $zero, 0
/* 4F4D28 8021D888 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F4D2C 8021D88C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4D30 8021D890 00000043 */  sra       $zero, $zero, 1
/* 4F4D34 8021D894 00000004 */  sllv      $zero, $zero, $zero
/* 4F4D38 8021D898 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F4D3C 8021D89C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4D40 8021D8A0 00000006 */  srlv      $zero, $zero, $zero
/* 4F4D44 8021D8A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4D48 8021D8A8 0000000A */  movz      $zero, $zero, $zero
/* 4F4D4C 8021D8AC 00000002 */  srl       $zero, $zero, 0
/* 4F4D50 8021D8B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4D54 8021D8B4 00000000 */  nop       
/* 4F4D58 8021D8B8 00000043 */  sra       $zero, $zero, 1
/* 4F4D5C 8021D8BC 00000002 */  srl       $zero, $zero, 0
/* 4F4D60 8021D8C0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4D64 8021D8C4 0000000D */  break     
/* 4F4D68 8021D8C8 00000043 */   sra      $zero, $zero, 1
/* 4F4D6C 8021D8CC 00000002 */  srl       $zero, $zero, 0
/* 4F4D70 8021D8D0 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F4D74 8021D8D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4D78 8021D8D8 00000043 */  sra       $zero, $zero, 1
/* 4F4D7C 8021D8DC 00000002 */  srl       $zero, $zero, 0
/* 4F4D80 8021D8E0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F4D84 8021D8E4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4D88 8021D8E8 00000008 */  jr        $zero
/* 4F4D8C 8021D8EC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4D90 8021D8F0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4D94 8021D8F4 00000043 */  sra       $zero, $zero, 1
/* 4F4D98 8021D8F8 00000006 */  srlv      $zero, $zero, $zero
/* 4F4D9C 8021D8FC 80252F30 */  lb        $a1, 0x2f30($at)
/* 4F4DA0 8021D900 000D00E5 */  .byte     0x00, 0x0d, 0x00, 0xe5
/* 4F4DA4 8021D904 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4DA8 8021D908 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4DAC 8021D90C 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F4DB0 8021D910 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F4DB4 8021D914 00000043 */  sra       $zero, $zero, 1
/* 4F4DB8 8021D918 00000002 */  srl       $zero, $zero, 0
/* 4F4DBC 8021D91C 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4DC0 8021D920 00000002 */  srl       $zero, $zero, 0
/* 4F4DC4 8021D924 00000043 */  sra       $zero, $zero, 1
/* 4F4DC8 8021D928 00000002 */  srl       $zero, $zero, 0
/* 4F4DCC 8021D92C 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4DD0 8021D930 00000002 */  srl       $zero, $zero, 0
/* 4F4DD4 8021D934 00000013 */  mtlo      $zero
/* 4F4DD8 8021D938 00000000 */  nop       
/* 4F4DDC 8021D93C 00000043 */  sra       $zero, $zero, 1
/* 4F4DE0 8021D940 00000003 */  sra       $zero, $zero, 0
/* 4F4DE4 8021D944 8025385C */  lb        $a1, 0x385c($at)
/* 4F4DE8 8021D948 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4DEC 8021D94C 000020E1 */  .byte     0x00, 0x00, 0x20, 0xe1
/* 4F4DF0 8021D950 00000043 */  sra       $zero, $zero, 1
/* 4F4DF4 8021D954 00000004 */  sllv      $zero, $zero, $zero
/* 4F4DF8 8021D958 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4DFC 8021D95C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4E00 8021D960 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4E04 8021D964 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F4E08 8021D968 00000043 */  sra       $zero, $zero, 1
/* 4F4E0C 8021D96C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4E10 8021D970 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F4E14 8021D974 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4E18 8021D978 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4E1C 8021D97C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4E20 8021D980 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4E24 8021D984 00000027 */  not       $zero, $zero
/* 4F4E28 8021D988 00000002 */  srl       $zero, $zero, 0
/* 4F4E2C 8021D98C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4E30 8021D990 00000014 */  dsllv     $zero, $zero, $zero
/* 4F4E34 8021D994 00000043 */  sra       $zero, $zero, 1
/* 4F4E38 8021D998 0000000F */  sync      
/* 4F4E3C 8021D99C 802D829C */  lb        $t5, -0x7d64($at)
/* 4F4E40 8021D9A0 00000071 */  tgeu      $zero, $zero, 1
/* 4F4E44 8021D9A4 00000000 */  nop       
/* 4F4E48 8021D9A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4E4C 8021D9AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F4E50 8021D9B0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F4E54 8021D9B4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F4E58 8021D9B8 0000002D */  daddu     $zero, $zero, $zero
/* 4F4E5C 8021D9BC 00000000 */  nop       
/* 4F4E60 8021D9C0 00000000 */  nop       
/* 4F4E64 8021D9C4 00000000 */  nop       
/* 4F4E68 8021D9C8 00000000 */  nop       
/* 4F4E6C 8021D9CC 00000000 */  nop       
/* 4F4E70 8021D9D0 00000000 */  nop       
/* 4F4E74 8021D9D4 00000000 */  nop       
/* 4F4E78 8021D9D8 00000008 */  jr        $zero
/* 4F4E7C 8021D9DC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4E80 8021D9E0 0000001E */  ddiv      $zero, $zero, $zero
/* 4F4E84 8021D9E4 00000043 */  sra       $zero, $zero, 1
/* 4F4E88 8021D9E8 00000002 */  srl       $zero, $zero, 0
/* 4F4E8C 8021D9EC 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F4E90 8021D9F0 00000002 */  srl       $zero, $zero, 0
/* 4F4E94 8021D9F4 00000043 */  sra       $zero, $zero, 1
/* 4F4E98 8021D9F8 00000002 */  srl       $zero, $zero, 0
/* 4F4E9C 8021D9FC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F4EA0 8021DA00 00000046 */  rotrv     $zero, $zero, $zero
/* 4F4EA4 8021DA04 00000043 */  sra       $zero, $zero, 1
/* 4F4EA8 8021DA08 00000002 */  srl       $zero, $zero, 0
/* 4F4EAC 8021DA0C 802D6150 */  lb        $t5, 0x6150($at)
/* 4F4EB0 8021DA10 000020E7 */  .byte     0x00, 0x00, 0x20, 0xe7
/* 4F4EB4 8021DA14 00000043 */  sra       $zero, $zero, 1
/* 4F4EB8 8021DA18 0000000F */  sync      
/* 4F4EBC 8021DA1C 802D829C */  lb        $t5, -0x7d64($at)
/* 4F4EC0 8021DA20 0000004D */  break     0, 1
/* 4F4EC4 8021DA24 00000000 */   nop      
/* 4F4EC8 8021DA28 00000000 */  nop       
/* 4F4ECC 8021DA2C 0000003C */  dsll32    $zero, $zero, 0
/* 4F4ED0 8021DA30 00000000 */  nop       
/* 4F4ED4 8021DA34 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F4ED8 8021DA38 00000000 */  nop       
/* 4F4EDC 8021DA3C F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F4EE0 8021DA40 000000FF */  dsra32    $zero, $zero, 3
/* 4F4EE4 8021DA44 F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F4EE8 8021DA48 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F4EEC 8021DA4C 00000000 */  nop       
/* 4F4EF0 8021DA50 00000000 */  nop       
/* 4F4EF4 8021DA54 00000000 */  nop       
/* 4F4EF8 8021DA58 00000008 */  jr        $zero
/* 4F4EFC 8021DA5C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4F00 8021DA60 0000000F */  sync      
/* 4F4F04 8021DA64 00000043 */  sra       $zero, $zero, 1
/* 4F4F08 8021DA68 00000003 */  sra       $zero, $zero, 0
/* 4F4F0C 8021DA6C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F4F10 8021DA70 00000000 */  nop       
/* 4F4F14 8021DA74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4F18 8021DA78 00000011 */  mthi      $zero
/* 4F4F1C 8021DA7C 00000002 */  srl       $zero, $zero, 0
/* 4F4F20 8021DA80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F4F24 8021DA84 0435D000 */  .byte     0x04, 0x35, 0xd0, 0x00
/* 4F4F28 8021DA88 00000043 */  sra       $zero, $zero, 1
/* 4F4F2C 8021DA8C 00000003 */  sra       $zero, $zero, 0
/* 4F4F30 8021DA90 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F4F34 8021DA94 00000000 */  nop       
/* 4F4F38 8021DA98 00000000 */  nop       
/* 4F4F3C 8021DA9C 00000043 */  sra       $zero, $zero, 1
/* 4F4F40 8021DAA0 00000004 */  sllv      $zero, $zero, $zero
/* 4F4F44 8021DAA4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4F48 8021DAA8 00000000 */  nop       
/* 4F4F4C 8021DAAC 00000000 */  nop       
/* 4F4F50 8021DAB0 0001002B */  sltu      $zero, $zero, $at
/* 4F4F54 8021DAB4 00000008 */  jr        $zero
/* 4F4F58 8021DAB8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4F5C 8021DABC 00000031 */  tgeu      $zero, $zero
/* 4F4F60 8021DAC0 00000043 */  sra       $zero, $zero, 1
/* 4F4F64 8021DAC4 00000002 */  srl       $zero, $zero, 0
/* 4F4F68 8021DAC8 802D6150 */  lb        $t5, 0x6150($at)
/* 4F4F6C 8021DACC 000020E9 */  .byte     0x00, 0x00, 0x20, 0xe9
/* 4F4F70 8021DAD0 00000008 */  jr        $zero
/* 4F4F74 8021DAD4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4F78 8021DAD8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4F7C 8021DADC 00000043 */  sra       $zero, $zero, 1
/* 4F4F80 8021DAE0 00000004 */  sllv      $zero, $zero, $zero
/* 4F4F84 8021DAE4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4F88 8021DAE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F4F8C 8021DAEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4F90 8021DAF0 00680005 */  lsa       $zero, $v1, $t0, 1
/* 4F4F94 8021DAF4 00000008 */  jr        $zero
/* 4F4F98 8021DAF8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4F9C 8021DAFC 00000008 */  jr        $zero
/* 4F4FA0 8021DB00 00000043 */   sra      $zero, $zero, 1
/* 4F4FA4 8021DB04 00000004 */  sllv      $zero, $zero, $zero
/* 4F4FA8 8021DB08 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F4FAC 8021DB0C 00000000 */  nop       
/* 4F4FB0 8021DB10 00000000 */  nop       
/* 4F4FB4 8021DB14 00010014 */  dsllv     $zero, $at, $zero
/* 4F4FB8 8021DB18 00000008 */  jr        $zero
/* 4F4FBC 8021DB1C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F4FC0 8021DB20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4FC4 8021DB24 00000043 */  sra       $zero, $zero, 1
/* 4F4FC8 8021DB28 00000002 */  srl       $zero, $zero, 0
/* 4F4FCC 8021DB2C 80254218 */  lb        $a1, 0x4218($at)
/* 4F4FD0 8021DB30 0000000A */  movz      $zero, $zero, $zero
/* 4F4FD4 8021DB34 00000043 */  sra       $zero, $zero, 1
/* 4F4FD8 8021DB38 00000002 */  srl       $zero, $zero, 0
/* 4F4FDC 8021DB3C 802D6150 */  lb        $t5, 0x6150($at)
/* 4F4FE0 8021DB40 000020EA */  .byte     0x00, 0x00, 0x20, 0xea
/* 4F4FE4 8021DB44 00000043 */  sra       $zero, $zero, 1
/* 4F4FE8 8021DB48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4FEC 8021DB4C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F4FF0 8021DB50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F4FF4 8021DB54 00000000 */  nop       
/* 4F4FF8 8021DB58 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F4FFC 8021DB5C F24A8A80 */  scd       $t2, -0x7580($s2)
/* 4F5000 8021DB60 00000008 */  jr        $zero
/* 4F5004 8021DB64 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5008 8021DB68 00000014 */  dsllv     $zero, $zero, $zero
/* 4F500C 8021DB6C 00000043 */  sra       $zero, $zero, 1
/* 4F5010 8021DB70 00000004 */  sllv      $zero, $zero, $zero
/* 4F5014 8021DB74 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5018 8021DB78 00000000 */  nop       
/* 4F501C 8021DB7C 00000000 */  nop       
/* 4F5020 8021DB80 00010028 */  .byte     0x00, 0x01, 0x00, 0x28
/* 4F5024 8021DB84 00000043 */  sra       $zero, $zero, 1
/* 4F5028 8021DB88 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F502C 8021DB8C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F5030 8021DB90 00000000 */  nop       
/* 4F5034 8021DB94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5038 8021DB98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F503C 8021DB9C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5040 8021DBA0 00000027 */  not       $zero, $zero
/* 4F5044 8021DBA4 00000002 */  srl       $zero, $zero, 0
/* 4F5048 8021DBA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F504C 8021DBAC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5050 8021DBB0 00000043 */  sra       $zero, $zero, 1
/* 4F5054 8021DBB4 0000000F */  sync      
/* 4F5058 8021DBB8 802D829C */  lb        $t5, -0x7d64($at)
/* 4F505C 8021DBBC 00000010 */  mfhi      $zero
/* 4F5060 8021DBC0 00000002 */  srl       $zero, $zero, 0
/* 4F5064 8021DBC4 00000000 */  nop       
/* 4F5068 8021DBC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F506C 8021DBCC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5070 8021DBD0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5074 8021DBD4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5078 8021DBD8 0000013B */  dsra      $zero, $zero, 4
/* 4F507C 8021DBDC 0000001E */  ddiv      $zero, $zero, $zero
/* 4F5080 8021DBE0 00000000 */  nop       
/* 4F5084 8021DBE4 00000000 */  nop       
/* 4F5088 8021DBE8 00000000 */  nop       
/* 4F508C 8021DBEC 00000000 */  nop       
/* 4F5090 8021DBF0 00000000 */  nop       
/* 4F5094 8021DBF4 00000043 */  sra       $zero, $zero, 1
/* 4F5098 8021DBF8 00000002 */  srl       $zero, $zero, 0
/* 4F509C 8021DBFC 802D6150 */  lb        $t5, 0x6150($at)
/* 4F50A0 8021DC00 000020E8 */  .byte     0x00, 0x00, 0x20, 0xe8
/* 4F50A4 8021DC04 00000012 */  mflo      $zero
/* 4F50A8 8021DC08 00000000 */  nop       
/* 4F50AC 8021DC0C 00000008 */  jr        $zero
/* 4F50B0 8021DC10 00000001 */   movf     $zero, $zero, $fcc0
/* 4F50B4 8021DC14 00000032 */  tlt       $zero, $zero
/* 4F50B8 8021DC18 00000043 */  sra       $zero, $zero, 1
/* 4F50BC 8021DC1C 00000002 */  srl       $zero, $zero, 0
/* 4F50C0 8021DC20 802D6150 */  lb        $t5, 0x6150($at)
/* 4F50C4 8021DC24 000020E9 */  .byte     0x00, 0x00, 0x20, 0xe9
/* 4F50C8 8021DC28 00000008 */  jr        $zero
/* 4F50CC 8021DC2C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F50D0 8021DC30 00000012 */  mflo      $zero
/* 4F50D4 8021DC34 00000043 */  sra       $zero, $zero, 1
/* 4F50D8 8021DC38 00000002 */  srl       $zero, $zero, 0
/* 4F50DC 8021DC3C 80254218 */  lb        $a1, 0x4218($at)
/* 4F50E0 8021DC40 0000000A */  movz      $zero, $zero, $zero
/* 4F50E4 8021DC44 00000043 */  sra       $zero, $zero, 1
/* 4F50E8 8021DC48 00000002 */  srl       $zero, $zero, 0
/* 4F50EC 8021DC4C 802D6150 */  lb        $t5, 0x6150($at)
/* 4F50F0 8021DC50 000020EA */  .byte     0x00, 0x00, 0x20, 0xea
/* 4F50F4 8021DC54 00000008 */  jr        $zero
/* 4F50F8 8021DC58 00000001 */   movf     $zero, $zero, $fcc0
/* 4F50FC 8021DC5C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5100 8021DC60 00000043 */  sra       $zero, $zero, 1
/* 4F5104 8021DC64 00000002 */  srl       $zero, $zero, 0
/* 4F5108 8021DC68 802D6150 */  lb        $t5, 0x6150($at)
/* 4F510C 8021DC6C 000020E8 */  .byte     0x00, 0x00, 0x20, 0xe8
/* 4F5110 8021DC70 00000013 */  mtlo      $zero
/* 4F5114 8021DC74 00000000 */  nop       
/* 4F5118 8021DC78 00000043 */  sra       $zero, $zero, 1
/* 4F511C 8021DC7C 00000004 */  sllv      $zero, $zero, $zero
/* 4F5120 8021DC80 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F5124 8021DC84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5128 8021DC88 00000006 */  srlv      $zero, $zero, $zero
/* 4F512C 8021DC8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5130 8021DC90 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5134 8021DC94 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5138 8021DC98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F513C 8021DC9C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F5140 8021DCA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5144 8021DCA4 00000000 */  nop       
/* 4F5148 8021DCA8 00000043 */  sra       $zero, $zero, 1
/* 4F514C 8021DCAC 00000004 */  sllv      $zero, $zero, $zero
/* 4F5150 8021DCB0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F5154 8021DCB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5158 8021DCB8 00000006 */  srlv      $zero, $zero, $zero
/* 4F515C 8021DCBC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5160 8021DCC0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F5164 8021DCC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5168 8021DCC8 8021E008 */  lb        $at, -0x1ff8($at)
/* 4F516C 8021DCCC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F5170 8021DCD0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5174 8021DCD4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5178 8021DCD8 00000043 */  sra       $zero, $zero, 1
/* 4F517C 8021DCDC 00000003 */  sra       $zero, $zero, 0
/* 4F5180 8021DCE0 8027C6A0 */  lb        $a3, -0x3960($at)
/* 4F5184 8021DCE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5188 8021DCE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F518C 8021DCEC 00000043 */  sra       $zero, $zero, 1
/* 4F5190 8021DCF0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5194 8021DCF4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F5198 8021DCF8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F519C 8021DCFC 00000006 */  srlv      $zero, $zero, $zero
/* 4F51A0 8021DD00 00000002 */  srl       $zero, $zero, 0
/* 4F51A4 8021DD04 0000000D */  break     
/* 4F51A8 8021DD08 00000002 */   srl      $zero, $zero, 0
/* 4F51AC 8021DD0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F51B0 8021DD10 00000002 */  srl       $zero, $zero, 0
/* 4F51B4 8021DD14 00000046 */  rotrv     $zero, $zero, $zero
/* 4F51B8 8021DD18 00000001 */  movf      $zero, $zero, $fcc0
/* 4F51BC 8021DD1C 8021DDE8 */  lb        $at, -0x2218($at)
/* 4F51C0 8021DD20 00000012 */  mflo      $zero
/* 4F51C4 8021DD24 00000000 */  nop       
/* 4F51C8 8021DD28 00000046 */  rotrv     $zero, $zero, $zero
/* 4F51CC 8021DD2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F51D0 8021DD30 8021E008 */  lb        $at, -0x1ff8($at)
/* 4F51D4 8021DD34 00000013 */  mtlo      $zero
/* 4F51D8 8021DD38 00000000 */  nop       
/* 4F51DC 8021DD3C 0000001C */  dmult     $zero, $zero
/* 4F51E0 8021DD40 00000000 */  nop       
/* 4F51E4 8021DD44 00000043 */  sra       $zero, $zero, 1
/* 4F51E8 8021DD48 00000003 */  sra       $zero, $zero, 0
/* 4F51EC 8021DD4C 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F51F0 8021DD50 00000002 */  srl       $zero, $zero, 0
/* 4F51F4 8021DD54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F51F8 8021DD58 0000000A */  movz      $zero, $zero, $zero
/* 4F51FC 8021DD5C 00000002 */  srl       $zero, $zero, 0
/* 4F5200 8021DD60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5204 8021DD64 00000000 */  nop       
/* 4F5208 8021DD68 00000043 */  sra       $zero, $zero, 1
/* 4F520C 8021DD6C 00000003 */  sra       $zero, $zero, 0
/* 4F5210 8021DD70 8027C6A0 */  lb        $a3, -0x3960($at)
/* 4F5214 8021DD74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5218 8021DD78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F521C 8021DD7C 0000000D */  break     
/* 4F5220 8021DD80 00000002 */   srl      $zero, $zero, 0
/* 4F5224 8021DD84 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5228 8021DD88 00000002 */  srl       $zero, $zero, 0
/* 4F522C 8021DD8C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F5230 8021DD90 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5234 8021DD94 8021DDE8 */  lb        $at, -0x2218($at)
/* 4F5238 8021DD98 00000012 */  mflo      $zero
/* 4F523C 8021DD9C 00000000 */  nop       
/* 4F5240 8021DDA0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F5244 8021DDA4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5248 8021DDA8 8021E008 */  lb        $at, -0x1ff8($at)
/* 4F524C 8021DDAC 00000013 */  mtlo      $zero
/* 4F5250 8021DDB0 00000000 */  nop       
/* 4F5254 8021DDB4 00000012 */  mflo      $zero
/* 4F5258 8021DDB8 00000000 */  nop       
/* 4F525C 8021DDBC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F5260 8021DDC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5264 8021DDC4 8021E008 */  lb        $at, -0x1ff8($at)
/* 4F5268 8021DDC8 00000013 */  mtlo      $zero
/* 4F526C 8021DDCC 00000000 */  nop       
/* 4F5270 8021DDD0 00000023 */  negu      $zero, $zero
/* 4F5274 8021DDD4 00000000 */  nop       
/* 4F5278 8021DDD8 00000002 */  srl       $zero, $zero, 0
/* 4F527C 8021DDDC 00000000 */  nop       
/* 4F5280 8021DDE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5284 8021DDE4 00000000 */  nop       
/* 4F5288 8021DDE8 00000043 */  sra       $zero, $zero, 1
/* 4F528C 8021DDEC 00000003 */  sra       $zero, $zero, 0
/* 4F5290 8021DDF0 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F5294 8021DDF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5298 8021DDF8 00000200 */  sll       $zero, $zero, 8
/* 4F529C 8021DDFC 00000043 */  sra       $zero, $zero, 1
/* 4F52A0 8021DE00 00000002 */  srl       $zero, $zero, 0
/* 4F52A4 8021DE04 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F52A8 8021DE08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F52AC 8021DE0C 00000043 */  sra       $zero, $zero, 1
/* 4F52B0 8021DE10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F52B4 8021DE14 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F52B8 8021DE18 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F52BC 8021DE1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F52C0 8021DE20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F52C4 8021DE24 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F52C8 8021DE28 00000024 */  and       $zero, $zero, $zero
/* 4F52CC 8021DE2C 00000002 */  srl       $zero, $zero, 0
/* 4F52D0 8021DE30 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F52D4 8021DE34 000000AA */  .byte     0x00, 0x00, 0x00, 0xaa
/* 4F52D8 8021DE38 00000043 */  sra       $zero, $zero, 1
/* 4F52DC 8021DE3C 00000006 */  srlv      $zero, $zero, $zero
/* 4F52E0 8021DE40 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F52E4 8021DE44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F52E8 8021DE48 00000008 */  jr        $zero
/* 4F52EC 8021DE4C FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F52F0 8021DE50 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F52F4 8021DE54 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F52F8 8021DE58 00000043 */  sra       $zero, $zero, 1
/* 4F52FC 8021DE5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5300 8021DE60 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5304 8021DE64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5308 8021DE68 00000008 */  jr        $zero
/* 4F530C 8021DE6C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5310 8021DE70 00000000 */  nop       
/* 4F5314 8021DE74 00000043 */  sra       $zero, $zero, 1
/* 4F5318 8021DE78 00000004 */  sllv      $zero, $zero, $zero
/* 4F531C 8021DE7C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5320 8021DE80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5324 8021DE84 00000008 */  jr        $zero
/* 4F5328 8021DE88 00680016 */   dsrlv    $zero, $t0, $v1
/* 4F532C 8021DE8C 00000043 */  sra       $zero, $zero, 1
/* 4F5330 8021DE90 00000002 */  srl       $zero, $zero, 0
/* 4F5334 8021DE94 802D6150 */  lb        $t5, 0x6150($at)
/* 4F5338 8021DE98 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F533C 8021DE9C 00000043 */  sra       $zero, $zero, 1
/* 4F5340 8021DEA0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5344 8021DEA4 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F5348 8021DEA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F534C 8021DEAC 00000008 */  jr        $zero
/* 4F5350 8021DEB0 F24A9A80 */   scd      $t2, -0x6580($s2)
/* 4F5354 8021DEB4 00000043 */  sra       $zero, $zero, 1
/* 4F5358 8021DEB8 00000004 */  sllv      $zero, $zero, $zero
/* 4F535C 8021DEBC 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F5360 8021DEC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5364 8021DEC4 00000008 */  jr        $zero
/* 4F5368 8021DEC8 F24A7BB4 */   scd      $t2, 0x7bb4($s2)
/* 4F536C 8021DECC 00000043 */  sra       $zero, $zero, 1
/* 4F5370 8021DED0 00000007 */  srav      $zero, $zero, $zero
/* 4F5374 8021DED4 8027A854 */  lb        $a3, -0x57ac($at)
/* 4F5378 8021DED8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F537C 8021DEDC 00000008 */  jr        $zero
/* 4F5380 8021DEE0 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F5384 8021DEE4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5388 8021DEE8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F538C 8021DEEC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5390 8021DEF0 00000056 */  drotrv    $zero, $zero, $zero
/* 4F5394 8021DEF4 00000000 */  nop       
/* 4F5398 8021DEF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F539C 8021DEFC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F53A0 8021DF00 00000014 */  dsllv     $zero, $zero, $zero
/* 4F53A4 8021DF04 00000043 */  sra       $zero, $zero, 1
/* 4F53A8 8021DF08 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F53AC 8021DF0C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F53B0 8021DF10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F53B4 8021DF14 00000008 */  jr        $zero
/* 4F53B8 8021DF18 00000001 */   movf     $zero, $zero, $fcc0
/* 4F53BC 8021DF1C 00000000 */  nop       
/* 4F53C0 8021DF20 00000008 */  jr        $zero
/* 4F53C4 8021DF24 00000001 */   movf     $zero, $zero, $fcc0
/* 4F53C8 8021DF28 00000001 */  movf      $zero, $zero, $fcc0
/* 4F53CC 8021DF2C 00000043 */  sra       $zero, $zero, 1
/* 4F53D0 8021DF30 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F53D4 8021DF34 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F53D8 8021DF38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F53DC 8021DF3C 00000008 */  jr        $zero
/* 4F53E0 8021DF40 00000001 */   movf     $zero, $zero, $fcc0
/* 4F53E4 8021DF44 00000001 */  movf      $zero, $zero, $fcc0
/* 4F53E8 8021DF48 00000008 */  jr        $zero
/* 4F53EC 8021DF4C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F53F0 8021DF50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F53F4 8021DF54 00000006 */  srlv      $zero, $zero, $zero
/* 4F53F8 8021DF58 00000000 */  nop       
/* 4F53FC 8021DF5C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F5400 8021DF60 00000000 */  nop       
/* 4F5404 8021DF64 00000043 */  sra       $zero, $zero, 1
/* 4F5408 8021DF68 00000003 */  sra       $zero, $zero, 0
/* 4F540C 8021DF6C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F5410 8021DF70 00000000 */  nop       
/* 4F5414 8021DF74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5418 8021DF78 00000011 */  mthi      $zero
/* 4F541C 8021DF7C 00000002 */  srl       $zero, $zero, 0
/* 4F5420 8021DF80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5424 8021DF84 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4F5428 8021DF88 00000043 */  sra       $zero, $zero, 1
/* 4F542C 8021DF8C 00000004 */  sllv      $zero, $zero, $zero
/* 4F5430 8021DF90 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5434 8021DF94 00000000 */  nop       
/* 4F5438 8021DF98 00000000 */  nop       
/* 4F543C 8021DF9C 00010032 */  tlt       $zero, $at
/* 4F5440 8021DFA0 00000013 */  mtlo      $zero
/* 4F5444 8021DFA4 00000000 */  nop       
/* 4F5448 8021DFA8 00000043 */  sra       $zero, $zero, 1
/* 4F544C 8021DFAC 00000004 */  sllv      $zero, $zero, $zero
/* 4F5450 8021DFB0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F5454 8021DFB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5458 8021DFB8 0000000D */  break     
/* 4F545C 8021DFBC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5460 8021DFC0 00000043 */  sra       $zero, $zero, 1
/* 4F5464 8021DFC4 00000002 */  srl       $zero, $zero, 0
/* 4F5468 8021DFC8 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F546C 8021DFCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5470 8021DFD0 00000043 */  sra       $zero, $zero, 1
/* 4F5474 8021DFD4 00000008 */  jr        $zero
/* 4F5478 8021DFD8 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F547C 8021DFDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5480 8021DFE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5484 8021DFE4 08000000 */  j         .L80000000
/* 4F5488 8021DFE8 00000000 */   nop      
/* 4F548C 8021DFEC 00000000 */  nop       
/* 4F5490 8021DFF0 00000002 */  srl       $zero, $zero, 0
/* 4F5494 8021DFF4 00000020 */  add       $zero, $zero, $zero
/* 4F5498 8021DFF8 00000002 */  srl       $zero, $zero, 0
/* 4F549C 8021DFFC 00000000 */  nop       
/* 4F54A0 8021E000 00000001 */  movf      $zero, $zero, $fcc0
/* 4F54A4 8021E004 00000000 */  nop       
/* 4F54A8 8021E008 00000043 */  sra       $zero, $zero, 1
/* 4F54AC 8021E00C 00000003 */  sra       $zero, $zero, 0
/* 4F54B0 8021E010 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F54B4 8021E014 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F54B8 8021E018 00000000 */  nop       
/* 4F54BC 8021E01C 00000043 */  sra       $zero, $zero, 1
/* 4F54C0 8021E020 00000007 */  srav      $zero, $zero, $zero
/* 4F54C4 8021E024 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F54C8 8021E028 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F54CC 8021E02C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F54D0 8021E030 00000000 */  nop       
/* 4F54D4 8021E034 00000000 */  nop       
/* 4F54D8 8021E038 00000001 */  movf      $zero, $zero, $fcc0
/* 4F54DC 8021E03C 00000010 */  mfhi      $zero
/* 4F54E0 8021E040 00000014 */  dsllv     $zero, $zero, $zero
/* 4F54E4 8021E044 00000001 */  movf      $zero, $zero, $fcc0
/* 4F54E8 8021E048 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F54EC 8021E04C 0000001D */  dmultu    $zero, $zero
/* 4F54F0 8021E050 00000001 */  movf      $zero, $zero, $fcc0
/* 4F54F4 8021E054 00000006 */  srlv      $zero, $zero, $zero
/* 4F54F8 8021E058 0000001D */  dmultu    $zero, $zero
/* 4F54FC 8021E05C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5500 8021E060 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5504 8021E064 00000056 */  drotrv    $zero, $zero, $zero
/* 4F5508 8021E068 00000000 */  nop       
/* 4F550C 8021E06C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5510 8021E070 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5514 8021E074 00000006 */  srlv      $zero, $zero, $zero
/* 4F5518 8021E078 00000043 */  sra       $zero, $zero, 1
/* 4F551C 8021E07C 00000003 */  sra       $zero, $zero, 0
/* 4F5520 8021E080 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F5524 8021E084 00000078 */  dsll      $zero, $zero, 1
/* 4F5528 8021E088 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F552C 8021E08C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5530 8021E090 00000002 */  srl       $zero, $zero, 0
/* 4F5534 8021E094 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5538 8021E098 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F553C 8021E09C 00000043 */  sra       $zero, $zero, 1
/* 4F5540 8021E0A0 00000003 */  sra       $zero, $zero, 0
/* 4F5544 8021E0A4 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F5548 8021E0A8 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4F554C 8021E0AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5550 8021E0B0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5554 8021E0B4 00000002 */  srl       $zero, $zero, 0
/* 4F5558 8021E0B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F555C 8021E0BC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5560 8021E0C0 00000043 */  sra       $zero, $zero, 1
/* 4F5564 8021E0C4 00000002 */  srl       $zero, $zero, 0
/* 4F5568 8021E0C8 802D6150 */  lb        $t5, 0x6150($at)
/* 4F556C 8021E0CC 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F5570 8021E0D0 00000043 */  sra       $zero, $zero, 1
/* 4F5574 8021E0D4 00000004 */  sllv      $zero, $zero, $zero
/* 4F5578 8021E0D8 8021875C */  lb        $at, -0x78a4($at)
/* 4F557C 8021E0DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5580 8021E0E0 00000000 */  nop       
/* 4F5584 8021E0E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5588 8021E0E8 00000043 */  sra       $zero, $zero, 1
/* 4F558C 8021E0EC 00000003 */  sra       $zero, $zero, 0
/* 4F5590 8021E0F0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F5594 8021E0F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5598 8021E0F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F559C 8021E0FC 00000027 */  not       $zero, $zero
/* 4F55A0 8021E100 00000002 */  srl       $zero, $zero, 0
/* 4F55A4 8021E104 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F55A8 8021E108 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F55AC 8021E10C 00000008 */  jr        $zero
/* 4F55B0 8021E110 00000001 */   movf     $zero, $zero, $fcc0
/* 4F55B4 8021E114 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F55B8 8021E118 00000006 */  srlv      $zero, $zero, $zero
/* 4F55BC 8021E11C 00000000 */  nop       
/* 4F55C0 8021E120 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F55C4 8021E124 00000000 */  nop       
/* 4F55C8 8021E128 00000043 */  sra       $zero, $zero, 1
/* 4F55CC 8021E12C 00000003 */  sra       $zero, $zero, 0
/* 4F55D0 8021E130 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F55D4 8021E134 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F55D8 8021E138 00000100 */  sll       $zero, $zero, 4
/* 4F55DC 8021E13C 00000043 */  sra       $zero, $zero, 1
/* 4F55E0 8021E140 00000007 */  srav      $zero, $zero, $zero
/* 4F55E4 8021E144 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F55E8 8021E148 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F55EC 8021E14C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F55F0 8021E150 00000000 */  nop       
/* 4F55F4 8021E154 00000000 */  nop       
/* 4F55F8 8021E158 00000001 */  movf      $zero, $zero, $fcc0
/* 4F55FC 8021E15C 00000010 */  mfhi      $zero
/* 4F5600 8021E160 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5604 8021E164 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5608 8021E168 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F560C 8021E16C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F5610 8021E170 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5614 8021E174 00000006 */  srlv      $zero, $zero, $zero
/* 4F5618 8021E178 00000002 */  srl       $zero, $zero, 0
/* 4F561C 8021E17C 00000000 */  nop       
/* 4F5620 8021E180 0000001C */  dmult     $zero, $zero
/* 4F5624 8021E184 00000000 */  nop       
/* 4F5628 8021E188 00000043 */  sra       $zero, $zero, 1
/* 4F562C 8021E18C 00000002 */  srl       $zero, $zero, 0
/* 4F5630 8021E190 8026BF48 */  lb        $a2, -0x40b8($at)
/* 4F5634 8021E194 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5638 8021E198 00000056 */  drotrv    $zero, $zero, $zero
/* 4F563C 8021E19C 00000000 */  nop       
/* 4F5640 8021E1A0 00000043 */  sra       $zero, $zero, 1
/* 4F5644 8021E1A4 00000002 */  srl       $zero, $zero, 0
/* 4F5648 8021E1A8 802D6150 */  lb        $t5, 0x6150($at)
/* 4F564C 8021E1AC 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F5650 8021E1B0 00000043 */  sra       $zero, $zero, 1
/* 4F5654 8021E1B4 00000003 */  sra       $zero, $zero, 0
/* 4F5658 8021E1B8 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F565C 8021E1BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5660 8021E1C0 00000000 */  nop       
/* 4F5664 8021E1C4 00000043 */  sra       $zero, $zero, 1
/* 4F5668 8021E1C8 00000002 */  srl       $zero, $zero, 0
/* 4F566C 8021E1CC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F5670 8021E1D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5674 8021E1D4 00000043 */  sra       $zero, $zero, 1
/* 4F5678 8021E1D8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F567C 8021E1DC 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F5680 8021E1E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5684 8021E1E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5688 8021E1E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F568C 8021E1EC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5690 8021E1F0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5694 8021E1F4 00000002 */  srl       $zero, $zero, 0
/* 4F5698 8021E1F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F569C 8021E1FC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F56A0 8021E200 00000024 */  and       $zero, $zero, $zero
/* 4F56A4 8021E204 00000002 */  srl       $zero, $zero, 0
/* 4F56A8 8021E208 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F56AC 8021E20C 00000000 */  nop       
/* 4F56B0 8021E210 00000024 */  and       $zero, $zero, $zero
/* 4F56B4 8021E214 00000002 */  srl       $zero, $zero, 0
/* 4F56B8 8021E218 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F56BC 8021E21C 000000AA */  .byte     0x00, 0x00, 0x00, 0xaa
/* 4F56C0 8021E220 00000043 */  sra       $zero, $zero, 1
/* 4F56C4 8021E224 00000006 */  srlv      $zero, $zero, $zero
/* 4F56C8 8021E228 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F56CC 8021E22C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F56D0 8021E230 00000006 */  srlv      $zero, $zero, $zero
/* 4F56D4 8021E234 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F56D8 8021E238 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F56DC 8021E23C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F56E0 8021E240 00000043 */  sra       $zero, $zero, 1
/* 4F56E4 8021E244 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F56E8 8021E248 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F56EC 8021E24C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F56F0 8021E250 00000006 */  srlv      $zero, $zero, $zero
/* 4F56F4 8021E254 00000001 */  movf      $zero, $zero, $fcc0
/* 4F56F8 8021E258 00000000 */  nop       
/* 4F56FC 8021E25C 00000043 */  sra       $zero, $zero, 1
/* 4F5700 8021E260 00000004 */  sllv      $zero, $zero, $zero
/* 4F5704 8021E264 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5708 8021E268 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F570C 8021E26C 00000006 */  srlv      $zero, $zero, $zero
/* 4F5710 8021E270 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F5714 8021E274 00000043 */  sra       $zero, $zero, 1
/* 4F5718 8021E278 00000004 */  sllv      $zero, $zero, $zero
/* 4F571C 8021E27C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F5720 8021E280 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5724 8021E284 00000006 */  srlv      $zero, $zero, $zero
/* 4F5728 8021E288 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F572C 8021E28C 00000043 */  sra       $zero, $zero, 1
/* 4F5730 8021E290 00000004 */  sllv      $zero, $zero, $zero
/* 4F5734 8021E294 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F5738 8021E298 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F573C 8021E29C 00000006 */  srlv      $zero, $zero, $zero
/* 4F5740 8021E2A0 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 4F5744 8021E2A4 00000043 */  sra       $zero, $zero, 1
/* 4F5748 8021E2A8 00000007 */  srav      $zero, $zero, $zero
/* 4F574C 8021E2AC 8027A854 */  lb        $a3, -0x57ac($at)
/* 4F5750 8021E2B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5754 8021E2B4 00000006 */  srlv      $zero, $zero, $zero
/* 4F5758 8021E2B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F575C 8021E2BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5760 8021E2C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5764 8021E2C4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5768 8021E2C8 00000043 */  sra       $zero, $zero, 1
/* 4F576C 8021E2CC 00000004 */  sllv      $zero, $zero, $zero
/* 4F5770 8021E2D0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5774 8021E2D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5778 8021E2D8 00000006 */  srlv      $zero, $zero, $zero
/* 4F577C 8021E2DC 00680017 */  dsrav     $zero, $t0, $v1
/* 4F5780 8021E2E0 0000000A */  movz      $zero, $zero, $zero
/* 4F5784 8021E2E4 00000002 */  srl       $zero, $zero, 0
/* 4F5788 8021E2E8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F578C 8021E2EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5790 8021E2F0 00000043 */  sra       $zero, $zero, 1
/* 4F5794 8021E2F4 00000007 */  srav      $zero, $zero, $zero
/* 4F5798 8021E2F8 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F579C 8021E2FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F57A0 8021E300 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F57A4 8021E304 80000000 */  lb        $zero, ($zero)
/* 4F57A8 8021E308 00000000 */  nop       
/* 4F57AC 8021E30C 00000000 */  nop       
/* 4F57B0 8021E310 00000000 */  nop       
/* 4F57B4 8021E314 00000013 */  mtlo      $zero
/* 4F57B8 8021E318 00000000 */  nop       
/* 4F57BC 8021E31C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F57C0 8021E320 00000000 */  nop       
/* 4F57C4 8021E324 00000008 */  jr        $zero
/* 4F57C8 8021E328 00000001 */   movf     $zero, $zero, $fcc0
/* 4F57CC 8021E32C 00000019 */  multu     $zero, $zero
/* 4F57D0 8021E330 00000043 */  sra       $zero, $zero, 1
/* 4F57D4 8021E334 00000003 */  sra       $zero, $zero, 0
/* 4F57D8 8021E338 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F57DC 8021E33C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F57E0 8021E340 00000100 */  sll       $zero, $zero, 4
/* 4F57E4 8021E344 00000043 */  sra       $zero, $zero, 1
/* 4F57E8 8021E348 00000002 */  srl       $zero, $zero, 0
/* 4F57EC 8021E34C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F57F0 8021E350 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F57F4 8021E354 00000043 */  sra       $zero, $zero, 1
/* 4F57F8 8021E358 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F57FC 8021E35C 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F5800 8021E360 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5804 8021E364 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5808 8021E368 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F580C 8021E36C FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F5810 8021E370 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5814 8021E374 00000002 */  srl       $zero, $zero, 0
/* 4F5818 8021E378 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F581C 8021E37C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5820 8021E380 00000027 */  not       $zero, $zero
/* 4F5824 8021E384 00000002 */  srl       $zero, $zero, 0
/* 4F5828 8021E388 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F582C 8021E38C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5830 8021E390 00000024 */  and       $zero, $zero, $zero
/* 4F5834 8021E394 00000002 */  srl       $zero, $zero, 0
/* 4F5838 8021E398 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4F583C 8021E39C 000000AA */  .byte     0x00, 0x00, 0x00, 0xaa
/* 4F5840 8021E3A0 00000043 */  sra       $zero, $zero, 1
/* 4F5844 8021E3A4 00000006 */  srlv      $zero, $zero, $zero
/* 4F5848 8021E3A8 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F584C 8021E3AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5850 8021E3B0 00000007 */  srav      $zero, $zero, $zero
/* 4F5854 8021E3B4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5858 8021E3B8 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4F585C 8021E3BC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F5860 8021E3C0 00000043 */  sra       $zero, $zero, 1
/* 4F5864 8021E3C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5868 8021E3C8 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F586C 8021E3CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5870 8021E3D0 00000007 */  srav      $zero, $zero, $zero
/* 4F5874 8021E3D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5878 8021E3D8 00000000 */  nop       
/* 4F587C 8021E3DC 00000043 */  sra       $zero, $zero, 1
/* 4F5880 8021E3E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5884 8021E3E4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5888 8021E3E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F588C 8021E3EC 00000007 */  srav      $zero, $zero, $zero
/* 4F5890 8021E3F0 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F5894 8021E3F4 00000043 */  sra       $zero, $zero, 1
/* 4F5898 8021E3F8 00000002 */  srl       $zero, $zero, 0
/* 4F589C 8021E3FC 802D6150 */  lb        $t5, 0x6150($at)
/* 4F58A0 8021E400 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F58A4 8021E404 00000043 */  sra       $zero, $zero, 1
/* 4F58A8 8021E408 00000004 */  sllv      $zero, $zero, $zero
/* 4F58AC 8021E40C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F58B0 8021E410 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F58B4 8021E414 00000007 */  srav      $zero, $zero, $zero
/* 4F58B8 8021E418 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F58BC 8021E41C 00000043 */  sra       $zero, $zero, 1
/* 4F58C0 8021E420 00000004 */  sllv      $zero, $zero, $zero
/* 4F58C4 8021E424 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F58C8 8021E428 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F58CC 8021E42C 00000007 */  srav      $zero, $zero, $zero
/* 4F58D0 8021E430 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 4F58D4 8021E434 00000043 */  sra       $zero, $zero, 1
/* 4F58D8 8021E438 00000007 */  srav      $zero, $zero, $zero
/* 4F58DC 8021E43C 8027A854 */  lb        $a3, -0x57ac($at)
/* 4F58E0 8021E440 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F58E4 8021E444 00000007 */  srav      $zero, $zero, $zero
/* 4F58E8 8021E448 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F58EC 8021E44C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F58F0 8021E450 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F58F4 8021E454 00000014 */  dsllv     $zero, $zero, $zero
/* 4F58F8 8021E458 00000043 */  sra       $zero, $zero, 1
/* 4F58FC 8021E45C 00000004 */  sllv      $zero, $zero, $zero
/* 4F5900 8021E460 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5904 8021E464 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5908 8021E468 00000006 */  srlv      $zero, $zero, $zero
/* 4F590C 8021E46C 00680017 */  dsrav     $zero, $t0, $v1
/* 4F5910 8021E470 00000043 */  sra       $zero, $zero, 1
/* 4F5914 8021E474 00000003 */  sra       $zero, $zero, 0
/* 4F5918 8021E478 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F591C 8021E47C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5920 8021E480 00000100 */  sll       $zero, $zero, 4
/* 4F5924 8021E484 00000043 */  sra       $zero, $zero, 1
/* 4F5928 8021E488 00000002 */  srl       $zero, $zero, 0
/* 4F592C 8021E48C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F5930 8021E490 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5934 8021E494 00000043 */  sra       $zero, $zero, 1
/* 4F5938 8021E498 00000008 */  jr        $zero
/* 4F593C 8021E49C 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F5940 8021E4A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5944 8021E4A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5948 8021E4A8 10000000 */  b         .L8021E4AC
.L8021E4AC:
/* 4F594C 8021E4AC 00000000 */   nop      
/* 4F5950 8021E4B0 00000000 */  nop       
/* 4F5954 8021E4B4 00000002 */  srl       $zero, $zero, 0
/* 4F5958 8021E4B8 00000020 */  add       $zero, $zero, $zero
/* 4F595C 8021E4BC 00000008 */  jr        $zero
/* 4F5960 8021E4C0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5964 8021E4C4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5968 8021E4C8 00000043 */  sra       $zero, $zero, 1
/* 4F596C 8021E4CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5970 8021E4D0 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5974 8021E4D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5978 8021E4D8 00000007 */  srav      $zero, $zero, $zero
/* 4F597C 8021E4DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5980 8021E4E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5984 8021E4E4 00000043 */  sra       $zero, $zero, 1
/* 4F5988 8021E4E8 00000002 */  srl       $zero, $zero, 0
/* 4F598C 8021E4EC 8026BF48 */  lb        $a2, -0x40b8($at)
/* 4F5990 8021E4F0 00000000 */  nop       
/* 4F5994 8021E4F4 00000002 */  srl       $zero, $zero, 0
/* 4F5998 8021E4F8 00000000 */  nop       
/* 4F599C 8021E4FC 00000023 */  negu      $zero, $zero
/* 4F59A0 8021E500 00000000 */  nop       
/* 4F59A4 8021E504 00000002 */  srl       $zero, $zero, 0
/* 4F59A8 8021E508 00000000 */  nop       
/* 4F59AC 8021E50C 00000020 */  add       $zero, $zero, $zero
/* 4F59B0 8021E510 00000000 */  nop       
/* 4F59B4 8021E514 00000023 */  negu      $zero, $zero
/* 4F59B8 8021E518 00000000 */  nop       
/* 4F59BC 8021E51C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F59C0 8021E520 00000000 */  nop       
/* 4F59C4 8021E524 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F59C8 8021E528 00000001 */  movf      $zero, $zero, $fcc0
/* 4F59CC 8021E52C 00000006 */  srlv      $zero, $zero, $zero
/* 4F59D0 8021E530 00000043 */  sra       $zero, $zero, 1
/* 4F59D4 8021E534 00000003 */  sra       $zero, $zero, 0
/* 4F59D8 8021E538 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F59DC 8021E53C 00000078 */  dsll      $zero, $zero, 1
/* 4F59E0 8021E540 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F59E4 8021E544 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F59E8 8021E548 00000002 */  srl       $zero, $zero, 0
/* 4F59EC 8021E54C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F59F0 8021E550 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F59F4 8021E554 00000043 */  sra       $zero, $zero, 1
/* 4F59F8 8021E558 00000003 */  sra       $zero, $zero, 0
/* 4F59FC 8021E55C 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F5A00 8021E560 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4F5A04 8021E564 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5A08 8021E568 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5A0C 8021E56C 00000002 */  srl       $zero, $zero, 0
/* 4F5A10 8021E570 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5A14 8021E574 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5A18 8021E578 00000043 */  sra       $zero, $zero, 1
/* 4F5A1C 8021E57C 00000002 */  srl       $zero, $zero, 0
/* 4F5A20 8021E580 802D6150 */  lb        $t5, 0x6150($at)
/* 4F5A24 8021E584 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F5A28 8021E588 00000043 */  sra       $zero, $zero, 1
/* 4F5A2C 8021E58C 00000004 */  sllv      $zero, $zero, $zero
/* 4F5A30 8021E590 8021875C */  lb        $at, -0x78a4($at)
/* 4F5A34 8021E594 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5A38 8021E598 00000000 */  nop       
/* 4F5A3C 8021E59C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5A40 8021E5A0 00000043 */  sra       $zero, $zero, 1
/* 4F5A44 8021E5A4 00000003 */  sra       $zero, $zero, 0
/* 4F5A48 8021E5A8 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F5A4C 8021E5AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5A50 8021E5B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5A54 8021E5B4 00000027 */  not       $zero, $zero
/* 4F5A58 8021E5B8 00000002 */  srl       $zero, $zero, 0
/* 4F5A5C 8021E5BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5A60 8021E5C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5A64 8021E5C4 00000008 */  jr        $zero
/* 4F5A68 8021E5C8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5A6C 8021E5CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5A70 8021E5D0 00000006 */  srlv      $zero, $zero, $zero
/* 4F5A74 8021E5D4 00000000 */  nop       
/* 4F5A78 8021E5D8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F5A7C 8021E5DC 00000000 */  nop       
/* 4F5A80 8021E5E0 00000043 */  sra       $zero, $zero, 1
/* 4F5A84 8021E5E4 00000002 */  srl       $zero, $zero, 0
/* 4F5A88 8021E5E8 8026BF48 */  lb        $a2, -0x40b8($at)
/* 4F5A8C 8021E5EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5A90 8021E5F0 00000056 */  drotrv    $zero, $zero, $zero
/* 4F5A94 8021E5F4 00000000 */  nop       
/* 4F5A98 8021E5F8 00000008 */  jr        $zero
/* 4F5A9C 8021E5FC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5AA0 8021E600 00000019 */  multu     $zero, $zero
/* 4F5AA4 8021E604 00000043 */  sra       $zero, $zero, 1
/* 4F5AA8 8021E608 00000003 */  sra       $zero, $zero, 0
/* 4F5AAC 8021E60C 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F5AB0 8021E610 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5AB4 8021E614 00000100 */  sll       $zero, $zero, 4
/* 4F5AB8 8021E618 00000043 */  sra       $zero, $zero, 1
/* 4F5ABC 8021E61C 00000002 */  srl       $zero, $zero, 0
/* 4F5AC0 8021E620 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F5AC4 8021E624 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5AC8 8021E628 00000043 */  sra       $zero, $zero, 1
/* 4F5ACC 8021E62C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5AD0 8021E630 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F5AD4 8021E634 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5AD8 8021E638 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5ADC 8021E63C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F5AE0 8021E640 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F5AE4 8021E644 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5AE8 8021E648 00000002 */  srl       $zero, $zero, 0
/* 4F5AEC 8021E64C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5AF0 8021E650 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5AF4 8021E654 00000027 */  not       $zero, $zero
/* 4F5AF8 8021E658 00000002 */  srl       $zero, $zero, 0
/* 4F5AFC 8021E65C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F5B00 8021E660 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5B04 8021E664 00000024 */  and       $zero, $zero, $zero
/* 4F5B08 8021E668 00000002 */  srl       $zero, $zero, 0
/* 4F5B0C 8021E66C FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4F5B10 8021E670 000000AA */  .byte     0x00, 0x00, 0x00, 0xaa
/* 4F5B14 8021E674 00000043 */  sra       $zero, $zero, 1
/* 4F5B18 8021E678 00000006 */  srlv      $zero, $zero, $zero
/* 4F5B1C 8021E67C 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F5B20 8021E680 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5B24 8021E684 00000007 */  srav      $zero, $zero, $zero
/* 4F5B28 8021E688 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5B2C 8021E68C FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4F5B30 8021E690 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F5B34 8021E694 00000043 */  sra       $zero, $zero, 1
/* 4F5B38 8021E698 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5B3C 8021E69C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5B40 8021E6A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5B44 8021E6A4 00000007 */  srav      $zero, $zero, $zero
/* 4F5B48 8021E6A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5B4C 8021E6AC 00000000 */  nop       
/* 4F5B50 8021E6B0 00000043 */  sra       $zero, $zero, 1
/* 4F5B54 8021E6B4 00000004 */  sllv      $zero, $zero, $zero
/* 4F5B58 8021E6B8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5B5C 8021E6BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5B60 8021E6C0 00000007 */  srav      $zero, $zero, $zero
/* 4F5B64 8021E6C4 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F5B68 8021E6C8 00000043 */  sra       $zero, $zero, 1
/* 4F5B6C 8021E6CC 00000002 */  srl       $zero, $zero, 0
/* 4F5B70 8021E6D0 802D6150 */  lb        $t5, 0x6150($at)
/* 4F5B74 8021E6D4 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F5B78 8021E6D8 00000043 */  sra       $zero, $zero, 1
/* 4F5B7C 8021E6DC 00000004 */  sllv      $zero, $zero, $zero
/* 4F5B80 8021E6E0 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F5B84 8021E6E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5B88 8021E6E8 00000007 */  srav      $zero, $zero, $zero
/* 4F5B8C 8021E6EC F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F5B90 8021E6F0 00000043 */  sra       $zero, $zero, 1
/* 4F5B94 8021E6F4 00000004 */  sllv      $zero, $zero, $zero
/* 4F5B98 8021E6F8 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F5B9C 8021E6FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5BA0 8021E700 00000007 */  srav      $zero, $zero, $zero
/* 4F5BA4 8021E704 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 4F5BA8 8021E708 00000043 */  sra       $zero, $zero, 1
/* 4F5BAC 8021E70C 00000007 */  srav      $zero, $zero, $zero
/* 4F5BB0 8021E710 8027A854 */  lb        $a3, -0x57ac($at)
/* 4F5BB4 8021E714 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5BB8 8021E718 00000007 */  srav      $zero, $zero, $zero
/* 4F5BBC 8021E71C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F5BC0 8021E720 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F5BC4 8021E724 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F5BC8 8021E728 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5BCC 8021E72C 00000043 */  sra       $zero, $zero, 1
/* 4F5BD0 8021E730 00000004 */  sllv      $zero, $zero, $zero
/* 4F5BD4 8021E734 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5BD8 8021E738 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5BDC 8021E73C 00000006 */  srlv      $zero, $zero, $zero
/* 4F5BE0 8021E740 00680017 */  dsrav     $zero, $t0, $v1
/* 4F5BE4 8021E744 00000043 */  sra       $zero, $zero, 1
/* 4F5BE8 8021E748 00000003 */  sra       $zero, $zero, 0
/* 4F5BEC 8021E74C 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F5BF0 8021E750 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5BF4 8021E754 00000100 */  sll       $zero, $zero, 4
/* 4F5BF8 8021E758 00000043 */  sra       $zero, $zero, 1
/* 4F5BFC 8021E75C 00000008 */  jr        $zero
/* 4F5C00 8021E760 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F5C04 8021E764 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5C08 8021E768 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5C0C 8021E76C 10000000 */  b         .L8021E770
.L8021E770:
/* 4F5C10 8021E770 00000000 */   nop      
/* 4F5C14 8021E774 00000000 */  nop       
/* 4F5C18 8021E778 00000002 */  srl       $zero, $zero, 0
/* 4F5C1C 8021E77C 00000020 */  add       $zero, $zero, $zero
/* 4F5C20 8021E780 00000008 */  jr        $zero
/* 4F5C24 8021E784 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5C28 8021E788 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5C2C 8021E78C 00000043 */  sra       $zero, $zero, 1
/* 4F5C30 8021E790 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5C34 8021E794 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5C38 8021E798 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5C3C 8021E79C 00000007 */  srav      $zero, $zero, $zero
/* 4F5C40 8021E7A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5C44 8021E7A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5C48 8021E7A8 00000043 */  sra       $zero, $zero, 1
/* 4F5C4C 8021E7AC 00000002 */  srl       $zero, $zero, 0
/* 4F5C50 8021E7B0 8026BF48 */  lb        $a2, -0x40b8($at)
/* 4F5C54 8021E7B4 00000000 */  nop       
/* 4F5C58 8021E7B8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F5C5C 8021E7BC 00000000 */  nop       
/* 4F5C60 8021E7C0 00000043 */  sra       $zero, $zero, 1
/* 4F5C64 8021E7C4 00000002 */  srl       $zero, $zero, 0
/* 4F5C68 8021E7C8 802D6150 */  lb        $t5, 0x6150($at)
/* 4F5C6C 8021E7CC 000020EB */  .byte     0x00, 0x00, 0x20, 0xeb
/* 4F5C70 8021E7D0 00000043 */  sra       $zero, $zero, 1
/* 4F5C74 8021E7D4 00000003 */  sra       $zero, $zero, 0
/* 4F5C78 8021E7D8 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F5C7C 8021E7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5C80 8021E7E0 00000000 */  nop       
/* 4F5C84 8021E7E4 00000043 */  sra       $zero, $zero, 1
/* 4F5C88 8021E7E8 00000002 */  srl       $zero, $zero, 0
/* 4F5C8C 8021E7EC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F5C90 8021E7F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5C94 8021E7F4 00000043 */  sra       $zero, $zero, 1
/* 4F5C98 8021E7F8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5C9C 8021E7FC 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F5CA0 8021E800 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5CA4 8021E804 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5CA8 8021E808 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5CAC 8021E80C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5CB0 8021E810 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F5CB4 8021E814 00000002 */  srl       $zero, $zero, 0
/* 4F5CB8 8021E818 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5CBC 8021E81C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5CC0 8021E820 00000027 */  not       $zero, $zero
/* 4F5CC4 8021E824 00000002 */  srl       $zero, $zero, 0
/* 4F5CC8 8021E828 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5CCC 8021E82C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5CD0 8021E830 00000024 */  and       $zero, $zero, $zero
/* 4F5CD4 8021E834 00000002 */  srl       $zero, $zero, 0
/* 4F5CD8 8021E838 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F5CDC 8021E83C 000000AA */  .byte     0x00, 0x00, 0x00, 0xaa
/* 4F5CE0 8021E840 00000043 */  sra       $zero, $zero, 1
/* 4F5CE4 8021E844 00000006 */  srlv      $zero, $zero, $zero
/* 4F5CE8 8021E848 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F5CEC 8021E84C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5CF0 8021E850 00000006 */  srlv      $zero, $zero, $zero
/* 4F5CF4 8021E854 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5CF8 8021E858 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F5CFC 8021E85C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5D00 8021E860 00000043 */  sra       $zero, $zero, 1
/* 4F5D04 8021E864 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5D08 8021E868 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5D0C 8021E86C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D10 8021E870 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D14 8021E874 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5D18 8021E878 00000000 */  nop       
/* 4F5D1C 8021E87C 00000043 */  sra       $zero, $zero, 1
/* 4F5D20 8021E880 00000004 */  sllv      $zero, $zero, $zero
/* 4F5D24 8021E884 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5D28 8021E888 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D2C 8021E88C 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D30 8021E890 00680016 */  dsrlv     $zero, $t0, $v1
/* 4F5D34 8021E894 00000043 */  sra       $zero, $zero, 1
/* 4F5D38 8021E898 00000004 */  sllv      $zero, $zero, $zero
/* 4F5D3C 8021E89C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4F5D40 8021E8A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D44 8021E8A4 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D48 8021E8A8 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F5D4C 8021E8AC 00000043 */  sra       $zero, $zero, 1
/* 4F5D50 8021E8B0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5D54 8021E8B4 8026B74C */  lb        $a2, -0x48b4($at)
/* 4F5D58 8021E8B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D5C 8021E8BC 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D60 8021E8C0 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 4F5D64 8021E8C4 00000043 */  sra       $zero, $zero, 1
/* 4F5D68 8021E8C8 00000007 */  srav      $zero, $zero, $zero
/* 4F5D6C 8021E8CC 8027A854 */  lb        $a3, -0x57ac($at)
/* 4F5D70 8021E8D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D74 8021E8D4 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D78 8021E8D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5D7C 8021E8DC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F5D80 8021E8E0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F5D84 8021E8E4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5D88 8021E8E8 00000043 */  sra       $zero, $zero, 1
/* 4F5D8C 8021E8EC 00000004 */  sllv      $zero, $zero, $zero
/* 4F5D90 8021E8F0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5D94 8021E8F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5D98 8021E8F8 00000006 */  srlv      $zero, $zero, $zero
/* 4F5D9C 8021E8FC 00680017 */  dsrav     $zero, $t0, $v1
/* 4F5DA0 8021E900 00000008 */  jr        $zero
/* 4F5DA4 8021E904 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5DA8 8021E908 00000002 */  srl       $zero, $zero, 0
/* 4F5DAC 8021E90C 00000043 */  sra       $zero, $zero, 1
/* 4F5DB0 8021E910 00000003 */  sra       $zero, $zero, 0
/* 4F5DB4 8021E914 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F5DB8 8021E918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5DBC 8021E91C 00000000 */  nop       
/* 4F5DC0 8021E920 00000043 */  sra       $zero, $zero, 1
/* 4F5DC4 8021E924 00000008 */  jr        $zero
/* 4F5DC8 8021E928 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F5DCC 8021E92C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5DD0 8021E930 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5DD4 8021E934 10000000 */  b         .L8021E938
.L8021E938:
/* 4F5DD8 8021E938 00000000 */   nop      
/* 4F5DDC 8021E93C 00000000 */  nop       
/* 4F5DE0 8021E940 00000002 */  srl       $zero, $zero, 0
/* 4F5DE4 8021E944 00000020 */  add       $zero, $zero, $zero
/* 4F5DE8 8021E948 00000008 */  jr        $zero
/* 4F5DEC 8021E94C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5DF0 8021E950 00000013 */  mtlo      $zero
/* 4F5DF4 8021E954 00000043 */  sra       $zero, $zero, 1
/* 4F5DF8 8021E958 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F5DFC 8021E95C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4F5E00 8021E960 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5E04 8021E964 00000006 */  srlv      $zero, $zero, $zero
/* 4F5E08 8021E968 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5E0C 8021E96C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5E10 8021E970 0000000A */  movz      $zero, $zero, $zero
/* 4F5E14 8021E974 00000002 */  srl       $zero, $zero, 0
/* 4F5E18 8021E978 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5E1C 8021E97C 0000000A */  movz      $zero, $zero, $zero
/* 4F5E20 8021E980 00000002 */  srl       $zero, $zero, 0
/* 4F5E24 8021E984 00000000 */  nop       
/* 4F5E28 8021E988 00000013 */  mtlo      $zero
/* 4F5E2C 8021E98C 00000000 */  nop       
/* 4F5E30 8021E990 00000002 */  srl       $zero, $zero, 0
/* 4F5E34 8021E994 00000000 */  nop       
/* 4F5E38 8021E998 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5E3C 8021E99C 00000000 */  nop       
/* 4F5E40 8021E9A0 000000BE */  dsrl32    $zero, $zero, 2
/* 4F5E44 8021E9A4 00000000 */  nop       
/* 4F5E48 8021E9A8 00000000 */  nop       
/* 4F5E4C 8021E9AC 80218E9C */  lb        $at, -0x7164($at)
/* 4F5E50 8021E9B0 8021E9A0 */  lb        $at, -0x1660($at)
/* 4F5E54 8021E9B4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4F5E58 8021E9B8 00000000 */  nop       
/* 4F5E5C 8021E9BC 00000000 */  nop       
/* 4F5E60 8021E9C0 00000000 */  nop       
/* 4F5E64 8021E9C4 00000000 */  nop       
/* 4F5E68 8021E9C8 00000043 */  sra       $zero, $zero, 1
/* 4F5E6C 8021E9CC 00000003 */  sra       $zero, $zero, 0
/* 4F5E70 8021E9D0 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F5E74 8021E9D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5E78 8021E9D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5E7C 8021E9DC 00000043 */  sra       $zero, $zero, 1
/* 4F5E80 8021E9E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5E84 8021E9E4 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F5E88 8021E9E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5E8C 8021E9EC 00000003 */  sra       $zero, $zero, 0
/* 4F5E90 8021E9F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5E94 8021E9F4 0000000A */  movz      $zero, $zero, $zero
/* 4F5E98 8021E9F8 00000002 */  srl       $zero, $zero, 0
/* 4F5E9C 8021E9FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5EA0 8021EA00 00000000 */  nop       
/* 4F5EA4 8021EA04 00000043 */  sra       $zero, $zero, 1
/* 4F5EA8 8021EA08 00000002 */  srl       $zero, $zero, 0
/* 4F5EAC 8021EA0C 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F5EB0 8021EA10 0000000D */  break     
/* 4F5EB4 8021EA14 00000043 */   sra      $zero, $zero, 1
/* 4F5EB8 8021EA18 00000002 */  srl       $zero, $zero, 0
/* 4F5EBC 8021EA1C 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F5EC0 8021EA20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5EC4 8021EA24 00000043 */  sra       $zero, $zero, 1
/* 4F5EC8 8021EA28 00000002 */  srl       $zero, $zero, 0
/* 4F5ECC 8021EA2C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F5ED0 8021EA30 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5ED4 8021EA34 00000008 */  jr        $zero
/* 4F5ED8 8021EA38 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5EDC 8021EA3C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5EE0 8021EA40 00000043 */  sra       $zero, $zero, 1
/* 4F5EE4 8021EA44 00000004 */  sllv      $zero, $zero, $zero
/* 4F5EE8 8021EA48 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5EEC 8021EA4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5EF0 8021EA50 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5EF4 8021EA54 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5EF8 8021EA58 00000043 */  sra       $zero, $zero, 1
/* 4F5EFC 8021EA5C 00000006 */  srlv      $zero, $zero, $zero
/* 4F5F00 8021EA60 80252F30 */  lb        $a1, 0x2f30($at)
/* 4F5F04 8021EA64 000D00E6 */  .byte     0x00, 0x0d, 0x00, 0xe6
/* 4F5F08 8021EA68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5F0C 8021EA6C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5F10 8021EA70 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5F14 8021EA74 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5F18 8021EA78 00000012 */  mflo      $zero
/* 4F5F1C 8021EA7C 00000000 */  nop       
/* 4F5F20 8021EA80 00000043 */  sra       $zero, $zero, 1
/* 4F5F24 8021EA84 00000002 */  srl       $zero, $zero, 0
/* 4F5F28 8021EA88 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F5F2C 8021EA8C 0000000D */  break     
/* 4F5F30 8021EA90 00000043 */   sra      $zero, $zero, 1
/* 4F5F34 8021EA94 00000002 */  srl       $zero, $zero, 0
/* 4F5F38 8021EA98 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F5F3C 8021EA9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5F40 8021EAA0 00000043 */  sra       $zero, $zero, 1
/* 4F5F44 8021EAA4 00000002 */  srl       $zero, $zero, 0
/* 4F5F48 8021EAA8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F5F4C 8021EAAC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5F50 8021EAB0 00000008 */  jr        $zero
/* 4F5F54 8021EAB4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F5F58 8021EAB8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F5F5C 8021EABC 00000043 */  sra       $zero, $zero, 1
/* 4F5F60 8021EAC0 00000004 */  sllv      $zero, $zero, $zero
/* 4F5F64 8021EAC4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5F68 8021EAC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5F6C 8021EACC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5F70 8021EAD0 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5F74 8021EAD4 00000043 */  sra       $zero, $zero, 1
/* 4F5F78 8021EAD8 00000006 */  srlv      $zero, $zero, $zero
/* 4F5F7C 8021EADC 80252F30 */  lb        $a1, 0x2f30($at)
/* 4F5F80 8021EAE0 000D00E7 */  .byte     0x00, 0x0d, 0x00, 0xe7
/* 4F5F84 8021EAE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5F88 8021EAE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5F8C 8021EAEC 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5F90 8021EAF0 00680003 */  .byte     0x00, 0x68, 0x00, 0x03
/* 4F5F94 8021EAF4 00000013 */  mtlo      $zero
/* 4F5F98 8021EAF8 00000000 */  nop       
/* 4F5F9C 8021EAFC 00000043 */  sra       $zero, $zero, 1
/* 4F5FA0 8021EB00 00000004 */  sllv      $zero, $zero, $zero
/* 4F5FA4 8021EB04 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F5FA8 8021EB08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5FAC 8021EB0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F5FB0 8021EB10 00680001 */  movf      $zero, $v1, $fcc2
/* 4F5FB4 8021EB14 00000043 */  sra       $zero, $zero, 1
/* 4F5FB8 8021EB18 00000004 */  sllv      $zero, $zero, $zero
/* 4F5FBC 8021EB1C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F5FC0 8021EB20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F5FC4 8021EB24 00000008 */  jr        $zero
/* 4F5FC8 8021EB28 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 4F5FCC 8021EB2C 0000000A */  movz      $zero, $zero, $zero
/* 4F5FD0 8021EB30 00000002 */  srl       $zero, $zero, 0
/* 4F5FD4 8021EB34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F5FD8 8021EB38 00000000 */  nop       
/* 4F5FDC 8021EB3C 00000043 */  sra       $zero, $zero, 1
/* 4F5FE0 8021EB40 00000002 */  srl       $zero, $zero, 0
/* 4F5FE4 8021EB44 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F5FE8 8021EB48 0000000D */  break     
/* 4F5FEC 8021EB4C 00000043 */   sra      $zero, $zero, 1
/* 4F5FF0 8021EB50 00000004 */  sllv      $zero, $zero, $zero
/* 4F5FF4 8021EB54 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4F5FF8 8021EB58 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F5FFC 8021EB5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6000 8021EB60 00000000 */  nop       
/* 4F6004 8021EB64 00000043 */  sra       $zero, $zero, 1
/* 4F6008 8021EB68 00000002 */  srl       $zero, $zero, 0
/* 4F600C 8021EB6C 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F6010 8021EB70 000000E1 */  .byte     0x00, 0x00, 0x00, 0xe1
/* 4F6014 8021EB74 00000043 */  sra       $zero, $zero, 1
/* 4F6018 8021EB78 00000002 */  srl       $zero, $zero, 0
/* 4F601C 8021EB7C 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4F6020 8021EB80 FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4F6024 8021EB84 00000043 */  sra       $zero, $zero, 1
/* 4F6028 8021EB88 00000002 */  srl       $zero, $zero, 0
/* 4F602C 8021EB8C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F6030 8021EB90 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F6034 8021EB94 00000012 */  mflo      $zero
/* 4F6038 8021EB98 00000000 */  nop       
/* 4F603C 8021EB9C 00000043 */  sra       $zero, $zero, 1
/* 4F6040 8021EBA0 00000002 */  srl       $zero, $zero, 0
/* 4F6044 8021EBA4 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F6048 8021EBA8 0000000D */  break     
/* 4F604C 8021EBAC 00000043 */   sra      $zero, $zero, 1
/* 4F6050 8021EBB0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6054 8021EBB4 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4F6058 8021EBB8 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F605C 8021EBBC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6060 8021EBC0 00000000 */  nop       
/* 4F6064 8021EBC4 00000043 */  sra       $zero, $zero, 1
/* 4F6068 8021EBC8 00000002 */  srl       $zero, $zero, 0
/* 4F606C 8021EBCC 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F6070 8021EBD0 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 4F6074 8021EBD4 00000043 */  sra       $zero, $zero, 1
/* 4F6078 8021EBD8 00000002 */  srl       $zero, $zero, 0
/* 4F607C 8021EBDC 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4F6080 8021EBE0 00000023 */  negu      $zero, $zero
/* 4F6084 8021EBE4 00000043 */  sra       $zero, $zero, 1
/* 4F6088 8021EBE8 00000002 */  srl       $zero, $zero, 0
/* 4F608C 8021EBEC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F6090 8021EBF0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F6094 8021EBF4 00000013 */  mtlo      $zero
/* 4F6098 8021EBF8 00000000 */  nop       
/* 4F609C 8021EBFC 00000043 */  sra       $zero, $zero, 1
/* 4F60A0 8021EC00 00000004 */  sllv      $zero, $zero, $zero
/* 4F60A4 8021EC04 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F60A8 8021EC08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F60AC 8021EC0C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F60B0 8021EC10 00000000 */  nop       
/* 4F60B4 8021EC14 00000056 */  drotrv    $zero, $zero, $zero
/* 4F60B8 8021EC18 00000000 */  nop       
/* 4F60BC 8021EC1C 00000003 */  sra       $zero, $zero, 0
/* 4F60C0 8021EC20 00000001 */  movf      $zero, $zero, $fcc0
/* 4F60C4 8021EC24 00000000 */  nop       
/* 4F60C8 8021EC28 00000043 */  sra       $zero, $zero, 1
/* 4F60CC 8021EC2C 00000002 */  srl       $zero, $zero, 0
/* 4F60D0 8021EC30 80254218 */  lb        $a1, 0x4218($at)
/* 4F60D4 8021EC34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F60D8 8021EC38 00000043 */  sra       $zero, $zero, 1
/* 4F60DC 8021EC3C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F60E0 8021EC40 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F60E4 8021EC44 00000001 */  movf      $zero, $zero, $fcc0
/* 4F60E8 8021EC48 00000000 */  nop       
/* 4F60EC 8021EC4C 00000002 */  srl       $zero, $zero, 0
/* 4F60F0 8021EC50 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F60F4 8021EC54 00000008 */  jr        $zero
/* 4F60F8 8021EC58 00000001 */   movf     $zero, $zero, $fcc0
/* 4F60FC 8021EC5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6100 8021EC60 00000043 */  sra       $zero, $zero, 1
/* 4F6104 8021EC64 00000004 */  sllv      $zero, $zero, $zero
/* 4F6108 8021EC68 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F610C 8021EC6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6110 8021EC70 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6114 8021EC74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6118 8021EC78 0000000C */  syscall   
/* 4F611C 8021EC7C 00000002 */  srl       $zero, $zero, 0
/* 4F6120 8021EC80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6124 8021EC84 0000003C */  dsll32    $zero, $zero, 0
/* 4F6128 8021EC88 00000004 */  sllv      $zero, $zero, $zero
/* 4F612C 8021EC8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6130 8021EC90 00000000 */  nop       
/* 4F6134 8021EC94 00000013 */  mtlo      $zero
/* 4F6138 8021EC98 00000000 */  nop       
/* 4F613C 8021EC9C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F6140 8021ECA0 00000000 */  nop       
/* 4F6144 8021ECA4 00000043 */  sra       $zero, $zero, 1
/* 4F6148 8021ECA8 00000002 */  srl       $zero, $zero, 0
/* 4F614C 8021ECAC 802D6150 */  lb        $t5, 0x6150($at)
/* 4F6150 8021ECB0 0000026B */  .byte     0x00, 0x00, 0x02, 0x6b
/* 4F6154 8021ECB4 00000003 */  sra       $zero, $zero, 0
/* 4F6158 8021ECB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F615C 8021ECBC 0000000A */  movz      $zero, $zero, $zero
/* 4F6160 8021ECC0 00000043 */  sra       $zero, $zero, 1
/* 4F6164 8021ECC4 00000004 */  sllv      $zero, $zero, $zero
/* 4F6168 8021ECC8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F616C 8021ECCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6170 8021ECD0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6174 8021ECD4 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F6178 8021ECD8 00000043 */  sra       $zero, $zero, 1
/* 4F617C 8021ECDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6180 8021ECE0 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4F6184 8021ECE4 0000001F */  ddivu     $zero, $zero, $zero
/* 4F6188 8021ECE8 00000000 */  nop       
/* 4F618C 8021ECEC FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F6190 8021ECF0 00000000 */  nop       
/* 4F6194 8021ECF4 00000027 */  not       $zero, $zero
/* 4F6198 8021ECF8 00000002 */  srl       $zero, $zero, 0
/* 4F619C 8021ECFC FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F61A0 8021ED00 00000001 */  movf      $zero, $zero, $fcc0
/* 4F61A4 8021ED04 00000043 */  sra       $zero, $zero, 1
/* 4F61A8 8021ED08 00000004 */  sllv      $zero, $zero, $zero
/* 4F61AC 8021ED0C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F61B0 8021ED10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F61B4 8021ED14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F61B8 8021ED18 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F61BC 8021ED1C 00000008 */  jr        $zero
/* 4F61C0 8021ED20 00000001 */   movf     $zero, $zero, $fcc0
/* 4F61C4 8021ED24 00000001 */  movf      $zero, $zero, $fcc0
/* 4F61C8 8021ED28 0000000C */  syscall   
/* 4F61CC 8021ED2C 00000002 */  srl       $zero, $zero, 0
/* 4F61D0 8021ED30 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F61D4 8021ED34 0000003C */  dsll32    $zero, $zero, 0
/* 4F61D8 8021ED38 00000004 */  sllv      $zero, $zero, $zero
/* 4F61DC 8021ED3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F61E0 8021ED40 0000000A */  movz      $zero, $zero, $zero
/* 4F61E4 8021ED44 00000013 */  mtlo      $zero
/* 4F61E8 8021ED48 00000000 */  nop       
/* 4F61EC 8021ED4C 00000043 */  sra       $zero, $zero, 1
/* 4F61F0 8021ED50 00000002 */  srl       $zero, $zero, 0
/* 4F61F4 8021ED54 802D62B8 */  lb        $t5, 0x62b8($at)
/* 4F61F8 8021ED58 0000026B */  .byte     0x00, 0x00, 0x02, 0x6b
/* 4F61FC 8021ED5C 00000008 */  jr        $zero
/* 4F6200 8021ED60 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6204 8021ED64 0000000A */  movz      $zero, $zero, $zero
/* 4F6208 8021ED68 00000043 */  sra       $zero, $zero, 1
/* 4F620C 8021ED6C 00000003 */  sra       $zero, $zero, 0
/* 4F6210 8021ED70 8026DB64 */  lb        $a2, -0x249c($at)
/* 4F6214 8021ED74 8021E9AC */  lb        $at, -0x1654($at)
/* 4F6218 8021ED78 00000000 */  nop       
/* 4F621C 8021ED7C 00000024 */  and       $zero, $zero, $zero
/* 4F6220 8021ED80 00000002 */  srl       $zero, $zero, 0
/* 4F6224 8021ED84 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6228 8021ED88 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F622C 8021ED8C 00000024 */  and       $zero, $zero, $zero
/* 4F6230 8021ED90 00000002 */  srl       $zero, $zero, 0
/* 4F6234 8021ED94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6238 8021ED98 000000A5 */  .byte     0x00, 0x00, 0x00, 0xa5
/* 4F623C 8021ED9C 00000024 */  and       $zero, $zero, $zero
/* 4F6240 8021EDA0 00000002 */  srl       $zero, $zero, 0
/* 4F6244 8021EDA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6248 8021EDA8 00000000 */  nop       
/* 4F624C 8021EDAC 00000024 */  and       $zero, $zero, $zero
/* 4F6250 8021EDB0 00000002 */  srl       $zero, $zero, 0
/* 4F6254 8021EDB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6258 8021EDB8 FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4F625C 8021EDBC 00000043 */  sra       $zero, $zero, 1
/* 4F6260 8021EDC0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6264 8021EDC4 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4F6268 8021EDC8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F626C 8021EDCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6270 8021EDD0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6274 8021EDD4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6278 8021EDD8 00000043 */  sra       $zero, $zero, 1
/* 4F627C 8021EDDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6280 8021EDE0 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F6284 8021EDE4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6288 8021EDE8 00000000 */  nop       
/* 4F628C 8021EDEC 00000000 */  nop       
/* 4F6290 8021EDF0 00000000 */  nop       
/* 4F6294 8021EDF4 00000043 */  sra       $zero, $zero, 1
/* 4F6298 8021EDF8 00000003 */  sra       $zero, $zero, 0
/* 4F629C 8021EDFC 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F62A0 8021EE00 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F62A4 8021EE04 00000000 */  nop       
/* 4F62A8 8021EE08 00000043 */  sra       $zero, $zero, 1
/* 4F62AC 8021EE0C 00000003 */  sra       $zero, $zero, 0
/* 4F62B0 8021EE10 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F62B4 8021EE14 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F62B8 8021EE18 00000000 */  nop       
/* 4F62BC 8021EE1C 00000043 */  sra       $zero, $zero, 1
/* 4F62C0 8021EE20 00000004 */  sllv      $zero, $zero, $zero
/* 4F62C4 8021EE24 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F62C8 8021EE28 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F62CC 8021EE2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F62D0 8021EE30 00690005 */  lsa       $zero, $v1, $t1, 1
/* 4F62D4 8021EE34 00000043 */  sra       $zero, $zero, 1
/* 4F62D8 8021EE38 00000003 */  sra       $zero, $zero, 0
/* 4F62DC 8021EE3C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F62E0 8021EE40 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F62E4 8021EE44 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F62E8 8021EE48 00000043 */  sra       $zero, $zero, 1
/* 4F62EC 8021EE4C 00000003 */  sra       $zero, $zero, 0
/* 4F62F0 8021EE50 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F62F4 8021EE54 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F62F8 8021EE58 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F62FC 8021EE5C 00000024 */  and       $zero, $zero, $zero
/* 4F6300 8021EE60 00000002 */  srl       $zero, $zero, 0
/* 4F6304 8021EE64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6308 8021EE68 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4F630C 8021EE6C 00000024 */  and       $zero, $zero, $zero
/* 4F6310 8021EE70 00000002 */  srl       $zero, $zero, 0
/* 4F6314 8021EE74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6318 8021EE78 00000000 */  nop       
/* 4F631C 8021EE7C 00000024 */  and       $zero, $zero, $zero
/* 4F6320 8021EE80 00000002 */  srl       $zero, $zero, 0
/* 4F6324 8021EE84 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6328 8021EE88 FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4F632C 8021EE8C 00000024 */  and       $zero, $zero, $zero
/* 4F6330 8021EE90 00000002 */  srl       $zero, $zero, 0
/* 4F6334 8021EE94 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F6338 8021EE98 00000008 */  jr        $zero
/* 4F633C 8021EE9C 00000024 */   and      $zero, $zero, $zero
/* 4F6340 8021EEA0 00000002 */  srl       $zero, $zero, 0
/* 4F6344 8021EEA4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F6348 8021EEA8 0000001E */  ddiv      $zero, $zero, $zero
/* 4F634C 8021EEAC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F6350 8021EEB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6354 8021EEB4 8021F42C */  lb        $at, -0xbd4($at)
/* 4F6358 8021EEB8 00000043 */  sra       $zero, $zero, 1
/* 4F635C 8021EEBC 00000004 */  sllv      $zero, $zero, $zero
/* 4F6360 8021EEC0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F6364 8021EEC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6368 8021EEC8 00000003 */  sra       $zero, $zero, 0
/* 4F636C 8021EECC FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F6370 8021EED0 0000000A */  movz      $zero, $zero, $zero
/* 4F6374 8021EED4 00000002 */  srl       $zero, $zero, 0
/* 4F6378 8021EED8 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F637C 8021EEDC 00000000 */  nop       
/* 4F6380 8021EEE0 00000043 */  sra       $zero, $zero, 1
/* 4F6384 8021EEE4 00000002 */  srl       $zero, $zero, 0
/* 4F6388 8021EEE8 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F638C 8021EEEC 00000013 */  mtlo      $zero
/* 4F6390 8021EEF0 00000043 */  sra       $zero, $zero, 1
/* 4F6394 8021EEF4 00000002 */  srl       $zero, $zero, 0
/* 4F6398 8021EEF8 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F639C 8021EEFC 000000A0 */  .byte     0x00, 0x00, 0x00, 0xa0
/* 4F63A0 8021EF00 00000043 */  sra       $zero, $zero, 1
/* 4F63A4 8021EF04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F63A8 8021EF08 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F63AC 8021EF0C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F63B0 8021EF10 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F63B4 8021EF14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F63B8 8021EF18 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F63BC 8021EF1C 00000024 */  and       $zero, $zero, $zero
/* 4F63C0 8021EF20 00000002 */  srl       $zero, $zero, 0
/* 4F63C4 8021EF24 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F63C8 8021EF28 0000003C */  dsll32    $zero, $zero, 0
/* 4F63CC 8021EF2C 00000043 */  sra       $zero, $zero, 1
/* 4F63D0 8021EF30 00000004 */  sllv      $zero, $zero, $zero
/* 4F63D4 8021EF34 8024E90C */  lb        $a0, -0x16f4($at)
/* 4F63D8 8021EF38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F63DC 8021EF3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F63E0 8021EF40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F63E4 8021EF44 00000043 */  sra       $zero, $zero, 1
/* 4F63E8 8021EF48 00000002 */  srl       $zero, $zero, 0
/* 4F63EC 8021EF4C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F63F0 8021EF50 00000008 */  jr        $zero
/* 4F63F4 8021EF54 00000005 */   lsa      $zero, $zero, $zero, 1
/* 4F63F8 8021EF58 00000001 */  movf      $zero, $zero, $fcc0
/* 4F63FC 8021EF5C 00000003 */  sra       $zero, $zero, 0
/* 4F6400 8021EF60 00000043 */  sra       $zero, $zero, 1
/* 4F6404 8021EF64 00000002 */  srl       $zero, $zero, 0
/* 4F6408 8021EF68 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F640C 8021EF6C 00000013 */  mtlo      $zero
/* 4F6410 8021EF70 00000043 */  sra       $zero, $zero, 1
/* 4F6414 8021EF74 00000002 */  srl       $zero, $zero, 0
/* 4F6418 8021EF78 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F641C 8021EF7C 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F6420 8021EF80 00000043 */  sra       $zero, $zero, 1
/* 4F6424 8021EF84 00000004 */  sllv      $zero, $zero, $zero
/* 4F6428 8021EF88 8024E90C */  lb        $a0, -0x16f4($at)
/* 4F642C 8021EF8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6430 8021EF90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6434 8021EF94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6438 8021EF98 00000043 */  sra       $zero, $zero, 1
/* 4F643C 8021EF9C 00000002 */  srl       $zero, $zero, 0
/* 4F6440 8021EFA0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F6444 8021EFA4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6448 8021EFA8 00000008 */  jr        $zero
/* 4F644C 8021EFAC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6450 8021EFB0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6454 8021EFB4 00000043 */  sra       $zero, $zero, 1
/* 4F6458 8021EFB8 00000003 */  sra       $zero, $zero, 0
/* 4F645C 8021EFBC 8025385C */  lb        $a1, 0x385c($at)
/* 4F6460 8021EFC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6464 8021EFC4 00002061 */  .byte     0x00, 0x00, 0x20, 0x61
/* 4F6468 8021EFC8 00000043 */  sra       $zero, $zero, 1
/* 4F646C 8021EFCC 00000002 */  srl       $zero, $zero, 0
/* 4F6470 8021EFD0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F6474 8021EFD4 00000013 */  mtlo      $zero
/* 4F6478 8021EFD8 00000043 */  sra       $zero, $zero, 1
/* 4F647C 8021EFDC 00000002 */  srl       $zero, $zero, 0
/* 4F6480 8021EFE0 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F6484 8021EFE4 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 4F6488 8021EFE8 00000043 */  sra       $zero, $zero, 1
/* 4F648C 8021EFEC 00000004 */  sllv      $zero, $zero, $zero
/* 4F6490 8021EFF0 8024E90C */  lb        $a0, -0x16f4($at)
/* 4F6494 8021EFF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6498 8021EFF8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F649C 8021EFFC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F64A0 8021F000 00000043 */  sra       $zero, $zero, 1
/* 4F64A4 8021F004 00000002 */  srl       $zero, $zero, 0
/* 4F64A8 8021F008 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F64AC 8021F00C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F64B0 8021F010 00000008 */  jr        $zero
/* 4F64B4 8021F014 00000001 */   movf     $zero, $zero, $fcc0
/* 4F64B8 8021F018 00000004 */  sllv      $zero, $zero, $zero
/* 4F64BC 8021F01C 00000006 */  srlv      $zero, $zero, $zero
/* 4F64C0 8021F020 00000000 */  nop       
/* 4F64C4 8021F024 00000012 */  mflo      $zero
/* 4F64C8 8021F028 00000000 */  nop       
/* 4F64CC 8021F02C 00000008 */  jr        $zero
/* 4F64D0 8021F030 00000001 */   movf     $zero, $zero, $fcc0
/* 4F64D4 8021F034 00000008 */  jr        $zero
/* 4F64D8 8021F038 00000043 */   sra      $zero, $zero, 1
/* 4F64DC 8021F03C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F64E0 8021F040 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F64E4 8021F044 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F64E8 8021F048 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F64EC 8021F04C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F64F0 8021F050 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F64F4 8021F054 00000043 */  sra       $zero, $zero, 1
/* 4F64F8 8021F058 00000006 */  srlv      $zero, $zero, $zero
/* 4F64FC 8021F05C 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6500 8021F060 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6504 8021F064 00000008 */  jr        $zero
/* 4F6508 8021F068 00000000 */   nop      
/* 4F650C 8021F06C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6510 8021F070 00000000 */  nop       
/* 4F6514 8021F074 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6518 8021F078 00000000 */  nop       
/* 4F651C 8021F07C 00000043 */  sra       $zero, $zero, 1
/* 4F6520 8021F080 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6524 8021F084 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F6528 8021F088 00000001 */  movf      $zero, $zero, $fcc0
/* 4F652C 8021F08C 00000000 */  nop       
/* 4F6530 8021F090 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6534 8021F094 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F6538 8021F098 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F653C 8021F09C 00000000 */  nop       
/* 4F6540 8021F0A0 00000043 */  sra       $zero, $zero, 1
/* 4F6544 8021F0A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6548 8021F0A8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F654C 8021F0AC FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6550 8021F0B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6554 8021F0B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6558 8021F0B8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F655C 8021F0BC 00000043 */  sra       $zero, $zero, 1
/* 4F6560 8021F0C0 00000006 */  srlv      $zero, $zero, $zero
/* 4F6564 8021F0C4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6568 8021F0C8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F656C 8021F0CC 00000008 */  jr        $zero
/* 4F6570 8021F0D0 00000000 */   nop      
/* 4F6574 8021F0D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6578 8021F0D8 00000000 */  nop       
/* 4F657C 8021F0DC 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6580 8021F0E0 00000000 */  nop       
/* 4F6584 8021F0E4 00000043 */  sra       $zero, $zero, 1
/* 4F6588 8021F0E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F658C 8021F0EC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F6590 8021F0F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6594 8021F0F4 00000000 */  nop       
/* 4F6598 8021F0F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F659C 8021F0FC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F65A0 8021F100 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F65A4 8021F104 00000000 */  nop       
/* 4F65A8 8021F108 00000008 */  jr        $zero
/* 4F65AC 8021F10C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F65B0 8021F110 00000008 */  jr        $zero
/* 4F65B4 8021F114 00000013 */   mtlo     $zero
/* 4F65B8 8021F118 00000000 */  nop       
/* 4F65BC 8021F11C 00000043 */  sra       $zero, $zero, 1
/* 4F65C0 8021F120 00000002 */  srl       $zero, $zero, 0
/* 4F65C4 8021F124 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F65C8 8021F128 00000002 */  srl       $zero, $zero, 0
/* 4F65CC 8021F12C 00000043 */  sra       $zero, $zero, 1
/* 4F65D0 8021F130 00000002 */  srl       $zero, $zero, 0
/* 4F65D4 8021F134 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F65D8 8021F138 0000001E */  ddiv      $zero, $zero, $zero
/* 4F65DC 8021F13C 00000043 */  sra       $zero, $zero, 1
/* 4F65E0 8021F140 00000003 */  sra       $zero, $zero, 0
/* 4F65E4 8021F144 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F65E8 8021F148 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F65EC 8021F14C F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F65F0 8021F150 00000043 */  sra       $zero, $zero, 1
/* 4F65F4 8021F154 00000003 */  sra       $zero, $zero, 0
/* 4F65F8 8021F158 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F65FC 8021F15C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6600 8021F160 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F6604 8021F164 00000024 */  and       $zero, $zero, $zero
/* 4F6608 8021F168 00000002 */  srl       $zero, $zero, 0
/* 4F660C 8021F16C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6610 8021F170 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6614 8021F174 00000024 */  and       $zero, $zero, $zero
/* 4F6618 8021F178 00000002 */  srl       $zero, $zero, 0
/* 4F661C 8021F17C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6620 8021F180 00000000 */  nop       
/* 4F6624 8021F184 00000024 */  and       $zero, $zero, $zero
/* 4F6628 8021F188 00000002 */  srl       $zero, $zero, 0
/* 4F662C 8021F18C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6630 8021F190 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6634 8021F194 00000024 */  and       $zero, $zero, $zero
/* 4F6638 8021F198 00000002 */  srl       $zero, $zero, 0
/* 4F663C 8021F19C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F6640 8021F1A0 00000008 */  jr        $zero
/* 4F6644 8021F1A4 00000024 */   and      $zero, $zero, $zero
/* 4F6648 8021F1A8 00000002 */  srl       $zero, $zero, 0
/* 4F664C 8021F1AC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F6650 8021F1B0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6654 8021F1B4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F6658 8021F1B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F665C 8021F1BC 8021F42C */  lb        $at, -0xbd4($at)
/* 4F6660 8021F1C0 00000043 */  sra       $zero, $zero, 1
/* 4F6664 8021F1C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6668 8021F1C8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F666C 8021F1CC FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6670 8021F1D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6674 8021F1D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6678 8021F1D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F667C 8021F1DC 00000043 */  sra       $zero, $zero, 1
/* 4F6680 8021F1E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6684 8021F1E4 8026A1EC */  lb        $a2, -0x5e14($at)
/* 4F6688 8021F1E8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F668C 8021F1EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6690 8021F1F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6694 8021F1F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6698 8021F1F8 00000043 */  sra       $zero, $zero, 1
/* 4F669C 8021F1FC 00000006 */  srlv      $zero, $zero, $zero
/* 4F66A0 8021F200 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4F66A4 8021F204 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F66A8 8021F208 00000002 */  srl       $zero, $zero, 0
/* 4F66AC 8021F20C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F66B0 8021F210 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F66B4 8021F214 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F66B8 8021F218 00000043 */  sra       $zero, $zero, 1
/* 4F66BC 8021F21C 00000002 */  srl       $zero, $zero, 0
/* 4F66C0 8021F220 8026D664 */  lb        $a2, -0x299c($at)
/* 4F66C4 8021F224 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F66C8 8021F228 00000043 */  sra       $zero, $zero, 1
/* 4F66CC 8021F22C 00000003 */  sra       $zero, $zero, 0
/* 4F66D0 8021F230 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F66D4 8021F234 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F66D8 8021F238 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F66DC 8021F23C 00000043 */  sra       $zero, $zero, 1
/* 4F66E0 8021F240 00000003 */  sra       $zero, $zero, 0
/* 4F66E4 8021F244 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F66E8 8021F248 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F66EC 8021F24C F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F66F0 8021F250 00000043 */  sra       $zero, $zero, 1
/* 4F66F4 8021F254 00000003 */  sra       $zero, $zero, 0
/* 4F66F8 8021F258 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F66FC 8021F25C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6700 8021F260 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6704 8021F264 00000043 */  sra       $zero, $zero, 1
/* 4F6708 8021F268 00000003 */  sra       $zero, $zero, 0
/* 4F670C 8021F26C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F6710 8021F270 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6714 8021F274 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6718 8021F278 00000043 */  sra       $zero, $zero, 1
/* 4F671C 8021F27C 00000004 */  sllv      $zero, $zero, $zero
/* 4F6720 8021F280 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F6724 8021F284 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6728 8021F288 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F672C 8021F28C 0000003C */  dsll32    $zero, $zero, 0
/* 4F6730 8021F290 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6734 8021F294 00000000 */  nop       
/* 4F6738 8021F298 00000003 */  sra       $zero, $zero, 0
/* 4F673C 8021F29C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6740 8021F2A0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F6744 8021F2A4 00000043 */  sra       $zero, $zero, 1
/* 4F6748 8021F2A8 00000002 */  srl       $zero, $zero, 0
/* 4F674C 8021F2AC 80254218 */  lb        $a1, 0x4218($at)
/* 4F6750 8021F2B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6754 8021F2B4 00000043 */  sra       $zero, $zero, 1
/* 4F6758 8021F2B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F675C 8021F2BC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F6760 8021F2C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6764 8021F2C4 00000000 */  nop       
/* 4F6768 8021F2C8 00000002 */  srl       $zero, $zero, 0
/* 4F676C 8021F2CC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F6770 8021F2D0 00000008 */  jr        $zero
/* 4F6774 8021F2D4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6778 8021F2D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F677C 8021F2DC 00000043 */  sra       $zero, $zero, 1
/* 4F6780 8021F2E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6784 8021F2E4 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F6788 8021F2E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F678C 8021F2EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6790 8021F2F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6794 8021F2F4 0000000B */  movn      $zero, $zero, $zero
/* 4F6798 8021F2F8 00000002 */  srl       $zero, $zero, 0
/* 4F679C 8021F2FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F67A0 8021F300 00000000 */  nop       
/* 4F67A4 8021F304 00000004 */  sllv      $zero, $zero, $zero
/* 4F67A8 8021F308 00000001 */  movf      $zero, $zero, $fcc0
/* 4F67AC 8021F30C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F67B0 8021F310 00000013 */  mtlo      $zero
/* 4F67B4 8021F314 00000000 */  nop       
/* 4F67B8 8021F318 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F67BC 8021F31C 00000000 */  nop       
/* 4F67C0 8021F320 00000043 */  sra       $zero, $zero, 1
/* 4F67C4 8021F324 00000002 */  srl       $zero, $zero, 0
/* 4F67C8 8021F328 802D6150 */  lb        $t5, 0x6150($at)
/* 4F67CC 8021F32C 0000026B */  .byte     0x00, 0x00, 0x02, 0x6b
/* 4F67D0 8021F330 00000003 */  sra       $zero, $zero, 0
/* 4F67D4 8021F334 00000001 */  movf      $zero, $zero, $fcc0
/* 4F67D8 8021F338 00000032 */  tlt       $zero, $zero
/* 4F67DC 8021F33C 00000043 */  sra       $zero, $zero, 1
/* 4F67E0 8021F340 00000004 */  sllv      $zero, $zero, $zero
/* 4F67E4 8021F344 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F67E8 8021F348 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F67EC 8021F34C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F67F0 8021F350 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F67F4 8021F354 00000043 */  sra       $zero, $zero, 1
/* 4F67F8 8021F358 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F67FC 8021F35C 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4F6800 8021F360 0000001F */  ddivu     $zero, $zero, $zero
/* 4F6804 8021F364 00000000 */  nop       
/* 4F6808 8021F368 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F680C 8021F36C 00000000 */  nop       
/* 4F6810 8021F370 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F6814 8021F374 00000002 */  srl       $zero, $zero, 0
/* 4F6818 8021F378 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F681C 8021F37C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6820 8021F380 00000043 */  sra       $zero, $zero, 1
/* 4F6824 8021F384 00000004 */  sllv      $zero, $zero, $zero
/* 4F6828 8021F388 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F682C 8021F38C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6830 8021F390 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6834 8021F394 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F6838 8021F398 00000008 */  jr        $zero
/* 4F683C 8021F39C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6840 8021F3A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6844 8021F3A4 0000000D */  break     
/* 4F6848 8021F3A8 00000002 */   srl      $zero, $zero, 0
/* 4F684C 8021F3AC FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 4F6850 8021F3B0 00000000 */  nop       
/* 4F6854 8021F3B4 00000004 */  sllv      $zero, $zero, $zero
/* 4F6858 8021F3B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F685C 8021F3BC 00000032 */  tlt       $zero, $zero
/* 4F6860 8021F3C0 00000013 */  mtlo      $zero
/* 4F6864 8021F3C4 00000000 */  nop       
/* 4F6868 8021F3C8 00000043 */  sra       $zero, $zero, 1
/* 4F686C 8021F3CC 00000002 */  srl       $zero, $zero, 0
/* 4F6870 8021F3D0 802D62B8 */  lb        $t5, 0x62b8($at)
/* 4F6874 8021F3D4 0000026B */  .byte     0x00, 0x00, 0x02, 0x6b
/* 4F6878 8021F3D8 00000043 */  sra       $zero, $zero, 1
/* 4F687C 8021F3DC 00000002 */  srl       $zero, $zero, 0
/* 4F6880 8021F3E0 802D6150 */  lb        $t5, 0x6150($at)
/* 4F6884 8021F3E4 0000026C */  .byte     0x00, 0x00, 0x02, 0x6c
/* 4F6888 8021F3E8 00000043 */  sra       $zero, $zero, 1
/* 4F688C 8021F3EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6890 8021F3F0 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F6894 8021F3F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6898 8021F3F8 00000000 */  nop       
/* 4F689C 8021F3FC 00000004 */  sllv      $zero, $zero, $zero
/* 4F68A0 8021F400 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F68A4 8021F404 00000043 */  sra       $zero, $zero, 1
/* 4F68A8 8021F408 00000004 */  sllv      $zero, $zero, $zero
/* 4F68AC 8021F40C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F68B0 8021F410 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F68B4 8021F414 00000003 */  sra       $zero, $zero, 0
/* 4F68B8 8021F418 00000001 */  movf      $zero, $zero, $fcc0
/* 4F68BC 8021F41C 00000002 */  srl       $zero, $zero, 0
/* 4F68C0 8021F420 00000000 */  nop       
/* 4F68C4 8021F424 00000001 */  movf      $zero, $zero, $fcc0
/* 4F68C8 8021F428 00000000 */  nop       
/* 4F68CC 8021F42C 00000003 */  sra       $zero, $zero, 0
/* 4F68D0 8021F430 00000001 */  movf      $zero, $zero, $fcc0
/* 4F68D4 8021F434 00000014 */  dsllv     $zero, $zero, $zero
/* 4F68D8 8021F438 00000043 */  sra       $zero, $zero, 1
/* 4F68DC 8021F43C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F68E0 8021F440 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F68E4 8021F444 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F68E8 8021F448 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F68EC 8021F44C FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F68F0 8021F450 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4F68F4 8021F454 0000000A */  movz      $zero, $zero, $zero
/* 4F68F8 8021F458 00000002 */  srl       $zero, $zero, 0
/* 4F68FC 8021F45C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F6900 8021F460 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6904 8021F464 00000004 */  sllv      $zero, $zero, $zero
/* 4F6908 8021F468 00000001 */  movf      $zero, $zero, $fcc0
/* 4F690C 8021F46C 0000001E */  ddiv      $zero, $zero, $zero
/* 4F6910 8021F470 00000013 */  mtlo      $zero
/* 4F6914 8021F474 00000000 */  nop       
/* 4F6918 8021F478 00000024 */  and       $zero, $zero, $zero
/* 4F691C 8021F47C 00000002 */  srl       $zero, $zero, 0
/* 4F6920 8021F480 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F6924 8021F484 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F6928 8021F488 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F692C 8021F48C 00000002 */  srl       $zero, $zero, 0
/* 4F6930 8021F490 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F6934 8021F494 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6938 8021F498 0000000C */  syscall   
/* 4F693C 8021F49C 00000002 */  srl       $zero, $zero, 0
/* 4F6940 8021F4A0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4F6944 8021F4A4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F6948 8021F4A8 00000043 */  sra       $zero, $zero, 1
/* 4F694C 8021F4AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6950 8021F4B0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F6954 8021F4B4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6958 8021F4B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F695C 8021F4BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6960 8021F4C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6964 8021F4C4 00000043 */  sra       $zero, $zero, 1
/* 4F6968 8021F4C8 00000006 */  srlv      $zero, $zero, $zero
/* 4F696C 8021F4CC 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6970 8021F4D0 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6974 8021F4D4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F6978 8021F4D8 00000000 */  nop       
/* 4F697C 8021F4DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6980 8021F4E0 00000000 */  nop       
/* 4F6984 8021F4E4 00000043 */  sra       $zero, $zero, 1
/* 4F6988 8021F4E8 00000003 */  sra       $zero, $zero, 0
/* 4F698C 8021F4EC 8025385C */  lb        $a1, 0x385c($at)
/* 4F6990 8021F4F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6994 8021F4F4 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F6998 8021F4F8 00000056 */  drotrv    $zero, $zero, $zero
/* 4F699C 8021F4FC 00000000 */  nop       
/* 4F69A0 8021F500 00000043 */  sra       $zero, $zero, 1
/* 4F69A4 8021F504 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F69A8 8021F508 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F69AC 8021F50C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F69B0 8021F510 00000000 */  nop       
/* 4F69B4 8021F514 00000001 */  movf      $zero, $zero, $fcc0
/* 4F69B8 8021F518 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F69BC 8021F51C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F69C0 8021F520 00000000 */  nop       
/* 4F69C4 8021F524 00000012 */  mflo      $zero
/* 4F69C8 8021F528 00000000 */  nop       
/* 4F69CC 8021F52C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F69D0 8021F530 00000002 */  srl       $zero, $zero, 0
/* 4F69D4 8021F534 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F69D8 8021F538 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4F69DC 8021F53C 00000043 */  sra       $zero, $zero, 1
/* 4F69E0 8021F540 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F69E4 8021F544 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F69E8 8021F548 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F69EC 8021F54C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F69F0 8021F550 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F69F4 8021F554 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F69F8 8021F558 00000043 */  sra       $zero, $zero, 1
/* 4F69FC 8021F55C 00000006 */  srlv      $zero, $zero, $zero
/* 4F6A00 8021F560 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6A04 8021F564 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F6A08 8021F568 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F6A0C 8021F56C 00000000 */  nop       
/* 4F6A10 8021F570 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A14 8021F574 00000000 */  nop       
/* 4F6A18 8021F578 00000043 */  sra       $zero, $zero, 1
/* 4F6A1C 8021F57C 00000003 */  sra       $zero, $zero, 0
/* 4F6A20 8021F580 8025385C */  lb        $a1, 0x385c($at)
/* 4F6A24 8021F584 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6A28 8021F588 00002062 */  .byte     0x00, 0x00, 0x20, 0x62
/* 4F6A2C 8021F58C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6A30 8021F590 00000000 */  nop       
/* 4F6A34 8021F594 00000043 */  sra       $zero, $zero, 1
/* 4F6A38 8021F598 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6A3C 8021F59C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 4F6A40 8021F5A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A44 8021F5A4 00000000 */  nop       
/* 4F6A48 8021F5A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A4C 8021F5AC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F6A50 8021F5B0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F6A54 8021F5B4 00000000 */  nop       
/* 4F6A58 8021F5B8 00000013 */  mtlo      $zero
/* 4F6A5C 8021F5BC 00000000 */  nop       
/* 4F6A60 8021F5C0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6A64 8021F5C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A68 8021F5C8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6A6C 8021F5CC 00000003 */  sra       $zero, $zero, 0
/* 4F6A70 8021F5D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A74 8021F5D4 0000001E */  ddiv      $zero, $zero, $zero
/* 4F6A78 8021F5D8 00000002 */  srl       $zero, $zero, 0
/* 4F6A7C 8021F5DC 00000000 */  nop       
/* 4F6A80 8021F5E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6A84 8021F5E4 00000000 */  nop       
/* 4F6A88 8021F5E8 00000043 */  sra       $zero, $zero, 1
/* 4F6A8C 8021F5EC 00000004 */  sllv      $zero, $zero, $zero
/* 4F6A90 8021F5F0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F6A94 8021F5F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6A98 8021F5F8 00000007 */  srav      $zero, $zero, $zero
/* 4F6A9C 8021F5FC 00000000 */  nop       
/* 4F6AA0 8021F600 00000043 */  sra       $zero, $zero, 1
/* 4F6AA4 8021F604 00000002 */  srl       $zero, $zero, 0
/* 4F6AA8 8021F608 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F6AAC 8021F60C 0000000D */  break     
/* 4F6AB0 8021F610 00000043 */   sra      $zero, $zero, 1
/* 4F6AB4 8021F614 00000002 */  srl       $zero, $zero, 0
/* 4F6AB8 8021F618 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F6ABC 8021F61C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6AC0 8021F620 00000043 */  sra       $zero, $zero, 1
/* 4F6AC4 8021F624 00000003 */  sra       $zero, $zero, 0
/* 4F6AC8 8021F628 8025385C */  lb        $a1, 0x385c($at)
/* 4F6ACC 8021F62C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6AD0 8021F630 000020E1 */  .byte     0x00, 0x00, 0x20, 0xe1
/* 4F6AD4 8021F634 00000043 */  sra       $zero, $zero, 1
/* 4F6AD8 8021F638 00000004 */  sllv      $zero, $zero, $zero
/* 4F6ADC 8021F63C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F6AE0 8021F640 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6AE4 8021F644 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6AE8 8021F648 00680008 */  .byte     0x00, 0x68, 0x00, 0x08
/* 4F6AEC 8021F64C 00000043 */  sra       $zero, $zero, 1
/* 4F6AF0 8021F650 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6AF4 8021F654 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F6AF8 8021F658 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6AFC 8021F65C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6B00 8021F660 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6B04 8021F664 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6B08 8021F668 00000027 */  not       $zero, $zero
/* 4F6B0C 8021F66C 00000002 */  srl       $zero, $zero, 0
/* 4F6B10 8021F670 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6B14 8021F674 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6B18 8021F678 00000043 */  sra       $zero, $zero, 1
/* 4F6B1C 8021F67C 0000000F */  sync      
/* 4F6B20 8021F680 802D829C */  lb        $t5, -0x7d64($at)
/* 4F6B24 8021F684 00000071 */  tgeu      $zero, $zero, 1
/* 4F6B28 8021F688 00000000 */  nop       
/* 4F6B2C 8021F68C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6B30 8021F690 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6B34 8021F694 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6B38 8021F698 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F6B3C 8021F69C 0000002D */  daddu     $zero, $zero, $zero
/* 4F6B40 8021F6A0 00000000 */  nop       
/* 4F6B44 8021F6A4 00000000 */  nop       
/* 4F6B48 8021F6A8 00000000 */  nop       
/* 4F6B4C 8021F6AC 00000000 */  nop       
/* 4F6B50 8021F6B0 00000000 */  nop       
/* 4F6B54 8021F6B4 00000000 */  nop       
/* 4F6B58 8021F6B8 00000000 */  nop       
/* 4F6B5C 8021F6BC 00000008 */  jr        $zero
/* 4F6B60 8021F6C0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6B64 8021F6C4 0000002D */  daddu     $zero, $zero, $zero
/* 4F6B68 8021F6C8 00000043 */  sra       $zero, $zero, 1
/* 4F6B6C 8021F6CC 00000002 */  srl       $zero, $zero, 0
/* 4F6B70 8021F6D0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F6B74 8021F6D4 00000002 */  srl       $zero, $zero, 0
/* 4F6B78 8021F6D8 00000043 */  sra       $zero, $zero, 1
/* 4F6B7C 8021F6DC 00000002 */  srl       $zero, $zero, 0
/* 4F6B80 8021F6E0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F6B84 8021F6E4 0000003C */  dsll32    $zero, $zero, 0
/* 4F6B88 8021F6E8 00000043 */  sra       $zero, $zero, 1
/* 4F6B8C 8021F6EC 00000003 */  sra       $zero, $zero, 0
/* 4F6B90 8021F6F0 8025385C */  lb        $a1, 0x385c($at)
/* 4F6B94 8021F6F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6B98 8021F6F8 000020E6 */  .byte     0x00, 0x00, 0x20, 0xe6
/* 4F6B9C 8021F6FC 00000043 */  sra       $zero, $zero, 1
/* 4F6BA0 8021F700 00000003 */  sra       $zero, $zero, 0
/* 4F6BA4 8021F704 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F6BA8 8021F708 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6BAC 8021F70C F24A7AE7 */  scd       $t2, 0x7ae7($s2)
/* 4F6BB0 8021F710 00000043 */  sra       $zero, $zero, 1
/* 4F6BB4 8021F714 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6BB8 8021F718 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F6BBC 8021F71C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6BC0 8021F720 00000061 */  .byte     0x00, 0x00, 0x00, 0x61
/* 4F6BC4 8021F724 00000046 */  rotrv     $zero, $zero, $zero
/* 4F6BC8 8021F728 0000000F */  sync      
/* 4F6BCC 8021F72C 00000043 */  sra       $zero, $zero, 1
/* 4F6BD0 8021F730 00000006 */  srlv      $zero, $zero, $zero
/* 4F6BD4 8021F734 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6BD8 8021F738 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6BDC 8021F73C 0000002D */  daddu     $zero, $zero, $zero
/* 4F6BE0 8021F740 00000000 */  nop       
/* 4F6BE4 8021F744 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6BE8 8021F748 00000000 */  nop       
/* 4F6BEC 8021F74C 00000043 */  sra       $zero, $zero, 1
/* 4F6BF0 8021F750 00000003 */  sra       $zero, $zero, 0
/* 4F6BF4 8021F754 8025385C */  lb        $a1, 0x385c($at)
/* 4F6BF8 8021F758 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6BFC 8021F75C 000020BA */  dsrl      $a0, $zero, 2
/* 4F6C00 8021F760 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6C04 8021F764 00000000 */  nop       
/* 4F6C08 8021F768 00000008 */  jr        $zero
/* 4F6C0C 8021F76C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6C10 8021F770 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6C14 8021F774 00000043 */  sra       $zero, $zero, 1
/* 4F6C18 8021F778 00000003 */  sra       $zero, $zero, 0
/* 4F6C1C 8021F77C 8025385C */  lb        $a1, 0x385c($at)
/* 4F6C20 8021F780 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6C24 8021F784 000003B4 */  teq       $zero, $zero, 0xe
/* 4F6C28 8021F788 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F6C2C 8021F78C 00000000 */  nop       
/* 4F6C30 8021F790 00000008 */  jr        $zero
/* 4F6C34 8021F794 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6C38 8021F798 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6C3C 8021F79C 00000043 */  sra       $zero, $zero, 1
/* 4F6C40 8021F7A0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6C44 8021F7A4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F6C48 8021F7A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6C4C 8021F7AC 00000008 */  jr        $zero
/* 4F6C50 8021F7B0 00000000 */   nop      
/* 4F6C54 8021F7B4 00000043 */  sra       $zero, $zero, 1
/* 4F6C58 8021F7B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6C5C 8021F7BC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F6C60 8021F7C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6C64 8021F7C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6C68 8021F7C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6C6C 8021F7CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6C70 8021F7D0 00000043 */  sra       $zero, $zero, 1
/* 4F6C74 8021F7D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6C78 8021F7D8 8026A1EC */  lb        $a2, -0x5e14($at)
/* 4F6C7C 8021F7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6C80 8021F7E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6C84 8021F7E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6C88 8021F7E8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6C8C 8021F7EC 00000043 */  sra       $zero, $zero, 1
/* 4F6C90 8021F7F0 00000002 */  srl       $zero, $zero, 0
/* 4F6C94 8021F7F4 8026D664 */  lb        $a2, -0x299c($at)
/* 4F6C98 8021F7F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6C9C 8021F7FC 00000002 */  srl       $zero, $zero, 0
/* 4F6CA0 8021F800 00000000 */  nop       
/* 4F6CA4 8021F804 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6CA8 8021F808 00000000 */  nop       
/* 4F6CAC 8021F80C 00000043 */  sra       $zero, $zero, 1
/* 4F6CB0 8021F810 00000004 */  sllv      $zero, $zero, $zero
/* 4F6CB4 8021F814 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F6CB8 8021F818 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6CBC 8021F81C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6CC0 8021F820 00680008 */  .byte     0x00, 0x68, 0x00, 0x08
/* 4F6CC4 8021F824 00000043 */  sra       $zero, $zero, 1
/* 4F6CC8 8021F828 00000003 */  sra       $zero, $zero, 0
/* 4F6CCC 8021F82C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F6CD0 8021F830 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6CD4 8021F834 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F6CD8 8021F838 00000043 */  sra       $zero, $zero, 1
/* 4F6CDC 8021F83C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6CE0 8021F840 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F6CE4 8021F844 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6CE8 8021F848 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6CEC 8021F84C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6CF0 8021F850 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6CF4 8021F854 00000043 */  sra       $zero, $zero, 1
/* 4F6CF8 8021F858 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6CFC 8021F85C 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F6D00 8021F860 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D04 8021F864 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6D08 8021F868 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F6D0C 8021F86C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6D10 8021F870 00000043 */  sra       $zero, $zero, 1
/* 4F6D14 8021F874 00000006 */  srlv      $zero, $zero, $zero
/* 4F6D18 8021F878 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F6D1C 8021F87C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D20 8021F880 00000008 */  jr        $zero
/* 4F6D24 8021F884 00000000 */   nop      
/* 4F6D28 8021F888 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6D2C 8021F88C 00000000 */  nop       
/* 4F6D30 8021F890 00000043 */  sra       $zero, $zero, 1
/* 4F6D34 8021F894 00000003 */  sra       $zero, $zero, 0
/* 4F6D38 8021F898 8025385C */  lb        $a1, 0x385c($at)
/* 4F6D3C 8021F89C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D40 8021F8A0 000020BA */  dsrl      $a0, $zero, 2
/* 4F6D44 8021F8A4 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6D48 8021F8A8 00000000 */  nop       
/* 4F6D4C 8021F8AC 00000008 */  jr        $zero
/* 4F6D50 8021F8B0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6D54 8021F8B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6D58 8021F8B8 00000043 */  sra       $zero, $zero, 1
/* 4F6D5C 8021F8BC 00000003 */  sra       $zero, $zero, 0
/* 4F6D60 8021F8C0 8025385C */  lb        $a1, 0x385c($at)
/* 4F6D64 8021F8C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D68 8021F8C8 000003B4 */  teq       $zero, $zero, 0xe
/* 4F6D6C 8021F8CC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F6D70 8021F8D0 00000000 */  nop       
/* 4F6D74 8021F8D4 00000043 */  sra       $zero, $zero, 1
/* 4F6D78 8021F8D8 00000004 */  sllv      $zero, $zero, $zero
/* 4F6D7C 8021F8DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F6D80 8021F8E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D84 8021F8E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6D88 8021F8E8 00680001 */  movf      $zero, $v1, $fcc2
/* 4F6D8C 8021F8EC 00000043 */  sra       $zero, $zero, 1
/* 4F6D90 8021F8F0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6D94 8021F8F4 8027CB7C */  lb        $a3, -0x3484($at)
/* 4F6D98 8021F8F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6D9C 8021F8FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6DA0 8021F900 8021B960 */  lb        $at, -0x46a0($at)
/* 4F6DA4 8021F904 00000008 */  jr        $zero
/* 4F6DA8 8021F908 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6DAC 8021F90C 0000000A */  movz      $zero, $zero, $zero
/* 4F6DB0 8021F910 00000043 */  sra       $zero, $zero, 1
/* 4F6DB4 8021F914 00000004 */  sllv      $zero, $zero, $zero
/* 4F6DB8 8021F918 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F6DBC 8021F91C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6DC0 8021F920 00000004 */  sllv      $zero, $zero, $zero
/* 4F6DC4 8021F924 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6DC8 8021F928 0000000A */  movz      $zero, $zero, $zero
/* 4F6DCC 8021F92C 00000002 */  srl       $zero, $zero, 0
/* 4F6DD0 8021F930 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6DD4 8021F934 00000000 */  nop       
/* 4F6DD8 8021F938 00000043 */  sra       $zero, $zero, 1
/* 4F6DDC 8021F93C 00000002 */  srl       $zero, $zero, 0
/* 4F6DE0 8021F940 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F6DE4 8021F944 0000000D */  break     
/* 4F6DE8 8021F948 00000043 */   sra      $zero, $zero, 1
/* 4F6DEC 8021F94C 00000002 */  srl       $zero, $zero, 0
/* 4F6DF0 8021F950 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F6DF4 8021F954 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6DF8 8021F958 00000043 */  sra       $zero, $zero, 1
/* 4F6DFC 8021F95C 00000002 */  srl       $zero, $zero, 0
/* 4F6E00 8021F960 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F6E04 8021F964 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6E08 8021F968 00000008 */  jr        $zero
/* 4F6E0C 8021F96C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6E10 8021F970 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6E14 8021F974 00000043 */  sra       $zero, $zero, 1
/* 4F6E18 8021F978 00000006 */  srlv      $zero, $zero, $zero
/* 4F6E1C 8021F97C 80252F30 */  lb        $a1, 0x2f30($at)
/* 4F6E20 8021F980 000D00E4 */  .byte     0x00, 0x0d, 0x00, 0xe4
/* 4F6E24 8021F984 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6E28 8021F988 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6E2C 8021F98C 0068000B */  movn      $zero, $v1, $t0
/* 4F6E30 8021F990 00680001 */  movf      $zero, $v1, $fcc2
/* 4F6E34 8021F994 00000043 */  sra       $zero, $zero, 1
/* 4F6E38 8021F998 00000004 */  sllv      $zero, $zero, $zero
/* 4F6E3C 8021F99C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F6E40 8021F9A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6E44 8021F9A4 00000004 */  sllv      $zero, $zero, $zero
/* 4F6E48 8021F9A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6E4C 8021F9AC 00000013 */  mtlo      $zero
/* 4F6E50 8021F9B0 00000000 */  nop       
/* 4F6E54 8021F9B4 00000002 */  srl       $zero, $zero, 0
/* 4F6E58 8021F9B8 00000000 */  nop       
/* 4F6E5C 8021F9BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6E60 8021F9C0 00000000 */  nop       
/* 4F6E64 8021F9C4 00000043 */  sra       $zero, $zero, 1
/* 4F6E68 8021F9C8 00000002 */  srl       $zero, $zero, 0
/* 4F6E6C 8021F9CC 80269E28 */  lb        $a2, -0x61d8($at)
/* 4F6E70 8021F9D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6E74 8021F9D4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6E78 8021F9D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6E7C 8021F9DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6E80 8021F9E0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F6E84 8021F9E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6E88 8021F9E8 0000000A */  movz      $zero, $zero, $zero
/* 4F6E8C 8021F9EC 00000043 */  sra       $zero, $zero, 1
/* 4F6E90 8021F9F0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6E94 8021F9F4 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F6E98 8021F9F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6E9C 8021F9FC 0000000A */  movz      $zero, $zero, $zero
/* 4F6EA0 8021FA00 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6EA4 8021FA04 00000014 */  dsllv     $zero, $zero, $zero
/* 4F6EA8 8021FA08 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6EAC 8021FA0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F6EB0 8021FA10 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F6EB4 8021FA14 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6EB8 8021FA18 00000000 */  nop       
/* 4F6EBC 8021FA1C 00000043 */  sra       $zero, $zero, 1
/* 4F6EC0 8021FA20 00000004 */  sllv      $zero, $zero, $zero
/* 4F6EC4 8021FA24 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F6EC8 8021FA28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F6ECC 8021FA2C 0000000A */  movz      $zero, $zero, $zero
/* 4F6ED0 8021FA30 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6ED4 8021FA34 00000023 */  negu      $zero, $zero
/* 4F6ED8 8021FA38 00000000 */  nop       
/* 4F6EDC 8021FA3C 00000023 */  negu      $zero, $zero
/* 4F6EE0 8021FA40 00000000 */  nop       
/* 4F6EE4 8021FA44 00000002 */  srl       $zero, $zero, 0
/* 4F6EE8 8021FA48 00000000 */  nop       
/* 4F6EEC 8021FA4C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6EF0 8021FA50 00000000 */  nop       
/* 4F6EF4 8021FA54 00000043 */  sra       $zero, $zero, 1
/* 4F6EF8 8021FA58 00000003 */  sra       $zero, $zero, 0
/* 4F6EFC 8021FA5C 8026DE5C */  lb        $a2, -0x21a4($at)
/* 4F6F00 8021FA60 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F04 8021FA64 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6F08 8021FA68 0000000B */  movn      $zero, $zero, $zero
/* 4F6F0C 8021FA6C 00000002 */  srl       $zero, $zero, 0
/* 4F6F10 8021FA70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6F14 8021FA74 00000000 */  nop       
/* 4F6F18 8021FA78 00000043 */  sra       $zero, $zero, 1
/* 4F6F1C 8021FA7C 00000003 */  sra       $zero, $zero, 0
/* 4F6F20 8021FA80 8027C6A0 */  lb        $a3, -0x3960($at)
/* 4F6F24 8021FA84 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F28 8021FA88 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6F2C 8021FA8C 0000000B */  movn      $zero, $zero, $zero
/* 4F6F30 8021FA90 00000002 */  srl       $zero, $zero, 0
/* 4F6F34 8021FA94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6F38 8021FA98 00000000 */  nop       
/* 4F6F3C 8021FA9C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F6F40 8021FAA0 00000000 */  nop       
/* 4F6F44 8021FAA4 00000043 */  sra       $zero, $zero, 1
/* 4F6F48 8021FAA8 00000002 */  srl       $zero, $zero, 0
/* 4F6F4C 8021FAAC 8027D32C */  lb        $a3, -0x2cd4($at)
/* 4F6F50 8021FAB0 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F54 8021FAB4 00000043 */  sra       $zero, $zero, 1
/* 4F6F58 8021FAB8 00000003 */  sra       $zero, $zero, 0
/* 4F6F5C 8021FABC 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F6F60 8021FAC0 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F64 8021FAC4 00000000 */  nop       
/* 4F6F68 8021FAC8 00000043 */  sra       $zero, $zero, 1
/* 4F6F6C 8021FACC 00000003 */  sra       $zero, $zero, 0
/* 4F6F70 8021FAD0 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F6F74 8021FAD4 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F78 8021FAD8 00000000 */  nop       
/* 4F6F7C 8021FADC 00000043 */  sra       $zero, $zero, 1
/* 4F6F80 8021FAE0 00000004 */  sllv      $zero, $zero, $zero
/* 4F6F84 8021FAE4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F6F88 8021FAE8 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6F8C 8021FAEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6F90 8021FAF0 00690006 */  srlv      $zero, $t1, $v1
/* 4F6F94 8021FAF4 00000008 */  jr        $zero
/* 4F6F98 8021FAF8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6F9C 8021FAFC 0000000A */  movz      $zero, $zero, $zero
/* 4F6FA0 8021FB00 00000024 */  and       $zero, $zero, $zero
/* 4F6FA4 8021FB04 00000002 */  srl       $zero, $zero, 0
/* 4F6FA8 8021FB08 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6FAC 8021FB0C 00000000 */  nop       
/* 4F6FB0 8021FB10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F6FB4 8021FB14 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6FB8 8021FB18 00000018 */  mult      $zero, $zero
/* 4F6FBC 8021FB1C 00000043 */  sra       $zero, $zero, 1
/* 4F6FC0 8021FB20 00000003 */  sra       $zero, $zero, 0
/* 4F6FC4 8021FB24 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F6FC8 8021FB28 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F6FCC 8021FB2C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6FD0 8021FB30 00000027 */  not       $zero, $zero
/* 4F6FD4 8021FB34 00000002 */  srl       $zero, $zero, 0
/* 4F6FD8 8021FB38 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F6FDC 8021FB3C 0000001E */  ddiv      $zero, $zero, $zero
/* 4F6FE0 8021FB40 00000008 */  jr        $zero
/* 4F6FE4 8021FB44 00000001 */   movf     $zero, $zero, $fcc0
/* 4F6FE8 8021FB48 00000001 */  movf      $zero, $zero, $fcc0
/* 4F6FEC 8021FB4C 00000006 */  srlv      $zero, $zero, $zero
/* 4F6FF0 8021FB50 00000000 */  nop       
/* 4F6FF4 8021FB54 00000043 */  sra       $zero, $zero, 1
/* 4F6FF8 8021FB58 00000003 */  sra       $zero, $zero, 0
/* 4F6FFC 8021FB5C 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F7000 8021FB60 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F7004 8021FB64 00000000 */  nop       
/* 4F7008 8021FB68 00000043 */  sra       $zero, $zero, 1
/* 4F700C 8021FB6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7010 8021FB70 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F7014 8021FB74 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F7018 8021FB78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F701C 8021FB7C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F7020 8021FB80 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F7024 8021FB84 00000027 */  not       $zero, $zero
/* 4F7028 8021FB88 00000002 */  srl       $zero, $zero, 0
/* 4F702C 8021FB8C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F7030 8021FB90 0000000A */  movz      $zero, $zero, $zero
/* 4F7034 8021FB94 00000043 */  sra       $zero, $zero, 1
/* 4F7038 8021FB98 0000000F */  sync      
/* 4F703C 8021FB9C 802D829C */  lb        $t5, -0x7d64($at)
/* 4F7040 8021FBA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7044 8021FBA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F7048 8021FBA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F704C 8021FBAC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F7050 8021FBB0 00000000 */  nop       
/* 4F7054 8021FBB4 00000000 */  nop       
/* 4F7058 8021FBB8 00000000 */  nop       
/* 4F705C 8021FBBC 00000000 */  nop       
/* 4F7060 8021FBC0 00000000 */  nop       
/* 4F7064 8021FBC4 00000000 */  nop       
/* 4F7068 8021FBC8 00000000 */  nop       
/* 4F706C 8021FBCC 00000000 */  nop       
/* 4F7070 8021FBD0 00000000 */  nop       
/* 4F7074 8021FBD4 00000000 */  nop       
/* 4F7078 8021FBD8 00000043 */  sra       $zero, $zero, 1
/* 4F707C 8021FBDC 00000003 */  sra       $zero, $zero, 0
/* 4F7080 8021FBE0 8025385C */  lb        $a1, 0x385c($at)
/* 4F7084 8021FBE4 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F7088 8021FBE8 000003E5 */  .byte     0x00, 0x00, 0x03, 0xe5
/* 4F708C 8021FBEC 00000024 */  and       $zero, $zero, $zero
/* 4F7090 8021FBF0 00000002 */  srl       $zero, $zero, 0
/* 4F7094 8021FBF4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F7098 8021FBF8 00000000 */  nop       
/* 4F709C 8021FBFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F70A0 8021FC00 00000001 */  movf      $zero, $zero, $fcc0
/* 4F70A4 8021FC04 0000000C */  syscall   
/* 4F70A8 8021FC08 00000043 */  sra       $zero, $zero, 1
/* 4F70AC 8021FC0C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F70B0 8021FC10 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F70B4 8021FC14 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F70B8 8021FC18 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F70BC 8021FC1C 00000000 */  nop       
/* 4F70C0 8021FC20 00000000 */  nop       
/* 4F70C4 8021FC24 00000027 */  not       $zero, $zero
/* 4F70C8 8021FC28 00000002 */  srl       $zero, $zero, 0
/* 4F70CC 8021FC2C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F70D0 8021FC30 00000008 */  jr        $zero
/* 4F70D4 8021FC34 00000008 */   jr       $zero
/* 4F70D8 8021FC38 00000001 */   movf     $zero, $zero, $fcc0
/* 4F70DC 8021FC3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F70E0 8021FC40 00000006 */  srlv      $zero, $zero, $zero
/* 4F70E4 8021FC44 00000000 */  nop       
/* 4F70E8 8021FC48 00000043 */  sra       $zero, $zero, 1
/* 4F70EC 8021FC4C 00000002 */  srl       $zero, $zero, 0
/* 4F70F0 8021FC50 8027C7B0 */  lb        $a3, -0x3850($at)
/* 4F70F4 8021FC54 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F70F8 8021FC58 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F70FC 8021FC5C 00000000 */  nop       
/* 4F7100 8021FC60 00000013 */  mtlo      $zero
/* 4F7104 8021FC64 00000000 */  nop       
/* 4F7108 8021FC68 00000013 */  mtlo      $zero
/* 4F710C 8021FC6C 00000000 */  nop       
/* 4F7110 8021FC70 00000046 */  rotrv     $zero, $zero, $zero
/* 4F7114 8021FC74 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7118 8021FC78 8029AF08 */  lb        $t1, -0x50f8($at)
/* 4F711C 8021FC7C 00000003 */  sra       $zero, $zero, 0
/* 4F7120 8021FC80 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7124 8021FC84 00000000 */  nop       
/* 4F7128 8021FC88 00000043 */  sra       $zero, $zero, 1
/* 4F712C 8021FC8C 00000003 */  sra       $zero, $zero, 0
/* 4F7130 8021FC90 8026DE5C */  lb        $a2, -0x21a4($at)
/* 4F7134 8021FC94 00000201 */  .byte     0x00, 0x00, 0x02, 0x01
/* 4F7138 8021FC98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F713C 8021FC9C 0000000B */  movn      $zero, $zero, $zero
/* 4F7140 8021FCA0 00000002 */  srl       $zero, $zero, 0
/* 4F7144 8021FCA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F7148 8021FCA8 00000000 */  nop       
/* 4F714C 8021FCAC 00000008 */  jr        $zero
/* 4F7150 8021FCB0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F7154 8021FCB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7158 8021FCB8 00000004 */  sllv      $zero, $zero, $zero
/* 4F715C 8021FCBC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7160 8021FCC0 00000000 */  nop       
/* 4F7164 8021FCC4 00000013 */  mtlo      $zero
/* 4F7168 8021FCC8 00000000 */  nop       
/* 4F716C 8021FCCC 00000043 */  sra       $zero, $zero, 1
/* 4F7170 8021FCD0 00000002 */  srl       $zero, $zero, 0
/* 4F7174 8021FCD4 8027C7B0 */  lb        $a3, -0x3850($at)
/* 4F7178 8021FCD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F717C 8021FCDC 00000002 */  srl       $zero, $zero, 0
/* 4F7180 8021FCE0 00000000 */  nop       
/* 4F7184 8021FCE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7188 8021FCE8 00000000 */  nop       
/* 4F718C 8021FCEC 00000000 */  nop       
/* 4F7190 8021FCF0 00000043 */  sra       $zero, $zero, 1
/* 4F7194 8021FCF4 00000002 */  srl       $zero, $zero, 0
/* 4F7198 8021FCF8 802D9700 */  lb        $t5, -0x6900($at)
/* 4F719C 8021FCFC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F71A0 8021FD00 00000043 */  sra       $zero, $zero, 1
/* 4F71A4 8021FD04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F71A8 8021FD08 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F71AC 8021FD0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F71B0 8021FD10 00000000 */  nop       
/* 4F71B4 8021FD14 00000000 */  nop       
/* 4F71B8 8021FD18 00000000 */  nop       
/* 4F71BC 8021FD1C 00000002 */  srl       $zero, $zero, 0
/* 4F71C0 8021FD20 00000000 */  nop       
/* 4F71C4 8021FD24 00000001 */  movf      $zero, $zero, $fcc0
/* 4F71C8 8021FD28 00000000 */  nop       
/* 4F71CC 8021FD2C 00000002 */  srl       $zero, $zero, 0
/* 4F71D0 8021FD30 00000000 */  nop       
/* 4F71D4 8021FD34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F71D8 8021FD38 00000000 */  nop       
/* 4F71DC 8021FD3C 80220500 */  lb        $v0, 0x500($at)
/* 4F71E0 8021FD40 802204F0 */  lb        $v0, 0x4f0($at)
/* 4F71E4 8021FD44 00000000 */  nop       
/* 4F71E8 8021FD48 8021FCF0 */  lb        $at, -0x310($at)
/* 4F71EC 8021FD4C 8021FD2C */  lb        $at, -0x2d4($at)
/* 4F71F0 8021FD50 00000000 */  nop       
/* 4F71F4 8021FD54 00000000 */  nop       
/* 4F71F8 8021FD58 00000000 */  nop       
/* 4F71FC 8021FD5C 00000000 */  nop       
/* 4F7200 8021FD60 00000000 */  nop       
/* 4F7204 8021FD64 00000000 */  nop       
/* 4F7208 8021FD68 00000000 */  nop       
/* 4F720C 8021FD6C 00000000 */  nop       
/* 4F7210 8021FD70 00000043 */  sra       $zero, $zero, 1
/* 4F7214 8021FD74 00000002 */  srl       $zero, $zero, 0
/* 4F7218 8021FD78 802D9700 */  lb        $t5, -0x6900($at)
/* 4F721C 8021FD7C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7220 8021FD80 00000043 */  sra       $zero, $zero, 1
/* 4F7224 8021FD84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7228 8021FD88 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F722C 8021FD8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7230 8021FD90 00000000 */  nop       
/* 4F7234 8021FD94 00000000 */  nop       
/* 4F7238 8021FD98 00000000 */  nop       
/* 4F723C 8021FD9C 00000002 */  srl       $zero, $zero, 0
/* 4F7240 8021FDA0 00000000 */  nop       
/* 4F7244 8021FDA4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7248 8021FDA8 00000000 */  nop       
/* 4F724C 8021FDAC 00000002 */  srl       $zero, $zero, 0
/* 4F7250 8021FDB0 00000000 */  nop       
/* 4F7254 8021FDB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7258 8021FDB8 00000000 */  nop       
/* 4F725C 8021FDBC 80220528 */  lb        $v0, 0x528($at)
/* 4F7260 8021FDC0 80220518 */  lb        $v0, 0x518($at)
/* 4F7264 8021FDC4 80220508 */  lb        $v0, 0x508($at)
/* 4F7268 8021FDC8 8021FD70 */  lb        $at, -0x290($at)
/* 4F726C 8021FDCC 8021FDAC */  lb        $at, -0x254($at)
/* 4F7270 8021FDD0 00000000 */  nop       
/* 4F7274 8021FDD4 00000000 */  nop       
/* 4F7278 8021FDD8 00000000 */  nop       
/* 4F727C 8021FDDC 00000000 */  nop       
/* 4F7280 8021FDE0 00000000 */  nop       
/* 4F7284 8021FDE4 00000000 */  nop       
/* 4F7288 8021FDE8 00000000 */  nop       
/* 4F728C 8021FDEC 00000000 */  nop       
/* 4F7290 8021FDF0 00000043 */  sra       $zero, $zero, 1
/* 4F7294 8021FDF4 00000002 */  srl       $zero, $zero, 0
/* 4F7298 8021FDF8 802D9700 */  lb        $t5, -0x6900($at)
/* 4F729C 8021FDFC 000C0000 */  sll       $zero, $t4, 0
/* 4F72A0 8021FE00 00000043 */  sra       $zero, $zero, 1
/* 4F72A4 8021FE04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F72A8 8021FE08 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F72AC 8021FE0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F72B0 8021FE10 00000000 */  nop       
/* 4F72B4 8021FE14 00000000 */  nop       
/* 4F72B8 8021FE18 00000000 */  nop       
/* 4F72BC 8021FE1C 00000002 */  srl       $zero, $zero, 0
/* 4F72C0 8021FE20 00000000 */  nop       
/* 4F72C4 8021FE24 00000001 */  movf      $zero, $zero, $fcc0
/* 4F72C8 8021FE28 00000000 */  nop       
/* 4F72CC 8021FE2C 00000002 */  srl       $zero, $zero, 0
/* 4F72D0 8021FE30 00000000 */  nop       
/* 4F72D4 8021FE34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F72D8 8021FE38 00000000 */  nop       
/* 4F72DC 8021FE3C 0000001F */  ddivu     $zero, $zero, $zero
/* 4F72E0 8021FE40 0000001E */  ddiv      $zero, $zero, $zero
/* 4F72E4 8021FE44 00000021 */  addu      $zero, $zero, $zero
/* 4F72E8 8021FE48 00000000 */  nop       
/* 4F72EC 8021FE4C 80220550 */  lb        $v0, 0x550($at)
/* 4F72F0 8021FE50 80220540 */  lb        $v0, 0x540($at)
/* 4F72F4 8021FE54 80220530 */  lb        $v0, 0x530($at)
/* 4F72F8 8021FE58 8021FDF0 */  lb        $at, -0x210($at)
/* 4F72FC 8021FE5C 8021FE2C */  lb        $at, -0x1d4($at)
/* 4F7300 8021FE60 00000000 */  nop       
/* 4F7304 8021FE64 8021FE3C */  lb        $at, -0x1c4($at)
/* 4F7308 8021FE68 00000000 */  nop       
/* 4F730C 8021FE6C 00000000 */  nop       
/* 4F7310 8021FE70 00000000 */  nop       
/* 4F7314 8021FE74 00000000 */  nop       
/* 4F7318 8021FE78 00000000 */  nop       
/* 4F731C 8021FE7C 00000000 */  nop       
/* 4F7320 8021FE80 00000043 */  sra       $zero, $zero, 1
/* 4F7324 8021FE84 00000002 */  srl       $zero, $zero, 0
/* 4F7328 8021FE88 802D9700 */  lb        $t5, -0x6900($at)
/* 4F732C 8021FE8C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7330 8021FE90 00000043 */  sra       $zero, $zero, 1
/* 4F7334 8021FE94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7338 8021FE98 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F733C 8021FE9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7340 8021FEA0 00000000 */  nop       
/* 4F7344 8021FEA4 00000000 */  nop       
/* 4F7348 8021FEA8 00000000 */  nop       
/* 4F734C 8021FEAC 00000043 */  sra       $zero, $zero, 1
/* 4F7350 8021FEB0 00000003 */  sra       $zero, $zero, 0
/* 4F7354 8021FEB4 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F7358 8021FEB8 00000007 */  srav      $zero, $zero, $zero
/* 4F735C 8021FEBC 00000000 */  nop       
/* 4F7360 8021FEC0 00000043 */  sra       $zero, $zero, 1
/* 4F7364 8021FEC4 00000003 */  sra       $zero, $zero, 0
/* 4F7368 8021FEC8 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F736C 8021FECC 00000008 */  jr        $zero
/* 4F7370 8021FED0 00000000 */   nop      
/* 4F7374 8021FED4 00000043 */  sra       $zero, $zero, 1
/* 4F7378 8021FED8 00000003 */  sra       $zero, $zero, 0
/* 4F737C 8021FEDC 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F7380 8021FEE0 00000009 */  jr        $zero
/* 4F7384 8021FEE4 00000000 */   nop      
/* 4F7388 8021FEE8 00000043 */  sra       $zero, $zero, 1
/* 4F738C 8021FEEC 00000003 */  sra       $zero, $zero, 0
/* 4F7390 8021FEF0 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F7394 8021FEF4 0000000F */  sync      
/* 4F7398 8021FEF8 00000000 */  nop       
/* 4F739C 8021FEFC 00000043 */  sra       $zero, $zero, 1
/* 4F73A0 8021FF00 00000003 */  sra       $zero, $zero, 0
/* 4F73A4 8021FF04 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F73A8 8021FF08 00000010 */  mfhi      $zero
/* 4F73AC 8021FF0C 00000000 */  nop       
/* 4F73B0 8021FF10 00000043 */  sra       $zero, $zero, 1
/* 4F73B4 8021FF14 00000003 */  sra       $zero, $zero, 0
/* 4F73B8 8021FF18 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F73BC 8021FF1C 00000011 */  mthi      $zero
/* 4F73C0 8021FF20 00000000 */  nop       
/* 4F73C4 8021FF24 00000002 */  srl       $zero, $zero, 0
/* 4F73C8 8021FF28 00000000 */  nop       
/* 4F73CC 8021FF2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F73D0 8021FF30 00000000 */  nop       
/* 4F73D4 8021FF34 00000002 */  srl       $zero, $zero, 0
/* 4F73D8 8021FF38 00000000 */  nop       
/* 4F73DC 8021FF3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F73E0 8021FF40 00000000 */  nop       
/* 4F73E4 8021FF44 0000001F */  ddivu     $zero, $zero, $zero
/* 4F73E8 8021FF48 0000001E */  ddiv      $zero, $zero, $zero
/* 4F73EC 8021FF4C 00000021 */  addu      $zero, $zero, $zero
/* 4F73F0 8021FF50 00000000 */  nop       
/* 4F73F4 8021FF54 80220578 */  lb        $v0, 0x578($at)
/* 4F73F8 8021FF58 80220568 */  lb        $v0, 0x568($at)
/* 4F73FC 8021FF5C 80220558 */  lb        $v0, 0x558($at)
/* 4F7400 8021FF60 8021FE80 */  lb        $at, -0x180($at)
/* 4F7404 8021FF64 8021FF34 */  lb        $at, -0xcc($at)
/* 4F7408 8021FF68 00000000 */  nop       
/* 4F740C 8021FF6C 8021FF44 */  lb        $at, -0xbc($at)
/* 4F7410 8021FF70 00000000 */  nop       
/* 4F7414 8021FF74 00000000 */  nop       
/* 4F7418 8021FF78 00000000 */  nop       
/* 4F741C 8021FF7C 00000000 */  nop       
/* 4F7420 8021FF80 00000043 */  sra       $zero, $zero, 1
/* 4F7424 8021FF84 00000002 */  srl       $zero, $zero, 0
/* 4F7428 8021FF88 802D9700 */  lb        $t5, -0x6900($at)
/* 4F742C 8021FF8C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7430 8021FF90 00000043 */  sra       $zero, $zero, 1
/* 4F7434 8021FF94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7438 8021FF98 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F743C 8021FF9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7440 8021FFA0 00000000 */  nop       
/* 4F7444 8021FFA4 00000000 */  nop       
/* 4F7448 8021FFA8 00000000 */  nop       
/* 4F744C 8021FFAC 00000043 */  sra       $zero, $zero, 1
/* 4F7450 8021FFB0 00000003 */  sra       $zero, $zero, 0
/* 4F7454 8021FFB4 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F7458 8021FFB8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F745C 8021FFBC 00000000 */  nop       
/* 4F7460 8021FFC0 00000043 */  sra       $zero, $zero, 1
/* 4F7464 8021FFC4 00000003 */  sra       $zero, $zero, 0
/* 4F7468 8021FFC8 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F746C 8021FFCC 0000000B */  movn      $zero, $zero, $zero
/* 4F7470 8021FFD0 00000000 */  nop       
/* 4F7474 8021FFD4 00000002 */  srl       $zero, $zero, 0
/* 4F7478 8021FFD8 00000000 */  nop       
/* 4F747C 8021FFDC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7480 8021FFE0 00000000 */  nop       
/* 4F7484 8021FFE4 00000002 */  srl       $zero, $zero, 0
/* 4F7488 8021FFE8 00000000 */  nop       
/* 4F748C 8021FFEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7490 8021FFF0 00000000 */  nop       
/* 4F7494 8021FFF4 0000001F */  ddivu     $zero, $zero, $zero
/* 4F7498 8021FFF8 0000001E */  ddiv      $zero, $zero, $zero
/* 4F749C 8021FFFC 00000021 */  addu      $zero, $zero, $zero
/* 4F74A0 80220000 00000000 */  nop       
/* 4F74A4 80220004 802205A0 */  lb        $v0, 0x5a0($at)
/* 4F74A8 80220008 80220590 */  lb        $v0, 0x590($at)
/* 4F74AC 8022000C 80220580 */  lb        $v0, 0x580($at)
/* 4F74B0 80220010 8021FF80 */  lb        $at, -0x80($at)
/* 4F74B4 80220014 8021FFE4 */  lb        $at, -0x1c($at)
/* 4F74B8 80220018 00000000 */  nop       
/* 4F74BC 8022001C 8021FFF4 */  lb        $at, -0xc($at)
/* 4F74C0 80220020 00000000 */  nop       
/* 4F74C4 80220024 00000000 */  nop       
/* 4F74C8 80220028 00000000 */  nop       
/* 4F74CC 8022002C 00000000 */  nop       
/* 4F74D0 80220030 00000043 */  sra       $zero, $zero, 1
/* 4F74D4 80220034 00000002 */  srl       $zero, $zero, 0
/* 4F74D8 80220038 802D9700 */  lb        $t5, -0x6900($at)
/* 4F74DC 8022003C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F74E0 80220040 00000043 */  sra       $zero, $zero, 1
/* 4F74E4 80220044 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F74E8 80220048 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F74EC 8022004C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F74F0 80220050 00000000 */  nop       
/* 4F74F4 80220054 00000000 */  nop       
/* 4F74F8 80220058 00000000 */  nop       
/* 4F74FC 8022005C 00000002 */  srl       $zero, $zero, 0
/* 4F7500 80220060 00000000 */  nop       
/* 4F7504 80220064 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7508 80220068 00000000 */  nop       
/* 4F750C 8022006C 00000002 */  srl       $zero, $zero, 0
/* 4F7510 80220070 00000000 */  nop       
/* 4F7514 80220074 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7518 80220078 00000000 */  nop       
/* 4F751C 8022007C 802205D0 */  lb        $v0, 0x5d0($at)
/* 4F7520 80220080 802205C0 */  lb        $v0, 0x5c0($at)
/* 4F7524 80220084 802205B0 */  lb        $v0, 0x5b0($at)
/* 4F7528 80220088 80220030 */  lb        $v0, 0x30($at)
/* 4F752C 8022008C 8022006C */  lb        $v0, 0x6c($at)
/* 4F7530 80220090 802205A8 */  lb        $v0, 0x5a8($at)
/* 4F7534 80220094 00000000 */  nop       
/* 4F7538 80220098 00000000 */  nop       
/* 4F753C 8022009C 00000000 */  nop       
/* 4F7540 802200A0 00000000 */  nop       
/* 4F7544 802200A4 00000000 */  nop       
/* 4F7548 802200A8 00000000 */  nop       
/* 4F754C 802200AC 00000000 */  nop       
/* 4F7550 802200B0 00000043 */  sra       $zero, $zero, 1
/* 4F7554 802200B4 00000002 */  srl       $zero, $zero, 0
/* 4F7558 802200B8 802D9700 */  lb        $t5, -0x6900($at)
/* 4F755C 802200BC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7560 802200C0 00000043 */  sra       $zero, $zero, 1
/* 4F7564 802200C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7568 802200C8 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F756C 802200CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7570 802200D0 00000000 */  nop       
/* 4F7574 802200D4 00000000 */  nop       
/* 4F7578 802200D8 00000000 */  nop       
/* 4F757C 802200DC 00000002 */  srl       $zero, $zero, 0
/* 4F7580 802200E0 00000000 */  nop       
/* 4F7584 802200E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7588 802200E8 00000000 */  nop       
/* 4F758C 802200EC 00000002 */  srl       $zero, $zero, 0
/* 4F7590 802200F0 00000000 */  nop       
/* 4F7594 802200F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7598 802200F8 00000000 */  nop       
/* 4F759C 802200FC 802205F8 */  lb        $v0, 0x5f8($at)
/* 4F75A0 80220100 802205E8 */  lb        $v0, 0x5e8($at)
/* 4F75A4 80220104 802205D8 */  lb        $v0, 0x5d8($at)
/* 4F75A8 80220108 802200B0 */  lb        $v0, 0xb0($at)
/* 4F75AC 8022010C 802200EC */  lb        $v0, 0xec($at)
/* 4F75B0 80220110 00000000 */  nop       
/* 4F75B4 80220114 00000000 */  nop       
/* 4F75B8 80220118 00000000 */  nop       
/* 4F75BC 8022011C 00000000 */  nop       
/* 4F75C0 80220120 00000000 */  nop       
/* 4F75C4 80220124 00000000 */  nop       
/* 4F75C8 80220128 00000000 */  nop       
/* 4F75CC 8022012C 00000000 */  nop       
/* 4F75D0 80220130 00000043 */  sra       $zero, $zero, 1
/* 4F75D4 80220134 00000002 */  srl       $zero, $zero, 0
/* 4F75D8 80220138 802D9700 */  lb        $t5, -0x6900($at)
/* 4F75DC 8022013C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F75E0 80220140 00000043 */  sra       $zero, $zero, 1
/* 4F75E4 80220144 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F75E8 80220148 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F75EC 8022014C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F75F0 80220150 00000000 */  nop       
/* 4F75F4 80220154 00000000 */  nop       
/* 4F75F8 80220158 00000000 */  nop       
/* 4F75FC 8022015C 00000043 */  sra       $zero, $zero, 1
/* 4F7600 80220160 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7604 80220164 80218850 */  lb        $at, -0x77b0($at)
/* 4F7608 80220168 00000002 */  srl       $zero, $zero, 0
/* 4F760C 8022016C 00000000 */  nop       
/* 4F7610 80220170 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7614 80220174 00000000 */  nop       
/* 4F7618 80220178 00000043 */  sra       $zero, $zero, 1
/* 4F761C 8022017C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7620 80220180 802188E4 */  lb        $at, -0x771c($at)
/* 4F7624 80220184 00000002 */  srl       $zero, $zero, 0
/* 4F7628 80220188 00000000 */  nop       
/* 4F762C 8022018C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7630 80220190 00000000 */  nop       
/* 4F7634 80220194 00000033 */  tltu      $zero, $zero
/* 4F7638 80220198 00000034 */  teq       $zero, $zero
/* 4F763C 8022019C 00000000 */  nop       
/* 4F7640 802201A0 80220620 */  lb        $v0, 0x620($at)
/* 4F7644 802201A4 80220610 */  lb        $v0, 0x610($at)
/* 4F7648 802201A8 80220600 */  lb        $v0, 0x600($at)
/* 4F764C 802201AC 80220130 */  lb        $v0, 0x130($at)
/* 4F7650 802201B0 80220178 */  lb        $v0, 0x178($at)
/* 4F7654 802201B4 00000000 */  nop       
/* 4F7658 802201B8 80220194 */  lb        $v0, 0x194($at)
/* 4F765C 802201BC 00000000 */  nop       
/* 4F7660 802201C0 00000000 */  nop       
/* 4F7664 802201C4 00000000 */  nop       
/* 4F7668 802201C8 00000000 */  nop       
/* 4F766C 802201CC 00000000 */  nop       
/* 4F7670 802201D0 00000043 */  sra       $zero, $zero, 1
/* 4F7674 802201D4 00000002 */  srl       $zero, $zero, 0
/* 4F7678 802201D8 802D9700 */  lb        $t5, -0x6900($at)
/* 4F767C 802201DC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7680 802201E0 00000043 */  sra       $zero, $zero, 1
/* 4F7684 802201E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7688 802201E8 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F768C 802201EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7690 802201F0 00000000 */  nop       
/* 4F7694 802201F4 00000000 */  nop       
/* 4F7698 802201F8 00000000 */  nop       
/* 4F769C 802201FC 00000043 */  sra       $zero, $zero, 1
/* 4F76A0 80220200 00000001 */  movf      $zero, $zero, $fcc0
/* 4F76A4 80220204 80218920 */  lb        $at, -0x76e0($at)
/* 4F76A8 80220208 00000002 */  srl       $zero, $zero, 0
/* 4F76AC 8022020C 00000000 */  nop       
/* 4F76B0 80220210 00000001 */  movf      $zero, $zero, $fcc0
/* 4F76B4 80220214 00000000 */  nop       
/* 4F76B8 80220218 00000043 */  sra       $zero, $zero, 1
/* 4F76BC 8022021C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F76C0 80220220 802189B0 */  lb        $at, -0x7650($at)
/* 4F76C4 80220224 00000002 */  srl       $zero, $zero, 0
/* 4F76C8 80220228 00000000 */  nop       
/* 4F76CC 8022022C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F76D0 80220230 00000000 */  nop       
/* 4F76D4 80220234 80220648 */  lb        $v0, 0x648($at)
/* 4F76D8 80220238 80220638 */  lb        $v0, 0x638($at)
/* 4F76DC 8022023C 80220628 */  lb        $v0, 0x628($at)
/* 4F76E0 80220240 802201D0 */  lb        $v0, 0x1d0($at)
/* 4F76E4 80220244 80220218 */  lb        $v0, 0x218($at)
/* 4F76E8 80220248 00000000 */  nop       
/* 4F76EC 8022024C 00000000 */  nop       
/* 4F76F0 80220250 00000000 */  nop       
/* 4F76F4 80220254 00000000 */  nop       
/* 4F76F8 80220258 00000000 */  nop       
/* 4F76FC 8022025C 00000000 */  nop       
/* 4F7700 80220260 00000043 */  sra       $zero, $zero, 1
/* 4F7704 80220264 00000002 */  srl       $zero, $zero, 0
/* 4F7708 80220268 802D9700 */  lb        $t5, -0x6900($at)
/* 4F770C 8022026C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7710 80220270 00000043 */  sra       $zero, $zero, 1
/* 4F7714 80220274 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7718 80220278 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F771C 8022027C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7720 80220280 00000000 */  nop       
/* 4F7724 80220284 00000000 */  nop       
/* 4F7728 80220288 00000000 */  nop       
/* 4F772C 8022028C 00000043 */  sra       $zero, $zero, 1
/* 4F7730 80220290 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7734 80220294 802189F0 */  lb        $at, -0x7610($at)
/* 4F7738 80220298 00000002 */  srl       $zero, $zero, 0
/* 4F773C 8022029C 00000000 */  nop       
/* 4F7740 802202A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7744 802202A4 00000000 */  nop       
/* 4F7748 802202A8 00000043 */  sra       $zero, $zero, 1
/* 4F774C 802202AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7750 802202B0 80218A38 */  lb        $at, -0x75c8($at)
/* 4F7754 802202B4 00000002 */  srl       $zero, $zero, 0
/* 4F7758 802202B8 00000000 */  nop       
/* 4F775C 802202BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7760 802202C0 00000000 */  nop       
/* 4F7764 802202C4 80220670 */  lb        $v0, 0x670($at)
/* 4F7768 802202C8 80220660 */  lb        $v0, 0x660($at)
/* 4F776C 802202CC 80220650 */  lb        $v0, 0x650($at)
/* 4F7770 802202D0 80220260 */  lb        $v0, 0x260($at)
/* 4F7774 802202D4 802202A8 */  lb        $v0, 0x2a8($at)
/* 4F7778 802202D8 00000000 */  nop       
/* 4F777C 802202DC 00000000 */  nop       
/* 4F7780 802202E0 00000000 */  nop       
/* 4F7784 802202E4 00000000 */  nop       
/* 4F7788 802202E8 00000000 */  nop       
/* 4F778C 802202EC 00000000 */  nop       
/* 4F7790 802202F0 00000043 */  sra       $zero, $zero, 1
/* 4F7794 802202F4 00000002 */  srl       $zero, $zero, 0
/* 4F7798 802202F8 802D9700 */  lb        $t5, -0x6900($at)
/* 4F779C 802202FC FFFFFFFF */  sd        $ra, -1($ra)
/* 4F77A0 80220300 00000043 */  sra       $zero, $zero, 1
/* 4F77A4 80220304 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F77A8 80220308 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F77AC 8022030C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F77B0 80220310 00000000 */  nop       
/* 4F77B4 80220314 00000000 */  nop       
/* 4F77B8 80220318 00000000 */  nop       
/* 4F77BC 8022031C 00000043 */  sra       $zero, $zero, 1
/* 4F77C0 80220320 00000001 */  movf      $zero, $zero, $fcc0
/* 4F77C4 80220324 80218A60 */  lb        $at, -0x75a0($at)
/* 4F77C8 80220328 00000043 */  sra       $zero, $zero, 1
/* 4F77CC 8022032C 00000003 */  sra       $zero, $zero, 0
/* 4F77D0 80220330 802C9288 */  lb        $t4, -0x6d78($at)
/* 4F77D4 80220334 00000017 */  dsrav     $zero, $zero, $zero
/* 4F77D8 80220338 00000000 */  nop       
/* 4F77DC 8022033C 00000002 */  srl       $zero, $zero, 0
/* 4F77E0 80220340 00000000 */  nop       
/* 4F77E4 80220344 00000001 */  movf      $zero, $zero, $fcc0
/* 4F77E8 80220348 00000000 */  nop       
/* 4F77EC 8022034C 00000043 */  sra       $zero, $zero, 1
/* 4F77F0 80220350 00000001 */  movf      $zero, $zero, $fcc0
/* 4F77F4 80220354 80218AA8 */  lb        $at, -0x7558($at)
/* 4F77F8 80220358 00000002 */  srl       $zero, $zero, 0
/* 4F77FC 8022035C 00000000 */  nop       
/* 4F7800 80220360 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7804 80220364 00000000 */  nop       
/* 4F7808 80220368 80220698 */  lb        $v0, 0x698($at)
/* 4F780C 8022036C 80220688 */  lb        $v0, 0x688($at)
/* 4F7810 80220370 80220678 */  lb        $v0, 0x678($at)
/* 4F7814 80220374 802202F0 */  lb        $v0, 0x2f0($at)
/* 4F7818 80220378 8022034C */  lb        $v0, 0x34c($at)
/* 4F781C 8022037C 00000000 */  nop       
/* 4F7820 80220380 00000000 */  nop       
/* 4F7824 80220384 00000000 */  nop       
/* 4F7828 80220388 00000000 */  nop       
/* 4F782C 8022038C 00000000 */  nop       
/* 4F7830 80220390 00000043 */  sra       $zero, $zero, 1
/* 4F7834 80220394 00000002 */  srl       $zero, $zero, 0
/* 4F7838 80220398 802D9700 */  lb        $t5, -0x6900($at)
/* 4F783C 8022039C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F7840 802203A0 00000043 */  sra       $zero, $zero, 1
/* 4F7844 802203A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7848 802203A8 802CAD98 */  lb        $t4, -0x5268($at)
/* 4F784C 802203AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7850 802203B0 00000000 */  nop       
/* 4F7854 802203B4 00000000 */  nop       
/* 4F7858 802203B8 00000000 */  nop       
/* 4F785C 802203BC 00000043 */  sra       $zero, $zero, 1
/* 4F7860 802203C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7864 802203C4 80218AD0 */  lb        $at, -0x7530($at)
/* 4F7868 802203C8 00000002 */  srl       $zero, $zero, 0
/* 4F786C 802203CC 00000000 */  nop       
/* 4F7870 802203D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7874 802203D4 00000000 */  nop       
/* 4F7878 802203D8 00000043 */  sra       $zero, $zero, 1
/* 4F787C 802203DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7880 802203E0 80218B18 */  lb        $at, -0x74e8($at)
/* 4F7884 802203E4 00000002 */  srl       $zero, $zero, 0
/* 4F7888 802203E8 00000000 */  nop       
/* 4F788C 802203EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7890 802203F0 00000000 */  nop       
/* 4F7894 802203F4 802206C0 */  lb        $v0, 0x6c0($at)
/* 4F7898 802203F8 802206B0 */  lb        $v0, 0x6b0($at)
/* 4F789C 802203FC 802206A0 */  lb        $v0, 0x6a0($at)
/* 4F78A0 80220400 80220390 */  lb        $v0, 0x390($at)
/* 4F78A4 80220404 802203D8 */  lb        $v0, 0x3d8($at)
/* 4F78A8 80220408 00000000 */  nop       
/* 4F78AC 8022040C 00000000 */  nop       
/* 4F78B0 80220410 00000000 */  nop       
/* 4F78B4 80220414 00000000 */  nop       
/* 4F78B8 80220418 00000000 */  nop       
/* 4F78BC 8022041C 00000000 */  nop       
/* 4F78C0 80220420 00000061 */  .byte     0x00, 0x00, 0x00, 0x61
/* 4F78C4 80220424 00000046 */  rotrv     $zero, $zero, $zero
/* 4F78C8 80220428 00000011 */  mthi      $zero
/* 4F78CC 8022042C 8021BBF4 */  lb        $at, -0x440c($at)
/* 4F78D0 80220430 80220420 */  lb        $v0, 0x420($at)
/* 4F78D4 80220434 0000000A */  movz      $zero, $zero, $zero
/* 4F78D8 80220438 00000000 */  nop       
/* 4F78DC 8022043C 00000000 */  nop       
/* 4F78E0 80220440 00000000 */  nop       
/* 4F78E4 80220444 00000000 */  nop       
/* 4F78E8 80220448 802206C8 */  lb        $v0, 0x6c8($at)
/* 4F78EC 8022044C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F78F0 80220450 8022042C */  lb        $v0, 0x42c($at)
/* 4F78F4 80220454 8021FDBC */  lb        $at, -0x244($at)
/* 4F78F8 80220458 00000000 */  nop       
/* 4F78FC 8022045C 00000000 */  nop       
/* 4F7900 80220460 00000000 */  nop       
/* 4F7904 80220464 00000000 */  nop       
/* 4F7908 80220468 00000000 */  nop       
/* 4F790C 8022046C 00000000 */  nop       
/* 4F7910 80220470 80220734 */  lb        $v0, 0x734($at)
/* 4F7914 80220474 8021FD3C */  lb        $at, -0x2c4($at)
/* 4F7918 80220478 8022072C */  lb        $v0, 0x72c($at)
/* 4F791C 8022047C 8021FDBC */  lb        $at, -0x244($at)
/* 4F7920 80220480 80220724 */  lb        $v0, 0x724($at)
/* 4F7924 80220484 8021FE4C */  lb        $at, -0x1b4($at)
/* 4F7928 80220488 8022071C */  lb        $v0, 0x71c($at)
/* 4F792C 8022048C 8021FF54 */  lb        $at, -0xac($at)
/* 4F7930 80220490 80220714 */  lb        $v0, 0x714($at)
/* 4F7934 80220494 80220004 */  lb        $v0, 4($at)
/* 4F7938 80220498 8022070C */  lb        $v0, 0x70c($at)
/* 4F793C 8022049C 8022007C */  lb        $v0, 0x7c($at)
/* 4F7940 802204A0 80220704 */  lb        $v0, 0x704($at)
/* 4F7944 802204A4 802200FC */  lb        $v0, 0xfc($at)
/* 4F7948 802204A8 802206FC */  lb        $v0, 0x6fc($at)
/* 4F794C 802204AC 802201A0 */  lb        $v0, 0x1a0($at)
/* 4F7950 802204B0 802206F4 */  lb        $v0, 0x6f4($at)
/* 4F7954 802204B4 80220234 */  lb        $v0, 0x234($at)
/* 4F7958 802204B8 802206EC */  lb        $v0, 0x6ec($at)
/* 4F795C 802204BC 802202C4 */  lb        $v0, 0x2c4($at)
/* 4F7960 802204C0 802206E4 */  lb        $v0, 0x6e4($at)
/* 4F7964 802204C4 80220368 */  lb        $v0, 0x368($at)
/* 4F7968 802204C8 802206DC */  lb        $v0, 0x6dc($at)
/* 4F796C 802204CC 802203F4 */  lb        $v0, 0x3f4($at)
/* 4F7970 802204D0 00000000 */  nop       
/* 4F7974 802204D4 00000000 */  nop       
/* 4F7978 802204D8 00000000 */  nop       
/* 4F797C 802204DC 00000000 */  nop       
/* 4F7980 802204E0 3FC99999 */  .byte     0x3f, 0xc9, 0x99, 0x99
/* 4F7984 802204E4 9999999A */  lwr       $t9, -0x6666($t4)
/* 4F7988 802204E8 00000000 */  nop       
/* 4F798C 802204EC 00000000 */  nop       
/* 4F7990 802204F0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7994 802204F4 62743030 */  daddi     $s4, $s3, 0x3030
/* 4F7998 802204F8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F799C 802204FC 70650000 */  madd      $v1, $a1
/* 4F79A0 80220500 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F79A4 80220504 74657800 */  jalx      0x8195e000
/* 4F79A8 80220508 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F79AC 8022050C 62743031 */  daddi     $s4, $s3, 0x3031
/* 4F79B0 80220510 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F79B4 80220514 00000000 */  nop       
/* 4F79B8 80220518 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F79BC 8022051C 62743031 */  daddi     $s4, $s3, 0x3031
/* 4F79C0 80220520 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F79C4 80220524 70650000 */  madd      $v1, $a1
/* 4F79C8 80220528 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F79CC 8022052C 74657800 */  jalx      0x8195e000
/* 4F79D0 80220530 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F79D4 80220534 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F79D8 80220538 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F79DC 8022053C 00000000 */  nop       
/* 4F79E0 80220540 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F79E4 80220544 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F79E8 80220548 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F79EC 8022054C 70650000 */  madd      $v1, $a1
/* 4F79F0 80220550 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F79F4 80220554 74657800 */  jalx      0x8195e000
/* 4F79F8 80220558 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F79FC 8022055C 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F7A00 80220560 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7A04 80220564 00000000 */  nop       
/* 4F7A08 80220568 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A0C 8022056C 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F7A10 80220570 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7A14 80220574 70650000 */  madd      $v1, $a1
/* 4F7A18 80220578 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A1C 8022057C 74657800 */  jalx      0x8195e000
/* 4F7A20 80220580 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7A24 80220584 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F7A28 80220588 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7A2C 8022058C 00000000 */  nop       
/* 4F7A30 80220590 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A34 80220594 62743032 */  daddi     $s4, $s3, 0x3032
/* 4F7A38 80220598 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7A3C 8022059C 70650000 */  madd      $v1, $a1
/* 4F7A40 802205A0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A44 802205A4 74657800 */  jalx      0x8195e000
/* 4F7A48 802205A8 73626B33 */   cins32   $v0, $k1, 0xc, 0xd
/* 4F7A4C 802205AC 5F626700 */  .byte     0x5f, 0x62, 0x67, 0x00
/* 4F7A50 802205B0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A54 802205B4 62743033 */  daddi     $s4, $s3, 0x3033
/* 4F7A58 802205B8 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7A5C 802205BC 00000000 */  nop       
/* 4F7A60 802205C0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A64 802205C4 62743033 */  daddi     $s4, $s3, 0x3033
/* 4F7A68 802205C8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7A6C 802205CC 70650000 */  madd      $v1, $a1
/* 4F7A70 802205D0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A74 802205D4 74657800 */  jalx      0x8195e000
/* 4F7A78 802205D8 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7A7C 802205DC 62743033 */  daddi     $s4, $s3, 0x3033
/* 4F7A80 802205E0 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7A84 802205E4 00000000 */  nop       
/* 4F7A88 802205E8 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A8C 802205EC 62743033 */  daddi     $s4, $s3, 0x3033
/* 4F7A90 802205F0 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7A94 802205F4 70650000 */  madd      $v1, $a1
/* 4F7A98 802205F8 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7A9C 802205FC 74657800 */  jalx      0x8195e000
/* 4F7AA0 80220600 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7AA4 80220604 62743034 */  daddi     $s4, $s3, 0x3034
/* 4F7AA8 80220608 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7AAC 8022060C 00000000 */  nop       
/* 4F7AB0 80220610 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7AB4 80220614 62743034 */  daddi     $s4, $s3, 0x3034
/* 4F7AB8 80220618 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7ABC 8022061C 70650000 */  madd      $v1, $a1
/* 4F7AC0 80220620 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7AC4 80220624 74657800 */  jalx      0x8195e000
/* 4F7AC8 80220628 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7ACC 8022062C 62743035 */  daddi     $s4, $s3, 0x3035
/* 4F7AD0 80220630 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7AD4 80220634 00000000 */  nop       
/* 4F7AD8 80220638 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7ADC 8022063C 62743035 */  daddi     $s4, $s3, 0x3035
/* 4F7AE0 80220640 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7AE4 80220644 70650000 */  madd      $v1, $a1
/* 4F7AE8 80220648 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7AEC 8022064C 74657800 */  jalx      0x8195e000
/* 4F7AF0 80220650 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7AF4 80220654 62743036 */  daddi     $s4, $s3, 0x3036
/* 4F7AF8 80220658 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7AFC 8022065C 00000000 */  nop       
/* 4F7B00 80220660 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B04 80220664 62743036 */  daddi     $s4, $s3, 0x3036
/* 4F7B08 80220668 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7B0C 8022066C 70650000 */  madd      $v1, $a1
/* 4F7B10 80220670 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B14 80220674 74657800 */  jalx      0x8195e000
/* 4F7B18 80220678 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7B1C 8022067C 62743036 */  daddi     $s4, $s3, 0x3036
/* 4F7B20 80220680 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7B24 80220684 00000000 */  nop       
/* 4F7B28 80220688 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B2C 8022068C 62743036 */  daddi     $s4, $s3, 0x3036
/* 4F7B30 80220690 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7B34 80220694 70650000 */  madd      $v1, $a1
/* 4F7B38 80220698 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B3C 8022069C 74657800 */  jalx      0x8195e000
/* 4F7B40 802206A0 69736B5F */   ldl      $s3, 0x6b5f($t3)
/* 4F7B44 802206A4 62743037 */  daddi     $s4, $s3, 0x3037
/* 4F7B48 802206A8 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4F7B4C 802206AC 00000000 */  nop       
/* 4F7B50 802206B0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B54 802206B4 62743037 */  daddi     $s4, $s3, 0x3037
/* 4F7B58 802206B8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4F7B5C 802206BC 70650000 */  madd      $v1, $a1
/* 4F7B60 802206C0 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B64 802206C4 74657800 */  jalx      0x8195e000
/* 4F7B68 802206C8 834A815B */   lb       $t2, -0x7ea5($k0)
/* 4F7B6C 802206CC 83818393 */  lb        $at, -0x7c6d($gp)
/* 4F7B70 802206D0 8140838F */  lb        $zero, -0x7c71($t2)
/* 4F7B74 802206D4 8393838F */  lb        $s3, -0x7c71($gp)
/* 4F7B78 802206D8 83930000 */  lb        $s3, ($gp)
/* 4F7B7C 802206DC 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B80 802206E0 30370000 */  andi      $s7, $at, 0
/* 4F7B84 802206E4 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B88 802206E8 30366200 */  andi      $s6, $at, 0x6200
/* 4F7B8C 802206EC 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B90 802206F0 30360000 */  andi      $s6, $at, 0
/* 4F7B94 802206F4 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7B98 802206F8 30350000 */  andi      $s5, $at, 0
/* 4F7B9C 802206FC 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BA0 80220700 30340000 */  andi      $s4, $at, 0
/* 4F7BA4 80220704 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BA8 80220708 30336200 */  andi      $s3, $at, 0x6200
/* 4F7BAC 8022070C 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BB0 80220710 30330000 */  andi      $s3, $at, 0
/* 4F7BB4 80220714 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BB8 80220718 30326300 */  andi      $s2, $at, 0x6300
/* 4F7BBC 8022071C 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BC0 80220720 30326200 */  andi      $s2, $at, 0x6200
/* 4F7BC4 80220724 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BC8 80220728 30320000 */  andi      $s2, $at, 0
/* 4F7BCC 8022072C 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BD0 80220730 30310000 */  andi      $s1, $at, 0
/* 4F7BD4 80220734 69736B5F */  ldl       $s3, 0x6b5f($t3)
/* 4F7BD8 80220738 30300000 */  andi      $s0, $at, 0
/* 4F7BDC 8022073C 00000000 */  nop       
