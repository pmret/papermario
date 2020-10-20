.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AF2CA0
/* AF2CA0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF2CA4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* AF2CA8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* AF2CAC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* AF2CB0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AF2CB4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* AF2CB8 80240018 00621821 */  addu      $v1, $v1, $v0
/* AF2CBC 8024001C 04610004 */  bgez      $v1, .L80240030
/* AF2CC0 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AF2CC4 80240024 3C020002 */  lui       $v0, 2
/* AF2CC8 80240028 08090010 */  j         .L80240040
/* AF2CCC 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* AF2CD0 80240030 3C040002 */  lui       $a0, 2
/* AF2CD4 80240034 0083102A */  slt       $v0, $a0, $v1
/* AF2CD8 80240038 10400002 */  beqz      $v0, .L80240044
/* AF2CDC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* AF2CE0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* AF2CE4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* AF2CE8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* AF2CEC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* AF2CF0 80240050 04610004 */  bgez      $v1, .L80240064
/* AF2CF4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* AF2CF8 80240058 3C020002 */  lui       $v0, 2
/* AF2CFC 8024005C 0809001D */  j         .L80240074
/* AF2D00 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* AF2D04 80240064 3C040002 */  lui       $a0, 2
/* AF2D08 80240068 0083102A */  slt       $v0, $a0, $v1
/* AF2D0C 8024006C 10400002 */  beqz      $v0, .L80240078
/* AF2D10 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* AF2D14 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* AF2D18 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AF2D1C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* AF2D20 80240080 00621821 */  addu      $v1, $v1, $v0
/* AF2D24 80240084 04610004 */  bgez      $v1, .L80240098
/* AF2D28 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AF2D2C 8024008C 3C020002 */  lui       $v0, 2
/* AF2D30 80240090 0809002A */  j         .L802400A8
/* AF2D34 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* AF2D38 80240098 3C040002 */  lui       $a0, 2
/* AF2D3C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* AF2D40 802400A0 10400002 */  beqz      $v0, .L802400AC
/* AF2D44 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* AF2D48 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* AF2D4C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AF2D50 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* AF2D54 802400B4 00621821 */  addu      $v1, $v1, $v0
/* AF2D58 802400B8 04610004 */  bgez      $v1, .L802400CC
/* AF2D5C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* AF2D60 802400C0 3C020002 */  lui       $v0, 2
/* AF2D64 802400C4 08090037 */  j         .L802400DC
/* AF2D68 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* AF2D6C 802400CC 3C040002 */  lui       $a0, 2
/* AF2D70 802400D0 0083102A */  slt       $v0, $a0, $v1
/* AF2D74 802400D4 10400002 */  beqz      $v0, .L802400E0
/* AF2D78 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* AF2D7C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* AF2D80 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* AF2D84 802400E4 0C046F07 */  jal       set_main_pan_u
/* AF2D88 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AF2D8C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* AF2D90 802400F0 0C046F0D */  jal       set_main_pan_v
/* AF2D94 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* AF2D98 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* AF2D9C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* AF2DA0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AF2DA4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* AF2DA8 80240108 0C046F19 */  jal       set_aux_pan_v
/* AF2DAC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AF2DB0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* AF2DB4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* AF2DB8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* AF2DBC 8024011C 03E00008 */  jr        $ra
/* AF2DC0 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
