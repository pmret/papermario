.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B30_9C5F10
/* 9C5F10 80240B30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C5F14 80240B34 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C5F18 80240B38 0080882D */  daddu     $s1, $a0, $zero
/* 9C5F1C 80240B3C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C5F20 80240B40 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C5F24 80240B44 8E30000C */  lw        $s0, 0xc($s1)
/* 9C5F28 80240B48 8E050000 */  lw        $a1, ($s0)
/* 9C5F2C 80240B4C 0C0B1EAF */  jal       get_variable
/* 9C5F30 80240B50 26100004 */   addiu    $s0, $s0, 4
/* 9C5F34 80240B54 0220202D */  daddu     $a0, $s1, $zero
/* 9C5F38 80240B58 8E050000 */  lw        $a1, ($s0)
/* 9C5F3C 80240B5C 0C0B1EAF */  jal       get_variable
/* 9C5F40 80240B60 0040802D */   daddu    $s0, $v0, $zero
/* 9C5F44 80240B64 44820000 */  mtc1      $v0, $f0
/* 9C5F48 80240B68 00000000 */  nop       
/* 9C5F4C 80240B6C 46800020 */  cvt.s.w   $f0, $f0
/* 9C5F50 80240B70 24020002 */  addiu     $v0, $zero, 2
/* 9C5F54 80240B74 00501804 */  sllv      $v1, $s0, $v0
/* 9C5F58 80240B78 00701821 */  addu      $v1, $v1, $s0
/* 9C5F5C 80240B7C 00431804 */  sllv      $v1, $v1, $v0
/* 9C5F60 80240B80 00701823 */  subu      $v1, $v1, $s0
/* 9C5F64 80240B84 000320C0 */  sll       $a0, $v1, 3
/* 9C5F68 80240B88 00641821 */  addu      $v1, $v1, $a0
/* 9C5F6C 80240B8C 000318C0 */  sll       $v1, $v1, 3
/* 9C5F70 80240B90 3C01800B */  lui       $at, 0x800b
/* 9C5F74 80240B94 00230821 */  addu      $at, $at, $v1
/* 9C5F78 80240B98 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 9C5F7C 80240B9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C5F80 80240BA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C5F84 80240BA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C5F88 80240BA8 03E00008 */  jr        $ra
/* 9C5F8C 80240BAC 27BD0020 */   addiu    $sp, $sp, 0x20
