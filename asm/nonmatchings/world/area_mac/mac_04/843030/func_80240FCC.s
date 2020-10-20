.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FCC
/* 843B9C 80240FCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 843BA0 80240FD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 843BA4 80240FD4 0080882D */  daddu     $s1, $a0, $zero
/* 843BA8 80240FD8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 843BAC 80240FDC AFB00010 */  sw        $s0, 0x10($sp)
/* 843BB0 80240FE0 8E30000C */  lw        $s0, 0xc($s1)
/* 843BB4 80240FE4 8E050000 */  lw        $a1, ($s0)
/* 843BB8 80240FE8 0C0B1EAF */  jal       get_variable
/* 843BBC 80240FEC 26100004 */   addiu    $s0, $s0, 4
/* 843BC0 80240FF0 0220202D */  daddu     $a0, $s1, $zero
/* 843BC4 80240FF4 8E050000 */  lw        $a1, ($s0)
/* 843BC8 80240FF8 0C0B210B */  jal       get_float_variable
/* 843BCC 80240FFC 0040802D */   daddu    $s0, $v0, $zero
/* 843BD0 80241000 24020002 */  addiu     $v0, $zero, 2
/* 843BD4 80241004 00501804 */  sllv      $v1, $s0, $v0
/* 843BD8 80241008 00701821 */  addu      $v1, $v1, $s0
/* 843BDC 8024100C 00431804 */  sllv      $v1, $v1, $v0
/* 843BE0 80241010 00701823 */  subu      $v1, $v1, $s0
/* 843BE4 80241014 000320C0 */  sll       $a0, $v1, 3
/* 843BE8 80241018 00641821 */  addu      $v1, $v1, $a0
/* 843BEC 8024101C 000318C0 */  sll       $v1, $v1, 3
/* 843BF0 80241020 3C01800B */  lui       $at, 0x800b
/* 843BF4 80241024 00230821 */  addu      $at, $at, $v1
/* 843BF8 80241028 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 843BFC 8024102C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 843C00 80241030 8FB10014 */  lw        $s1, 0x14($sp)
/* 843C04 80241034 8FB00010 */  lw        $s0, 0x10($sp)
/* 843C08 80241038 03E00008 */  jr        $ra
/* 843C0C 8024103C 27BD0020 */   addiu    $sp, $sp, 0x20
