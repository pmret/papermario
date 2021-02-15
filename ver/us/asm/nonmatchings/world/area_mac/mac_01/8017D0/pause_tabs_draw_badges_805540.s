.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_badges_805540
/* 805540 80244CC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805544 80244CC4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 805548 80244CC8 0000202D */  daddu     $a0, $zero, $zero
/* 80554C 80244CCC 3C05F840 */  lui       $a1, 0xf840
/* 805550 80244CD0 0C0B1EAF */  jal       get_variable
/* 805554 80244CD4 34A55C84 */   ori      $a1, $a1, 0x5c84
/* 805558 80244CD8 14400008 */  bnez      $v0, .L80244CFC
/* 80555C 80244CDC 0000202D */   daddu    $a0, $zero, $zero
/* 805560 80244CE0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 805564 80244CE4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 805568 80244CE8 8C420140 */  lw        $v0, 0x140($v0)
/* 80556C 80244CEC 8C440000 */  lw        $a0, ($v0)
/* 805570 80244CF0 0C04D062 */  jal       clear_item_entity_flags
/* 805574 80244CF4 24050040 */   addiu    $a1, $zero, 0x40
/* 805578 80244CF8 0000202D */  daddu     $a0, $zero, $zero
.L80244CFC:
/* 80557C 80244CFC 3C05F840 */  lui       $a1, 0xf840
/* 805580 80244D00 0C0B1EAF */  jal       get_variable
/* 805584 80244D04 34A55C85 */   ori      $a1, $a1, 0x5c85
/* 805588 80244D08 14400008 */  bnez      $v0, .L80244D2C
/* 80558C 80244D0C 0000202D */   daddu    $a0, $zero, $zero
/* 805590 80244D10 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 805594 80244D14 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 805598 80244D18 8C420140 */  lw        $v0, 0x140($v0)
/* 80559C 80244D1C 8C440010 */  lw        $a0, 0x10($v0)
/* 8055A0 80244D20 0C04D062 */  jal       clear_item_entity_flags
/* 8055A4 80244D24 24050040 */   addiu    $a1, $zero, 0x40
/* 8055A8 80244D28 0000202D */  daddu     $a0, $zero, $zero
.L80244D2C:
/* 8055AC 80244D2C 3C05F840 */  lui       $a1, 0xf840
/* 8055B0 80244D30 0C0B1EAF */  jal       get_variable
/* 8055B4 80244D34 34A55C86 */   ori      $a1, $a1, 0x5c86
/* 8055B8 80244D38 14400007 */  bnez      $v0, .L80244D58
/* 8055BC 80244D3C 00000000 */   nop
/* 8055C0 80244D40 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8055C4 80244D44 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8055C8 80244D48 8C420140 */  lw        $v0, 0x140($v0)
/* 8055CC 80244D4C 8C440020 */  lw        $a0, 0x20($v0)
/* 8055D0 80244D50 0C04D062 */  jal       clear_item_entity_flags
/* 8055D4 80244D54 24050040 */   addiu    $a1, $zero, 0x40
.L80244D58:
/* 8055D8 80244D58 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8055DC 80244D5C 24020002 */  addiu     $v0, $zero, 2
/* 8055E0 80244D60 03E00008 */  jr        $ra
/* 8055E4 80244D64 27BD0018 */   addiu    $sp, $sp, 0x18
