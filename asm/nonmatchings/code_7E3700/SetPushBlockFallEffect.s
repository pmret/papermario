.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPushBlockFallEffect
/* 7E462C 802837AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 7E4630 802837B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 7E4634 802837B4 0080882D */  daddu $s1, $a0, $zero
/* 7E4638 802837B8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 7E463C 802837BC AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4640 802837C0 8E30000C */  lw    $s0, 0xc($s1)
/* 7E4644 802837C4 8E050000 */  lw    $a1, ($s0)
/* 7E4648 802837C8 0C0B1EAF */  jal   get_variable
/* 7E464C 802837CC 26100004 */   addiu $s0, $s0, 4
/* 7E4650 802837D0 0220202D */  daddu $a0, $s1, $zero
/* 7E4654 802837D4 8E050000 */  lw    $a1, ($s0)
/* 7E4658 802837D8 0C0B1EAF */  jal   get_variable
/* 7E465C 802837DC 0040802D */   daddu $s0, $v0, $zero
/* 7E4660 802837E0 00108080 */  sll   $s0, $s0, 2
/* 7E4664 802837E4 3C03802E */  lui   $v1, 0x802e
/* 7E4668 802837E8 00701821 */  addu  $v1, $v1, $s0
/* 7E466C 802837EC 8C63BC88 */  lw    $v1, -0x4378($v1)
/* 7E4670 802837F0 AC620014 */  sw    $v0, 0x14($v1)
/* 7E4674 802837F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 7E4678 802837F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E467C 802837FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E4680 80283800 24020002 */  addiu $v0, $zero, 2
/* 7E4684 80283804 03E00008 */  jr    $ra
/* 7E4688 80283808 27BD0020 */   addiu $sp, $sp, 0x20

/* 7E468C 8028380C 00000000 */  nop   
/* 7E4690 80283810 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 7E4694 80283814 AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4698 80283818 0080802D */  daddu $s0, $a0, $zero
/* 7E469C 8028381C AFBF0014 */  sw    $ra, 0x14($sp)
/* 7E46A0 80283820 0C03AD8E */  jal   func_800EB638
/* 7E46A4 80283824 AE0000AC */   sw    $zero, 0xac($s0)
/* 7E46A8 80283828 1040000F */  beqz  $v0, .L80283868
/* 7E46AC 8028382C 00000000 */   nop   
/* 7E46B0 80283830 3C028011 */  lui   $v0, 0x8011
/* 7E46B4 80283834 8042EBB0 */  lb    $v0, -0x1450($v0)
/* 7E46B8 80283838 14400003 */  bnez  $v0, .L80283848
/* 7E46BC 8028383C 24020001 */   addiu $v0, $zero, 1
/* 7E46C0 80283840 080A0E1A */  j     .L80283868
/* 7E46C4 80283844 AE0000AC */   sw    $zero, 0xac($s0)

.L80283848:
/* 7E46C8 80283848 0C03AD8E */  jal   func_800EB638
/* 7E46CC 8028384C AE0200AC */   sw    $v0, 0xac($s0)
/* 7E46D0 80283850 AE0200B0 */  sw    $v0, 0xb0($s0)
/* 7E46D4 80283854 3C028011 */  lui   $v0, 0x8011
/* 7E46D8 80283858 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 7E46DC 8028385C C4400080 */  lwc1  $f0, 0x80($v0)
/* 7E46E0 80283860 4600008D */  trunc.w.s $f2, $f0
/* 7E46E4 80283864 E60200B8 */  swc1  $f2, 0xb8($s0)
.L80283868:
.L80283868:
/* 7E46E8 80283868 8FBF0014 */  lw    $ra, 0x14($sp)
/* 7E46EC 8028386C 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E46F0 80283870 24020002 */  addiu $v0, $zero, 2
/* 7E46F4 80283874 03E00008 */  jr    $ra
/* 7E46F8 80283878 27BD0018 */   addiu $sp, $sp, 0x18

