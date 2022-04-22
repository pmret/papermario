.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80246F20_DC41D0
.word .L80241818_DBEAC8, .L80241828_DBEAD8, .L80241840_DBEAF0, .L80241850_DBEB00, .L80241868_DBEB18, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241880_DBEB30, .L80241890_DBEB40, .L802418A8_DBEB58, .L802418B8_DBEB68, .L802418D0_DBEB80, .L802418F0_DBEBA0, .L80241910_DBEBC0, .L80241930_DBEBE0, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241950_DBEC00, .L80241948_DBEBF8

.section .text

glabel func_80241634_DBE8E4
/* DBE8E4 80241634 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DBE8E8 80241638 AFB30054 */  sw        $s3, 0x54($sp)
/* DBE8EC 8024163C 0080982D */  daddu     $s3, $a0, $zero
/* DBE8F0 80241640 AFBF0060 */  sw        $ra, 0x60($sp)
/* DBE8F4 80241644 AFB5005C */  sw        $s5, 0x5c($sp)
/* DBE8F8 80241648 AFB40058 */  sw        $s4, 0x58($sp)
/* DBE8FC 8024164C AFB20050 */  sw        $s2, 0x50($sp)
/* DBE900 80241650 AFB1004C */  sw        $s1, 0x4c($sp)
/* DBE904 80241654 AFB00048 */  sw        $s0, 0x48($sp)
/* DBE908 80241658 8E710148 */  lw        $s1, 0x148($s3)
/* DBE90C 8024165C 86240008 */  lh        $a0, 8($s1)
/* DBE910 80241660 0C00EABB */  jal       get_npc_unsafe
/* DBE914 80241664 00A0802D */   daddu    $s0, $a1, $zero
/* DBE918 80241668 8E63000C */  lw        $v1, 0xc($s3)
/* DBE91C 8024166C 0260202D */  daddu     $a0, $s3, $zero
/* DBE920 80241670 8C650000 */  lw        $a1, ($v1)
/* DBE924 80241674 0C0B1EAF */  jal       evt_get_variable
/* DBE928 80241678 0040902D */   daddu    $s2, $v0, $zero
/* DBE92C 8024167C AFA00018 */  sw        $zero, 0x18($sp)
/* DBE930 80241680 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBE934 80241684 8C630094 */  lw        $v1, 0x94($v1)
/* DBE938 80241688 AFA3001C */  sw        $v1, 0x1c($sp)
/* DBE93C 8024168C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBE940 80241690 8C630080 */  lw        $v1, 0x80($v1)
/* DBE944 80241694 AFA30020 */  sw        $v1, 0x20($sp)
/* DBE948 80241698 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBE94C 8024169C 8C630088 */  lw        $v1, 0x88($v1)
/* DBE950 802416A0 AFA30024 */  sw        $v1, 0x24($sp)
/* DBE954 802416A4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBE958 802416A8 8C63008C */  lw        $v1, 0x8c($v1)
/* DBE95C 802416AC 27B50018 */  addiu     $s5, $sp, 0x18
/* DBE960 802416B0 AFA30028 */  sw        $v1, 0x28($sp)
/* DBE964 802416B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBE968 802416B8 3C014282 */  lui       $at, 0x4282
/* DBE96C 802416BC 44810000 */  mtc1      $at, $f0
/* DBE970 802416C0 8C630090 */  lw        $v1, 0x90($v1)
/* DBE974 802416C4 0040A02D */  daddu     $s4, $v0, $zero
/* DBE978 802416C8 E7A00030 */  swc1      $f0, 0x30($sp)
/* DBE97C 802416CC A7A00034 */  sh        $zero, 0x34($sp)
/* DBE980 802416D0 16000005 */  bnez      $s0, .L802416E8
/* DBE984 802416D4 AFA3002C */   sw       $v1, 0x2c($sp)
/* DBE988 802416D8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBE98C 802416DC 30420004 */  andi      $v0, $v0, 4
/* DBE990 802416E0 10400044 */  beqz      $v0, .L802417F4
/* DBE994 802416E4 00000000 */   nop
.L802416E8:
/* DBE998 802416E8 2404F7FF */  addiu     $a0, $zero, -0x801
/* DBE99C 802416EC AE600070 */  sw        $zero, 0x70($s3)
/* DBE9A0 802416F0 A640008E */  sh        $zero, 0x8e($s2)
/* DBE9A4 802416F4 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBE9A8 802416F8 8E430000 */  lw        $v1, ($s2)
/* DBE9AC 802416FC 8C420000 */  lw        $v0, ($v0)
/* DBE9B0 80241700 00641824 */  and       $v1, $v1, $a0
/* DBE9B4 80241704 AE430000 */  sw        $v1, ($s2)
/* DBE9B8 80241708 AE420028 */  sw        $v0, 0x28($s2)
/* DBE9BC 8024170C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBE9C0 80241710 8C420098 */  lw        $v0, 0x98($v0)
/* DBE9C4 80241714 54400005 */  bnel      $v0, $zero, .L8024172C
/* DBE9C8 80241718 2402FDFF */   addiu    $v0, $zero, -0x201
/* DBE9CC 8024171C 34620200 */  ori       $v0, $v1, 0x200
/* DBE9D0 80241720 2403FFF7 */  addiu     $v1, $zero, -9
/* DBE9D4 80241724 080905CD */  j         .L80241734
/* DBE9D8 80241728 00431024 */   and      $v0, $v0, $v1
.L8024172C:
/* DBE9DC 8024172C 00621024 */  and       $v0, $v1, $v0
/* DBE9E0 80241730 34420008 */  ori       $v0, $v0, 8
.L80241734:
/* DBE9E4 80241734 AE420000 */  sw        $v0, ($s2)
/* DBE9E8 80241738 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBE9EC 8024173C 30420004 */  andi      $v0, $v0, 4
/* DBE9F0 80241740 10400008 */  beqz      $v0, .L80241764
/* DBE9F4 80241744 24020063 */   addiu    $v0, $zero, 0x63
/* DBE9F8 80241748 AE620070 */  sw        $v0, 0x70($s3)
/* DBE9FC 8024174C AE600074 */  sw        $zero, 0x74($s3)
/* DBEA00 80241750 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBEA04 80241754 2403FFFB */  addiu     $v1, $zero, -5
/* DBEA08 80241758 00431024 */  and       $v0, $v0, $v1
/* DBEA0C 8024175C 080905E4 */  j         .L80241790
/* DBEA10 80241760 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241764:
/* DBEA14 80241764 8E220000 */  lw        $v0, ($s1)
/* DBEA18 80241768 3C034000 */  lui       $v1, 0x4000
/* DBEA1C 8024176C 00431024 */  and       $v0, $v0, $v1
/* DBEA20 80241770 10400007 */  beqz      $v0, .L80241790
/* DBEA24 80241774 3C03BFFF */   lui      $v1, 0xbfff
/* DBEA28 80241778 2402000C */  addiu     $v0, $zero, 0xc
/* DBEA2C 8024177C AE620070 */  sw        $v0, 0x70($s3)
/* DBEA30 80241780 8E220000 */  lw        $v0, ($s1)
/* DBEA34 80241784 3463FFFF */  ori       $v1, $v1, 0xffff
/* DBEA38 80241788 00431024 */  and       $v0, $v0, $v1
/* DBEA3C 8024178C AE220000 */  sw        $v0, ($s1)
.L80241790:
/* DBEA40 80241790 27A50038 */  addiu     $a1, $sp, 0x38
/* DBEA44 80241794 27A6003C */  addiu     $a2, $sp, 0x3c
/* DBEA48 80241798 C6400038 */  lwc1      $f0, 0x38($s2)
/* DBEA4C 8024179C 864200A8 */  lh        $v0, 0xa8($s2)
/* DBEA50 802417A0 3C0142C8 */  lui       $at, 0x42c8
/* DBEA54 802417A4 44812000 */  mtc1      $at, $f4
/* DBEA58 802417A8 44823000 */  mtc1      $v0, $f6
/* DBEA5C 802417AC 00000000 */  nop
/* DBEA60 802417B0 468031A0 */  cvt.s.w   $f6, $f6
/* DBEA64 802417B4 27A20044 */  addiu     $v0, $sp, 0x44
/* DBEA68 802417B8 E7A00038 */  swc1      $f0, 0x38($sp)
/* DBEA6C 802417BC C640003C */  lwc1      $f0, 0x3c($s2)
/* DBEA70 802417C0 C6420040 */  lwc1      $f2, 0x40($s2)
/* DBEA74 802417C4 46060000 */  add.s     $f0, $f0, $f6
/* DBEA78 802417C8 E7A40044 */  swc1      $f4, 0x44($sp)
/* DBEA7C 802417CC E7A20040 */  swc1      $f2, 0x40($sp)
/* DBEA80 802417D0 E7A0003C */  swc1      $f0, 0x3c($sp)
/* DBEA84 802417D4 AFA20010 */  sw        $v0, 0x10($sp)
/* DBEA88 802417D8 8E440080 */  lw        $a0, 0x80($s2)
/* DBEA8C 802417DC 0C0372DF */  jal       npc_raycast_down_sides
/* DBEA90 802417E0 27A70040 */   addiu    $a3, $sp, 0x40
/* DBEA94 802417E4 10400003 */  beqz      $v0, .L802417F4
/* DBEA98 802417E8 00000000 */   nop
/* DBEA9C 802417EC C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DBEAA0 802417F0 E640003C */  swc1      $f0, 0x3c($s2)
.L802417F4:
/* DBEAA4 802417F4 8E630070 */  lw        $v1, 0x70($s3)
/* DBEAA8 802417F8 2C620064 */  sltiu     $v0, $v1, 0x64
/* DBEAAC 802417FC 10400054 */  beqz      $v0, .L80241950_DBEC00
/* DBEAB0 80241800 00031080 */   sll      $v0, $v1, 2
/* DBEAB4 80241804 3C018024 */  lui       $at, %hi(jtbl_80246F20_DC41D0)
/* DBEAB8 80241808 00220821 */  addu      $at, $at, $v0
/* DBEABC 8024180C 8C226F20 */  lw        $v0, %lo(jtbl_80246F20_DC41D0)($at)
/* DBEAC0 80241810 00400008 */  jr        $v0
/* DBEAC4 80241814 00000000 */   nop
.L80241818_DBEAC8:
/* DBEAC8 80241818 0260202D */  daddu     $a0, $s3, $zero
/* DBEACC 8024181C 0280282D */  daddu     $a1, $s4, $zero
/* DBEAD0 80241820 0C09015B */  jal       omo_07_PatrolAI_MoveInit
/* DBEAD4 80241824 02A0302D */   daddu    $a2, $s5, $zero
.L80241828_DBEAD8:
/* DBEAD8 80241828 0260202D */  daddu     $a0, $s3, $zero
/* DBEADC 8024182C 0280282D */  daddu     $a1, $s4, $zero
/* DBEAE0 80241830 0C0901B1 */  jal       omo_07_PatrolAI_Move
/* DBEAE4 80241834 02A0302D */   daddu    $a2, $s5, $zero
/* DBEAE8 80241838 08090654 */  j         .L80241950_DBEC00
/* DBEAEC 8024183C 00000000 */   nop
.L80241840_DBEAF0:
/* DBEAF0 80241840 0260202D */  daddu     $a0, $s3, $zero
/* DBEAF4 80241844 0280282D */  daddu     $a1, $s4, $zero
/* DBEAF8 80241848 0C09025B */  jal       omo_07_UnkNpcAIFunc1
/* DBEAFC 8024184C 02A0302D */   daddu    $a2, $s5, $zero
.L80241850_DBEB00:
/* DBEB00 80241850 0260202D */  daddu     $a0, $s3, $zero
/* DBEB04 80241854 0280282D */  daddu     $a1, $s4, $zero
/* DBEB08 80241858 0C09028B */  jal       omo_07_PatrolAI_Loiter
/* DBEB0C 8024185C 02A0302D */   daddu    $a2, $s5, $zero
/* DBEB10 80241860 08090654 */  j         .L80241950_DBEC00
/* DBEB14 80241864 00000000 */   nop
.L80241868_DBEB18:
/* DBEB18 80241868 0260202D */  daddu     $a0, $s3, $zero
/* DBEB1C 8024186C 0280282D */  daddu     $a1, $s4, $zero
/* DBEB20 80241870 0C0902FA */  jal       omo_07_PatrolAI_PostLoiter
/* DBEB24 80241874 02A0302D */   daddu    $a2, $s5, $zero
/* DBEB28 80241878 08090654 */  j         .L80241950_DBEC00
/* DBEB2C 8024187C 00000000 */   nop
.L80241880_DBEB30:
/* DBEB30 80241880 0260202D */  daddu     $a0, $s3, $zero
/* DBEB34 80241884 0280282D */  daddu     $a1, $s4, $zero
/* DBEB38 80241888 0C090327 */  jal       omo_07_NpcJumpFunc2
/* DBEB3C 8024188C 02A0302D */   daddu    $a2, $s5, $zero
.L80241890_DBEB40:
/* DBEB40 80241890 0260202D */  daddu     $a0, $s3, $zero
/* DBEB44 80241894 0280282D */  daddu     $a1, $s4, $zero
/* DBEB48 80241898 0C090344 */  jal       omo_07_NpcJumpFunc
/* DBEB4C 8024189C 02A0302D */   daddu    $a2, $s5, $zero
/* DBEB50 802418A0 08090654 */  j         .L80241950_DBEC00
/* DBEB54 802418A4 00000000 */   nop
.L802418A8_DBEB58:
/* DBEB58 802418A8 0260202D */  daddu     $a0, $s3, $zero
/* DBEB5C 802418AC 0280282D */  daddu     $a1, $s4, $zero
/* DBEB60 802418B0 0C090362 */  jal       omo_07_FlyingNoFirstStrikeAI_12
/* DBEB64 802418B4 02A0302D */   daddu    $a2, $s5, $zero
.L802418B8_DBEB68:
/* DBEB68 802418B8 0260202D */  daddu     $a0, $s3, $zero
/* DBEB6C 802418BC 0280282D */  daddu     $a1, $s4, $zero
/* DBEB70 802418C0 0C0903AE */  jal       omo_07_UnkFunc15
/* DBEB74 802418C4 02A0302D */   daddu    $a2, $s5, $zero
/* DBEB78 802418C8 08090654 */  j         .L80241950_DBEC00
/* DBEB7C 802418CC 00000000 */   nop
.L802418D0_DBEB80:
/* DBEB80 802418D0 0260202D */  daddu     $a0, $s3, $zero
/* DBEB84 802418D4 0280282D */  daddu     $a1, $s4, $zero
/* DBEB88 802418D8 0C0904FF */  jal       func_802413FC_DBE6AC
/* DBEB8C 802418DC 02A0302D */   daddu    $a2, $s5, $zero
/* DBEB90 802418E0 8E630070 */  lw        $v1, 0x70($s3)
/* DBEB94 802418E4 2402000F */  addiu     $v0, $zero, 0xf
/* DBEB98 802418E8 14620019 */  bne       $v1, $v0, .L80241950_DBEC00
/* DBEB9C 802418EC 00000000 */   nop
.L802418F0_DBEBA0:
/* DBEBA0 802418F0 0260202D */  daddu     $a0, $s3, $zero
/* DBEBA4 802418F4 0280282D */  daddu     $a1, $s4, $zero
/* DBEBA8 802418F8 0C09051B */  jal       func_8024146C_DBE71C
/* DBEBAC 802418FC 02A0302D */   daddu    $a2, $s5, $zero
/* DBEBB0 80241900 8E630070 */  lw        $v1, 0x70($s3)
/* DBEBB4 80241904 24020010 */  addiu     $v0, $zero, 0x10
/* DBEBB8 80241908 14620011 */  bne       $v1, $v0, .L80241950_DBEC00
/* DBEBBC 8024190C 00000000 */   nop
.L80241910_DBEBC0:
/* DBEBC0 80241910 0260202D */  daddu     $a0, $s3, $zero
/* DBEBC4 80241914 0280282D */  daddu     $a1, $s4, $zero
/* DBEBC8 80241918 0C09054F */  jal       func_8024153C_DBE7EC
/* DBEBCC 8024191C 02A0302D */   daddu    $a2, $s5, $zero
/* DBEBD0 80241920 8E630070 */  lw        $v1, 0x70($s3)
/* DBEBD4 80241924 24020011 */  addiu     $v0, $zero, 0x11
/* DBEBD8 80241928 14620009 */  bne       $v1, $v0, .L80241950_DBEC00
/* DBEBDC 8024192C 00000000 */   nop
.L80241930_DBEBE0:
/* DBEBE0 80241930 0260202D */  daddu     $a0, $s3, $zero
/* DBEBE4 80241934 0280282D */  daddu     $a1, $s4, $zero
/* DBEBE8 80241938 0C090575 */  jal       dup_omo_07_UnkNpcDurationAnimationFunc
/* DBEBEC 8024193C 02A0302D */   daddu    $a2, $s5, $zero
/* DBEBF0 80241940 08090654 */  j         .L80241950_DBEC00
/* DBEBF4 80241944 00000000 */   nop
.L80241948_DBEBF8:
/* DBEBF8 80241948 0C0129CF */  jal       basic_ai_suspend
/* DBEBFC 8024194C 0260202D */   daddu    $a0, $s3, $zero
.L80241950_DBEC00:
/* DBEC00 80241950 8FBF0060 */  lw        $ra, 0x60($sp)
/* DBEC04 80241954 8FB5005C */  lw        $s5, 0x5c($sp)
/* DBEC08 80241958 8FB40058 */  lw        $s4, 0x58($sp)
/* DBEC0C 8024195C 8FB30054 */  lw        $s3, 0x54($sp)
/* DBEC10 80241960 8FB20050 */  lw        $s2, 0x50($sp)
/* DBEC14 80241964 8FB1004C */  lw        $s1, 0x4c($sp)
/* DBEC18 80241968 8FB00048 */  lw        $s0, 0x48($sp)
/* DBEC1C 8024196C 0000102D */  daddu     $v0, $zero, $zero
/* DBEC20 80241970 03E00008 */  jr        $ra
/* DBEC24 80241974 27BD0068 */   addiu    $sp, $sp, 0x68
