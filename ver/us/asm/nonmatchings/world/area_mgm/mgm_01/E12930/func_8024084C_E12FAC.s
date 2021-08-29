.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024084C_E12FAC
/* E12FAC 8024084C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E12FB0 80240850 AFB10014 */  sw        $s1, 0x14($sp)
/* E12FB4 80240854 0080882D */  daddu     $s1, $a0, $zero
/* E12FB8 80240858 0000202D */  daddu     $a0, $zero, $zero
/* E12FBC 8024085C AFBF0018 */  sw        $ra, 0x18($sp)
/* E12FC0 80240860 0C00FB3A */  jal       get_enemy
/* E12FC4 80240864 AFB00010 */   sw       $s0, 0x10($sp)
/* E12FC8 80240868 8E23000C */  lw        $v1, 0xc($s1)
/* E12FCC 8024086C 8C650000 */  lw        $a1, ($v1)
/* E12FD0 80240870 8C500080 */  lw        $s0, 0x80($v0)
/* E12FD4 80240874 0C0B1EAF */  jal       get_variable
/* E12FD8 80240878 0220202D */   daddu    $a0, $s1, $zero
/* E12FDC 8024087C 00021840 */  sll       $v1, $v0, 1
/* E12FE0 80240880 00621821 */  addu      $v1, $v1, $v0
/* E12FE4 80240884 000318C0 */  sll       $v1, $v1, 3
/* E12FE8 80240888 00621823 */  subu      $v1, $v1, $v0
/* E12FEC 8024088C 00031880 */  sll       $v1, $v1, 2
/* E12FF0 80240890 02038021 */  addu      $s0, $s0, $v1
/* E12FF4 80240894 8E02008C */  lw        $v0, 0x8c($s0)
/* E12FF8 80240898 8E030090 */  lw        $v1, 0x90($s0)
/* E12FFC 8024089C 24420001 */  addiu     $v0, $v0, 1
/* E13000 802408A0 AE02008C */  sw        $v0, 0x8c($s0)
/* E13004 802408A4 0043102A */  slt       $v0, $v0, $v1
/* E13008 802408A8 14400005 */  bnez      $v0, .L802408C0
/* E1300C 802408AC 0220202D */   daddu    $a0, $s1, $zero
/* E13010 802408B0 3C05FE36 */  lui       $a1, 0xfe36
/* E13014 802408B4 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E13018 802408B8 08090233 */  j         .L802408CC
/* E1301C 802408BC 24060001 */   addiu    $a2, $zero, 1
.L802408C0:
/* E13020 802408C0 3C05FE36 */  lui       $a1, 0xfe36
/* E13024 802408C4 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E13028 802408C8 0000302D */  daddu     $a2, $zero, $zero
.L802408CC:
/* E1302C 802408CC 0C0B2026 */  jal       evt_set_variable
/* E13030 802408D0 00000000 */   nop
/* E13034 802408D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E13038 802408D8 8FB10014 */  lw        $s1, 0x14($sp)
/* E1303C 802408DC 8FB00010 */  lw        $s0, 0x10($sp)
/* E13040 802408E0 24020002 */  addiu     $v0, $zero, 2
/* E13044 802408E4 03E00008 */  jr        $ra
/* E13048 802408E8 27BD0020 */   addiu    $sp, $sp, 0x20