/* 7E46FC 8028387C 3C028011 */  lui   $v0, 0x8011
/* 7E4700 80283880 8042F2A2 */  lb    $v0, -0xd5e($v0)
/* 7E4704 80283884 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 7E4708 80283888 AFB10014 */  sw    $s1, 0x14($sp)
/* 7E470C 8028388C 3C118011 */  lui   $s1, 0x8011
/* 7E4710 80283890 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 7E4714 80283894 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E4718 80283898 0220902D */  daddu $s2, $s1, $zero
/* 7E471C 8028389C AFBF001C */  sw    $ra, 0x1c($sp)
/* 7E4720 802838A0 10400012 */  beqz  $v0, .L802838EC
/* 7E4724 802838A4 AFB00010 */   sw    $s0, 0x10($sp)
/* 7E4728 802838A8 0C00EABB */  jal   get_npc_unsafe
/* 7E472C 802838AC 2404FFFC */   addiu $a0, $zero, -4
/* 7E4730 802838B0 C6200028 */  lwc1  $f0, 0x28($s1)
/* 7E4734 802838B4 0040802D */  daddu $s0, $v0, $zero
/* 7E4738 802838B8 E6000038 */  swc1  $f0, 0x38($s0)
/* 7E473C 802838BC C6200030 */  lwc1  $f0, 0x30($s1)
/* 7E4740 802838C0 0C03A969 */  jal   func_800EA5A4
/* 7E4744 802838C4 E6000040 */   swc1  $f0, 0x40($s0)
/* 7E4748 802838C8 10400003 */  beqz  $v0, .L802838D8
/* 7E474C 802838CC 00000000 */   nop   
/* 7E4750 802838D0 C620002C */  lwc1  $f0, 0x2c($s1)
/* 7E4754 802838D4 E600003C */  swc1  $f0, 0x3c($s0)
.L802838D8:
/* 7E4758 802838D8 8E450080 */  lw    $a1, 0x80($s2)
/* 7E475C 802838DC 0C00ECD0 */  jal   set_npc_yaw
/* 7E4760 802838E0 0200202D */   daddu $a0, $s0, $zero
/* 7E4764 802838E4 0C03BD17 */  jal   clear_partner_move_history
/* 7E4768 802838E8 0200202D */   daddu $a0, $s0, $zero
.L802838EC:
/* 7E476C 802838EC 24020002 */  addiu $v0, $zero, 2
/* 7E4770 802838F0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 7E4774 802838F4 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E4778 802838F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E477C 802838FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E4780 80283900 03E00008 */  jr    $ra
/* 7E4784 80283904 27BD0020 */   addiu $sp, $sp, 0x20

