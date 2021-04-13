.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_windows_visible
/* DE5C4 80147EC4 3C068016 */  lui       $a2, %hi(gUIPanels)
/* DE5C8 80147EC8 24C69D50 */  addiu     $a2, $a2, %lo(gUIPanels)
/* DE5CC 80147ECC 0000282D */  daddu     $a1, $zero, $zero
/* DE5D0 80147ED0 3C028015 */  lui       $v0, %hi(D_8014F2C0)
/* DE5D4 80147ED4 2442F2C0 */  addiu     $v0, $v0, %lo(D_8014F2C0)
/* DE5D8 80147ED8 00042040 */  sll       $a0, $a0, 1
/* DE5DC 80147EDC 00822021 */  addu      $a0, $a0, $v0
/* DE5E0 80147EE0 90870000 */  lbu       $a3, ($a0)
/* DE5E4 80147EE4 90840001 */  lbu       $a0, 1($a0)
.L80147EE8:
/* DE5E8 80147EE8 90C30000 */  lbu       $v1, ($a2)
/* DE5EC 80147EEC 30620001 */  andi      $v0, $v1, 1
/* DE5F0 80147EF0 5040000A */  beql      $v0, $zero, .L80147F1C
/* DE5F4 80147EF4 24A50001 */   addiu    $a1, $a1, 1
/* DE5F8 80147EF8 00A7102A */  slt       $v0, $a1, $a3
/* DE5FC 80147EFC 14400005 */  bnez      $v0, .L80147F14
/* DE600 80147F00 34620020 */   ori      $v0, $v1, 0x20
/* DE604 80147F04 0085102A */  slt       $v0, $a0, $a1
/* DE608 80147F08 14400002 */  bnez      $v0, .L80147F14
/* DE60C 80147F0C 34620020 */   ori      $v0, $v1, 0x20
/* DE610 80147F10 306200DF */  andi      $v0, $v1, 0xdf
.L80147F14:
/* DE614 80147F14 A0C20000 */  sb        $v0, ($a2)
/* DE618 80147F18 24A50001 */  addiu     $a1, $a1, 1
.L80147F1C:
/* DE61C 80147F1C 28A20040 */  slti      $v0, $a1, 0x40
/* DE620 80147F20 1440FFF1 */  bnez      $v0, .L80147EE8
/* DE624 80147F24 24C60020 */   addiu    $a2, $a2, 0x20
/* DE628 80147F28 03E00008 */  jr        $ra
/* DE62C 80147F2C 00000000 */   nop
