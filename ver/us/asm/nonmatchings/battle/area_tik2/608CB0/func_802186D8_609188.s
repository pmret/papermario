.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186D8_609188
/* 609188 802186D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 60918C 802186DC AFB00010 */  sw        $s0, 0x10($sp)
/* 609190 802186E0 0080802D */  daddu     $s0, $a0, $zero
/* 609194 802186E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 609198 802186E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 60919C 802186EC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6091A0 802186F0 8E02000C */  lw        $v0, 0xc($s0)
/* 6091A4 802186F4 8C450004 */  lw        $a1, 4($v0)
/* 6091A8 802186F8 0C0B210B */  jal       evt_get_float_variable
/* 6091AC 802186FC 8C510000 */   lw       $s1, ($v0)
/* 6091B0 80218700 46000506 */  mov.s     $f20, $f0
/* 6091B4 80218704 0200202D */  daddu     $a0, $s0, $zero
/* 6091B8 80218708 0C0B210B */  jal       evt_get_float_variable
/* 6091BC 8021870C 0220282D */   daddu    $a1, $s1, $zero
/* 6091C0 80218710 3C0140C9 */  lui       $at, 0x40c9
/* 6091C4 80218714 34210FD0 */  ori       $at, $at, 0xfd0
/* 6091C8 80218718 44811000 */  mtc1      $at, $f2
/* 6091CC 8021871C 00000000 */  nop
/* 6091D0 80218720 46020002 */  mul.s     $f0, $f0, $f2
/* 6091D4 80218724 00000000 */  nop
/* 6091D8 80218728 3C0143B4 */  lui       $at, 0x43b4
/* 6091DC 8021872C 44816000 */  mtc1      $at, $f12
/* 6091E0 80218730 0C00A85B */  jal       sin_rad
/* 6091E4 80218734 460C0303 */   div.s    $f12, $f0, $f12
/* 6091E8 80218738 4600A502 */  mul.s     $f20, $f20, $f0
/* 6091EC 8021873C 00000000 */  nop
/* 6091F0 80218740 0200202D */  daddu     $a0, $s0, $zero
/* 6091F4 80218744 4406A000 */  mfc1      $a2, $f20
/* 6091F8 80218748 0C0B2190 */  jal       evt_set_float_variable
/* 6091FC 8021874C 0220282D */   daddu    $a1, $s1, $zero
/* 609200 80218750 8FBF0018 */  lw        $ra, 0x18($sp)
/* 609204 80218754 8FB10014 */  lw        $s1, 0x14($sp)
/* 609208 80218758 8FB00010 */  lw        $s0, 0x10($sp)
/* 60920C 8021875C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 609210 80218760 24020002 */  addiu     $v0, $zero, 2
/* 609214 80218764 03E00008 */  jr        $ra
/* 609218 80218768 27BD0028 */   addiu    $sp, $sp, 0x28