/* 7E4788 80283908 3C038007 */  lui   $v1, 0x8007
/* 7E478C 8028390C 8C63419C */  lw    $v1, 0x419c($v1)
/* 7E4790 80283910 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 7E4794 80283914 AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4798 80283918 3C108011 */  lui   $s0, 0x8011
/* 7E479C 8028391C 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 7E47A0 80283920 AFBF001C */  sw    $ra, 0x1c($sp)
/* 7E47A4 80283924 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E47A8 80283928 AFB10014 */  sw    $s1, 0x14($sp)
/* 7E47AC 8028392C 84620160 */  lh    $v0, 0x160($v1)
/* 7E47B0 80283930 0200882D */  daddu $s1, $s0, $zero
/* 7E47B4 80283934 44820000 */  mtc1  $v0, $f0
/* 7E47B8 80283938 00000000 */  nop   
/* 7E47BC 8028393C 46800020 */  cvt.s.w $f0, $f0
/* 7E47C0 80283940 E6000028 */  swc1  $f0, 0x28($s0)
/* 7E47C4 80283944 84620162 */  lh    $v0, 0x162($v1)
/* 7E47C8 80283948 3C04800B */  lui   $a0, 0x800b
/* 7E47CC 8028394C 24841D80 */  addiu $a0, $a0, 0x1d80
/* 7E47D0 80283950 44820000 */  mtc1  $v0, $f0
/* 7E47D4 80283954 00000000 */  nop   
/* 7E47D8 80283958 46800020 */  cvt.s.w $f0, $f0
/* 7E47DC 8028395C E600002C */  swc1  $f0, 0x2c($s0)
/* 7E47E0 80283960 84620164 */  lh    $v0, 0x164($v1)
/* 7E47E4 80283964 3C038007 */  lui   $v1, 0x8007
/* 7E47E8 80283968 8C637410 */  lw    $v1, 0x7410($v1)
/* 7E47EC 8028396C 44820000 */  mtc1  $v0, $f0
/* 7E47F0 80283970 00000000 */  nop   
/* 7E47F4 80283974 46800020 */  cvt.s.w $f0, $f0
/* 7E47F8 80283978 00031080 */  sll   $v0, $v1, 2
/* 7E47FC 8028397C 00431021 */  addu  $v0, $v0, $v1
/* 7E4800 80283980 00021080 */  sll   $v0, $v0, 2
/* 7E4804 80283984 00431023 */  subu  $v0, $v0, $v1
/* 7E4808 80283988 000218C0 */  sll   $v1, $v0, 3
/* 7E480C 8028398C 00431021 */  addu  $v0, $v0, $v1
/* 7E4810 80283990 000210C0 */  sll   $v0, $v0, 3
/* 7E4814 80283994 E6000030 */  swc1  $f0, 0x30($s0)
/* 7E4818 80283998 3C038011 */  lui   $v1, 0x8011
/* 7E481C 8028399C 8063F2A2 */  lb    $v1, -0xd5e($v1)
/* 7E4820 802839A0 10600022 */  beqz  $v1, .L80283A2C
/* 7E4824 802839A4 00449021 */   addu  $s2, $v0, $a0
/* 7E4828 802839A8 0C00EABB */  jal   get_npc_unsafe
/* 7E482C 802839AC 2404FFFC */   addiu $a0, $zero, -4
/* 7E4830 802839B0 C60200A8 */  lwc1  $f2, 0xa8($s0)
/* 7E4834 802839B4 3C014334 */  lui   $at, 0x4334
/* 7E4838 802839B8 44810000 */  mtc1  $at, $f0
/* 7E483C 802839BC 3C01C2B4 */  lui   $at, 0xc2b4
/* 7E4840 802839C0 44816000 */  mtc1  $at, $f12
/* 7E4844 802839C4 4600103C */  c.lt.s $f2, $f0
/* 7E4848 802839C8 00000000 */  nop   
/* 7E484C 802839CC 45000003 */  bc1f  .L802839DC
/* 7E4850 802839D0 0040802D */   daddu $s0, $v0, $zero
/* 7E4854 802839D4 3C0142B4 */  lui   $at, 0x42b4
/* 7E4858 802839D8 44816000 */  mtc1  $at, $f12
.L802839DC:
/* 7E485C 802839DC 0C00A6C9 */  jal   clamp_angle
/* 7E4860 802839E0 00000000 */   nop   
/* 7E4864 802839E4 C6220028 */  lwc1  $f2, 0x28($s1)
/* 7E4868 802839E8 E6020038 */  swc1  $f2, 0x38($s0)
/* 7E486C 802839EC C622002C */  lwc1  $f2, 0x2c($s1)
/* 7E4870 802839F0 E602003C */  swc1  $f2, 0x3c($s0)
/* 7E4874 802839F4 C6220030 */  lwc1  $f2, 0x30($s1)
/* 7E4878 802839F8 26040038 */  addiu $a0, $s0, 0x38
/* 7E487C 802839FC E6020040 */  swc1  $f2, 0x40($s0)
/* 7E4880 80283A00 862200B2 */  lh    $v0, 0xb2($s1)
/* 7E4884 80283A04 44070000 */  mfc1  $a3, $f0
/* 7E4888 80283A08 24420005 */  addiu $v0, $v0, 5
/* 7E488C 80283A0C 44822000 */  mtc1  $v0, $f4
/* 7E4890 80283A10 00000000 */  nop   
/* 7E4894 80283A14 46802120 */  cvt.s.w $f4, $f4
/* 7E4898 80283A18 44062000 */  mfc1  $a2, $f4
/* 7E489C 80283A1C 0C00A7E7 */  jal   add_vec2D_polar
/* 7E48A0 80283A20 26050040 */   addiu $a1, $s0, 0x40
/* 7E48A4 80283A24 0C03BCCA */  jal   enable_partner_ai
/* 7E48A8 80283A28 00000000 */   nop   
.L80283A2C:
/* 7E48AC 80283A2C 24020001 */  addiu $v0, $zero, 1
/* 7E48B0 80283A30 A6420008 */  sh    $v0, 8($s2)
/* 7E48B4 80283A34 8FBF001C */  lw    $ra, 0x1c($sp)
/* 7E48B8 80283A38 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E48BC 80283A3C 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E48C0 80283A40 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E48C4 80283A44 24020002 */  addiu $v0, $zero, 2
/* 7E48C8 80283A48 03E00008 */  jr    $ra
/* 7E48CC 80283A4C 27BD0020 */   addiu $sp, $sp, 0x20

