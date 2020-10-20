.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_988FE0
/* 988FE0 80240480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 988FE4 80240484 AFB1001C */  sw        $s1, 0x1c($sp)
/* 988FE8 80240488 0080882D */  daddu     $s1, $a0, $zero
/* 988FEC 8024048C AFBF0020 */  sw        $ra, 0x20($sp)
/* 988FF0 80240490 AFB00018 */  sw        $s0, 0x18($sp)
/* 988FF4 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* 988FF8 80240498 8E050000 */  lw        $a1, ($s0)
/* 988FFC 8024049C 0C0B1EAF */  jal       get_variable
/* 989000 802404A0 26100004 */   addiu    $s0, $s0, 4
/* 989004 802404A4 0C04417A */  jal       get_entity_by_index
/* 989008 802404A8 0040202D */   daddu    $a0, $v0, $zero
/* 98900C 802404AC 8E100000 */  lw        $s0, ($s0)
/* 989010 802404B0 C444004C */  lwc1      $f4, 0x4c($v0)
/* 989014 802404B4 3C014148 */  lui       $at, 0x4148
/* 989018 802404B8 44810000 */  mtc1      $at, $f0
/* 98901C 802404BC 3C013F33 */  lui       $at, 0x3f33
/* 989020 802404C0 34213333 */  ori       $at, $at, 0x3333
/* 989024 802404C4 44811000 */  mtc1      $at, $f2
/* 989028 802404C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 98902C 802404CC 46002100 */  add.s     $f4, $f4, $f0
/* 989030 802404D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* 989034 802404D4 8C450048 */  lw        $a1, 0x48($v0)
/* 989038 802404D8 8C470050 */  lw        $a3, 0x50($v0)
/* 98903C 802404DC 44062000 */  mfc1      $a2, $f4
/* 989040 802404E0 0C01C5D4 */  jal       func_80071750
/* 989044 802404E4 0000202D */   daddu    $a0, $zero, $zero
/* 989048 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* 98904C 802404EC 0200282D */  daddu     $a1, $s0, $zero
/* 989050 802404F0 0C0B2026 */  jal       set_variable
/* 989054 802404F4 0040302D */   daddu    $a2, $v0, $zero
/* 989058 802404F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 98905C 802404FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 989060 80240500 8FB00018 */  lw        $s0, 0x18($sp)
/* 989064 80240504 24020002 */  addiu     $v0, $zero, 2
/* 989068 80240508 03E00008 */  jr        $ra
/* 98906C 8024050C 27BD0028 */   addiu    $sp, $sp, 0x28
