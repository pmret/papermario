.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419AC_D070DC
/* D070DC 802419AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D070E0 802419B0 AFB10014 */  sw        $s1, 0x14($sp)
/* D070E4 802419B4 0080882D */  daddu     $s1, $a0, $zero
/* D070E8 802419B8 AFB00010 */  sw        $s0, 0x10($sp)
/* D070EC 802419BC 00A0802D */  daddu     $s0, $a1, $zero
/* D070F0 802419C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D070F4 802419C4 0C00EABB */  jal       get_npc_unsafe
/* D070F8 802419C8 2404FFFC */   addiu    $a0, $zero, -4
/* D070FC 802419CC 12000003 */  beqz      $s0, .L802419DC
/* D07100 802419D0 0040182D */   daddu    $v1, $v0, $zero
/* D07104 802419D4 2402003C */  addiu     $v0, $zero, 0x3c
/* D07108 802419D8 AE220070 */  sw        $v0, 0x70($s1)
.L802419DC:
/* D0710C 802419DC C462000C */  lwc1      $f2, 0xc($v1)
/* D07110 802419E0 3C0141F0 */  lui       $at, 0x41f0
/* D07114 802419E4 44810000 */  mtc1      $at, $f0
/* D07118 802419E8 00000000 */  nop       
/* D0711C 802419EC 46001000 */  add.s     $f0, $f2, $f0
/* D07120 802419F0 3C0143B4 */  lui       $at, 0x43b4
/* D07124 802419F4 44811000 */  mtc1      $at, $f2
/* D07128 802419F8 00000000 */  nop       
/* D0712C 802419FC 4600103E */  c.le.s    $f2, $f0
/* D07130 80241A00 00000000 */  nop       
/* D07134 80241A04 45000003 */  bc1f      .L80241A14
/* D07138 80241A08 E460000C */   swc1     $f0, 0xc($v1)
/* D0713C 80241A0C 46020001 */  sub.s     $f0, $f0, $f2
/* D07140 80241A10 E460000C */  swc1      $f0, 0xc($v1)
.L80241A14:
/* D07144 80241A14 8E230070 */  lw        $v1, 0x70($s1)
/* D07148 80241A18 2463FFFF */  addiu     $v1, $v1, -1
/* D0714C 80241A1C 000317C3 */  sra       $v0, $v1, 0x1f
/* D07150 80241A20 AE230070 */  sw        $v1, 0x70($s1)
/* D07154 80241A24 8FBF0018 */  lw        $ra, 0x18($sp)
/* D07158 80241A28 8FB10014 */  lw        $s1, 0x14($sp)
/* D0715C 80241A2C 8FB00010 */  lw        $s0, 0x10($sp)
/* D07160 80241A30 30420002 */  andi      $v0, $v0, 2
/* D07164 80241A34 03E00008 */  jr        $ra
/* D07168 80241A38 27BD0020 */   addiu    $sp, $sp, 0x20
