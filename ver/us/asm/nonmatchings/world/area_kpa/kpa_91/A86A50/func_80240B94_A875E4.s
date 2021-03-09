.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_A875E4
/* A875E4 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A875E8 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* A875EC 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* A875F0 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* A875F4 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* A875F8 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* A875FC 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* A87600 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* A87604 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* A87608 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* A8760C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* A87610 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* A87614 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* A87618 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* A8761C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* A87620 80240BD0 8C650000 */  lw        $a1, ($v1)
/* A87624 80240BD4 0C0B1EAF */  jal       get_variable
/* A87628 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* A8762C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* A87630 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A87634 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* A87638 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* A8763C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A87640 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* A87644 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* A87648 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8764C 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* A87650 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* A87654 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A87658 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* A8765C 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* A87660 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* A87664 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A87668 80240C18 3C014282 */  lui       $at, 0x4282
/* A8766C 80240C1C 44810000 */  mtc1      $at, $f0
/* A87670 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* A87674 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* A87678 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* A8767C 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* A87680 80240C30 16000005 */  bnez      $s0, .L80240C48
/* A87684 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* A87688 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A8768C 80240C3C 30420004 */  andi      $v0, $v0, 4
/* A87690 80240C40 10400044 */  beqz      $v0, .L80240D54
/* A87694 80240C44 00000000 */   nop
.L80240C48:
/* A87698 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* A8769C 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* A876A0 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* A876A4 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* A876A8 80240C58 8E430000 */  lw        $v1, ($s2)
/* A876AC 80240C5C 8C420000 */  lw        $v0, ($v0)
/* A876B0 80240C60 00641824 */  and       $v1, $v1, $a0
/* A876B4 80240C64 AE430000 */  sw        $v1, ($s2)
/* A876B8 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* A876BC 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A876C0 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* A876C4 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* A876C8 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* A876CC 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* A876D0 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* A876D4 80240C84 08090325 */  j         .L80240C94
/* A876D8 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* A876DC 80240C8C 00621024 */  and       $v0, $v1, $v0
/* A876E0 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* A876E4 80240C94 AE420000 */  sw        $v0, ($s2)
/* A876E8 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A876EC 80240C9C 30420004 */  andi      $v0, $v0, 4
/* A876F0 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* A876F4 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* A876F8 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* A876FC 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* A87700 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A87704 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* A87708 80240CB8 00431024 */  and       $v0, $v0, $v1
/* A8770C 80240CBC 0809033C */  j         .L80240CF0
/* A87710 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* A87714 80240CC4 8E220000 */  lw        $v0, ($s1)
/* A87718 80240CC8 3C034000 */  lui       $v1, 0x4000
/* A8771C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* A87720 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* A87724 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* A87728 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* A8772C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* A87730 80240CE0 8E220000 */  lw        $v0, ($s1)
/* A87734 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* A87738 80240CE8 00431024 */  and       $v0, $v0, $v1
/* A8773C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* A87740 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* A87744 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* A87748 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* A8774C 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* A87750 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* A87754 80240D04 44812000 */  mtc1      $at, $f4
/* A87758 80240D08 44823000 */  mtc1      $v0, $f6
/* A8775C 80240D0C 00000000 */  nop
/* A87760 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* A87764 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* A87768 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* A8776C 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* A87770 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* A87774 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* A87778 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* A8777C 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* A87780 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* A87784 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* A87788 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* A8778C 80240D3C 0C0372DF */  jal       func_800DCB7C
/* A87790 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* A87794 80240D44 10400003 */  beqz      $v0, .L80240D54
/* A87798 80240D48 00000000 */   nop
/* A8779C 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* A877A0 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* A877A4 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* A877A8 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* A877AC 80240D5C 10400042 */  beqz      $v0, L80240E68_A878B8
/* A877B0 80240D60 00031080 */   sll      $v0, $v1, 2
/* A877B4 80240D64 3C018024 */  lui       $at, %hi(jtbl_80245A40_A8C490)
/* A877B8 80240D68 00220821 */  addu      $at, $at, $v0
/* A877BC 80240D6C 8C225A40 */  lw        $v0, %lo(jtbl_80245A40_A8C490)($at)
/* A877C0 80240D70 00400008 */  jr        $v0
/* A877C4 80240D74 00000000 */   nop
glabel L80240D78_A877C8
/* A877C8 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* A877CC 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* A877D0 80240D80 0C090000 */  jal       func_80240000_A86A50
/* A877D4 80240D84 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240D88_A877D8
/* A877D8 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* A877DC 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* A877E0 80240D90 0C090056 */  jal       func_80240158_A86BA8
/* A877E4 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* A877E8 80240D98 0809039A */  j         L80240E68_A878B8
/* A877EC 80240D9C 00000000 */   nop
glabel L80240DA0_A877F0
/* A877F0 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* A877F4 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* A877F8 80240DA8 0C090100 */  jal       kpa_91_UnkNpcAIFunc1
/* A877FC 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DB0_A87800
/* A87800 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* A87804 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* A87808 80240DB8 0C090130 */  jal       func_802404C0_A86F10
/* A8780C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* A87810 80240DC0 0809039A */  j         L80240E68_A878B8
/* A87814 80240DC4 00000000 */   nop
glabel L80240DC8_A87818
/* A87818 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* A8781C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* A87820 80240DD0 0C09019F */  jal       func_8024067C_A870CC
/* A87824 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* A87828 80240DD8 0809039A */  j         L80240E68_A878B8
/* A8782C 80240DDC 00000000 */   nop
glabel L80240DE0_A87830
/* A87830 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* A87834 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* A87838 80240DE8 0C0901CC */  jal       kpa_91_NpcJumpFunc2
/* A8783C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DF0_A87840
/* A87840 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* A87844 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* A87848 80240DF8 0C0901E9 */  jal       kpa_91_NpcJumpFunc
/* A8784C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* A87850 80240E00 0809039A */  j         L80240E68_A878B8
/* A87854 80240E04 00000000 */   nop
glabel L80240E08_A87858
/* A87858 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* A8785C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* A87860 80240E10 0C090207 */  jal       kpa_91_UnkNpcAIFunc13
/* A87864 80240E14 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E18_A87868
/* A87868 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* A8786C 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* A87870 80240E20 0C090253 */  jal       func_8024094C_A8739C
/* A87874 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* A87878 80240E28 0809039A */  j         L80240E68_A878B8
/* A8787C 80240E2C 00000000 */   nop
glabel L80240E30_A87880
/* A87880 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* A87884 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* A87888 80240E38 0C09029B */  jal       kpa_91_UnkNpcDurationFlagFunc
/* A8788C 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* A87890 80240E40 0809039A */  j         L80240E68_A878B8
/* A87894 80240E44 00000000 */   nop
glabel L80240E48_A87898
/* A87898 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* A8789C 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* A878A0 80240E50 0C0902B5 */  jal       func_80240AD4_A87524
/* A878A4 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* A878A8 80240E58 0809039A */  j         L80240E68_A878B8
/* A878AC 80240E5C 00000000 */   nop
glabel L80240E60_A878B0
/* A878B0 80240E60 0C0129CF */  jal       func_8004A73C
/* A878B4 80240E64 0280202D */   daddu    $a0, $s4, $zero
glabel L80240E68_A878B8
/* A878B8 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* A878BC 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* A878C0 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* A878C4 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* A878C8 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* A878CC 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* A878D0 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* A878D4 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* A878D8 80240E88 03E00008 */  jr        $ra
/* A878DC 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
