.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80244CF8_A0BBF8
.word L80240A80_A07980, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A80_A07980, L80240A8C_A0798C, L80240A80_A07980, L80240A8C_A0798C, L80240A80_A07980, L80240A8C_A0798C, L80240A80_A07980, L80240A8C_A0798C, L80240A8C_A0798C, L80240A8C_A0798C, L80240A80_A07980, L80240A8C_A0798C, L80240A80_A07980, 0

.section .text

glabel func_80240674_A07574
/* A07574 80240674 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A07578 80240678 AFB3005C */  sw        $s3, 0x5c($sp)
/* A0757C 8024067C 0080982D */  daddu     $s3, $a0, $zero
/* A07580 80240680 AFBF0068 */  sw        $ra, 0x68($sp)
/* A07584 80240684 AFB50064 */  sw        $s5, 0x64($sp)
/* A07588 80240688 AFB40060 */  sw        $s4, 0x60($sp)
/* A0758C 8024068C AFB20058 */  sw        $s2, 0x58($sp)
/* A07590 80240690 AFB10054 */  sw        $s1, 0x54($sp)
/* A07594 80240694 AFB00050 */  sw        $s0, 0x50($sp)
/* A07598 80240698 8E710148 */  lw        $s1, 0x148($s3)
/* A0759C 8024069C 86240008 */  lh        $a0, 8($s1)
/* A075A0 802406A0 0C00EABB */  jal       get_npc_unsafe
/* A075A4 802406A4 00A0802D */   daddu    $s0, $a1, $zero
/* A075A8 802406A8 8E63000C */  lw        $v1, 0xc($s3)
/* A075AC 802406AC 0260202D */  daddu     $a0, $s3, $zero
/* A075B0 802406B0 8C650000 */  lw        $a1, ($v1)
/* A075B4 802406B4 0C0B1EAF */  jal       evt_get_variable
/* A075B8 802406B8 0040902D */   daddu    $s2, $v0, $zero
/* A075BC 802406BC AFA00028 */  sw        $zero, 0x28($sp)
/* A075C0 802406C0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A075C4 802406C4 8C630030 */  lw        $v1, 0x30($v1)
/* A075C8 802406C8 AFA3002C */  sw        $v1, 0x2c($sp)
/* A075CC 802406CC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A075D0 802406D0 8C63001C */  lw        $v1, 0x1c($v1)
/* A075D4 802406D4 AFA30030 */  sw        $v1, 0x30($sp)
/* A075D8 802406D8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A075DC 802406DC 8C630024 */  lw        $v1, 0x24($v1)
/* A075E0 802406E0 AFA30034 */  sw        $v1, 0x34($sp)
/* A075E4 802406E4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A075E8 802406E8 8C630028 */  lw        $v1, 0x28($v1)
/* A075EC 802406EC 27B50028 */  addiu     $s5, $sp, 0x28
/* A075F0 802406F0 AFA30038 */  sw        $v1, 0x38($sp)
/* A075F4 802406F4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A075F8 802406F8 3C0142C8 */  lui       $at, 0x42c8
/* A075FC 802406FC 44810000 */  mtc1      $at, $f0
/* A07600 80240700 8C63002C */  lw        $v1, 0x2c($v1)
/* A07604 80240704 0040A02D */  daddu     $s4, $v0, $zero
/* A07608 80240708 E7A00040 */  swc1      $f0, 0x40($sp)
/* A0760C 8024070C A7A00044 */  sh        $zero, 0x44($sp)
/* A07610 80240710 12000009 */  beqz      $s0, .L80240738
/* A07614 80240714 AFA3003C */   sw       $v1, 0x3c($sp)
/* A07618 80240718 864300A8 */  lh        $v1, 0xa8($s2)
/* A0761C 8024071C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A07620 80240720 AE20008C */  sw        $zero, 0x8c($s1)
/* A07624 80240724 A22000B5 */  sb        $zero, 0xb5($s1)
/* A07628 80240728 34420008 */  ori       $v0, $v0, 8
/* A0762C 8024072C AE230084 */  sw        $v1, 0x84($s1)
/* A07630 80240730 080901D2 */  j         .L80240748
/* A07634 80240734 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240738:
/* A07638 80240738 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A0763C 8024073C 30420004 */  andi      $v0, $v0, 4
/* A07640 80240740 10400047 */  beqz      $v0, .L80240860
/* A07644 80240744 00000000 */   nop
.L80240748:
/* A07648 80240748 AE600070 */  sw        $zero, 0x70($s3)
/* A0764C 8024074C A640008E */  sh        $zero, 0x8e($s2)
/* A07650 80240750 8E2300CC */  lw        $v1, 0xcc($s1)
/* A07654 80240754 2404F7FF */  addiu     $a0, $zero, -0x801
/* A07658 80240758 A2200007 */  sb        $zero, 7($s1)
/* A0765C 8024075C 8E420000 */  lw        $v0, ($s2)
/* A07660 80240760 8C630000 */  lw        $v1, ($v1)
/* A07664 80240764 00441024 */  and       $v0, $v0, $a0
/* A07668 80240768 AE420000 */  sw        $v0, ($s2)
/* A0766C 8024076C AE430028 */  sw        $v1, 0x28($s2)
/* A07670 80240770 96220086 */  lhu       $v0, 0x86($s1)
/* A07674 80240774 A64200A8 */  sh        $v0, 0xa8($s2)
/* A07678 80240778 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A0767C 8024077C AE200090 */  sw        $zero, 0x90($s1)
/* A07680 80240780 8C420034 */  lw        $v0, 0x34($v0)
/* A07684 80240784 14400006 */  bnez      $v0, .L802407A0
/* A07688 80240788 2403FDFF */   addiu    $v1, $zero, -0x201
/* A0768C 8024078C 8E420000 */  lw        $v0, ($s2)
/* A07690 80240790 2403FFF7 */  addiu     $v1, $zero, -9
/* A07694 80240794 34420200 */  ori       $v0, $v0, 0x200
/* A07698 80240798 080901EB */  j         .L802407AC
/* A0769C 8024079C 00431024 */   and      $v0, $v0, $v1
.L802407A0:
/* A076A0 802407A0 8E420000 */  lw        $v0, ($s2)
/* A076A4 802407A4 00431024 */  and       $v0, $v0, $v1
/* A076A8 802407A8 34420008 */  ori       $v0, $v0, 8
.L802407AC:
/* A076AC 802407AC AE420000 */  sw        $v0, ($s2)
/* A076B0 802407B0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A076B4 802407B4 30420004 */  andi      $v0, $v0, 4
/* A076B8 802407B8 1040001E */  beqz      $v0, .L80240834
/* A076BC 802407BC 24040002 */   addiu    $a0, $zero, 2
/* A076C0 802407C0 0240282D */  daddu     $a1, $s2, $zero
/* A076C4 802407C4 0000302D */  daddu     $a2, $zero, $zero
/* A076C8 802407C8 24020063 */  addiu     $v0, $zero, 0x63
/* A076CC 802407CC AE620070 */  sw        $v0, 0x70($s3)
/* A076D0 802407D0 AE600074 */  sw        $zero, 0x74($s3)
/* A076D4 802407D4 864300A8 */  lh        $v1, 0xa8($s2)
/* A076D8 802407D8 3C013F80 */  lui       $at, 0x3f80
/* A076DC 802407DC 44810000 */  mtc1      $at, $f0
/* A076E0 802407E0 3C014000 */  lui       $at, 0x4000
/* A076E4 802407E4 44811000 */  mtc1      $at, $f2
/* A076E8 802407E8 3C01C1A0 */  lui       $at, 0xc1a0
/* A076EC 802407EC 44812000 */  mtc1      $at, $f4
/* A076F0 802407F0 24020028 */  addiu     $v0, $zero, 0x28
/* A076F4 802407F4 AFA2001C */  sw        $v0, 0x1c($sp)
/* A076F8 802407F8 44833000 */  mtc1      $v1, $f6
/* A076FC 802407FC 00000000 */  nop
/* A07700 80240800 468031A0 */  cvt.s.w   $f6, $f6
/* A07704 80240804 44073000 */  mfc1      $a3, $f6
/* A07708 80240808 27A20048 */  addiu     $v0, $sp, 0x48
/* A0770C 8024080C AFA20020 */  sw        $v0, 0x20($sp)
/* A07710 80240810 E7A00010 */  swc1      $f0, 0x10($sp)
/* A07714 80240814 E7A20014 */  swc1      $f2, 0x14($sp)
/* A07718 80240818 0C01BFA4 */  jal       fx_emote
/* A0771C 8024081C E7A40018 */   swc1     $f4, 0x18($sp)
/* A07720 80240820 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A07724 80240824 2403FFFB */  addiu     $v1, $zero, -5
/* A07728 80240828 00431024 */  and       $v0, $v0, $v1
/* A0772C 8024082C 08090218 */  j         .L80240860
/* A07730 80240830 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240834:
/* A07734 80240834 8E220000 */  lw        $v0, ($s1)
/* A07738 80240838 3C034000 */  lui       $v1, 0x4000
/* A0773C 8024083C 00431024 */  and       $v0, $v0, $v1
/* A07740 80240840 10400007 */  beqz      $v0, .L80240860
/* A07744 80240844 3C03BFFF */   lui      $v1, 0xbfff
/* A07748 80240848 2402000C */  addiu     $v0, $zero, 0xc
/* A0774C 8024084C AE620070 */  sw        $v0, 0x70($s3)
/* A07750 80240850 8E220000 */  lw        $v0, ($s1)
/* A07754 80240854 3463FFFF */  ori       $v1, $v1, 0xffff
/* A07758 80240858 00431024 */  and       $v0, $v0, $v1
/* A0775C 8024085C AE220000 */  sw        $v0, ($s1)
.L80240860:
/* A07760 80240860 8E220090 */  lw        $v0, 0x90($s1)
/* A07764 80240864 1840000C */  blez      $v0, .L80240898
/* A07768 80240868 2442FFFF */   addiu    $v0, $v0, -1
/* A0776C 8024086C 14400087 */  bnez      $v0, L80240A8C_A0798C
/* A07770 80240870 AE220090 */   sw       $v0, 0x90($s1)
/* A07774 80240874 3C03FFAA */  lui       $v1, 0xffaa
/* A07778 80240878 8E420028 */  lw        $v0, 0x28($s2)
/* A0777C 8024087C 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* A07780 80240880 00431021 */  addu      $v0, $v0, $v1
/* A07784 80240884 2C420002 */  sltiu     $v0, $v0, 2
/* A07788 80240888 10400003 */  beqz      $v0, .L80240898
/* A0778C 8024088C 3C020055 */   lui      $v0, 0x55
/* A07790 80240890 3442000C */  ori       $v0, $v0, 0xc
/* A07794 80240894 AE420028 */  sw        $v0, 0x28($s2)
.L80240898:
/* A07798 80240898 8E630070 */  lw        $v1, 0x70($s3)
/* A0779C 8024089C 2402000C */  addiu     $v0, $zero, 0xc
/* A077A0 802408A0 10620048 */  beq       $v1, $v0, .L802409C4
/* A077A4 802408A4 2862000D */   slti     $v0, $v1, 0xd
/* A077A8 802408A8 1040000F */  beqz      $v0, .L802408E8
/* A077AC 802408AC 24100001 */   addiu    $s0, $zero, 1
/* A077B0 802408B0 1070001E */  beq       $v1, $s0, .L8024092C
/* A077B4 802408B4 28620002 */   slti     $v0, $v1, 2
/* A077B8 802408B8 10400005 */  beqz      $v0, .L802408D0
/* A077BC 802408BC 24020002 */   addiu    $v0, $zero, 2
/* A077C0 802408C0 10600015 */  beqz      $v1, .L80240918
/* A077C4 802408C4 0260202D */   daddu    $a0, $s3, $zero
/* A077C8 802408C8 08090288 */  j         .L80240A20
/* A077CC 802408CC 00000000 */   nop
.L802408D0:
/* A077D0 802408D0 1062001C */  beq       $v1, $v0, .L80240944
/* A077D4 802408D4 24020003 */   addiu    $v0, $zero, 3
/* A077D8 802408D8 10620035 */  beq       $v1, $v0, .L802409B0
/* A077DC 802408DC 0260202D */   daddu    $a0, $s3, $zero
/* A077E0 802408E0 08090288 */  j         .L80240A20
/* A077E4 802408E4 00000000 */   nop
.L802408E8:
/* A077E8 802408E8 2402000E */  addiu     $v0, $zero, 0xe
/* A077EC 802408EC 1062003F */  beq       $v1, $v0, .L802409EC
/* A077F0 802408F0 0062102A */   slt      $v0, $v1, $v0
/* A077F4 802408F4 14400038 */  bnez      $v0, .L802409D8
/* A077F8 802408F8 0260202D */   daddu    $a0, $s3, $zero
/* A077FC 802408FC 2402000F */  addiu     $v0, $zero, 0xf
/* A07800 80240900 10620040 */  beq       $v1, $v0, .L80240A04
/* A07804 80240904 24020063 */   addiu    $v0, $zero, 0x63
/* A07808 80240908 10620043 */  beq       $v1, $v0, .L80240A18
/* A0780C 8024090C 00000000 */   nop
/* A07810 80240910 08090288 */  j         .L80240A20
/* A07814 80240914 00000000 */   nop
.L80240918:
/* A07818 80240918 0280282D */  daddu     $a1, $s4, $zero
/* A0781C 8024091C 0C012568 */  jal       func_800495A0
/* A07820 80240920 02A0302D */   daddu    $a2, $s5, $zero
/* A07824 80240924 96220086 */  lhu       $v0, 0x86($s1)
/* A07828 80240928 A64200A8 */  sh        $v0, 0xa8($s2)
.L8024092C:
/* A0782C 8024092C 0260202D */  daddu     $a0, $s3, $zero
/* A07830 80240930 0280282D */  daddu     $a1, $s4, $zero
/* A07834 80240934 0C0125AE */  jal       func_800496B8
/* A07838 80240938 02A0302D */   daddu    $a2, $s5, $zero
/* A0783C 8024093C 08090288 */  j         .L80240A20
/* A07840 80240940 00000000 */   nop
.L80240944:
/* A07844 80240944 0260202D */  daddu     $a0, $s3, $zero
/* A07848 80240948 0280282D */  daddu     $a1, $s4, $zero
/* A0784C 8024094C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* A07850 80240950 02A0302D */   daddu    $a2, $s5, $zero
/* A07854 80240954 8E230088 */  lw        $v1, 0x88($s1)
/* A07858 80240958 24020006 */  addiu     $v0, $zero, 6
/* A0785C 8024095C 14620014 */  bne       $v1, $v0, .L802409B0
/* A07860 80240960 0260202D */   daddu    $a0, $s3, $zero
/* A07864 80240964 0C00A67F */  jal       rand_int
/* A07868 80240968 24040064 */   addiu    $a0, $zero, 0x64
/* A0786C 8024096C 28420021 */  slti      $v0, $v0, 0x21
/* A07870 80240970 5040000F */  beql      $v0, $zero, .L802409B0
/* A07874 80240974 0260202D */   daddu    $a0, $s3, $zero
/* A07878 80240978 8E22008C */  lw        $v0, 0x8c($s1)
/* A0787C 8024097C 10400005 */  beqz      $v0, .L80240994
/* A07880 80240980 3C020055 */   lui      $v0, 0x55
/* A07884 80240984 3442002F */  ori       $v0, $v0, 0x2f
/* A07888 80240988 AE20008C */  sw        $zero, 0x8c($s1)
/* A0788C 8024098C 08090268 */  j         .L802409A0
/* A07890 80240990 A22000B5 */   sb       $zero, 0xb5($s1)
.L80240994:
/* A07894 80240994 3442002E */  ori       $v0, $v0, 0x2e
/* A07898 80240998 AE30008C */  sw        $s0, 0x8c($s1)
/* A0789C 8024099C A23000B5 */  sb        $s0, 0xb5($s1)
.L802409A0:
/* A078A0 802409A0 AE420028 */  sw        $v0, 0x28($s2)
/* A078A4 802409A4 24020007 */  addiu     $v0, $zero, 7
/* A078A8 802409A8 080902A3 */  j         L80240A8C_A0798C
/* A078AC 802409AC AE220090 */   sw       $v0, 0x90($s1)
.L802409B0:
/* A078B0 802409B0 0280282D */  daddu     $a1, $s4, $zero
/* A078B4 802409B4 0C012701 */  jal       func_80049C04
/* A078B8 802409B8 02A0302D */   daddu    $a2, $s5, $zero
/* A078BC 802409BC 08090288 */  j         .L80240A20
/* A078C0 802409C0 00000000 */   nop
.L802409C4:
/* A078C4 802409C4 0260202D */  daddu     $a0, $s3, $zero
/* A078C8 802409C8 0280282D */  daddu     $a1, $s4, $zero
/* A078CC 802409CC 0C0900B8 */  jal       nok_15_set_script_owner_npc_anim
/* A078D0 802409D0 02A0302D */   daddu    $a2, $s5, $zero
/* A078D4 802409D4 0260202D */  daddu     $a0, $s3, $zero
.L802409D8:
/* A078D8 802409D8 0280282D */  daddu     $a1, $s4, $zero
/* A078DC 802409DC 0C0900D7 */  jal       nok_15_UnkDistFunc
/* A078E0 802409E0 02A0302D */   daddu    $a2, $s5, $zero
/* A078E4 802409E4 08090288 */  j         .L80240A20
/* A078E8 802409E8 00000000 */   nop
.L802409EC:
/* A078EC 802409EC 0260202D */  daddu     $a0, $s3, $zero
/* A078F0 802409F0 0280282D */  daddu     $a1, $s4, $zero
/* A078F4 802409F4 0C090124 */  jal       nok_15_UnkNpcAIFunc12
/* A078F8 802409F8 02A0302D */   daddu    $a2, $s5, $zero
/* A078FC 802409FC 08090288 */  j         .L80240A20
/* A07900 80240A00 00000000 */   nop
.L80240A04:
/* A07904 80240A04 0280282D */  daddu     $a1, $s4, $zero
/* A07908 80240A08 0C09017D */  jal       nok_15_set_script_owner_npc_col_height
/* A0790C 80240A0C 02A0302D */   daddu    $a2, $s5, $zero
/* A07910 80240A10 08090288 */  j         .L80240A20
/* A07914 80240A14 00000000 */   nop
.L80240A18:
/* A07918 80240A18 0C0129CF */  jal       func_8004A73C
/* A0791C 80240A1C 0260202D */   daddu    $a0, $s3, $zero
.L80240A20:
/* A07920 80240A20 8E230088 */  lw        $v1, 0x88($s1)
/* A07924 80240A24 24020006 */  addiu     $v0, $zero, 6
/* A07928 80240A28 14620019 */  bne       $v1, $v0, .L80240A90
/* A0792C 80240A2C 0000102D */   daddu    $v0, $zero, $zero
/* A07930 80240A30 8E22008C */  lw        $v0, 0x8c($s1)
/* A07934 80240A34 10400003 */  beqz      $v0, .L80240A44
/* A07938 80240A38 24020001 */   addiu    $v0, $zero, 1
/* A0793C 80240A3C 08090292 */  j         .L80240A48
/* A07940 80240A40 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240A44:
/* A07944 80240A44 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240A48:
/* A07948 80240A48 8E22008C */  lw        $v0, 0x8c($s1)
/* A0794C 80240A4C 1040000F */  beqz      $v0, L80240A8C_A0798C
/* A07950 80240A50 3C03FFAA */   lui      $v1, 0xffaa
/* A07954 80240A54 8E420028 */  lw        $v0, 0x28($s2)
/* A07958 80240A58 3463FFFC */  ori       $v1, $v1, 0xfffc
/* A0795C 80240A5C 00431821 */  addu      $v1, $v0, $v1
/* A07960 80240A60 2C620015 */  sltiu     $v0, $v1, 0x15
/* A07964 80240A64 10400009 */  beqz      $v0, L80240A8C_A0798C
/* A07968 80240A68 00031080 */   sll      $v0, $v1, 2
/* A0796C 80240A6C 3C018024 */  lui       $at, %hi(jtbl_80244CF8_A0BBF8)
/* A07970 80240A70 00220821 */  addu      $at, $at, $v0
/* A07974 80240A74 8C224CF8 */  lw        $v0, %lo(jtbl_80244CF8_A0BBF8)($at)
/* A07978 80240A78 00400008 */  jr        $v0
/* A0797C 80240A7C 00000000 */   nop
dlabel L80240A80_A07980
/* A07980 80240A80 8E420028 */  lw        $v0, 0x28($s2)
/* A07984 80240A84 24420001 */  addiu     $v0, $v0, 1
/* A07988 80240A88 AE420028 */  sw        $v0, 0x28($s2)
dlabel L80240A8C_A0798C
/* A0798C 80240A8C 0000102D */  daddu     $v0, $zero, $zero
.L80240A90:
/* A07990 80240A90 8FBF0068 */  lw        $ra, 0x68($sp)
/* A07994 80240A94 8FB50064 */  lw        $s5, 0x64($sp)
/* A07998 80240A98 8FB40060 */  lw        $s4, 0x60($sp)
/* A0799C 80240A9C 8FB3005C */  lw        $s3, 0x5c($sp)
/* A079A0 80240AA0 8FB20058 */  lw        $s2, 0x58($sp)
/* A079A4 80240AA4 8FB10054 */  lw        $s1, 0x54($sp)
/* A079A8 80240AA8 8FB00050 */  lw        $s0, 0x50($sp)
/* A079AC 80240AAC 03E00008 */  jr        $ra
/* A079B0 80240AB0 27BD0070 */   addiu    $sp, $sp, 0x70
