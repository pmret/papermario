.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C8DBB0
/* C8DBB0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8DBB4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* C8DBB8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* C8DBBC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* C8DBC0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* C8DBC4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* C8DBC8 80240018 00621821 */  addu      $v1, $v1, $v0
/* C8DBCC 8024001C 04610004 */  bgez      $v1, .L80240030
/* C8DBD0 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* C8DBD4 80240024 3C020002 */  lui       $v0, 2
/* C8DBD8 80240028 08090010 */  j         .L80240040
/* C8DBDC 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* C8DBE0 80240030 3C040002 */  lui       $a0, 2
/* C8DBE4 80240034 0083102A */  slt       $v0, $a0, $v1
/* C8DBE8 80240038 10400002 */  beqz      $v0, .L80240044
/* C8DBEC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* C8DBF0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* C8DBF4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* C8DBF8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* C8DBFC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* C8DC00 80240050 04610004 */  bgez      $v1, .L80240064
/* C8DC04 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* C8DC08 80240058 3C020002 */  lui       $v0, 2
/* C8DC0C 8024005C 0809001D */  j         .L80240074
/* C8DC10 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* C8DC14 80240064 3C040002 */  lui       $a0, 2
/* C8DC18 80240068 0083102A */  slt       $v0, $a0, $v1
/* C8DC1C 8024006C 10400002 */  beqz      $v0, .L80240078
/* C8DC20 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* C8DC24 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* C8DC28 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* C8DC2C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* C8DC30 80240080 00621821 */  addu      $v1, $v1, $v0
/* C8DC34 80240084 04610004 */  bgez      $v1, .L80240098
/* C8DC38 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* C8DC3C 8024008C 3C020002 */  lui       $v0, 2
/* C8DC40 80240090 0809002A */  j         .L802400A8
/* C8DC44 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* C8DC48 80240098 3C040002 */  lui       $a0, 2
/* C8DC4C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* C8DC50 802400A0 10400002 */  beqz      $v0, .L802400AC
/* C8DC54 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* C8DC58 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* C8DC5C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* C8DC60 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* C8DC64 802400B4 00621821 */  addu      $v1, $v1, $v0
/* C8DC68 802400B8 04610004 */  bgez      $v1, .L802400CC
/* C8DC6C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* C8DC70 802400C0 3C020002 */  lui       $v0, 2
/* C8DC74 802400C4 08090037 */  j         .L802400DC
/* C8DC78 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* C8DC7C 802400CC 3C040002 */  lui       $a0, 2
/* C8DC80 802400D0 0083102A */  slt       $v0, $a0, $v1
/* C8DC84 802400D4 10400002 */  beqz      $v0, .L802400E0
/* C8DC88 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* C8DC8C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* C8DC90 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* C8DC94 802400E4 0C046F07 */  jal       set_main_pan_u
/* C8DC98 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* C8DC9C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* C8DCA0 802400F0 0C046F0D */  jal       set_main_pan_v
/* C8DCA4 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* C8DCA8 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* C8DCAC 802400FC 0C046F13 */  jal       set_aux_pan_u
/* C8DCB0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* C8DCB4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* C8DCB8 80240108 0C046F19 */  jal       set_aux_pan_v
/* C8DCBC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* C8DCC0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* C8DCC4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* C8DCC8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* C8DCCC 8024011C 03E00008 */  jr        $ra
/* C8DCD0 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
