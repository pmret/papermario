.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419FC_CB073C
/* CB073C 802419FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB0740 80241A00 AFBF0010 */  sw        $ra, 0x10($sp)
/* CB0744 80241A04 8C82000C */  lw        $v0, 0xc($a0)
/* CB0748 80241A08 0C0B1EAF */  jal       get_variable
/* CB074C 80241A0C 8C450000 */   lw       $a1, ($v0)
/* CB0750 80241A10 0040182D */  daddu     $v1, $v0, $zero
/* CB0754 80241A14 10600012 */  beqz      $v1, .L80241A60
/* CB0758 80241A18 0000202D */   daddu    $a0, $zero, $zero
/* CB075C 80241A1C 8C620000 */  lw        $v0, ($v1)
/* CB0760 80241A20 5040000A */  beql      $v0, $zero, .L80241A4C
/* CB0764 80241A24 00041080 */   sll      $v0, $a0, 2
/* CB0768 80241A28 3C058024 */  lui       $a1, %hi(D_802462C0_B4AA30)
/* CB076C 80241A2C 24A562C0 */  addiu     $a1, $a1, %lo(D_802462C0_B4AA30)
.L80241A30:
/* CB0770 80241A30 24630004 */  addiu     $v1, $v1, 4
/* CB0774 80241A34 24840001 */  addiu     $a0, $a0, 1
/* CB0778 80241A38 ACA20000 */  sw        $v0, ($a1)
/* CB077C 80241A3C 8C620000 */  lw        $v0, ($v1)
/* CB0780 80241A40 1440FFFB */  bnez      $v0, .L80241A30
/* CB0784 80241A44 24A50004 */   addiu    $a1, $a1, 4
/* CB0788 80241A48 00041080 */  sll       $v0, $a0, 2
.L80241A4C:
/* CB078C 80241A4C 3C018024 */  lui       $at, %hi(D_802462C0_B4AA30)
/* CB0790 80241A50 00220821 */  addu      $at, $at, $v0
/* CB0794 80241A54 AC2062C0 */  sw        $zero, %lo(D_802462C0_B4AA30)($at)
/* CB0798 80241A58 080906A2 */  j         .L80241A88
/* CB079C 80241A5C 00000000 */   nop
.L80241A60:
/* CB07A0 80241A60 3C038024 */  lui       $v1, %hi(D_802462C0_B4AA30)
/* CB07A4 80241A64 246362C0 */  addiu     $v1, $v1, %lo(D_802462C0_B4AA30)
/* CB07A8 80241A68 0060282D */  daddu     $a1, $v1, $zero
.L80241A6C:
/* CB07AC 80241A6C 24820080 */  addiu     $v0, $a0, 0x80
/* CB07B0 80241A70 AC620000 */  sw        $v0, ($v1)
/* CB07B4 80241A74 24630004 */  addiu     $v1, $v1, 4
/* CB07B8 80241A78 24840001 */  addiu     $a0, $a0, 1
/* CB07BC 80241A7C 2882005B */  slti      $v0, $a0, 0x5b
/* CB07C0 80241A80 1440FFFA */  bnez      $v0, .L80241A6C
/* CB07C4 80241A84 ACA0016C */   sw       $zero, 0x16c($a1)
.L80241A88:
/* CB07C8 80241A88 8FBF0010 */  lw        $ra, 0x10($sp)
/* CB07CC 80241A8C 24020002 */  addiu     $v0, $zero, 2
/* CB07D0 80241A90 03E00008 */  jr        $ra
/* CB07D4 80241A94 27BD0018 */   addiu    $sp, $sp, 0x18
