.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CF7B70
/* CF7B70 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF7B74 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* CF7B78 80240008 0080802D */  daddu     $s0, $a0, $zero
/* CF7B7C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* CF7B80 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CF7B84 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* CF7B88 80240018 00621821 */  addu      $v1, $v1, $v0
/* CF7B8C 8024001C 04610004 */  bgez      $v1, .L80240030
/* CF7B90 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CF7B94 80240024 3C020002 */  lui       $v0, 2
/* CF7B98 80240028 08090010 */  j         .L80240040
/* CF7B9C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* CF7BA0 80240030 3C040002 */  lui       $a0, 2
/* CF7BA4 80240034 0083102A */  slt       $v0, $a0, $v1
/* CF7BA8 80240038 10400002 */  beqz      $v0, .L80240044
/* CF7BAC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* CF7BB0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* CF7BB4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* CF7BB8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* CF7BBC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* CF7BC0 80240050 04610004 */  bgez      $v1, .L80240064
/* CF7BC4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* CF7BC8 80240058 3C020002 */  lui       $v0, 2
/* CF7BCC 8024005C 0809001D */  j         .L80240074
/* CF7BD0 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* CF7BD4 80240064 3C040002 */  lui       $a0, 2
/* CF7BD8 80240068 0083102A */  slt       $v0, $a0, $v1
/* CF7BDC 8024006C 10400002 */  beqz      $v0, .L80240078
/* CF7BE0 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* CF7BE4 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* CF7BE8 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CF7BEC 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* CF7BF0 80240080 00621821 */  addu      $v1, $v1, $v0
/* CF7BF4 80240084 04610004 */  bgez      $v1, .L80240098
/* CF7BF8 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* CF7BFC 8024008C 3C020002 */  lui       $v0, 2
/* CF7C00 80240090 0809002A */  j         .L802400A8
/* CF7C04 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* CF7C08 80240098 3C040002 */  lui       $a0, 2
/* CF7C0C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* CF7C10 802400A0 10400002 */  beqz      $v0, .L802400AC
/* CF7C14 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* CF7C18 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* CF7C1C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CF7C20 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* CF7C24 802400B4 00621821 */  addu      $v1, $v1, $v0
/* CF7C28 802400B8 04610004 */  bgez      $v1, .L802400CC
/* CF7C2C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* CF7C30 802400C0 3C020002 */  lui       $v0, 2
/* CF7C34 802400C4 08090037 */  j         .L802400DC
/* CF7C38 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* CF7C3C 802400CC 3C040002 */  lui       $a0, 2
/* CF7C40 802400D0 0083102A */  slt       $v0, $a0, $v1
/* CF7C44 802400D4 10400002 */  beqz      $v0, .L802400E0
/* CF7C48 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* CF7C4C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* CF7C50 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* CF7C54 802400E4 0C046F07 */  jal       set_main_pan_u
/* CF7C58 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CF7C5C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* CF7C60 802400F0 0C046F0D */  jal       set_main_pan_v
/* CF7C64 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* CF7C68 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* CF7C6C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* CF7C70 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CF7C74 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* CF7C78 80240108 0C046F19 */  jal       set_aux_pan_v
/* CF7C7C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CF7C80 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF7C84 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* CF7C88 80240118 0000102D */  daddu     $v0, $zero, $zero
/* CF7C8C 8024011C 03E00008 */  jr        $ra
/* CF7C90 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
