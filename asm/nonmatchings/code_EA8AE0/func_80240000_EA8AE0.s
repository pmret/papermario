.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nonmatchings_DeadUnkTexturePanFunc
/* EA8AE0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA8AE4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* EA8AE8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* EA8AEC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* EA8AF0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* EA8AF4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* EA8AF8 80240018 00621821 */  addu      $v1, $v1, $v0
/* EA8AFC 8024001C 04610004 */  bgez      $v1, .L80240030
/* EA8B00 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* EA8B04 80240024 3C020002 */  lui       $v0, 2
/* EA8B08 80240028 08090010 */  j         .L80240040
/* EA8B0C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* EA8B10 80240030 3C040002 */  lui       $a0, 2
/* EA8B14 80240034 0083102A */  slt       $v0, $a0, $v1
/* EA8B18 80240038 10400002 */  beqz      $v0, .L80240044
/* EA8B1C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* EA8B20 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* EA8B24 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* EA8B28 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* EA8B2C 8024004C 00621821 */  addu      $v1, $v1, $v0
/* EA8B30 80240050 04610004 */  bgez      $v1, .L80240064
/* EA8B34 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* EA8B38 80240058 3C020002 */  lui       $v0, 2
/* EA8B3C 8024005C 0809001D */  j         .L80240074
/* EA8B40 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* EA8B44 80240064 3C040002 */  lui       $a0, 2
/* EA8B48 80240068 0083102A */  slt       $v0, $a0, $v1
/* EA8B4C 8024006C 10400002 */  beqz      $v0, .L80240078
/* EA8B50 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* EA8B54 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* EA8B58 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* EA8B5C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* EA8B60 80240080 00621821 */  addu      $v1, $v1, $v0
/* EA8B64 80240084 04610004 */  bgez      $v1, .L80240098
/* EA8B68 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* EA8B6C 8024008C 3C020002 */  lui       $v0, 2
/* EA8B70 80240090 0809002A */  j         .L802400A8
/* EA8B74 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* EA8B78 80240098 3C040002 */  lui       $a0, 2
/* EA8B7C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* EA8B80 802400A0 10400002 */  beqz      $v0, .L802400AC
/* EA8B84 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* EA8B88 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* EA8B8C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* EA8B90 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* EA8B94 802400B4 00621821 */  addu      $v1, $v1, $v0
/* EA8B98 802400B8 04610004 */  bgez      $v1, .L802400CC
/* EA8B9C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* EA8BA0 802400C0 3C020002 */  lui       $v0, 2
/* EA8BA4 802400C4 08090037 */  j         .L802400DC
/* EA8BA8 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* EA8BAC 802400CC 3C040002 */  lui       $a0, 2
/* EA8BB0 802400D0 0083102A */  slt       $v0, $a0, $v1
/* EA8BB4 802400D4 10400002 */  beqz      $v0, .L802400E0
/* EA8BB8 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* EA8BBC 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* EA8BC0 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* EA8BC4 802400E4 0C049819 */  jal       func_80126064
/* EA8BC8 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* EA8BCC 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* EA8BD0 802400F0 0C04981F */  jal       func_8012607C
/* EA8BD4 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* EA8BD8 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* EA8BDC 802400FC 0C049825 */  jal       func_80126094
/* EA8BE0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* EA8BE4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* EA8BE8 80240108 0C04982B */  jal       func_801260AC
/* EA8BEC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* EA8BF0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA8BF4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* EA8BF8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* EA8BFC 8024011C 03E00008 */  jr        $ra
/* EA8C00 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
