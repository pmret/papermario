.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A64_B36634
/* B36634 80241A64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36638 80241A68 AFBF0010 */  sw        $ra, 0x10($sp)
/* B3663C 80241A6C 8C82000C */  lw        $v0, 0xc($a0)
/* B36640 80241A70 0C0B1EAF */  jal       evt_get_variable
/* B36644 80241A74 8C450000 */   lw       $a1, ($v0)
/* B36648 80241A78 0040182D */  daddu     $v1, $v0, $zero
/* B3664C 80241A7C 10600012 */  beqz      $v1, .L80241AC8
/* B36650 80241A80 0000202D */   daddu    $a0, $zero, $zero
/* B36654 80241A84 8C620000 */  lw        $v0, ($v1)
/* B36658 80241A88 5040000A */  beql      $v0, $zero, .L80241AB4
/* B3665C 80241A8C 00041080 */   sll      $v0, $a0, 2
/* B36660 80241A90 3C058025 */  lui       $a1, %hi(D_8024FBA0)
/* B36664 80241A94 24A5FBA0 */  addiu     $a1, $a1, %lo(D_8024FBA0)
.L80241A98:
/* B36668 80241A98 24630004 */  addiu     $v1, $v1, 4
/* B3666C 80241A9C 24840001 */  addiu     $a0, $a0, 1
/* B36670 80241AA0 ACA20000 */  sw        $v0, ($a1)
/* B36674 80241AA4 8C620000 */  lw        $v0, ($v1)
/* B36678 80241AA8 1440FFFB */  bnez      $v0, .L80241A98
/* B3667C 80241AAC 24A50004 */   addiu    $a1, $a1, 4
/* B36680 80241AB0 00041080 */  sll       $v0, $a0, 2
.L80241AB4:
/* B36684 80241AB4 3C018025 */  lui       $at, %hi(D_8024FBA0)
/* B36688 80241AB8 00220821 */  addu      $at, $at, $v0
/* B3668C 80241ABC AC20FBA0 */  sw        $zero, %lo(D_8024FBA0)($at)
/* B36690 80241AC0 080906BC */  j         .L80241AF0
/* B36694 80241AC4 00000000 */   nop
.L80241AC8:
/* B36698 80241AC8 3C038025 */  lui       $v1, %hi(D_8024FBA0)
/* B3669C 80241ACC 2463FBA0 */  addiu     $v1, $v1, %lo(D_8024FBA0)
/* B366A0 80241AD0 0060282D */  daddu     $a1, $v1, $zero
.L80241AD4:
/* B366A4 80241AD4 24820010 */  addiu     $v0, $a0, 0x10
/* B366A8 80241AD8 AC620000 */  sw        $v0, ($v1)
/* B366AC 80241ADC 24630004 */  addiu     $v1, $v1, 4
/* B366B0 80241AE0 24840001 */  addiu     $a0, $a0, 1
/* B366B4 80241AE4 28820070 */  slti      $v0, $a0, 0x70
/* B366B8 80241AE8 1440FFFA */  bnez      $v0, .L80241AD4
/* B366BC 80241AEC ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241AF0:
/* B366C0 80241AF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* B366C4 80241AF4 24020002 */  addiu     $v0, $zero, 2
/* B366C8 80241AF8 03E00008 */  jr        $ra
/* B366CC 80241AFC 27BD0018 */   addiu    $sp, $sp, 0x18
