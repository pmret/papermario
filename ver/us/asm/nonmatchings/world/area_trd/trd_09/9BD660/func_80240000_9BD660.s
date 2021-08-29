.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9BD660
/* 9BD660 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9BD664 80240004 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9BD668 80240008 0080982D */  daddu     $s3, $a0, $zero
/* 9BD66C 8024000C AFBF0024 */  sw        $ra, 0x24($sp)
/* 9BD670 80240010 AFB40020 */  sw        $s4, 0x20($sp)
/* 9BD674 80240014 AFB20018 */  sw        $s2, 0x18($sp)
/* 9BD678 80240018 AFB10014 */  sw        $s1, 0x14($sp)
/* 9BD67C 8024001C AFB00010 */  sw        $s0, 0x10($sp)
/* 9BD680 80240020 8E70000C */  lw        $s0, 0xc($s3)
/* 9BD684 80240024 8E720148 */  lw        $s2, 0x148($s3)
/* 9BD688 80240028 8E050000 */  lw        $a1, ($s0)
/* 9BD68C 8024002C 0C0B1EAF */  jal       get_variable
/* 9BD690 80240030 26100004 */   addiu    $s0, $s0, 4
/* 9BD694 80240034 0040882D */  daddu     $s1, $v0, $zero
/* 9BD698 80240038 8E050000 */  lw        $a1, ($s0)
/* 9BD69C 8024003C 26100004 */  addiu     $s0, $s0, 4
/* 9BD6A0 80240040 0C0B1EAF */  jal       get_variable
/* 9BD6A4 80240044 0260202D */   daddu    $a0, $s3, $zero
/* 9BD6A8 80240048 0040A02D */  daddu     $s4, $v0, $zero
/* 9BD6AC 8024004C 2402FFFF */  addiu     $v0, $zero, -1
/* 9BD6B0 80240050 16220002 */  bne       $s1, $v0, .L8024005C
/* 9BD6B4 80240054 8E100000 */   lw       $s0, ($s0)
/* 9BD6B8 80240058 86510008 */  lh        $s1, 8($s2)
.L8024005C:
/* 9BD6BC 8024005C 0C00FB3A */  jal       get_enemy
/* 9BD6C0 80240060 0220202D */   daddu    $a0, $s1, $zero
/* 9BD6C4 80240064 0040902D */  daddu     $s2, $v0, $zero
/* 9BD6C8 80240068 12400006 */  beqz      $s2, .L80240084
/* 9BD6CC 8024006C 0260202D */   daddu    $a0, $s3, $zero
/* 9BD6D0 80240070 00141080 */  sll       $v0, $s4, 2
/* 9BD6D4 80240074 02421021 */  addu      $v0, $s2, $v0
/* 9BD6D8 80240078 8C46006C */  lw        $a2, 0x6c($v0)
/* 9BD6DC 8024007C 08090023 */  j         .L8024008C
/* 9BD6E0 80240080 0200282D */   daddu    $a1, $s0, $zero
.L80240084:
/* 9BD6E4 80240084 0200282D */  daddu     $a1, $s0, $zero
/* 9BD6E8 80240088 2406FFFF */  addiu     $a2, $zero, -1
.L8024008C:
/* 9BD6EC 8024008C 0C0B2026 */  jal       evt_set_variable
/* 9BD6F0 80240090 00000000 */   nop
/* 9BD6F4 80240094 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9BD6F8 80240098 8FB40020 */  lw        $s4, 0x20($sp)
/* 9BD6FC 8024009C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9BD700 802400A0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9BD704 802400A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9BD708 802400A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9BD70C 802400AC 24020002 */  addiu     $v0, $zero, 2
/* 9BD710 802400B0 03E00008 */  jr        $ra
/* 9BD714 802400B4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9BD718 802400B8 00000000 */  nop
/* 9BD71C 802400BC 00000000 */  nop
