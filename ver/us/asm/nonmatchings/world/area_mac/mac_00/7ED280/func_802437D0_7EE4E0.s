.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802437D0_7EE4E0
/* 7EE4E0 802437D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE4E4 802437D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EE4E8 802437D8 8C82000C */  lw        $v0, 0xc($a0)
/* 7EE4EC 802437DC 0C0B1EAF */  jal       evt_get_variable
/* 7EE4F0 802437E0 8C450000 */   lw       $a1, ($v0)
/* 7EE4F4 802437E4 0040182D */  daddu     $v1, $v0, $zero
/* 7EE4F8 802437E8 10600012 */  beqz      $v1, .L80243834
/* 7EE4FC 802437EC 0000202D */   daddu    $a0, $zero, $zero
/* 7EE500 802437F0 8C620000 */  lw        $v0, ($v1)
/* 7EE504 802437F4 5040000A */  beql      $v0, $zero, .L80243820
/* 7EE508 802437F8 00041080 */   sll      $v0, $a0, 2
/* 7EE50C 802437FC 3C058025 */  lui       $a1, %hi(D_80255EE0)
/* 7EE510 80243800 24A55EE0 */  addiu     $a1, $a1, %lo(D_80255EE0)
.L80243804:
/* 7EE514 80243804 24630004 */  addiu     $v1, $v1, 4
/* 7EE518 80243808 24840001 */  addiu     $a0, $a0, 1
/* 7EE51C 8024380C ACA20000 */  sw        $v0, ($a1)
/* 7EE520 80243810 8C620000 */  lw        $v0, ($v1)
/* 7EE524 80243814 1440FFFB */  bnez      $v0, .L80243804
/* 7EE528 80243818 24A50004 */   addiu    $a1, $a1, 4
/* 7EE52C 8024381C 00041080 */  sll       $v0, $a0, 2
.L80243820:
/* 7EE530 80243820 3C018025 */  lui       $at, %hi(D_80255EE0)
/* 7EE534 80243824 00220821 */  addu      $at, $at, $v0
/* 7EE538 80243828 AC205EE0 */  sw        $zero, %lo(D_80255EE0)($at)
/* 7EE53C 8024382C 08090E17 */  j         .L8024385C
/* 7EE540 80243830 00000000 */   nop
.L80243834:
/* 7EE544 80243834 3C038025 */  lui       $v1, %hi(D_80255EE0)
/* 7EE548 80243838 24635EE0 */  addiu     $v1, $v1, %lo(D_80255EE0)
/* 7EE54C 8024383C 0060282D */  daddu     $a1, $v1, $zero
.L80243840:
/* 7EE550 80243840 24820010 */  addiu     $v0, $a0, 0x10
/* 7EE554 80243844 AC620000 */  sw        $v0, ($v1)
/* 7EE558 80243848 24630004 */  addiu     $v1, $v1, 4
/* 7EE55C 8024384C 24840001 */  addiu     $a0, $a0, 1
/* 7EE560 80243850 28820070 */  slti      $v0, $a0, 0x70
/* 7EE564 80243854 1440FFFA */  bnez      $v0, .L80243840
/* 7EE568 80243858 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L8024385C:
/* 7EE56C 8024385C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EE570 80243860 24020002 */  addiu     $v0, $zero, 2
/* 7EE574 80243864 03E00008 */  jr        $ra
/* 7EE578 80243868 27BD0018 */   addiu    $sp, $sp, 0x18