/* 7E48D0 80283A50 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 7E48D4 80283A54 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E48D8 80283A58 0080902D */  daddu $s2, $a0, $zero
/* 7E48DC 80283A5C AFB00010 */  sw    $s0, 0x10($sp)
/* 7E48E0 80283A60 00A0802D */  daddu $s0, $a1, $zero
/* 7E48E4 80283A64 AFBF001C */  sw    $ra, 0x1c($sp)
/* 7E48E8 80283A68 0C016AFA */  jal   get_current_map_header
/* 7E48EC 80283A6C AFB10014 */   sw    $s1, 0x14($sp)
/* 7E48F0 80283A70 0000302D */  daddu $a2, $zero, $zero
/* 7E48F4 80283A74 3C118011 */  lui   $s1, 0x8011
/* 7E48F8 80283A78 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 7E48FC 80283A7C 12000021 */  beqz  $s0, .L80283B04
/* 7E4900 80283A80 0040282D */   daddu $a1, $v0, $zero
/* 7E4904 80283A84 3C048007 */  lui   $a0, 0x8007
/* 7E4908 80283A88 8C84419C */  lw    $a0, 0x419c($a0)
/* 7E490C 80283A8C 8482008E */  lh    $v0, 0x8e($a0)
/* 7E4910 80283A90 8CA30014 */  lw    $v1, 0x14($a1)
/* 7E4914 80283A94 00021100 */  sll   $v0, $v0, 4
/* 7E4918 80283A98 00431021 */  addu  $v0, $v0, $v1
/* 7E491C 80283A9C C4400000 */  lwc1  $f0, ($v0)
/* 7E4920 80283AA0 E6200028 */  swc1  $f0, 0x28($s1)
/* 7E4924 80283AA4 8482008E */  lh    $v0, 0x8e($a0)
/* 7E4928 80283AA8 8CA30014 */  lw    $v1, 0x14($a1)
/* 7E492C 80283AAC 00021100 */  sll   $v0, $v0, 4
/* 7E4930 80283AB0 00431021 */  addu  $v0, $v0, $v1
/* 7E4934 80283AB4 C4400008 */  lwc1  $f0, 8($v0)
/* 7E4938 80283AB8 E6200030 */  swc1  $f0, 0x30($s1)
/* 7E493C 80283ABC 8482008E */  lh    $v0, 0x8e($a0)
/* 7E4940 80283AC0 8CA30014 */  lw    $v1, 0x14($a1)
/* 7E4944 80283AC4 00021100 */  sll   $v0, $v0, 4
/* 7E4948 80283AC8 00431021 */  addu  $v0, $v0, $v1
/* 7E494C 80283ACC C4400004 */  lwc1  $f0, 4($v0)
/* 7E4950 80283AD0 4600018D */  trunc.w.s $f6, $f0
/* 7E4954 80283AD4 44023000 */  mfc1  $v0, $f6
/* 7E4958 80283AD8 00000000 */  nop   
/* 7E495C 80283ADC AE42008C */  sw    $v0, 0x8c($s2)
/* 7E4960 80283AE0 2442FFD8 */  addiu $v0, $v0, -0x28
/* 7E4964 80283AE4 44820000 */  mtc1  $v0, $f0
/* 7E4968 80283AE8 00000000 */  nop   
/* 7E496C 80283AEC 46800020 */  cvt.s.w $f0, $f0
/* 7E4970 80283AF0 8E220000 */  lw    $v0, ($s1)
/* 7E4974 80283AF4 3C030400 */  lui   $v1, 0x400
/* 7E4978 80283AF8 E620002C */  swc1  $f0, 0x2c($s1)
/* 7E497C 80283AFC 080A0ED2 */  j     .L80283B48
/* 7E4980 80283B00 00431025 */   or    $v0, $v0, $v1

