.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_BCF65C
/* BCF65C 80240A6C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BCF660 80240A70 AFBF001C */  sw        $ra, 0x1c($sp)
/* BCF664 80240A74 AFB20018 */  sw        $s2, 0x18($sp)
/* BCF668 80240A78 AFB10014 */  sw        $s1, 0x14($sp)
/* BCF66C 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* BCF670 80240A80 0C090150 */  jal       func_80240540_BCF130
/* BCF674 80240A84 F7B40020 */   sdc1     $f20, 0x20($sp)
/* BCF678 80240A88 0040882D */  daddu     $s1, $v0, $zero
/* BCF67C 80240A8C 8E2301C0 */  lw        $v1, 0x1c0($s1)
/* BCF680 80240A90 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BCF684 80240A94 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BCF688 80240A98 00031880 */  sll       $v1, $v1, 2
/* BCF68C 80240A9C 8C420010 */  lw        $v0, 0x10($v0)
/* BCF690 80240AA0 02231821 */  addu      $v1, $s1, $v1
/* BCF694 80240AA4 30428000 */  andi      $v0, $v0, 0x8000
/* BCF698 80240AA8 AC620058 */  sw        $v0, 0x58($v1)
/* BCF69C 80240AAC 8E2201C0 */  lw        $v0, 0x1c0($s1)
/* BCF6A0 80240AB0 24420001 */  addiu     $v0, $v0, 1
/* BCF6A4 80240AB4 AE2201C0 */  sw        $v0, 0x1c0($s1)
/* BCF6A8 80240AB8 2842005A */  slti      $v0, $v0, 0x5a
/* BCF6AC 80240ABC 50400001 */  beql      $v0, $zero, .L80240AC4
/* BCF6B0 80240AC0 AE2001C0 */   sw       $zero, 0x1c0($s1)
.L80240AC4:
/* BCF6B4 80240AC4 8E230030 */  lw        $v1, 0x30($s1)
/* BCF6B8 80240AC8 24120001 */  addiu     $s2, $zero, 1
/* BCF6BC 80240ACC 10720023 */  beq       $v1, $s2, .L80240B5C
/* BCF6C0 80240AD0 28620002 */   slti     $v0, $v1, 2
/* BCF6C4 80240AD4 50400005 */  beql      $v0, $zero, .L80240AEC
/* BCF6C8 80240AD8 2402000A */   addiu    $v0, $zero, 0xa
/* BCF6CC 80240ADC 10600009 */  beqz      $v1, .L80240B04
/* BCF6D0 80240AE0 240500FF */   addiu    $a1, $zero, 0xff
/* BCF6D4 80240AE4 080903B7 */  j         .L80240EDC
/* BCF6D8 80240AE8 00000000 */   nop
.L80240AEC:
/* BCF6DC 80240AEC 10620033 */  beq       $v1, $v0, .L80240BBC
/* BCF6E0 80240AF0 2402000B */   addiu    $v0, $zero, 0xb
/* BCF6E4 80240AF4 10620038 */  beq       $v1, $v0, .L80240BD8
/* BCF6E8 80240AF8 00000000 */   nop
/* BCF6EC 80240AFC 080903B7 */  j         .L80240EDC
/* BCF6F0 80240B00 00000000 */   nop
.L80240B04:
/* BCF6F4 80240B04 8E30003C */  lw        $s0, 0x3c($s1)
/* BCF6F8 80240B08 0C0513AC */  jal       set_hud_element_alpha
/* BCF6FC 80240B0C 0200202D */   daddu    $a0, $s0, $zero
/* BCF700 80240B10 0200202D */  daddu     $a0, $s0, $zero
/* BCF704 80240B14 0C05128B */  jal       clear_hud_element_flags
/* BCF708 80240B18 24050002 */   addiu    $a1, $zero, 2
/* BCF70C 80240B1C 8E300040 */  lw        $s0, 0x40($s1)
/* BCF710 80240B20 240500FF */  addiu     $a1, $zero, 0xff
/* BCF714 80240B24 0C0513AC */  jal       set_hud_element_alpha
/* BCF718 80240B28 0200202D */   daddu    $a0, $s0, $zero
/* BCF71C 80240B2C 0200202D */  daddu     $a0, $s0, $zero
/* BCF720 80240B30 0C05128B */  jal       clear_hud_element_flags
/* BCF724 80240B34 24050002 */   addiu    $a1, $zero, 2
/* BCF728 80240B38 8E300044 */  lw        $s0, 0x44($s1)
/* BCF72C 80240B3C 240500FF */  addiu     $a1, $zero, 0xff
/* BCF730 80240B40 0C0513AC */  jal       set_hud_element_alpha
/* BCF734 80240B44 0200202D */   daddu    $a0, $s0, $zero
/* BCF738 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* BCF73C 80240B4C 0C05128B */  jal       clear_hud_element_flags
/* BCF740 80240B50 24050002 */   addiu    $a1, $zero, 2
/* BCF744 80240B54 080903B7 */  j         .L80240EDC
/* BCF748 80240B58 AE320030 */   sw       $s2, 0x30($s1)
.L80240B5C:
/* BCF74C 80240B5C 8E220034 */  lw        $v0, 0x34($s1)
/* BCF750 80240B60 24420014 */  addiu     $v0, $v0, 0x14
/* BCF754 80240B64 AE220034 */  sw        $v0, 0x34($s1)
/* BCF758 80240B68 28420033 */  slti      $v0, $v0, 0x33
/* BCF75C 80240B6C 14400002 */  bnez      $v0, .L80240B78
/* BCF760 80240B70 24020032 */   addiu    $v0, $zero, 0x32
/* BCF764 80240B74 AE220034 */  sw        $v0, 0x34($s1)
.L80240B78:
/* BCF768 80240B78 8E24003C */  lw        $a0, 0x3c($s1)
/* BCF76C 80240B7C 8E250034 */  lw        $a1, 0x34($s1)
/* BCF770 80240B80 0C051261 */  jal       set_hud_element_render_pos
/* BCF774 80240B84 8E260038 */   lw       $a2, 0x38($s1)
/* BCF778 80240B88 8E240040 */  lw        $a0, 0x40($s1)
/* BCF77C 80240B8C 8E260038 */  lw        $a2, 0x38($s1)
/* BCF780 80240B90 8E250034 */  lw        $a1, 0x34($s1)
/* BCF784 80240B94 0C051261 */  jal       set_hud_element_render_pos
/* BCF788 80240B98 24C6001C */   addiu    $a2, $a2, 0x1c
/* BCF78C 80240B9C 8E240044 */  lw        $a0, 0x44($s1)
/* BCF790 80240BA0 8E250034 */  lw        $a1, 0x34($s1)
/* BCF794 80240BA4 8E260038 */  lw        $a2, 0x38($s1)
/* BCF798 80240BA8 24A50002 */  addiu     $a1, $a1, 2
/* BCF79C 80240BAC 0C051261 */  jal       set_hud_element_render_pos
/* BCF7A0 80240BB0 24C6000E */   addiu    $a2, $a2, 0xe
/* BCF7A4 80240BB4 080903B7 */  j         .L80240EDC
/* BCF7A8 80240BB8 00000000 */   nop
.L80240BBC:
/* BCF7AC 80240BBC 8E24003C */  lw        $a0, 0x3c($s1)
/* BCF7B0 80240BC0 3C058011 */  lui       $a1, %hi(D_80108C34)
/* BCF7B4 80240BC4 24A58C34 */  addiu     $a1, $a1, %lo(D_80108C34)
/* BCF7B8 80240BC8 0C0511FF */  jal       set_hud_element_script
/* BCF7BC 80240BCC 00000000 */   nop
/* BCF7C0 80240BD0 2402000B */  addiu     $v0, $zero, 0xb
/* BCF7C4 80240BD4 AE220030 */  sw        $v0, 0x30($s1)
.L80240BD8:
/* BCF7C8 80240BD8 8E2301C0 */  lw        $v1, 0x1c0($s1)
/* BCF7CC 80240BDC 2405005A */  addiu     $a1, $zero, 0x5a
/* BCF7D0 80240BE0 2463FFA6 */  addiu     $v1, $v1, -0x5a
/* BCF7D4 80240BE4 04610002 */  bgez      $v1, .L80240BF0
/* BCF7D8 80240BE8 AE200004 */   sw       $zero, 4($s1)
/* BCF7DC 80240BEC 00651821 */  addu      $v1, $v1, $a1
.L80240BF0:
/* BCF7E0 80240BF0 0000802D */  daddu     $s0, $zero, $zero
/* BCF7E4 80240BF4 0200202D */  daddu     $a0, $s0, $zero
.L80240BF8:
/* BCF7E8 80240BF8 2862005A */  slti      $v0, $v1, 0x5a
/* BCF7EC 80240BFC 50400001 */  beql      $v0, $zero, .L80240C04
/* BCF7F0 80240C00 2463FFA6 */   addiu    $v1, $v1, -0x5a
.L80240C04:
/* BCF7F4 80240C04 00031080 */  sll       $v0, $v1, 2
/* BCF7F8 80240C08 02221021 */  addu      $v0, $s1, $v0
/* BCF7FC 80240C0C 8C420058 */  lw        $v0, 0x58($v0)
/* BCF800 80240C10 54400001 */  bnel      $v0, $zero, .L80240C18
/* BCF804 80240C14 26100001 */   addiu    $s0, $s0, 1
.L80240C18:
/* BCF808 80240C18 24840001 */  addiu     $a0, $a0, 1
/* BCF80C 80240C1C 0085102A */  slt       $v0, $a0, $a1
/* BCF810 80240C20 1440FFF5 */  bnez      $v0, .L80240BF8
/* BCF814 80240C24 24630001 */   addiu    $v1, $v1, 1
/* BCF818 80240C28 0000202D */  daddu     $a0, $zero, $zero
/* BCF81C 80240C2C 3C05FD05 */  lui       $a1, 0xfd05
/* BCF820 80240C30 34A50F87 */  ori       $a1, $a1, 0xf87
/* BCF824 80240C34 00103140 */  sll       $a2, $s0, 5
/* BCF828 80240C38 00D03023 */  subu      $a2, $a2, $s0
/* BCF82C 80240C3C 00063080 */  sll       $a2, $a2, 2
/* BCF830 80240C40 00D03021 */  addu      $a2, $a2, $s0
/* BCF834 80240C44 0C0B2026 */  jal       set_variable
/* BCF838 80240C48 000630C0 */   sll      $a2, $a2, 3
/* BCF83C 80240C4C 3C032E8B */  lui       $v1, 0x2e8b
/* BCF840 80240C50 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BCF844 80240C54 00101040 */  sll       $v0, $s0, 1
/* BCF848 80240C58 00501021 */  addu      $v0, $v0, $s0
/* BCF84C 80240C5C 000210C0 */  sll       $v0, $v0, 3
/* BCF850 80240C60 00501021 */  addu      $v0, $v0, $s0
/* BCF854 80240C64 00021080 */  sll       $v0, $v0, 2
/* BCF858 80240C68 00430018 */  mult      $v0, $v1
/* BCF85C 80240C6C 000217C3 */  sra       $v0, $v0, 0x1f
/* BCF860 80240C70 00003810 */  mfhi      $a3
/* BCF864 80240C74 00071883 */  sra       $v1, $a3, 2
/* BCF868 80240C78 00621823 */  subu      $v1, $v1, $v0
/* BCF86C 80240C7C 04610002 */  bgez      $v1, .L80240C88
/* BCF870 80240C80 AE230004 */   sw       $v1, 4($s1)
/* BCF874 80240C84 AE200004 */  sw        $zero, 4($s1)
.L80240C88:
/* BCF878 80240C88 8E220004 */  lw        $v0, 4($s1)
/* BCF87C 80240C8C 28420065 */  slti      $v0, $v0, 0x65
/* BCF880 80240C90 14400004 */  bnez      $v0, .L80240CA4
/* BCF884 80240C94 3C028888 */   lui      $v0, 0x8888
/* BCF888 80240C98 24020064 */  addiu     $v0, $zero, 0x64
/* BCF88C 80240C9C AE220004 */  sw        $v0, 4($s1)
/* BCF890 80240CA0 3C028888 */  lui       $v0, 0x8888
.L80240CA4:
/* BCF894 80240CA4 8E230008 */  lw        $v1, 8($s1)
/* BCF898 80240CA8 34428889 */  ori       $v0, $v0, 0x8889
/* BCF89C 80240CAC 00620018 */  mult      $v1, $v0
/* BCF8A0 80240CB0 00003810 */  mfhi      $a3
/* BCF8A4 80240CB4 00E31021 */  addu      $v0, $a3, $v1
/* BCF8A8 80240CB8 00021143 */  sra       $v0, $v0, 5
/* BCF8AC 80240CBC 00031FC3 */  sra       $v1, $v1, 0x1f
/* BCF8B0 80240CC0 00438023 */  subu      $s0, $v0, $v1
/* BCF8B4 80240CC4 2A020033 */  slti      $v0, $s0, 0x33
/* BCF8B8 80240CC8 10400021 */  beqz      $v0, .L80240D50
/* BCF8BC 80240CCC 00101840 */   sll      $v1, $s0, 1
/* BCF8C0 80240CD0 3C0451EB */  lui       $a0, 0x51eb
/* BCF8C4 80240CD4 3484851F */  ori       $a0, $a0, 0x851f
/* BCF8C8 80240CD8 00701821 */  addu      $v1, $v1, $s0
/* BCF8CC 80240CDC 00031100 */  sll       $v0, $v1, 4
/* BCF8D0 80240CE0 00431023 */  subu      $v0, $v0, $v1
/* BCF8D4 80240CE4 00021040 */  sll       $v0, $v0, 1
/* BCF8D8 80240CE8 00440018 */  mult      $v0, $a0
/* BCF8DC 80240CEC 000217C3 */  sra       $v0, $v0, 0x1f
/* BCF8E0 80240CF0 3C0140C9 */  lui       $at, 0x40c9
/* BCF8E4 80240CF4 34210FD0 */  ori       $at, $at, 0xfd0
/* BCF8E8 80240CF8 44810000 */  mtc1      $at, $f0
/* BCF8EC 80240CFC 00003810 */  mfhi      $a3
/* BCF8F0 80240D00 00071903 */  sra       $v1, $a3, 4
/* BCF8F4 80240D04 00621823 */  subu      $v1, $v1, $v0
/* BCF8F8 80240D08 44836000 */  mtc1      $v1, $f12
/* BCF8FC 80240D0C 00000000 */  nop
/* BCF900 80240D10 46806320 */  cvt.s.w   $f12, $f12
/* BCF904 80240D14 46006302 */  mul.s     $f12, $f12, $f0
/* BCF908 80240D18 00000000 */  nop
/* BCF90C 80240D1C 3C0143B4 */  lui       $at, 0x43b4
/* BCF910 80240D20 44810000 */  mtc1      $at, $f0
/* BCF914 80240D24 0C00A85B */  jal       sin_rad
/* BCF918 80240D28 46006303 */   div.s    $f12, $f12, $f0
/* BCF91C 80240D2C 3C014248 */  lui       $at, 0x4248
/* BCF920 80240D30 44811000 */  mtc1      $at, $f2
/* BCF924 80240D34 00000000 */  nop
/* BCF928 80240D38 46020002 */  mul.s     $f0, $f0, $f2
/* BCF92C 80240D3C 00000000 */  nop
/* BCF930 80240D40 4600018D */  trunc.w.s $f6, $f0
/* BCF934 80240D44 44103000 */  mfc1      $s0, $f6
/* BCF938 80240D48 0809037D */  j         .L80240DF4
/* BCF93C 80240D4C 24020064 */   addiu    $v0, $zero, 0x64
.L80240D50:
/* BCF940 80240D50 3C0451EB */  lui       $a0, 0x51eb
/* BCF944 80240D54 3484851F */  ori       $a0, $a0, 0x851f
/* BCF948 80240D58 2602FFCE */  addiu     $v0, $s0, -0x32
/* BCF94C 80240D5C 00021840 */  sll       $v1, $v0, 1
/* BCF950 80240D60 00621821 */  addu      $v1, $v1, $v0
/* BCF954 80240D64 00031100 */  sll       $v0, $v1, 4
/* BCF958 80240D68 00431023 */  subu      $v0, $v0, $v1
/* BCF95C 80240D6C 00021040 */  sll       $v0, $v0, 1
/* BCF960 80240D70 00440018 */  mult      $v0, $a0
/* BCF964 80240D74 000217C3 */  sra       $v0, $v0, 0x1f
/* BCF968 80240D78 3C0140C9 */  lui       $at, 0x40c9
/* BCF96C 80240D7C 34210FD0 */  ori       $at, $at, 0xfd0
/* BCF970 80240D80 44810000 */  mtc1      $at, $f0
/* BCF974 80240D84 00003810 */  mfhi      $a3
/* BCF978 80240D88 00071903 */  sra       $v1, $a3, 4
/* BCF97C 80240D8C 00621823 */  subu      $v1, $v1, $v0
/* BCF980 80240D90 2463005A */  addiu     $v1, $v1, 0x5a
/* BCF984 80240D94 44836000 */  mtc1      $v1, $f12
/* BCF988 80240D98 00000000 */  nop
/* BCF98C 80240D9C 46806320 */  cvt.s.w   $f12, $f12
/* BCF990 80240DA0 46006302 */  mul.s     $f12, $f12, $f0
/* BCF994 80240DA4 00000000 */  nop
/* BCF998 80240DA8 3C0143B4 */  lui       $at, 0x43b4
/* BCF99C 80240DAC 44810000 */  mtc1      $at, $f0
/* BCF9A0 80240DB0 0C00A85B */  jal       sin_rad
/* BCF9A4 80240DB4 46006303 */   div.s    $f12, $f12, $f0
/* BCF9A8 80240DB8 3C013FF0 */  lui       $at, 0x3ff0
/* BCF9AC 80240DBC 44811800 */  mtc1      $at, $f3
/* BCF9B0 80240DC0 44801000 */  mtc1      $zero, $f2
/* BCF9B4 80240DC4 46000021 */  cvt.d.s   $f0, $f0
/* BCF9B8 80240DC8 46201081 */  sub.d     $f2, $f2, $f0
/* BCF9BC 80240DCC 3C014049 */  lui       $at, 0x4049
/* BCF9C0 80240DD0 44810800 */  mtc1      $at, $f1
/* BCF9C4 80240DD4 44800000 */  mtc1      $zero, $f0
/* BCF9C8 80240DD8 00000000 */  nop
/* BCF9CC 80240DDC 46201082 */  mul.d     $f2, $f2, $f0
/* BCF9D0 80240DE0 00000000 */  nop
/* BCF9D4 80240DE4 46201080 */  add.d     $f2, $f2, $f0
/* BCF9D8 80240DE8 4620118D */  trunc.w.d $f6, $f2
/* BCF9DC 80240DEC 44103000 */  mfc1      $s0, $f6
/* BCF9E0 80240DF0 24020064 */  addiu     $v0, $zero, 0x64
.L80240DF4:
/* BCF9E4 80240DF4 00501023 */  subu      $v0, $v0, $s0
/* BCF9E8 80240DF8 3C013FD0 */  lui       $at, 0x3fd0
/* BCF9EC 80240DFC 44811800 */  mtc1      $at, $f3
/* BCF9F0 80240E00 44801000 */  mtc1      $zero, $f2
/* BCF9F4 80240E04 44820000 */  mtc1      $v0, $f0
/* BCF9F8 80240E08 00000000 */  nop
/* BCF9FC 80240E0C 46800021 */  cvt.d.w   $f0, $f0
/* BCFA00 80240E10 46220002 */  mul.d     $f0, $f0, $f2
/* BCFA04 80240E14 00000000 */  nop
/* BCFA08 80240E18 44901000 */  mtc1      $s0, $f2
/* BCFA0C 80240E1C 00000000 */  nop
/* BCFA10 80240E20 468010A1 */  cvt.d.w   $f2, $f2
/* BCFA14 80240E24 46221080 */  add.d     $f2, $f2, $f2
/* BCFA18 80240E28 3C014059 */  lui       $at, 0x4059
/* BCFA1C 80240E2C 44812800 */  mtc1      $at, $f5
/* BCFA20 80240E30 44802000 */  mtc1      $zero, $f4
/* BCFA24 80240E34 00000000 */  nop
/* BCFA28 80240E38 46241083 */  div.d     $f2, $f2, $f4
/* BCFA2C 80240E3C 46240003 */  div.d     $f0, $f0, $f4
/* BCFA30 80240E40 46220000 */  add.d     $f0, $f0, $f2
/* BCFA34 80240E44 8E24000C */  lw        $a0, 0xc($s1)
/* BCFA38 80240E48 46200020 */  cvt.s.d   $f0, $f0
/* BCFA3C 80240E4C 44050000 */  mfc1      $a1, $f0
/* BCFA40 80240E50 0C01574E */  jal       func_80055D38
/* BCFA44 80240E54 AE2501C4 */   sw       $a1, 0x1c4($s1)
/* BCFA48 80240E58 8E24004C */  lw        $a0, 0x4c($s1)
/* BCFA4C 80240E5C 0C0B11EA */  jal       get_script_by_id
/* BCFA50 80240E60 00000000 */   nop
/* BCFA54 80240E64 C62201C4 */  lwc1      $f2, 0x1c4($s1)
/* BCFA58 80240E68 3C014040 */  lui       $at, 0x4040
/* BCFA5C 80240E6C 44810000 */  mtc1      $at, $f0
/* BCFA60 80240E70 00000000 */  nop
/* BCFA64 80240E74 46001082 */  mul.s     $f2, $f2, $f0
/* BCFA68 80240E78 00000000 */  nop
/* BCFA6C 80240E7C 44051000 */  mfc1      $a1, $f2
/* BCFA70 80240E80 0C0B1078 */  jal       set_script_timescale
/* BCFA74 80240E84 0040202D */   daddu    $a0, $v0, $zero
/* BCFA78 80240E88 8E240050 */  lw        $a0, 0x50($s1)
/* BCFA7C 80240E8C 0C0B11EA */  jal       get_script_by_id
/* BCFA80 80240E90 00000000 */   nop
/* BCFA84 80240E94 C62001C4 */  lwc1      $f0, 0x1c4($s1)
/* BCFA88 80240E98 3C0140A0 */  lui       $at, 0x40a0
/* BCFA8C 80240E9C 4481A000 */  mtc1      $at, $f20
/* BCFA90 80240EA0 00000000 */  nop
/* BCFA94 80240EA4 46140002 */  mul.s     $f0, $f0, $f20
/* BCFA98 80240EA8 00000000 */  nop
/* BCFA9C 80240EAC 44050000 */  mfc1      $a1, $f0
/* BCFAA0 80240EB0 0C0B1078 */  jal       set_script_timescale
/* BCFAA4 80240EB4 0040202D */   daddu    $a0, $v0, $zero
/* BCFAA8 80240EB8 8E240054 */  lw        $a0, 0x54($s1)
/* BCFAAC 80240EBC 0C0B11EA */  jal       get_script_by_id
/* BCFAB0 80240EC0 00000000 */   nop
/* BCFAB4 80240EC4 C62001C4 */  lwc1      $f0, 0x1c4($s1)
/* BCFAB8 80240EC8 46140002 */  mul.s     $f0, $f0, $f20
/* BCFABC 80240ECC 00000000 */  nop
/* BCFAC0 80240ED0 44050000 */  mfc1      $a1, $f0
/* BCFAC4 80240ED4 0C0B1078 */  jal       set_script_timescale
/* BCFAC8 80240ED8 0040202D */   daddu    $a0, $v0, $zero
.L80240EDC:
/* BCFACC 80240EDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* BCFAD0 80240EE0 8FB20018 */  lw        $s2, 0x18($sp)
/* BCFAD4 80240EE4 8FB10014 */  lw        $s1, 0x14($sp)
/* BCFAD8 80240EE8 8FB00010 */  lw        $s0, 0x10($sp)
/* BCFADC 80240EEC D7B40020 */  ldc1      $f20, 0x20($sp)
/* BCFAE0 80240EF0 03E00008 */  jr        $ra
/* BCFAE4 80240EF4 27BD0028 */   addiu    $sp, $sp, 0x28
