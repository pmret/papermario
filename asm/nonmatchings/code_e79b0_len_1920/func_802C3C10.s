.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802C3C10
/* 0E85C0 802C3C10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E85C4 802C3C14 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E85C8 802C3C18 0080882D */  daddu $s1, $a0, $zero
/* 0E85CC 802C3C1C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E85D0 802C3C20 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E85D4 802C3C24 92220000 */  lbu   $v0, ($s1)
/* 0E85D8 802C3C28 3C013F80 */  lui   $at, 0x3f80
/* 0E85DC 802C3C2C 44810000 */  mtc1  $at, $f0
/* 0E85E0 802C3C30 8E240060 */  lw    $a0, 0x60($s1)
/* 0E85E4 802C3C34 AE250008 */  sw    $a1, 8($s1)
/* 0E85E8 802C3C38 AE25015C */  sw    $a1, 0x15c($s1)
/* 0E85EC 802C3C3C AE250164 */  sw    $a1, 0x164($s1)
/* 0E85F0 802C3C40 A2200002 */  sb    $zero, 2($s1)
/* 0E85F4 802C3C44 AE200154 */  sw    $zero, 0x154($s1)
/* 0E85F8 802C3C48 00461025 */  or    $v0, $v0, $a2
/* 0E85FC 802C3C4C A2220000 */  sb    $v0, ($s1)
/* 0E8600 802C3C50 10800004 */  beqz  $a0, .L802C3C64
/* 0E8604 802C3C54 E6200150 */   swc1  $f0, 0x150($s1)
/* 0E8608 802C3C58 0C00AB4B */  jal   heap_free
/* 0E860C 802C3C5C 00000000 */   nop   
/* 0E8610 802C3C60 AE200060 */  sw    $zero, 0x60($s1)
.L802C3C64:
/* 0E8614 802C3C64 8E240068 */  lw    $a0, 0x68($s1)
/* 0E8618 802C3C68 10800003 */  beqz  $a0, .L802C3C78
/* 0E861C 802C3C6C 0000802D */   daddu $s0, $zero, $zero
/* 0E8620 802C3C70 0C0B0FCF */  jal   kill_script
/* 0E8624 802C3C74 00000000 */   nop   
.L802C3C78:
/* 0E8628 802C3C78 3C03802E */  lui   $v1, 0x802e
/* 0E862C 802C3C7C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8630 802C3C80 00101080 */  sll   $v0, $s0, 2
/* 0E8634 802C3C84 00431021 */  addu  $v0, $v0, $v1
/* 0E8638 802C3C88 8C440000 */  lw    $a0, ($v0)
/* 0E863C 802C3C8C 10800006 */  beqz  $a0, .L802C3CA8
/* 0E8640 802C3C90 26100001 */   addiu $s0, $s0, 1
/* 0E8644 802C3C94 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E8648 802C3C98 14510003 */  bne   $v0, $s1, .L802C3CA8
/* 0E864C 802C3C9C 00000000 */   nop   
/* 0E8650 802C3CA0 0C0B0FCF */  jal   kill_script
/* 0E8654 802C3CA4 00000000 */   nop   
.L802C3CA8:
/* 0E8658 802C3CA8 2A020080 */  slti  $v0, $s0, 0x80
/* 0E865C 802C3CAC 1440FFF2 */  bnez  $v0, .L802C3C78
/* 0E8660 802C3CB0 2402FFFF */   addiu $v0, $zero, -1
/* 0E8664 802C3CB4 A2220006 */  sb    $v0, 6($s1)
/* 0E8668 802C3CB8 A2220007 */  sb    $v0, 7($s1)
/* 0E866C 802C3CBC 3C01802E */  lui   $at, 0x802e
/* 0E8670 802C3CC0 C4209CA8 */  lwc1  $f0, -0x6358($at)
/* 0E8674 802C3CC4 0220202D */  daddu $a0, $s1, $zero
/* 0E8678 802C3CC8 AE200064 */  sw    $zero, 0x64($s1)
/* 0E867C 802C3CCC AE20006C */  sw    $zero, 0x6c($s1)
/* 0E8680 802C3CD0 AE200068 */  sw    $zero, 0x68($s1)
/* 0E8684 802C3CD4 AE200154 */  sw    $zero, 0x154($s1)
/* 0E8688 802C3CD8 AE200158 */  sw    $zero, 0x158($s1)
/* 0E868C 802C3CDC 0C0B0C52 */  jal   find_script_labels
/* 0E8690 802C3CE0 E6200150 */   swc1  $f0, 0x150($s1)
/* 0E8694 802C3CE4 0C0B0CE4 */  jal   func_802C3390
/* 0E8698 802C3CE8 0220202D */   daddu $a0, $s1, $zero
/* 0E869C 802C3CEC 0220102D */  daddu $v0, $s1, $zero
/* 0E86A0 802C3CF0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E86A4 802C3CF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E86A8 802C3CF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E86AC 802C3CFC 03E00008 */  jr    $ra
/* 0E86B0 802C3D00 27BD0020 */   addiu $sp, $sp, 0x20