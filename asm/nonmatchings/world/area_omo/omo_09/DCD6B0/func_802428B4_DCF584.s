.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428B4_DCF584
/* DCF584 802428B4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* DCF588 802428B8 AFB7004C */  sw        $s7, 0x4c($sp)
/* DCF58C 802428BC 0080B82D */  daddu     $s7, $a0, $zero
/* DCF590 802428C0 AFB10034 */  sw        $s1, 0x34($sp)
/* DCF594 802428C4 00A0882D */  daddu     $s1, $a1, $zero
/* DCF598 802428C8 AFBF0050 */  sw        $ra, 0x50($sp)
/* DCF59C 802428CC AFB60048 */  sw        $s6, 0x48($sp)
/* DCF5A0 802428D0 AFB50044 */  sw        $s5, 0x44($sp)
/* DCF5A4 802428D4 AFB40040 */  sw        $s4, 0x40($sp)
/* DCF5A8 802428D8 AFB3003C */  sw        $s3, 0x3c($sp)
/* DCF5AC 802428DC AFB20038 */  sw        $s2, 0x38($sp)
/* DCF5B0 802428E0 AFB00030 */  sw        $s0, 0x30($sp)
/* DCF5B4 802428E4 8EF30148 */  lw        $s3, 0x148($s7)
/* DCF5B8 802428E8 86640008 */  lh        $a0, 8($s3)
/* DCF5BC 802428EC 8EF0000C */  lw        $s0, 0xc($s7)
/* DCF5C0 802428F0 0C00FB5A */  jal       get_enemy_safe
/* DCF5C4 802428F4 0000B02D */   daddu    $s6, $zero, $zero
/* DCF5C8 802428F8 10400131 */  beqz      $v0, .L80242DC0
/* DCF5CC 802428FC 24020005 */   addiu    $v0, $zero, 5
/* DCF5D0 80242900 8E63006C */  lw        $v1, 0x6c($s3)
/* DCF5D4 80242904 1062012F */  beq       $v1, $v0, .L80242DC4
/* DCF5D8 80242908 0000102D */   daddu    $v0, $zero, $zero
/* DCF5DC 8024290C 8E050000 */  lw        $a1, ($s0)
/* DCF5E0 80242910 0C0B1EAF */  jal       get_variable
/* DCF5E4 80242914 02E0202D */   daddu    $a0, $s7, $zero
/* DCF5E8 80242918 86640008 */  lh        $a0, 8($s3)
/* DCF5EC 8024291C 0C00EABB */  jal       get_npc_unsafe
/* DCF5F0 80242920 0040A82D */   daddu    $s5, $v0, $zero
/* DCF5F4 80242924 8E630070 */  lw        $v1, 0x70($s3)
/* DCF5F8 80242928 30630002 */  andi      $v1, $v1, 2
/* DCF5FC 8024292C 10600008 */  beqz      $v1, .L80242950
/* DCF600 80242930 0040902D */   daddu    $s2, $v0, $zero
/* DCF604 80242934 964200A8 */  lhu       $v0, 0xa8($s2)
/* DCF608 80242938 00021400 */  sll       $v0, $v0, 0x10
/* DCF60C 8024293C 00021C03 */  sra       $v1, $v0, 0x10
/* DCF610 80242940 000217C2 */  srl       $v0, $v0, 0x1f
/* DCF614 80242944 00621821 */  addu      $v1, $v1, $v0
/* DCF618 80242948 00031843 */  sra       $v1, $v1, 1
/* DCF61C 8024294C A24300AB */  sb        $v1, 0xab($s2)
.L80242950:
/* DCF620 80242950 16200005 */  bnez      $s1, .L80242968
/* DCF624 80242954 3C030004 */   lui      $v1, 4
/* DCF628 80242958 8E6200B0 */  lw        $v0, 0xb0($s3)
/* DCF62C 8024295C 30420004 */  andi      $v0, $v0, 4
/* DCF630 80242960 10400019 */  beqz      $v0, .L802429C8
/* DCF634 80242964 00000000 */   nop      
.L80242968:
/* DCF638 80242968 34630102 */  ori       $v1, $v1, 0x102
/* DCF63C 8024296C AEE00070 */  sw        $zero, 0x70($s7)
/* DCF640 80242970 8E420000 */  lw        $v0, ($s2)
/* DCF644 80242974 0240202D */  daddu     $a0, $s2, $zero
/* DCF648 80242978 A640008E */  sh        $zero, 0x8e($s2)
/* DCF64C 8024297C 00431025 */  or        $v0, $v0, $v1
/* DCF650 80242980 0C00EAFF */  jal       disable_npc_shadow
/* DCF654 80242984 AE420000 */   sw       $v0, ($s2)
/* DCF658 80242988 3C041F30 */  lui       $a0, 0x1f30
/* DCF65C 8024298C 8E420000 */  lw        $v0, ($s2)
/* DCF660 80242990 2403F7FF */  addiu     $v1, $zero, -0x801
/* DCF664 80242994 00431024 */  and       $v0, $v0, $v1
/* DCF668 80242998 AE420000 */  sw        $v0, ($s2)
/* DCF66C 8024299C 8E620000 */  lw        $v0, ($s3)
/* DCF670 802429A0 8E6300B0 */  lw        $v1, 0xb0($s3)
/* DCF674 802429A4 34840040 */  ori       $a0, $a0, 0x40
/* DCF678 802429A8 AE60006C */  sw        $zero, 0x6c($s3)
/* DCF67C 802429AC 00441025 */  or        $v0, $v0, $a0
/* DCF680 802429B0 AE620000 */  sw        $v0, ($s3)
/* DCF684 802429B4 30620004 */  andi      $v0, $v1, 4
/* DCF688 802429B8 10400003 */  beqz      $v0, .L802429C8
/* DCF68C 802429BC 2402FFFB */   addiu    $v0, $zero, -5
/* DCF690 802429C0 00621024 */  and       $v0, $v1, $v0
/* DCF694 802429C4 AE6200B0 */  sw        $v0, 0xb0($s3)
.L802429C8:
/* DCF698 802429C8 8EE30070 */  lw        $v1, 0x70($s7)
/* DCF69C 802429CC 24100001 */  addiu     $s0, $zero, 1
/* DCF6A0 802429D0 10700012 */  beq       $v1, $s0, .L80242A1C
/* DCF6A4 802429D4 28620002 */   slti     $v0, $v1, 2
/* DCF6A8 802429D8 10400005 */  beqz      $v0, .L802429F0
/* DCF6AC 802429DC 24020002 */   addiu    $v0, $zero, 2
/* DCF6B0 802429E0 10600007 */  beqz      $v1, .L80242A00
/* DCF6B4 802429E4 0000102D */   daddu    $v0, $zero, $zero
/* DCF6B8 802429E8 08090B71 */  j         .L80242DC4
/* DCF6BC 802429EC 00000000 */   nop      
.L802429F0:
/* DCF6C0 802429F0 1062005B */  beq       $v1, $v0, .L80242B60
/* DCF6C4 802429F4 0000102D */   daddu    $v0, $zero, $zero
/* DCF6C8 802429F8 08090B71 */  j         .L80242DC4
/* DCF6CC 802429FC 00000000 */   nop      
.L80242A00:
/* DCF6D0 80242A00 8E420000 */  lw        $v0, ($s2)
/* DCF6D4 80242A04 0240202D */  daddu     $a0, $s2, $zero
/* DCF6D8 80242A08 34420002 */  ori       $v0, $v0, 2
/* DCF6DC 80242A0C 0C00EAFF */  jal       disable_npc_shadow
/* DCF6E0 80242A10 AE420000 */   sw       $v0, ($s2)
/* DCF6E4 80242A14 AE60006C */  sw        $zero, 0x6c($s3)
/* DCF6E8 80242A18 AEF00070 */  sw        $s0, 0x70($s7)
.L80242A1C:
/* DCF6EC 80242A1C 8E74006C */  lw        $s4, 0x6c($s3)
/* DCF6F0 80242A20 24020001 */  addiu     $v0, $zero, 1
/* DCF6F4 80242A24 168200E7 */  bne       $s4, $v0, .L80242DC4
/* DCF6F8 80242A28 0000102D */   daddu    $v0, $zero, $zero
/* DCF6FC 80242A2C 8E64007C */  lw        $a0, 0x7c($s3)
/* DCF700 80242A30 24110002 */  addiu     $s1, $zero, 2
/* DCF704 80242A34 0C00EABB */  jal       get_npc_unsafe
/* DCF708 80242A38 AE71006C */   sw       $s1, 0x6c($s3)
/* DCF70C 80242A3C 0040802D */  daddu     $s0, $v0, $zero
/* DCF710 80242A40 C6000038 */  lwc1      $f0, 0x38($s0)
/* DCF714 80242A44 E6400038 */  swc1      $f0, 0x38($s2)
/* DCF718 80242A48 C6000040 */  lwc1      $f0, 0x40($s0)
/* DCF71C 80242A4C E6400040 */  swc1      $f0, 0x40($s2)
/* DCF720 80242A50 C6020034 */  lwc1      $f2, 0x34($s0)
/* DCF724 80242A54 3C014387 */  lui       $at, 0x4387
/* DCF728 80242A58 44810000 */  mtc1      $at, $f0
/* DCF72C 80242A5C 26440038 */  addiu     $a0, $s2, 0x38
/* DCF730 80242A60 46020001 */  sub.s     $f0, $f0, $f2
/* DCF734 80242A64 C6680078 */  lwc1      $f8, 0x78($s3)
/* DCF738 80242A68 46804220 */  cvt.s.w   $f8, $f8
/* DCF73C 80242A6C 44064000 */  mfc1      $a2, $f8
/* DCF740 80242A70 44070000 */  mfc1      $a3, $f0
/* DCF744 80242A74 0C00A7E7 */  jal       add_vec2D_polar
/* DCF748 80242A78 26450040 */   addiu    $a1, $s2, 0x40
/* DCF74C 80242A7C C600003C */  lwc1      $f0, 0x3c($s0)
/* DCF750 80242A80 C6620074 */  lwc1      $f2, 0x74($s3)
/* DCF754 80242A84 468010A0 */  cvt.s.w   $f2, $f2
/* DCF758 80242A88 46020000 */  add.s     $f0, $f0, $f2
/* DCF75C 80242A8C E640003C */  swc1      $f0, 0x3c($s2)
/* DCF760 80242A90 A2740007 */  sb        $s4, 7($s3)
/* DCF764 80242A94 C6400038 */  lwc1      $f0, 0x38($s2)
/* DCF768 80242A98 4600020D */  trunc.w.s $f8, $f0
/* DCF76C 80242A9C 44024000 */  mfc1      $v0, $f8
/* DCF770 80242AA0 00000000 */  nop       
/* DCF774 80242AA4 A6620010 */  sh        $v0, 0x10($s3)
/* DCF778 80242AA8 C640003C */  lwc1      $f0, 0x3c($s2)
/* DCF77C 80242AAC 4600020D */  trunc.w.s $f8, $f0
/* DCF780 80242AB0 44024000 */  mfc1      $v0, $f8
/* DCF784 80242AB4 00000000 */  nop       
/* DCF788 80242AB8 A6620012 */  sh        $v0, 0x12($s3)
/* DCF78C 80242ABC C6400040 */  lwc1      $f0, 0x40($s2)
/* DCF790 80242AC0 4600020D */  trunc.w.s $f8, $f0
/* DCF794 80242AC4 44024000 */  mfc1      $v0, $f8
/* DCF798 80242AC8 00000000 */  nop       
/* DCF79C 80242ACC A6620014 */  sh        $v0, 0x14($s3)
/* DCF7A0 80242AD0 AE400044 */  sw        $zero, 0x44($s2)
/* DCF7A4 80242AD4 AE400048 */  sw        $zero, 0x48($s2)
/* DCF7A8 80242AD8 AE40004C */  sw        $zero, 0x4c($s2)
/* DCF7AC 80242ADC C6A00000 */  lwc1      $f0, ($s5)
/* DCF7B0 80242AE0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DCF7B4 80242AE4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DCF7B8 80242AE8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* DCF7BC 80242AEC C64E0040 */  lwc1      $f14, 0x40($s2)
/* DCF7C0 80242AF0 E6400018 */  swc1      $f0, 0x18($s2)
/* DCF7C4 80242AF4 8C460028 */  lw        $a2, 0x28($v0)
/* DCF7C8 80242AF8 0C00A720 */  jal       atan2
/* DCF7CC 80242AFC 8C470030 */   lw       $a3, 0x30($v0)
/* DCF7D0 80242B00 E640000C */  swc1      $f0, 0xc($s2)
/* DCF7D4 80242B04 C6A0000C */  lwc1      $f0, 0xc($s5)
/* DCF7D8 80242B08 8E420000 */  lw        $v0, ($s2)
/* DCF7DC 80242B0C 0240202D */  daddu     $a0, $s2, $zero
/* DCF7E0 80242B10 E640001C */  swc1      $f0, 0x1c($s2)
/* DCF7E4 80242B14 C6A00010 */  lwc1      $f0, 0x10($s5)
/* DCF7E8 80242B18 2403FFFD */  addiu     $v1, $zero, -3
/* DCF7EC 80242B1C E6400014 */  swc1      $f0, 0x14($s2)
/* DCF7F0 80242B20 C600003C */  lwc1      $f0, 0x3c($s0)
/* DCF7F4 80242B24 00431024 */  and       $v0, $v0, $v1
/* DCF7F8 80242B28 AE420000 */  sw        $v0, ($s2)
/* DCF7FC 80242B2C 0C00EAE8 */  jal       enable_npc_shadow
/* DCF800 80242B30 E6400064 */   swc1     $f0, 0x64($s2)
/* DCF804 80242B34 8E420000 */  lw        $v0, ($s2)
/* DCF808 80242B38 3C03E0FF */  lui       $v1, 0xe0ff
/* DCF80C 80242B3C 34420800 */  ori       $v0, $v0, 0x800
/* DCF810 80242B40 AE420000 */  sw        $v0, ($s2)
/* DCF814 80242B44 8E620000 */  lw        $v0, ($s3)
/* DCF818 80242B48 3463FFFF */  ori       $v1, $v1, 0xffff
/* DCF81C 80242B4C 00431024 */  and       $v0, $v0, $v1
/* DCF820 80242B50 AE620000 */  sw        $v0, ($s3)
/* DCF824 80242B54 2402005A */  addiu     $v0, $zero, 0x5a
/* DCF828 80242B58 A642008E */  sh        $v0, 0x8e($s2)
/* DCF82C 80242B5C AEF10070 */  sw        $s1, 0x70($s7)
.L80242B60:
/* DCF830 80242B60 0000202D */  daddu     $a0, $zero, $zero
/* DCF834 80242B64 27B00020 */  addiu     $s0, $sp, 0x20
/* DCF838 80242B68 864200A8 */  lh        $v0, 0xa8($s2)
/* DCF83C 80242B6C 3C013FE0 */  lui       $at, 0x3fe0
/* DCF840 80242B70 44810800 */  mtc1      $at, $f1
/* DCF844 80242B74 44800000 */  mtc1      $zero, $f0
/* DCF848 80242B78 44821000 */  mtc1      $v0, $f2
/* DCF84C 80242B7C 00000000 */  nop       
/* DCF850 80242B80 468010A1 */  cvt.d.w   $f2, $f2
/* DCF854 80242B84 46201082 */  mul.d     $f2, $f2, $f0
/* DCF858 80242B88 00000000 */  nop       
/* DCF85C 80242B8C 0200282D */  daddu     $a1, $s0, $zero
/* DCF860 80242B90 C6440038 */  lwc1      $f4, 0x38($s2)
/* DCF864 80242B94 C640003C */  lwc1      $f0, 0x3c($s2)
/* DCF868 80242B98 27B10024 */  addiu     $s1, $sp, 0x24
/* DCF86C 80242B9C E7A40020 */  swc1      $f4, 0x20($sp)
/* DCF870 80242BA0 C6440040 */  lwc1      $f4, 0x40($s2)
/* DCF874 80242BA4 46000021 */  cvt.d.s   $f0, $f0
/* DCF878 80242BA8 46220000 */  add.d     $f0, $f0, $f2
/* DCF87C 80242BAC E7A40028 */  swc1      $f4, 0x28($sp)
/* DCF880 80242BB0 C6420018 */  lwc1      $f2, 0x18($s2)
/* DCF884 80242BB4 46200020 */  cvt.s.d   $f0, $f0
/* DCF888 80242BB8 E7A00024 */  swc1      $f0, 0x24($sp)
/* DCF88C 80242BBC E7A20010 */  swc1      $f2, 0x10($sp)
/* DCF890 80242BC0 C640000C */  lwc1      $f0, 0xc($s2)
/* DCF894 80242BC4 0220302D */  daddu     $a2, $s1, $zero
/* DCF898 80242BC8 E7A00014 */  swc1      $f0, 0x14($sp)
/* DCF89C 80242BCC 864200A6 */  lh        $v0, 0xa6($s2)
/* DCF8A0 80242BD0 27B40028 */  addiu     $s4, $sp, 0x28
/* DCF8A4 80242BD4 44820000 */  mtc1      $v0, $f0
/* DCF8A8 80242BD8 00000000 */  nop       
/* DCF8AC 80242BDC 46800020 */  cvt.s.w   $f0, $f0
/* DCF8B0 80242BE0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DCF8B4 80242BE4 864200A8 */  lh        $v0, 0xa8($s2)
/* DCF8B8 80242BE8 0280382D */  daddu     $a3, $s4, $zero
/* DCF8BC 80242BEC 44820000 */  mtc1      $v0, $f0
/* DCF8C0 80242BF0 00000000 */  nop       
/* DCF8C4 80242BF4 46800020 */  cvt.s.w   $f0, $f0
/* DCF8C8 80242BF8 0C0376B9 */  jal       func_800DDAE4
/* DCF8CC 80242BFC E7A0001C */   swc1     $f0, 0x1c($sp)
/* DCF8D0 80242C00 54400001 */  bnel      $v0, $zero, .L80242C08
/* DCF8D4 80242C04 24160001 */   addiu    $s6, $zero, 1
.L80242C08:
/* DCF8D8 80242C08 0200282D */  daddu     $a1, $s0, $zero
/* DCF8DC 80242C0C 0220302D */  daddu     $a2, $s1, $zero
/* DCF8E0 80242C10 C6400038 */  lwc1      $f0, 0x38($s2)
/* DCF8E4 80242C14 C642003C */  lwc1      $f2, 0x3c($s2)
/* DCF8E8 80242C18 C6440040 */  lwc1      $f4, 0x40($s2)
/* DCF8EC 80242C1C 3C01447A */  lui       $at, 0x447a
/* DCF8F0 80242C20 44813000 */  mtc1      $at, $f6
/* DCF8F4 80242C24 27A2002C */  addiu     $v0, $sp, 0x2c
/* DCF8F8 80242C28 E7A00020 */  swc1      $f0, 0x20($sp)
/* DCF8FC 80242C2C E7A20024 */  swc1      $f2, 0x24($sp)
/* DCF900 80242C30 E7A40028 */  swc1      $f4, 0x28($sp)
/* DCF904 80242C34 E7A6002C */  swc1      $f6, 0x2c($sp)
/* DCF908 80242C38 AFA20010 */  sw        $v0, 0x10($sp)
/* DCF90C 80242C3C 8E440080 */  lw        $a0, 0x80($s2)
/* DCF910 80242C40 0C0372DF */  jal       func_800DCB7C
/* DCF914 80242C44 0280382D */   daddu    $a3, $s4, $zero
/* DCF918 80242C48 10400019 */  beqz      $v0, .L80242CB0
/* DCF91C 80242C4C 00000000 */   nop      
/* DCF920 80242C50 C640001C */  lwc1      $f0, 0x1c($s2)
/* DCF924 80242C54 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* DCF928 80242C58 46000005 */  abs.s     $f0, $f0
/* DCF92C 80242C5C 4600103C */  c.lt.s    $f2, $f0
/* DCF930 80242C60 00000000 */  nop       
/* DCF934 80242C64 45000012 */  bc1f      .L80242CB0
/* DCF938 80242C68 00000000 */   nop      
/* DCF93C 80242C6C C7A40024 */  lwc1      $f4, 0x24($sp)
/* DCF940 80242C70 C6400064 */  lwc1      $f0, 0x64($s2)
/* DCF944 80242C74 46002001 */  sub.s     $f0, $f4, $f0
/* DCF948 80242C78 3C014034 */  lui       $at, 0x4034
/* DCF94C 80242C7C 44811800 */  mtc1      $at, $f3
/* DCF950 80242C80 44801000 */  mtc1      $zero, $f2
/* DCF954 80242C84 46000005 */  abs.s     $f0, $f0
/* DCF958 80242C88 46000021 */  cvt.d.s   $f0, $f0
/* DCF95C 80242C8C 4622003C */  c.lt.d    $f0, $f2
/* DCF960 80242C90 00000000 */  nop       
/* DCF964 80242C94 45000006 */  bc1f      .L80242CB0
/* DCF968 80242C98 0240202D */   daddu    $a0, $s2, $zero
/* DCF96C 80242C9C 8E450018 */  lw        $a1, 0x18($s2)
/* DCF970 80242CA0 8E46000C */  lw        $a2, 0xc($s2)
/* DCF974 80242CA4 2416000A */  addiu     $s6, $zero, 0xa
/* DCF978 80242CA8 0C00EA95 */  jal       npc_move_heading
/* DCF97C 80242CAC E644003C */   swc1     $f4, 0x3c($s2)
.L80242CB0:
/* DCF980 80242CB0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DCF984 80242CB4 3C013FF0 */  lui       $at, 0x3ff0
/* DCF988 80242CB8 44811800 */  mtc1      $at, $f3
/* DCF98C 80242CBC 44801000 */  mtc1      $zero, $f2
/* DCF990 80242CC0 46000021 */  cvt.d.s   $f0, $f0
/* DCF994 80242CC4 4622003C */  c.lt.d    $f0, $f2
/* DCF998 80242CC8 00000000 */  nop       
/* DCF99C 80242CCC 45030001 */  bc1tl     .L80242CD4
/* DCF9A0 80242CD0 2416000B */   addiu    $s6, $zero, 0xb
.L80242CD4:
/* DCF9A4 80242CD4 9642008E */  lhu       $v0, 0x8e($s2)
/* DCF9A8 80242CD8 2442FFFF */  addiu     $v0, $v0, -1
/* DCF9AC 80242CDC A642008E */  sh        $v0, 0x8e($s2)
/* DCF9B0 80242CE0 00021400 */  sll       $v0, $v0, 0x10
/* DCF9B4 80242CE4 58400001 */  blezl     $v0, .L80242CEC
/* DCF9B8 80242CE8 24160014 */   addiu    $s6, $zero, 0x14
.L80242CEC:
/* DCF9BC 80242CEC 56C00019 */  bnel      $s6, $zero, .L80242D54
/* DCF9C0 80242CF0 AFA00010 */   sw       $zero, 0x10($sp)
/* DCF9C4 80242CF4 8E620070 */  lw        $v0, 0x70($s3)
/* DCF9C8 80242CF8 30420001 */  andi      $v0, $v0, 1
/* DCF9CC 80242CFC 10400009 */  beqz      $v0, .L80242D24
/* DCF9D0 80242D00 00000000 */   nop      
/* DCF9D4 80242D04 C640004C */  lwc1      $f0, 0x4c($s2)
/* DCF9D8 80242D08 3C014044 */  lui       $at, 0x4044
/* DCF9DC 80242D0C 44811800 */  mtc1      $at, $f3
/* DCF9E0 80242D10 44801000 */  mtc1      $zero, $f2
/* DCF9E4 80242D14 46000021 */  cvt.d.s   $f0, $f0
/* DCF9E8 80242D18 46220000 */  add.d     $f0, $f0, $f2
/* DCF9EC 80242D1C 46200020 */  cvt.s.d   $f0, $f0
/* DCF9F0 80242D20 E640004C */  swc1      $f0, 0x4c($s2)
.L80242D24:
/* DCF9F4 80242D24 8E450018 */  lw        $a1, 0x18($s2)
/* DCF9F8 80242D28 8E46000C */  lw        $a2, 0xc($s2)
/* DCF9FC 80242D2C 0C00EA95 */  jal       npc_move_heading
/* DCFA00 80242D30 0240202D */   daddu    $a0, $s2, $zero
/* DCFA04 80242D34 C644003C */  lwc1      $f4, 0x3c($s2)
/* DCFA08 80242D38 C640001C */  lwc1      $f0, 0x1c($s2)
/* DCFA0C 80242D3C 46002100 */  add.s     $f4, $f4, $f0
/* DCFA10 80242D40 C6420014 */  lwc1      $f2, 0x14($s2)
/* DCFA14 80242D44 46020001 */  sub.s     $f0, $f0, $f2
/* DCFA18 80242D48 E644003C */  swc1      $f4, 0x3c($s2)
/* DCFA1C 80242D4C 08090B70 */  j         .L80242DC0
/* DCFA20 80242D50 E640001C */   swc1     $f0, 0x1c($s2)
.L80242D54:
/* DCFA24 80242D54 AFA00014 */  sw        $zero, 0x14($sp)
/* DCFA28 80242D58 8E450038 */  lw        $a1, 0x38($s2)
/* DCFA2C 80242D5C 8E46003C */  lw        $a2, 0x3c($s2)
/* DCFA30 80242D60 8E470040 */  lw        $a3, 0x40($s2)
/* DCFA34 80242D64 0C01BECC */  jal       fx_walk_normal
/* DCFA38 80242D68 24040002 */   addiu    $a0, $zero, 2
/* DCFA3C 80242D6C 3C01C47A */  lui       $at, 0xc47a
/* DCFA40 80242D70 44810000 */  mtc1      $at, $f0
/* DCFA44 80242D74 AE60006C */  sw        $zero, 0x6c($s3)
/* DCFA48 80242D78 8E420000 */  lw        $v0, ($s2)
/* DCFA4C 80242D7C 0240202D */  daddu     $a0, $s2, $zero
/* DCFA50 80242D80 AE400038 */  sw        $zero, 0x38($s2)
/* DCFA54 80242D84 AE400040 */  sw        $zero, 0x40($s2)
/* DCFA58 80242D88 AE40001C */  sw        $zero, 0x1c($s2)
/* DCFA5C 80242D8C 34420002 */  ori       $v0, $v0, 2
/* DCFA60 80242D90 E640003C */  swc1      $f0, 0x3c($s2)
/* DCFA64 80242D94 0C00EAFF */  jal       disable_npc_shadow
/* DCFA68 80242D98 AE420000 */   sw       $v0, ($s2)
/* DCFA6C 80242D9C 8E420000 */  lw        $v0, ($s2)
/* DCFA70 80242DA0 2403F7FF */  addiu     $v1, $zero, -0x801
/* DCFA74 80242DA4 00431024 */  and       $v0, $v0, $v1
/* DCFA78 80242DA8 AE420000 */  sw        $v0, ($s2)
/* DCFA7C 80242DAC 8E620000 */  lw        $v0, ($s3)
/* DCFA80 80242DB0 3C031F00 */  lui       $v1, 0x1f00
/* DCFA84 80242DB4 00431025 */  or        $v0, $v0, $v1
/* DCFA88 80242DB8 AE620000 */  sw        $v0, ($s3)
/* DCFA8C 80242DBC AEE00070 */  sw        $zero, 0x70($s7)
.L80242DC0:
/* DCFA90 80242DC0 0000102D */  daddu     $v0, $zero, $zero
.L80242DC4:
/* DCFA94 80242DC4 8FBF0050 */  lw        $ra, 0x50($sp)
/* DCFA98 80242DC8 8FB7004C */  lw        $s7, 0x4c($sp)
/* DCFA9C 80242DCC 8FB60048 */  lw        $s6, 0x48($sp)
/* DCFAA0 80242DD0 8FB50044 */  lw        $s5, 0x44($sp)
/* DCFAA4 80242DD4 8FB40040 */  lw        $s4, 0x40($sp)
/* DCFAA8 80242DD8 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCFAAC 80242DDC 8FB20038 */  lw        $s2, 0x38($sp)
/* DCFAB0 80242DE0 8FB10034 */  lw        $s1, 0x34($sp)
/* DCFAB4 80242DE4 8FB00030 */  lw        $s0, 0x30($sp)
/* DCFAB8 80242DE8 03E00008 */  jr        $ra
/* DCFABC 80242DEC 27BD0058 */   addiu    $sp, $sp, 0x58
