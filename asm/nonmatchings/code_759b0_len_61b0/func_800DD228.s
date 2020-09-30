.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DD228
/* 766D8 800DD228 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 766DC 800DD22C F7B40050 */  sdc1      $f20, 0x50($sp)
/* 766E0 800DD230 C7B4008C */  lwc1      $f20, 0x8c($sp)
/* 766E4 800DD234 3C0140C9 */  lui       $at, 0x40c9
/* 766E8 800DD238 34210FD0 */  ori       $at, $at, 0xfd0
/* 766EC 800DD23C 44810000 */  mtc1      $at, $f0
/* 766F0 800DD240 AFB60040 */  sw        $s6, 0x40($sp)
/* 766F4 800DD244 8FB60088 */  lw        $s6, 0x88($sp)
/* 766F8 800DD248 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 766FC 800DD24C C7B60090 */  lwc1      $f22, 0x90($sp)
/* 76700 800DD250 AFB5003C */  sw        $s5, 0x3c($sp)
/* 76704 800DD254 0080A82D */  daddu     $s5, $a0, $zero
/* 76708 800DD258 AFB70044 */  sw        $s7, 0x44($sp)
/* 7670C 800DD25C 00A0B82D */  daddu     $s7, $a1, $zero
/* 76710 800DD260 AFBE0048 */  sw        $fp, 0x48($sp)
/* 76714 800DD264 4600A502 */  mul.s     $f20, $f20, $f0
/* 76718 800DD268 00000000 */  nop       
/* 7671C 800DD26C 3C0143B4 */  lui       $at, 0x43b4
/* 76720 800DD270 44810000 */  mtc1      $at, $f0
/* 76724 800DD274 00C0F02D */  daddu     $fp, $a2, $zero
/* 76728 800DD278 AFBF004C */  sw        $ra, 0x4c($sp)
/* 7672C 800DD27C AFB40038 */  sw        $s4, 0x38($sp)
/* 76730 800DD280 AFB30034 */  sw        $s3, 0x34($sp)
/* 76734 800DD284 AFB20030 */  sw        $s2, 0x30($sp)
/* 76738 800DD288 AFB1002C */  sw        $s1, 0x2c($sp)
/* 7673C 800DD28C AFB00028 */  sw        $s0, 0x28($sp)
/* 76740 800DD290 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 76744 800DD294 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 76748 800DD298 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 7674C 800DD29C AFA70084 */  sw        $a3, 0x84($sp)
/* 76750 800DD2A0 4600A503 */  div.s     $f20, $f20, $f0
/* 76754 800DD2A4 0C00A85B */  jal       sin_rad
/* 76758 800DD2A8 4600A306 */   mov.s    $f12, $f20
/* 7675C 800DD2AC 4600B702 */  mul.s     $f28, $f22, $f0
/* 76760 800DD2B0 00000000 */  nop       
/* 76764 800DD2B4 2414FFFF */  addiu     $s4, $zero, -1
/* 76768 800DD2B8 4600A306 */  mov.s     $f12, $f20
/* 7676C 800DD2BC 0C00A874 */  jal       cos_rad
/* 76770 800DD2C0 4600B587 */   neg.s    $f22, $f22
/* 76774 800DD2C4 02A0202D */  daddu     $a0, $s5, $zero
/* 76778 800DD2C8 27B30018 */  addiu     $s3, $sp, 0x18
/* 7677C 800DD2CC 0260282D */  daddu     $a1, $s3, $zero
/* 76780 800DD2D0 27B2001C */  addiu     $s2, $sp, 0x1c
/* 76784 800DD2D4 0240302D */  daddu     $a2, $s2, $zero
/* 76788 800DD2D8 27B10020 */  addiu     $s1, $sp, 0x20
/* 7678C 800DD2DC 0220382D */  daddu     $a3, $s1, $zero
/* 76790 800DD2E0 4600B682 */  mul.s     $f26, $f22, $f0
/* 76794 800DD2E4 00000000 */  nop       
/* 76798 800DD2E8 C6F60000 */  lwc1      $f22, ($s7)
/* 7679C 800DD2EC C7D80000 */  lwc1      $f24, ($fp)
/* 767A0 800DD2F0 8FA30084 */  lw        $v1, 0x84($sp)
/* 767A4 800DD2F4 C6C00000 */  lwc1      $f0, ($s6)
/* 767A8 800DD2F8 C4740000 */  lwc1      $f20, ($v1)
/* 767AC 800DD2FC 461CB080 */  add.s     $f2, $f22, $f28
/* 767B0 800DD300 27B00024 */  addiu     $s0, $sp, 0x24
/* 767B4 800DD304 E7A00024 */  swc1      $f0, 0x24($sp)
/* 767B8 800DD308 461AA000 */  add.s     $f0, $f20, $f26
/* 767BC 800DD30C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 767C0 800DD310 E7A20018 */  swc1      $f2, 0x18($sp)
/* 767C4 800DD314 E7A00020 */  swc1      $f0, 0x20($sp)
/* 767C8 800DD318 0C037413 */  jal       func_800DD04C
/* 767CC 800DD31C AFB00010 */   sw       $s0, 0x10($sp)
/* 767D0 800DD320 04410025 */  bgez      $v0, .L800DD3B8
/* 767D4 800DD324 02A0202D */   daddu    $a0, $s5, $zero
/* 767D8 800DD328 0260282D */  daddu     $a1, $s3, $zero
/* 767DC 800DD32C 461CB081 */  sub.s     $f2, $f22, $f28
/* 767E0 800DD330 0240302D */  daddu     $a2, $s2, $zero
/* 767E4 800DD334 0220382D */  daddu     $a3, $s1, $zero
/* 767E8 800DD338 461AA001 */  sub.s     $f0, $f20, $f26
/* 767EC 800DD33C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 767F0 800DD340 E7A20018 */  swc1      $f2, 0x18($sp)
/* 767F4 800DD344 E7A00020 */  swc1      $f0, 0x20($sp)
/* 767F8 800DD348 0C037413 */  jal       func_800DD04C
/* 767FC 800DD34C AFB00010 */   sw       $s0, 0x10($sp)
/* 76800 800DD350 04410019 */  bgez      $v0, .L800DD3B8
/* 76804 800DD354 02A0202D */   daddu    $a0, $s5, $zero
/* 76808 800DD358 0260282D */  daddu     $a1, $s3, $zero
/* 7680C 800DD35C 461AB080 */  add.s     $f2, $f22, $f26
/* 76810 800DD360 0240302D */  daddu     $a2, $s2, $zero
/* 76814 800DD364 0220382D */  daddu     $a3, $s1, $zero
/* 76818 800DD368 461CA000 */  add.s     $f0, $f20, $f28
/* 7681C 800DD36C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 76820 800DD370 E7A20018 */  swc1      $f2, 0x18($sp)
/* 76824 800DD374 E7A00020 */  swc1      $f0, 0x20($sp)
/* 76828 800DD378 0C037413 */  jal       func_800DD04C
/* 7682C 800DD37C AFB00010 */   sw       $s0, 0x10($sp)
/* 76830 800DD380 0441000D */  bgez      $v0, .L800DD3B8
/* 76834 800DD384 02A0202D */   daddu    $a0, $s5, $zero
/* 76838 800DD388 0260282D */  daddu     $a1, $s3, $zero
/* 7683C 800DD38C 461AB081 */  sub.s     $f2, $f22, $f26
/* 76840 800DD390 0240302D */  daddu     $a2, $s2, $zero
/* 76844 800DD394 0220382D */  daddu     $a3, $s1, $zero
/* 76848 800DD398 461CA001 */  sub.s     $f0, $f20, $f28
/* 7684C 800DD39C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 76850 800DD3A0 E7A20018 */  swc1      $f2, 0x18($sp)
/* 76854 800DD3A4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 76858 800DD3A8 0C037413 */  jal       func_800DD04C
/* 7685C 800DD3AC AFB00010 */   sw       $s0, 0x10($sp)
/* 76860 800DD3B0 0440000B */  bltz      $v0, .L800DD3E0
/* 76864 800DD3B4 00000000 */   nop      
.L800DD3B8:
/* 76868 800DD3B8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7686C 800DD3BC E6E00000 */  swc1      $f0, ($s7)
/* 76870 800DD3C0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 76874 800DD3C4 E7C00000 */  swc1      $f0, ($fp)
/* 76878 800DD3C8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7687C 800DD3CC 8FA30084 */  lw        $v1, 0x84($sp)
/* 76880 800DD3D0 E4600000 */  swc1      $f0, ($v1)
/* 76884 800DD3D4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 76888 800DD3D8 0040A02D */  daddu     $s4, $v0, $zero
/* 7688C 800DD3DC E6C00000 */  swc1      $f0, ($s6)
.L800DD3E0:
/* 76890 800DD3E0 06810009 */  bgez      $s4, .L800DD408
/* 76894 800DD3E4 0280102D */   daddu    $v0, $s4, $zero
/* 76898 800DD3E8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 7689C 800DD3EC E6E00000 */  swc1      $f0, ($s7)
/* 768A0 800DD3F0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 768A4 800DD3F4 E7C00000 */  swc1      $f0, ($fp)
/* 768A8 800DD3F8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 768AC 800DD3FC 8FA30084 */  lw        $v1, 0x84($sp)
/* 768B0 800DD400 E4600000 */  swc1      $f0, ($v1)
/* 768B4 800DD404 AEC00000 */  sw        $zero, ($s6)
.L800DD408:
/* 768B8 800DD408 8FBF004C */  lw        $ra, 0x4c($sp)
/* 768BC 800DD40C 8FBE0048 */  lw        $fp, 0x48($sp)
/* 768C0 800DD410 8FB70044 */  lw        $s7, 0x44($sp)
/* 768C4 800DD414 8FB60040 */  lw        $s6, 0x40($sp)
/* 768C8 800DD418 8FB5003C */  lw        $s5, 0x3c($sp)
/* 768CC 800DD41C 8FB40038 */  lw        $s4, 0x38($sp)
/* 768D0 800DD420 8FB30034 */  lw        $s3, 0x34($sp)
/* 768D4 800DD424 8FB20030 */  lw        $s2, 0x30($sp)
/* 768D8 800DD428 8FB1002C */  lw        $s1, 0x2c($sp)
/* 768DC 800DD42C 8FB00028 */  lw        $s0, 0x28($sp)
/* 768E0 800DD430 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 768E4 800DD434 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 768E8 800DD438 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 768EC 800DD43C D7B60058 */  ldc1      $f22, 0x58($sp)
/* 768F0 800DD440 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 768F4 800DD444 03E00008 */  jr        $ra
/* 768F8 800DD448 27BD0078 */   addiu    $sp, $sp, 0x78
