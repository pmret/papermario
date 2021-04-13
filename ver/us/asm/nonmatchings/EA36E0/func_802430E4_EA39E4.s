.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430E4_EA39E4
/* EA39E4 802430E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA39E8 802430E8 AFB1001C */  sw        $s1, 0x1c($sp)
/* EA39EC 802430EC 0080882D */  daddu     $s1, $a0, $zero
/* EA39F0 802430F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* EA39F4 802430F4 AFB00018 */  sw        $s0, 0x18($sp)
/* EA39F8 802430F8 8E30000C */  lw        $s0, 0xc($s1)
/* EA39FC 802430FC 8E050000 */  lw        $a1, ($s0)
/* EA3A00 80243100 0C0B53A3 */  jal       dead_get_variable
/* EA3A04 80243104 26100004 */   addiu    $s0, $s0, 4
/* EA3A08 80243108 AE220070 */  sw        $v0, 0x70($s1)
/* EA3A0C 8024310C 8E050000 */  lw        $a1, ($s0)
/* EA3A10 80243110 26100004 */  addiu     $s0, $s0, 4
/* EA3A14 80243114 0C0B53A3 */  jal       dead_get_variable
/* EA3A18 80243118 0220202D */   daddu    $a0, $s1, $zero
/* EA3A1C 8024311C AE220074 */  sw        $v0, 0x74($s1)
/* EA3A20 80243120 8E050000 */  lw        $a1, ($s0)
/* EA3A24 80243124 0C0B53A3 */  jal       dead_get_variable
/* EA3A28 80243128 0220202D */   daddu    $a0, $s1, $zero
/* EA3A2C 8024312C 24040052 */  addiu     $a0, $zero, 0x52
/* EA3A30 80243130 0000282D */  daddu     $a1, $zero, $zero
/* EA3A34 80243134 C6200070 */  lwc1      $f0, 0x70($s1)
/* EA3A38 80243138 46800020 */  cvt.s.w   $f0, $f0
/* EA3A3C 8024313C C6220074 */  lwc1      $f2, 0x74($s1)
/* EA3A40 80243140 468010A0 */  cvt.s.w   $f2, $f2
/* EA3A44 80243144 44060000 */  mfc1      $a2, $f0
/* EA3A48 80243148 44071000 */  mfc1      $a3, $f2
/* EA3A4C 8024314C 44820000 */  mtc1      $v0, $f0
/* EA3A50 80243150 00000000 */  nop
/* EA3A54 80243154 46800020 */  cvt.s.w   $f0, $f0
/* EA3A58 80243158 AE220078 */  sw        $v0, 0x78($s1)
/* EA3A5C 8024315C 0C055C13 */  jal       func_8015704C
/* EA3A60 80243160 E7A00010 */   swc1     $f0, 0x10($sp)
/* EA3A64 80243164 8FBF0020 */  lw        $ra, 0x20($sp)
/* EA3A68 80243168 8FB1001C */  lw        $s1, 0x1c($sp)
/* EA3A6C 8024316C 8FB00018 */  lw        $s0, 0x18($sp)
/* EA3A70 80243170 24020002 */  addiu     $v0, $zero, 2
/* EA3A74 80243174 03E00008 */  jr        $ra
/* EA3A78 80243178 27BD0028 */   addiu    $sp, $sp, 0x28
/* EA3A7C 8024317C 00000000 */  nop
