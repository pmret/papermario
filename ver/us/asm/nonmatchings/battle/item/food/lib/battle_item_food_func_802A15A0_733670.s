.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel battle_item_food_func_802A15A0_733670
/* 733670 802A15A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 733674 802A15A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 733678 802A15A8 0080802D */  daddu     $s0, $a0, $zero
/* 73367C 802A15AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 733680 802A15B0 8E02000C */  lw        $v0, 0xc($s0)
/* 733684 802A15B4 0C0B1EAF */  jal       get_variable
/* 733688 802A15B8 8C450000 */   lw       $a1, ($v0)
/* 73368C 802A15BC 3C038008 */  lui       $v1, %hi(gItemTable)
/* 733690 802A15C0 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* 733694 802A15C4 00021140 */  sll       $v0, $v0, 5
/* 733698 802A15C8 00431021 */  addu      $v0, $v0, $v1
/* 73369C 802A15CC 8043001B */  lb        $v1, 0x1b($v0)
/* 7336A0 802A15D0 AE0300B0 */  sw        $v1, 0xb0($s0)
/* 7336A4 802A15D4 8043001C */  lb        $v1, 0x1c($v0)
/* 7336A8 802A15D8 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 7336AC 802A15DC AE0300B4 */  sw        $v1, 0xb4($s0)
/* 7336B0 802A15E0 94420018 */  lhu       $v0, 0x18($v0)
/* 7336B4 802A15E4 30420100 */  andi      $v0, $v0, 0x100
/* 7336B8 802A15E8 10400002 */  beqz      $v0, .L802A15F4
/* 7336BC 802A15EC 24020001 */   addiu    $v0, $zero, 1
/* 7336C0 802A15F0 AE0200B8 */  sw        $v0, 0xb8($s0)
.L802A15F4:
/* 7336C4 802A15F4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 7336C8 802A15F8 04400006 */  bltz      $v0, .L802A1614
/* 7336CC 802A15FC 0000182D */   daddu    $v1, $zero, $zero
/* 7336D0 802A1600 5C400006 */  bgtzl     $v0, .L802A161C
/* 7336D4 802A1604 AE0300C0 */   sw       $v1, 0xc0($s0)
/* 7336D8 802A1608 8E0200B4 */  lw        $v0, 0xb4($s0)
/* 7336DC 802A160C 04430003 */  bgezl     $v0, .L802A161C
/* 7336E0 802A1610 AE0300C0 */   sw       $v1, 0xc0($s0)
.L802A1614:
/* 7336E4 802A1614 24030001 */  addiu     $v1, $zero, 1
/* 7336E8 802A1618 AE0300C0 */  sw        $v1, 0xc0($s0)
.L802A161C:
/* 7336EC 802A161C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7336F0 802A1620 8FB00010 */  lw        $s0, 0x10($sp)
/* 7336F4 802A1624 24020002 */  addiu     $v0, $zero, 2
/* 7336F8 802A1628 03E00008 */  jr        $ra
/* 7336FC 802A162C 27BD0018 */   addiu    $sp, $sp, 0x18
