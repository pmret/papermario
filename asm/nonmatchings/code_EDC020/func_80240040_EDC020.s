.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EDC020
/* EDC020 80240040 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EDC024 80240044 F7B40018 */  sdc1      $f20, 0x18($sp)
/* EDC028 80240048 4485A000 */  mtc1      $a1, $f20
/* EDC02C 8024004C F7B60020 */  sdc1      $f22, 0x20($sp)
/* EDC030 80240050 4486B000 */  mtc1      $a2, $f22
/* EDC034 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* EDC038 80240058 F7B80028 */  sdc1      $f24, 0x28($sp)
/* EDC03C 8024005C 4487C000 */  mtc1      $a3, $f24
/* EDC040 80240060 AFBF0014 */  sw        $ra, 0x14($sp)
/* EDC044 80240064 0C01B198 */  jal       osGetCause
/* EDC048 80240068 0080802D */   daddu    $s0, $a0, $zero
/* EDC04C 8024006C 4616A582 */  mul.s     $f22, $f20, $f22
/* EDC050 80240070 00000000 */  nop       
/* EDC054 80240074 4618A502 */  mul.s     $f20, $f20, $f24
/* EDC058 80240078 00000000 */  nop       
/* EDC05C 8024007C 3C013F80 */  lui       $at, 0x3f80
/* EDC060 80240080 44810000 */  mtc1      $at, $f0
/* EDC064 80240084 00000000 */  nop       
/* EDC068 80240088 E6000014 */  swc1      $f0, 0x14($s0)
/* EDC06C 8024008C E6160010 */  swc1      $f22, 0x10($s0)
/* EDC070 80240090 E6140018 */  swc1      $f20, 0x18($s0)
/* EDC074 80240094 8FBF0014 */  lw        $ra, 0x14($sp)
/* EDC078 80240098 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC07C 8024009C D7B80028 */  ldc1      $f24, 0x28($sp)
/* EDC080 802400A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* EDC084 802400A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* EDC088 802400A8 03E00008 */  jr        $ra
/* EDC08C 802400AC 27BD0030 */   addiu    $sp, $sp, 0x30
