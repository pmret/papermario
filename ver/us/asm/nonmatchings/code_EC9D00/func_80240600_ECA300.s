.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240600_ECA300
/* ECA300 80240600 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* ECA304 80240604 AFB60040 */  sw        $s6, 0x40($sp)
/* ECA308 80240608 0080B02D */  daddu     $s6, $a0, $zero
/* ECA30C 8024060C AFB00028 */  sw        $s0, 0x28($sp)
/* ECA310 80240610 00A0802D */  daddu     $s0, $a1, $zero
/* ECA314 80240614 AFBF0044 */  sw        $ra, 0x44($sp)
/* ECA318 80240618 AFB5003C */  sw        $s5, 0x3c($sp)
/* ECA31C 8024061C AFB40038 */  sw        $s4, 0x38($sp)
/* ECA320 80240620 AFB30034 */  sw        $s3, 0x34($sp)
/* ECA324 80240624 AFB20030 */  sw        $s2, 0x30($sp)
/* ECA328 80240628 AFB1002C */  sw        $s1, 0x2c($sp)
/* ECA32C 8024062C F7B80058 */  sdc1      $f24, 0x58($sp)
/* ECA330 80240630 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ECA334 80240634 F7B40048 */  sdc1      $f20, 0x48($sp)
/* ECA338 80240638 8ED3000C */  lw        $s3, 0xc($s6)
/* ECA33C 8024063C 0C00F94D */  jal       func_8003E534
/* ECA340 80240640 2404FFFC */   addiu    $a0, $zero, -4
/* ECA344 80240644 27A50018 */  addiu     $a1, $sp, 0x18
/* ECA348 80240648 3C048008 */  lui       $a0, %hi(D_8007C760)
/* ECA34C 8024064C 8C84C760 */  lw        $a0, %lo(D_8007C760)($a0)
/* ECA350 80240650 27A6001C */  addiu     $a2, $sp, 0x1c
/* ECA354 80240654 00041880 */  sll       $v1, $a0, 2
/* ECA358 80240658 00641821 */  addu      $v1, $v1, $a0
/* ECA35C 8024065C 00031880 */  sll       $v1, $v1, 2
/* ECA360 80240660 00641823 */  subu      $v1, $v1, $a0
/* ECA364 80240664 000320C0 */  sll       $a0, $v1, 3
/* ECA368 80240668 00641821 */  addu      $v1, $v1, $a0
/* ECA36C 8024066C 000318C0 */  sll       $v1, $v1, 3
/* ECA370 80240670 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* ECA374 80240674 00230821 */  addu      $at, $at, $v1
/* ECA378 80240678 C42C8DEC */  lwc1      $f12, %lo(D_800B8DEC)($at)
/* ECA37C 8024067C 0C00AD49 */  jal       func_8002B524
/* ECA380 80240680 0040A82D */   daddu    $s5, $v0, $zero
/* ECA384 80240684 1200005D */  beqz      $s0, .L802407FC
/* ECA388 80240688 00000000 */   nop
/* ECA38C 8024068C 0C00AFC6 */  jal       func_8002BF18
/* ECA390 80240690 24040068 */   addiu    $a0, $zero, 0x68
/* ECA394 80240694 0040902D */  daddu     $s2, $v0, $zero
/* ECA398 80240698 02C0202D */  daddu     $a0, $s6, $zero
/* ECA39C 8024069C 0000882D */  daddu     $s1, $zero, $zero
/* ECA3A0 802406A0 2414FFFF */  addiu     $s4, $zero, -1
/* ECA3A4 802406A4 AED20060 */  sw        $s2, 0x60($s6)
/* ECA3A8 802406A8 8E650000 */  lw        $a1, ($s3)
/* ECA3AC 802406AC 3C014148 */  lui       $at, 0x4148
/* ECA3B0 802406B0 4481C000 */  mtc1      $at, $f24
/* ECA3B4 802406B4 3C013F80 */  lui       $at, 0x3f80
/* ECA3B8 802406B8 4481B000 */  mtc1      $at, $f22
/* ECA3BC 802406BC 4480A000 */  mtc1      $zero, $f20
/* ECA3C0 802406C0 0C0B53A3 */  jal       dead_get_variable
/* ECA3C4 802406C4 0240802D */   daddu    $s0, $s2, $zero
/* ECA3C8 802406C8 0C0462EC */  jal       func_80118BB0
/* ECA3CC 802406CC 0040202D */   daddu    $a0, $v0, $zero
/* ECA3D0 802406D0 AE42005C */  sw        $v0, 0x5c($s2)
.L802406D4:
/* ECA3D4 802406D4 8E42005C */  lw        $v0, 0x5c($s2)
/* ECA3D8 802406D8 C440004C */  lwc1      $f0, 0x4c($v0)
/* ECA3DC 802406DC 0000202D */  daddu     $a0, $zero, $zero
/* ECA3E0 802406E0 E7B60010 */  swc1      $f22, 0x10($sp)
/* ECA3E4 802406E4 AFB40014 */  sw        $s4, 0x14($sp)
/* ECA3E8 802406E8 46180000 */  add.s     $f0, $f0, $f24
/* ECA3EC 802406EC 8C450048 */  lw        $a1, 0x48($v0)
/* ECA3F0 802406F0 8C470050 */  lw        $a3, 0x50($v0)
/* ECA3F4 802406F4 44060000 */  mfc1      $a2, $f0
/* ECA3F8 802406F8 0C01DA5C */  jal       func_80076970
/* ECA3FC 802406FC 26310001 */   addiu    $s1, $s1, 1
/* ECA400 80240700 AE020008 */  sw        $v0, 8($s0)
/* ECA404 80240704 E614002C */  swc1      $f20, 0x2c($s0)
/* ECA408 80240708 E6140020 */  swc1      $f20, 0x20($s0)
/* ECA40C 8024070C E6140014 */  swc1      $f20, 0x14($s0)
/* ECA410 80240710 E6140050 */  swc1      $f20, 0x50($s0)
/* ECA414 80240714 E6140044 */  swc1      $f20, 0x44($s0)
/* ECA418 80240718 E6140038 */  swc1      $f20, 0x38($s0)
/* ECA41C 8024071C 2A220003 */  slti      $v0, $s1, 3
/* ECA420 80240720 1440FFEC */  bnez      $v0, .L802406D4
/* ECA424 80240724 26100004 */   addiu    $s0, $s0, 4
/* ECA428 80240728 0000882D */  daddu     $s1, $zero, $zero
/* ECA42C 8024072C 0240802D */  daddu     $s0, $s2, $zero
/* ECA430 80240730 3C148024 */  lui       $s4, %hi(D_80242038_ECBD38)
/* ECA434 80240734 26942038 */  addiu     $s4, $s4, %lo(D_80242038_ECBD38)
/* ECA438 80240738 3C014248 */  lui       $at, 0x4248
/* ECA43C 8024073C 4481A000 */  mtc1      $at, $f20
/* ECA440 80240740 24130044 */  addiu     $s3, $zero, 0x44
/* ECA444 80240744 AE400000 */  sw        $zero, ($s2)
/* ECA448 80240748 AE400004 */  sw        $zero, 4($s2)
/* ECA44C 8024074C AE400060 */  sw        $zero, 0x60($s2)
/* ECA450 80240750 AE400064 */  sw        $zero, 0x64($s2)
.L80240754:
/* ECA454 80240754 27A40020 */  addiu     $a0, $sp, 0x20
/* ECA458 80240758 4406A000 */  mfc1      $a2, $f20
/* ECA45C 8024075C 8E870000 */  lw        $a3, ($s4)
/* ECA460 80240760 02532821 */  addu      $a1, $s2, $s3
/* ECA464 80240764 0C00ACA3 */  jal       func_8002B28C
/* ECA468 80240768 AFA00020 */   sw       $zero, 0x20($sp)
/* ECA46C 8024076C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* ECA470 80240770 C7A40020 */  lwc1      $f4, 0x20($sp)
/* ECA474 80240774 46041082 */  mul.s     $f2, $f2, $f4
/* ECA478 80240778 00000000 */  nop
/* ECA47C 8024077C C7A00018 */  lwc1      $f0, 0x18($sp)
/* ECA480 80240780 46040002 */  mul.s     $f0, $f0, $f4
/* ECA484 80240784 00000000 */  nop
/* ECA488 80240788 E6020038 */  swc1      $f2, 0x38($s0)
/* ECA48C 8024078C E6000050 */  swc1      $f0, 0x50($s0)
/* ECA490 80240790 8E42005C */  lw        $v0, 0x5c($s2)
/* ECA494 80240794 C6000038 */  lwc1      $f0, 0x38($s0)
/* ECA498 80240798 C4420048 */  lwc1      $f2, 0x48($v0)
/* ECA49C 8024079C 46001080 */  add.s     $f2, $f2, $f0
/* ECA4A0 802407A0 C6A00038 */  lwc1      $f0, 0x38($s5)
/* ECA4A4 802407A4 46020001 */  sub.s     $f0, $f0, $f2
/* ECA4A8 802407A8 E6000038 */  swc1      $f0, 0x38($s0)
/* ECA4AC 802407AC 8E42005C */  lw        $v0, 0x5c($s2)
/* ECA4B0 802407B0 C6000044 */  lwc1      $f0, 0x44($s0)
/* ECA4B4 802407B4 C442004C */  lwc1      $f2, 0x4c($v0)
/* ECA4B8 802407B8 46001080 */  add.s     $f2, $f2, $f0
/* ECA4BC 802407BC C6A0003C */  lwc1      $f0, 0x3c($s5)
/* ECA4C0 802407C0 46020001 */  sub.s     $f0, $f0, $f2
/* ECA4C4 802407C4 E6000044 */  swc1      $f0, 0x44($s0)
/* ECA4C8 802407C8 8E42005C */  lw        $v0, 0x5c($s2)
/* ECA4CC 802407CC C6000050 */  lwc1      $f0, 0x50($s0)
/* ECA4D0 802407D0 C4420050 */  lwc1      $f2, 0x50($v0)
/* ECA4D4 802407D4 26940004 */  addiu     $s4, $s4, 4
/* ECA4D8 802407D8 46001080 */  add.s     $f2, $f2, $f0
/* ECA4DC 802407DC C6A00040 */  lwc1      $f0, 0x40($s5)
/* ECA4E0 802407E0 26730004 */  addiu     $s3, $s3, 4
/* ECA4E4 802407E4 46020001 */  sub.s     $f0, $f0, $f2
/* ECA4E8 802407E8 26310001 */  addiu     $s1, $s1, 1
/* ECA4EC 802407EC 2A220003 */  slti      $v0, $s1, 3
/* ECA4F0 802407F0 E6000050 */  swc1      $f0, 0x50($s0)
/* ECA4F4 802407F4 1440FFD7 */  bnez      $v0, .L80240754
/* ECA4F8 802407F8 26100004 */   addiu    $s0, $s0, 4
.L802407FC:
/* ECA4FC 802407FC 8ED20060 */  lw        $s2, 0x60($s6)
/* ECA500 80240800 8E430000 */  lw        $v1, ($s2)
/* ECA504 80240804 24020001 */  addiu     $v0, $zero, 1
/* ECA508 80240808 10620038 */  beq       $v1, $v0, .L802408EC
/* ECA50C 8024080C 28620002 */   slti     $v0, $v1, 2
/* ECA510 80240810 50400005 */  beql      $v0, $zero, .L80240828
/* ECA514 80240814 24020002 */   addiu    $v0, $zero, 2
/* ECA518 80240818 10600007 */  beqz      $v1, .L80240838
/* ECA51C 8024081C 24040005 */   addiu    $a0, $zero, 5
/* ECA520 80240820 08090274 */  j         .L802409D0
/* ECA524 80240824 00000000 */   nop
.L80240828:
/* ECA528 80240828 10620058 */  beq       $v1, $v0, .L8024098C
/* ECA52C 8024082C 00000000 */   nop
/* ECA530 80240830 08090274 */  j         .L802409D0
/* ECA534 80240834 00000000 */   nop
.L80240838:
/* ECA538 80240838 0000882D */  daddu     $s1, $zero, $zero
/* ECA53C 8024083C 3C148024 */  lui       $s4, %hi(D_80242038_ECBD38)
/* ECA540 80240840 26942038 */  addiu     $s4, $s4, %lo(D_80242038_ECBD38)
/* ECA544 80240844 24130020 */  addiu     $s3, $zero, 0x20
/* ECA548 80240848 3C064248 */  lui       $a2, 0x4248
/* ECA54C 8024084C 44800000 */  mtc1      $zero, $f0
/* ECA550 80240850 24020014 */  addiu     $v0, $zero, 0x14
/* ECA554 80240854 AFA20010 */  sw        $v0, 0x10($sp)
/* ECA558 80240858 44050000 */  mfc1      $a1, $f0
/* ECA55C 8024085C 8E470060 */  lw        $a3, 0x60($s2)
/* ECA560 80240860 4485B000 */  mtc1      $a1, $f22
/* ECA564 80240864 0C00ADA9 */  jal       func_8002B6A4
/* ECA568 80240868 0240802D */   daddu    $s0, $s2, $zero
/* ECA56C 8024086C 46000506 */  mov.s     $f20, $f0
.L80240870:
/* ECA570 80240870 4406A000 */  mfc1      $a2, $f20
/* ECA574 80240874 27A40020 */  addiu     $a0, $sp, 0x20
/* ECA578 80240878 E6160020 */  swc1      $f22, 0x20($s0)
/* ECA57C 8024087C 8E870000 */  lw        $a3, ($s4)
/* ECA580 80240880 02532821 */  addu      $a1, $s2, $s3
/* ECA584 80240884 0C00ACA3 */  jal       func_8002B28C
/* ECA588 80240888 E7B60020 */   swc1     $f22, 0x20($sp)
/* ECA58C 8024088C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* ECA590 80240890 C7A00020 */  lwc1      $f0, 0x20($sp)
/* ECA594 80240894 46002102 */  mul.s     $f4, $f4, $f0
/* ECA598 80240898 00000000 */  nop
/* ECA59C 8024089C C7A20018 */  lwc1      $f2, 0x18($sp)
/* ECA5A0 802408A0 26940004 */  addiu     $s4, $s4, 4
/* ECA5A4 802408A4 46001082 */  mul.s     $f2, $f2, $f0
/* ECA5A8 802408A8 00000000 */  nop
/* ECA5AC 802408AC 26730004 */  addiu     $s3, $s3, 4
/* ECA5B0 802408B0 26310001 */  addiu     $s1, $s1, 1
/* ECA5B4 802408B4 2A220003 */  slti      $v0, $s1, 3
/* ECA5B8 802408B8 E6040014 */  swc1      $f4, 0x14($s0)
/* ECA5BC 802408BC E602002C */  swc1      $f2, 0x2c($s0)
/* ECA5C0 802408C0 1440FFEB */  bnez      $v0, .L80240870
/* ECA5C4 802408C4 26100004 */   addiu    $s0, $s0, 4
/* ECA5C8 802408C8 8E420060 */  lw        $v0, 0x60($s2)
/* ECA5CC 802408CC 24420001 */  addiu     $v0, $v0, 1
/* ECA5D0 802408D0 AE420060 */  sw        $v0, 0x60($s2)
/* ECA5D4 802408D4 28420015 */  slti      $v0, $v0, 0x15
/* ECA5D8 802408D8 1440003D */  bnez      $v0, .L802409D0
/* ECA5DC 802408DC 24020001 */   addiu    $v0, $zero, 1
/* ECA5E0 802408E0 AE420000 */  sw        $v0, ($s2)
/* ECA5E4 802408E4 08090274 */  j         .L802409D0
/* ECA5E8 802408E8 AE400060 */   sw       $zero, 0x60($s2)
.L802408EC:
/* ECA5EC 802408EC 0000882D */  daddu     $s1, $zero, $zero
/* ECA5F0 802408F0 3C148024 */  lui       $s4, %hi(D_80242038_ECBD38)
/* ECA5F4 802408F4 26942038 */  addiu     $s4, $s4, %lo(D_80242038_ECBD38)
/* ECA5F8 802408F8 24130020 */  addiu     $s3, $zero, 0x20
/* ECA5FC 802408FC 0240802D */  daddu     $s0, $s2, $zero
/* ECA600 80240900 3C014248 */  lui       $at, 0x4248
/* ECA604 80240904 4481A000 */  mtc1      $at, $f20
/* ECA608 80240908 4480B000 */  mtc1      $zero, $f22
.L8024090C:
/* ECA60C 8024090C 4406A000 */  mfc1      $a2, $f20
/* ECA610 80240910 27A40020 */  addiu     $a0, $sp, 0x20
/* ECA614 80240914 E6160020 */  swc1      $f22, 0x20($s0)
/* ECA618 80240918 8E870000 */  lw        $a3, ($s4)
/* ECA61C 8024091C 02532821 */  addu      $a1, $s2, $s3
/* ECA620 80240920 0C00ACA3 */  jal       func_8002B28C
/* ECA624 80240924 E7B60020 */   swc1     $f22, 0x20($sp)
/* ECA628 80240928 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* ECA62C 8024092C C7A00020 */  lwc1      $f0, 0x20($sp)
/* ECA630 80240930 46002102 */  mul.s     $f4, $f4, $f0
/* ECA634 80240934 00000000 */  nop
/* ECA638 80240938 C7A20018 */  lwc1      $f2, 0x18($sp)
/* ECA63C 8024093C 26940004 */  addiu     $s4, $s4, 4
/* ECA640 80240940 46001082 */  mul.s     $f2, $f2, $f0
/* ECA644 80240944 00000000 */  nop
/* ECA648 80240948 26730004 */  addiu     $s3, $s3, 4
/* ECA64C 8024094C 26310001 */  addiu     $s1, $s1, 1
/* ECA650 80240950 2A220003 */  slti      $v0, $s1, 3
/* ECA654 80240954 E6040014 */  swc1      $f4, 0x14($s0)
/* ECA658 80240958 E602002C */  swc1      $f2, 0x2c($s0)
/* ECA65C 8024095C 1440FFEB */  bnez      $v0, .L8024090C
/* ECA660 80240960 26100004 */   addiu    $s0, $s0, 4
/* ECA664 80240964 8E420060 */  lw        $v0, 0x60($s2)
/* ECA668 80240968 24420001 */  addiu     $v0, $v0, 1
/* ECA66C 8024096C AE420060 */  sw        $v0, 0x60($s2)
/* ECA670 80240970 28420010 */  slti      $v0, $v0, 0x10
/* ECA674 80240974 14400016 */  bnez      $v0, .L802409D0
/* ECA678 80240978 2402000F */   addiu    $v0, $zero, 0xf
/* ECA67C 8024097C AE420060 */  sw        $v0, 0x60($s2)
/* ECA680 80240980 24020002 */  addiu     $v0, $zero, 2
/* ECA684 80240984 08090274 */  j         .L802409D0
/* ECA688 80240988 AE420000 */   sw       $v0, ($s2)
.L8024098C:
/* ECA68C 8024098C 8E420060 */  lw        $v0, 0x60($s2)
/* ECA690 80240990 24420001 */  addiu     $v0, $v0, 1
/* ECA694 80240994 AE420060 */  sw        $v0, 0x60($s2)
/* ECA698 80240998 2842001F */  slti      $v0, $v0, 0x1f
/* ECA69C 8024099C 1440000C */  bnez      $v0, .L802409D0
/* ECA6A0 802409A0 0000882D */   daddu    $s1, $zero, $zero
/* ECA6A4 802409A4 0240282D */  daddu     $a1, $s2, $zero
.L802409A8:
/* ECA6A8 802409A8 8CA20008 */  lw        $v0, 8($a1)
/* ECA6AC 802409AC 8C430000 */  lw        $v1, ($v0)
/* ECA6B0 802409B0 26310001 */  addiu     $s1, $s1, 1
/* ECA6B4 802409B4 34630010 */  ori       $v1, $v1, 0x10
/* ECA6B8 802409B8 AC430000 */  sw        $v1, ($v0)
/* ECA6BC 802409BC 2A220003 */  slti      $v0, $s1, 3
/* ECA6C0 802409C0 1440FFF9 */  bnez      $v0, .L802409A8
/* ECA6C4 802409C4 24A50004 */   addiu    $a1, $a1, 4
/* ECA6C8 802409C8 080902C1 */  j         .L80240B04
/* ECA6CC 802409CC 24020002 */   addiu    $v0, $zero, 2
.L802409D0:
/* ECA6D0 802409D0 8E430004 */  lw        $v1, 4($s2)
/* ECA6D4 802409D4 10600005 */  beqz      $v1, .L802409EC
/* ECA6D8 802409D8 24020001 */   addiu    $v0, $zero, 1
/* ECA6DC 802409DC 1062000B */  beq       $v1, $v0, .L80240A0C
/* ECA6E0 802409E0 0000882D */   daddu    $s1, $zero, $zero
/* ECA6E4 802409E4 080902B0 */  j         .L80240AC0
/* ECA6E8 802409E8 0240282D */   daddu    $a1, $s2, $zero
.L802409EC:
/* ECA6EC 802409EC 8E420064 */  lw        $v0, 0x64($s2)
/* ECA6F0 802409F0 24420001 */  addiu     $v0, $v0, 1
/* ECA6F4 802409F4 AE420064 */  sw        $v0, 0x64($s2)
/* ECA6F8 802409F8 28420010 */  slti      $v0, $v0, 0x10
/* ECA6FC 802409FC 1440002F */  bnez      $v0, .L80240ABC
/* ECA700 80240A00 0000882D */   daddu    $s1, $zero, $zero
/* ECA704 80240A04 080902AC */  j         .L80240AB0
/* ECA708 80240A08 24020001 */   addiu    $v0, $zero, 1
.L80240A0C:
/* ECA70C 80240A0C 4480A000 */  mtc1      $zero, $f20
/* ECA710 80240A10 24130014 */  addiu     $s3, $zero, 0x14
/* ECA714 80240A14 0240802D */  daddu     $s0, $s2, $zero
.L80240A18:
/* ECA718 80240A18 4405A000 */  mfc1      $a1, $f20
/* ECA71C 80240A1C AFB30010 */  sw        $s3, 0x10($sp)
/* ECA720 80240A20 8E060038 */  lw        $a2, 0x38($s0)
/* ECA724 80240A24 8E470064 */  lw        $a3, 0x64($s2)
/* ECA728 80240A28 0C00ADA9 */  jal       func_8002B6A4
/* ECA72C 80240A2C 24040001 */   addiu    $a0, $zero, 1
/* ECA730 80240A30 C6020014 */  lwc1      $f2, 0x14($s0)
/* ECA734 80240A34 46001080 */  add.s     $f2, $f2, $f0
/* ECA738 80240A38 4405A000 */  mfc1      $a1, $f20
/* ECA73C 80240A3C E6020014 */  swc1      $f2, 0x14($s0)
/* ECA740 80240A40 AFB30010 */  sw        $s3, 0x10($sp)
/* ECA744 80240A44 8E060044 */  lw        $a2, 0x44($s0)
/* ECA748 80240A48 8E470064 */  lw        $a3, 0x64($s2)
/* ECA74C 80240A4C 0C00ADA9 */  jal       func_8002B6A4
/* ECA750 80240A50 24040001 */   addiu    $a0, $zero, 1
/* ECA754 80240A54 C6020020 */  lwc1      $f2, 0x20($s0)
/* ECA758 80240A58 46001080 */  add.s     $f2, $f2, $f0
/* ECA75C 80240A5C 4405A000 */  mfc1      $a1, $f20
/* ECA760 80240A60 E6020020 */  swc1      $f2, 0x20($s0)
/* ECA764 80240A64 AFB30010 */  sw        $s3, 0x10($sp)
/* ECA768 80240A68 8E060050 */  lw        $a2, 0x50($s0)
/* ECA76C 80240A6C 8E470064 */  lw        $a3, 0x64($s2)
/* ECA770 80240A70 0C00ADA9 */  jal       func_8002B6A4
/* ECA774 80240A74 24040001 */   addiu    $a0, $zero, 1
/* ECA778 80240A78 C602002C */  lwc1      $f2, 0x2c($s0)
/* ECA77C 80240A7C 46001080 */  add.s     $f2, $f2, $f0
/* ECA780 80240A80 26310001 */  addiu     $s1, $s1, 1
/* ECA784 80240A84 2A220003 */  slti      $v0, $s1, 3
/* ECA788 80240A88 E602002C */  swc1      $f2, 0x2c($s0)
/* ECA78C 80240A8C 1440FFE2 */  bnez      $v0, .L80240A18
/* ECA790 80240A90 26100004 */   addiu    $s0, $s0, 4
/* ECA794 80240A94 8E420064 */  lw        $v0, 0x64($s2)
/* ECA798 80240A98 24420001 */  addiu     $v0, $v0, 1
/* ECA79C 80240A9C AE420064 */  sw        $v0, 0x64($s2)
/* ECA7A0 80240AA0 28420015 */  slti      $v0, $v0, 0x15
/* ECA7A4 80240AA4 14400005 */  bnez      $v0, .L80240ABC
/* ECA7A8 80240AA8 0000882D */   daddu    $s1, $zero, $zero
/* ECA7AC 80240AAC 24020002 */  addiu     $v0, $zero, 2
.L80240AB0:
/* ECA7B0 80240AB0 AE420004 */  sw        $v0, 4($s2)
/* ECA7B4 80240AB4 AE400064 */  sw        $zero, 0x64($s2)
/* ECA7B8 80240AB8 0000882D */  daddu     $s1, $zero, $zero
.L80240ABC:
/* ECA7BC 80240ABC 0240282D */  daddu     $a1, $s2, $zero
.L80240AC0:
/* ECA7C0 80240AC0 8CA20008 */  lw        $v0, 8($a1)
/* ECA7C4 80240AC4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* ECA7C8 80240AC8 8C42000C */  lw        $v0, 0xc($v0)
/* ECA7CC 80240ACC E4400010 */  swc1      $f0, 0x10($v0)
/* ECA7D0 80240AD0 8CA20008 */  lw        $v0, 8($a1)
/* ECA7D4 80240AD4 C4A00020 */  lwc1      $f0, 0x20($a1)
/* ECA7D8 80240AD8 8C42000C */  lw        $v0, 0xc($v0)
/* ECA7DC 80240ADC 26310001 */  addiu     $s1, $s1, 1
/* ECA7E0 80240AE0 E4400014 */  swc1      $f0, 0x14($v0)
/* ECA7E4 80240AE4 8CA20008 */  lw        $v0, 8($a1)
/* ECA7E8 80240AE8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* ECA7EC 80240AEC 8C42000C */  lw        $v0, 0xc($v0)
/* ECA7F0 80240AF0 E4400018 */  swc1      $f0, 0x18($v0)
/* ECA7F4 80240AF4 2A220003 */  slti      $v0, $s1, 3
/* ECA7F8 80240AF8 1440FFF1 */  bnez      $v0, .L80240AC0
/* ECA7FC 80240AFC 24A50004 */   addiu    $a1, $a1, 4
/* ECA800 80240B00 0000102D */  daddu     $v0, $zero, $zero
.L80240B04:
/* ECA804 80240B04 8FBF0044 */  lw        $ra, 0x44($sp)
/* ECA808 80240B08 8FB60040 */  lw        $s6, 0x40($sp)
/* ECA80C 80240B0C 8FB5003C */  lw        $s5, 0x3c($sp)
/* ECA810 80240B10 8FB40038 */  lw        $s4, 0x38($sp)
/* ECA814 80240B14 8FB30034 */  lw        $s3, 0x34($sp)
/* ECA818 80240B18 8FB20030 */  lw        $s2, 0x30($sp)
/* ECA81C 80240B1C 8FB1002C */  lw        $s1, 0x2c($sp)
/* ECA820 80240B20 8FB00028 */  lw        $s0, 0x28($sp)
/* ECA824 80240B24 D7B80058 */  ldc1      $f24, 0x58($sp)
/* ECA828 80240B28 D7B60050 */  ldc1      $f22, 0x50($sp)
/* ECA82C 80240B2C D7B40048 */  ldc1      $f20, 0x48($sp)
/* ECA830 80240B30 03E00008 */  jr        $ra
/* ECA834 80240B34 27BD0060 */   addiu    $sp, $sp, 0x60
