.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BAF84_E2F8D4
/* E2F8D4 802BAF84 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* E2F8D8 802BAF88 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* E2F8DC 802BAF8C AFB200A0 */  sw        $s2, 0xa0($sp)
/* E2F8E0 802BAF90 AFB1009C */  sw        $s1, 0x9c($sp)
/* E2F8E4 802BAF94 0C04417A */  jal       get_entity_by_index
/* E2F8E8 802BAF98 AFB00098 */   sw       $s0, 0x98($sp)
/* E2F8EC 802BAF9C 27A40018 */  addiu     $a0, $sp, 0x18
/* E2F8F0 802BAFA0 0040902D */  daddu     $s2, $v0, $zero
/* E2F8F4 802BAFA4 3C050A00 */  lui       $a1, 0xa00
/* E2F8F8 802BAFA8 24A519A8 */  addiu     $a1, $a1, 0x19a8
/* E2F8FC 802BAFAC 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2F900 802BAFB0 8E420044 */  lw        $v0, 0x44($s2)
/* E2F904 802BAFB4 8E510040 */  lw        $s1, 0x40($s2)
/* E2F908 802BAFB8 0C019D60 */  jal       guMtxL2F
/* E2F90C 802BAFBC 00452821 */   addu     $a1, $v0, $a1
/* E2F910 802BAFC0 44800000 */  mtc1      $zero, $f0
/* E2F914 802BAFC4 3C073F80 */  lui       $a3, 0x3f80
/* E2F918 802BAFC8 27B00058 */  addiu     $s0, $sp, 0x58
/* E2F91C 802BAFCC E7A00010 */  swc1      $f0, 0x10($sp)
/* E2F920 802BAFD0 8E25000C */  lw        $a1, 0xc($s1)
/* E2F924 802BAFD4 44060000 */  mfc1      $a2, $f0
/* E2F928 802BAFD8 0C019EC8 */  jal       guRotateF
/* E2F92C 802BAFDC 0200202D */   daddu    $a0, $s0, $zero
/* E2F930 802BAFE0 0200202D */  daddu     $a0, $s0, $zero
/* E2F934 802BAFE4 27A50018 */  addiu     $a1, $sp, 0x18
/* E2F938 802BAFE8 0C019D80 */  jal       guMtxCatF
/* E2F93C 802BAFEC 00A0302D */   daddu    $a2, $a1, $zero
/* E2F940 802BAFF0 27A40018 */  addiu     $a0, $sp, 0x18
/* E2F944 802BAFF4 26300050 */  addiu     $s0, $s1, 0x50
/* E2F948 802BAFF8 0C019D40 */  jal       guMtxF2L
/* E2F94C 802BAFFC 0200282D */   daddu    $a1, $s0, $zero
/* E2F950 802BB000 3C040001 */  lui       $a0, 1
/* E2F954 802BB004 34841630 */  ori       $a0, $a0, 0x1630
/* E2F958 802BB008 26310090 */  addiu     $s1, $s1, 0x90
/* E2F95C 802BB00C 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* E2F960 802BB010 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* E2F964 802BB014 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2F968 802BB018 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2F96C 802BB01C 00021180 */  sll       $v0, $v0, 6
/* E2F970 802BB020 00621821 */  addu      $v1, $v1, $v0
/* E2F974 802BB024 00641821 */  addu      $v1, $v1, $a0
.L802BB028:
/* E2F978 802BB028 8E0A0000 */  lw        $t2, ($s0)
/* E2F97C 802BB02C 8E0B0004 */  lw        $t3, 4($s0)
/* E2F980 802BB030 8E0C0008 */  lw        $t4, 8($s0)
/* E2F984 802BB034 8E0D000C */  lw        $t5, 0xc($s0)
/* E2F988 802BB038 AC6A0000 */  sw        $t2, ($v1)
/* E2F98C 802BB03C AC6B0004 */  sw        $t3, 4($v1)
/* E2F990 802BB040 AC6C0008 */  sw        $t4, 8($v1)
/* E2F994 802BB044 AC6D000C */  sw        $t5, 0xc($v1)
/* E2F998 802BB048 26100010 */  addiu     $s0, $s0, 0x10
/* E2F99C 802BB04C 1611FFF6 */  bne       $s0, $s1, .L802BB028
/* E2F9A0 802BB050 24630010 */   addiu    $v1, $v1, 0x10
/* E2F9A4 802BB054 3C080001 */  lui       $t0, 1
/* E2F9A8 802BB058 35081630 */  ori       $t0, $t0, 0x1630
/* E2F9AC 802BB05C 3C09D838 */  lui       $t1, 0xd838
/* E2F9B0 802BB060 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* E2F9B4 802BB064 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* E2F9B8 802BB068 35290002 */  ori       $t1, $t1, 2
/* E2F9BC 802BB06C 8CC40000 */  lw        $a0, ($a2)
/* E2F9C0 802BB070 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* E2F9C4 802BB074 24A541F0 */  addiu     $a1, $a1, %lo(gMatrixListPos)
/* E2F9C8 802BB078 0080382D */  daddu     $a3, $a0, $zero
/* E2F9CC 802BB07C 24840008 */  addiu     $a0, $a0, 8
/* E2F9D0 802BB080 ACC40000 */  sw        $a0, ($a2)
/* E2F9D4 802BB084 94A20000 */  lhu       $v0, ($a1)
/* E2F9D8 802BB088 3C03DA38 */  lui       $v1, 0xda38
/* E2F9DC 802BB08C ACE30000 */  sw        $v1, ($a3)
/* E2F9E0 802BB090 24430001 */  addiu     $v1, $v0, 1
/* E2F9E4 802BB094 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2F9E8 802BB098 00021180 */  sll       $v0, $v0, 6
/* E2F9EC 802BB09C A4A30000 */  sh        $v1, ($a1)
/* E2F9F0 802BB0A0 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2F9F4 802BB0A4 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2F9F8 802BB0A8 00481021 */  addu      $v0, $v0, $t0
/* E2F9FC 802BB0AC 00621821 */  addu      $v1, $v1, $v0
/* E2FA00 802BB0B0 24820008 */  addiu     $v0, $a0, 8
/* E2FA04 802BB0B4 ACE30004 */  sw        $v1, 4($a3)
/* E2FA08 802BB0B8 ACC20000 */  sw        $v0, ($a2)
/* E2FA0C 802BB0BC 8E430044 */  lw        $v1, 0x44($s2)
/* E2FA10 802BB0C0 3C02DE00 */  lui       $v0, 0xde00
/* E2FA14 802BB0C4 AC820000 */  sw        $v0, ($a0)
/* E2FA18 802BB0C8 24820010 */  addiu     $v0, $a0, 0x10
/* E2FA1C 802BB0CC ACC20000 */  sw        $v0, ($a2)
/* E2FA20 802BB0D0 24020040 */  addiu     $v0, $zero, 0x40
/* E2FA24 802BB0D4 AC82000C */  sw        $v0, 0xc($a0)
/* E2FA28 802BB0D8 3C020A00 */  lui       $v0, 0xa00
/* E2FA2C 802BB0DC 24421B68 */  addiu     $v0, $v0, 0x1b68
/* E2FA30 802BB0E0 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2FA34 802BB0E4 AC890008 */  sw        $t1, 8($a0)
/* E2FA38 802BB0E8 00621821 */  addu      $v1, $v1, $v0
/* E2FA3C 802BB0EC AC830004 */  sw        $v1, 4($a0)
/* E2FA40 802BB0F0 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* E2FA44 802BB0F4 8FB200A0 */  lw        $s2, 0xa0($sp)
/* E2FA48 802BB0F8 8FB1009C */  lw        $s1, 0x9c($sp)
/* E2FA4C 802BB0FC 8FB00098 */  lw        $s0, 0x98($sp)
/* E2FA50 802BB100 03E00008 */  jr        $ra
/* E2FA54 802BB104 27BD00A8 */   addiu    $sp, $sp, 0xa8
