.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_E1E740
/* E1E740 802402E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1E744 802402E4 AFB00010 */  sw        $s0, 0x10($sp)
/* E1E748 802402E8 0080802D */  daddu     $s0, $a0, $zero
/* E1E74C 802402EC AFBF0014 */  sw        $ra, 0x14($sp)
/* E1E750 802402F0 8E0300A8 */  lw        $v1, 0xa8($s0)
/* E1E754 802402F4 8E020088 */  lw        $v0, 0x88($s0)
/* E1E758 802402F8 00621821 */  addu      $v1, $v1, $v0
/* E1E75C 802402FC 04610004 */  bgez      $v1, .L80240310
/* E1E760 80240300 AE0300A8 */   sw       $v1, 0xa8($s0)
/* E1E764 80240304 3C020002 */  lui       $v0, 2
/* E1E768 80240308 080900C8 */  j         .L80240320
/* E1E76C 8024030C 00621021 */   addu     $v0, $v1, $v0
.L80240310:
/* E1E770 80240310 3C040002 */  lui       $a0, 2
/* E1E774 80240314 0083102A */  slt       $v0, $a0, $v1
/* E1E778 80240318 10400002 */  beqz      $v0, .L80240324
/* E1E77C 8024031C 00641023 */   subu     $v0, $v1, $a0
.L80240320:
/* E1E780 80240320 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240324:
/* E1E784 80240324 8E0300AC */  lw        $v1, 0xac($s0)
/* E1E788 80240328 8E02008C */  lw        $v0, 0x8c($s0)
/* E1E78C 8024032C 00621821 */  addu      $v1, $v1, $v0
/* E1E790 80240330 04610004 */  bgez      $v1, .L80240344
/* E1E794 80240334 AE0300AC */   sw       $v1, 0xac($s0)
/* E1E798 80240338 3C020002 */  lui       $v0, 2
/* E1E79C 8024033C 080900D5 */  j         .L80240354
/* E1E7A0 80240340 00621021 */   addu     $v0, $v1, $v0
.L80240344:
/* E1E7A4 80240344 3C040002 */  lui       $a0, 2
/* E1E7A8 80240348 0083102A */  slt       $v0, $a0, $v1
/* E1E7AC 8024034C 10400002 */  beqz      $v0, .L80240358
/* E1E7B0 80240350 00641023 */   subu     $v0, $v1, $a0
.L80240354:
/* E1E7B4 80240354 AE0200AC */  sw        $v0, 0xac($s0)
.L80240358:
/* E1E7B8 80240358 8E0300B0 */  lw        $v1, 0xb0($s0)
/* E1E7BC 8024035C 8E020090 */  lw        $v0, 0x90($s0)
/* E1E7C0 80240360 00621821 */  addu      $v1, $v1, $v0
/* E1E7C4 80240364 04610004 */  bgez      $v1, .L80240378
/* E1E7C8 80240368 AE0300B0 */   sw       $v1, 0xb0($s0)
/* E1E7CC 8024036C 3C020002 */  lui       $v0, 2
/* E1E7D0 80240370 080900E2 */  j         .L80240388
/* E1E7D4 80240374 00621021 */   addu     $v0, $v1, $v0
.L80240378:
/* E1E7D8 80240378 3C040002 */  lui       $a0, 2
/* E1E7DC 8024037C 0083102A */  slt       $v0, $a0, $v1
/* E1E7E0 80240380 10400002 */  beqz      $v0, .L8024038C
/* E1E7E4 80240384 00641023 */   subu     $v0, $v1, $a0
.L80240388:
/* E1E7E8 80240388 AE0200B0 */  sw        $v0, 0xb0($s0)
.L8024038C:
/* E1E7EC 8024038C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* E1E7F0 80240390 8E020094 */  lw        $v0, 0x94($s0)
/* E1E7F4 80240394 00621821 */  addu      $v1, $v1, $v0
/* E1E7F8 80240398 04610004 */  bgez      $v1, .L802403AC
/* E1E7FC 8024039C AE0300B4 */   sw       $v1, 0xb4($s0)
/* E1E800 802403A0 3C020002 */  lui       $v0, 2
/* E1E804 802403A4 080900EF */  j         .L802403BC
/* E1E808 802403A8 00621021 */   addu     $v0, $v1, $v0
.L802403AC:
/* E1E80C 802403AC 3C040002 */  lui       $a0, 2
/* E1E810 802403B0 0083102A */  slt       $v0, $a0, $v1
/* E1E814 802403B4 10400002 */  beqz      $v0, .L802403C0
/* E1E818 802403B8 00641023 */   subu     $v0, $v1, $a0
.L802403BC:
/* E1E81C 802403BC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802403C0:
/* E1E820 802403C0 8E040084 */  lw        $a0, 0x84($s0)
/* E1E824 802403C4 0C046F07 */  jal       set_main_pan_u
/* E1E828 802403C8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* E1E82C 802403CC 8E040084 */  lw        $a0, 0x84($s0)
/* E1E830 802403D0 0C046F0D */  jal       set_main_pan_v
/* E1E834 802403D4 8E0500AC */   lw       $a1, 0xac($s0)
/* E1E838 802403D8 8E040084 */  lw        $a0, 0x84($s0)
/* E1E83C 802403DC 0C046F13 */  jal       set_aux_pan_u
/* E1E840 802403E0 8E0500B0 */   lw       $a1, 0xb0($s0)
/* E1E844 802403E4 8E040084 */  lw        $a0, 0x84($s0)
/* E1E848 802403E8 0C046F19 */  jal       set_aux_pan_v
/* E1E84C 802403EC 8E0500B4 */   lw       $a1, 0xb4($s0)
/* E1E850 802403F0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E1E854 802403F4 8FB00010 */  lw        $s0, 0x10($sp)
/* E1E858 802403F8 0000102D */  daddu     $v0, $zero, $zero
/* E1E85C 802403FC 03E00008 */  jr        $ra
/* E1E860 80240400 27BD0018 */   addiu    $sp, $sp, 0x18
