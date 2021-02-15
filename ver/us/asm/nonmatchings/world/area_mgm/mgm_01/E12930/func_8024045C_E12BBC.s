.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024045C_E12BBC
/* E12BBC 8024045C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E12BC0 80240460 AFB10014 */  sw        $s1, 0x14($sp)
/* E12BC4 80240464 0080882D */  daddu     $s1, $a0, $zero
/* E12BC8 80240468 0000202D */  daddu     $a0, $zero, $zero
/* E12BCC 8024046C AFBF0018 */  sw        $ra, 0x18($sp)
/* E12BD0 80240470 0C00FB3A */  jal       get_enemy
/* E12BD4 80240474 AFB00010 */   sw       $s0, 0x10($sp)
/* E12BD8 80240478 8E23000C */  lw        $v1, 0xc($s1)
/* E12BDC 8024047C 8C650000 */  lw        $a1, ($v1)
/* E12BE0 80240480 8C500080 */  lw        $s0, 0x80($v0)
/* E12BE4 80240484 0C0B1EAF */  jal       get_variable
/* E12BE8 80240488 0220202D */   daddu    $a0, $s1, $zero
/* E12BEC 8024048C 0220202D */  daddu     $a0, $s1, $zero
/* E12BF0 80240490 3C05FE36 */  lui       $a1, 0xfe36
/* E12BF4 80240494 00021840 */  sll       $v1, $v0, 1
/* E12BF8 80240498 00621821 */  addu      $v1, $v1, $v0
/* E12BFC 8024049C 000318C0 */  sll       $v1, $v1, 3
/* E12C00 802404A0 00621823 */  subu      $v1, $v1, $v0
/* E12C04 802404A4 00031880 */  sll       $v1, $v1, 2
/* E12C08 802404A8 02038021 */  addu      $s0, $s0, $v1
/* E12C0C 802404AC 8E060074 */  lw        $a2, 0x74($s0)
/* E12C10 802404B0 0C0B2026 */  jal       set_variable
/* E12C14 802404B4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* E12C18 802404B8 0220202D */  daddu     $a0, $s1, $zero
/* E12C1C 802404BC 3C05FE36 */  lui       $a1, 0xfe36
/* E12C20 802404C0 8E060078 */  lw        $a2, 0x78($s0)
/* E12C24 802404C4 0C0B2026 */  jal       set_variable
/* E12C28 802404C8 34A53C81 */   ori      $a1, $a1, 0x3c81
/* E12C2C 802404CC 0220202D */  daddu     $a0, $s1, $zero
/* E12C30 802404D0 3C05FE36 */  lui       $a1, 0xfe36
/* E12C34 802404D4 8E06007C */  lw        $a2, 0x7c($s0)
/* E12C38 802404D8 0C0B2026 */  jal       set_variable
/* E12C3C 802404DC 34A53C82 */   ori      $a1, $a1, 0x3c82
/* E12C40 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* E12C44 802404E4 3C05FE36 */  lui       $a1, 0xfe36
/* E12C48 802404E8 8E060084 */  lw        $a2, 0x84($s0)
/* E12C4C 802404EC 0C0B2026 */  jal       set_variable
/* E12C50 802404F0 34A53C83 */   ori      $a1, $a1, 0x3c83
/* E12C54 802404F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E12C58 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* E12C5C 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* E12C60 80240500 24020002 */  addiu     $v0, $zero, 2
/* E12C64 80240504 03E00008 */  jr        $ra
/* E12C68 80240508 27BD0020 */   addiu    $sp, $sp, 0x20
