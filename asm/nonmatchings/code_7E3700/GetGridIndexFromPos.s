.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetGridIndexFromPos
/* 7E4538 802836B8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 7E453C 802836BC AFB3001C */  sw    $s3, 0x1c($sp)
/* 7E4540 802836C0 0080982D */  daddu $s3, $a0, $zero
/* 7E4544 802836C4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 7E4548 802836C8 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E454C 802836CC AFB10014 */  sw    $s1, 0x14($sp)
/* 7E4550 802836D0 AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4554 802836D4 8E70000C */  lw    $s0, 0xc($s3)
/* 7E4558 802836D8 8E050000 */  lw    $a1, ($s0)
/* 7E455C 802836DC 0C0B1EAF */  jal   get_variable
/* 7E4560 802836E0 26100004 */   addiu $s0, $s0, 4
/* 7E4564 802836E4 8E050000 */  lw    $a1, ($s0)
/* 7E4568 802836E8 26100004 */  addiu $s0, $s0, 4
/* 7E456C 802836EC 0260202D */  daddu $a0, $s3, $zero
/* 7E4570 802836F0 0C0B1EAF */  jal   get_variable
/* 7E4574 802836F4 0040882D */   daddu $s1, $v0, $zero
/* 7E4578 802836F8 0040902D */  daddu $s2, $v0, $zero
/* 7E457C 802836FC 8E050000 */  lw    $a1, ($s0)
/* 7E4580 80283700 26100004 */  addiu $s0, $s0, 4
/* 7E4584 80283704 0C0B1EAF */  jal   get_variable
/* 7E4588 80283708 0260202D */   daddu $a0, $s3, $zero
/* 7E458C 8028370C 8E050000 */  lw    $a1, ($s0)
/* 7E4590 80283710 0C0B1EAF */  jal   get_variable
/* 7E4594 80283714 0260202D */   daddu $a0, $s3, $zero
/* 7E4598 80283718 00118880 */  sll   $s1, $s1, 2
/* 7E459C 8028371C 3C04802E */  lui   $a0, 0x802e
/* 7E45A0 80283720 00912021 */  addu  $a0, $a0, $s1
/* 7E45A4 80283724 8C84BC88 */  lw    $a0, -0x4378($a0)
/* 7E45A8 80283728 3C0651EB */  lui   $a2, 0x51eb
/* 7E45AC 8028372C 8C830008 */  lw    $v1, 8($a0)
/* 7E45B0 80283730 34C6851F */  ori   $a2, $a2, 0x851f
/* 7E45B4 80283734 02439023 */  subu  $s2, $s2, $v1
/* 7E45B8 80283738 02460018 */  mult  $s2, $a2
/* 7E45BC 8028373C 26100004 */  addiu $s0, $s0, 4
/* 7E45C0 80283740 8E050000 */  lw    $a1, ($s0)
/* 7E45C4 80283744 8E100004 */  lw    $s0, 4($s0)
/* 7E45C8 80283748 8C830010 */  lw    $v1, 0x10($a0)
/* 7E45CC 8028374C 00003810 */  mfhi  $a3
/* 7E45D0 80283750 0260202D */  daddu $a0, $s3, $zero
/* 7E45D4 80283754 00431023 */  subu  $v0, $v0, $v1
/* 7E45D8 80283758 00460018 */  mult  $v0, $a2
/* 7E45DC 8028375C 001297C3 */  sra   $s2, $s2, 0x1f
/* 7E45E0 80283760 000730C3 */  sra   $a2, $a3, 3
/* 7E45E4 80283764 00D23023 */  subu  $a2, $a2, $s2
/* 7E45E8 80283768 000217C3 */  sra   $v0, $v0, 0x1f
/* 7E45EC 8028376C 00001810 */  mfhi  $v1
/* 7E45F0 80283770 000388C3 */  sra   $s1, $v1, 3
/* 7E45F4 80283774 0C0B2026 */  jal   set_variable
/* 7E45F8 80283778 02228823 */   subu  $s1, $s1, $v0
/* 7E45FC 8028377C 0260202D */  daddu $a0, $s3, $zero
/* 7E4600 80283780 0200282D */  daddu $a1, $s0, $zero
/* 7E4604 80283784 0C0B2026 */  jal   set_variable
/* 7E4608 80283788 0220302D */   daddu $a2, $s1, $zero
/* 7E460C 8028378C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 7E4610 80283790 8FB3001C */  lw    $s3, 0x1c($sp)
/* 7E4614 80283794 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E4618 80283798 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E461C 8028379C 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E4620 802837A0 24020002 */  addiu $v0, $zero, 2
/* 7E4624 802837A4 03E00008 */  jr    $ra
/* 7E4628 802837A8 27BD0028 */   addiu $sp, $sp, 0x28

