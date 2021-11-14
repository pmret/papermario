.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_121_appendGfx
/* 3EBA38 E010E558 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3EBA3C E010E55C 3C07DB06 */  lui       $a3, 0xdb06
/* 3EBA40 E010E560 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 3EBA44 E010E564 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 3EBA48 E010E568 34E70024 */  ori       $a3, $a3, 0x24
/* 3EBA4C E010E56C AFBF0024 */  sw        $ra, 0x24($sp)
/* 3EBA50 E010E570 AFB20020 */  sw        $s2, 0x20($sp)
/* 3EBA54 E010E574 AFB1001C */  sw        $s1, 0x1c($sp)
/* 3EBA58 E010E578 AFB00018 */  sw        $s0, 0x18($sp)
/* 3EBA5C E010E57C 8CC50000 */  lw        $a1, ($a2)
/* 3EBA60 E010E580 8C90000C */  lw        $s0, 0xc($a0)
/* 3EBA64 E010E584 00A0182D */  daddu     $v1, $a1, $zero
/* 3EBA68 E010E588 24A50008 */  addiu     $a1, $a1, 8
/* 3EBA6C E010E58C ACC50000 */  sw        $a1, ($a2)
/* 3EBA70 E010E590 8E0B002C */  lw        $t3, 0x2c($s0)
/* 3EBA74 E010E594 8E080000 */  lw        $t0, ($s0)
/* 3EBA78 E010E598 3C02E700 */  lui       $v0, 0xe700
/* 3EBA7C E010E59C AC620000 */  sw        $v0, ($v1)
/* 3EBA80 E010E5A0 AC600004 */  sw        $zero, 4($v1)
/* 3EBA84 E010E5A4 ACA70000 */  sw        $a3, ($a1)
/* 3EBA88 E010E5A8 8C830010 */  lw        $v1, 0x10($a0)
/* 3EBA8C E010E5AC 24A20008 */  addiu     $v0, $a1, 8
/* 3EBA90 E010E5B0 ACC20000 */  sw        $v0, ($a2)
/* 3EBA94 E010E5B4 8C62001C */  lw        $v0, 0x1c($v1)
/* 3EBA98 E010E5B8 3C038000 */  lui       $v1, 0x8000
/* 3EBA9C E010E5BC 00431021 */  addu      $v0, $v0, $v1
/* 3EBAA0 E010E5C0 ACA20004 */  sw        $v0, 4($a1)
/* 3EBAA4 E010E5C4 2D020013 */  sltiu     $v0, $t0, 0x13
/* 3EBAA8 E010E5C8 1040001A */  beqz      $v0, .LE010E634
/* 3EBAAC E010E5CC 00081080 */   sll      $v0, $t0, 2
/* 3EBAB0 E010E5D0 3C01E011 */  lui       $at, %hi(jtbl_E010E930)
/* 3EBAB4 E010E5D4 00220821 */  addu      $at, $at, $v0
/* 3EBAB8 E010E5D8 8C22E930 */  lw        $v0, %lo(jtbl_E010E930)($at)
/* 3EBABC E010E5DC 00400008 */  jr        $v0
/* 3EBAC0 E010E5E0 00000000 */   nop
dlabel LE010E5E4_3EBAC4
/* 3EBAC4 E010E5E4 3C06E011 */  lui       $a2, %hi(D_E010E7FC)
/* 3EBAC8 E010E5E8 24C6E7FC */  addiu     $a2, $a2, %lo(D_E010E7FC)
/* 3EBACC E010E5EC 3C04E011 */  lui       $a0, %hi(D_E010E868)
/* 3EBAD0 E010E5F0 2484E868 */  addiu     $a0, $a0, %lo(D_E010E868)
/* 3EBAD4 E010E5F4 2503FFFF */  addiu     $v1, $t0, -1
/* 3EBAD8 E010E5F8 00031040 */  sll       $v0, $v1, 1
/* 3EBADC E010E5FC 00431021 */  addu      $v0, $v0, $v1
/* 3EBAE0 E010E600 000210C0 */  sll       $v0, $v0, 3
/* 3EBAE4 E010E604 0804398F */  j         .LE010E63C
/* 3EBAE8 E010E608 00448821 */   addu     $s1, $v0, $a0
dlabel LE010E60C_3EBAEC
/* 3EBAEC E010E60C 3C06E011 */  lui       $a2, %hi(D_E010E7D8)
/* 3EBAF0 E010E610 24C6E7D8 */  addiu     $a2, $a2, %lo(D_E010E7D8)
/* 3EBAF4 E010E614 0804398F */  j         .LE010E63C
/* 3EBAF8 E010E618 0000882D */   daddu    $s1, $zero, $zero
dlabel LE010E61C_3EBAFC
/* 3EBAFC E010E61C 3C06E011 */  lui       $a2, %hi(D_E010E79C)
/* 3EBB00 E010E620 24C6E79C */  addiu     $a2, $a2, %lo(D_E010E79C)
/* 3EBB04 E010E624 3C11E011 */  lui       $s1, %hi(D_E010E838)
/* 3EBB08 E010E628 2631E838 */  addiu     $s1, $s1, %lo(D_E010E838)
/* 3EBB0C E010E62C 08043990 */  j         .LE010E640
/* 3EBB10 E010E630 0200202D */   daddu    $a0, $s0, $zero
.LE010E634:
/* 3EBB14 E010E634 0000882D */  daddu     $s1, $zero, $zero
/* 3EBB18 E010E638 0220302D */  daddu     $a2, $s1, $zero
.LE010E63C:
/* 3EBB1C E010E63C 0200202D */  daddu     $a0, $s0, $zero
.LE010E640:
/* 3EBB20 E010E640 0000282D */  daddu     $a1, $zero, $zero
/* 3EBB24 E010E644 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 3EBB28 E010E648 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 3EBB2C E010E64C 8E490000 */  lw        $t1, ($s2)
/* 3EBB30 E010E650 3C02FA00 */  lui       $v0, 0xfa00
/* 3EBB34 E010E654 0120502D */  daddu     $t2, $t1, $zero
/* 3EBB38 E010E658 25290008 */  addiu     $t1, $t1, 8
/* 3EBB3C E010E65C AE490000 */  sw        $t1, ($s2)
/* 3EBB40 E010E660 AD420000 */  sw        $v0, ($t2)
/* 3EBB44 E010E664 92020023 */  lbu       $v0, 0x23($s0)
/* 3EBB48 E010E668 92070027 */  lbu       $a3, 0x27($s0)
/* 3EBB4C E010E66C 9208002B */  lbu       $t0, 0x2b($s0)
/* 3EBB50 E010E670 25230008 */  addiu     $v1, $t1, 8
/* 3EBB54 E010E674 AE430000 */  sw        $v1, ($s2)
/* 3EBB58 E010E678 316300FF */  andi      $v1, $t3, 0xff
/* 3EBB5C E010E67C 00021600 */  sll       $v0, $v0, 0x18
/* 3EBB60 E010E680 00073C00 */  sll       $a3, $a3, 0x10
/* 3EBB64 E010E684 00471025 */  or        $v0, $v0, $a3
/* 3EBB68 E010E688 00084200 */  sll       $t0, $t0, 8
/* 3EBB6C E010E68C 00481025 */  or        $v0, $v0, $t0
/* 3EBB70 E010E690 00431025 */  or        $v0, $v0, $v1
/* 3EBB74 E010E694 AD420004 */  sw        $v0, 4($t2)
/* 3EBB78 E010E698 3C02FB00 */  lui       $v0, 0xfb00
/* 3EBB7C E010E69C AD220000 */  sw        $v0, ($t1)
/* 3EBB80 E010E6A0 92020033 */  lbu       $v0, 0x33($s0)
/* 3EBB84 E010E6A4 92030037 */  lbu       $v1, 0x37($s0)
/* 3EBB88 E010E6A8 9207003B */  lbu       $a3, 0x3b($s0)
/* 3EBB8C E010E6AC 00021600 */  sll       $v0, $v0, 0x18
/* 3EBB90 E010E6B0 00031C00 */  sll       $v1, $v1, 0x10
/* 3EBB94 E010E6B4 00431025 */  or        $v0, $v0, $v1
/* 3EBB98 E010E6B8 00073A00 */  sll       $a3, $a3, 8
/* 3EBB9C E010E6BC 9203003F */  lbu       $v1, 0x3f($s0)
/* 3EBBA0 E010E6C0 00471025 */  or        $v0, $v0, $a3
/* 3EBBA4 E010E6C4 00431025 */  or        $v0, $v0, $v1
/* 3EBBA8 E010E6C8 0C043800 */  jal       func_E010E000
/* 3EBBAC E010E6CC AD220004 */   sw       $v0, 4($t1)
/* 3EBBB0 E010E6D0 0200202D */  daddu     $a0, $s0, $zero
/* 3EBBB4 E010E6D4 24050001 */  addiu     $a1, $zero, 1
/* 3EBBB8 E010E6D8 0C043800 */  jal       func_E010E000
/* 3EBBBC E010E6DC 0220302D */   daddu    $a2, $s1, $zero
/* 3EBBC0 E010E6E0 8E020054 */  lw        $v0, 0x54($s0)
/* 3EBBC4 E010E6E4 0440000A */  bltz      $v0, .LE010E710
/* 3EBBC8 E010E6E8 24020015 */   addiu    $v0, $zero, 0x15
/* 3EBBCC E010E6EC 8E030040 */  lw        $v1, 0x40($s0)
/* 3EBBD0 E010E6F0 8E050048 */  lw        $a1, 0x48($s0)
/* 3EBBD4 E010E6F4 240700FF */  addiu     $a3, $zero, 0xff
/* 3EBBD8 E010E6F8 AFA20010 */  sw        $v0, 0x10($sp)
/* 3EBBDC E010E6FC AFA00014 */  sw        $zero, 0x14($sp)
/* 3EBBE0 E010E700 8E040054 */  lw        $a0, 0x54($s0)
/* 3EBBE4 E010E704 8E060044 */  lw        $a2, 0x44($s0)
/* 3EBBE8 E010E708 0C080194 */  jal       shim_draw_msg
/* 3EBBEC E010E70C 00652823 */   subu     $a1, $v1, $a1
.LE010E710:
/* 3EBBF0 E010E710 8E420000 */  lw        $v0, ($s2)
/* 3EBBF4 E010E714 0040182D */  daddu     $v1, $v0, $zero
/* 3EBBF8 E010E718 24420008 */  addiu     $v0, $v0, 8
/* 3EBBFC E010E71C AE420000 */  sw        $v0, ($s2)
/* 3EBC00 E010E720 3C02E700 */  lui       $v0, 0xe700
/* 3EBC04 E010E724 AC620000 */  sw        $v0, ($v1)
/* 3EBC08 E010E728 AC600004 */  sw        $zero, 4($v1)
/* 3EBC0C E010E72C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3EBC10 E010E730 8FB20020 */  lw        $s2, 0x20($sp)
/* 3EBC14 E010E734 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3EBC18 E010E738 8FB00018 */  lw        $s0, 0x18($sp)
/* 3EBC1C E010E73C 03E00008 */  jr        $ra
/* 3EBC20 E010E740 27BD0028 */   addiu    $sp, $sp, 0x28
/* 3EBC24 E010E744 00000000 */  nop
/* 3EBC28 E010E748 00000000 */  nop
/* 3EBC2C E010E74C 00000000 */  nop