.L80283B04:
/* 7E4984 80283B04 C622002C */  lwc1  $f2, 0x2c($s1)
/* 7E4988 80283B08 3C013F80 */  lui   $at, 0x3f80
/* 7E498C 80283B0C 44810000 */  mtc1  $at, $f0
/* 7E4990 80283B10 00000000 */  nop   
/* 7E4994 80283B14 46001080 */  add.s $f2, $f2, $f0
/* 7E4998 80283B18 E622002C */  swc1  $f2, 0x2c($s1)
/* 7E499C 80283B1C C640008C */  lwc1  $f0, 0x8c($s2)
/* 7E49A0 80283B20 46800020 */  cvt.s.w $f0, $f0
/* 7E49A4 80283B24 4600103C */  c.lt.s $f2, $f0
/* 7E49A8 80283B28 00000000 */  nop   
/* 7E49AC 80283B2C 45010007 */  bc1t  .L80283B4C
/* 7E49B0 80283B30 3C03FBFF */   lui   $v1, 0xfbff
/* 7E49B4 80283B34 3463FFFF */  ori   $v1, $v1, 0xffff
/* 7E49B8 80283B38 8E220000 */  lw    $v0, ($s1)
/* 7E49BC 80283B3C 24060002 */  addiu $a2, $zero, 2
/* 7E49C0 80283B40 E620002C */  swc1  $f0, 0x2c($s1)
/* 7E49C4 80283B44 00431024 */  and   $v0, $v0, $v1
.L80283B48:
/* 7E49C8 80283B48 AE220000 */  sw    $v0, ($s1)
.L80283B4C:
/* 7E49CC 80283B4C C6200028 */  lwc1  $f0, 0x28($s1)
/* 7E49D0 80283B50 C622002C */  lwc1  $f2, 0x2c($s1)
/* 7E49D4 80283B54 C6240030 */  lwc1  $f4, 0x30($s1)
/* 7E49D8 80283B58 3C03800B */  lui   $v1, 0x800b
/* 7E49DC 80283B5C 24631D80 */  addiu $v1, $v1, 0x1d80
/* 7E49E0 80283B60 E4600060 */  swc1  $f0, 0x60($v1)
/* 7E49E4 80283B64 E4620064 */  swc1  $f2, 0x64($v1)
/* 7E49E8 80283B68 E4640068 */  swc1  $f4, 0x68($v1)
/* 7E49EC 80283B6C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 7E49F0 80283B70 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E49F4 80283B74 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E49F8 80283B78 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E49FC 80283B7C 00C0102D */  daddu $v0, $a2, $zero
/* 7E4A00 80283B80 03E00008 */  jr    $ra
/* 7E4A04 80283B84 27BD0020 */   addiu $sp, $sp, 0x20

/* 7E4A08 80283B88 3C0141A0 */  lui   $at, 0x41a0
/* 7E4A0C 80283B8C 44816000 */  mtc1  $at, $f12
/* 7E4A10 80283B90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 7E4A14 80283B94 AFBF0010 */  sw    $ra, 0x10($sp)
/* 7E4A18 80283B98 0C03BCE5 */  jal   func_800EF394
/* 7E4A1C 80283B9C 00000000 */   nop   
/* 7E4A20 80283BA0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 7E4A24 80283BA4 24020002 */  addiu $v0, $zero, 2
/* 7E4A28 80283BA8 03E00008 */  jr    $ra
/* 7E4A2C 80283BAC 27BD0018 */   addiu $sp, $sp, 0x18

/* 7E4A30 80283BB0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 7E4A34 80283BB4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 7E4A38 80283BB8 0C03BCE9 */  jal   func_800EF3A4
/* 7E4A3C 80283BBC 00000000 */   nop   
/* 7E4A40 80283BC0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 7E4A44 80283BC4 24020002 */  addiu $v0, $zero, 2
/* 7E4A48 80283BC8 03E00008 */  jr    $ra
/* 7E4A4C 80283BCC 27BD0018 */   addiu $sp, $sp, 0x18

/* 7E4A50 80283BD0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 7E4A54 80283BD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4A58 80283BD8 0080802D */  daddu $s0, $a0, $zero
/* 7E4A5C 80283BDC AFB10014 */  sw    $s1, 0x14($sp)
/* 7E4A60 80283BE0 3C118011 */  lui   $s1, 0x8011
/* 7E4A64 80283BE4 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 7E4A68 80283BE8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 7E4A6C 80283BEC 10A00008 */  beqz  $a1, .L80283C10
/* 7E4A70 80283BF0 8E02000C */   lw    $v0, 0xc($s0)
/* 7E4A74 80283BF4 0C0B1EAF */  jal   get_variable
/* 7E4A78 80283BF8 8C450000 */   lw    $a1, ($v0)
/* 7E4A7C 80283BFC AE020070 */  sw    $v0, 0x70($s0)
/* 7E4A80 80283C00 8E250080 */  lw    $a1, 0x80($s1)
/* 7E4A84 80283C04 8E26005C */  lw    $a2, 0x5c($s1)
/* 7E4A88 80283C08 0C0389DE */  jal   move_player
/* 7E4A8C 80283C0C 0040202D */   daddu $a0, $v0, $zero
.L80283C10:
/* 7E4A90 80283C10 8E030070 */  lw    $v1, 0x70($s0)
/* 7E4A94 80283C14 2463FFFF */  addiu $v1, $v1, -1
/* 7E4A98 80283C18 AE030070 */  sw    $v1, 0x70($s0)
/* 7E4A9C 80283C1C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 7E4AA0 80283C20 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E4AA4 80283C24 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E4AA8 80283C28 000317C2 */  srl   $v0, $v1, 0x1f
/* 7E4AAC 80283C2C 03E00008 */  jr    $ra
/* 7E4AB0 80283C30 27BD0020 */   addiu $sp, $sp, 0x20

