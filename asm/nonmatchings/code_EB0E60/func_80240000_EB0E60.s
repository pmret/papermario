.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nonmatchings_DeadUnkTexturePanFunc
/* EB0E60 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB0E64 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* EB0E68 80240008 0080802D */  daddu     $s0, $a0, $zero
/* EB0E6C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* EB0E70 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* EB0E74 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* EB0E78 80240018 00621821 */  addu      $v1, $v1, $v0
/* EB0E7C 8024001C 04610004 */  bgez      $v1, .L80240030
/* EB0E80 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* EB0E84 80240024 3C020002 */  lui       $v0, 2
/* EB0E88 80240028 08090010 */  j         .L80240040
/* EB0E8C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* EB0E90 80240030 3C040002 */  lui       $a0, 2
/* EB0E94 80240034 0083102A */  slt       $v0, $a0, $v1
/* EB0E98 80240038 10400002 */  beqz      $v0, .L80240044
/* EB0E9C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* EB0EA0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* EB0EA4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* EB0EA8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* EB0EAC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* EB0EB0 80240050 04610004 */  bgez      $v1, .L80240064
/* EB0EB4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* EB0EB8 80240058 3C020002 */  lui       $v0, 2
/* EB0EBC 8024005C 0809001D */  j         .L80240074
/* EB0EC0 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* EB0EC4 80240064 3C040002 */  lui       $a0, 2
/* EB0EC8 80240068 0083102A */  slt       $v0, $a0, $v1
/* EB0ECC 8024006C 10400002 */  beqz      $v0, .L80240078
/* EB0ED0 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* EB0ED4 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* EB0ED8 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* EB0EDC 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* EB0EE0 80240080 00621821 */  addu      $v1, $v1, $v0
/* EB0EE4 80240084 04610004 */  bgez      $v1, .L80240098
/* EB0EE8 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* EB0EEC 8024008C 3C020002 */  lui       $v0, 2
/* EB0EF0 80240090 0809002A */  j         .L802400A8
/* EB0EF4 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* EB0EF8 80240098 3C040002 */  lui       $a0, 2
/* EB0EFC 8024009C 0083102A */  slt       $v0, $a0, $v1
/* EB0F00 802400A0 10400002 */  beqz      $v0, .L802400AC
/* EB0F04 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* EB0F08 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* EB0F0C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* EB0F10 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* EB0F14 802400B4 00621821 */  addu      $v1, $v1, $v0
/* EB0F18 802400B8 04610004 */  bgez      $v1, .L802400CC
/* EB0F1C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* EB0F20 802400C0 3C020002 */  lui       $v0, 2
/* EB0F24 802400C4 08090037 */  j         .L802400DC
/* EB0F28 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* EB0F2C 802400CC 3C040002 */  lui       $a0, 2
/* EB0F30 802400D0 0083102A */  slt       $v0, $a0, $v1
/* EB0F34 802400D4 10400002 */  beqz      $v0, .L802400E0
/* EB0F38 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* EB0F3C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* EB0F40 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* EB0F44 802400E4 0C049819 */  jal       func_80126064
/* EB0F48 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* EB0F4C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* EB0F50 802400F0 0C04981F */  jal       func_8012607C
/* EB0F54 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* EB0F58 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* EB0F5C 802400FC 0C049825 */  jal       func_80126094
/* EB0F60 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* EB0F64 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* EB0F68 80240108 0C04982B */  jal       func_801260AC
/* EB0F6C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* EB0F70 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB0F74 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* EB0F78 80240118 0000102D */  daddu     $v0, $zero, $zero
/* EB0F7C 8024011C 03E00008 */  jr        $ra
/* EB0F80 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
