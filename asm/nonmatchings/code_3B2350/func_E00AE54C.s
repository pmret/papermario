.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AE54C
/* 3B289C E00AE54C 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 3B28A0 E00AE550 3C06DB06 */  lui       $a2, 0xdb06
/* 3B28A4 E00AE554 34C60024 */  ori       $a2, $a2, 0x24
/* 3B28A8 E00AE558 AFB300BC */  sw        $s3, 0xbc($sp)
/* 3B28AC E00AE55C 3C13800A */  lui       $s3, %hi(D_8009A66C)
/* 3B28B0 E00AE560 2673A66C */  addiu     $s3, $s3, %lo(D_8009A66C)
/* 3B28B4 E00AE564 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3B28B8 E00AE568 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3B28BC E00AE56C AFB700CC */  sw        $s7, 0xcc($sp)
/* 3B28C0 E00AE570 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3B28C4 E00AE574 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3B28C8 E00AE578 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3B28CC E00AE57C AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3B28D0 E00AE580 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3B28D4 E00AE584 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3B28D8 E00AE588 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 3B28DC E00AE58C F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3B28E0 E00AE590 AFA400E8 */  sw        $a0, 0xe8($sp)
/* 3B28E4 E00AE594 8E650000 */  lw        $a1, ($s3)
/* 3B28E8 E00AE598 8FA900E8 */  lw        $t1, 0xe8($sp)
/* 3B28EC E00AE59C 00A0182D */  daddu     $v1, $a1, $zero
/* 3B28F0 E00AE5A0 8D32000C */  lw        $s2, 0xc($t1)
/* 3B28F4 E00AE5A4 24A50008 */  addiu     $a1, $a1, 8
/* 3B28F8 E00AE5A8 AE650000 */  sw        $a1, ($s3)
/* 3B28FC E00AE5AC 8E490014 */  lw        $t1, 0x14($s2)
/* 3B2900 E00AE5B0 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B2904 E00AE5B4 AFA90098 */  sw        $t1, 0x98($sp)
/* 3B2908 E00AE5B8 8E490024 */  lw        $t1, 0x24($s2)
/* 3B290C E00AE5BC 3C110001 */  lui       $s1, 1
/* 3B2910 E00AE5C0 AFA9009C */  sw        $t1, 0x9c($sp)
/* 3B2914 E00AE5C4 8E5E0018 */  lw        $fp, 0x18($s2)
/* 3B2918 E00AE5C8 8E49001C */  lw        $t1, 0x1c($s2)
/* 3B291C E00AE5CC 36311630 */  ori       $s1, $s1, 0x1630
/* 3B2920 E00AE5D0 AFA900A0 */  sw        $t1, 0xa0($sp)
/* 3B2924 E00AE5D4 8E490020 */  lw        $t1, 0x20($s2)
/* 3B2928 E00AE5D8 3C02E700 */  lui       $v0, 0xe700
/* 3B292C E00AE5DC AFA900A4 */  sw        $t1, 0xa4($sp)
/* 3B2930 E00AE5E0 AC620000 */  sw        $v0, ($v1)
/* 3B2934 E00AE5E4 AC600004 */  sw        $zero, 4($v1)
/* 3B2938 E00AE5E8 ACA60000 */  sw        $a2, ($a1)
/* 3B293C E00AE5EC 8FA900E8 */  lw        $t1, 0xe8($sp)
/* 3B2940 E00AE5F0 24150001 */  addiu     $s5, $zero, 1
/* 3B2944 E00AE5F4 8D230010 */  lw        $v1, 0x10($t1)
/* 3B2948 E00AE5F8 24A20008 */  addiu     $v0, $a1, 8
/* 3B294C E00AE5FC AE620000 */  sw        $v0, ($s3)
/* 3B2950 E00AE600 8C62001C */  lw        $v0, 0x1c($v1)
/* 3B2954 E00AE604 3C038000 */  lui       $v1, 0x8000
/* 3B2958 E00AE608 00431021 */  addu      $v0, $v0, $v1
/* 3B295C E00AE60C 3C03800B */  lui       $v1, %hi(gCameras)
/* 3B2960 E00AE610 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3B2964 E00AE614 ACA20004 */  sw        $v0, 4($a1)
/* 3B2968 E00AE618 8E450004 */  lw        $a1, 4($s2)
/* 3B296C E00AE61C 8E460008 */  lw        $a2, 8($s2)
/* 3B2970 E00AE620 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3B2974 E00AE624 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3B2978 E00AE628 8E47000C */  lw        $a3, 0xc($s2)
/* 3B297C E00AE62C 00028080 */  sll       $s0, $v0, 2
/* 3B2980 E00AE630 02028021 */  addu      $s0, $s0, $v0
/* 3B2984 E00AE634 00108080 */  sll       $s0, $s0, 2
/* 3B2988 E00AE638 02028023 */  subu      $s0, $s0, $v0
/* 3B298C E00AE63C 001010C0 */  sll       $v0, $s0, 3
/* 3B2990 E00AE640 02028021 */  addu      $s0, $s0, $v0
/* 3B2994 E00AE644 001080C0 */  sll       $s0, $s0, 3
/* 3B2998 E00AE648 0C080108 */  jal       func_E0200420
/* 3B299C E00AE64C 02038021 */   addu     $s0, $s0, $v1
/* 3B29A0 E00AE650 27B40058 */  addiu     $s4, $sp, 0x58
/* 3B29A4 E00AE654 8E450038 */  lw        $a1, 0x38($s2)
/* 3B29A8 E00AE658 0280202D */  daddu     $a0, $s4, $zero
/* 3B29AC E00AE65C 00A0302D */  daddu     $a2, $a1, $zero
/* 3B29B0 E00AE660 0C080110 */  jal       func_E0200440
/* 3B29B4 E00AE664 00A0382D */   daddu    $a3, $a1, $zero
/* 3B29B8 E00AE668 0280202D */  daddu     $a0, $s4, $zero
/* 3B29BC E00AE66C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B29C0 E00AE670 0C080114 */  jal       func_E0200450
/* 3B29C4 E00AE674 00A0302D */   daddu    $a2, $a1, $zero
/* 3B29C8 E00AE678 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B29CC E00AE67C 3C168007 */  lui       $s6, %hi(D_800741F0)
/* 3B29D0 E00AE680 26D641F0 */  addiu     $s6, $s6, %lo(D_800741F0)
/* 3B29D4 E00AE684 3C17800A */  lui       $s7, %hi(D_8009A674)
/* 3B29D8 E00AE688 26F7A674 */  addiu     $s7, $s7, %lo(D_8009A674)
/* 3B29DC E00AE68C 96C50000 */  lhu       $a1, ($s6)
/* 3B29E0 E00AE690 8EE20000 */  lw        $v0, ($s7)
/* 3B29E4 E00AE694 00052980 */  sll       $a1, $a1, 6
/* 3B29E8 E00AE698 00B12821 */  addu      $a1, $a1, $s1
/* 3B29EC E00AE69C 0C080118 */  jal       func_E0200460
/* 3B29F0 E00AE6A0 00452821 */   addu     $a1, $v0, $a1
/* 3B29F4 E00AE6A4 3C03DA38 */  lui       $v1, 0xda38
/* 3B29F8 E00AE6A8 34630002 */  ori       $v1, $v1, 2
/* 3B29FC E00AE6AC 3C06DA38 */  lui       $a2, 0xda38
/* 3B2A00 E00AE6B0 00D53025 */  or        $a2, $a2, $s5
/* 3B2A04 E00AE6B4 8E640000 */  lw        $a0, ($s3)
/* 3B2A08 E00AE6B8 96C20000 */  lhu       $v0, ($s6)
/* 3B2A0C E00AE6BC 0080282D */  daddu     $a1, $a0, $zero
/* 3B2A10 E00AE6C0 24840008 */  addiu     $a0, $a0, 8
/* 3B2A14 E00AE6C4 AE640000 */  sw        $a0, ($s3)
/* 3B2A18 E00AE6C8 ACA30000 */  sw        $v1, ($a1)
/* 3B2A1C E00AE6CC 00551821 */  addu      $v1, $v0, $s5
/* 3B2A20 E00AE6D0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B2A24 E00AE6D4 00021180 */  sll       $v0, $v0, 6
/* 3B2A28 E00AE6D8 A6C30000 */  sh        $v1, ($s6)
/* 3B2A2C E00AE6DC 8EE30000 */  lw        $v1, ($s7)
/* 3B2A30 E00AE6E0 00511021 */  addu      $v0, $v0, $s1
/* 3B2A34 E00AE6E4 00621821 */  addu      $v1, $v1, $v0
/* 3B2A38 E00AE6E8 24820008 */  addiu     $v0, $a0, 8
/* 3B2A3C E00AE6EC ACA30004 */  sw        $v1, 4($a1)
/* 3B2A40 E00AE6F0 AE620000 */  sw        $v0, ($s3)
/* 3B2A44 E00AE6F4 24820010 */  addiu     $v0, $a0, 0x10
/* 3B2A48 E00AE6F8 AC860000 */  sw        $a2, ($a0)
/* 3B2A4C E00AE6FC AE620000 */  sw        $v0, ($s3)
/* 3B2A50 E00AE700 8E030204 */  lw        $v1, 0x204($s0)
/* 3B2A54 E00AE704 3C02FB00 */  lui       $v0, 0xfb00
/* 3B2A58 E00AE708 AC820008 */  sw        $v0, 8($a0)
/* 3B2A5C E00AE70C AC830004 */  sw        $v1, 4($a0)
/* 3B2A60 E00AE710 9243002B */  lbu       $v1, 0x2b($s2)
/* 3B2A64 E00AE714 9245002F */  lbu       $a1, 0x2f($s2)
/* 3B2A68 E00AE718 92460033 */  lbu       $a2, 0x33($s2)
/* 3B2A6C E00AE71C 3C02DE00 */  lui       $v0, 0xde00
/* 3B2A70 E00AE720 AC820010 */  sw        $v0, 0x10($a0)
/* 3B2A74 E00AE724 3C020900 */  lui       $v0, 0x900
/* 3B2A78 E00AE728 24421000 */  addiu     $v0, $v0, 0x1000
/* 3B2A7C E00AE72C AC820014 */  sw        $v0, 0x14($a0)
/* 3B2A80 E00AE730 00031E00 */  sll       $v1, $v1, 0x18
/* 3B2A84 E00AE734 00052C00 */  sll       $a1, $a1, 0x10
/* 3B2A88 E00AE738 00651825 */  or        $v1, $v1, $a1
/* 3B2A8C E00AE73C 00063200 */  sll       $a2, $a2, 8
/* 3B2A90 E00AE740 00661825 */  or        $v1, $v1, $a2
/* 3B2A94 E00AE744 AC83000C */  sw        $v1, 0xc($a0)
/* 3B2A98 E00AE748 8FA900E8 */  lw        $t1, 0xe8($sp)
/* 3B2A9C E00AE74C 26520044 */  addiu     $s2, $s2, 0x44
/* 3B2AA0 E00AE750 8D220008 */  lw        $v0, 8($t1)
/* 3B2AA4 E00AE754 24840018 */  addiu     $a0, $a0, 0x18
/* 3B2AA8 E00AE758 02A2102A */  slt       $v0, $s5, $v0
/* 3B2AAC E00AE75C 10400098 */  beqz      $v0, .LE00AE9C0
/* 3B2AB0 E00AE760 AE640000 */   sw       $a0, ($s3)
/* 3B2AB4 E00AE764 0260882D */  daddu     $s1, $s3, $zero
/* 3B2AB8 E00AE768 001E1E00 */  sll       $v1, $fp, 0x18
/* 3B2ABC E00AE76C 0280982D */  daddu     $s3, $s4, $zero
/* 3B2AC0 E00AE770 02C0B82D */  daddu     $s7, $s6, $zero
/* 3B2AC4 E00AE774 3C140001 */  lui       $s4, 1
/* 3B2AC8 E00AE778 36941630 */  ori       $s4, $s4, 0x1630
/* 3B2ACC E00AE77C 3C1EF200 */  lui       $fp, 0xf200
/* 3B2AD0 E00AE780 26500040 */  addiu     $s0, $s2, 0x40
/* 3B2AD4 E00AE784 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 3B2AD8 E00AE788 4480A000 */  mtc1      $zero, $f20
/* 3B2ADC E00AE78C 3C013F80 */  lui       $at, 0x3f80
/* 3B2AE0 E00AE790 4481B000 */  mtc1      $at, $f22
/* 3B2AE4 E00AE794 312200FF */  andi      $v0, $t1, 0xff
/* 3B2AE8 E00AE798 00021400 */  sll       $v0, $v0, 0x10
/* 3B2AEC E00AE79C 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 3B2AF0 E00AE7A0 00621825 */  or        $v1, $v1, $v0
/* 3B2AF4 E00AE7A4 312200FF */  andi      $v0, $t1, 0xff
/* 3B2AF8 E00AE7A8 00021200 */  sll       $v0, $v0, 8
/* 3B2AFC E00AE7AC 8FA90098 */  lw        $t1, 0x98($sp)
/* 3B2B00 E00AE7B0 00621825 */  or        $v1, $v1, $v0
/* 3B2B04 E00AE7B4 AFA300A8 */  sw        $v1, 0xa8($sp)
/* 3B2B08 E00AE7B8 02A91004 */  sllv      $v0, $t1, $s5
/* 3B2B0C E00AE7BC 0049B021 */  addu      $s6, $v0, $t1
/* 3B2B10 E00AE7C0 26C2001F */  addiu     $v0, $s6, 0x1f
/* 3B2B14 E00AE7C4 00021080 */  sll       $v0, $v0, 2
/* 3B2B18 E00AE7C8 30420FFF */  andi      $v0, $v0, 0xfff
/* 3B2B1C E00AE7CC 00021300 */  sll       $v0, $v0, 0xc
/* 3B2B20 E00AE7D0 AFA200AC */  sw        $v0, 0xac($sp)
.LE00AE7D4:
/* 3B2B24 E00AE7D4 8E280000 */  lw        $t0, ($s1)
/* 3B2B28 E00AE7D8 3C02FA00 */  lui       $v0, 0xfa00
/* 3B2B2C E00AE7DC 0100282D */  daddu     $a1, $t0, $zero
/* 3B2B30 E00AE7E0 ACA20000 */  sw        $v0, ($a1)
/* 3B2B34 E00AE7E4 8E03FFE4 */  lw        $v1, -0x1c($s0)
/* 3B2B38 E00AE7E8 8FA9009C */  lw        $t1, 0x9c($sp)
/* 3B2B3C E00AE7EC 00690018 */  mult      $v1, $t1
/* 3B2B40 E00AE7F0 00001812 */  mflo      $v1
/* 3B2B44 E00AE7F4 3C028080 */  lui       $v0, 0x8080
/* 3B2B48 E00AE7F8 34428081 */  ori       $v0, $v0, 0x8081
/* 3B2B4C E00AE7FC 00620018 */  mult      $v1, $v0
/* 3B2B50 E00AE800 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B2B54 E00AE804 4407A000 */  mfc1      $a3, $f20
/* 3B2B58 E00AE808 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 3B2B5C E00AE80C 00001010 */  mfhi      $v0
/* 3B2B60 E00AE810 00431021 */  addu      $v0, $v0, $v1
/* 3B2B64 E00AE814 000211C3 */  sra       $v0, $v0, 7
/* 3B2B68 E00AE818 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3B2B6C E00AE81C 00431023 */  subu      $v0, $v0, $v1
/* 3B2B70 E00AE820 304200FF */  andi      $v0, $v0, 0xff
/* 3B2B74 E00AE824 01221025 */  or        $v0, $t1, $v0
/* 3B2B78 E00AE828 ACA20004 */  sw        $v0, 4($a1)
/* 3B2B7C E00AE82C 8E05FFC4 */  lw        $a1, -0x3c($s0)
/* 3B2B80 E00AE830 8E06FFC8 */  lw        $a2, -0x38($s0)
/* 3B2B84 E00AE834 25080008 */  addiu     $t0, $t0, 8
/* 3B2B88 E00AE838 0C080108 */  jal       func_E0200420
/* 3B2B8C E00AE83C AE280000 */   sw       $t0, ($s1)
/* 3B2B90 E00AE840 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3B2B94 E00AE844 8E05FFFC */  lw        $a1, -4($s0)
/* 3B2B98 E00AE848 4406A000 */  mfc1      $a2, $f20
/* 3B2B9C E00AE84C 4407A000 */  mfc1      $a3, $f20
/* 3B2BA0 E00AE850 0C080104 */  jal       func_E0200410
/* 3B2BA4 E00AE854 0260202D */   daddu    $a0, $s3, $zero
/* 3B2BA8 E00AE858 0260202D */  daddu     $a0, $s3, $zero
/* 3B2BAC E00AE85C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B2BB0 E00AE860 0C080114 */  jal       func_E0200450
/* 3B2BB4 E00AE864 00A0302D */   daddu    $a2, $a1, $zero
/* 3B2BB8 E00AE868 C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 3B2BBC E00AE86C 3C013D80 */  lui       $at, 0x3d80
/* 3B2BC0 E00AE870 44810000 */  mtc1      $at, $f0
/* 3B2BC4 E00AE874 00000000 */  nop       
/* 3B2BC8 E00AE878 46001082 */  mul.s     $f2, $f2, $f0
/* 3B2BCC E00AE87C 00000000 */  nop       
/* 3B2BD0 E00AE880 0260202D */  daddu     $a0, $s3, $zero
/* 3B2BD4 E00AE884 44051000 */  mfc1      $a1, $f2
/* 3B2BD8 E00AE888 4407B000 */  mfc1      $a3, $f22
/* 3B2BDC E00AE88C 0C080110 */  jal       func_E0200440
/* 3B2BE0 E00AE890 00A0302D */   daddu    $a2, $a1, $zero
/* 3B2BE4 E00AE894 0260202D */  daddu     $a0, $s3, $zero
/* 3B2BE8 E00AE898 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B2BEC E00AE89C 0C080114 */  jal       func_E0200450
/* 3B2BF0 E00AE8A0 00A0302D */   daddu    $a2, $a1, $zero
/* 3B2BF4 E00AE8A4 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B2BF8 E00AE8A8 96E50000 */  lhu       $a1, ($s7)
/* 3B2BFC E00AE8AC 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3B2C00 E00AE8B0 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3B2C04 E00AE8B4 00052980 */  sll       $a1, $a1, 6
/* 3B2C08 E00AE8B8 00B42821 */  addu      $a1, $a1, $s4
/* 3B2C0C E00AE8BC 0C080118 */  jal       func_E0200460
/* 3B2C10 E00AE8C0 00452821 */   addu     $a1, $v0, $a1
/* 3B2C14 E00AE8C4 3C060100 */  lui       $a2, 0x100
/* 3B2C18 E00AE8C8 34C6007C */  ori       $a2, $a2, 0x7c
/* 3B2C1C E00AE8CC 3C07D838 */  lui       $a3, 0xd838
/* 3B2C20 E00AE8D0 8E240000 */  lw        $a0, ($s1)
/* 3B2C24 E00AE8D4 34E70002 */  ori       $a3, $a3, 2
/* 3B2C28 E00AE8D8 0080282D */  daddu     $a1, $a0, $zero
/* 3B2C2C E00AE8DC 24840008 */  addiu     $a0, $a0, 8
/* 3B2C30 E00AE8E0 AE240000 */  sw        $a0, ($s1)
/* 3B2C34 E00AE8E4 96E20000 */  lhu       $v0, ($s7)
/* 3B2C38 E00AE8E8 3C03DA38 */  lui       $v1, 0xda38
/* 3B2C3C E00AE8EC ACA30000 */  sw        $v1, ($a1)
/* 3B2C40 E00AE8F0 24430001 */  addiu     $v1, $v0, 1
/* 3B2C44 E00AE8F4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B2C48 E00AE8F8 00021180 */  sll       $v0, $v0, 6
/* 3B2C4C E00AE8FC A6E30000 */  sh        $v1, ($s7)
/* 3B2C50 E00AE900 3C03800A */  lui       $v1, %hi(D_8009A674)
/* 3B2C54 E00AE904 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* 3B2C58 E00AE908 00541021 */  addu      $v0, $v0, $s4
/* 3B2C5C E00AE90C 00621821 */  addu      $v1, $v1, $v0
/* 3B2C60 E00AE910 24820008 */  addiu     $v0, $a0, 8
/* 3B2C64 E00AE914 ACA30004 */  sw        $v1, 4($a1)
/* 3B2C68 E00AE918 AE220000 */  sw        $v0, ($s1)
/* 3B2C6C E00AE91C 24820010 */  addiu     $v0, $a0, 0x10
/* 3B2C70 E00AE920 AE220000 */  sw        $v0, ($s1)
/* 3B2C74 E00AE924 24820018 */  addiu     $v0, $a0, 0x18
/* 3B2C78 E00AE928 AE220000 */  sw        $v0, ($s1)
/* 3B2C7C E00AE92C 8E020000 */  lw        $v0, ($s0)
/* 3B2C80 E00AE930 24830020 */  addiu     $v1, $a0, 0x20
/* 3B2C84 E00AE934 AE230000 */  sw        $v1, ($s1)
/* 3B2C88 E00AE938 00021180 */  sll       $v0, $v0, 6
/* 3B2C8C E00AE93C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3B2C90 E00AE940 00021300 */  sll       $v0, $v0, 0xc
/* 3B2C94 E00AE944 005E1025 */  or        $v0, $v0, $fp
/* 3B2C98 E00AE948 AC820000 */  sw        $v0, ($a0)
/* 3B2C9C E00AE94C 00161080 */  sll       $v0, $s6, 2
/* 3B2CA0 E00AE950 30420FFF */  andi      $v0, $v0, 0xfff
/* 3B2CA4 E00AE954 00021300 */  sll       $v0, $v0, 0xc
/* 3B2CA8 E00AE958 8E030000 */  lw        $v1, ($s0)
/* 3B2CAC E00AE95C 005E1025 */  or        $v0, $v0, $fp
/* 3B2CB0 E00AE960 AC820008 */  sw        $v0, 8($a0)
/* 3B2CB4 E00AE964 8FA900AC */  lw        $t1, 0xac($sp)
/* 3B2CB8 E00AE968 3C02DE00 */  lui       $v0, 0xde00
/* 3B2CBC E00AE96C AC820010 */  sw        $v0, 0x10($a0)
/* 3B2CC0 E00AE970 3C020900 */  lui       $v0, 0x900
/* 3B2CC4 E00AE974 244210F8 */  addiu     $v0, $v0, 0x10f8
/* 3B2CC8 E00AE978 AC820014 */  sw        $v0, 0x14($a0)
/* 3B2CCC E00AE97C 24020040 */  addiu     $v0, $zero, 0x40
/* 3B2CD0 E00AE980 AC870018 */  sw        $a3, 0x18($a0)
/* 3B2CD4 E00AE984 AC82001C */  sw        $v0, 0x1c($a0)
/* 3B2CD8 E00AE988 01263025 */  or        $a2, $t1, $a2
/* 3B2CDC E00AE98C 00031980 */  sll       $v1, $v1, 6
/* 3B2CE0 E00AE990 3463003C */  ori       $v1, $v1, 0x3c
/* 3B2CE4 E00AE994 30630FFF */  andi      $v1, $v1, 0xfff
/* 3B2CE8 E00AE998 00031B00 */  sll       $v1, $v1, 0xc
/* 3B2CEC E00AE99C 3463007C */  ori       $v1, $v1, 0x7c
/* 3B2CF0 E00AE9A0 AC86000C */  sw        $a2, 0xc($a0)
/* 3B2CF4 E00AE9A4 AC830004 */  sw        $v1, 4($a0)
/* 3B2CF8 E00AE9A8 8FA900E8 */  lw        $t1, 0xe8($sp)
/* 3B2CFC E00AE9AC 26B50001 */  addiu     $s5, $s5, 1
/* 3B2D00 E00AE9B0 8D220008 */  lw        $v0, 8($t1)
/* 3B2D04 E00AE9B4 02A2102A */  slt       $v0, $s5, $v0
/* 3B2D08 E00AE9B8 1440FF86 */  bnez      $v0, .LE00AE7D4
/* 3B2D0C E00AE9BC 26100044 */   addiu    $s0, $s0, 0x44
.LE00AE9C0:
/* 3B2D10 E00AE9C0 3C05E200 */  lui       $a1, 0xe200
/* 3B2D14 E00AE9C4 34A51E01 */  ori       $a1, $a1, 0x1e01
/* 3B2D18 E00AE9C8 3C06D838 */  lui       $a2, 0xd838
/* 3B2D1C E00AE9CC 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 3B2D20 E00AE9D0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 3B2D24 E00AE9D4 8C820000 */  lw        $v0, ($a0)
/* 3B2D28 E00AE9D8 34C60002 */  ori       $a2, $a2, 2
/* 3B2D2C E00AE9DC 0040182D */  daddu     $v1, $v0, $zero
/* 3B2D30 E00AE9E0 24420008 */  addiu     $v0, $v0, 8
/* 3B2D34 E00AE9E4 AC820000 */  sw        $v0, ($a0)
/* 3B2D38 E00AE9E8 AC650000 */  sw        $a1, ($v1)
/* 3B2D3C E00AE9EC AC600004 */  sw        $zero, 4($v1)
/* 3B2D40 E00AE9F0 24430008 */  addiu     $v1, $v0, 8
/* 3B2D44 E00AE9F4 AC830000 */  sw        $v1, ($a0)
/* 3B2D48 E00AE9F8 24030040 */  addiu     $v1, $zero, 0x40
/* 3B2D4C E00AE9FC AC460000 */  sw        $a2, ($v0)
/* 3B2D50 E00AEA00 AC430004 */  sw        $v1, 4($v0)
/* 3B2D54 E00AEA04 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3B2D58 E00AEA08 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3B2D5C E00AEA0C 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3B2D60 E00AEA10 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3B2D64 E00AEA14 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3B2D68 E00AEA18 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3B2D6C E00AEA1C 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3B2D70 E00AEA20 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3B2D74 E00AEA24 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3B2D78 E00AEA28 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3B2D7C E00AEA2C D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 3B2D80 E00AEA30 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3B2D84 E00AEA34 03E00008 */  jr        $ra
/* 3B2D88 E00AEA38 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 3B2D8C E00AEA3C 00000000 */  nop       