/* 7E4AB4 80283C34 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 7E4AB8 80283C38 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E4ABC 80283C3C 0080902D */  daddu $s2, $a0, $zero
/* 7E4AC0 80283C40 AFBF0020 */  sw    $ra, 0x20($sp)
/* 7E4AC4 80283C44 AFB3001C */  sw    $s3, 0x1c($sp)
/* 7E4AC8 80283C48 AFB10014 */  sw    $s1, 0x14($sp)
/* 7E4ACC 80283C4C AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4AD0 80283C50 0C016AFA */  jal   get_current_map_header
/* 7E4AD4 80283C54 8E50000C */   lw    $s0, 0xc($s2)
/* 7E4AD8 80283C58 0240202D */  daddu $a0, $s2, $zero
/* 7E4ADC 80283C5C 8C530014 */  lw    $s3, 0x14($v0)
/* 7E4AE0 80283C60 8E050000 */  lw    $a1, ($s0)
/* 7E4AE4 80283C64 0C0B1EAF */  jal   get_variable
/* 7E4AE8 80283C68 26100004 */   addiu $s0, $s0, 4
/* 7E4AEC 80283C6C 8E050000 */  lw    $a1, ($s0)
/* 7E4AF0 80283C70 26100004 */  addiu $s0, $s0, 4
/* 7E4AF4 80283C74 00028900 */  sll   $s1, $v0, 4
/* 7E4AF8 80283C78 02338821 */  addu  $s1, $s1, $s3
/* 7E4AFC 80283C7C C6200000 */  lwc1  $f0, ($s1)
/* 7E4B00 80283C80 4600008D */  trunc.w.s $f2, $f0
/* 7E4B04 80283C84 44061000 */  mfc1  $a2, $f2
/* 7E4B08 80283C88 0C0B2026 */  jal   set_variable
/* 7E4B0C 80283C8C 0240202D */   daddu $a0, $s2, $zero
/* 7E4B10 80283C90 8E050000 */  lw    $a1, ($s0)
/* 7E4B14 80283C94 26100004 */  addiu $s0, $s0, 4
/* 7E4B18 80283C98 C6200004 */  lwc1  $f0, 4($s1)
/* 7E4B1C 80283C9C 4600008D */  trunc.w.s $f2, $f0
/* 7E4B20 80283CA0 44061000 */  mfc1  $a2, $f2
/* 7E4B24 80283CA4 0C0B2026 */  jal   set_variable
/* 7E4B28 80283CA8 0240202D */   daddu $a0, $s2, $zero
/* 7E4B2C 80283CAC 8E050000 */  lw    $a1, ($s0)
/* 7E4B30 80283CB0 26100004 */  addiu $s0, $s0, 4
/* 7E4B34 80283CB4 C6200008 */  lwc1  $f0, 8($s1)
/* 7E4B38 80283CB8 4600008D */  trunc.w.s $f2, $f0
/* 7E4B3C 80283CBC 44061000 */  mfc1  $a2, $f2
/* 7E4B40 80283CC0 0C0B2026 */  jal   set_variable
/* 7E4B44 80283CC4 0240202D */   daddu $a0, $s2, $zero
/* 7E4B48 80283CC8 C620000C */  lwc1  $f0, 0xc($s1)
/* 7E4B4C 80283CCC 8E050000 */  lw    $a1, ($s0)
/* 7E4B50 80283CD0 4600008D */  trunc.w.s $f2, $f0
/* 7E4B54 80283CD4 44061000 */  mfc1  $a2, $f2
/* 7E4B58 80283CD8 0C0B2026 */  jal   set_variable
/* 7E4B5C 80283CDC 0240202D */   daddu $a0, $s2, $zero
/* 7E4B60 80283CE0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 7E4B64 80283CE4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 7E4B68 80283CE8 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E4B6C 80283CEC 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E4B70 80283CF0 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E4B74 80283CF4 24020002 */  addiu $v0, $zero, 2
/* 7E4B78 80283CF8 03E00008 */  jr    $ra
/* 7E4B7C 80283CFC 27BD0028 */   addiu $sp, $sp, 0x28

