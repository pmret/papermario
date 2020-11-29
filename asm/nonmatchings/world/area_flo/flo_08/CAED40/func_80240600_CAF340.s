.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240600_CAF340
/* CAF340 80240600 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* CAF344 80240604 AFB60040 */  sw        $s6, 0x40($sp)
/* CAF348 80240608 0080B02D */  daddu     $s6, $a0, $zero
/* CAF34C 8024060C AFB00028 */  sw        $s0, 0x28($sp)
/* CAF350 80240610 00A0802D */  daddu     $s0, $a1, $zero
/* CAF354 80240614 AFBF0044 */  sw        $ra, 0x44($sp)
/* CAF358 80240618 AFB5003C */  sw        $s5, 0x3c($sp)
/* CAF35C 8024061C AFB40038 */  sw        $s4, 0x38($sp)
/* CAF360 80240620 AFB30034 */  sw        $s3, 0x34($sp)
/* CAF364 80240624 AFB20030 */  sw        $s2, 0x30($sp)
/* CAF368 80240628 AFB1002C */  sw        $s1, 0x2c($sp)
/* CAF36C 8024062C F7B80058 */  sdc1      $f24, 0x58($sp)
/* CAF370 80240630 F7B60050 */  sdc1      $f22, 0x50($sp)
/* CAF374 80240634 F7B40048 */  sdc1      $f20, 0x48($sp)
/* CAF378 80240638 8ED3000C */  lw        $s3, 0xc($s6)
/* CAF37C 8024063C 0C00EAD2 */  jal       get_npc_safe
/* CAF380 80240640 2404FFFC */   addiu    $a0, $zero, -4
/* CAF384 80240644 27A50018 */  addiu     $a1, $sp, 0x18
/* CAF388 80240648 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* CAF38C 8024064C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* CAF390 80240650 27A6001C */  addiu     $a2, $sp, 0x1c
/* CAF394 80240654 00041880 */  sll       $v1, $a0, 2
/* CAF398 80240658 00641821 */  addu      $v1, $v1, $a0
/* CAF39C 8024065C 00031880 */  sll       $v1, $v1, 2
/* CAF3A0 80240660 00641823 */  subu      $v1, $v1, $a0
/* CAF3A4 80240664 000320C0 */  sll       $a0, $v1, 3
/* CAF3A8 80240668 00641821 */  addu      $v1, $v1, $a0
/* CAF3AC 8024066C 000318C0 */  sll       $v1, $v1, 3
/* CAF3B0 80240670 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* CAF3B4 80240674 00230821 */  addu      $at, $at, $v1
/* CAF3B8 80240678 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* CAF3BC 8024067C 0C00A88D */  jal       sin_cos_deg
/* CAF3C0 80240680 0040A82D */   daddu    $s5, $v0, $zero
/* CAF3C4 80240684 1200005D */  beqz      $s0, .L802407FC
/* CAF3C8 80240688 00000000 */   nop      
/* CAF3CC 8024068C 0C00AB0A */  jal       general_heap_malloc
/* CAF3D0 80240690 24040068 */   addiu    $a0, $zero, 0x68
/* CAF3D4 80240694 0040902D */  daddu     $s2, $v0, $zero
/* CAF3D8 80240698 02C0202D */  daddu     $a0, $s6, $zero
/* CAF3DC 8024069C 0000882D */  daddu     $s1, $zero, $zero
/* CAF3E0 802406A0 2414FFFF */  addiu     $s4, $zero, -1
/* CAF3E4 802406A4 AED20060 */  sw        $s2, 0x60($s6)
/* CAF3E8 802406A8 8E650000 */  lw        $a1, ($s3)
/* CAF3EC 802406AC 3C014148 */  lui       $at, 0x4148
/* CAF3F0 802406B0 4481C000 */  mtc1      $at, $f24
/* CAF3F4 802406B4 3C013F80 */  lui       $at, 0x3f80
/* CAF3F8 802406B8 4481B000 */  mtc1      $at, $f22
/* CAF3FC 802406BC 4480A000 */  mtc1      $zero, $f20
/* CAF400 802406C0 0C0B1EAF */  jal       get_variable
/* CAF404 802406C4 0240802D */   daddu    $s0, $s2, $zero
/* CAF408 802406C8 0C04417A */  jal       get_entity_by_index
/* CAF40C 802406CC 0040202D */   daddu    $a0, $v0, $zero
/* CAF410 802406D0 AE42005C */  sw        $v0, 0x5c($s2)
.L802406D4:
/* CAF414 802406D4 8E42005C */  lw        $v0, 0x5c($s2)
/* CAF418 802406D8 C440004C */  lwc1      $f0, 0x4c($v0)
/* CAF41C 802406DC 0000202D */  daddu     $a0, $zero, $zero
/* CAF420 802406E0 E7B60010 */  swc1      $f22, 0x10($sp)
/* CAF424 802406E4 AFB40014 */  sw        $s4, 0x14($sp)
/* CAF428 802406E8 46180000 */  add.s     $f0, $f0, $f24
/* CAF42C 802406EC 8C450048 */  lw        $a1, 0x48($v0)
/* CAF430 802406F0 8C470050 */  lw        $a3, 0x50($v0)
/* CAF434 802406F4 44060000 */  mfc1      $a2, $f0
/* CAF438 802406F8 0C01C5BC */  jal       func_800716F0
/* CAF43C 802406FC 26310001 */   addiu    $s1, $s1, 1
/* CAF440 80240700 AE020008 */  sw        $v0, 8($s0)
/* CAF444 80240704 E614002C */  swc1      $f20, 0x2c($s0)
/* CAF448 80240708 E6140020 */  swc1      $f20, 0x20($s0)
/* CAF44C 8024070C E6140014 */  swc1      $f20, 0x14($s0)
/* CAF450 80240710 E6140050 */  swc1      $f20, 0x50($s0)
/* CAF454 80240714 E6140044 */  swc1      $f20, 0x44($s0)
/* CAF458 80240718 E6140038 */  swc1      $f20, 0x38($s0)
/* CAF45C 8024071C 2A220003 */  slti      $v0, $s1, 3
/* CAF460 80240720 1440FFEC */  bnez      $v0, .L802406D4
/* CAF464 80240724 26100004 */   addiu    $s0, $s0, 4
/* CAF468 80240728 0000882D */  daddu     $s1, $zero, $zero
/* CAF46C 8024072C 0240802D */  daddu     $s0, $s2, $zero
/* CAF470 80240730 3C148024 */  lui       $s4, %hi(D_80242008)
/* CAF474 80240734 26942008 */  addiu     $s4, $s4, %lo(D_80242008)
/* CAF478 80240738 3C014248 */  lui       $at, 0x4248
/* CAF47C 8024073C 4481A000 */  mtc1      $at, $f20
/* CAF480 80240740 24130044 */  addiu     $s3, $zero, 0x44
/* CAF484 80240744 AE400000 */  sw        $zero, ($s2)
/* CAF488 80240748 AE400004 */  sw        $zero, 4($s2)
/* CAF48C 8024074C AE400060 */  sw        $zero, 0x60($s2)
/* CAF490 80240750 AE400064 */  sw        $zero, 0x64($s2)
.L80240754:
/* CAF494 80240754 27A40020 */  addiu     $a0, $sp, 0x20
/* CAF498 80240758 4406A000 */  mfc1      $a2, $f20
/* CAF49C 8024075C 8E870000 */  lw        $a3, ($s4)
/* CAF4A0 80240760 02532821 */  addu      $a1, $s2, $s3
/* CAF4A4 80240764 0C00A7E7 */  jal       add_vec2D_polar
/* CAF4A8 80240768 AFA00020 */   sw       $zero, 0x20($sp)
/* CAF4AC 8024076C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* CAF4B0 80240770 C7A40020 */  lwc1      $f4, 0x20($sp)
/* CAF4B4 80240774 46041082 */  mul.s     $f2, $f2, $f4
/* CAF4B8 80240778 00000000 */  nop       
/* CAF4BC 8024077C C7A00018 */  lwc1      $f0, 0x18($sp)
/* CAF4C0 80240780 46040002 */  mul.s     $f0, $f0, $f4
/* CAF4C4 80240784 00000000 */  nop       
/* CAF4C8 80240788 E6020038 */  swc1      $f2, 0x38($s0)
/* CAF4CC 8024078C E6000050 */  swc1      $f0, 0x50($s0)
/* CAF4D0 80240790 8E42005C */  lw        $v0, 0x5c($s2)
/* CAF4D4 80240794 C6000038 */  lwc1      $f0, 0x38($s0)
/* CAF4D8 80240798 C4420048 */  lwc1      $f2, 0x48($v0)
/* CAF4DC 8024079C 46001080 */  add.s     $f2, $f2, $f0
/* CAF4E0 802407A0 C6A00038 */  lwc1      $f0, 0x38($s5)
/* CAF4E4 802407A4 46020001 */  sub.s     $f0, $f0, $f2
/* CAF4E8 802407A8 E6000038 */  swc1      $f0, 0x38($s0)
/* CAF4EC 802407AC 8E42005C */  lw        $v0, 0x5c($s2)
/* CAF4F0 802407B0 C6000044 */  lwc1      $f0, 0x44($s0)
/* CAF4F4 802407B4 C442004C */  lwc1      $f2, 0x4c($v0)
/* CAF4F8 802407B8 46001080 */  add.s     $f2, $f2, $f0
/* CAF4FC 802407BC C6A0003C */  lwc1      $f0, 0x3c($s5)
/* CAF500 802407C0 46020001 */  sub.s     $f0, $f0, $f2
/* CAF504 802407C4 E6000044 */  swc1      $f0, 0x44($s0)
/* CAF508 802407C8 8E42005C */  lw        $v0, 0x5c($s2)
/* CAF50C 802407CC C6000050 */  lwc1      $f0, 0x50($s0)
/* CAF510 802407D0 C4420050 */  lwc1      $f2, 0x50($v0)
/* CAF514 802407D4 26940004 */  addiu     $s4, $s4, 4
/* CAF518 802407D8 46001080 */  add.s     $f2, $f2, $f0
/* CAF51C 802407DC C6A00040 */  lwc1      $f0, 0x40($s5)
/* CAF520 802407E0 26730004 */  addiu     $s3, $s3, 4
/* CAF524 802407E4 46020001 */  sub.s     $f0, $f0, $f2
/* CAF528 802407E8 26310001 */  addiu     $s1, $s1, 1
/* CAF52C 802407EC 2A220003 */  slti      $v0, $s1, 3
/* CAF530 802407F0 E6000050 */  swc1      $f0, 0x50($s0)
/* CAF534 802407F4 1440FFD7 */  bnez      $v0, .L80240754
/* CAF538 802407F8 26100004 */   addiu    $s0, $s0, 4
.L802407FC:
/* CAF53C 802407FC 8ED20060 */  lw        $s2, 0x60($s6)
/* CAF540 80240800 8E430000 */  lw        $v1, ($s2)
/* CAF544 80240804 24020001 */  addiu     $v0, $zero, 1
/* CAF548 80240808 10620038 */  beq       $v1, $v0, .L802408EC
/* CAF54C 8024080C 28620002 */   slti     $v0, $v1, 2
/* CAF550 80240810 50400005 */  beql      $v0, $zero, .L80240828
/* CAF554 80240814 24020002 */   addiu    $v0, $zero, 2
/* CAF558 80240818 10600007 */  beqz      $v1, .L80240838
/* CAF55C 8024081C 24040005 */   addiu    $a0, $zero, 5
/* CAF560 80240820 08090274 */  j         .L802409D0
/* CAF564 80240824 00000000 */   nop      
.L80240828:
/* CAF568 80240828 10620058 */  beq       $v1, $v0, .L8024098C
/* CAF56C 8024082C 00000000 */   nop      
/* CAF570 80240830 08090274 */  j         .L802409D0
/* CAF574 80240834 00000000 */   nop      
.L80240838:
/* CAF578 80240838 0000882D */  daddu     $s1, $zero, $zero
/* CAF57C 8024083C 3C148024 */  lui       $s4, %hi(D_80242008)
/* CAF580 80240840 26942008 */  addiu     $s4, $s4, %lo(D_80242008)
/* CAF584 80240844 24130020 */  addiu     $s3, $zero, 0x20
/* CAF588 80240848 3C064248 */  lui       $a2, 0x4248
/* CAF58C 8024084C 44800000 */  mtc1      $zero, $f0
/* CAF590 80240850 24020014 */  addiu     $v0, $zero, 0x14
/* CAF594 80240854 AFA20010 */  sw        $v0, 0x10($sp)
/* CAF598 80240858 44050000 */  mfc1      $a1, $f0
/* CAF59C 8024085C 8E470060 */  lw        $a3, 0x60($s2)
/* CAF5A0 80240860 4485B000 */  mtc1      $a1, $f22
/* CAF5A4 80240864 0C00A8ED */  jal       update_lerp
/* CAF5A8 80240868 0240802D */   daddu    $s0, $s2, $zero
/* CAF5AC 8024086C 46000506 */  mov.s     $f20, $f0
.L80240870:
/* CAF5B0 80240870 4406A000 */  mfc1      $a2, $f20
/* CAF5B4 80240874 27A40020 */  addiu     $a0, $sp, 0x20
/* CAF5B8 80240878 E6160020 */  swc1      $f22, 0x20($s0)
/* CAF5BC 8024087C 8E870000 */  lw        $a3, ($s4)
/* CAF5C0 80240880 02532821 */  addu      $a1, $s2, $s3
/* CAF5C4 80240884 0C00A7E7 */  jal       add_vec2D_polar
/* CAF5C8 80240888 E7B60020 */   swc1     $f22, 0x20($sp)
/* CAF5CC 8024088C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* CAF5D0 80240890 C7A00020 */  lwc1      $f0, 0x20($sp)
/* CAF5D4 80240894 46002102 */  mul.s     $f4, $f4, $f0
/* CAF5D8 80240898 00000000 */  nop       
/* CAF5DC 8024089C C7A20018 */  lwc1      $f2, 0x18($sp)
/* CAF5E0 802408A0 26940004 */  addiu     $s4, $s4, 4
/* CAF5E4 802408A4 46001082 */  mul.s     $f2, $f2, $f0
/* CAF5E8 802408A8 00000000 */  nop       
/* CAF5EC 802408AC 26730004 */  addiu     $s3, $s3, 4
/* CAF5F0 802408B0 26310001 */  addiu     $s1, $s1, 1
/* CAF5F4 802408B4 2A220003 */  slti      $v0, $s1, 3
/* CAF5F8 802408B8 E6040014 */  swc1      $f4, 0x14($s0)
/* CAF5FC 802408BC E602002C */  swc1      $f2, 0x2c($s0)
/* CAF600 802408C0 1440FFEB */  bnez      $v0, .L80240870
/* CAF604 802408C4 26100004 */   addiu    $s0, $s0, 4
/* CAF608 802408C8 8E420060 */  lw        $v0, 0x60($s2)
/* CAF60C 802408CC 24420001 */  addiu     $v0, $v0, 1
/* CAF610 802408D0 AE420060 */  sw        $v0, 0x60($s2)
/* CAF614 802408D4 28420015 */  slti      $v0, $v0, 0x15
/* CAF618 802408D8 1440003D */  bnez      $v0, .L802409D0
/* CAF61C 802408DC 24020001 */   addiu    $v0, $zero, 1
/* CAF620 802408E0 AE420000 */  sw        $v0, ($s2)
/* CAF624 802408E4 08090274 */  j         .L802409D0
/* CAF628 802408E8 AE400060 */   sw       $zero, 0x60($s2)
.L802408EC:
/* CAF62C 802408EC 0000882D */  daddu     $s1, $zero, $zero
/* CAF630 802408F0 3C148024 */  lui       $s4, %hi(D_80242008)
/* CAF634 802408F4 26942008 */  addiu     $s4, $s4, %lo(D_80242008)
/* CAF638 802408F8 24130020 */  addiu     $s3, $zero, 0x20
/* CAF63C 802408FC 0240802D */  daddu     $s0, $s2, $zero
/* CAF640 80240900 3C014248 */  lui       $at, 0x4248
/* CAF644 80240904 4481A000 */  mtc1      $at, $f20
/* CAF648 80240908 4480B000 */  mtc1      $zero, $f22
.L8024090C:
/* CAF64C 8024090C 4406A000 */  mfc1      $a2, $f20
/* CAF650 80240910 27A40020 */  addiu     $a0, $sp, 0x20
/* CAF654 80240914 E6160020 */  swc1      $f22, 0x20($s0)
/* CAF658 80240918 8E870000 */  lw        $a3, ($s4)
/* CAF65C 8024091C 02532821 */  addu      $a1, $s2, $s3
/* CAF660 80240920 0C00A7E7 */  jal       add_vec2D_polar
/* CAF664 80240924 E7B60020 */   swc1     $f22, 0x20($sp)
/* CAF668 80240928 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* CAF66C 8024092C C7A00020 */  lwc1      $f0, 0x20($sp)
/* CAF670 80240930 46002102 */  mul.s     $f4, $f4, $f0
/* CAF674 80240934 00000000 */  nop       
/* CAF678 80240938 C7A20018 */  lwc1      $f2, 0x18($sp)
/* CAF67C 8024093C 26940004 */  addiu     $s4, $s4, 4
/* CAF680 80240940 46001082 */  mul.s     $f2, $f2, $f0
/* CAF684 80240944 00000000 */  nop       
/* CAF688 80240948 26730004 */  addiu     $s3, $s3, 4
/* CAF68C 8024094C 26310001 */  addiu     $s1, $s1, 1
/* CAF690 80240950 2A220003 */  slti      $v0, $s1, 3
/* CAF694 80240954 E6040014 */  swc1      $f4, 0x14($s0)
/* CAF698 80240958 E602002C */  swc1      $f2, 0x2c($s0)
/* CAF69C 8024095C 1440FFEB */  bnez      $v0, .L8024090C
/* CAF6A0 80240960 26100004 */   addiu    $s0, $s0, 4
/* CAF6A4 80240964 8E420060 */  lw        $v0, 0x60($s2)
/* CAF6A8 80240968 24420001 */  addiu     $v0, $v0, 1
/* CAF6AC 8024096C AE420060 */  sw        $v0, 0x60($s2)
/* CAF6B0 80240970 28420010 */  slti      $v0, $v0, 0x10
/* CAF6B4 80240974 14400016 */  bnez      $v0, .L802409D0
/* CAF6B8 80240978 2402000F */   addiu    $v0, $zero, 0xf
/* CAF6BC 8024097C AE420060 */  sw        $v0, 0x60($s2)
/* CAF6C0 80240980 24020002 */  addiu     $v0, $zero, 2
/* CAF6C4 80240984 08090274 */  j         .L802409D0
/* CAF6C8 80240988 AE420000 */   sw       $v0, ($s2)
.L8024098C:
/* CAF6CC 8024098C 8E420060 */  lw        $v0, 0x60($s2)
/* CAF6D0 80240990 24420001 */  addiu     $v0, $v0, 1
/* CAF6D4 80240994 AE420060 */  sw        $v0, 0x60($s2)
/* CAF6D8 80240998 2842001F */  slti      $v0, $v0, 0x1f
/* CAF6DC 8024099C 1440000C */  bnez      $v0, .L802409D0
/* CAF6E0 802409A0 0000882D */   daddu    $s1, $zero, $zero
/* CAF6E4 802409A4 0240282D */  daddu     $a1, $s2, $zero
.L802409A8:
/* CAF6E8 802409A8 8CA20008 */  lw        $v0, 8($a1)
/* CAF6EC 802409AC 8C430000 */  lw        $v1, ($v0)
/* CAF6F0 802409B0 26310001 */  addiu     $s1, $s1, 1
/* CAF6F4 802409B4 34630010 */  ori       $v1, $v1, 0x10
/* CAF6F8 802409B8 AC430000 */  sw        $v1, ($v0)
/* CAF6FC 802409BC 2A220003 */  slti      $v0, $s1, 3
/* CAF700 802409C0 1440FFF9 */  bnez      $v0, .L802409A8
/* CAF704 802409C4 24A50004 */   addiu    $a1, $a1, 4
/* CAF708 802409C8 080902C1 */  j         .L80240B04
/* CAF70C 802409CC 24020002 */   addiu    $v0, $zero, 2
.L802409D0:
/* CAF710 802409D0 8E430004 */  lw        $v1, 4($s2)
/* CAF714 802409D4 10600005 */  beqz      $v1, .L802409EC
/* CAF718 802409D8 24020001 */   addiu    $v0, $zero, 1
/* CAF71C 802409DC 1062000B */  beq       $v1, $v0, .L80240A0C
/* CAF720 802409E0 0000882D */   daddu    $s1, $zero, $zero
/* CAF724 802409E4 080902B0 */  j         .L80240AC0
/* CAF728 802409E8 0240282D */   daddu    $a1, $s2, $zero
.L802409EC:
/* CAF72C 802409EC 8E420064 */  lw        $v0, 0x64($s2)
/* CAF730 802409F0 24420001 */  addiu     $v0, $v0, 1
/* CAF734 802409F4 AE420064 */  sw        $v0, 0x64($s2)
/* CAF738 802409F8 28420010 */  slti      $v0, $v0, 0x10
/* CAF73C 802409FC 1440002F */  bnez      $v0, .L80240ABC
/* CAF740 80240A00 0000882D */   daddu    $s1, $zero, $zero
/* CAF744 80240A04 080902AC */  j         .L80240AB0
/* CAF748 80240A08 24020001 */   addiu    $v0, $zero, 1
.L80240A0C:
/* CAF74C 80240A0C 4480A000 */  mtc1      $zero, $f20
/* CAF750 80240A10 24130014 */  addiu     $s3, $zero, 0x14
/* CAF754 80240A14 0240802D */  daddu     $s0, $s2, $zero
.L80240A18:
/* CAF758 80240A18 4405A000 */  mfc1      $a1, $f20
/* CAF75C 80240A1C AFB30010 */  sw        $s3, 0x10($sp)
/* CAF760 80240A20 8E060038 */  lw        $a2, 0x38($s0)
/* CAF764 80240A24 8E470064 */  lw        $a3, 0x64($s2)
/* CAF768 80240A28 0C00A8ED */  jal       update_lerp
/* CAF76C 80240A2C 24040001 */   addiu    $a0, $zero, 1
/* CAF770 80240A30 C6020014 */  lwc1      $f2, 0x14($s0)
/* CAF774 80240A34 46001080 */  add.s     $f2, $f2, $f0
/* CAF778 80240A38 4405A000 */  mfc1      $a1, $f20
/* CAF77C 80240A3C E6020014 */  swc1      $f2, 0x14($s0)
/* CAF780 80240A40 AFB30010 */  sw        $s3, 0x10($sp)
/* CAF784 80240A44 8E060044 */  lw        $a2, 0x44($s0)
/* CAF788 80240A48 8E470064 */  lw        $a3, 0x64($s2)
/* CAF78C 80240A4C 0C00A8ED */  jal       update_lerp
/* CAF790 80240A50 24040001 */   addiu    $a0, $zero, 1
/* CAF794 80240A54 C6020020 */  lwc1      $f2, 0x20($s0)
/* CAF798 80240A58 46001080 */  add.s     $f2, $f2, $f0
/* CAF79C 80240A5C 4405A000 */  mfc1      $a1, $f20
/* CAF7A0 80240A60 E6020020 */  swc1      $f2, 0x20($s0)
/* CAF7A4 80240A64 AFB30010 */  sw        $s3, 0x10($sp)
/* CAF7A8 80240A68 8E060050 */  lw        $a2, 0x50($s0)
/* CAF7AC 80240A6C 8E470064 */  lw        $a3, 0x64($s2)
/* CAF7B0 80240A70 0C00A8ED */  jal       update_lerp
/* CAF7B4 80240A74 24040001 */   addiu    $a0, $zero, 1
/* CAF7B8 80240A78 C602002C */  lwc1      $f2, 0x2c($s0)
/* CAF7BC 80240A7C 46001080 */  add.s     $f2, $f2, $f0
/* CAF7C0 80240A80 26310001 */  addiu     $s1, $s1, 1
/* CAF7C4 80240A84 2A220003 */  slti      $v0, $s1, 3
/* CAF7C8 80240A88 E602002C */  swc1      $f2, 0x2c($s0)
/* CAF7CC 80240A8C 1440FFE2 */  bnez      $v0, .L80240A18
/* CAF7D0 80240A90 26100004 */   addiu    $s0, $s0, 4
/* CAF7D4 80240A94 8E420064 */  lw        $v0, 0x64($s2)
/* CAF7D8 80240A98 24420001 */  addiu     $v0, $v0, 1
/* CAF7DC 80240A9C AE420064 */  sw        $v0, 0x64($s2)
/* CAF7E0 80240AA0 28420015 */  slti      $v0, $v0, 0x15
/* CAF7E4 80240AA4 14400005 */  bnez      $v0, .L80240ABC
/* CAF7E8 80240AA8 0000882D */   daddu    $s1, $zero, $zero
/* CAF7EC 80240AAC 24020002 */  addiu     $v0, $zero, 2
.L80240AB0:
/* CAF7F0 80240AB0 AE420004 */  sw        $v0, 4($s2)
/* CAF7F4 80240AB4 AE400064 */  sw        $zero, 0x64($s2)
/* CAF7F8 80240AB8 0000882D */  daddu     $s1, $zero, $zero
.L80240ABC:
/* CAF7FC 80240ABC 0240282D */  daddu     $a1, $s2, $zero
.L80240AC0:
/* CAF800 80240AC0 8CA20008 */  lw        $v0, 8($a1)
/* CAF804 80240AC4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* CAF808 80240AC8 8C42000C */  lw        $v0, 0xc($v0)
/* CAF80C 80240ACC E4400010 */  swc1      $f0, 0x10($v0)
/* CAF810 80240AD0 8CA20008 */  lw        $v0, 8($a1)
/* CAF814 80240AD4 C4A00020 */  lwc1      $f0, 0x20($a1)
/* CAF818 80240AD8 8C42000C */  lw        $v0, 0xc($v0)
/* CAF81C 80240ADC 26310001 */  addiu     $s1, $s1, 1
/* CAF820 80240AE0 E4400014 */  swc1      $f0, 0x14($v0)
/* CAF824 80240AE4 8CA20008 */  lw        $v0, 8($a1)
/* CAF828 80240AE8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* CAF82C 80240AEC 8C42000C */  lw        $v0, 0xc($v0)
/* CAF830 80240AF0 E4400018 */  swc1      $f0, 0x18($v0)
/* CAF834 80240AF4 2A220003 */  slti      $v0, $s1, 3
/* CAF838 80240AF8 1440FFF1 */  bnez      $v0, .L80240AC0
/* CAF83C 80240AFC 24A50004 */   addiu    $a1, $a1, 4
/* CAF840 80240B00 0000102D */  daddu     $v0, $zero, $zero
.L80240B04:
/* CAF844 80240B04 8FBF0044 */  lw        $ra, 0x44($sp)
/* CAF848 80240B08 8FB60040 */  lw        $s6, 0x40($sp)
/* CAF84C 80240B0C 8FB5003C */  lw        $s5, 0x3c($sp)
/* CAF850 80240B10 8FB40038 */  lw        $s4, 0x38($sp)
/* CAF854 80240B14 8FB30034 */  lw        $s3, 0x34($sp)
/* CAF858 80240B18 8FB20030 */  lw        $s2, 0x30($sp)
/* CAF85C 80240B1C 8FB1002C */  lw        $s1, 0x2c($sp)
/* CAF860 80240B20 8FB00028 */  lw        $s0, 0x28($sp)
/* CAF864 80240B24 D7B80058 */  ldc1      $f24, 0x58($sp)
/* CAF868 80240B28 D7B60050 */  ldc1      $f22, 0x50($sp)
/* CAF86C 80240B2C D7B40048 */  ldc1      $f20, 0x48($sp)
/* CAF870 80240B30 03E00008 */  jr        $ra
/* CAF874 80240B34 27BD0060 */   addiu    $sp, $sp, 0x60
