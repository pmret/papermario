.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240604_AF7F54
/* AF7F54 80240604 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7F58 80240608 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF7F5C 8024060C 8C82000C */  lw        $v0, 0xc($a0)
/* AF7F60 80240610 0C0B1EAF */  jal       get_variable
/* AF7F64 80240614 8C450000 */   lw       $a1, ($v0)
/* AF7F68 80240618 0040182D */  daddu     $v1, $v0, $zero
/* AF7F6C 8024061C 10600012 */  beqz      $v1, .L80240668
/* AF7F70 80240620 0000202D */   daddu    $a0, $zero, $zero
/* AF7F74 80240624 8C620000 */  lw        $v0, ($v1)
/* AF7F78 80240628 5040000A */  beql      $v0, $zero, .L80240654
/* AF7F7C 8024062C 00041080 */   sll      $v0, $a0, 2
/* AF7F80 80240630 3C058024 */  lui       $a1, %hi(D_802463B8)
/* AF7F84 80240634 24A563B8 */  addiu     $a1, $a1, %lo(D_802463B8)
.L80240638:
/* AF7F88 80240638 24630004 */  addiu     $v1, $v1, 4
/* AF7F8C 8024063C 24840001 */  addiu     $a0, $a0, 1
/* AF7F90 80240640 ACA20000 */  sw        $v0, ($a1)
/* AF7F94 80240644 8C620000 */  lw        $v0, ($v1)
/* AF7F98 80240648 1440FFFB */  bnez      $v0, .L80240638
/* AF7F9C 8024064C 24A50004 */   addiu    $a1, $a1, 4
/* AF7FA0 80240650 00041080 */  sll       $v0, $a0, 2
.L80240654:
/* AF7FA4 80240654 3C018024 */  lui       $at, %hi(D_802463B8)
/* AF7FA8 80240658 00220821 */  addu      $at, $at, $v0
/* AF7FAC 8024065C AC2063B8 */  sw        $zero, %lo(D_802463B8)($at)
/* AF7FB0 80240660 080901A4 */  j         .L80240690
/* AF7FB4 80240664 00000000 */   nop      
.L80240668:
/* AF7FB8 80240668 3C038024 */  lui       $v1, %hi(D_802463B8)
/* AF7FBC 8024066C 246363B8 */  addiu     $v1, $v1, %lo(D_802463B8)
/* AF7FC0 80240670 0060282D */  daddu     $a1, $v1, $zero
.L80240674:
/* AF7FC4 80240674 24820080 */  addiu     $v0, $a0, 0x80
/* AF7FC8 80240678 AC620000 */  sw        $v0, ($v1)
/* AF7FCC 8024067C 24630004 */  addiu     $v1, $v1, 4
/* AF7FD0 80240680 24840001 */  addiu     $a0, $a0, 1
/* AF7FD4 80240684 2882005B */  slti      $v0, $a0, 0x5b
/* AF7FD8 80240688 1440FFFA */  bnez      $v0, .L80240674
/* AF7FDC 8024068C ACA0016C */   sw       $zero, 0x16c($a1)
.L80240690:
/* AF7FE0 80240690 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF7FE4 80240694 24020002 */  addiu     $v0, $zero, 2
/* AF7FE8 80240698 03E00008 */  jr        $ra
/* AF7FEC 8024069C 27BD0018 */   addiu    $sp, $sp, 0x18