/* 7E4B80 80283D00 0080282D */  daddu $a1, $a0, $zero
/* 7E4B84 80283D04 8CA20090 */  lw    $v0, 0x90($a1)
/* 7E4B88 80283D08 04400009 */  bltz  $v0, .L80283D30
/* 7E4B8C 80283D0C 2403FFFF */   addiu $v1, $zero, -1
/* 7E4B90 80283D10 3C02802E */  lui   $v0, 0x802e
/* 7E4B94 80283D14 2442BD28 */  addiu $v0, $v0, -0x42d8
/* 7E4B98 80283D18 8CA4008C */  lw    $a0, 0x8c($a1)
/* 7E4B9C 80283D1C AC430004 */  sw    $v1, 4($v0)
/* 7E4BA0 80283D20 3C01802E */  lui   $at, 0x802e
/* 7E4BA4 80283D24 AC23BC7C */  sw    $v1, -0x4384($at)
/* 7E4BA8 80283D28 080A0F55 */  j     .L80283D54
/* 7E4BAC 80283D2C AC440000 */   sw    $a0, ($v0)

.L80283D30:
/* 7E4BB0 80283D30 3C02802E */  lui   $v0, 0x802e
/* 7E4BB4 80283D34 2442BC7C */  addiu $v0, $v0, -0x4384
/* 7E4BB8 80283D38 8CA4008C */  lw    $a0, 0x8c($a1)
/* 7E4BBC 80283D3C AC430004 */  sw    $v1, 4($v0)
/* 7E4BC0 80283D40 3C01802E */  lui   $at, 0x802e
/* 7E4BC4 80283D44 AC23BD28 */  sw    $v1, -0x42d8($at)
/* 7E4BC8 80283D48 AC440000 */  sw    $a0, ($v0)
/* 7E4BCC 80283D4C 3C02802E */  lui   $v0, 0x802e
/* 7E4BD0 80283D50 2442BD28 */  addiu $v0, $v0, -0x42d8
.L80283D54:
/* 7E4BD4 80283D54 ACA2008C */  sw    $v0, 0x8c($a1)
/* 7E4BD8 80283D58 3C02802E */  lui   $v0, 0x802e
/* 7E4BDC 80283D5C 2442BC7C */  addiu $v0, $v0, -0x4384
/* 7E4BE0 80283D60 ACA20090 */  sw    $v0, 0x90($a1)
/* 7E4BE4 80283D64 03E00008 */  jr    $ra
/* 7E4BE8 80283D68 24020002 */   addiu $v0, $zero, 2

/* 7E4BEC 80283D6C 0080282D */  daddu $a1, $a0, $zero
/* 7E4BF0 80283D70 8CA20090 */  lw    $v0, 0x90($a1)
/* 7E4BF4 80283D74 0440000C */  bltz  $v0, .L80283DA8
/* 7E4BF8 80283D78 00000000 */   nop   
/* 7E4BFC 80283D7C 8CA2008C */  lw    $v0, 0x8c($a1)
/* 7E4C00 80283D80 3C03802E */  lui   $v1, 0x802e
/* 7E4C04 80283D84 2463BD28 */  addiu $v1, $v1, -0x42d8
/* 7E4C08 80283D88 AC620000 */  sw    $v0, ($v1)
/* 7E4C0C 80283D8C 8CA40094 */  lw    $a0, 0x94($a1)
/* 7E4C10 80283D90 2402FFFF */  addiu $v0, $zero, -1
/* 7E4C14 80283D94 AC620008 */  sw    $v0, 8($v1)
/* 7E4C18 80283D98 3C01802E */  lui   $at, 0x802e
/* 7E4C1C 80283D9C AC22BC7C */  sw    $v0, -0x4384($at)
/* 7E4C20 80283DA0 080A0F74 */  j     .L80283DD0
/* 7E4C24 80283DA4 AC640004 */   sw    $a0, 4($v1)

