.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20
/* 832720 80240F20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832724 80240F24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832728 80240F28 8C82000C */  lw        $v0, 0xc($a0)
/* 83272C 80240F2C 0C0B1EAF */  jal       get_variable
/* 832730 80240F30 8C450000 */   lw       $a1, ($v0)
/* 832734 80240F34 0040202D */  daddu     $a0, $v0, $zero
/* 832738 80240F38 3C028025 */  lui       $v0, %hi(ForceCloseMessageBox)
/* 83273C 80240F3C 8C4213F0 */  lw        $v0, %lo(ForceCloseMessageBox)($v0)
/* 832740 80240F40 24030001 */  addiu     $v1, $zero, 1
/* 832744 80240F44 8C45000C */  lw        $a1, 0xc($v0)
/* 832748 80240F48 1083000D */  beq       $a0, $v1, .L80240F80
/* 83274C 80240F4C 28820002 */   slti     $v0, $a0, 2
/* 832750 80240F50 10400005 */  beqz      $v0, .L80240F68
/* 832754 80240F54 24020002 */   addiu    $v0, $zero, 2
/* 832758 80240F58 10800007 */  beqz      $a0, .L80240F78
/* 83275C 80240F5C 240200C0 */   addiu    $v0, $zero, 0xc0
/* 832760 80240F60 080903E4 */  j         .L80240F90
/* 832764 80240F64 ACA00038 */   sw       $zero, 0x38($a1)
.L80240F68:
/* 832768 80240F68 10820008 */  beq       $a0, $v0, .L80240F8C
/* 83276C 80240F6C 24020040 */   addiu    $v0, $zero, 0x40
/* 832770 80240F70 080903E4 */  j         .L80240F90
/* 832774 80240F74 ACA00038 */   sw       $zero, 0x38($a1)
.L80240F78:
/* 832778 80240F78 080903E4 */  j         .L80240F90
/* 83277C 80240F7C ACA20038 */   sw       $v0, 0x38($a1)
.L80240F80:
/* 832780 80240F80 24020080 */  addiu     $v0, $zero, 0x80
/* 832784 80240F84 080903E4 */  j         .L80240F90
/* 832788 80240F88 ACA20038 */   sw       $v0, 0x38($a1)
.L80240F8C:
/* 83278C 80240F8C ACA20038 */  sw        $v0, 0x38($a1)
.L80240F90:
/* 832790 80240F90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832794 80240F94 24020002 */  addiu     $v0, $zero, 2
/* 832798 80240F98 03E00008 */  jr        $ra
/* 83279C 80240F9C 27BD0018 */   addiu    $sp, $sp, 0x18
