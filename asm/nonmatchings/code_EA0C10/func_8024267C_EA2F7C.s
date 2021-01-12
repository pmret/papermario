.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024267C_EA2F7C
/* EA2F7C 8024267C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA2F80 80242680 AFB00010 */  sw        $s0, 0x10($sp)
/* EA2F84 80242684 3C108024 */  lui       $s0, %hi(D_80244154)
/* EA2F88 80242688 26104154 */  addiu     $s0, $s0, %lo(D_80244154)
/* EA2F8C 8024268C AFBF0018 */  sw        $ra, 0x18($sp)
/* EA2F90 80242690 AFB10014 */  sw        $s1, 0x14($sp)
/* EA2F94 80242694 8E020000 */  lw        $v0, ($s0)
/* EA2F98 80242698 14400010 */  bnez      $v0, .L802426DC
/* EA2F9C 8024269C 0080882D */   daddu    $s1, $a0, $zero
/* EA2FA0 802426A0 0C00AFF5 */  jal       func_8002BFD4
/* EA2FA4 802426A4 24040040 */   addiu    $a0, $zero, 0x40
/* EA2FA8 802426A8 AE020000 */  sw        $v0, ($s0)
/* EA2FAC 802426AC 0000182D */  daddu     $v1, $zero, $zero
/* EA2FB0 802426B0 0040282D */  daddu     $a1, $v0, $zero
/* EA2FB4 802426B4 0220202D */  daddu     $a0, $s1, $zero
.L802426B8:
/* EA2FB8 802426B8 8C820084 */  lw        $v0, 0x84($a0)
/* EA2FBC 802426BC 24840004 */  addiu     $a0, $a0, 4
/* EA2FC0 802426C0 24630001 */  addiu     $v1, $v1, 1
/* EA2FC4 802426C4 ACA20000 */  sw        $v0, ($a1)
/* EA2FC8 802426C8 28620010 */  slti      $v0, $v1, 0x10
/* EA2FCC 802426CC 1440FFFA */  bnez      $v0, .L802426B8
/* EA2FD0 802426D0 24A50004 */   addiu    $a1, $a1, 4
/* EA2FD4 802426D4 080909C6 */  j         .L80242718
/* EA2FD8 802426D8 00000000 */   nop
.L802426DC:
/* EA2FDC 802426DC 0000182D */  daddu     $v1, $zero, $zero
/* EA2FE0 802426E0 0040282D */  daddu     $a1, $v0, $zero
/* EA2FE4 802426E4 0220202D */  daddu     $a0, $s1, $zero
.L802426E8:
/* EA2FE8 802426E8 8CA20000 */  lw        $v0, ($a1)
/* EA2FEC 802426EC 24A50004 */  addiu     $a1, $a1, 4
/* EA2FF0 802426F0 24630001 */  addiu     $v1, $v1, 1
/* EA2FF4 802426F4 AC820084 */  sw        $v0, 0x84($a0)
/* EA2FF8 802426F8 28620010 */  slti      $v0, $v1, 0x10
/* EA2FFC 802426FC 1440FFFA */  bnez      $v0, .L802426E8
/* EA3000 80242700 24840004 */   addiu    $a0, $a0, 4
/* EA3004 80242704 3C108024 */  lui       $s0, %hi(D_80244154)
/* EA3008 80242708 26104154 */  addiu     $s0, $s0, %lo(D_80244154)
/* EA300C 8024270C 0C00B007 */  jal       func_8002C01C
/* EA3010 80242710 8E040000 */   lw       $a0, ($s0)
/* EA3014 80242714 AE000000 */  sw        $zero, ($s0)
.L80242718:
/* EA3018 80242718 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA301C 8024271C 8FB10014 */  lw        $s1, 0x14($sp)
/* EA3020 80242720 8FB00010 */  lw        $s0, 0x10($sp)
/* EA3024 80242724 24020002 */  addiu     $v0, $zero, 2
/* EA3028 80242728 03E00008 */  jr        $ra
/* EA302C 8024272C 27BD0020 */   addiu    $sp, $sp, 0x20
