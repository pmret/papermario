.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nonmatchings_DeadUnkTexturePanFunc
/* EFEB00 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EFEB04 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* EFEB08 80240008 0080802D */  daddu     $s0, $a0, $zero
/* EFEB0C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* EFEB10 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* EFEB14 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* EFEB18 80240018 00621821 */  addu      $v1, $v1, $v0
/* EFEB1C 8024001C 04610004 */  bgez      $v1, .L80240030
/* EFEB20 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* EFEB24 80240024 3C020002 */  lui       $v0, 2
/* EFEB28 80240028 08090010 */  j         .L80240040
/* EFEB2C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* EFEB30 80240030 3C040002 */  lui       $a0, 2
/* EFEB34 80240034 0083102A */  slt       $v0, $a0, $v1
/* EFEB38 80240038 10400002 */  beqz      $v0, .L80240044
/* EFEB3C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* EFEB40 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* EFEB44 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* EFEB48 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* EFEB4C 8024004C 00621821 */  addu      $v1, $v1, $v0
/* EFEB50 80240050 04610004 */  bgez      $v1, .L80240064
/* EFEB54 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* EFEB58 80240058 3C020002 */  lui       $v0, 2
/* EFEB5C 8024005C 0809001D */  j         .L80240074
/* EFEB60 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* EFEB64 80240064 3C040002 */  lui       $a0, 2
/* EFEB68 80240068 0083102A */  slt       $v0, $a0, $v1
/* EFEB6C 8024006C 10400002 */  beqz      $v0, .L80240078
/* EFEB70 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* EFEB74 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* EFEB78 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* EFEB7C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* EFEB80 80240080 00621821 */  addu      $v1, $v1, $v0
/* EFEB84 80240084 04610004 */  bgez      $v1, .L80240098
/* EFEB88 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* EFEB8C 8024008C 3C020002 */  lui       $v0, 2
/* EFEB90 80240090 0809002A */  j         .L802400A8
/* EFEB94 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* EFEB98 80240098 3C040002 */  lui       $a0, 2
/* EFEB9C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* EFEBA0 802400A0 10400002 */  beqz      $v0, .L802400AC
/* EFEBA4 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* EFEBA8 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* EFEBAC 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* EFEBB0 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* EFEBB4 802400B4 00621821 */  addu      $v1, $v1, $v0
/* EFEBB8 802400B8 04610004 */  bgez      $v1, .L802400CC
/* EFEBBC 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* EFEBC0 802400C0 3C020002 */  lui       $v0, 2
/* EFEBC4 802400C4 08090037 */  j         .L802400DC
/* EFEBC8 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* EFEBCC 802400CC 3C040002 */  lui       $a0, 2
/* EFEBD0 802400D0 0083102A */  slt       $v0, $a0, $v1
/* EFEBD4 802400D4 10400002 */  beqz      $v0, .L802400E0
/* EFEBD8 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* EFEBDC 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* EFEBE0 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* EFEBE4 802400E4 0C049819 */  jal       func_80126064
/* EFEBE8 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* EFEBEC 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* EFEBF0 802400F0 0C04981F */  jal       func_8012607C
/* EFEBF4 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* EFEBF8 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* EFEBFC 802400FC 0C049825 */  jal       func_80126094
/* EFEC00 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* EFEC04 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* EFEC08 80240108 0C04982B */  jal       func_801260AC
/* EFEC0C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* EFEC10 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* EFEC14 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* EFEC18 80240118 0000102D */  daddu     $v0, $zero, $zero
/* EFEC1C 8024011C 03E00008 */  jr        $ra
/* EFEC20 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