.L80283DA8:
/* 7E4C28 80283DA8 8CA2008C */  lw    $v0, 0x8c($a1)
/* 7E4C2C 80283DAC 3C03802E */  lui   $v1, 0x802e
/* 7E4C30 80283DB0 2463BC7C */  addiu $v1, $v1, -0x4384
/* 7E4C34 80283DB4 AC620000 */  sw    $v0, ($v1)
/* 7E4C38 80283DB8 8CA40094 */  lw    $a0, 0x94($a1)
/* 7E4C3C 80283DBC 2402FFFF */  addiu $v0, $zero, -1
/* 7E4C40 80283DC0 AC620008 */  sw    $v0, 8($v1)
/* 7E4C44 80283DC4 3C01802E */  lui   $at, 0x802e
/* 7E4C48 80283DC8 AC22BD28 */  sw    $v0, -0x42d8($at)
/* 7E4C4C 80283DCC AC640004 */  sw    $a0, 4($v1)
.L80283DD0:
/* 7E4C50 80283DD0 3C02802E */  lui   $v0, 0x802e
/* 7E4C54 80283DD4 2442BD28 */  addiu $v0, $v0, -0x42d8
/* 7E4C58 80283DD8 ACA2008C */  sw    $v0, 0x8c($a1)
/* 7E4C5C 80283DDC 3C02802E */  lui   $v0, 0x802e
/* 7E4C60 80283DE0 2442BC7C */  addiu $v0, $v0, -0x4384
/* 7E4C64 80283DE4 ACA20090 */  sw    $v0, 0x90($a1)
/* 7E4C68 80283DE8 03E00008 */  jr    $ra
/* 7E4C6C 80283DEC 24020002 */   addiu $v0, $zero, 2

/* 7E4C70 80283DF0 3C03802E */  lui   $v1, 0x802e
/* 7E4C74 80283DF4 2463BD28 */  addiu $v1, $v1, -0x42d8
/* 7E4C78 80283DF8 8C82008C */  lw    $v0, 0x8c($a0)
/* 7E4C7C 80283DFC 2406FFFF */  addiu $a2, $zero, -1
/* 7E4C80 80283E00 AC660004 */  sw    $a2, 4($v1)
/* 7E4C84 80283E04 AC620000 */  sw    $v0, ($v1)
/* 7E4C88 80283E08 8C850090 */  lw    $a1, 0x90($a0)
/* 7E4C8C 80283E0C 3C02802E */  lui   $v0, 0x802e
/* 7E4C90 80283E10 2442BC7C */  addiu $v0, $v0, -0x4384
/* 7E4C94 80283E14 AC460004 */  sw    $a2, 4($v0)
/* 7E4C98 80283E18 AC450000 */  sw    $a1, ($v0)
/* 7E4C9C 80283E1C AC820090 */  sw    $v0, 0x90($a0)
/* 7E4CA0 80283E20 24020002 */  addiu $v0, $zero, 2
/* 7E4CA4 80283E24 03E00008 */  jr    $ra
/* 7E4CA8 80283E28 AC83008C */   sw    $v1, 0x8c($a0)

/* 7E4CAC 80283E2C 8C82008C */  lw    $v0, 0x8c($a0)
/* 7E4CB0 80283E30 3C05802E */  lui   $a1, 0x802e
/* 7E4CB4 80283E34 24A5BD28 */  addiu $a1, $a1, -0x42d8
/* 7E4CB8 80283E38 ACA20000 */  sw    $v0, ($a1)
/* 7E4CBC 80283E3C 8C820094 */  lw    $v0, 0x94($a0)
/* 7E4CC0 80283E40 2406FFFF */  addiu $a2, $zero, -1
/* 7E4CC4 80283E44 ACA60008 */  sw    $a2, 8($a1)
/* 7E4CC8 80283E48 ACA20004 */  sw    $v0, 4($a1)
/* 7E4CCC 80283E4C 8C830090 */  lw    $v1, 0x90($a0)
/* 7E4CD0 80283E50 3C02802E */  lui   $v0, 0x802e
/* 7E4CD4 80283E54 2442BC7C */  addiu $v0, $v0, -0x4384
/* 7E4CD8 80283E58 AC430000 */  sw    $v1, ($v0)
/* 7E4CDC 80283E5C 8C830098 */  lw    $v1, 0x98($a0)
/* 7E4CE0 80283E60 AC460008 */  sw    $a2, 8($v0)
/* 7E4CE4 80283E64 AC430004 */  sw    $v1, 4($v0)
/* 7E4CE8 80283E68 AC820090 */  sw    $v0, 0x90($a0)
/* 7E4CEC 80283E6C 24020002 */  addiu $v0, $zero, 2
/* 7E4CF0 80283E70 03E00008 */  jr    $ra
/* 7E4CF4 80283E74 AC85008C */   sw    $a1, 0x8c($a0)

/* 7E4CF8 80283E78 00000000 */  nop   
/* 7E4CFC 80283E7C 00000000 */  nop   
