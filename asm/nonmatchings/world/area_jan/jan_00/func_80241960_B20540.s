.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241960_B21EA0
/* B21EA0 80241960 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B21EA4 80241964 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B21EA8 80241968 4485A000 */  mtc1      $a1, $f20
/* B21EAC 8024196C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B21EB0 80241970 4486B000 */  mtc1      $a2, $f22
/* B21EB4 80241974 AFB00010 */  sw        $s0, 0x10($sp)
/* B21EB8 80241978 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B21EBC 8024197C 4487C000 */  mtc1      $a3, $f24
/* B21EC0 80241980 AFBF0014 */  sw        $ra, 0x14($sp)
/* B21EC4 80241984 0C019D28 */  jal       guMtxIdentF
/* B21EC8 80241988 0080802D */   daddu    $s0, $a0, $zero
/* B21ECC 8024198C 4616A582 */  mul.s     $f22, $f20, $f22
/* B21ED0 80241990 00000000 */  nop       
/* B21ED4 80241994 4618A502 */  mul.s     $f20, $f20, $f24
/* B21ED8 80241998 00000000 */  nop       
/* B21EDC 8024199C 3C013F80 */  lui       $at, 0x3f80
/* B21EE0 802419A0 44810000 */  mtc1      $at, $f0
/* B21EE4 802419A4 00000000 */  nop       
/* B21EE8 802419A8 E6000014 */  swc1      $f0, 0x14($s0)
/* B21EEC 802419AC E6160010 */  swc1      $f22, 0x10($s0)
/* B21EF0 802419B0 E6140018 */  swc1      $f20, 0x18($s0)
/* B21EF4 802419B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B21EF8 802419B8 8FB00010 */  lw        $s0, 0x10($sp)
/* B21EFC 802419BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B21F00 802419C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B21F04 802419C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B21F08 802419C8 03E00008 */  jr        $ra
/* B21F0C 802419CC 27BD0030 */   addiu    $sp, $sp, 0x30
